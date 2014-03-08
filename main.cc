

#include <iostream>
#include <stdio.h>
#include <bitset>
/*****constants*****/
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


/*********Class***********/
class branch_record
{
public:
    unsigned int   instruction_addr;       // the branch's PC (program counter)
    unsigned int   branch_target;          // this is the target of the branch if it's taken; branches that aren't conditional are always taken
    unsigned int   instruction_next_addr;  // the PC of the static instruction following the branch
    bool   is_indirect;            // true if the target is computed; false if it's PC-rel; returns are also considered indirect
    bool   is_conditional;         // true if the branch is conditional; false otherwise
    bool   is_call;                // true if the branch is a call; false otherwise
    bool   is_return;              // true if the branch is a return; false otherwise
    bool   is_taken;

    void branch_record_c(){
        instruction_addr      = 0x0;
        branch_target         = 0x0;
        instruction_next_addr = 0x0;
        is_indirect           = false;
        is_conditional        = false;
        is_call               = false;
        is_return             = false;
        is_taken			  = false;
    }

};

class predictor{
	char localHistory[LOCAL_HISTORY_SIZE];
	int count;
public:
	predictor(){
			for(count=0;count<LOCAL_HISTORY_SIZE;count++){
				localHistory[count] = WEAKLY_NOT_TAKEN;
			}
		}
	bool getPrediction(branch_record br_obj){
		int temp_address = br_obj.instruction_addr;
		printf("Prediction State in history : %d \n", localHistory[mask(temp_address,LOCAL_HISTORY_MASK)]);

		if((br_obj.is_call || br_obj.is_return) && !br_obj.is_conditional)
			return true;
		else
			return mask(localHistory[mask(temp_address,LOCAL_HISTORY_MASK)],0b11)>>2;
	}
	void updatePrediction(branch_record br_obj,bool br_result){
		int temp_address = br_obj.instruction_addr;
		char predictionState = localHistory[mask(temp_address,LOCAL_HISTORY_MASK)];
		if(br_result){
			predictionState++;
			if(predictionState > MAX_COUNTER_VAL)
				predictionState = MAX_COUNTER_VAL;
		}
		else{
			predictionState--;
			if(predictionState < MIN_COUNTER_VAL)
				predictionState = MIN_COUNTER_VAL;
		}
		printf("prediction State of %d is %d",temp_address,predictionState);
		//printb(predictionState,4);
		printf("\n");
		localHistory[mask(temp_address,LOCAL_HISTORY_MASK)] = predictionState;
	}
};


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



	printf("\n\n %x %x %x %d %d %d %d %d\n",br.instruction_addr,
									   br.branch_target ,
									   br.instruction_next_addr,
									   br.is_indirect,
									   br.is_conditional,
									   br.is_call,
									   br.is_return,
									   br.is_taken);
	/*dummy = p.getPrediction(br);
		printf("My function returns : %d\n",dummy);
	*/

	dummy = p.getPrediction(br);
	printf("Prediction returned is ");
	printb(dummy,1);
	p.updatePrediction(br,br.is_taken);

	}










	/*dummy = 15;
	printf("dummy -> ");
	printb(dummy,4);
	printf("\n");
	//printf("dummy is this-> %d\n",);
	mask(dummy,0b10);
	printf("set macro (0,1): ");
	printb(dummy,4);
	if(check(dummy,3))
		printf("\nYes");
	else
		printf("\nNo");*/
	return 0;
}






