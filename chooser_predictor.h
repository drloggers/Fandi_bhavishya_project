/*
 * chooser_predictor.h
 *
 *  Created on: Mar 8, 2014
 *      Author: sanket
 */

#ifndef CHOOSER_PREDICTOR_H_
#define CHOOSER_PREDICTOR_H_

#include "config.h"
#include "branch_record.h"

class Chooser_predictor
{
	char chooser_predictor_table[CHOOSER_PREDICTOR_ENTRIES-1];
	int count;
	public:
		Chooser_predictor();		//Constructor. Initializes predictor entries
		~Chooser_predictor();
		bool get_chooser_prediction(branch_record br_obj);
		void update_chooser_predictor(branch_record br_obj,bool taken);
};



#endif /* CHOOSER_PREDICTOR_H_ */
