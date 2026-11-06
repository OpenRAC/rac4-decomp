#include "common.h"
typedef struct __attribute__((packed)) { unsigned char a[2]; unsigned char b; unsigned char c; unsigned short d; unsigned char e[2]; unsigned int f; } Packet;
typedef struct { char pad[0x188]; void *entries; } Owner;
int func_01EBA758(Owner *owner, int unused, Packet *input) {
    Packet packet = *input;
    char *entries = owner->entries;
    if (entries) {
        unsigned int i = packet.b;
        void **table = *(void ***)(((char *)(((i << 1) + i) << 3) + (unsigned int)entries));
        *(unsigned int *)((char *)table[packet.d] + 0x48) = packet.f;
    }
    return 0;
}
