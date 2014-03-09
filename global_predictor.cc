#include <iostream>
#include "global_predictor.h"



Global_predictor::Global_predictor(){
			 for(count=0;count<GLOBAL_PREDICTOR_ENTRIES;count++)
				{
					global_predictor_table[count] = WEAKLY_NOT_TAKEN_2b;
				}
			path_history=0;		//Initialize path history to 0. None of the previous branches taken.
}

Global_predictor::~Global_predictor(){

}

/**************** returns the prediction of global predictor ************************/
bool Global_predictor::get_global_prediction(branch_record br_obj){
	if(DEBUG)
		printf("Prediction State in Global History : %d \n", global_predictor_table[path_history]);
	if((br_obj.is_call || br_obj.is_return) && !br_obj.is_conditional)
		return true;
	else
		return (check(global_predictor_table[path_history],1));
}

/**************** updates the global history ***************************************/
void Global_predictor::update_global_predictor(branch_record br_obj,bool br_result){
	char global_predictionState = global_predictor_table[path_history];
	unsigned short int temp_path_history = path_history;
	path_history = path_history << 1;
	if(br_result){
		global_predictionState++;
		if(global_predictionState > MAX_COUNTER_VAL_2b)
		global_predictionState = MAX_COUNTER_VAL_2b;
		set(path_history,0);
	}
	else{
		global_predictionState--;
		if(global_predictionState < MIN_COUNTER_VAL_2b)
			global_predictionState = MIN_COUNTER_VAL_2b;
		clear(path_history,0);
	}
	mask(path_history,PATH_HISTORY_MASK);
	if(DEBUG)
		printf("Updated global prediction State of %d is %d\n",path_history,global_predictionState);

		global_predictor_table[temp_path_history] = global_predictionState;
		printb(path_history,12);
}



