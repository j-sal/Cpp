#include <iostream>
#include "park.h"
#define MAX_LOTS 2 //100
#define AISLE_SIZE 1 //10

using namespace std;

/*************************************************************
[FunctionName]main
[Function] Main function of the programm, application's entry
[Argument]void
[ReturnValue]int:exit status of the program
*************************************************************/

int main()
{
	//def queue
	Queue cPark;
	Queue cPass;

	initQ(cPark, MAX_LOTS);
	initQ(cPass, AISLE_SIZE);

	bool running = true; //flag
	char key[10] = {0}; //user input
	int inPark(Queue &cPark, Queue &cPass);
	int outPark(Queue &cPark, Queue &cPass);
	int viewPark(Queue &cPark, Queue &cPass);

	while(running)
	{
		//UI
		cout<<"\n********************    Joey's  Parking Lot    ********************"<<endl;
		cout<<"********************       fare: 2$/hour       ********************"<<endl;
		cout<<"********************          15309001         ********************\n"<<endl;
		cout<<"1. Vehicle arrival"<<endl;
		cout<<"2. Vehicle departure"<<endl;
		cout<<"3. View parking lot"<<endl;
		cout<<"4. Exit Interface"<<endl;

		//key input
		cout<<"\nSelected option: ";
		cin>>key;

		//process key
		switch(key[0]){
		case '1':
			{
				inPark(cPark, cPass);
				break;
			}
			
		case '2':
			{
				outPark(cPark, cPass);
				break;
			}
		case '3':
			{
				viewPark(cPark, cPass);
				break;
			}
		case '4':
			running = false;
			cout<<"\nYou'll be back\n"<<endl;
			break;
		default:
			break; //?

		}
	}

	

	//DESTROYER OF QUEUES >:)
	destroyQ(cPark);
	destroyQ(cPass);
	
	cout << "Press enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();

	return 0;
}