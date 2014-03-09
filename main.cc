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



int main(){
	branch_record br;
	Predictor p;
/*	Local_predictor lp;
	Global_predictor gp;
	Chooser_predictor cp;*/
	FILE *traceFile;
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
	dummy = p.get_prediction(br);
	if(DEBUG)
		printf("Prediction returned is ");
	printb(dummy,1);
	p.update_predictor(br,br.is_taken);
/**********************************************/
	}// end of while
	printf("\nTrace File end.");
	return 0;
}






