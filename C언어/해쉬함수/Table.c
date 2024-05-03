#include<stdio.h>
#include<stdlib.h>
#include"Table.h"

void TBLInit(Table* pt, HashFunc* f) {
	int i;

	for (i = 0; i < MAX_TBL; i++)
		(pt->tbl[i]).status = EMPTY;

	pt->hf = f;
}

void TBLInsert(Table* pt, key k, value v) {
	int hv = pt->hf(k);
	pt->tbl[hv].val = v;
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}

value TBLDelete(Table* pt, key k) {
	int hv = pt->hf(k);

	if ((pt->tbl[hv]).status != INUSE)
		return NULL;
	else {
		(pt->tbl[hv]).status = DELETED;
		return (pt->tbl[hv]).val;
	}
}

value TBLSearch(Table* pt, key k) {
	int hv = pt->hf(k);

	if ((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
		return (pt->tbl[hv].val);
}