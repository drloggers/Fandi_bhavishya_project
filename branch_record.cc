
#include "branch_record.h"
/********* Constructor **************/
branch_record_c::branch_record_c() {
	        instruction_addr      = 0x0;
	        branch_target         = 0x0;
	        instruction_next_addr = 0x0;
	        is_indirect           = false;
	        is_conditional        = false;
	        is_call               = false;
	        is_return             = false;
	        is_taken			  = false;
}

branch_record_c::~branch_record_c() {
	// TODO Auto-generated destructor stub
}

