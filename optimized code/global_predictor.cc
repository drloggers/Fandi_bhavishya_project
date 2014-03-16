#include <iostream>
#include "global_predictor.h"
#include "path_history.h"



Global_predictor::Global_predictor(){
			 for(count=0;count<GLOBAL_PREDICTOR_ENTRIES;count++)
				{
					global_predictor_table[count] = WEAKLY_NOT_TAKEN_2b;
				 	//global_predictor_table[count] = -1;
				}
}

Global_predictor::~Global_predictor(){

}

/**************** returns the prediction of global predictor ************************/
bool Global_predictor::get_global_prediction(const branch_record_c* br_obj,Path_history* ph){
	unsigned int address = br_obj->instruction_addr;
	unsigned int target = br_obj->branch_target;
	unsigned int index = ph->get_path_history() ^ mask(address,GLOBAL_MASK) ^ mask(target,GLOBAL_MASK);
	char prediction = global_predictor_table[index];
	if(DEBUG)
		printf("Prediction State in Global History : %d \n", global_predictor_table[ph->get_path_history()]);
	if(prediction == -1){
		if(br_obj->branch_target > br_obj->instruction_addr)
			return false;
		else
			return true;
	}
	else
		return check(prediction,2);
}

/**************** updates the global history ***************************************/
void Global_predictor::update_global_predictor(const branch_record_c* br_obj,Path_history* ph,bool taken){
	unsigned int address = br_obj->instruction_addr;
	unsigned int target = br_obj->branch_target;
	unsigned int index = ph->get_path_history() ^ mask(address,GLOBAL_MASK) ^ mask(target,GLOBAL_MASK);
	char global_predictionState = global_predictor_table[index];
	if(taken){
		if(global_predictionState < MAX_COUNTER_VAL_2b)
			global_predictionState++;

	}
	else{
		if(global_predictionState > MIN_COUNTER_VAL_2b)
			global_predictionState--;

	}
	if(DEBUG)
		printf("Updated global prediction State of %d is %d\n",ph->get_path_history(),global_predictionState);

		global_predictor_table[index] = global_predictionState;
		if(DEBUG)
			printb(ph->get_path_history(),12);
}



