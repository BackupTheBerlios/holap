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
#include <ladspa.h>
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

  LADSPA_Data *output_l;
  LADSPA_Data *output_r;
  LADSPA_Data *vol;
  LADSPA_Data *tune;
  LADSPA_Data *modulation;
  

  OperatorPar Op[6];
  char Name[36];
  float modulation;
  float Pitch_LFO_Speed;
  float Pitch_LFO_Delay;
  float LFOpitch;
  float Master_Volume;
  int LFO_Wave;
  float Portamento_Speed;

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
  float buf[8192];
  unsigned int SAMPLE_RATE;
  float velocity;
  float pitch;
  float env_time;
  int note;
  int gate;
  float Envelope_Volume;
  float lasfreq[22];
  float master_volume;
  int pedal;
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
float Jenvelope (goomf_synth_t * s, int op, int gate, float t);
float Get_Partial (goomf_synth_t * s, int note);
float Pitch_LFO (goomf_synth_t * s, float t);
void Calc_LFO_Frequency (goomf_synth_t * s);
float pitch_Operator (goomf_synth_t * s, int i, int note);
float pitch_Operator2 (goomf_synth_t * s, int i, int note);
float Get_Keyb_Level_Scaling (goomf_synth_t * s, int nota);
void New (goomf_synth_t * s);
void New_Bank (goomf_synth_t * s);
void panic (goomf_synth_t * s);
int loadbank (goomf_synth_t * s, const char *filename);
void Put_Combi_t (goomf_synth_t * s, int i);
void init_vars (goomf_synth_t * s);



#endif

