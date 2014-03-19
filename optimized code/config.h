
#include <iostream>
#include <stdio.h>
#include <bitset>
#include "tread.h"

/*****constants*****/
#define DEBUG 						0

#define LOCAL_PREDICTOR_SIZE		1024
#define GLOBAL_PREDICTOR_ENTRIES  	4096
#define CHOOSER_PREDICTOR_ENTRIES 	4096

// For 3 bit counter
#define STRONGLY_TAKEN_3b     		0b111
#define WEAKLY_TAKEN_3b       		0b100
#define STRONGLY_NOT_TAKEN_3b  	    0b000
#define WEAKLY_NOT_TAKEN_3b    	    0b011

#define MAX_COUNTER_VAL_3b     		0b111		// strongly taken
#define MIN_COUNTER_VAL_3b     		0b000		// strongly not taken

//For 2 bit counter
#define STRONGLY_TAKEN_2b     		0b11
#define WEAKLY_TAKEN_2b       		0b10
#define STRONGLY_NOT_TAKEN_2b  	    0b00
#define WEAKLY_NOT_TAKEN_2b    	    0b01

#define MAX_COUNTER_VAL_2b     	    0b11		// strongly taken
#define MIN_COUNTER_VAL_2b     	    0b00		// strongly not taken

//Masks
#define LOCAL_HISTORY_MASK_11_2  	0xFFFFF003  // made first 22 bits high to get only 10 bits
#define PATH_HISTORY_MASK  			0xF000	//Masks upper 4 bits of unsigned short int to obtain 12 bits.
#define GLOBAL_MASK					0xFFFFF000
#define LOCAL_HISTORY_MASK_9_0  	0xFFFFFC00  // made first 22 bits high to get only 10 bits


#define PATH_HISTORY_LENGTH 		12


/******macros*******/
#define set(number,position)     (number|=(1<<position))
#define clear(number,position)   (number&=(~(1<<position)))
#define check(number,position)   (number&(1<<position))

#define mask(number,bits)        (number&=(~bits))
#define printb(number,bits)      {int i;for(i=bits-1;i>=0;i--){if(check(number,i)) printf("1");else printf("0");}printf("\n");}


