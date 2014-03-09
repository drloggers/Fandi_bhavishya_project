
#ifndef GLOBAL_PREDICTOR_H_
#define GLOBAL_PREDICTOR_H_
#include "config.h"
#include "branch_record.h"

class Global_predictor
{
	char global_predictor_table[GLOBAL_PREDICTOR_ENTRIES-1];
	int count;
	unsigned short int path_history;
	public:
		Global_predictor();		//Constructor. Initializes predictor entries
		~Global_predictor();
		bool get_global_prediction(branch_record br_obj);
		void update_global_predictor(branch_record br_obj,bool br_result);
};


#endif /* GLOBAL_PREDICTOR_H_ */
