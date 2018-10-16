#ifndef _SemTest_h_
#define _SemTest_h_

#include "Thread.h"
#include "Sem.h"
#include <iostream.h>


class Writer : public Thread
{
private:
	static int ident;
	static Semaphore* console;
	int id;
	
public:
	Writer() : Thread(2048, 1)
	{
		if (!console) console = new Semaphore(1);
		id = ident++;
	}
	
	void wait()
	{
		console->wait();
	}
	
	void signal()
	{
		console->signal();
	}
	
	int getID()
	{
		return id;
	}
	
	void run();
	
	~Writer()
	{
		waitToComplete();
	}
};
#endif