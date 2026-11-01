/* cflags: @ee29 -O2 -G0 */
#include "common.h"
#include "pal/l00_record_iteration.h"

typedef struct PalL00RecordNode PalL00RecordNode;
struct PalL00RecordNode {
    void *value;
    PalL00RecordNode *next;
};

struct PalL00Records {
    PalL00RecordNode **buckets;
    u8 unknown_04[8];
    s32 count;
};

void func_L00_004F9140(PalL00Records *records, PalL00RecordCallback callback, void *context) {
    s32 i;
    PalL00RecordNode *node;
    void *value;

    for (i = (s32)((u32)records->count - 1U); i >= 0; i--) {
        node = records->buckets[i];
        while (node) {
            value = node->value;
            node = node->next;
            callback(value, context);
        }
    }
}
