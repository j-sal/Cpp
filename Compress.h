#include "Huffman.h"

// File head
struct HEAD
{
	char aType[4];		// File type
	int nLength;		// Length of source file
	int aWeight[256];	// Weight data
};

// Compressed data
typedef char *BUFFER;

// Compresses the file
int Compress(const char *pFilename);

// Initializes the file head
int InitHead(const char *pFilename, HEAD &sHead);

// Encodes and compresses the file
int Encode(const char *pFilename, const HCode pHC, BUFFER &pBuffer, const int nSize);

// String transcoding
char Str2byte(const char *pBinStr);

// Writes the file
int WriteFile(const char *pFilename, const HEAD sHead, const BUFFER pBuffer, const int nSize);
