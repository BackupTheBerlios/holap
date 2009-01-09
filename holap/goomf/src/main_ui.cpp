/*
  goomf - a FM mono syhth plugin software

  main_ui.cpp  -  Main dssi GUI file of the plugin
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

#include <dssi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <lo/lo.h>
#include "goomf_ui.h"
#include "main_ui.h"


pthread_t thr1;

void *
thread1 (void *arg)
{

  while (gui.Pexitprogram == 0)
    {
      switch (gui.ready)
	{
	case 1:
	  lo_send (m_host, osc_configure_path, "ss", "load",
		   gui.uBankFilename);
	  update_patches (gui.uBankFilename);
	  break;

	case 2:
	  lo_send (m_host, osc_program_path, "ii", 0,
		   (int) gui.PresetSelect->value () + 1);

	  break;
	}

      gui.ready = 0;

      switch (funcion)
	{
	case 1:
	  gui.ui_win->iconize ();
	  break;
	case 2:
	  gui.ui_win->show ();
	  break;
	}

      funcion = 0;

      if (gui.cop)
        {
          sprintf(tmpchar,"%d",gui.op);
          lo_send(m_host,osc_configure_path, "ss","op",tmpchar);
          gui.cop=0;
        }  
      if (gui.D_Vol_c)
	{
	  lo_send (m_host, osc_control_path, "if", 2, gui.D_Vol->value ());
	  gui.D_Vol_c = 0;
	}

      if (gui.D_Tune_c)
	{
	  lo_send (m_host, osc_control_path, "if", 3, gui.D_Tune->value ());
	  gui.D_Tune_c = 0;
	}

      if (gui.D_Portamento_c)
	{
	  lo_send (m_host, osc_control_path, "if", 4, gui.D_Portamento->value ());
	  gui.D_Portamento_c = 0;
	}

      if (gui.D_Wave_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 5+gui.op, gui.D_Wave->value ());
	  gui.D_Wave_c[gui.op] = 0;
	}
      if (gui.D_H_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 11+gui.op, gui.D_H->value ());
	  gui.D_H_c[gui.op] = 0;
	}
      
      if (gui.D_HF_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 17+gui.op, gui.D_HF->value ());
	  gui.D_HF_c[gui.op] = 0;
	}
      
      if (gui.D_OVol_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 23+gui.op, gui.D_OVol->value ());
	  gui.D_OVol_c[gui.op] = 0;
	}
      
      if (gui.D_Attack_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 29+gui.op, gui.D_Attack->value ());
	  gui.D_Attack_c[gui.op] = 0;
       	}
      
      if (gui.D_Decay_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 35+gui.op, gui.D_Decay->value ());
	  gui.D_Decay_c[gui.op] = 0;
	}
      
      if (gui.D_Sustain_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 41+gui.op, gui.D_Sustain->value ());
	  gui.D_Sustain_c[gui.op] = 0;
	}

      if (gui.D_Release_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 47+gui.op, gui.D_Release->value ());
	  gui.D_Release_c[gui.op] = 0;
	}
      
      if (gui.D_pLFO_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 53+gui.op, gui.D_pLFO->value ());
	  gui.D_pLFO_c[gui.op] = 0;
	}
      
      if (gui.D_aLFO_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 59+gui.op, gui.D_aLFO->value ());
	  gui.D_aLFO_c[gui.op] = 0;
	}

      if (gui.D_VSR_c[gui.op])
	{
	  lo_send (m_host, osc_control_path, "if", 65+gui.op, gui.D_VSR->value ());
	  gui.D_VSR_c[gui.op] = 0;
	}


        Fl::wait();
    }

  lo_send (m_host, osc_exiting_path, "");

  return (0);
};



void
update_widgets (int port, float value)
{

  switch (port)
    {
    case 2:
      gui.D_Vol->value (value);
      break;
    case 3:
      gui.D_Tune->value (value);
      break;
    case 4:
      gui.D_Portamento->value (value);
      break;
    case 5:
      gui.D_Wave->value(value);
      break;  
    case 6:
      gui.D_H->value(value);
      break;  
    case 7:
      gui.D_HF->value(value);
      break;  
    case 8:
      gui.D_OVol->value(value);
      break;  
    case 9:
      gui.D_Attack->value(value);
      break;  
    case 10:
      gui.D_Decay->value(value);
      break;  
    case 11:
      gui.D_Sustain->value(value);
      break;  
    case 12:
      gui.D_Release->value(value);
      break;  
    case 13:
      gui.D_pLFO->value(value);
      break;  
    case 14:
      gui.D_aLFO->value(value);
      break;  
    case 15:
      gui.D_VSR->value(value);
      break;  

 }


}

void
update_patches (const char *filename)
{

  return;

  int i, j;
  FILE *fn;
  char buf[2048];
  char Name[64];

  if ((fn = fopen (filename, "r")) == NULL)
    return;

  gui.PresetSelect->clear ();

  fclose (fn);



}


static char *
osc_build_path (char *base_path, const char *method)
{
  char buffer[256];
  char *full_path;

  snprintf (buffer, 256, "%s%s", base_path, method);
  if (!(full_path = strdup (buffer)))
    {
      printf ("out of memory!\n");
      exit (1);
    }
  return strdup (buffer);
}


static void
osc_error (int num, const char *msg, const char *path)
{

  printf (" error: liblo server error %d in path \"%s\": %s\n",
	  num, (path ? path : "(null)"), msg);


}




int
debug_handler (const char *path, const char *types, lo_arg ** argv,
	       int argc, void *data, void *user_data)
{
  int i;

  printf ("Warning: unhandled OSC message in GUI:\n");
  for (i = 0; i < argc; ++i)
    {
      printf ("arg  %d : type : %c \n", i, types[i]);
      lo_arg_pp ((lo_type) types[i], argv[i]);

    }

  printf ("path is %s\n", path);
  return 1;
}

int
configure_handler (const char *path, const char *types, lo_arg ** argv,
		   int argc, void *data, void *user_data)
{

  const char *key = (const char *) &argv[0]->s;
  const char *value = (const char *) &argv[1]->s;

  if (!strcmp (key, "load"))
    {
      update_patches (value);
      gui.setBankFile->copy_label (value);
      gui.setBankFile->redraw ();

    }
  return 0;
}

int
show_handler (const char *path, const char *types, lo_arg ** argv,
	      int argc, void *data, void *user_data)
{
  funcion = 2;
  return 0;
}

int
hide_handler (const char *path, const char *types, lo_arg ** argv,
	      int argc, void *data, void *user_data)
{

  funcion = 1;
  return 0;
}

int
quit_handler (const char *path, const char *types, lo_arg ** argv,
	      int argc, void *data, void *user_data)
{

  gui.ui_win->do_callback ();
  gui.quit ();
  lo_send (m_host, osc_exiting_path, "");
  gui.Pexitprogram = 1;
  return 0;

}

int
exiting_handler (const char *path, const char *types, lo_arg ** argv,
		 int argc, void *data, void *user_data)
{
  gui.ui_win->do_callback ();
  gui.quit ();
  lo_send (m_host, osc_exiting_path, "");
  gui.Pexitprogram = 1;
  return 0;


}

int
control_handler (const char *path, const char *types, lo_arg ** argv,
		 int argc, void *data, void *user_data)
{


  if (argc < 2)
    {
      printf ("Error: too few arguments to control_handler\n");
      return 1;
    }

  const int port = argv[0]->i;
  const float value = argv[1]->f;


if (port < 5)  update_widgets (port, value);
  else  update_widgets(((port+1)/6)+4,value);
  
  return 0;
}

int
program_handler (const char *path, const char *types, lo_arg ** argv,
		 int argc, lo_message msg, void *user_data)
{
  int bank, program, i;

  if (argc < 2)
    {
      printf (" error: too few arguments to osc_program_handler\n");
      return 1;
    }

  bank = argv[0]->i;
  program = argv[1]->i;
  gui.PresetSelect->value (program);
  




  printf
    ("osc_program_handler: received program change, bank %d, program %d\n",
     bank, program);

  return 0;
}


int
main (int argc, char **argv)
{

  int i;
  int lo_fd;
  fd_set rfds;
  struct timeval tv;
  int retval;
  int done = 0;

  funcion = 0;
  gui.Pexitprogram = 0;
  gui.ready = 0;
  gui.D_Vol_c = 0;
  gui.D_Tune_c = 0;
  gui.D_Portamento_c  = 0;
  gui.cop = 0;
  for (i=0; i<6; i++)
  {
    gui.D_Wave_c[i]=0;
    gui.D_H_c[i]=0;
    gui.D_HF_c[i]=0;
    gui.D_OVol_c[i]=0;
    gui.D_VSR_c[i]=0;
    gui.D_pLFO_c[i]=0;
    gui.D_aLFO_c[i]=0;
    gui.D_Attack_c[i]=0;
    gui.D_Decay_c[i]=0;
    gui.D_Sustain_c[i]=0;
    gui.D_Release_c[i]=0;
  }  
  
  
    
  
  sprintf (gui.uBankFilename, "%s/Default.goomf", DATADIR);
  update_patches (gui.uBankFilename);

  char *url = argv[1];
  char *host = lo_url_get_hostname (url);
  char *port = lo_url_get_port (url);
  char *path = lo_url_get_path (url);
  char *label = argv[3];
  char *temp;

  pthread_create (&thr1, NULL, thread1, NULL);
  
  gui.ui_win->copy_label (argv[3]);
  gui.ui_win->show ();

  osc_server = 0;
  m_host = lo_address_new (host, port);

  osc_configure_path = osc_build_path (path, "/configure");
  osc_control_path = osc_build_path (path, "/control");
  osc_exiting_path = osc_build_path (path, "/exiting");
  osc_hide_path = osc_build_path (path, "/hide");
  osc_midi_path = osc_build_path (path, "/midi");
  osc_program_path = osc_build_path (path, "/program");
  osc_quit_path = osc_build_path (path, "/quit");
  osc_show_path = osc_build_path (path, "/show");
  osc_update_path = osc_build_path (path, "/update");

  osc_server = lo_server_new (NULL, osc_error);

  lo_server_add_method (osc_server, osc_configure_path, "ss",
			configure_handler, NULL);
  lo_server_add_method (osc_server, osc_control_path, "if", control_handler,
			NULL);
  lo_server_add_method (osc_server, osc_hide_path, "", hide_handler, NULL);
  lo_server_add_method (osc_server, osc_program_path, "ii", program_handler,
			NULL);
  lo_server_add_method (osc_server, osc_quit_path, "", quit_handler, NULL);
  lo_server_add_method (osc_server, osc_exiting_path, "", exiting_handler,
			NULL);
  lo_server_add_method (osc_server, osc_show_path, "", show_handler, NULL);
  lo_server_add_method (osc_server, NULL, NULL, debug_handler, NULL);

   


  temp = lo_server_get_url (osc_server);

  myurl = osc_build_path (temp, (strlen (path) > 1 ? path + 1 : path));

  gui.d_osc_label->copy_label (myurl);

  lo_send (m_host, osc_update_path, "s", myurl);

  lo_send (m_host, osc_configure_path, "ss", "url",myurl);

  lo_fd = lo_server_get_socket_fd (osc_server);

  if (lo_fd > 0)
    {

      do
	{


	  FD_ZERO (&rfds);
	  FD_SET (lo_fd, &rfds);

	  retval = select (lo_fd + 1, &rfds, NULL, NULL, NULL);

	  if (retval == -1)
	    {

	      printf ("select() error\n");
	      exit (1);

	    }
	  else if (retval > 0)

	    {

	      if (FD_ISSET (0, &rfds))
		{

		  read_stdin ();
		}
	      if (FD_ISSET (lo_fd, &rfds))
		{

		  lo_server_recv_noblock (osc_server, 0);

		}
	    }


	}
      while (!done);

    }
  else
    {

      do
	{



	  FD_ZERO (&rfds);
	  FD_SET (0, &rfds);
	  tv.tv_sec = 0;
	  tv.tv_usec = 10000;

	  retval = select (1, &rfds, NULL, NULL, &tv);

	  if (retval == -1)
	    {

	      printf ("select() error\n");
	      exit (1);

	    }
	  else if (retval > 0 && FD_ISSET (0, &rfds))
	    {

	      read_stdin ();

	    }

	  lo_server_recv_noblock (osc_server, 0);



	}
      while (!done);

    }





  free (host);
  free (port);
  free (path);
  free (osc_configure_path);
  free (osc_control_path);
  free (osc_exiting_path);
  free (osc_hide_path);
  free (osc_midi_path);
  free (osc_program_path);
  free (osc_quit_path);
  free (osc_show_path);
  free (osc_update_path);
  free (myurl);


  return (0);





}

void
read_stdin (void)
{
  char buf[256];
  int len = read (0, buf, 256);
  if (len > 0)
    {
      printf ("stdin: ");
      fwrite (buf, len, 1, stdout);
      printf ("\n");
      fflush (stdout);
    }
}


