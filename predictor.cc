
#include "predictor.h"
#include "branch_record.h"
#include "local_predictor.h"
#include "global_predictor.h"
#include "chooser_predictor.h"
#include "path_history.h"

Local_predictor lp;
Global_predictor gp;
Chooser_predictor cp;
Path_history ph;


Predictor::Predictor(){
	path_history=0;		//Initialize path history to 0. None of the previous branches taken.
}
Predictor::~Predictor(){

}

bool Predictor::get_prediction(branch_record br_obj){
	if((br_obj.is_call || br_obj.is_return) && !br_obj.is_conditional)
		return true;
	if(lp.get_local_prediction(br_obj) == gp.get_global_prediction(br_obj))
		return gp.get_global_prediction(br_obj); 	// any one will work
	else{
		if(cp.get_chooser_prediction(br_obj))			// if 1 -> choose local
			return lp.get_local_prediction(br_obj);
		else											// else if 0 -> choose global
			return gp.get_global_prediction(br_obj);
	}
}

void Predictor::update_predictor(branch_record br_obj,bool taken){

	if(lp.get_local_prediction(br_obj) == taken && gp.get_global_prediction(br_obj) != taken)
		cp.update_chooser_predictor(br_obj,1);			// choose local
	if(gp.get_global_prediction(br_obj) == taken && lp.get_local_prediction(br_obj) != taken)
		cp.update_chooser_predictor(br_obj,0);			// choose global
	// else no change in chooser predictor

	lp.update_local_predictor(br_obj,taken);
	gp.update_global_predictor(br_obj,taken);
	ph.update_path_history(taken);

}


