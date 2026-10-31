# Third-party notices

## GCC runtime library (`src/libgcc/`)

`libgcc2.c`, `gbl-ctors.h`, `longlong.h` (GCC trunk, 1999-09-09) and
`fp-bit.c` (GCC 2.95.3): Copyright Free Software Foundation, Inc. Licensed
under the GNU General Public License version 2 or later with the libgcc
linking exception, as stated in each file's header. They are built unchanged
(except two edits marked in place in `fp-bit.c`) to reproduce the library
that Sony's toolchain linked into the game.

The selection and build recipe come from
[rac1-decomp](https://github.com/OpenRAC/rac1-decomp) (GPL-3.0).

## Math library (`src/libm/`)

Sources from newlib (snapshot 2000-02-17), derived from Sun Microsystems' fdlibm:
"Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved. Developed at
SunSoft, a Sun Microsystems, Inc. business. Permission to use, copy, modify, and
distribute this software is freely granted, provided that this notice is
preserved." Other files carry the notices of their respective authors in their
headers. They are built unchanged to reproduce the library that Sony's
toolchain linked into the game.

## Other public decompilations (`src/core/`, `src/net/`, `src/game/`)

The C of 183 functions started from the matching C of the equivalent functions in
[rac3-decomp](https://github.com/OpenRAC/rac3-decomp) (*Ratchet & Clank: Up Your Arsenal*, commit
`403f30a9561324342c87802960eefbaaae13b372`), found by comparing the opcode sequences of the two games'
retail code: Sony's library code and the engine's own helpers are the same in both games. That project's
`LEGAL.md` keeps its decompiled `src/` outside its GPL-3.0 licence (its contributors claim no copyright
over it and grant no licence); it is credited here as the "other public decompilations" that
`LEGAL.md` and `CONTRIBUTING.md` allow, not taken under a licence. Its own `CREDITS.md` traces that C to
rac3-uya-decomp (vetusmagnus and contributors) and to its maintainers and contributors.

Each such file says so in a comment on its first lines (`C adapted from rac3-decomp func_XXXXXXXX`); the
exact donor file, function and commit of every one are recorded in the maintainers' review notes. The text
was then given this game's names and checked against this game's code.

The C of 3 functions started from the matching C of equivalent functions in
[rac2-decomp](https://github.com/OpenRAC/rac2-decomp) (*Ratchet & Clank: Going Commando*, GPL-3.0, commit
`1243c8ea`): `src/core/001399E0.c`, `src/core/00139A80.c`, `src/core/00139AE0.c`. They were found the same way (opcode sequences), renamed and checked against this game's code;
each file says so in its first-line comment (`C adapted from rac2-decomp func_XXXXXXXX`).

The C of 5 functions (`src/core/00155908.c`, `src/game/0046D6A8.c`, `src/game/0049B5E0.c`, `src/game/004A7C50.c`,
`src/game/004B5E18.c`) started from the SCES_532.85 reconstruction of the same routines in OpenRAC/rac4-decomp pull
request #43 (Shaar-games), and was then checked against this game's SCUS_974.65 bytes. Each file says so in its first-line
comment.

## Standard C library algorithm references (`src/core/`)

The matching reconstructions in this contribution were written against the retail
code, with public newlib algorithms as references. They are not unchanged vendor
files. The following original notices are preserved for the relevant mprec,
Berkeley stdio/stdlib, malloc and fdlibm algorithm families. The reference snapshot
is newlib commit `8a0efa53e44919bcf5ccb1d3353618a82afdf8bc` (2000-02-17).
These notices do not license all decompiled game/SDK code as newlib or GPL.

### David M. Gay / AT&T `mprec.c`

```
The author of this software is David M. Gay.

Copyright (c) 1991 by AT&T.

Permission to use, copy, modify, and distribute this software for any
purpose without fee is hereby granted, provided that this entire notice
is included in all copies of any software which is or includes a copy
or modification of this software and in all copies of the supporting
documentation for such software.

THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR AT&T MAKES ANY
REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
```

### Berkeley stdio sources (`fgets`, `fread`, `fwrite`, `fseek`, `puts`, `vsprintf`)

```
Copyright (c) 1990 The Regents of the University of California.
All rights reserved.

Redistribution and use in source and binary forms are permitted
provided that the above copyright notice and this paragraph are
duplicated in all such forms and that any documentation,
advertising materials, and other materials related to such
distribution and use acknowledge that the software was developed
by the University of California, Berkeley.  The name of the
University may not be used to endorse or promote products derived
from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
```

### Berkeley `getenv_r.c` (1987 notice)

```
Copyright (c) 1987 Regents of the University of California.
All rights reserved.

Redistribution and use in source and binary forms are permitted
provided that: (1) source distributions retain this entire copyright
notice and comment, and (2) distributions including binaries display
the following acknowledgement:  ``This product includes software
developed by the University of California, Berkeley and its contributors''
in the documentation or other materials provided with the distribution
and in all advertising materials mentioning features or use of this
software. Neither the name of the University nor the names of its
contributors may be used to endorse or promote products derived
from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
```

### Berkeley `strtol.c` / `strtoul.c` (1990 four-clause notice)

Both files carry this four-clause form; the exact copyright line varies (`1990 The Regents...` in `strtol.c`; `1990 Regents...` in `strtoul.c`). Preserve the applicable exact copyright line when source mapping is confirmed:

```
Copyright (c) 1990 The Regents of the University of California.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the University of
   California, Berkeley and its contributors.
4. Neither the name of the University nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
```

### Berkeley `qsort.c` (1992-1993 four-clause notice)

```
Copyright (c) 1992, 1993
The Regents of the University of California. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the University of
   California, Berkeley and its contributors.
4. Neither the name of the University nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
SUCH DAMAGE.
```

### Doug Lea malloc 2.6.4 public-domain statement

From `newlib/libc/stdlib/mallocr.c`:

```
A version of malloc/free/realloc written by Doug Lea and released to the
public domain.
VERSION 2.6.4  Thu Nov 28 07:54:55 1996  Doug Lea  (dl at gee)
```

This is the source's attribution/public-domain statement; it is not a BSD or GPL notice.

### Sun fdlibm (`s_floor.c`, `e_fmod.c`)

```
Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.

Developed at SunPro, a Sun Microsystems, Inc. business.
Permission to use, copy, modify, and distribute this
software is freely granted, provided that this notice
is preserved.
```

### Public-decompilation source references

All entries below refer to OpenRAC/rac3-decomp commit `403f30a9561324342c87802960eefbaaae13b372`. PAL and US symbols identify the same donor C; target names and layouts are independently checked against RAC4.

| RAC4 source | Donor source | PAL / US donor |
| --- | --- | --- |
| `src/core/001277A0.c` | `src/boot_elf/core/11FA10.c` | `func_0011FA10` / `func_0011FA10` |
| `src/core/00127878.c` | `src/boot_elf/core/11FA10.c` | `func_0011FAE8` / `func_0011FAE8` |
| `src/core/00128180.c` | `src/boot_elf/core/1200E0.c` | `func_001203F0` / `func_001203F0` |
| `src/core/00128348.c` | `src/boot_elf/core/1205B8.c` | `func_001205B8` / `func_001205B8` |
| `src/core/001283F8.c` | `src/boot_elf/core/120668.c` | `func_00120668` / `func_00120668` |
| `src/core/001293B0.c` | `src/boot_elf/core/121620.c` | `func_00121620` / `func_00121620` |
| `src/core/001294A8.c` | `src/boot_elf/core/121718.c` | `func_00121718` / `func_00121718` |
| `src/core/001294F0.c` | `src/boot_elf/core/121718.c` | `func_00121760` / `func_00121760` |
| `src/core/00129570.c` | `src/boot_elf/core/121718.c` | `func_00121760` / `func_00121760` |
| `src/core/00129660.c` | `src/boot_elf/core/1218B8.c` | `func_001218B8` / `func_001218B8` |
| `src/core/001299E0.c` | `src/boot_elf/core/121C38.c` | `func_00121C38` / `func_00121C38` |
| `src/core/0012A688.c` | `src/boot_elf/core/122780.c` | `func_00122780` / `func_00122780` |
| `src/core/0012A918.c` | `src/boot_elf/core/122A10.c` | `func_00122A10` / `func_00122A10` |
| `src/core/0012A970.c` | `src/boot_elf/core/122A68.c` | `func_00122A68` / `func_00122A68` |
| `src/core/0012A9E8.c` | `src/boot_elf/core/122AE0.c` | `func_00122AE0` / `func_00122AE0` |
| `src/core/0012AF88.c` | `src/boot_elf/core/123080.c` | `func_00123080` / `func_00123080` |
| `src/core/0012B270.c` | `src/boot_elf/core/123368.c` | `func_00123368` / `func_00123368` |
| `src/core/0012C2B0.c` | `src/boot_elf/core/123B98.c` | `func_00123B98` / `func_00123B98` |
| `src/core/0012C438.c` | `src/boot_elf/core/123B98.c` | `func_00123C90` / `func_00123C90` |
| `src/core/0012C4B8.c` | `src/boot_elf/core/123B98.c` | `func_00123D10` / `func_00123D10` |
| `src/core/0012C5B8.c` | `src/boot_elf/core/123368.c` | `func_00123368` / `func_00123368` |
| `src/core/0012CC30.c` | `src/boot_elf/core/124138.c` | `func_00124138` / `func_00124138` |
| `src/core/0012CF28.c` | `src/boot_elf/core/124430.c` | `func_00124430` / `func_00124430` |
| `src/core/0012CF80.c` | `src/boot_elf/core/124488.c` | `func_00124488` / `func_00124488` |
| `src/core/0012D488.c` | `src/boot_elf/core/124988.c` | `func_00124988` / `func_00124988` |
| `src/core/0012D528.c` | `src/boot_elf/core/124988.c` | `func_00124A28` / `func_00124A28` |
| `src/core/0012D580.c` | `src/boot_elf/core/124A80.c` | `func_00124A80` / `func_00124A80` |
| `src/core/0012D708.c` | `src/boot_elf/core/124430.c` | `func_00124430` / `func_00124430` |
| `src/core/0012D750.c` | `src/boot_elf/core/124C50.c` | `func_00124C50` / `func_00124C50` |
| `src/core/0012D7B8.c` | `src/boot_elf/core/124CB8.c` | `func_00124CB8` / `func_00124CB8` |
| `src/core/0012D878.c` | `src/boot_elf/core/124D78.c` | `func_00124D78` / `func_00124D78` |
| `src/core/0012D8B8.c` | `src/boot_elf/core/124DB8.c` | `func_00124DB8` / `func_00124DB8` |
| `src/core/0012D9D8.c` | `src/boot_elf/core/124ED8.c` | `func_00124ED8` / `func_00124ED8` |
| `src/core/0012DA70.c` | `src/boot_elf/core/124430.c` | `func_00124430` / `func_00124430` |
| `src/core/0012DAB8.c` | `src/boot_elf/core/124FB8.c` | `func_00124FB8` / `func_00124FB8` |
| `src/core/0012DC30.c` | `src/boot_elf/core/125130.c` | `func_00125130` / `func_00125130` |
| `src/core/0012DD90.c` | `src/boot_elf/core/125290.c` | `func_00125290` / `func_00125290` |
| `src/core/0012DFB8.c` | `src/boot_elf/core/1254B8.c` | `func_001254B8` / `func_001254B8` |
| `src/core/0012E040.c` | `src/boot_elf/core/125540.c` | `func_00125540` / `func_00125540` |
| `src/core/0012E460.c` | `src/boot_elf/core/1258E8.c` | `func_001258E8` / `func_001258E8` |
| `src/core/0012E548.c` | `src/boot_elf/core/1258E8.c` | `func_001259F0` / `func_001259F0` |
| `src/core/0012E650.c` | `src/boot_elf/core/1258E8.c` | `func_001259F0` / `func_001259F0` |
| `src/core/0012E7C8.c` | `src/boot_elf/core/125B68.c` | `func_00125B68` / `func_00125B68` |
| `src/core/0012E978.c` | `src/boot_elf/core/125D18.c` | `func_00125D18` / `func_00125D18` |
| `src/core/0012EAA8.c` | `src/boot_elf/core/125D18.c` | `func_00125E48` / `func_00125E48` |
| `src/core/00136E10.c` | `src/boot_elf/core/12AA78.c` | `func_0012AAE0` / `func_0012AAE0` |
| `src/core/00136F70.c` | `src/boot_elf/core/12AC40.c` | `func_0012AC40` / `func_0012AC40` |
| `src/core/001371D0.c` | `src/boot_elf/core/12AE20.c` | `func_0012AE20` / `func_0012AE20` |
| `src/core/00137258.c` | `src/boot_elf/core/12AE20.c` | `func_0012AEA8` / `func_0012AEA8` |
| `src/core/00137448.c` | `src/boot_elf/core/12B098.c` | `func_0012B098` / `func_0012B098` |
| `src/core/001374E8.c` | `src/boot_elf/core/12B138.c` | `func_0012B138` / `func_0012B138` |
| `src/core/00137998.c` | `src/boot_elf/core/12B5E8.c` | `func_0012B5E8` / `func_0012B5E8` |
| `src/core/00137BB0.c` | `src/boot_elf/core/12B5E8.c` | `func_0012B800` / `func_0012B800` |
| `src/core/001384F0.c` | `src/boot_elf/core/12C088.c` | `func_0012C088` / `func_0012C088` |
| `src/core/001389D8.c` | `src/boot_elf/core/12C4B0.c` | `func_0012C570` / `func_0012C570` |
| `src/core/00138D70.c` | `src/boot_elf/core/12C4B0.c` | `func_0012C908` / `func_0012C908` |
| `src/core/00139130.c` | `src/boot_elf/core/12CCC8.c` | `func_0012CCC8` / `func_0012CCC8` |
| `src/core/00139940.c` | `src/boot_elf/core/12CCC8.c` | `func_0012D4D8` / `func_0012D4D8` |
| `src/core/0013A160.c` | `src/boot_elf/core/12DCA0.c` | `func_0012DCA0` / `func_0012DCA0` |
| `src/core/0013A288.c` | `src/boot_elf/core/12DDC8.c` | `func_0012DDC8` / `func_0012DDC8` |
| `src/core/0013A868.c` | `src/boot_elf/core/12E3A8.c` | `func_0012E3A8` / `func_0012E3A8` |
| `src/core/0013A8C0.c` | `src/boot_elf/core/12E400.c` | `func_0012E400` / `func_0012E400` |
| `src/core/0013AC68.c` | `src/boot_elf/core/12E6D8.c` | `func_0012E7A8` / `func_0012E7A8` |
| `src/core/0013AE98.c` | `src/boot_elf/core/12E9B0.c` | `func_0012E9D8` / `func_0012E9D8` |
| `src/core/0013B018.c` | `src/boot_elf/core/12EB40.c` | `func_0012EB40` / `func_0012EB40` |
| `src/core/0013B168.c` | `src/boot_elf/core/12EB40.c` | `func_0012EC28` / `func_0012EC28` |
| `src/core/0013B8C8.c` | `src/boot_elf/core/12F2A0.c` | `func_0012F2A0` / `func_0012F2A0` |
| `src/core/0013BE88.c` | `src/boot_elf/core/12F728.c` | `func_0012F860` / `func_0012F860` |
| `src/core/0013BF40.c` | `src/boot_elf/core/12F728.c` | `func_0012F918` / `func_0012F918` |
| `src/core/0013C008.c` | `src/boot_elf/core/12F728.c` | `func_0012F9E0` / `func_0012F9E0` |
| `src/core/0013C0E0.c` | `src/boot_elf/core/12F728.c` | `func_0012FB68` / `func_0012FB68` |
| `src/core/0013C280.c` | `src/boot_elf/core/12FCE8.c` | `func_0012FCE8` / `func_0012FCE8` |
| `src/core/0013C750.c` | `src/boot_elf/core/130210.c` | `func_00130210` / `func_00130210` |
| `src/core/0013CFE0.c` | `src/boot_elf/core/130AA0.c` | `func_00130AA0` / `func_00130AA0` |
| `src/core/0013D8D8.c` | `src/boot_elf/core/131178.c` | `func_00131398` / `func_00131398` |
| `src/core/0013DE48.c` | `src/boot_elf/core/131178.c` | `func_00131908` / `func_00131908` |
| `src/core/0013E270.c` | `src/boot_elf/core/131178.c` | `func_00131D30` / `func_00131D30` |
| `src/core/0013E410.c` | `src/boot_elf/core/131178.c` | `func_00131ED0` / `func_00131ED0` |
| `src/core/0013E968.c` | `src/boot_elf/core/131178.c` | `func_00132428` / `func_00132428` |
| `src/core/0013EAE0.c` | `src/boot_elf/core/131178.c` | `func_001325A0` / `func_001325A0` |
| `src/core/0013EC48.c` | `src/boot_elf/core/131178.c` | `func_00132708` / `func_00132708` |
| `src/core/0013F018.c` | `src/boot_elf/core/132AD8.c` | `func_00132AD8` / `func_00132AD8` |
| `src/core/001400F8.c` | `src/boot_elf/core/133BB8.c` | `func_00133BB8` / `func_00133BB8` |
| `src/core/00140198.c` | `src/boot_elf/core/133BB8.c` | `func_00133C58` / `func_00133C58` |
| `src/core/00140338.c` | `src/boot_elf/core/133BB8.c` | `func_00133DF8` / `func_00133DF8` |
| `src/core/00140900.c` | `src/boot_elf/core/1343C0.c` | `func_001343C0` / `func_001343C0` |
| `src/core/001409A0.c` | `src/boot_elf/core/1343C0.c` | `func_00134460` / `func_00134460` |
| `src/core/00140AE8.c` | `src/boot_elf/core/1343C0.c` | `func_001345A8` / `func_001345A8` |
| `src/core/00140C28.c` | `src/boot_elf/core/1343C0.c` | `func_001346E8` / `func_001346E8` |
| `src/core/00140F38.c` | `src/boot_elf/core/1349F8.c` | `func_001349F8` / `func_001349F8` |
| `src/core/00141148.c` | `src/boot_elf/core/134C08.c` | `func_00134C08` / `func_00134C08` |
| `src/core/001412F8.c` | `src/boot_elf/core/134D68.c` | `func_00134DB8` / `func_00134DB8` |
| `src/core/00141388.c` | `src/boot_elf/core/134D68.c` | `func_00134E48` / `func_00134E48` |
| `src/core/00141420.c` | `src/boot_elf/core/134D68.c` | `func_00134EE0` / `func_00134EE0` |
| `src/core/001421A0.c` | `src/boot_elf/core/135C60.c` | `func_00135C60` / `func_00135C60` |
| `src/core/00142380.c` | `src/boot_elf/core/135CE0.c` | `func_00135E40` / `func_00135E40` |
| `src/core/00142448.c` | `src/boot_elf/core/135F08.c` | `func_00135F08` / `func_00135F08` |
| `src/core/00142610.c` | `src/boot_elf/core/1360D0.c` | `func_001360D0` / `func_001360D0` |
| `src/core/00142B60.c` | `src/boot_elf/core/136620.c` | `func_00136620` / `func_00136620` |
| `src/core/00143990.c` | `src/boot_elf/core/137450.c` | `func_00137450` / `func_00137450` |
| `src/core/00143B60.c` | `src/boot_elf/core/137450.c` | `func_00137620` / `func_00137620` |
| `src/core/001464D0.c` | `src/boot_elf/core/139F90.c` | `func_00139F90` / `func_00139F90` |
| `src/core/00146638.c` | `src/boot_elf/core/13A030.c` | `func_0013A0F8` / `func_0013A0F8` |
| `src/core/00146690.c` | `src/boot_elf/core/13A150.c` | `func_0013A150` / `func_0013A150` |
| `src/core/001466D0.c` | `src/boot_elf/core/13A150.c` | `func_0013A190` / `func_0013A190` |
| `src/core/001467C0.c` | `src/boot_elf/core/13A150.c` | `func_0013A280` / `func_0013A280` |
| `src/core/001468A8.c` | `src/boot_elf/core/13A150.c` | `func_0013A368` / `func_0013A368` |
| `src/core/00146AD8.c` | `src/boot_elf/core/13A520.c` | `func_0013A598` / `func_0013A598` |
| `src/core/00155510.c` | `src/boot_elf/core/13A520.c` | `func_0013A7D0` / `func_0013A7D0` |
| `src/core/00155580.c` | `src/boot_elf/core/13A520.c` | `func_0013A840` / `func_0013A840` |
| `src/core/001555C0.c` | `src/boot_elf/core/13A880.c` | `func_0013A880` / `func_0013A880` |
| `src/core/00155670.c` | `src/boot_elf/core/13A880.c` | `func_0013A930` / `func_0013A930` |
| `src/core/001556C8.c` | `src/boot_elf/core/13A880.c` | `func_0013A988` / `func_0013A988` |
| `src/core/00155760.c` | `src/boot_elf/core/13A880.c` | `func_0013AA20` / `func_0013AA20` |
| `src/core/00155780.c` | `src/boot_elf/core/13AA40.c` | `func_0013AA40` / `func_0013AA40` |
| `src/core/001557E8.c` | `src/boot_elf/core/13AA40.c` | `func_0013AA40` / `func_0013AA40` |
| `src/core/00155850.c` | `src/boot_elf/core/13AA40.c` | `func_0013AB10` / `func_0013AB10` |
| `src/core/00159670.c` | `src/boot_elf/core/13C8D0.c` | `func_0013CFF8` / `func_0013CFF8` |
| `src/core/001597B8.c` | `src/boot_elf/core/13C8D0.c` | `func_0013D120` / `func_0013D120` |
| `src/core/001637D0.c` | `src/boot_elf/text/3A1558.c` | `func_003A1730` / `func_003A15F0` |
| `src/game/0046CBD8.c` | `src/boot_elf/text/3C3398.c` | `func_003C3568` / `func_003C3450` |
| `src/game/0046D5C0.c` | `src/boot_elf/text/3C3B38.c` | `func_003C3C98` / `func_003C3B80` |
| `src/game/00489E28.c` | `src/boot_elf/text/3A1558.c` | `func_003A2E90` / `func_003A2D50` |
| `src/game/00489E80.c` | `src/boot_elf/text/3A1558.c` | `func_003A2EE8` / `func_003A2DA8` |
| `src/game/0048FA80.c` | `src/boot_elf/text/3A2FC0.c` | `func_003A30D8` / `func_003A2F98` |
| `src/game/004968E8.c` | `src/boot_elf/text/3B3408.c` | `func_003B3408` / `func_003B3268` |
| `src/game/00496A08.c` | `src/boot_elf/text/3B3408.c` | `func_003B3408` / `func_003B3268` |
| `src/game/00496A40.c` | `src/boot_elf/text/3B3408.c` | `func_003B3408` / `func_003B3268` |
| `src/game/004978C0.c` | `src/boot_elf/core/121860.c` | `func_00121890` / `func_00121890` |
| `src/game/004A2D40.c` | `src/boot_elf/text/3B3B08.c` | `func_003B4A40` / `func_003B4890` |
| `src/game/004CE410.c` | `src/boot_elf/core/121860.c` | `func_00121890` / `func_00121890` |
| `src/game/004CE428.c` | `src/boot_elf/core/121860.c` | `func_00121890` / `func_00121890` |
| `src/game/004D2058.c` | `src/boot_elf/core/121860.c` | `func_00121890` / `func_00121890` |
| `src/game/004D2070.c` | `src/boot_elf/core/121860.c` | `func_00121890` / `func_00121890` |
| `src/game/004D2088.c` | `src/boot_elf/core/121860.c` | `func_00121890` / `func_00121890` |
| `src/game/004E8068.c` | `src/boot_elf/text/3A9408.c` | `func_003A9DF8` / `func_003A9CB0` |
| `src/game/004E8298.c` | `src/boot_elf/text/3AA028.c` | `func_003AA028` / `func_003A9EE0` |
| `src/game/004EE6E8.c` | `src/boot_elf/text/3AACC8.c` | `func_003AACC8` / `func_003AAB70` |
| `src/game/004EEDC8.c` | `src/boot_elf/text/3AF658.c` | `func_003AF658` / `func_003AF4B8` |
| `src/game/004EF790.c` | `src/boot_elf/text/3B0400.c` | `func_003B04E8` / `func_003B0348` |
| `src/game/004EF948.c` | `src/boot_elf/text/3B0400.c` | `func_003B06A0` / `func_003B0500` |
| `src/game/004EFA68.c` | `src/boot_elf/text/3B0400.c` | `func_003B07C0` / `func_003B0620` |
| `src/game/004EFD88.c` | `src/boot_elf/text/3B0400.c` | `func_003B0AE0` / `func_003B0940` |
| `src/game/004EFE28.c` | `src/boot_elf/text/3B0400.c` | `func_003B0B80` / `func_003B09E0` |
| `src/game/004F0778.c` | `src/boot_elf/text/3B13A8.c` | `func_003B14C0` / `func_003B1320` |
| `src/game/004F0848.c` | `src/boot_elf/text/3B1590.c` | `func_003B1590` / `func_003B13F0` |
| `src/game/004F0978.c` | `src/boot_elf/text/3B1590.c` | `func_003B16C0` / `func_003B1520` |
| `src/game/004F0998.c` | `src/boot_elf/text/3B1590.c` | `func_003B16E0` / `func_003B1540` |
| `src/game/004F0A08.c` | `src/boot_elf/text/3B1590.c` | `func_003B1750` / `func_003B15B0` |
| `src/game/004F0A48.c` | `src/boot_elf/text/3B1590.c` | `func_003B1790` / `func_003B15F0` |
| `src/game/004F0BE8.c` | `src/boot_elf/text/3B1590.c` | `func_003B1930` / `func_003B1790` |
| `src/game/004F0CF0.c` | `src/boot_elf/text/3B1590.c` | `func_003B1A38` / `func_003B1898` |
| `src/game/004F0D68.c` | `src/boot_elf/text/3B1590.c` | `func_003B1AB0` / `func_003B1910` |
| `src/game/004F0EC8.c` | `src/boot_elf/text/3B1590.c` | `func_003B1C10` / `func_003B1A70` |
| `src/game/004F0FB8.c` | `src/boot_elf/text/3B1590.c` | `func_003B1D00` / `func_003B1B60` |
| `src/game/004F1618.c` | `src/boot_elf/text/3B1590.c` | `func_003B2360` / `func_003B21C0` |
| `src/game/004F1670.c` | `src/boot_elf/text/3B1590.c` | `func_003B23B8` / `func_003B2218` |
| `src/game/004F16C0.c` | `src/boot_elf/text/3B1590.c` | `func_003B2408` / `func_003B2268` |
| `src/game/004F1848.c` | `src/boot_elf/text/3B1590.c` | `func_003B2590` / `func_003B23F0` |
| `src/game/004F1950.c` | `src/boot_elf/text/3B1590.c` | `func_003B2698` / `func_003B24F8` |
| `src/game/004F2138.c` | `src/boot_elf/text/3B1590.c` | `func_003B1590` / `func_003B13F0` |
| `src/game/004F22F0.c` | `src/boot_elf/text/3B2DB8.c` | `func_003B3038` / `func_003B2E98` |
| `src/game/004F23B0.c` | `src/boot_elf/text/3B2DB8.c` | `func_003B30F8` / `func_003B2F58` |
| `src/game/004F6498.c` | `src/boot_elf/text/3D6DD8.c` | `func_003D6DD8` / `func_003D6C70` |
| `src/game/00500950.c` | `src/boot_elf/text/3E5C60.c` | `func_003E69F0` / `func_003E68A8` |
| `src/game/00501090.c` | `src/boot_elf/text/3E6A58.c` | `func_003E6F70` / `func_003E6E28` |
| `src/game/005012C8.c` | `src/boot_elf/text/3E6A58.c` | `func_003E71C8` / `func_003E7080` |
| `src/game/005013D0.c` | `src/boot_elf/text/3E6A58.c` | `func_003E72D0` / `func_003E7188` |
| `src/game/00501458.c` | `src/boot_elf/text/3E6A58.c` | `func_003E7358` / `func_003E7210` |
| `src/game/00505AD8.c` | `src/boot_elf/text/3E7758.c` | `func_003E86B0` / `func_003E8550` |
| `src/game/00506860.c` | `src/boot_elf/text/3E7758.c` | `func_003E93A0` / `func_003E9240` |
| `src/game/00506A78.c` | `src/boot_elf/text/3E7758.c` | `func_003E9710` / `func_003E95B0` |
| `src/game/0050DA70.c` | `src/boot_elf/text/3E5C60.c` | `func_003E5C78` / `func_003E5B30` |
| `src/game/00510C18.c` | `src/boot_elf/core/121860.c` | `func_00121890` / `func_00121890` |
| `src/core/0012C3C8.c` | `src/boot_elf/core/123B98.c` | `func_00123C90` / `func_00123C90` |
| `src/core/0012C888.c` | `src/boot_elf/core/123ED8.c` | `func_00123ED8` / `func_00123ED8` |
| `src/core/00137558.c` | `src/boot_elf/core/12AE20.c` | `func_0012AEA8` / `func_0012AEA8` |
| `src/core/00146748.c` | `src/boot_elf/core/13A150.c` | `func_0013A190` / `func_0013A190` |
| `src/core/00146A60.c` | `src/boot_elf/core/13A150.c` | `func_0013A190` / `func_0013A190` |
| `src/game/004F1AE8.c` | `src/frontbin/3AF2A0.c` | `func_003B2478` / `func_003ACED0` |
| `src/game/00500F70.c` | `src/boot_elf/text/3B3408.c` | `func_003E6E50` / `func_003E6D08` |
| `src/game/00501000.c` | `src/boot_elf/text/3B3408.c` | `func_003E6E50` / `func_003E6D08` |

## Lombyte I/O reference

`src/core/00127168.c` and `src/core/001271E8.c` use the public
[Lombyte decompilation](https://github.com/lombyte-project/Lombyte) as a reference:
`src/sdk/library/write.c` and `read.c` at commit
`0cf08ef39c8a2e37f122a5fdf5393856d7aefb09`. Call targets and shared state
were retargeted against Deadlocked's retail program; pointer parameters agree
with the TTY implementation in the public UYA decompilation. The source's
newlib attribution comments are retained.

### Additional PAL public-decompilation references

These PAL reconstructions also use the public RAC3 sources pinned below; each target was independently checked against RAC4.

| RAC4 source | RAC3 source | Donor function | Commit |
| --- | --- | --- | --- |
| `src/pal/overlays/l41_battledome_tower/L41_00449C20.c` | `src/levels/shared/L01_00515DE0.c` | `func_L01_00515DE0` | `cd0e7c20fd8a93116566ba2e024fa2f3536bd30c` |
| `src/pal/core/00159748.c` | `src/boot_elf/core/13C8D0.c` | `func_0013D080` | `cd0e7c20fd8a93116566ba2e024fa2f3536bd30c` |
| `src/pal/overlays/l00_multiplayer_menu/L00_007148A0.c` | `src/levels/39_multiplayer_menu/L39_0067F8A8.c` | `func_L39_0067F8B0` | `cd0e7c20fd8a93116566ba2e024fa2f3536bd30c` |
| `src/pal/overlays/shared/L00_006F2370.c` | `src/levels/shared/L39_00662678.c` | `func_L39_00665CC0` | `cd0e7c20fd8a93116566ba2e024fa2f3536bd30c` |
| `src/pal/overlays/l41_battledome_tower/L41_00411F80.c` | `src/levels/shared/L40_00420998.c` | `func_L40_004224F8` | `cd0e7c20fd8a93116566ba2e024fa2f3536bd30c` |
| `src/pal/overlays/l41_battledome_tower/L41_00621CE8.c` | `src/levels/shared/L40_005416F0.c` | `func_L40_005416F0` | `cd0e7c20fd8a93116566ba2e024fa2f3536bd30c` |
