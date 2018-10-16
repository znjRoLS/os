#include "SemTest.h"
#include "Lock.h"
int Writer::ident = 0;
Semaphore* Writer::console = 0;

void Writer::run()

{
	for (int i = 0; i <
	5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			wait();
			//lock(); 
			cout << getID() << ": D " << " O " << " B " << " A " << " R " << " D " << " A " << " N " << " ! " <<  "\n";
			//unlock();
			signal();
		}
	}
}