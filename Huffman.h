// Huffman tree node
struct HTNode
{
	int nWeight;// Weight
	int nParent;// Parent node
	int nLchild;// Left child
	int nRchild;// Right child
};

// Huffman tree
typedef HTNode *HTree;// Dynamically allocated arrays to store Huffman tree

// Huffman code table
typedef char **HCode;// Dynamically allocated arrays to store Huffman code table

// Generates Huffman tree
int HuffmanTree(HTree &pHT, int *aWeight);

//selects the smallest element
int Select(HTree pHT, int nSize);

// Traverses the Huffman tree and generates the  Huffman code
int HuffmanCoding(HCode &pHC, HTree &pHT);