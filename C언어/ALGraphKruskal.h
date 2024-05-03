#ifndef __AL_GRAPH_KRUSKAL__
#define __AL_GRAPH_KRUSKAL__

#include"DLinkedList.h"
#include"ALEdge.h"
#include"PriorityQueue.h"
#include"ArrayBaseStack.h"

enum { A, B, C, D, E, F, G, H, I, J };

typedef struct _ual {
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
	PQueue pqueue;
}ALGraph;

void GraphInit(ALGraph* pg, int nv);

void GraphDestroy(ALGraph* pg);

void AddEdge(ALGraph* pg, int fromV, int toV, int weight);

void ShowGraphEdgeInfo(ALGraph* pg);

void DFShowGraphVertex(ALGraph* pg, int startV);

void ConKruskalMST(ALGraph* pg);

void ShowGraphEdgeWeightInfo(ALGraph* pg);

void RemoveWayEdge(ALGraph* pg, int fromV, int toV);

void RemoveEdge(ALGraph* pg, int fromV, int toV);

void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight);

int IsConnVertex(ALGraph* pg, int v1, int v2);

#endif