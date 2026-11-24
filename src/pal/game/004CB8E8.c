#include "common.h"

typedef struct Clock {
    u8 stat;
    u8 second;
    u8 minute;
    u8 hour;
    u8 pad;
    u8 day;
    u8 month;
    u8 year;
} Clock;

typedef struct Entry {
    s32 kind;
    s32 value;
    s32 count;
    s32 time;
    Clock date;
    u8 pad18[0x8];
} Entry;

typedef struct Data {
    u8 pad0[0x34];
    Entry entries[1];
} Data;

typedef struct Text {
    char name[0x40];
    char time[0x40];
    char date[0x40];
    char level[0x40];
    s32 handle;
} Text;

typedef struct Slots {
    s32 v[8];
} Slots;

typedef struct Level {
    s32 x0;
    s32 name;
} Level;

extern Data D_001719C8;
extern Text D_0030E5C8[];
extern Slots D_003D2688[];
extern s32 D_002219F8;
extern u8 D_001CDFD0[];
extern u8 D_001CE050[];
extern char D_0021FAF0[];
extern char D_0021FAF8[];
extern char D_0021FB08[];
extern char D_0021FB18[];
extern s32 func_004CBDD0(s32);
extern char *func_0045E850(s32);
extern s32 func_0011D920(char *, const char *, ...);
extern s32 func_0054C040(s32);
extern Level *func_0054BEE8(s32);
extern s32 func_004A2798(s32 *, s32);
extern s32 func_00506000(s32, s32);
extern s32 func_005062D0(s32, char *);
extern void func_0049AA18(s32);
extern s32 func_0049A9D8(void *, s32);
extern s32 func_005071B8(s32, s32);

// Fills one save-slot row of the load screen: name, play time, date,
// level name, icons and the preview image.
void func_004CB8E8(s32 i)
{
    if (func_004CBDD0(i)) {
        s32 sec;
        s32 h;
        s32 m;
        s32 s;
        Clock c;
        Clock *d;
        Level *l;

        func_0011D920(D_0030E5C8[i].name, D_0021FAF0, D_001719C8.entries[i].value, func_0045E850(0x2F1F));
        sec = D_001719C8.entries[i].time / 50;
        s = sec % 60;
        sec = sec / 60;
        m = sec % 60;
        h = sec / 60;
        if (h >= 1000) {
            h = 999;
            m = 59;
            s = 59;
        }
        func_0011D920(D_0030E5C8[i].time, D_0021FAF8, h, m, s);
        d = &D_001719C8.entries[i].date;
        c = *d;
        func_0011D920(D_0030E5C8[i].date, D_0021FB08, c.day, c.month, c.year);
        l = func_0054BEE8(func_0054C040(D_001719C8.entries[i].kind));
        func_0011D920(D_0030E5C8[i].level, D_0021FB18, func_0045E850(l->name));
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[0]), 1);
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[1]), 1);
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[2]), 1);
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[3]), 1);
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[7]), 0);
        if (D_001719C8.entries[i].count > 0) {
            func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[6]), 1);
        } else {
            func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[6]), 0);
        }
        if (D_0030E5C8[i].handle) {
            func_0049AA18(D_0030E5C8[i].handle);
            D_0030E5C8[i].handle = 0;
        }
        D_0030E5C8[i].handle = func_0049A9D8(D_001CDFD0 + D_001719C8.entries[i].kind % 20 * 8, -1);
        func_005071B8(func_004A2798(&D_002219F8, D_003D2688[i].v[4]), D_0030E5C8[i].handle);
    } else {
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[0]), 0);
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[1]), 0);
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[2]), 0);
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[3]), 0);
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[7]), 1);
        func_005062D0(func_004A2798(&D_002219F8, D_003D2688[i].v[7]), func_0045E850(0x238));
        func_00506000(func_004A2798(&D_002219F8, D_003D2688[i].v[6]), 0);
        if (D_0030E5C8[i].handle) {
            func_0049AA18(D_0030E5C8[i].handle);
            D_0030E5C8[i].handle = 0;
        }
        D_0030E5C8[i].handle = func_0049A9D8(D_001CE050 + i * 8, -1);
        func_005071B8(func_004A2798(&D_002219F8, D_003D2688[i].v[4]), D_0030E5C8[i].handle);
    }
}
