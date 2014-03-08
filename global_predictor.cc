
#include "global_predictor.h"

global_predictor::global_predictor(){
			 for(count=0;count<GLOBAL_HISTORY_ENTRIES;count++)
				{
					globalHistory[count] = WEAKLY_NOT_TAKEN;
				}
			path_history=0;		//Initialize path history to 0. None of the previous branches taken.
		}
global_predictor::~global_predictor(){

}

bool global_predictor::get_global_prediction(branch_record br_obj){
			if(DEBUG)
					printf("Prediction State in Global History : %d \n", globalHistory[path_history]);

					if((br_obj.is_call || br_obj.is_return) && !br_obj.is_conditional)
						return true;
					else
						return (check(globalHistory[path_history],0b01));

				}
void global_predictor::update_global_predictor(branch_record br_obj,bool br_result){
	{

					char global_predictionState = globalHistory[path_history];
					if(br_result){
						global_predictionState++;
						if(global_predictionState > MAX_GLOBAL_COUNTER_VAL)
							global_predictionState = MAX_GLOBAL_COUNTER_VAL;
					}
					else{
						global_predictionState--;
						if(global_predictionState < MIN_GLOBAL_COUNTER_VAL)
							global_predictionState = MIN_GLOBAL_COUNTER_VAL;
					}
					if(DEBUG)
						printf("Updated global prediction State of %d is %d\n",path_history,global_predictionState);
					globalHistory[path_history] = global_predictionState;

					path_history = path_history << 1;
					set(path_history,1);
					mask(path_history,GLOBAL_HISTORY_MASK);
				}

}

