/*****constants*****/
#define DEBUG 				1

#define LOCAL_HISTORY_SIZE	1024
#define STRONGLY_TAKEN     	0b111
#define WEAKLY_TAKEN       	0b100
#define STRONGLY_NOT_TAKEN  0b000
#define WEAKLY_NOT_TAKEN    0b011
#define MAX_COUNTER_VAL     0b111		// strongly taken
#define MIN_COUNTER_VAL     0b000		// strongly not taken
#define LOCAL_HISTORY_MASK  4294966297  // made first 22 bits high to get only 10 bits

/******macros*******/
#define set(number,position)     (number|=(1<<position))
#define clear(number,position)   (number&=(~(1<<position)))
#define check(number,position)   (number&(1<<position))

#define mask(number,bits)        (number&=(~bits))
#define printb(number,bits)		 {int i;int temp = number; for(i=0;i<bits;i++){if((temp&((1<<bits)-1))!=0) printf("1"); else printf("0"); temp<<=1;}printf("\n");}



