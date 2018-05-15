#include "Compress.h"
#include <iostream>

using namespace std;

/************************************************
[FunctionName]main
[Function]Entry function
[Argument]void
[ReturnedValue]int:Exiting state of the program
************************************************/
int main()
{
	char filename[256];// File name

	// Input file name
	cout<<"\n**************  Huffman Image Compression Solution  **************"<<endl;
	cout<<"**************          by  Joey  15309001          **************"<<endl;
	cout<<"\nType in the file's name: ";
	cin>>filename;

	// Compress file
	Compress(filename);

	getchar();

	cout << "Press enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();

	return 0;
}