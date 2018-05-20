#pragma once
#include "Graph.h"

class CTourism
{
public:
	CTourism(void);
	~CTourism(void);

private:
	CGraph m_Graph;

public:
	void CreateGraph(void); //read files and create the spot information
	void GetSpotInfo(void);// To query the specific vertex info
	void TravelPath(void);
	void FindShortPath(void);
	void DesignPath(void);
};
