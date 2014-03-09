
#ifndef LOCAL_PREDICTOR_H_
#define LOCAL_PREDICTOR_H_
#include "config.h"
#include "branch_record.h"

class Local_predictor{
	char local_predictor_table[LOCAL_PREDICTOR_SIZE-1];
	int count;
public:
	Local_predictor();
	bool get_local_prediction(branch_record br_obj);
	void update_local_predictor(branch_record br_obj,bool taken);
	~Local_predictor();
};
#endif /* LOCAL_PREDICTOR_H_ */
