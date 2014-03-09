
#include "config.h"
#include "path_history.h"

Path_history::Path_history(){
	path_history = 0;
}

Path_history::~Path_history(){

}

unsigned short int Path_history::get_path_history(){
	return path_history;
}

void Path_history::update_path_history(bool taken){
	path_history = path_history << 1;
	if(taken)
		set(path_history,0);
	else
		clear(path_history,0);
	mask(path_history,PATH_HISTORY_MASK);
}

