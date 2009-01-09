/*
  goomf a FM mono synth plugin software

  synthvarios.c  -  miscelaneous functions
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
 (version2)  along with this program; if not, write to the Free Software
 Foundation,
 Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/


#include "goomf.h"
#include <math.h>


// Init Some Vars

void
New_Bank (goomf_synth_t * s)
{
  int j;

  New (s);
  for (j = 1; j <= 32; j++)
{
 //   s->Banco[j] = s->a[0]; NEW Bank .. a copiar y a joderse 
}
};


// Reset vars to New Preset

void
New (goomf_synth_t * s)
{
  int i;

  for (i = 0; i < 6; i++)
    {
      s->Op[i].harmonic = 0;
      s->Op[i].harmonic_fine = 0.0;
      s->Op[i].volumen = 0.0;
      s->Op[i].wave = 1;
      s->Op[i].attack = .001;
      s->Op[i].decay = .001;
      s->Op[i].sustain = .5;
      s->Op[i].release = .001;
      s->Op[i].pLFO = 0.0;
      s->Op[i].aLFO = 0.0;
      s->Op[i].vsr = 0.0;
    }

  s->Pitch_LFO_Speed = 0;
  s->Pitch_LFO_Delay = 0;
  s->LFO_Wave = 1;
  s->LFOpitch = 0;

  s->modulation = .99;
  s->pitch = 0;
  s->pedal = 0;
  s->scaling = 0;
  bzero (s->Name, sizeof (s->Name));

}

void
Put_Combi_t (goomf_synth_t * s, int i)
{
  // s->a[0] = s->Banco[i];  PASAR Banco a Local

  Calc_LFO_Frequency (s);

};


