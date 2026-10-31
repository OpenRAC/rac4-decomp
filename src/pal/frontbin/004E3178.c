/* cflags:  -Wuninitialized */
#include "common.h"
#define __int128 long long
#define __int64 long
#define __int16 short
#define __int8 char
typedef int bool;
typedef u8 _BYTE; typedef u16 _WORD; typedef u32 _DWORD; typedef u64 _QWORD; typedef unsigned long long _OWORD;
typedef u8 _BOOL1; typedef u16 _BOOL2; typedef u32 _BOOL4; typedef u64 _BOOL8;
typedef struct { u32 a; u8 gap[44]; u32 b; u32 c; } GlobalView;
extern GlobalView D_001DFAF0;

typedef struct { u32 a; u32 b; u8 tail[8]; } Record;
extern Record D_00323400[];
typedef char clear_word_width[(sizeof(u32)==4 && sizeof(int)==4)?1:-1];
typedef char clear_record_size[(sizeof(Record)==16)?1:-1];
typedef char clear_global_size[(sizeof(GlobalView)==56)?1:-1];

int func_FB_004E3178()
{
  Record *v0;
  int result;

  v0 = D_00323400;
  D_001DFAF0.c = 0;
  D_001DFAF0.b = D_001DFAF0.a;
  result = (s32)(63);
  do
  {
    v0->a = 0;
    result = (int)result - 1;
    v0->b = 0;
    v0++;
  }
  while ( result >= 0 );
  return result;
}
