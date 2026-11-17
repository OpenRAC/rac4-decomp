/* Not matching yet: 15/16 (93.75%) relocation-masked positional words; 60/64 candidate/target bytes. One trailing word after return omitted; callback ABI remains unproved. Reproduce: python tools/check_func.py --version pal func_L00_0051F2C0 nonmatching/pal/l00_multiplayer_menu/func_L00_0051F2C0.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* 15/16 target positions match (93.75%) under relocation-masked positional
 * comparison; 60/64 bytes. One trailing word after return is omitted.
 * The table and callback types describe the observed accesses only; allocation,
 * indirect caller and callback ABI remain uncertain. Verify with
 * tools/diff_func.py --version pal func_L00_0051F2C0. */
typedef struct Object Object; typedef struct Table Table;
struct Table { void *slots[4]; int (*call)(Object *, int, int, int, int, int); }; struct Object { Table *table; };
int func_L00_0051F2C0(Object *o,int a,int b,int c,int d) { return o->table->call(o,8,a,b,c,d); }
