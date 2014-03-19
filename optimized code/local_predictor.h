
#ifndef LOCAL_PREDICTOR_H_
#define LOCAL_PREDICTOR_H_
#include "config.h"

class Local_predictor{
private:
	char local_predictor_table[LOCAL_PREDICTOR_SIZE-1];
	int count;
public:
	Local_predictor();
	bool get_local_prediction(const branch_record_c* br_obj);
	void update_local_predictor(const branch_record_c* br_obj,bool taken);
	~Local_predictor();
};
#endif /* LOCAL_PREDICTOR_H_ */
