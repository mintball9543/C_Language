#ifndef __SLOT_H__
#define __SLOT_H__

#include"Person.h"

typedef int key;
typedef Person* value;

enum SlotStatus { EMPTY, DELETED, INUSE };

typedef struct _slot {
	key key;
	value val;
	enum SlotStatus status;
}Slot;

#endif