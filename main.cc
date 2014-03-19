/******************************************************************************************
 *
 * Project : Tournament Branch Prediction
 * This file is testing framework for the branch prediction.
 *
******************************************************************************************/

#include "config.h"
#include "local_predictor.h"
#include "global_predictor.h"
#include "branch_record.h"
#include "chooser_predictor.h"
#include "predictor.h"

bool test(){
	return (check(0x01,1));
}


int main(){
	/********************** initializing for testing purpose **********************/
	branch_record_c br;
	op_state_c os;
	PREDICTOR p;
	FILE *traceFile;


/*	Local_predictor lp;
	Global_predictor gp;
	Chooser_predictor cp;*/

	unsigned int dummy,indirect,conditional,call,return1,taken;
	traceFile = fopen("tracefile.txt","r");
	printf("trace File reading.......\n");
	while(!feof(traceFile)){
/******* Scanning file Lines******************/
	fscanf(traceFile,"%x %x %x %d %d %d %d %d",&br.instruction_addr,
											   &br.branch_target ,
											   &br.instruction_next_addr,
											   &indirect,
											   &conditional,
											   &call,
											   &return1,
											   &taken);

/******* Converting to boolean***************/
	br.is_indirect = (indirect > 0) ? true:false;
	br.is_call = (call > 0) ? true:false;
	br.is_conditional = (conditional > 0) ? true:false;
	br.is_return = (return1 > 0) ? true:false;
	br.is_taken = (taken > 0) ? true:false;
/*********************************************/

	if(DEBUG)
	printf("\n\n %x %x %x %d %d %d %d %d\n",br.instruction_addr,
									   	    br.branch_target ,
									   	    br.instruction_next_addr,
									   	    br.is_indirect,
									   	    br.is_conditional,
									   	    br.is_call,
									   	    br.is_return,
									   	    br.is_taken);

/*********** Calling Local predictor ***********/
	dummy = p.get_prediction(&br,&os);
	if(DEBUG)
		printf("Prediction returned is ");
	printb(dummy,1);
	p.update_predictor(&br,&os, br.is_taken);
/**********************************************/
	}// end of while
	printf("\nTrace File end.");
	dummy = 0x02;
	printf("\nxor thing :");
	printf("%d",check(dummy,1));
	printf("\nxor thing :");
	printb((check(dummy,1)),2);
	printf("\nxor thing :");
	printb((check(dummy,2)),1);

	printf("%d",test());
	return 0;
}






