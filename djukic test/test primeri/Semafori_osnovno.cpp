#include <iostream.h>
#include "thread.h"
#include "semaphor.h"

//SEMAFORI OPERACIJE

Semaphore *io, *done;

class Nit:public Thread
{
	int c;
public:
	Nit(int cc,StackSize ss,Time t):c(cc),Thread(ss,t){}
	void run();
	~Nit()
	{
		waitToComplete();
	}
};

void Nit::run()
{
	cout<<"NIT "<<c<<" CEKA NA IO"<<endl;
	io->wait();
	sleep(20);
	cout<<"ZASTICEN ISPIS"<<endl;
	io->signal();
	cout<<"NIT "<<c<<" GOTOVA"<<endl;
	done->signal();
}

void UserMain()
{
	Nit **a;
	int n=20;

	cout<<"GLAVAN PRAVI SEMAFORE"<<endl;
	io=new Semaphore();
	done=new Semaphore(0);
	cout<<"SEMAFORI IMAJU POCETNU VREDNOST "<<io->val()<<" I "<<done->val()<<endl;

	a=new Nit*[n];
	cout<<"GLAVNA KREIRA SVE"<<endl;
	for(int i=0;i<n;i++)
	{
		a[i]=new Nit(i+1,100,2);
		a[i]->start();
	}
	for(int k=0;k<n;k++)
	{
		cout<<"GLAVNA CEKA"<<endl;
		done->wait();
	}

	cout<<"GLAVNA BRISE SVE"<<endl;
	for(int j=0;j<n;j++) delete a[j];
	delete a;

	cout<<"GLAVNA BRISE SEMAFORE"<<endl;
	delete io;
	delete done;
}
