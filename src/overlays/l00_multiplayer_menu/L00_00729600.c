#include "common.h"
typedef struct Record {
    u32 words[35];
} Record;
void func_L00_00729600(Record *left, Record *right)
{
    Record temporary = *left;
    *left = *right;
    *right = temporary;
}
