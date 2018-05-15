#include "Global.h"
#include "Compress.h"

#include <stdlib.h>
#include <iostream>
using namespace std;

/************************************************
[FunctionName]Compress
[Function]Compresses the file
[Argument]const char *pFilename: Input source file name 
[ReturnedValue]int: ERROR Abnormal; OK Normal
************************************************/
int Compress(const char *pFilename)
{
	//Reads the file and initializes the file head
	HEAD sHead;
	if (ERROR == InitHead(pFilename, sHead))
	{
		return ERROR;
	}
	cout<<sHead.nLength<<" Bytes"<<endl;

	// Generates Huffman tree
	HTree pHT = NULL;
	HuffmanTree(pHT, sHead.aWeight);
	if (!pHT)
	{
		return ERROR;
	}

	// Generates Huffman code table
	HCode pHC = NULL;
	HuffmanCoding(pHC, pHT);
	
	// Releases Huffman tree space
	free(pHT);
	pHT = NULL;

	if (!pHC)
	{
		return ERROR;
	}

	//Calculates the buffer size
	int nSize = 0;
	for (int i = 0; i < SIZE; i++)
	{
		nSize += sHead.aWeight[i] * strlen(pHC[i]);
	}
	nSize = (nSize % 8) ? nSize / 8 + 1 : nSize / 8;

	//Encodes and compresses the source file 
	BUFFER pBuffer = NULL;
	Encode(pFilename, pHC, pBuffer, nSize);
	
	// Releases Huffman code table
	for( int i = 0; i < SIZE; i++)
	{
		free(pHC[i]);
	}
	free(pHC);
	pHC = NULL;

	if (!pBuffer)
	{
		return ERROR;
	}

	// Outputs compressed file
	int len = WriteFile(pFilename, sHead, pBuffer, nSize);
	
	// Releases compressed data
	free(pBuffer);
	pBuffer = NULL;

	if (len < 0)
	{
		return ERROR;
	}

	cout<<len<<" Bytes"<<endl;
	cout<<"The compression ratio is: "<<(double)len /(double)sHead.nLength * 100<<"%"<<endl;
	return OK;
}

/************************************************
[FunctionName]InitHead
[Function]Scans the source file, initializes compressed file head
[Argument]const char *pFilename:	Output source file name
[Argument]Head &head:			Output file head
[ReturnedValue]int: ERROR Abnormal; OK Normal
************************************************/
int InitHead(const char *pFilename, HEAD &sHead)
{
	//Initializes file head
	strcpy(sHead.aType, "HUF");// File type
	sHead.nLength = 0;// Length of source file
	for (int i = 0; i < SIZE; i++)
	{
		sHead.aWeight[i] = 0;// Weight
	}

	//Opens file in binary stream form
	FILE *in = fopen(pFilename, "rb");
	if (!in)
	{
		cerr<<"Failed to initialize file head! *o*"<<endl;
		return ERROR;
	}

	//Scans file, gets weight
	int ch;
	while((ch = fgetc(in)) != EOF)
	{
		sHead.aWeight[ch]++;
		sHead.nLength++;
	}

	// Closes file, releases file pointer
	fclose(in);
	in = NULL;

	return OK;
}

/************************************************
[FunctionName]Encode
[Function]Encodes and compresses file
[Argument]const char *pFilename:	Source file name
[Argument]const HCode pHC:		Huffman code table
[Argument]BUFFER pBuffer:		Encoding buffer
[Argument]const int nSize:		Buffer size
[ReturnedValue]int: ERROR Abnormal; OK Normal
************************************************/
int Encode(const char *pFilename, const HCode pHC, BUFFER &pBuffer, const int nSize)
{
	// Opens file in binary stream form
	FILE *in = fopen(pFilename, "rb");
	if (!in)
	{
		cerr<<"oh noi! Failed to open the source file!"<<endl;
		return ERROR;
	}

	// Creates a buffer
	pBuffer = (char *)malloc(nSize * sizeof(char));
	if (!pBuffer)
	{
		cerr<<"Failed to create a buffer!"<<endl;
		return ERROR;
	}

	// Scans source file and compresses it according to the Huffman code table, then stores the result into buff
	char cd[SIZE] = {0};// Workspace
	int pos = 0;// Pointer to buffer
	int ch;
	while((ch = fgetc(in)) != EOF)
	{
		strcat(cd, pHC[ch]);//Copies the  code string from HC to cd
		
		// Compresses code
		while(strlen(cd) >= 8)
		{
			//Intercepts the left eight characters of string, then encode them into bytes
			pBuffer[pos++] = Str2byte(cd);

			// Moves the whole string to left eight bytes
			for (int i = 0; i < SIZE - 8; i++)
			{
				cd[i] = cd[i+8];
			}
		}
	}
	if (strlen(cd) > 0)
	{
		pBuffer[pos++] = Str2byte(cd);
	}

	// Closes file, release file pointer
	fclose(in);
	in = NULL;
}

/************************************************
[FunctionName]Str2byte
[Function]String transcoding
[Argument]const char *pBinStr:	Binary string
[ReturnedValue]char: Encoding result
************************************************/
char Str2byte(const char *pBinStr)
{
	char b = 0x00;
	for(int i = 0; i < 8; i++)
	{
		b = b<<1;// Move to left one bit
		if (pBinStr[i] == '1') {
			b = b | 0x01;
		}
	}
	return b;
}

/************************************************
[FunctionName]WriteFile
[Function]Write file
[Argument]const char *pFilename:	Source file name
[Argument]const HEAD sHead:		File head
[Argument]const BUFFER pBuffer:	Encoding buffer
[Argument]const int nSize:		Buffer size
[ReturnedValue]int: File length
************************************************/
int WriteFile(const char *pFilename, const HEAD sHead, const BUFFER pBuffer, const int nSize)
{
	// Generate file name
	char filename[256] = {0};
	strcpy(filename, pFilename);
	strcat(filename, ".huf");

	// Open file in binary stream form
	FILE *out = fopen(filename, "wb");
	if (!out)
	{
		cerr<<"Failed to open file!"<<endl;
		return ERROR;
	}

	// Write file head
	fwrite(&sHead, sizeof(HEAD), 1, out);

	// Write compressed code
	fwrite(pBuffer, sizeof(char), nSize, out);

	// Close file, release file pointer
	fclose(out);
	out = NULL;

	cout<<"The compressed file is: "<<filename<<endl;
	int len = sizeof(HEAD) + strlen(pFilename) + 1 + nSize;
	return len;
}