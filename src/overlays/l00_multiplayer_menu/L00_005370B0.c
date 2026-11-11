/* cflags: @ee29 -O2 -G0 */
#include "common.h"
typedef struct { s32 f0; union { s32 i; void *p; } f4; } Type2;
typedef struct { s32 type; union { void *ptr; Type2 *seq; } value; } Type1;
extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_00534998(void *, u8 **, s64);
extern void *func_L00_00535300(void *, u8 **, s64);
extern void *func_L00_00535680(void *, u8 **, s64);
extern void *func_L00_00535968(void *, u8 **, s64);
extern s32 func_L00_00535C18(u8 **pp, s64 *len, s32 *tagOut, s32 *classOut, s64 remain);
extern s32 func_L00_00536190(void *, u8 *, s32);
extern Type2 *func_L00_00536270(void);
extern void *func_L00_00536A78(void *, u8 **, s64);
extern Type1 *func_L00_005373D8(void);
extern void func_L00_00537430(Type1 *);
extern void func_L00_00537478(Type1 *p);
extern void *func_L00_00545CB0(void *, u8 **, s64, s32);
extern void *func_L00_00546390(void *, u8 **, s64);

Type1 *func_L00_005370B0(Type1 **out, u8 **pp, s64 length) {
    u8 *q;
    s64 len;
    s32 tag;
    s32 cls;
    u8 *p;
    u8 *end;
    Type1 *obj = NULL;

    if (out == NULL || *out == NULL) {
        if ((obj = func_L00_005373D8()) == NULL) goto err;
    } else {
        obj = *out;
    }

    p = *pp;
    q = p;
    end = p + length;
    if (func_L00_00535C18(&q, &len, &tag, &cls, length) & 0x80) {
        goto err;
    }
    func_L00_00537478(obj);

    switch (tag) {
    case 5:
        p = q;
        obj->value.ptr = NULL;
        break;
    case 2:
        if ((obj->value.ptr = func_L00_00535300(NULL, &p, end - p)) == NULL) goto err;
        break;
    case 3:
        if ((obj->value.ptr = func_L00_00534998(NULL, &p, end - p)) == NULL) goto err;
        break;
    case 4:
        if ((obj->value.ptr = func_L00_00536A78(NULL, &p, end - p)) == NULL) goto err;
        break;
    case 6:
        if ((obj->value.ptr = func_L00_00535680(NULL, &p, end - p)) == NULL) goto err;
        break;
    case 19:
        if ((obj->value.ptr = func_L00_00546390(NULL, &p, end - p)) == NULL) goto err;
        break;
    case 20:
        if ((obj->value.ptr = func_L00_00545CB0(NULL, &p, end - p, 4)) == NULL) goto err;
        break;
    case 22:
        if ((obj->value.ptr = func_L00_00545CB0(NULL, &p, end - p, 0x10)) == NULL) goto err;
        break;
    case 27:
        if ((obj->value.ptr = func_L00_00545CB0(NULL, &p, end - p, 0x80)) == NULL) goto err;
        break;
    case 28:
        if ((obj->value.ptr = func_L00_00545CB0(NULL, &p, end - p, 0x100)) == NULL) goto err;
        break;
    case 30:
        if ((obj->value.ptr = func_L00_00545CB0(NULL, &p, end - p, 0x800)) == NULL) goto err;
        break;
    case 23:
        if ((obj->value.ptr = func_L00_00535968(NULL, &p, end - p)) == NULL) goto err;
        break;
    case 16:
    case 17:
        if (end - p < len) {
            func_L00_004F84C8(0xD, 0x85, 0x89, 0, 0);
            goto err;
        }
        if ((obj->value.seq = func_L00_00536270()) == NULL) goto err;
        obj->value.seq->f4.i = tag;
        len += q - p;
        if (func_L00_00536190(obj->value.seq, p, len) == 0) goto err;
        p += (s32)len;
        break;
    default:
        func_L00_004F84C8(0xD, 0x85, 0x6A, 0, 0);
        goto err;
    }

    obj->type = tag;
    if (out != NULL) {
        *out = obj;
    }
    *pp = p;
    return obj;

err:
    if (obj != NULL && (out == NULL || *out != obj)) {
        func_L00_00537430(obj);
    }
    return NULL;
}
