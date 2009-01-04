/*
  horgand-dssi a synth-organ plugin software

 organvarios.c  -  miscelaneous functions
  Copyright (C) 2004-2008 Josep Andreu (Holborn)
  Author: Josep Andreu

 This program is free software; you can redistribute it and/or modify
 it under the terms of version 2 of the GNU General Public License
 as published by the Free Software Foundation.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License (version 2) for more details.

 You should have received a copy of the GNU General Public License
 (version2)  along with this program; if not, write to the Free Software
 Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/


#include "Holrgan.h"
#include <math.h>


// Init Some Vars

void
Put_Period (horgand_synth_t * s)
{
  s->PERIOD2 = s->PERIOD * 2;
  s->PERIOD4 = s->PERIOD * 4;
};

void
New_Bank (horgand_synth_t * s)
{
  int j;

  New (s);
  for (j = 1; j <= 32; j++)
    s->Banco[j] = s->a[0];

};


// Reset vars to New Preset

void
New (horgand_synth_t * s)
{
  int i;

  for (i = 1; i <= 10; i++)
    {
      s->a[0].Operator[i].harmonic_fine = 0.0;
      s->a[0].Operator[i].volumen = 0.0;
      s->a[0].Operator[i].marimba = 0;
      s->a[0].Operator[i].wave = 1;
    }

  s->a[0].Operator[1].harmonic = 1;
  s->a[0].Operator[2].harmonic = 3;
  s->a[0].Operator[3].harmonic = 4;
  s->a[0].Operator[4].harmonic = 5;
  s->a[0].Operator[5].harmonic = 7;
  s->a[0].Operator[6].harmonic = 8;
  s->a[0].Operator[7].harmonic = 11;
  s->a[0].Operator[8].harmonic = 14;
  s->a[0].Operator[9].harmonic = 19;
  s->a[0].Operator[10].harmonic = 22;


  s->a[0].E_Delay_On = 0;
  s->a[0].Delay_Delay = 0;
  s->a[0].Delay_Volume = 0;
  s->a[0].Pitch_LFO_Speed = 0;
  s->a[0].Pitch_LFO_Delay = 0;
  s->a[0].Rotary_LFO_Speed = 0;
  s->a[0].LFOpitch = 0;
  s->a[0].modulation = .99;
  s->a[0].organ_transpose = 0;
  s->a[0].E_Rotary_On = 0;
  s->pitch = 0;
  s->pedal = 0;
  s->Master_Volume = 0.70;
  s->a[0].Organ_Master_Volume = 0.70;
  s->a[0].detune = 0;
  s->a[0].scaling = 0;
  s->a[0].Chorus_Volume = 0.60;
  s->a[0].E_Chorus_On = 0;
  s->a[0].Chorus_LFO_Speed = 0;
  s->a[0].Chorus_LFO_Amplitude = 0;
  s->a[0].Chorus_Delay = 0;
  s->a[0].Reverb_Preset = 1;
  s->a[0].E_Reverb_On = 0;
  bzero (s->a[0].Name, sizeof (s->a[0].Name));
  s->a[0].nombre = s->a[0].Name;
  s->a[0].Normalize[1] = 1.0;
  s->a[0].Normalize[2] = 1.0;
  s->a[0].Normalize[3] = 1.0;
  s->a[0].Normalize[4] = 1.0;
  s->a[0].Normalize[5] = 1.0;
  s->a[0].Normalize[6] = 1.0;
  s->a[0].Normalize[7] = 1.0;
  s->a[0].Normalize[8] = 1.0;
  s->a[0].Normalize[9] = .22;
  s->a[0].Normalize[10] = .2;
  s->a[0].Normalize[11] = .166;
  s->a[0].Normalize[12] = .142;
  s->a[0].Normalize[13] = .133;
  s->a[0].Normalize[14] = .125;
  s->a[0].Normalize[15] = .111;
  s->a[0].Normalize[16] = .1;
  s->a[0].Normalize[17] = 0.095;
  s->a[0].Normalize[18] = 0.090;
  s->a[0].Normalize[19] = 0.083;
  s->a[0].Normalize[20] = 0.076;
  s->a[0].Normalize[21] = 0.071;
  s->a[0].Normalize[22] = .066;
  s->a[0].attack = 0.003;
  s->u_attack = 1.0 / s->a[0].attack;
  s->a[0].decay = 0.28;
  s->u_decay = 1.0 / s->a[0].decay;
  s->a[0].sustain = 0.8;
  s->a[0].p_attack = 0.0002;
  s->u_p_attack = 1.0 / s->a[0].p_attack;
  s->a[0].p_decay = 0.077;
  s->u_p_decay = 1.0 / s->a[0].p_decay;
  s->p_release = 0.1;
  s->u_p_release = 1.0 / s->p_release;
  s->a[0].c_attack = 0.0001;
  s->a[0].c_decay = 0.003;
  s->u_c_attack = 1.0 / s->a[0].c_attack;
  s->u_c_decay = 1.0 / s->a[0].c_decay;
  s->a[0].Click_Vol = .2;
  s->a[0].Click2_Vol = .09;
  s->a[0].Click_Vol1 = .23;
  s->a[0].Click_Vol2 = .04;
  s->a[0].Click_Freq = 360;
  s->a[0].Click_Freq2 = 6712;
  s->a[0].Click = 0;
  s->a[0].Rotary_LFO_Amplitude = 9980;
  s->a[0].Speed_Sync = 0;
  s->a[0].LFO_Wave = 1;
  s->a[0].Chorus_Wave = 1;
  s->a[0].Rotary_Wave = 1;

}

void
Put_Combi_t (horgand_synth_t * s, int i)
{
  s->a[0] = s->Banco[i];
  PutReverb (s, s->a[0].Reverb_Preset);
  Calc_LFO_Frequency (s);
  Calc_Chorus_LFO_Frequency (s);
  syncadsr (s);

 *(s->E_Chorus_On) = s->a[0].E_Chorus_On;
 *(s->E_Rotary_On) = s->a[0].E_Rotary_On;
 *(s->E_Delay_On) = s->a[0].E_Reverb_On;
 *(s->E_Reverb_On) = s->a[0].E_Reverb_On;



};


void
syncadsr (horgand_synth_t * s)
{

  int i;

  memset (s->f, 0, sizeof s->f);
  memset (s->dcphi, 0, sizeof s->dcphi);


  s->u_attack = 1.0 / s->a[0].attack;
  s->u_decay = 1.0 / s->a[0].decay;
  s->u_p_attack = 1.0 / s->a[0].p_attack;
  s->u_p_decay = 1.0 / s->a[0].p_decay;
  s->u_c_attack = 1.0 / s->a[0].c_attack;
  s->u_c_decay = 1.0 / s->a[0].c_decay;

  s->total_vol = .1;


  for (i = 1; i < 11; i++)

    {
      s->p_op[i] = pitch_Operator (s, i, 0);
      s->p_op2[i] = pitch_Operator2 (s, i, 0);
      s->total_vol +=
	s->a[0].Operator[i].volumen *
	s->a[0].Normalize[s->a[0].Operator[i].harmonic];
      s->k[i] = s->a[0].Operator[i].wave;
    }

  s->organ_master = s->a[0].Organ_Master_Volume / s->total_vol;

  s->Click_sFreq = s->a[0].Click_Freq * s->D_PI_to_SAMPLE_RATE;
  s->Click_2sFreq = s->a[0].Click_Freq2 * s->D_PI_to_SAMPLE_RATE;



};



void
PutReverb (horgand_synth_t * s, int i)
{

  int j;

  Clean_Buffer_Effects (s);

  switch (i)
    {
    case 1:
      s->Reverb_Time = 16;
      s->Reverb_Volume = 0.65;
      s->Reverb_Diffussion = 0.14;

      break;

    case 2:
      s->Reverb_Time = 18;
      s->Reverb_Volume = 0.65;
      s->Reverb_Diffussion = 0.14;
      break;

    case 3:
      s->Reverb_Time = 20;
      s->Reverb_Volume = 0.65;
      s->Reverb_Diffussion = 0.16;
      break;

    case 4:
      s->Reverb_Time = 22;
      s->Reverb_Volume = 0.65;
      s->Reverb_Diffussion = 0.16;
      break;

    case 5:
      s->Reverb_Time = 24;
      s->Reverb_Volume = 0.65;
      s->Reverb_Diffussion = 0.16;
      break;

    case 6:
      s->Reverb_Time = 26;
      s->Reverb_Volume = 0.65;
      s->Reverb_Diffussion = 0.16;

    case 7:
      s->Reverb_Time = 30;
      s->Reverb_Volume = 0.65;
      s->Reverb_Diffussion = 0.16;
      break;

    case 8:
      s->Reverb_Time = 34;
      s->Reverb_Volume = 0.65;
      s->Reverb_Diffussion = 0.16;
      break;
    }

  for (j = 0; j < 16; j++)
    {
      s->a_combl[j] = (s->Reverb_Time * s->combl[j]);
      s->a_combr[j] = (s->Reverb_Time * s->combr[j]);
    }


};
