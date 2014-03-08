
#ifndef GLOBAL_PREDICTOR_H_
#define GLOBAL_PREDICTOR_H_
#include "config.h"
#include "branch_record.h"

class global_predictor
{
	char globalHistory[GLOBAL_HISTORY_ENTRIES-1];
	int count;
	unsigned short int path_history;

	public:
		global_predictor();		//Constructor. Initializes predictor entries
		~global_predictor();
		bool get_global_prediction(branch_record br_obj);
		void update_global_predictor(branch_record br_obj,bool br_result);
};


#endif /* GLOBAL_PREDICTOR_H_ */
