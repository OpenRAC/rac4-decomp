/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Stream {
    s32 size;
    s32 unk4;
    char *buf;
    s32 count;
    s32 pos;
} Stream;

typedef struct File {
    u8 pad0[0x20];
    Stream *stream;
    s32 handle;
} File;

extern void func_L00_004F7228(File *f);
extern s32 func_L00_00516990(s32 handle, char *buf, s32 size);
extern void func_L00_00516E90(File *f);

s32 func_L00_005165B0(File *f, char *dst, s32 size) {
    Stream *s;
    s32 total;
    s32 found;
    s32 i;
    char *p;

    size--;
    total = 0;
    s = f->stream;
    func_L00_004F7228(f);
    for (;;) {
        if (s->count > 0) {
            p = s->buf + s->pos;
            found = 0;
            for (i = 0; i < s->count && i < size; i++) {
                *dst = p[i];
                dst++;
                if (p[i] == '\n') {
                    found = 1;
                    i++;
                    break;
                }
            }
            s->count -= i;
            s->pos += i;
            total += i;
            size -= i;
            if (found || i == size) {
                *dst = 0;
                return total;
            }
        } else {
            i = func_L00_00516990(f->handle, s->buf, s->size);
            if (i <= 0) {
                func_L00_00516E90(f);
                if (i < 0) {
                    if (total > 0) {
                        return total;
                    }
                    return i;
                }
                if (i == 0) {
                    return total;
                }
            }
            s->count = i;
            s->pos = 0;
        }
    }
}
