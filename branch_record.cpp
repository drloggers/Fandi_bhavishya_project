
#include "branch_record.h"

branch_record::branch_record() {
	        instruction_addr      = 0x0;
	        branch_target         = 0x0;
	        instruction_next_addr = 0x0;
	        is_indirect           = false;
	        is_conditional        = false;
	        is_call               = false;
	        is_return             = false;
	        is_taken			  = false;
}

branch_record::~branch_record() {
	// TODO Auto-generated destructor stub
}

