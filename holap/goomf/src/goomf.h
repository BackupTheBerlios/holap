/*
  goomf - a FM mono synth plugin software
  
  goomf.h  -  Variable Definitions and functions
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
 (version2)  along with this program; if not, write to the Free Software Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
                            
*/


#ifndef DXEMU_H
#define DXEMU_H
#include <alsa/asoundlib.h>
#include "../config.h"
#include <lo/lo.h>
#include <ladspa.h>
#define D_PI 6.283185
#define F2I(x)  ( lrintf(x) )


typedef struct
{
  float phi;
  float dphi;
  float phi2;
  float dphi2;
} freqVarios;


typedef struct
{
  int wave;
  int harmonic;
  float harmonic_fine;
  float volumen;
  float attack;
  float decay;
  float sustain;
  float release;
  float pLFO;
  float aLFO;
  float vsr;
} OperatorPar;


typedef struct
{

  OperatorPar Op[6];
  char Name[36];
  float modulation;
  float Pitch_LFO_Speed;
  float Pitch_LFO_Delay;
  float LFOpitch;
  float Master_Volume;
  int LFO_Wave;
  float Portamento_Speed;
  
} Todolo;


typedef struct
{
  float f1, f2, f3;
} Menoscalculos;


typedef struct
{
  pthread_mutex_t mutex;
  lo_server osc_server;
  lo_address m_host;
  char *osc_configure_path;
  char *osc_control_path;       

  LADSPA_Data *output_l;
  LADSPA_Data *output_r;
  LADSPA_Data *master_volume;
  LADSPA_Data *tune;
  LADSPA_Data *rmodulation;
  LADSPA_Data *portamento;
  LADSPA_Data *wave[6];
  LADSPA_Data *H[6];
  LADSPA_Data *HF[6];
  LADSPA_Data *Ovol[6];
  LADSPA_Data *attack[6];
  LADSPA_Data *decay[6];
  LADSPA_Data *sustain[6];
  LADSPA_Data *release[6];  
  LADSPA_Data *pLFO[6];
  LADSPA_Data *aLFO[6];
  LADSPA_Data *vsr[6];   

  OperatorPar Op[6];
  char Name[36];
  float Pitch_LFO_Speed;
  float Pitch_LFO_Delay;
  float LFOpitch;
  float Master_Volume;
  int LFO_Wave;
  
  freqVarios f[6];
  Menoscalculos h[192];
  float lsin[6290];
  float nsin[6290];
  float msin[6290];
  float psin[6290];
  float qsin[6290];
  float rsin[6290];
  float tsin[6290];
  float ssin[6290];
  float usin[6290];
  float bufl[8192];
  float bufr[8192];
  unsigned int SAMPLE_RATE;
  float Envelope_Volume[6];
  float Env_Vol[6];
  float pitch;
  float env_time;
  float renv_time;
  float scaling;
  float modulation; 
  int note;
  int lastnote;
  float apartial;
  float lpartial;
  float ppartial;
  int gate;
  float lasfreq[22];
  float LFO_Volume;
  float LFO_Frequency;
  float increment;
  float D_PI_to_SAMPLE_RATE;
  int preset;
  char BankFilename[128];
  Todolo Banco[32];

} goomf_synth_t;

long int lrintf (float x);

float NFsin (goomf_synth_t * s, int i, float x);
void Alg1s (goomf_synth_t * s, int nframes);
float Jenvelope (goomf_synth_t * s, int op);
float Get_Partial (goomf_synth_t * s);
float Pitch_LFO (goomf_synth_t * s, float t);
void Calc_LFO_Frequency (goomf_synth_t * s);
float pitch_Operator (goomf_synth_t * s, int i);
float pitch_Operator2 (goomf_synth_t * s, int i);
void New (goomf_synth_t * s);
void New_Bank (goomf_synth_t * s);
int loadbank (goomf_synth_t * s, const char *filename);
void Put_Combi_t (goomf_synth_t * s, int i);
void init_vars (goomf_synth_t * s);



#endif

