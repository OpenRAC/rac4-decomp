/* cflags: -fno-schedule-insns */
/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: SIZE ours 128 / disc 132.
 * Function text: 128 B; native catalogue: 132 B; 11 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_L01_004FF540 nonmatching/pal/shared/func_L01_004FF540.c --diff
 */
#include "common.h"
/* Automatischer m2c-Grobentwurf, kein geprÃƒÂ¼fter Match.
 * Unbekannte M2C_* und saved_reg_* mÃƒÂ¼ssen manuell aufgelÃƒÂ¶st werden.
 * Signaturen, Datenbesitz und Funktionsgrenzen prÃƒÂ¼fen.
 */

s32 func_L01_004FF540(void *arg0, void *arg1)
{
  s32 var_a1;
  void **var_a0;
  void *temp_a0;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  temp_v1 = *((void **) (((s8 *) arg0) + 0xAC));
  *((void **) (((s8 *) temp_v1) + 0x254)) = arg1;
  *((void **) (((s8 *) arg0) + 0xB8)) = arg1;
  temp_a0 = *((void **) (((s8 *) temp_v1) + 0x228));
  var_a1 = 3;
  if (temp_a0 != NULL)
  {
    *((u8 *) (((s8 *) temp_a0) + 0x30)) = (u8) (*((u8 *) (((s8 *) arg0) + 0x30)));
    *((u16 *) (((s8 *) (*((void **) (((s8 *) temp_v1) + 0x228)))) + 0x32)) = (u16) (*((u16 *) (((s8 *) arg0) + 0x32)));
    var_a0 = (void **)((u8 *)*(void **)((u8 *)*(void **)((u8 *)temp_v1 + 0x228) + 0xAC) + 0xD0);
    do
    {
      temp_v1_2 = *var_a0;
      var_a1 -= 1;
      if (temp_v1_2 != NULL)
      {
        *((u16 *) (((s8 *) temp_v1_2) + 0x32)) = (u16) (*((u16 *) (((s8 *) arg0) + 0x32)));
      }
      var_a0 += 1;
    }
    while (var_a1 >= 0);
    return 1;
  }
  temp_v1_3 = *((void **) (((s8 *) temp_v1) + 0x274));
  if (temp_v1_3 != NULL)
  {
    *((u16 *) (((s8 *) temp_v1_3) + 0x32)) = (u16) (*((u16 *) (((s8 *) arg0) + 0x32)));
  }
  return 1;
}
