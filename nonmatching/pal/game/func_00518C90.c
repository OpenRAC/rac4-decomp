/* Not matching yet: PAL WIP; main .text 0x00518C90, 892B. Not part of the build. */
/*
 * Private getter(object) declaration follows native consumption but conflicts with current MATCH
 * no-argument source interface. Dependency/source-ABI debt and nonexact traversal/layout remain.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 6967ff51f1bfb7f9c70688632f820f5f955c2e7d65a33e917d9fc97adfc95bb2
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_00518C90 nonmatching/pal/game/func_00518C90.c --diff
 */
#include "common.h"

typedef s32 (*TestCallback)(void *, s32);
extern s32 *func_00510FB8(void *object);
extern s32 func_005112C8(s32 objectBits);
extern u8 D_002398C0[];

s32 func_00518C90(void *arg0, void *arg1, s32 forceWord)
{
    u8 *owner = (u8 *)arg0;
    u8 *current = (u8 *)arg1;
    s32 *selected;
    u8 *next;
    u8 *payload;
    u8 *service;
    u8 *actor;
    u32 index;
    s32 accepted = 0;
    s16 tag;
    TestCallback test;
    s32 status;
    s32 context;

    if (current != NULL) {
        selected = func_00510FB8(current);
    } else {
        selected = NULL;
    }
    if (selected != NULL) {
        test = *(TestCallback *)(*(u8 **)((u8 *)selected + 0x14) + 0x1C);
        context = *(s32 *)(owner + 0x2F14);
        status = test(selected, context);
        if (status != 0) {
            if (forceWord != 0) {
                *(s32 *)(owner + 0x2E78) = *selected;
            }
            return 0;
        }
        tag = *(s16 *)(current + 0xBC);
        switch (tag) {
        case 0x1087:
            *(s32 *)(owner + 0x2E7C) = 3;
            break;
        case 0x108C:
            *(s32 *)(owner + 0x2E7C) = 4;
            break;
        case 0x108F:
            *(s32 *)(owner + 0x2E7C) = 7;
            break;
        case 0x1095:
            *(s32 *)(owner + 0x2E7C) = 2;
            break;
        case 0x1096:
        case 0x1097:
            *(s32 *)(owner + 0x2E7C) = 5;
            break;
        case 0x1099:
            *(s32 *)(owner + 0x2E7C) = 6;
            break;
        case 0x10A9:
            *(s32 *)(owner + 0x2E7C) = 8;
            break;
        case 0x2106:
            *(s32 *)(owner + 0x2E7C) = 15;
            break;
        case 0x23FA:
            *(s32 *)(owner + 0x2E7C) = 1;
            break;
        case 0x20AB:
            payload = *(u8 **)(current + 0xAC);
            *(s32 *)(owner + 0x2E7C) = *(s32 *)(payload + 0x98);
            break;
        default:
            actor = *(u8 **)(owner + 0x2EF0);
            index = *(u8 *)(actor + 0x2C);
            if ((*(u32 *)(D_002398C0 + (index << 6) + 0x24) & 0x200) == 0) {
                *(s32 *)(owner + 0x2E7C) = -1;
            }
            break;
        }
        *(s32 *)(owner + 0x2E78) = *selected;
        return 1;
    }

    if (current != NULL) {
        next = *(u8 **)(current + 0xB8);
        if (next != NULL && next != current) {
            do {
                tag = *(s16 *)(current + 0xBC);
                switch (tag) {
                case 0x108A:
                    *(s32 *)(owner + 0x2E7C) = 7;
                    break;
                case 0x1094:
                    *(s32 *)(owner + 0x2E7C) = 2;
                    break;
                case 0x1087:
                    *(s32 *)(owner + 0x2E7C) = 3;
                    break;
                case 0x1096:
                    *(s32 *)(owner + 0x2E7C) = 5;
                    break;
                case 0x1089:
                    *(s32 *)(owner + 0x2E7C) = 4;
                    break;
                case 0x23FA:
                    *(s32 *)(owner + 0x2E7C) = 1;
                    break;
                case 0x1098:
                    *(s32 *)(owner + 0x2E7C) = 6;
                    break;
                case 0x10A9:
                    *(s32 *)(owner + 0x2E7C) = 8;
                    break;
                case 0x108F:
                    *(s32 *)(owner + 0x2E7C) = 7;
                    payload = *(u8 **)(current + 0xAC);
                    if (payload != NULL) {
                        service = *(u8 **)(payload + 0x3C);
                        if (service != NULL) {
                            accepted = 1;
                            test = *(TestCallback *)(*(u8 **)(service + 0x14) + 0x1C);
                            context = *(s32 *)(owner + 0x2F14);
                            status = test(service, context);
                            if (status != 0) {
                                *(s32 *)(owner + 0x2E7C) = -1;
                                return 0;
                            }
                            service = *(u8 **)(payload + 0x3C);
                            *(s32 *)(owner + 0x2E78) = *(s32 *)service;
                        }
                    }
                    break;
                default:
                    break;
                }
                if (accepted != 0) {
                    return 1;
                }
                current = *(u8 **)(current + 0xB8);
            } while (current != NULL &&
                     (next = *(u8 **)(current + 0xB8)) != NULL &&
                     next != current);
        }
    }

    selected = (s32 *)(u32)func_005112C8((s32)(u32)current);
    if (selected != NULL) {
        test = *(TestCallback *)(*(u8 **)((u8 *)selected + 0x14) + 0x1C);
        context = *(s32 *)(owner + 0x2F14);
        status = test(selected, context);
        if (status != 0) {
            if (forceWord != 0) {
                *(s32 *)(owner + 0x2E78) = *selected;
            }
            return 0;
        }
        *(s32 *)(owner + 0x2E78) = *selected;
    }
    return 1;
}
