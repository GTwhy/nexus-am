/***************************************************************************
 *   Copyright (C) 2013 by James Holodnak                                  *
 *   jamesholodnak@gmail.com                                               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "mappers/mapperinc.h"
#include "mappers/chips/latch.h"

static u8 readchr(u32 addr)
{
	return(0x12);
}

static void sync()
{
	int i;

	//chr enabled
	if((latch_data & 0xF) && latch_data != 0x13) {
		mem_setchr8(0,0);
		for(i=0;i<8;i++)
			nes->ppu.readfuncs[i] = 0;
	}

	//chr disabled
	else {
		mem_unsetppu8(0);
		for(i=0;i<8;i++)
			nes->ppu.readfuncs[i] = readchr;
	}
}

static void reset(int hard)
{
	latch_reset(sync,hard);
	mem_setprg16(0x8,0);
	mem_setprg16(0xC,(u32)-1);
}

MAPPER(B_NINTENDO_CNROM_CP,reset,0,0,latch_state);
