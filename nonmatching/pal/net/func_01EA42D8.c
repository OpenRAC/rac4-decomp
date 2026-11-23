/* Not matching yet: PAL WIP; main net.text 0x01EA42D8, 496B. Not part of the build. */
/*
 * Resultconstant definitions/dispatchbranchdestinations/defaultcontinuations and returnjoins
 * remain nonnative. Native1JR/7unconditionalbranches; t01
 * has22JR/6branches,t02has3JR/21branches,t03has4JR/21branches. This is NOT an exact graph or mere
 * normalized-byte match.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 7adfb0889f3f1b9d6e834cb58c4159804192507775f8a7dfdff7abc11cafef9c
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EA42D8 nonmatching/pal/net/func_01EA42D8.c --diff
 */
#include "common.h"

s32 func_01EA42D8(u32 status)
{
    s32 result;

    switch (status) {
    case 0x0:
        result = 0x0;
        break;
    case 0x2:
        result = 0x17;
        break;
    case 0x3:
        result = 0xA;
        break;
    case 0x4:
    case 0xC350:
    case 0xC351:
    case 0xC353:
    case 0xC355:
    case 0xC356:
        result = 0x23;
        break;
    case 0x5:
        result = 0x11;
        break;
    case 0x64:
        result = 0x16;
        break;
    case 0xC357:
        result = 0x19;
        break;
    case 0xC358:
    case 0xCB25:
        result = 0xE;
        break;
    case 0xC359:
        result = 0x2E;
        break;
    case 0xC35A:
        result = 0xC;
        break;
    case 0xC35B:
        result = 0x2C;
        break;
    case 0xC35C:
        result = 0x2D;
        break;
    case 0xCB23:
        result = 0xF;
        break;
    case 0xCB24:
        result = 0x3;
        break;
    case 0xCB26:
    case 0xCB27:
    case 0xCB2B:
        result = 0xD;
        break;
    case 0xCB28:
        result = 0x22;
        break;
    case 0xCB29:
        result = 0x1A;
        break;
    case 0xCB2A:
    case 0xCB2C:
        result = 0x25;
        break;
    case 0xCB2D:
        result = 0x10;
        break;
    case 0xCB2E:
        result = 0x2;
        break;
    case 0xCB2F:
        result = 0x2B;
        break;
    case 0xCB30:
    case 0xCB31:
        result = 0x20;
        break;
    default:
        result = 0x1E;
        break;
    }
    return result;
}
