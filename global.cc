/*
Source Code for Global Predictor
 */

#define GLOBAL_HISTORY_MASK = 0xF000;	//Masks upper 4 bits of unsigned short int to obtain 12 bits.
#define MAX_GLOBAL_COUNTER_VAL = 0b11;
#define MIN_GLOBAL_COUNTER_VAL = 0b00;

class global_predictor
{
	char globalHistory[GLOBAL_HISTORY_ENTRIES-1];
	int count;
	unsigned short int path_history;

	public:
		global_predictor()		//Constructor. Initializes predictor entries
		{
			 for(count=0;count<GLOBAL_HISTORY_ENTRIES;count++)
				{
					globalHistory[count] = WEAKLY_NOT_TAKEN;
				}
			path_history=0;		//Initialize path history to 0. None of the previous branches taken.
		}



		bool get_global_prediction(branch_record br_obj){

			printf("Prediction State in Global History : %d \n", globalHistory[path_history]);

				if((br_obj.is_call || br_obj.is_return) && !br_obj.is_conditional)
					return true;
				else
					return (check(globalHistory[path_history],0b01));

			}

		void update_global_predictor(branch_record br_obj,bool br_result)
			{

				char global_predictionState = globalHistory[path_history];
				if(br_result){
					global_predictionState++;
					if(global_predictionState > MAX_GLOBAL_COUNTER_VAL)
						predictionState = MAX_GLOBAL_COUNTER_VAL;
				}
				else{
					global_predictionState--;
					if(global_predictionState < MIN_GLOBAL_COUNTER_VAL)
						global_predictionState = MIN_GLOBAL_COUNTER_VAL;
				}
				printf("Updated global prediction State of %d is %d\n",path_history,global_predictionState);
				globalHistory[path_history] = global_predictionState;

				path_history = path_history << 1;
				set(path_history,1);
				mask(path_history,GLOBAL_HISTORY_MASK);
			}


};

