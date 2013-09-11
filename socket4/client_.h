#ifndef CLIENT__H_
#define CLIENT__H_

#include"socket_.h"

class client_ : public socket_
{
public:
	int start___(int argv2,char* argv1);
	int while___(int sec);

};

#endif /*CLIENT__H_*/
