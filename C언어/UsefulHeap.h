#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#include"ALEdge.h"

#define TRUE 1
#define FALSE 0

#define HEP_LEN 100

typedef Edge HData;
typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap {
	PriorityComp* comp;
	int numOfData;
	HData heapArr[HEP_LEN];
}Heap;

void HeapInit(Heap* ph, PriorityComp pc);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);

#endif