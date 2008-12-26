/*
  ZynAddSubFX - a software synthesizer
 
  Echo.h - Echo Effect
  Copyright (C) 2002-2005 Nasca Octavian Paul
  Author: Nasca Octavian Paul

  Modified for rakarrack by Josep Andreu
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License 
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2) for more details.

  You should have received a copy of the GNU General Public License (version 2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

#ifndef MUSDELAY_H
#define MUSDELAY_H

#include <ladspa.h>


typedef struct
 {
  unsigned int SAMPLE_RATE;

  LADSPA_Data *efxoutl;
  LADSPA_Data *efxoutr;
  LADSPA_Data *inputl;
  LADSPA_Dara *inputr;
  LADSPA_Data *outvolume;
  LADSPA_Data *dry;
  LADSPA_Data *Ppanning1;		//Panning
  LADSPA_Data *Ppanning2;
  LADSPA_Data *gain1;
  LADSPA_Data *gain2;
  LADSPA_Data *Pdelay1;
  LADSPA_Data *Pdelay2;
  LADSPA_Data *Plrdelay;			// L/R delay difference
  LADSPA_Data *Plrcross;			// L/R Mixing
  LADSPA_Data *Pfb1;			//Feed-back-ul
  LADSPA_Data *Pfb2;
  LADSPA_Data *Phidamp;
  LADSPA_Data *Ptempo;


  //Parametrii reali
  float panning1, panning2, lrcross, fb1, fb2, hidamp;
  int dl1, dr1, dl2, dr2, delay1, delay2, lrdelay;
  void initdelays ();
  float *ldelay1, *rdelay1, *ldelay2, *rdelay2;
  float oldl1, oldr1, oldl2, oldr2;	//pt. lpf
  int kl1, kr1, kl2, kr2;
 } MDelay_t;


  void MusicDelay_Init(MDelay_t * s);
  void out (MDelay_t * s, float * smpsl, float * smpr, unsigned long count);
  void MusicalDelay_Cleanup(MDelay_t * s);
  void setvolume (int Pvolume);
  void setpanning (int num, int Ppanning);
  void setdelay (int num, int Pdelay);
  void setgain (int num, int Pgain);
  void setlrdelay (int Plrdelay);
  void setlrcross (int Plrcross);
  void setfb (int num, int Pfb);
  void sethidamp (int Phidamp);
  void settempo (int Ptempo);


#endif
