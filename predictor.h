
#ifndef PREDICTOR_H_
#define PREDICTOR_H_
#include "config.h"
#include "branch_record.h"

class predictor{
	char localHistory[LOCAL_HISTORY_SIZE];
	int count;
public:
	predictor();
	bool getPrediction(branch_record br_obj);
	void updatePrediction(branch_record br_obj,bool br_result);
	~predictor();
};
#endif /* PREDICTOR_H_ */
