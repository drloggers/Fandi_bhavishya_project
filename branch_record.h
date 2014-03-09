#ifndef BRANCHRECORD_H_
#define BRANCHRECORD_H_

/*********Class***********/
class branch_record_c
{
public:
    unsigned int   instruction_addr;       // the branch's PC (program counter)
    unsigned int   branch_target;          // this is the target of the branch if it's taken; branches that aren't conditional are always taken
    unsigned int   instruction_next_addr;  // the PC of the static instruction following the branch
    bool   is_indirect;            // true if the target is computed; false if it's PC-rel; returns are also considered indirect
    bool   is_conditional;         // true if the branch is conditional; false otherwise
    bool   is_call;                // true if the branch is a call; false otherwise
    bool   is_return;              // true if the branch is a return; false otherwise
    bool   is_taken;

    branch_record_c();
    ~branch_record_c();
};

#endif /* BRANCHRECORD_H_ */
