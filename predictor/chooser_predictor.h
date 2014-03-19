
#ifndef CHOOSER_PREDICTOR_H_
#define CHOOSER_PREDICTOR_H_

#include "config.h"
#include "path_history.h"

class Chooser_predictor
{
	char chooser_predictor_table[CHOOSER_PREDICTOR_ENTRIES-1];
	int count;
	public:
		Chooser_predictor();		//Constructor. Initializes predictor entries
		~Chooser_predictor();
		bool get_chooser_prediction(const branch_record_c* br_obj,Path_history* ph);
		void update_chooser_predictor(const branch_record_c* br_obj,Path_history* ph,bool taken);
};

#endif /* CHOOSER_PREDICTOR_H_ */
