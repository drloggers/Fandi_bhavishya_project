
#include "predictor.h"
#include "config.h"
#include "local_predictor.h"
#include "global_predictor.h"
#include "chooser_predictor.h"
#include "path_history.h"

Local_predictor lp;
Global_predictor gp;
Chooser_predictor cp;
Path_history ph;

PREDICTOR::PREDICTOR(){
	path_history=0;		//Initialize path history to 0. None of the previous branches taken.
}
PREDICTOR::~PREDICTOR(){

}

bool PREDICTOR::get_prediction(const branch_record_c* br, const op_state_c* os){
    	if((br->is_call || br->is_return) && !br->is_conditional)
    			return true;
    	if(lp.get_local_prediction(br) == gp.get_global_prediction(br,&ph))
    			return gp.get_global_prediction(br,&ph); 	// calling any one predictor will work
    	else{
    		if(DEBUG)
    			printf("conditional Branch with choice of : %s \n",cp.get_chooser_prediction(br,&ph)>0 ? "local":"global");
    		if(cp.get_chooser_prediction(br,&ph))			// if 1 then choose local
    			return lp.get_local_prediction(br);
    		else											// else if 0 then choose global
    			return gp.get_global_prediction(br,&ph);
    	}
}

void PREDICTOR::update_predictor(const branch_record_c* br, const op_state_c* os, bool taken){
    		if((lp.get_local_prediction(br) == taken) && (gp.get_global_prediction(br,&ph) != taken))
    			cp.update_chooser_predictor(br,&ph,1);			// choose local
    		if((gp.get_global_prediction(br,&ph) == taken) && (lp.get_local_prediction(br) != taken))
    			cp.update_chooser_predictor(br,&ph,0);			// choose global
    		// else no change in chooser predictor

    		lp.update_local_predictor(br,taken);
    		gp.update_global_predictor(br,&ph,taken);
    		ph.update_path_history(taken);
}
