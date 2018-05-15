// ExprCPro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Expr.h"

using namespace std;

/*************************************************************
[FunctionName]main
[Function] Main function of the programm, application's entry
[Argument]int argc: how many arguments, at least 1
[Argument]_TCHAR argv: An array of null-terminated strings
[ReturnValue]int:exit status of the program
*************************************************************/

int _tmain(int argc, _TCHAR* argv[])
{
	//UI output
	cout<<"============ Expression Evaluation by Joey ============"<<endl;
	cout<<"====================== 15309001 ======================="<<endl;
	cout<<"\n          1 Supports four operators: + - * /"<<endl;
	cout<<"          2 Supports brackets: ( )"<<endl;
	cout<<"          3 Supports Floats: 3.1415926\n"<<endl;
	cout<<"\nPlease enter the expression to be evaluated \nPress Enter when finished."<<endl;
	cout<<"eg. 5*(3+4)/2\n"<<endl;

	//input expression
	char expr[256]={0};
	cout<<"Expr:";
	cin>>expr;

	//output result
	cout<<"Result: "<<parse(expr)<<endl;

	cout << "Press enter to continue..." << endl;
	cin.ignore(10, '\n');
	cin.get();

	return 0;
}

