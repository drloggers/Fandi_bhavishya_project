
#include <iostream>
#include "chooser_predictor.h"
#include "local_predictor.h"
#include "global_predictor.h"
#include "path_history.h"

Chooser_predictor::Chooser_predictor(){
			 for(count=0;count<CHOOSER_PREDICTOR_ENTRIES;count++)
				{
				 chooser_predictor_table[count] = WEAKLY_NOT_TAKEN_2b;
				}
}

Chooser_predictor::~Chooser_predictor(){

}

/**************** returns the prediction of global predictor ************************/
bool Chooser_predictor::get_chooser_prediction(branch_record br_obj){
	Path_history ph;
	if(DEBUG)
		printf("Prediction State in Chooser History : %d \n", chooser_predictor_table[ph.get_path_history()]);
	return check(chooser_predictor_table[ph.get_path_history()],1);
}

/**************** updates the global history ***************************************/
void Chooser_predictor::update_chooser_predictor(branch_record br_obj,bool taken){
	Path_history ph;
	char chooser_predictionState = chooser_predictor_table[ph.get_path_history()];
	if(taken){
		if(chooser_predictionState < MAX_COUNTER_VAL_2b)
			chooser_predictionState++;

	}
	else{
		if(chooser_predictionState > MIN_COUNTER_VAL_2b)
			chooser_predictionState--;

	}

	if(DEBUG)
		printf("Updated chooser prediction State of %d is %d\n",ph.get_path_history(),chooser_predictionState);

	chooser_predictor_table[ph.get_path_history()] = chooser_predictionState;
	if(DEBUG)
		printb(ph.get_path_history(),12);
}




