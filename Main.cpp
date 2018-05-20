#include <iostream>
#include "Tourism.h"
//#include "Graph.h"

using namespace std;

int main(void)
{
	CTourism tourism;

	bool bRunning = true;
	char key[10] = {0};
	while(bRunning)
	{
		cout<<"\n=== Scenic Information Management SYstem ==="<<endl;
		cout<<"===           by Joey 15309001           ===\n"<<endl;
		cout<<"1.Create Scenic Spot Graph NOW!"<<endl;
		cout<<"2.Queary Spot Information FOR LATER!!"<<endl;
		cout<<"3.Navigate Tourist Spot"<<endl;
		cout<<"4.Search Shortest Path QUICKLY!!"<<endl;
		cout<<"5.Lay Circuit Planning"<<endl;
		cout<<"6.C U Later!"<<endl;

		cout<<"\nSelect an option: "<<endl;
		cin>>key;

		switch(key[0])
		{
		case '1':
			tourism.CreateGraph();
			break;
		case '2':
			tourism.GetSpotInfo();
			break;
		case '3':
			tourism.TravelPath();
			break;
		case '4':
			tourism.FindShortPath();
			break;
		case '5':
			tourism.DesignPath();
			break;
		case '6':
			bRunning = false;
			cout<<"\nYou'll be back..."<<endl;
			break;
		}
		cout << "Press enter to continue..." << endl;

		cin.ignore(10, '\n');
		cin.get();
	}

	return 0;
}