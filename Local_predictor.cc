
#include "Local_predictor.h"

Local_predictor::Local_predictor(){
	for(count=0;count<LOCAL_HISTORY_SIZE;count++){
		localHistory[count] = WEAKLY_NOT_TAKEN;
	}
}
Local_predictor::~Local_predictor(){

}
/********************** returns the predicted values *****************************/
bool Local_predictor::get_local_Prediction(branch_record br_obj){
	int temp_address = br_obj.instruction_addr;
	int result = mask(temp_address,LOCAL_HISTORY_MASK);
	if(DEBUG)
		printf("Prediction State in history : %d \n", localHistory[result]);

	if((br_obj.is_call || br_obj.is_return) && !br_obj.is_conditional)
		return true;
	else
		return check(localHistory[mask(temp_address,LOCAL_HISTORY_MASK)],2);
}

/************************ update the local history ***********************************************/
void Local_predictor::update_local_Prediction(branch_record br_obj,bool br_result){
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
	if(DEBUG)
	printf("prediction State of %d is %d",temp_address,predictionState);
	//printb(predictionState,4);
	localHistory[mask(temp_address,LOCAL_HISTORY_MASK)] = predictionState;
}