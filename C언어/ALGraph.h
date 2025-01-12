#ifndef __AL_GRAPH__
#define __AL_GRAPH__

#include"DLinkedList.h"

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual {
	int numV;
	int numE;
	List* adjList;
}ALGraph;

void GraphInit(ALGraph* ph, int nv);

void GraphDestroy(ALGraph* pg);

void AddEdge(ALGraph* pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph* pg);

#endif