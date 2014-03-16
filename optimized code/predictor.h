
#ifndef PREDICTOR_H_
#define PREDICTOR_H_

#include "config.h"
#include "op_state.h"

class PREDICTOR
{
	unsigned short int path_history;
public:
	PREDICTOR();		//Constructor. Initializes predictor entries
	~PREDICTOR();
    bool get_prediction(const branch_record_c* br, const op_state_c* os);

    void update_predictor(const branch_record_c* br, const op_state_c* os, bool taken);

};



#endif /* PREDICTOR_H_ */
