
#ifndef PATH_HISTORY_H_
#define PATH_HISTORY_H_

class Path_history{

	unsigned short int path_history;
public:
	Path_history();
	~Path_history();
	unsigned short int get_path_history();
	void update_path_history(bool taken);
};



#endif /* PATH_HISTORY_H_ */
