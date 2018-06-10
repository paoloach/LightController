#ifndef __BIT_IO_H__
/**************************************************************************************************

 DESCRIPTION:
  --

 CREATED: 18/06/2016, by Paolo Achdjian

 FILE: bit_IO.h

***************************************************************************************************/
#define __BIT_IO_H__

__sfr __no_init volatile struct  {
	unsigned char P0IF0: 1;
	unsigned char P0IF1: 1;
	unsigned char P0IF2: 1;
	unsigned char P0IF3: 1;
	unsigned char P0IF4: 1;
	unsigned char P0IF5: 1;
	unsigned char P0IF6: 1;
	unsigned char P0IF7: 1;	
} @ 0x89;

__sfr __no_init volatile struct  {
	unsigned char P0ICON: 1;
	unsigned char P1ICON_L: 1;
	unsigned char P1ICON_H: 1;
	unsigned char P2ICON: 1;
	unsigned char PICTL4: 1;
	unsigned char PICTL5: 1;
	unsigned char PICTL6: 1;
	unsigned char PADSC: 1;
} @ 0x8C;

__sfr __no_init volatile struct  {
	unsigned char P0IEN_0: 1;
	unsigned char P0IEN_1: 1;
	unsigned char P0IEN_2: 1;
	unsigned char P0IEN_3: 1;
	unsigned char P0IEN_4: 1;
	unsigned char P0IEN_5: 1;
	unsigned char P0IEN_6: 1;
	unsigned char P0IEN_7: 1;
} @ 0xAB;

__sfr __no_init volatile struct  {
	unsigned char P0SEL_0: 1;
	unsigned char P0SEL_1: 1;
	unsigned char P0SEL_2: 1;
	unsigned char P0SEL_3: 1;
	unsigned char P0SEL_4: 1;
	unsigned char P0SEL_5: 1;
	unsigned char P0SEL_6: 1;
	unsigned char P0SEL_7: 1;
} @ 0xF3;

__sfr __no_init volatile struct  {
	unsigned char P1SEL_0: 1;
	unsigned char P1SEL_1: 1;
	unsigned char P1SEL_2: 1;
	unsigned char P1SEL_3: 1;
	unsigned char P1SEL_4: 1;
	unsigned char P1SEL_5: 1;
	unsigned char P1SEL_6: 1;
	unsigned char P1SEL_7: 1;
} @ 0xF4;

__sfr __no_init volatile struct  {
	unsigned char DIR0_0: 1;
	unsigned char DIR0_1: 1;
	unsigned char DIR0_2: 1;
	unsigned char DIR0_3: 1;
	unsigned char DIR0_4: 1;
	unsigned char DIR0_5: 1;
	unsigned char DIR0_6: 1;
	unsigned char DIR0_7: 1;
} @ 0xFD;

__sfr __no_init volatile struct  {
	unsigned char DIR1_0: 1;
	unsigned char DIR1_1: 1;
	unsigned char DIR1_2: 1;
	unsigned char DIR1_3: 1;
	unsigned char DIR1_4: 1;
	unsigned char DIR1_5: 1;
	unsigned char DIR1_6: 1;
	unsigned char DIR1_7: 1;
} @ 0xFE;



#endif