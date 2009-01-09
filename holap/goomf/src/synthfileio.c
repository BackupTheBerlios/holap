/*
  goomf  a FM mono synth plugin software

  synthfileio.c  -  File Input/Output functions
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

#define BANK_EXTENSION ".goomf"

int
loadbank (goomf_synth_t * s, const char *filename)
{

  FILE *fn;


  if ((fn = fopen (filename, "r")) == NULL)
    {
      fprintf (stderr, "File not found\n");
      return 1;
    }

  fclose (fn);
  return 0;
};
