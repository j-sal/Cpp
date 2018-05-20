#define ERROR -1
#define OK 0

//car
struct Car
{
	char regNum[10];
	int pTime;
};

//circular queue
typedef struct cQueue
{
	Car *base; //array
	int front; 
	int rear;
	int size;
}Queue;

int initQ(Queue &q, int nSize);
int destroyQ(Queue &q);
int arrQ(Queue &q, Car car); //EnQueue
int qLenght(Queue q); 
int depQ(Queue &q, Car &car);

int qTraverse(Queue q);