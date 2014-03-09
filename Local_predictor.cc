
#include "Local_predictor.h"

Local_predictor::Local_predictor(){
	for(count=0;count<LOCAL_PREDICTOR_SIZE;count++){
		local_predictor_table[count] = WEAKLY_NOT_TAKEN_3b;
	}
}
Local_predictor::~Local_predictor(){

}
/********************** returns the predicted values *****************************/
bool Local_predictor::get_local_prediction(branch_record br_obj){
	int temp_address = br_obj.instruction_addr;
	int result = mask(temp_address,LOCAL_HISTORY_MASK);
	if(DEBUG)
		printf("Prediction State in history : %d \n", local_predictor_table[result]);

	if((br_obj.is_call || br_obj.is_return) && !br_obj.is_conditional)
		return true;
	else
		return check(local_predictor_table[mask(temp_address,LOCAL_HISTORY_MASK)],2);
}

/************************ update the local history ***********************************************/
void Local_predictor::update_local_predictor(branch_record br_obj,bool br_result){
	int temp_address = br_obj.instruction_addr;
	char predictionState = local_predictor_table[mask(temp_address,LOCAL_HISTORY_MASK)];
	if(br_result){
		predictionState++;
		if(predictionState > MAX_COUNTER_VAL_3b)
			predictionState = MAX_COUNTER_VAL_3b;
	}
	else{
		predictionState--;
		if(predictionState < MIN_COUNTER_VAL_3b)
			predictionState = MIN_COUNTER_VAL_3b;
	}
	if(DEBUG)
	printf("prediction State of %d is %d",temp_address,predictionState);
	//printb(predictionState,4);
	local_predictor_table[mask(temp_address,LOCAL_HISTORY_MASK)] = predictionState;
}
