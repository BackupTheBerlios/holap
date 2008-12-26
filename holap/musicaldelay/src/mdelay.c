/*
  ZynAddSubFX - a software synthesizer
 
  Echo.C - Echo effect
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mdelay.h"

void
MusicDelay_Init(MDelay_t * s)
{

  //default values
  Ppreset = 0;
  Pvolume = 50;
  Ppanning1 = 64;
  Ppanning2 = 64;
  Pgain1 = 64;
  Pgain2 = 64;
  Pdelay1 = 60;
  Pdelay2 = 60;
  Plrdelay = 100;
  Plrcross = 100;
  Pfb1 = 40;
  Pfb2 = 40;
  Ptempo = 100;
  Phidamp = 60;

  ldelay1 = NULL;
  rdelay1 = NULL;
  ldelay2 = NULL;
  rdelay2 = NULL;


  lrdelay = 0;

  MusicalDelay_Cleanup (s);
};

/*
 * Cleanup the effect
 */
void
MusicDelay_Cleanup (MDelay_t * s)
{
  int i;
  for (i = 0; i < dl1; i++)
    ldelay1[i] = 0.0;
  for (i = 0; i < dr1; i++)
    rdelay1[i] = 0.0;
  for (i = 0; i < dl2; i++)
    ldelay2[i] = 0.0;
  for (i = 0; i < dr2; i++)
    rdelay2[i] = 0.0;

  oldl1 = 0.0;
  oldr1 = 0.0;
  oldl2 = 0.0;
  oldr2 = 0.0;
};


/*
 * Initialize the delays
 */
void
MusicDelay_initdelays (MDelay_t * s)
{
  kl1 = 0;
  kr1 = 0;
  dl1 = delay1;
  if (dl1 < 1)
    dl1 = 1;
  dr1 = delay1;
  if (dr1 < 1)
    dr1 = 1;
  kl2 = 0;
  kr2 = 0;
  dl2 = delay2 + lrdelay;
  if (dl2 < 1)
    dl2 = 1;
  dr2 = delay2 + lrdelay;
  if (dr2 < 1)
    dr2 = 1;


  if (ldelay1 != NULL)
    delete[]ldelay1;
  if (rdelay1 != NULL)
    delete[]rdelay1;
  ldelay1 = new float[dl1];
  rdelay1 = new float[dr1];
  if (ldelay2 != NULL)
    delete[]ldelay2;
  if (rdelay2 != NULL)
    delete[]rdelay2;
  ldelay2 = new float[dl2];
  rdelay2 = new float[dr2];



  MusicalDelay_Cleanup (s);
};

/*
 * Effect output
 */
void
out (MDelay_t * s, float * smpsl, float * smpsr, unsigned long count)
{
  int i;
  float l1, r1, ldl1, rdl1, l2, r2, ldl2, rdl2;

  for (i = 0; i < count; i++)
    {
      ldl1 = ldelay1[kl1];
      rdl1 = rdelay1[kr1];
      l1 = ldl1 * (1.0 - lrcross) + rdl1 * lrcross;
      r1 = rdl1 * (1.0 - lrcross) + ldl1 * lrcross;
      ldl1 = l1;
      rdl1 = r1;

      ldl2 = ldelay2[kl2];
      rdl2 = rdelay2[kr2];
      l2 = ldl2 * (1.0 - lrcross) + rdl2 * lrcross;
      r2 = rdl2 * (1.0 - lrcross) + ldl2 * lrcross;
      ldl2 = l2;
      rdl2 = r2;

      ldl1 = smpsl[i] * gain1 * panning1 - ldl1 * fb1;
      rdl1 = smpsr[i] * gain1 * (1.0 - panning1) - rdl1 * fb1;

      ldl2 = smpsl[i] * gain2 * panning2 - ldl2 * fb2;
      rdl2 = smpsr[i] * gain2 * (1.0 - panning2) - rdl2 * fb2;

      efxoutl[i] = (ldl1 + ldl2) * 2.0;
      efxoutr[i] = (rdl1 + rdl2) * 2.0;



      //LowPass Filter
      ldelay1[kl1] = ldl1 = ldl1 * hidamp + oldl1 * (1.0 - hidamp);
      rdelay1[kr1] = rdl1 = rdl1 * hidamp + oldr1 * (1.0 - hidamp);
      oldl1 = ldl1;
      oldr1 = rdl1;

      ldelay2[kl2] = ldl2 = ldl2 * hidamp + oldl2 * (1.0 - hidamp);
      rdelay2[kr2] = rdl2 = rdl2 * hidamp + oldr2 * (1.0 - hidamp);
      oldl2 = ldl2;
      oldr2 = rdl2;

      if (++kl1 >= dl1)
	kl1 = 0;
      if (++kr1 >= dr1)
	kr1 = 0;

      if (++kl2 >= dl2)
	kl2 = 0;
      if (++kr2 >= dr2)
	kr2 = 0;

    };

};


/*
 * Parameter control

void
MusicDelay::setvolume (int Pvolume)
{
  this->Pvolume = Pvolume;

  volume = outvolume = (float) Pvolume / 127.0;
  if (Pvolume == 0)
    cleanup ();

};

void
MusicDelay::setpanning (int num, int Ppanning)
{

  switch (num)
    {
    case 1:
      this->Ppanning1 = Ppanning;
      panning1 = ((float) Ppanning1 + 0.5) / 127.0;
      break;
    case 2:
      this->Ppanning2 = Ppanning;
      panning2 = ((float) Ppanning2 + 0.5) / 127.0;
      break;
    }

};

void
MusicDelay::setdelay (int num, int Pdelay)
{

  float ntem = 60.0 / (float) Ptempo;
  float coef;
  switch (num)
    {
    case 1:
      this->Pdelay1 = Pdelay;
      break;
    case 2:
      this->Pdelay2 = Pdelay;
      break;
    case 3:
      this->Plrdelay = Pdelay;
    }

  delay1 = (int) ((ntem / Pdelay1) * SAMPLE_RATE);

  if (Plrdelay != 0)
    coef = ntem / Plrdelay;
  else
    coef = 0;
  delay2 = (int) ((coef + (ntem / Pdelay2)) * SAMPLE_RATE);


  initdelays ();

};

void
MusicDelay::setlrcross (int Plrcross)
{
  this->Plrcross = Plrcross;
  lrcross = (float) Plrcross / 127.0 * 1.0;
};

void
MusicDelay::setfb (int num, int Pfb)
{
  switch (num)
    {
    case 1:
      this->Pfb1 = Pfb;
      fb1 = (float) Pfb1 / 128.0;
      break;
    case 2:
      this->Pfb2 = Pfb;
      fb2 = (float) Pfb2 / 128.0;
      break;
    }
};

void
MusicDelay::sethidamp (int Phidamp)
{
  this->Phidamp = Phidamp;
  hidamp = 1.0 - (float) Phidamp / 127.0;
};

void
MusicDelay::settempo (int Ptempo)
{

  float coef = 0.0;

  this->Ptempo = Ptempo;
  float ntem = 60.0 / (float) Ptempo;


  delay1 = (int) ((ntem / Pdelay1) * SAMPLE_RATE);
  if (Plrdelay != 0)
    coef = ntem / Plrdelay;
  else
    coef = 0;
  delay2 = (int) ((coef + (ntem / Pdelay2)) * SAMPLE_RATE);

  initdelays ();



};

*/
