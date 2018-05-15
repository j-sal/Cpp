#include "stdafx.h"
#include "Expr.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

/*************************************************************
[FunctionName]init
[Function] initializes the OPERAND stack
[Argument]OPND &opnd: operand stack
[Returned Value]0 OK; -1 Error
*************************************************************/
int init(OPND &opnd)
{
	while (opnd != NULL)
	{
		OPND temp = opnd;
		opnd = temp->next;
		free(temp);
	}

	opnd = NULL;

	return 0;
}

/*************************************************************
[FunctionName]push
[Function]push values into operand stack
[Argument]OPND &opnd, const double value: operand stack, operand 
[Returned Value]0 OK; -1 Error
*************************************************************/
int push(OPND &opnd, const double value)
{
	//add to stack node
	OPND temp = (OPND)malloc(sizeof(StackNodeOPND));
	if(!temp)
		return -1;

	temp->value = value;
	temp->next = opnd;
	opnd = temp;

	return 0;
}

/*************************************************************
[FunctionName]pop
[Function]pops the element
[Argument]OPND &opnd, double &value: operand stack, operand
[Returned Value]0 OK; -1 Error
*************************************************************/
int pop(OPND &opnd, double &value)
{
	if(opnd == NULL)
	{
		return -1;
	}

	//get the optr
	value = opnd->value;

	//delete stack node
	OPND temp = opnd;
	opnd = temp->next;
	free(temp);

	return 0;
}

/*************************************************************
[FunctionName]isEmpty
[Function]checks if OPND stack is empty
[Argument]OPND &opnd: operand stack
[Returned Value]int 1 empty; 0 Not empty
*************************************************************/
int isEmpty(OPND &opnd)
{
	if(opnd == NULL)
		return 1;

	else
		return 0;
}

/*************************************************************
[FunctionName]init
[Function] initializes the OPERATOR stack
[Argument]OPTR &optr: operator stack
[Returned Value]0 OK; -1 Error
*************************************************************/
int init(OPTR &optr)
{
	while (optr != NULL)
	{
		OPTR temp = optr;
		optr = temp->next;
		free(temp);
	}

	optr = NULL;

	return 0;
}

/*************************************************************
[FunctionName]push
[Function]push values into OPERATOR stack
[Argument]OPTR &optr, const char op: operator stack, operator 
[Returned Value]0 OK; -1 Error
*************************************************************/
int push(OPTR &optr, char op)
{
	//add to stack node
	OPTR temp = (OPTR)malloc(sizeof(StackNodeOPTR));
	if(!temp)
		return -1;

	temp->op = op;
	temp->next = optr;
	optr = temp;

	return 0;
}

/*************************************************************
[FunctionName]getTop
[Function]gets the top element
[Argument]OPTR &optr, char &op: operator stack, operator
[Returned Value]0 OK; -1 Error
*************************************************************/
int getTop(OPTR &optr, char &op)
{
	if(optr == NULL)
		return -1;

	op = optr->op;
	return 0;
}

/*************************************************************
[FunctionName]pop
[Function]pops the element
[Argument]OPTR &optr, char &op: operator stack, operator
[Returned Value]0 OK; -1 Error
*************************************************************/
int pop(OPTR &optr, char &op)
{
	if(optr == NULL)
	{
		return -1;
	}

	//get the optr
	op = optr->op;
	
	//delete stack node
	OPTR temp = optr;
	optr = temp->next;
	free(temp);

	return 0;
}

/*************************************************************
[FunctionName]precede
[Function]compares operator priority
[Argument]char a, char b; stack top optr, current optr
[Returned Value]char: '<'; a<b
					  '='; left and right parenthesis meet
					  '>'; a>b
*************************************************************/
char precede(char a, char b)
{
	char aPriorT[6][6] = {//priority
		//+   -   *   /   (   )
		{'>','>','<','<','<','>'},  // +
		{'>','>','<','<','<','>'},  // -
		{'>','>','>','<','<','>'},  // *
		{'>','>','>','<','<','>'},  // /
		{'<','<','<','<','<','='},  // (
		{'>','>','>','>','>','>'}}; // )

	int x = -1;
	int y = -1;
	char opr[] = "+-*/()";

	for(int i=0; i<6; i++)
	{
		if(a == opr[i]) x=i;
		if(b == opr[i]) y=i;
	}
	return aPriorT[x][y];
}

/*************************************************************
[FunctionName]isEmpty
[Function]checks if the OPTR stack is empty
[Argument]OPTR &optr; stack optr
[Returned Value]int 0: it's NOT empty, int 1: it's Empty
*************************************************************/
int isEmpty(OPTR &optr)
{
	if(optr == NULL)
		return 1;

	else
		return 0;
}

/*************************************************************
[FunctionName]parse
[Function] Expression parsing into the stacks
[Argument]char expr[]: expression array
[Returned Value]Expression result
*************************************************************/
double parse(char expr[])
{
	OPND opnd = NULL;
	OPTR optr = NULL;

	//initialize the stacks
	init(opnd);
	init(optr);

	for(int i=0; expr[i] != '\0'; i++)
	{
		//get next char
		char c = expr[i];

		//operands
		if(c >= '0' && c <= '9' || c == '.')
		{
			//process operand
			char token[20] = {0};
			int j = 0;

			while(expr[i+j] >= '0' && expr[i+j] <= '9' || expr[i+j] == '.')
			{
				token[j] = expr[i+j];
				j++;
			}
			token[j] = '\0';
			i = i+j-1;

			//convert token to double digit, push into OPND stack
			double value = atof(token);
			push(opnd, value);
		}
		else
		{
			//process operator
			if (isEmpty(optr))
			{
				// The stack is empty, push the operator into stack directly.
				push(optr, c);
			}
			else
			{
				//if the stack is not empty, get the top operator
				//determine top and current operator's priority
				char op =0;
				getTop(optr, op);

				switch(precede(op, c))
				{
				case '<'://Top optr priority < current optr
					push(optr, c);
					break;
				case'='://left and right parenthesis meet
					pop(optr, op);
					break;
				case'>'://Current optr priority < Top optr
					double a=0; 
					double b=0;

					pop(opnd, b);
					pop(opnd, a);
					pop(optr, op);
					    //Calculate expression value and push result into opnd stack
					push(opnd, calc(a, op, b));
					i--;//Withdraw a step
					break;
				}
			}
		}
	}

	//Calculate expression if OPTR stack is not empty
	if(!isEmpty(optr))
	{
		double a=0;
		double b=0;
		char op=0;

		pop(opnd, b);
		pop(opnd, a);
		pop(optr, op);
		push(opnd, calc(a, op, b));
	}

	double value=0;
	pop(opnd, value);

	
	/*TEST CODE
	//output operands
	cout<<"OPND: ";
	while(opnd != NULL)
	{
		//delete stack node
		OPND temp = opnd;
		opnd = temp->next;
		cout<<temp->value<<" ";
		free(temp);
	}
	cout<<"\n"<<endl;
	*/
	return value;
}

/*************************************************************
[FunctionName]calc
[Function] Calculates the value of an expression
[Argument]double a, char theta, double b: opnd a, optr, opnd b
[Returned Value]double: result 
*************************************************************/
double calc(double a, char theta, double b)
{
	double value = 0;
	switch (theta)
	{
	case '+':value = a+b; break;
	case '-':value = a-b; break;
	case '*':value = a*b; break;
	case '/':value = a/b; break;
	default:
		{
			cout<<"Expression error D:"<<endl;
			exit(0);
		}
	}

	return value;
}