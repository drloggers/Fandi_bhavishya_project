
#ifndef GLOBAL_PREDICTOR_H_
#define GLOBAL_PREDICTOR_H_
#include "config.h"
#include "path_history.h"

class Global_predictor
{
	char global_predictor_table[GLOBAL_PREDICTOR_ENTRIES-1];
	int count;
	public:
		Global_predictor();		//Constructor. Initializes predictor entries
		~Global_predictor();
		bool get_global_prediction(const branch_record_c* br_obj,Path_history* ph);
		void update_global_predictor(const branch_record_c* br_obj,Path_history* ph,bool taken);
};


#endif /* GLOBAL_PREDICTOR_H_ */
