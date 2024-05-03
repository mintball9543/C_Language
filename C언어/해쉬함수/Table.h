#ifndef __TABLE_H__
#define __TABLE_H__

#include"Slot.h"

#define MAX_TBL 100

typedef int HashFunc(key k);

typedef struct _table {
	Slot tbl[MAX_TBL];
	HashFunc* hf;
}Table;

void TBLInit(Table* pt, HashFunc* f);

void TBLInsert(Table* pt, key k, value v);

value TBLDelete(Table* pt, key k);

value TBLSearch(Table* pt, key k);

#endif
