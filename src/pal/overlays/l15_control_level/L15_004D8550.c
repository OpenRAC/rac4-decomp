/* cflags:  -Wuninitialized */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef long s64;
typedef float f32;
typedef double f64;
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
typedef long long s128;
typedef unsigned long long u128;
M2C_UNK func_0045DFC8(s16, s16, s16, s32, float, float, float, float);
s32 func_L15_004D8480(void *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_0021DE40;
extern u8 D_00240000[];
void func_L15_004D8550(void *arg0, s32 arg1)
{
  s32 temp_2;
  void *temp_16;
  temp_16 = *((void **) (((u8 *) arg0) + 0xAC));
  if ((arg1 != 0) || (((((int) (((unsigned int) D_0021DE40) - 0xBB8)) >= (*((s32 *) (((u8 *) temp_16) + 0x220)))) && (((int) (((unsigned int) D_0021DE40) - 0x2EE)) >= (*((s32 *) (((u8 *) temp_16) + 0x21C))))) && ((*((s16 *) (D_00240000 + 0x798c))) == 0)))
  {
    temp_2 = func_L15_004D8480(temp_16 + 0x224, 0x11, 0x2B01, 0x2B07, 0x2B06, 0x2B23, 0x2B24, 0x2B25, 0x2B26, 0x2B2C, 0x2B2E, 0x2B30, 0x2B32, 0x2B37, 0x2B38, 0x2B3F, 0x2B40, 0x2B41, 0x2B04);
    *((s32 *) (((u8 *) temp_16) + 0x218)) = temp_2;
    if (temp_2 >= 0)
    {
      *((s32 *) (((u8 *) temp_16) + 0x220)) = (s32) D_0021DE40;
      *((s32 *) (((u8 *) temp_16) + 0x21C)) = (s32) D_0021DE40;
      func_0045DFC8((s16) (*((s32 *) (((u8 *) temp_16) + 0x218))), -1, 2, 0, 0.75f, 1.0f, 0.0f, 64.0f);
    }
  }
}
