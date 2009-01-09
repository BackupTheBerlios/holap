/*
  goomf - a FM mono syhth plugin software

  goomf.c  -  Main dssi file of the plugin
  Copyright (C) 2009 Josep Andreu (Holborn)
  Author: Josep Andreu

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2) for more details.

  You should have received a copy of the GNU General Public License
(version2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/


#include "goomf.h"
#include <math.h>
#include <dssi.h>
#include <ladspa.h>
#include <pthread.h>

#define goomf_OUTPUT_L 0
#define goomf_OUTPUT_R 1
#define goomf_VOLUME 2
#define goomf_MASTERTUNE 3

#define STEP_SIZE 64

static LADSPA_Descriptor *goomfLDescriptor = NULL;
static DSSI_Descriptor *goomfDDescriptor = NULL;

static void rungoomf (LADSPA_Handle instance, unsigned long sample_count,
			snd_seq_event_t * events, unsigned long EventCount);


static void cleanupgoomf (LADSPA_Handle instance);


const LADSPA_Descriptor *
ladspa_descriptor (unsigned long index)
{
  switch (index)
    {
    case 0:
      return goomfLDescriptor;
    default:
      return NULL;
    }
}

const DSSI_Descriptor *
dssi_descriptor (unsigned long index)
{
  switch (index)
    {
    case 0:
      return goomfDDescriptor;
    default:
      return NULL;
    }
}

static void
cleanupgoomf (LADSPA_Handle instance)
{
  goomf_synth_t *synth = (goomf_synth_t *) instance;
  free (synth);
}

static void
connectPortgoomf (LADSPA_Handle instance, unsigned long port,
		    LADSPA_Data * data)
{
  goomf_synth_t *plugin = (goomf_synth_t *) instance;
  switch (port)
    {
    case goomf_OUTPUT_L:
      plugin->output_l = data;
      break;
    case goomf_OUTPUT_R:
      plugin->output_r = data;
      break;
    case goomf_VOLUME:
      plugin->vol = data;
      break;
    case goomf_MASTERTUNE:
      plugin->tune = data;
      break;
    }

}



char *
goomfConfigure (LADSPA_Handle instance, const char *key, const char *value)
{
  int i = 0;
  goomf_synth_t *synth = (goomf_synth_t *) instance;

  if (!strcmp (key, "load"))
    {
      pthread_mutex_lock (&synth->mutex);
      i = loadbank (synth, value);
      pthread_mutex_unlock (&synth->mutex);
      if (i)
	return strdup ("Error loading file");
      else
	return NULL;
    }

  return strdup ("error: unrecognized configure key");
}

const DSSI_Program_Descriptor *
goomf_get_program (LADSPA_Handle handle, unsigned long index)
{
  static DSSI_Program_Descriptor pd;
  goomf_synth_t *synth = (goomf_synth_t *) handle;

  if (index < 32)
    {

      pd.Bank = 0;
      pd.Program = index + 1;
      pd.Name = synth->Banco[index + 1].Name;
      return &pd;
    }
  return NULL;
}

void
goomf_select_program (LADSPA_Handle handle, unsigned long bank,
			unsigned long program)
{



  goomf_synth_t *synth = (goomf_synth_t *) handle;
  if (bank || program > 32)
    return;

  //pthread_mutex_lock (&synth->mutex);
  //Put_Combi_t (synth, program);
  //pthread_mutex_unlock (&synth->mutex);


}





static LADSPA_Handle
instantiategoomf (const LADSPA_Descriptor * descriptor,
		    unsigned long s_rate)
{

  goomf_synth_t *synth =
    (goomf_synth_t *) calloc (1, sizeof (goomf_synth_t));

  synth->SAMPLE_RATE = (unsigned int) s_rate;
  init_vars (synth);
  Adjust_Audio (synth);
  sprintf (synth->BankFilename, "%s/Default.goomf", DATADIR);
  pthread_mutex_init (&synth->mutex, NULL);
//  pthread_mutex_lock (&synth->mutex);
//  loadbank (synth, synth->BankFilename);
//  pthread_mutex_unlock (&synth->mutex);

  return (LADSPA_Handle) synth;
}

static void
activategoomf (LADSPA_Handle instance)
{

  goomf_synth_t *synth = (goomf_synth_t *) instance;

  panic (synth);
}


void
goomf_deactivate (LADSPA_Handle instance)
{
  goomf_synth_t *synth = (goomf_synth_t *) instance;
  panic (synth);

}


static void
rungoomfWrapper (LADSPA_Handle instance, unsigned long sample_count)
{
  rungoomf (instance, sample_count, NULL, 0);
}

static void
rungoomf (LADSPA_Handle instance, unsigned long sample_count,
	    snd_seq_event_t * events, unsigned long event_count)
{
  goomf_synth_t *synth = (goomf_synth_t *) instance;
  LADSPA_Data *const outputl = synth->output_l;
  LADSPA_Data *const outputr = synth->output_r;
  LADSPA_Data vol = *(synth->vol);

  unsigned long event_pos = 0;
  unsigned long pos;
  unsigned long count;
  int i,j;


  for (pos = 0, event_pos = 0; pos < sample_count; pos += STEP_SIZE)
    {

      while (event_pos < event_count)
	{

	  switch (events[event_pos].type)
	    {
	    case SND_SEQ_EVENT_PITCHBEND:
	      synth->pitch =
		(float) events[event_pos].data.control.value / 8192.0;
	      break;

	    case SND_SEQ_EVENT_PGMCHANGE:

	       if (events[event_pos].data.control.value < 33)
		synth->preset = events[event_pos].data.control.value;
	      break;


	    case SND_SEQ_EVENT_CONTROLLER:

	      if (events[event_pos].data.control.param == 1)
		{
		  synth->modulation =(float)
         	    events[event_pos].data.control.value / 128;
		  Calc_LFO_Frequency (synth);
		  break;
		}

	      if (events[event_pos].data.control.param == 7)
		{
		  synth->master_volume =
		    (float) events[event_pos].data.control.value / 128.0;
		  break;
		}
	      if (events[event_pos].data.control.param == 64)
		{
		  if (events[event_pos].data.control.value < 64)
		    {
		      synth->pedal = 0;
			if (synth->gate== 0) synth->env_time = 0;
		    }
		  if (events[event_pos].data.control.value > 63)
		    synth->pedal = 1;
		}
	      break;

	    case SND_SEQ_EVENT_NOTEON:

	      if (events[event_pos].data.note.velocity != 0)
		{
			  synth->note= events[event_pos].data.note.note;
			  synth->velocity = events[event_pos].data.note.velocity / 126.0;
			  if (synth->scaling)
			    synth->velocity=Get_Keyb_Level_Scaling (synth,synth->note);
			  if (synth->velocity> 1.0)
			    synth->velocity= 1.0;
			  synth->env_time = 0;
			  synth->gate=1;
			  break;
		  break;
		}
	      else
		{
		      if ((synth->gate) && (synth->note ==events[event_pos].data.note.note))
			{
			  synth->gate=0;
			  if (synth->pedal == 0) synth->env_time=0;
			}

		    
		}
	      break;
	    case SND_SEQ_EVENT_NOTEOFF:
		  if ((synth->gate) && (synth->note==events[event_pos].data.note.note))
		    {
		      synth->gate=0;
		      if (synth->pedal == 0) synth->env_time=0;
		    }

	      break;
	    }

	  event_pos++;
	}

      count = (sample_count - pos) > STEP_SIZE ? STEP_SIZE :
      sample_count - pos;



      // Alg1s (synth, count);

      for (i = 0; i < count; i += 2)
	{
	  j = pos + i;
	  outputl[j] = synth->buf[i] * vol;
	  outputr[j] = synth->buf[i + 1] * vol;

	}
    }

}




int
getControllergoomf (LADSPA_Handle instance, unsigned long port)
{
  switch (port)
    {
    case goomf_VOLUME:
      return DSSI_CC (7);


    }




  return -1;
}

void __attribute__((constructor))
goomf_init()
{


  char **port_names;
  LADSPA_PortDescriptor *port_descriptors;
  LADSPA_PortRangeHint *port_range_hints;

  goomfLDescriptor =
    (LADSPA_Descriptor *) malloc (sizeof (LADSPA_Descriptor));

  if (goomfLDescriptor)
    {
      goomfLDescriptor->UniqueID = 3983;
      goomfLDescriptor->Label = "goomf";
      goomfLDescriptor->Properties = 0;
      goomfLDescriptor->Name = "goomf";
      goomfLDescriptor->Maker = "Josep Andreu <holborn@telefonica.net>";
      goomfLDescriptor->Copyright = "GNU General Public License version 2";
      goomfLDescriptor->PortCount = 4;


      port_descriptors = (LADSPA_PortDescriptor *)
	calloc (goomfLDescriptor->PortCount, sizeof
		(LADSPA_PortDescriptor));
      goomfLDescriptor->PortDescriptors =
	(const LADSPA_PortDescriptor *) port_descriptors;

      port_range_hints = (LADSPA_PortRangeHint *)
	calloc (goomfLDescriptor->PortCount, sizeof (LADSPA_PortRangeHint));
      goomfLDescriptor->PortRangeHints =
	(const LADSPA_PortRangeHint *) port_range_hints;

      port_names =
	(char **) calloc (goomfLDescriptor->PortCount, sizeof (char *));
      goomfLDescriptor->PortNames = (const char **) port_names;

      /* Parameters for Output L */
      port_descriptors[goomf_OUTPUT_L] =
	LADSPA_PORT_OUTPUT | LADSPA_PORT_AUDIO;
      port_names[goomf_OUTPUT_L] = "Output L";
      port_range_hints[goomf_OUTPUT_L].HintDescriptor = 0;

      /* Parameters for Output R */
      port_descriptors[goomf_OUTPUT_R] =
	LADSPA_PORT_OUTPUT | LADSPA_PORT_AUDIO;
      port_names[goomf_OUTPUT_R] = "Output R";
      port_range_hints[goomf_OUTPUT_R].HintDescriptor = 0;

      /* Parameters for Volume */
      port_descriptors[goomf_VOLUME] =
	LADSPA_PORT_INPUT | LADSPA_PORT_CONTROL;
      port_names[goomf_VOLUME] = "Volume";
      port_range_hints[goomf_VOLUME].HintDescriptor =
	LADSPA_HINT_DEFAULT_MAXIMUM |
	LADSPA_HINT_BOUNDED_BELOW | LADSPA_HINT_BOUNDED_ABOVE;
      port_range_hints[goomf_VOLUME].LowerBound = 0.0;
      port_range_hints[goomf_VOLUME].UpperBound = 1.0;

      /* Parameters for MasterTune */
      port_descriptors[goomf_MASTERTUNE] =
	LADSPA_PORT_INPUT | LADSPA_PORT_CONTROL;
      port_names[goomf_MASTERTUNE] = "Mastertune";
      port_range_hints[goomf_MASTERTUNE].HintDescriptor =
	LADSPA_HINT_BOUNDED_BELOW | LADSPA_HINT_BOUNDED_ABOVE |
	LADSPA_HINT_DEFAULT_MIDDLE;
      port_range_hints[goomf_MASTERTUNE].LowerBound = -1.0;
      port_range_hints[goomf_MASTERTUNE].UpperBound = 1.0;

      goomfLDescriptor->instantiate = instantiategoomf;
      goomfLDescriptor->connect_port = connectPortgoomf;
      goomfLDescriptor->activate = activategoomf;
      goomfLDescriptor->run = rungoomfWrapper;
      goomfLDescriptor->run_adding = NULL;
      goomfLDescriptor->set_run_adding_gain = NULL;
      goomfLDescriptor->deactivate = goomf_deactivate;
      goomfLDescriptor->cleanup = cleanupgoomf;


    }



  goomfDDescriptor = (DSSI_Descriptor *) malloc (sizeof (DSSI_Descriptor));
  if (goomfDDescriptor)
    {
      goomfDDescriptor->DSSI_API_Version = 1;
      goomfDDescriptor->LADSPA_Plugin = goomfLDescriptor;
      goomfDDescriptor->configure = goomfConfigure;
      goomfDDescriptor->get_program = goomf_get_program;
      goomfDDescriptor->get_midi_controller_for_port = getControllergoomf;
      goomfDDescriptor->select_program = goomf_select_program;
      goomfDDescriptor->run_synth = rungoomf;
      goomfDDescriptor->run_synth_adding = NULL;
      goomfDDescriptor->run_multiple_synths = NULL;
      goomfDDescriptor->run_multiple_synths_adding = NULL;
    }
}


void __attribute__ ((destructor))
goomf_fini()
{
  if (goomfLDescriptor)
    {
      free ((LADSPA_PortDescriptor *) goomfLDescriptor->PortDescriptors);
      free ((char **) goomfLDescriptor->PortNames);
      free ((LADSPA_PortRangeHint *) goomfLDescriptor->PortRangeHints);
      free (goomfLDescriptor);
    }
  if (goomfDDescriptor)
    {
      free (goomfDDescriptor);
    }
}
