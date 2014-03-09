
#ifndef PREDICTOR_H_
#define PREDICTOR_H_
#include "config.h"
#include "branch_record.h"

class Predictor{
		unsigned short int path_history;
		public:
			Predictor();		//Constructor. Initializes predictor entries
			~Predictor();
			bool get_prediction(branch_record br_obj);
			void update_predictor(branch_record br_obj,bool br_result);
};



#endif /* PREDICTOR_H_ */
