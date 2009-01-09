/*
  goomf - a FM mono synth plugin software

  synth.c  -  synthesizer functions
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


#include <math.h>
#include "goomf.h"


void
init_vars (goomf_synth_t * s)
{

  //Init de vars
  s->Master_Volume = 0.70;

// FM Operator frequencys

  s->lasfreq[0] = 0.5;
  s->lasfreq[1] = 0.75;
  s->lasfreq[2] = 1.0;
  s->lasfreq[3] = 1.5;
  s->lasfreq[4] = 2.0;
  s->lasfreq[5] = 2.5;
  s->lasfreq[6] = 3.0;
  s->lasfreq[7] = 4.0;
  s->lasfreq[8] = 4.5;
  s->lasfreq[9] = 5.0;
  s->lasfreq[10] = 6.0;
  s->lasfreq[11] = 7.0;
  s->lasfreq[12] = 7.5;
  s->lasfreq[13] = 8.0;
  s->lasfreq[14] = 9.0;
  s->lasfreq[15] = 10.0;
  s->lasfreq[16] = 10.5;
  s->lasfreq[17] = 11.0;
  s->lasfreq[18] = 12.0;
  s->lasfreq[19] = 13.0;
  s->lasfreq[20] = 14.0;
  s->lasfreq[21] = 16.0;

  New (s);


  s->tune = 0;
  s->pitch = 0.0f;
  s->pedal = 0;


// Init Bank

  New_Bank (s);


  // Init gated notes

  // Init frequency Notes 


  for (i = 1; i <= 192; i++)
    {
      s->h[i].f1 = 8.1757989156 * expf ((float) (i - 2) * logf (2.0) / 12.0);
      s->h[i].f2 = 8.1757989156 * expf ((float) (i) * logf (2.0) / 12.0);
      s->h[i].f3 = 8.1757989156 * expf ((float) (i + 2) * logf (2.0) / 12.0);
    }


  // Allocate memory for calculated sins

  size_t sizesin = (size_t) (D_PI * 1000) + 2;


  memset (s->lsin, 0, sizeof (float) * (sizesin + 4));
  memset (s->nsin, 0, sizeof (float) * (sizesin + 4));
  memset (s->msin, 0, sizeof (float) * (sizesin + 4));
  memset (s->psin, 0, sizeof (float) * (sizesin + 4));
  memset (s->qsin, 0, sizeof (float) * (sizesin + 4));
  memset (s->rsin, 0, sizeof (float) * (sizesin + 4));
  memset (s->tsin, 0, sizeof (float) * (sizesin + 4));
  memset (s->ssin, 0, sizeof (float) * (sizesin + 4));
  memset (s->usin, 0, sizeof (float) * (sizesin + 4));



  float x_sin;
  for (i = 0; i < (int) sizesin; i++)

    {

      x_sin = (float) (i * D_PI / sizesin);
      s->lsin[i] = sinf (x_sin);

      if (i > 0)
	s->lsin[i - 1] =
	  (s->lsin[i - 1] * (1.0 + s->lsin[i] - s->lsin[i - 1]));
      if (i > 1)
	s->lsin[i - 2] =
	  (s->lsin[i - 2] * (1.0 + s->lsin[i - 1] - s->lsin[i - 2]));
      if (i > 2)
	s->lsin[i - 3] =
	  (s->lsin[i - 3] * (1.0 + s->lsin[i - 2] - s->lsin[i - 3]));
      if (i > 3)
	s->lsin[i - 4] =
	  (s->lsin[i - 4] * (1.0 + s->lsin[i - 3] - s->lsin[i - 4]));
      if (i > 4)
	s->lsin[i - 5] =
	  (s->lsin[i - 5] * (1.0 + s->lsin[i - 4] - s->lsin[i - 5]));
      if (i > 5)
	s->lsin[i - 6] =
	  (s->lsin[i - 6] * (1.0 + s->lsin[i - 5] - s->lsin[i - 6]));
      if (i > 6)
	s->lsin[i - 7] =
	  (s->lsin[i - 7] * (1.0 + s->lsin[i - 6] - s->lsin[i - 7]));
      if (i > 7)
	s->lsin[i - 8] =
	  (s->lsin[i - 8] * (1.0 + s->lsin[i - 7] - s->lsin[i - 8]));


    }

  for (i = 0; i < (int) sizesin; i++)
    {

      x_sin = (float) (i * D_PI / sizesin);

      s->nsin[i] = sinf (x_sin + sinf (x_sin));
      s->msin[i] = sinf (x_sin + sinf (1.5 * x_sin));
      if (i > 0)
	s->msin[i - 1] =
	  (s->msin[i - 1] * (1.0 + s->msin[i] - s->msin[i - 1]));
      if (i > 1)
	s->msin[i - 2] =
	  (s->msin[i - 2] * (1.0 + s->msin[i - 1] - s->msin[i - 2]));
      if (i > 2)
	s->msin[i - 3] =
	  (s->msin[i - 3] * (1.0 + s->msin[i - 2] - s->msin[i - 3]));
      if (i > 3)
	s->msin[i - 4] =
	  (s->msin[i - 4] * (1.0 + s->msin[i - 3] - s->msin[i - 4]));
      if (i > 4)
	s->msin[i - 5] =
	  (s->msin[i - 5] * (1.0 + s->msin[i - 4] - s->msin[i - 5]));
      if (i > 5)
	s->msin[i - 6] =
	  (s->msin[i - 6] * (1.0 + s->msin[i - 5] - s->msin[i - 6]));
      if (i > 6)
	s->msin[i - 7] =
	  (s->msin[i - 7] * (1.0 + s->msin[i - 6] - s->msin[i - 7]));
      if (i > 7)
	s->msin[i - 8] =
	  (s->msin[i - 8] * (1.0 + s->msin[i - 7] - s->msin[i - 8]));

      s->psin[i] = sinf (x_sin + sinf (2.0 * x_sin));
      s->qsin[i] = sinf (s->nsin[i] + s->lsin[i] + s->psin[i]);
      s->rsin[i] = sinf (s->lsin[i] + sinf (s->msin[i]));
      s->tsin[i] = sinf (s->lsin[i]);

      s->ssin[i] =
	(s->lsin[i] + s->nsin[i] + s->msin[i] + s->psin[i] + s->qsin[i] +
	 s->rsin[i] + s->tsin[i]) / 7.0;
      if (i > 0)
	s->ssin[i - 1] =
	  (s->ssin[i - 1] * (1.0 + s->ssin[i] - s->ssin[i - 1]));
      if (i > 1)
	s->ssin[i - 2] =
	  (s->ssin[i - 2] * (1.0 + s->ssin[i - 1] - s->ssin[i - 2]));
      if (i > 2)
	s->ssin[i - 3] =
	  (s->ssin[i - 3] * (1.0 + s->ssin[i - 2] - s->ssin[i - 3]));
      if (i > 3)
	s->ssin[i - 4] =
	  (s->ssin[i - 4] * (1.0 + s->ssin[i - 3] - s->ssin[i - 4]));
      if (i > 4)
	s->ssin[i - 5] =
	  (s->ssin[i - 5] * (1.0 + s->ssin[i - 4] - s->ssin[i - 5]));
      if (i > 5)
	s->ssin[i - 6] =
	  (s->ssin[i - 6] * (1.0 + s->ssin[i - 5] - s->ssin[i - 6]));
      if (i > 6)
	s->ssin[i - 7] =
	  (s->ssin[i - 7] * (1.0 + s->ssin[i - 6] - s->ssin[i - 7]));
      if (i > 7)
	s->ssin[i - 8] =
	  (s->ssin[i - 8] * (1.0 + s->ssin[i - 7] - s->ssin[i - 8]));

      s->usin[i] = sinf (s->ssin[i]);

    }


  for (i = 0; i < (int) sizesin; i++)
    {
      x_sin = (float) (i * D_PI / sizesin);
      s->ssin[i] = sinf (x_sin + s->usin[i]);

    }


// Init Buffers


  memset (s->buf, 0, sizeof(float)* 8192 );


};




void
Adjust_Audio (goomf_synth_t * s)
{

  s->increment = .5 / s->SAMPLE_RATE;
  s->D_PI_to_SAMPLE_RATE = D_PI / s->SAMPLE_RATE;

}

// Keyboard Level Scaling
float
Get_Keyb_Level_Scaling (goomf_synth_t * s, int nota)
{
  return (1.5 * s->velocity[nota] * sin ((120 - s->note[nota]) / 120.0));
};




// Returns the FM Operator Pitch (Frequency + LFO)

float
pitch_Operator (goomf_synth_t * s, int i)
{
  return (s->lasfreq[s->Operator[i].harmonic] +
	  s->Operator[i].harmonic_fine);
}


float
pitch_Operator2 (goomf_synth_t * s, int i)
{
  return (s->lasfreq[s->Operator[i].harmonic] -
	  s->Operator[i].harmonic_fine);
}





// Turn Off all the sound


void
panic (goomf_synth_t * s)
{
};



float
Jenvelope (goomf_synth_t * s, int op, int gate, float t)
{

  float Env = 0.0f;

  if (gate)
    {
      if (t > s->Op[op].attack + s->Op[op].decay)
	return (s->Op[op].sustain);
      if (t > s->Op[op].attack)
	return (1.0 - (1.0 - s->Op[op].sustain) * (t - s->Op[op].attack) * (1.0 / s->Op[op].decay ));

      return (t * s->u_attack);
    }
  else
    {

      if (s->pedal == 0)
	{
	  if (s->Op[op].release > t)
	    {
	      Env = s->Envelope_Volume * (1.0 - t * (1.0 / s->Op[op].release ));
	      if (Env < 0.0015)
		{
		  s->env_time=0.0f;
		  return (0.0f);
		}

	      else
		return (Env);
	    }
	  else
	    {
	      s->env_time=0.0f;
	      return (0.0f);
	    }
	}

      else
	{
	  if (s->Op[op].sustain != 0)
	    return (s->Op[op].sustain);
	  else
	    return (1.0 - (t - s->Op[op].attack) * ( 1.0 / s->Op[op].decay ));
	}
    }

  return (Env);
};



// Returns Pitch LFO 


float
Pitch_LFO (goomf_synth_t * s, float t)
{

  float x, out;

  if (t * 20 < s->Pitch_LFO_Delay)
  return (0.0f);

  x = fmodf (s->Pitch_LFO_Speed * t, 1.0);

  out = NFsin (s, s->LFO_Wave, x * D_PI) * s->LFO_Frequency;

  return (out);

}


// Return Played Note Frequency

float
Get_Partial (goomf_synth_t * s, int nota)
{
  int l;
  float partial = 0;
  float freq_note = 0;

  l = s->note[nota] + 12;
  freq_note =
    (s->pitch >
     0) ? s->h[l].f2 + (s->h[l].f3 - s->h[l].f2) * s->pitch : s->h[l].f2 +
    (s->h[l].f2 - s->h[l].f1) * s->pitch;
  partial = (1.0 + *(s->tune) / 16.0) * freq_note * s->D_PI_to_SAMPLE_RATE;
  if (partial > D_PI)
    partial = fmodf (partial, D_PI);
  return (partial);


};


void
Calc_LFO_Frequency (goomf_synth_t * s)
{

   float modulation = *(s->modulation);
   s->LFO_Frequency =  modulation * s->LFOpitch * s->D_PI_to_SAMPLE_RATE;

};




float
NFsin (goomf_synth_t * s, int i, float x)
{


  long int k = F2I (x * 1000.0);

  if (i == 1)
    return (s->lsin[k]);
  if (i == 2)
    return (s->nsin[k]);
  if (i == 3)
    return (s->msin[k]);
  if (i == 4)
    return (s->psin[k]);
  if (i == 5)
    return (s->qsin[k]);
  if (i == 6)
    return (s->rsin[k]);
  if (i == 7)
    return (s->tsin[k]);
  if (i == 8)
    return (s->ssin[k]);
  if (i == 9)
    return (s->usin[k]);



  return 0.0;
};




// Main Audio thread

void
Alg1s (goomf_synth_t * s, int nframes)
{

  int l2, i;
  int l1;
  float sound, sound2;
  float Env_Vol = 0.0f;
  float mEnv_Vol = 0.0f;
  float LFO_Volume = 0.0f;

  memset (s->buf, 0, sizeof(float) * 8192);


	  m_partial = Get_Partial (s);

	  for (l1 = 0; l1 < nframes; l1 += 2)
	    {

	      sound = 0.0f;
	      sound2 = 0.0f;

	      LFO_Volume = Pitch_LFO(s,s->env_time);

	      for (i = 0; i < 6; i =+2)
		{

                 //L
                 
                      Env_Vol = velocity*Op[i].volumen*Jenvelope(s,i,s->gate,s->env_time)*s->LFO_Volume*Op[i].aLFO;
                      Envelope_Volume = Env_vol;

		      s->f[i].dphi = Get_Partial(s) * (pitch_Operator(s,i)+s->LFO_Volume*Op[i].pLFO);
		      if (s->f[i].dphi > D_PI) s->f[i].dphi -= D_PI;
		      s->f[i].phi += s->f[i].dphi;
		      if (s->f[i].phi > D_PI) s->f[i].phi -= D_PI;

                      mEnv_Vol = velocity*Op[i+1].volumen*Jenvelope(s,i+1,s->gate,s->env_time)*s->LFO_Volume*Op[i+1].aLFO;

		      s->f[i+1].dphi = Get_Partial(s) * (pitch_Operator(s,i+1)+s->LFO_Volume*Op[i+1].pLFO);
		      if (s->f[i+1].dphi > D_PI) s->f[i+1].dphi -= D_PI;
		      s->f[i+1].phi += s->f[i+1].dphi;
		      if (s->f[i+1].phi > D_PI) s->f[i+1].phi -= D_PI;
                      
                  //R 

		      s->f[i].dphi2 = Get_Partial(s) * (pitch_Operator2(s,i)+s->LFO_Volume*Op[i].pLFO);
		      if (s->f[i].dphi2 > D_PI)	s->f[i].dphi2 -= D_PI;
		      s->f[i].phi2 += s->f[i].dphi2;
		      if (s->f[i].phi2 > D_PI) s->f[i].phi2 -= D_PI;

		      s->f[i+1].dphi2 = Get_Partial(s) * (pitch_Operator2(s,i+1)+s->LFO_Volume*Op[i+1].pLFO);
		      if (s->f[i+1].dphi2 > D_PI) s->f[i+1].dphi2 -= D_PI;
		      s->f[i+1].phi2 += s->f[i+1].dphi2;
		      if (s->f[i+1].phi2 > D_PI) s->f[i+1].phi2 -= D_PI;



	      sound += Env_Vol * NFsin (s, s->Op[i].wave, s->f[i].phi + mEnv_Vol * NFsin(s,s->Op[i+1].wave,s->f[i+1].phi));
	      sound2 += Env_Vol * NFsin (s, s->Op[i].wave, s->f[i].phi2 + mEnv_Vol * NFsin(s,s->Op[i+1].wave,s->f[i+1].phi2));

		}

	      s->buf[l1] += sound * s->master_volume;
	      s->buf[l1 + 1] += sound2 * s->master_volume;
	      s->env_time += s->increment;
	    }





};

