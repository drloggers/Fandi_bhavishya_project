
#ifndef PREDICTOR_H_
#define PREDICTOR_H_


#include "op_state.h"
#include "config.h"
#include "local_predictor.h"
#include "global_predictor.h"
#include "chooser_predictor.h"
#include "path_history.h"

class PREDICTOR
{
private:
	unsigned short int path_history;
public:
	PREDICTOR();		//Constructor. Initializes predictor entries
	~PREDICTOR();
    bool get_prediction(const branch_record_c* br, const op_state_c* os);

    void update_predictor(const branch_record_c* br, const op_state_c* os, bool taken);

};



#endif /* PREDICTOR_H_ */
