#include <iostream.h>
#include "thread.h"

//TESTIRANJE TAJMER I SPAVANJA OSNOVNO

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
	cout<<"NIT "<<c<<" SPAVA"<<endl;
	sleep(20);
	cout<<"NIT "<<c<<" SE BUDI"<<endl;

	cout<<"NIT "<<c<<" MENJA"<<endl;
	dispatch();
	cout<<"NIT "<<c<<" VRATILA I TESTIRA DA LI RADI TAJMER"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<"NIT "<<c<<" I: "<<i<<endl;
		for(long j=0;j<5000;j++)
			for(long k=0;k<15000;k++);
	}
}

void UserMain()
{
	Nit **a;
	int n=2;

	a=new Nit*[n];

	cout<<"GLAVNA KREIRA SVE"<<endl;
	for(int i=0;i<n;i++)
	{
		a[i]=new Nit(i+1,100,10);
		a[i]->start();
	}

	cout<<"GLAVNA SPAAVA"<<endl;
	Thread::sleep(20);
	cout<<"GLAVNA SE BUDI"<<endl;

	cout<<"GLAVNA BRISE SVE"<<endl;

	for(int j=0;j<n;j++) delete a[j];
	delete a;
}
