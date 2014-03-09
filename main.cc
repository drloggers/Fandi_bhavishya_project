/******************************************************************************************
 *
 * Project : Tournament Branch Prediction
 * This file is testing framework for the branch prediction.
 *
******************************************************************************************/

#include "config.h"
#include "Local_predictor.h"
#include "Branch_record.h"

int main(){
	branch_record br;
	Local_predictor p;
	FILE *traceFile;
	int dummy,indirect,conditional,call,return1,taken;
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
	dummy = p.get_local_Prediction(br);
	if(DEBUG)
		printf("Prediction returned is ");
	printb(dummy,1);
	p.update_local_Prediction(br,br.is_taken);
/**********************************************/
	}// end of while
	printf("\nTrace File end.");
	return 0;
}






