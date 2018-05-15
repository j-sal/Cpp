#include "Huffman.h"
#include "Global.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

/************************************************
[FunctionName]Select
[Function]Selects a node with the samllest weight and its parent is 0
[Argument]HTree pHT:  Huffman tree
[Argument]int nSize:  The number of elements
[ReturnedValue]int: Element number with the smallest weight
************************************************/
int Select(HTree pHT, int nSize)
{
	int minValue = 0x7FFFFFFF;// The minimum
	int min = 0;//element #

	//To find the e with smallest weight
	for (int i = 1; i <= nSize; i++)
	{
		if (pHT[i].nParent == 0 && pHT[i].nWeight < minValue)
		{
			minValue = pHT[i].nWeight;
			min = i;
		}
	}

	return min;
}

/************************************************
[FunctionName]HuffmanTree
[Function]Generates the Huffman tree
[Argument]HTree &pHT:     Huffman tree
[Argument]int *aWeight:   Weight array
[ReturnedValue]int: ERROR Abnormal; OK Normal
************************************************/
int HuffmanTree(HTree &pHT, int *aWeight)
{
	//mem allocation
	int m = 2 * SIZE - 1;
	pHT = (HTree)malloc((m + 1) * sizeof(HTNode));
	if (!pHT)
	{
		cerr<<"Failed to allocate memory! D:"<<endl;
		return ERROR;
	}

	// Initializes the tree node
	HTree p = pHT + 1;// 0 unit is not used
	for(int i = 0; i < m; i++)
	{
		p->nWeight = (i < SIZE) ? aWeight[i] : 0;
		p->nParent = 0;
		p->nLchild = 0;
		p->nRchild = 0;
		p++;
	}

	// Creates Huffman tree
	for (int i = SIZE + 1; i<=m; i++)
	{
		//1st Smallest Element
		int s1 = Select(pHT, i-1);
		pHT[s1].nParent = i;

		//2nd smallest
		int s2 = Select(pHT, i-1);
		pHT[s2].nParent = i;

		pHT[i].nWeight = pHT[s1].nWeight + pHT[s2].nWeight;
		pHT[i].nLchild = s1;
		pHT[i].nRchild = s2;
	}

	return OK;
}

/************************************************
[FunctionName]HuffmanCoding
[Function]Traverse Huffman tree, generate Huffman code
[Argument]HCode &pHC:  Huffman code
[Argument]HTree pHT:   Huffman tree
[ReturnedValue]int: ERROR Abnormal; OK Normal
************************************************/
int HuffmanCoding(HCode &pHC, HTree &pHT)
{
	// Allocates memory for the pointer of character code
	pHC = (HCode)malloc(SIZE * sizeof (char *));
	if (!pHC)
	{
		cerr<<"Failed to allocate memory!"<<endl;
		return ERROR;
	}

	//Allocates workspace for encoding
	char cd[SIZE] = {'\0'};//record the path
	int cdlen = 0; //record the length
	for(int i = 1; i<=SIZE*2-1; i++)
	{
		pHT[i].nWeight = 0;
	}

	int p = SIZE*2-1;//root node
	while(p != 0)
	{
		if(pHT[p].nWeight == 0)// Visits left child
		{
			pHT[p].nWeight = 1;
			if(pHT[p].nLchild != 0)
			{
				p = pHT[p].nLchild;
				cd[cdlen++] = '0';
			}
			else if(pHT[p].nRchild == 0)//left node is a leaf
			{
				pHC[p-1] = (char*)malloc((cdlen+1) * sizeof(char));
				cd[cdlen] = '\0';
				strcpy(pHC[p-1], cd);//copy the Huff code
			}
		}
		else if(pHT[p].nWeight == 1)// Visits right child
		{
			pHT[p].nWeight = 2;
			if(pHT[p].nRchild != 0)
			{
				p = pHT[p].nRchild;
				cd[cdlen++] = '1';
			}
		}
		else//Return to parent node, code length minus one
		{
			pHT[p].nWeight = 0;
			p = pHT[p].nParent;
			--cdlen;
		}
	}

	return OK;
}