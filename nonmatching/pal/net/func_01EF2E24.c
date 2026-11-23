/* Not matching yet: PAL WIP; main net.text 0x01EF2E24, 616B. Not part of the build. */
/*
 * Repeated helper argument setup is scheduled differently: object and descriptor argument copies
 * occupy different call/delay positions. Complete616B body remains nonexact; source/ABI
 * qualifications in the dated report remain.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: e9acfefd1fa8c8b15dfb0448b4638f8102a5b4940a70adb7aed6a9ef0d3bbf67
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EF2E24 nonmatching/pal/net/func_01EF2E24.c --diff
 */
#include "common.h"

void **func_01EF2C14(void);
void *func_01EF2CC4(void);
s32 func_01EF2D88(void *p, void *value);
void **func_01EF6048(void);
void **func_01EF6470(void);
void **func_01EF6A88(void);
void **func_01EF6BE8(void);
void **func_01EF72C8(void);
void **func_01EF7EF0(void);
void **func_01EF8050(void);
void **func_01EF8C34(void);
void **func_01EFB6E0(void);
void **func_01EFCCD4(void);
void **func_01EFD5F4(void);
void **func_01EFDE14(void);
void **func_01EFE6E8(void);
void **func_01EFF990(void);
void **func_01F001EC(void);
void **func_01F0044C(void);
void **func_01F03530(void);
void **func_01F0379C(void);
void **func_01F03C88(void);
void **func_01F04024(void);
void **func_01F04B70(void);
void **func_01F064F4(void);
void **func_01F06654(void);
void *func_01F07C34(void);
void *func_01F0A5F0(void);
void **func_01F0BA20(void);
void **func_01F0BB78(void);
void **func_01F0C390(void);

/* Registers each descriptor in the shared registry. */
void func_01EF2E24(void) {
    void *registry;
    void *descriptor;

    registry = func_01EF2CC4();
    descriptor = func_01EF2C14();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EF6048();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EF6BE8();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EF6470();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EF72C8();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EF7EF0();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F03530();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EFB6E0();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EFCCD4();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EFD5F4();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EFDE14();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EFE6E8();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F001EC();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F03C88();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EFF990();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F06654();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F0044C();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F0379C();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F04024();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F04B70();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F064F4();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F07C34();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EF8050();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EF8C34();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F0A5F0();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F0BA20();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01EF6A88();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F0BB78();
    func_01EF2D88(registry, descriptor);
    descriptor = func_01F0C390();
    func_01EF2D88(registry, descriptor);
}
