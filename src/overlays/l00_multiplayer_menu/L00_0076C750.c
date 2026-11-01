#include "common.h"
typedef struct { unsigned int words[9]; } Record;
typedef struct { char pad[0x3A8]; char flag; char pad2[3]; Record record; } Target;
typedef struct { char pad[0x3C]; Target *target; } Root;
extern Root *D_002233A4;

/* Clears the flag and copies the record. */
void func_L00_0076C750(Record *arg0) {
    Target *target = D_002233A4->target;
    target->flag = 0;
    target->record = *arg0;
}
