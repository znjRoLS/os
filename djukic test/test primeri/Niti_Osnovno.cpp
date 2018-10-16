#include <iostream.h>
#include "thread.h"
#include "semaphor.h"

class Nit:public Thread
{
	int id;
public:
	Nit(int ii,StackSize size,Time time):id(ii),Thread(size,time){}
	void run();
	~Nit()
	{
		waitToComplete();
	}
};

void Nit::run()
{
	cout<<"NIT "<<id<<" KRENULA"<<endl;
	cout<<"NIT "<<id<<" MENJA"<<endl;
	dispatch();
	cout<<"NIT "<<id<<" MENJA"<<endl;
	dispatch();
	cout<<"NIT "<<id<<" MENJA"<<endl;
	dispatch();
	cout<<"NIT "<<id<<" MENJA"<<endl;
	dispatch();
	cout<<"NIT "<<id<<" GOTOVA"<<endl;
}

void UserMain()
{
	Nit *t1=new Nit(1,1000,2);
	Nit *t2=new Nit(2,1000,2);
	Nit *t3=new Nit(3,1000,2);

	cout<<"GLAVNA STARTUJE"<<endl;

	t1->start();
	t2->start();

	cout<<"GLAVNA BRISE"<<endl;
	delete t1;
	delete t2;
	cout<<"NIT 3 NIJE NAMERNO STARTOVANA "<<endl;
	delete t3;
}
