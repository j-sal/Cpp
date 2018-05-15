// operand stack
typedef struct StackNodeOPND
{
	double value;
	StackNodeOPND *next;
}*OPND;

//initialize operand stack
int init(OPND &opnd);
//push values into operand stack
int push(OPND &opnd, const double value);
int pop(OPND &opnd, double &value);
int isEmpty(OPND &opnd);

// operator stack
typedef struct StackNodeOPTR
{
	char op;
	StackNodeOPTR *next;
}*OPTR;

//initialize operator stack
int init(OPTR &optr);
//push values into operator stack
int push(OPTR &optr, const char op);
int getTop(OPTR &optr, char &op);
int pop(OPTR &optr, char &op);
char precede(char a, char b);
int isEmpty(OPTR &optr);
	
//Expression parse
double parse(char expr[]);
double calc(double a, char theta, double b);