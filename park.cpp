#include <iostream>
#include "park.h"

using namespace std;

int initQ(Queue &q, int nSize)
{
	q.base = (Car *) malloc((nSize+1) * sizeof(Car));//QUEUE base =?
	if(!q.base)
	{
		//mem error
		return ERROR;
	}
	q.front = q.rear = 0;
	q.size = nSize +1;
	return OK;
}

int destroyQ(Queue &q)
{
	//free mem
	if(q.base)
	{
		free(q.base);
		q.base = NULL;
	}
	q.front = q.rear = 0;
	q.size = 0;

	return OK;
}

int arrQ(Queue &q, Car car)
{
	//if the Q is full
	if((q.rear +1)%q.size == q.front)
	{
		return ERROR;
	}

	q.base[q.rear] = car;
	q.rear = (q.rear +1)%q.size;

	return OK;
}

int qLenght(Queue q)
{
	return (q.rear - q.front + q.size)%q.size;
}

int inPark(Queue &cPark, Queue &cPass)//where?
	{
		cout<<"\n----------------------    Vehicle Arrival    ----------------------"<<endl;
		Car car;
		cout<<"\nEnter the Registration/Plate number: ";
		cin>>car.regNum;
		cout<<"Enter the Parking Arrival Time: ";
		cin>>car.pTime;

		if(OK == arrQ(cPark, car))
		{
			//in parking lot
			cout<<"\nYou are now in Parking Lot # "<<qLenght(cPark)<<"."<<endl;
		}
		else if(OK == arrQ(cPass, car))
		{
			cout<<"\nParking lot is Full\nStand by at passage # "<<qLenght(cPass)
				<<"..."<<endl;
		}
		else
		{
			cout<<"\nSurprise Mafaka!\nNo space available\n"<<endl;
		}

		return 0;
	}

int depQ(Queue &q, Car &car) //DeQueue
{
	//Empty queue
	if(q.front == q.rear)
	{
		return ERROR;
	}

	car = q.base[q.front];
	q.front = (q.front +1) %q.size;

	return OK;
}

int outPark(Queue &cPark, Queue &cPass)
{
	cout<<"\n----------------------    Vehicle departure    ----------------------\n"<<endl;

	Car car;
	if(OK == depQ(cPark, car))
	{
		int time = 0;
		int fee = 0;
		cout<<"Vehicle # "<<car.regNum<<" departure time: ";
		cin>>time;

		fee = (time - car.pTime) *2;
		cout<<"\nFee due: $"<<fee<<endl;

		if(OK == depQ(cPass, car))
		{
			cout<<"\nVehicle # "<<car.regNum<<" move to Parking Lot\n"<<endl;
			car.pTime = time;
			arrQ(cPark, car);
		}
	}
	else
	{
		cout<<"\n404 Vehicle not found\n"<<endl;
	}

	return 0;
}

int qTraverse(Queue q)
{
	if(q.front == q.rear)
		return ERROR;

	int i=q.front;
	while(i != q.rear)
	{
		Car car = q.base[i];
		cout<<"\nRegistration number: "<<car.regNum<<"\t\t Arrival time: "<<car.pTime<<" hour(s)"<<endl;
		i=(i+1) %q.size;
	}

	return OK;
}

int viewPark(Queue &cPark, Queue &cPass)
{
	cout<<"\n----------------------    View Parking Lot    ----------------------"<<endl;
	qTraverse(cPark);
	qTraverse(cPass);

	return 0;
}