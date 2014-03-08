/******************************************************************************************
 *
 * Project : Tournament Branch Prediction
 * This file is testing framework for the branch prediction.
 *
******************************************************************************************/

#include "config.h"
#include "predictor.h"
#include "branch_record.h"

int main(){
	branch_record br;
	predictor p;
	FILE *traceFile;
	int dummy;
	traceFile = fopen("tracefile.txt","r");
	printf("trace File reading.......\n");
	while(!feof(traceFile)){
	fscanf(traceFile,"%x %x %x %d %d %d %d %d",&br.instruction_addr,
											   &br.branch_target ,
											   &br.instruction_next_addr,
											   &br.is_indirect,
											   &br.is_conditional,
											   &br.is_call,
											   &br.is_return,
											   &br.is_taken);


	br.is_indirect = (br.is_indirect > 0) ? true:false;
	br.is_call = (br.is_call > 0) ? true:false;
	br.is_conditional = (br.is_conditional > 0) ? true:false;
	br.is_return = (br.is_return > 0) ? true:false;
	br.is_taken = (br.is_taken > 0) ? true:false;


	if(DEBUG)
	printf("\n\n %x %x %x %d %d %d %d %d\n",br.instruction_addr,
									   	    br.branch_target ,
									   	    br.instruction_next_addr,
									   	    br.is_indirect,
									   	    br.is_conditional,
									   	    br.is_call,
									   	    br.is_return,
									   	    br.is_taken);

	dummy = p.getPrediction(br);
	if(DEBUG)
		printf("Prediction returned is ");
	printb(dummy,1);
	p.updatePrediction(br,br.is_taken);

	}
	printf("Trace File end.");
	return 0;
}






