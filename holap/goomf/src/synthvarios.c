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
  int i,j;

  New (s);
  for (j = 0; j < 128; j++)
{

 bzero (s->Banco[j].Name, sizeof (s->Name));

 *(s->Banco[j].master_volume) = *(s->master_volume);
 *(s->Banco[j].tune) = *(s->tune);
 *(s->Banco[j].portamento) = *(s->portamento);
 *(s->Banco[j].LFO_Frequency) = *(s->LFO_Frequency);
 *(s->Banco[j].LFO_Delay) = *(s->LFO_Delay);
 *(s->Banco[j].LFO_Wave) = *(s->LFO_Wave);
 *(s->Banco[j].LFO_Volume) = *(s->LFO_Volume);
       
  for (i = 0; i < 6; i++)
    {
      *(s->Banco[j].H[i]) = *(s->H[i]);
      *(s->Banco[j].HF[i]) = *(s->HF[i]);
      *(s->Banco[j].Ovol[i]) = *(s->Ovol[i]);
      *(s->Banco[j].wave[i]) = *(s->wave[i]);
      *(s->Banco[j].attack[i]) = *(s->attack[i]);
      *(s->Banco[j].decay[i]) = *(s->decay[i]);
      *(s->Banco[j].sustain[i]) = *(s->sustain[i]);
      *(s->Banco[j].release[i]) = *(s->release[i]);
      *(s->Banco[j].pLFO[i]) = *(s->pLFO[i]);
    }



}
};


// Reset vars to New Preset

void
New (goomf_synth_t * s)
{
  int i;

  for (i = 0; i < 6; i++)
    {
      *(s->H[i]) = 0;
      *(s->HF[i]) = 0.0;
      *(s->Ovol[i]) = 0.0;
      *(s->wave[i]) = 1;
      *(s->attack[i]) = .001;
      *(s->decay[i]) = .001;
      *(s->sustain[i]) = .5;
      *(s->release[i]) = .001;
      *(s->pLFO[i]) = 0.0;
    }

  *(s->LFO_Frequency) = 0;
  *(s->LFO_Delay) = 0;
  *(s->LFO_Wave) = 1;
  *(s->LFO_Volume) = 0;
  *(s->master_volume) = .5;
  *(s->tune) = 0;
  *(s->portamento) = 0;
  s->modulation = .99;
  s->pitch = 0;
  bzero (s->Name, sizeof (s->Name));

}

void
Put_Combi_t (goomf_synth_t * s, int j)
{

int i;

  strcpy(s->Name,s->Banco[j].Name);

  *(s->master_volume) = *(s->Banco[j].master_volume);
  *(s->tune) =  *(s->Banco[j].tune);
  *(s->portamento) = *(s->Banco[j].portamento);
  *(s->LFO_Frequency) =  *(s->Banco[j].LFO_Frequency);
  *(s->LFO_Delay) = *(s->Banco[j].LFO_Delay);
  *(s->LFO_Wave)= *(s->Banco[j].LFO_Wave);
  *(s->LFO_Volume) =  *(s->Banco[j].LFO_Volume);
       
  for (i = 0; i < 6; i++)
    {
      *(s->H[i]) = *(s->Banco[j].H[i]);
      *(s->HF[i]) = *(s->Banco[j].HF[i]);
      *(s->Ovol[i]) = *(s->Banco[j].Ovol[i]);
      *(s->wave[i]) = *(s->Banco[j].wave[i]);
      *(s->attack[i]) = *(s->Banco[j].attack[i]);
      *(s->decay[i]) = *(s->Banco[j].decay[i]);
      *(s->sustain[i]) = *(s->Banco[j].sustain[i]);
      *(s->release[i]) = *(s->Banco[j].release[i]);
      *(s->pLFO[i]) = *(s->Banco[j].pLFO[i]);
    }








};


