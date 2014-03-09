/*
 Source Code for Chooser Predictor
 */

#include <iostream>
#include "chooser_predictor.h"

Chooser_predictor::Chooser_predictor(){
			 for(count=0;count<CHOOSER_PREDICTOR_ENTRIES;count++)
				{
				 chooser_predictor_table[count] = WEAKLY_NOT_TAKEN_2b;
				}
			path_history=0;		//Initialize path history to 0. None of the previous branches taken.
}

Chooser_predictor::~Chooser_predictor(){

}

/**************** returns the prediction of global predictor ************************/
bool Chooser_predictor::get_chooser_prediction(branch_record br_obj){
	if(DEBUG)
		printf("Prediction State in Chooser History : %d \n", chooser_predictor_table[path_history]);
	if((br_obj.is_call || br_obj.is_return) && !br_obj.is_conditional)
		return true;
	else
		return (check(chooser_predictor_table[path_history],1));
}

/**************** updates the global history ***************************************/
void Chooser_predictor::update_chooser_predictor(branch_record br_obj,bool br_result){
	char chooser_predictionState = chooser_predictor_table[path_history];
	unsigned short int temp_path_history = path_history;
	path_history = path_history << 1;
	if(br_result){
		chooser_predictionState++;
		if(chooser_predictionState > MAX_COUNTER_VAL_2b)
		   chooser_predictionState = MAX_COUNTER_VAL_2b;
		set(path_history,0);
	}
	else{
		chooser_predictionState--;
		if(chooser_predictionState < MIN_COUNTER_VAL_2b)
			chooser_predictionState = MIN_COUNTER_VAL_2b;
		clear(path_history,0);
	}
	mask(path_history,PATH_HISTORY_MASK);
	if(DEBUG)
		printf("Updated chooser prediction State of %d is %d\n",path_history,chooser_predictionState);

	   chooser_predictor_table[temp_path_history] = chooser_predictionState;
		printb(path_history,12);
}




