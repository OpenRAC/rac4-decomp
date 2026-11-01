# Forty-five NTSC-U helpers: publication snapshot

This publication branch rebases the forty-five verified local matches onto
upstream `fe6ec0d2`. The reconstructed source files are byte-for-byte unchanged
from the local work. Historical batch notes describe their original checkout
and audit baselines; this snapshot describes the rebased publication result.

The collection contains **45 matched functions / 1,936 retail bytes**. All
5,306 non-library C translation units compile in the complete source build.
The 45 newly built objects pass full non-relocated-field comparison and
standard relocation resolution in an in-memory proof copy, with **28 actual
call/address target groups** checked independently. No compiler object is
patched, and this is static matching proof, not a game or native-port test.

The merged compiler script preserves upstream `@lit4` handling and float
constant expansion for SN code, together with the pinned compiler profiles
needed by these sources. Compiler options remain whole-file options. All
26 compiler-route/profile tests pass. Compiler binaries, private runtimes,
retail inputs, generated assembly, objects and scratch evidence stay local.

Against a same-pipeline upstream baseline with these 45 objects excluded,
the legacy audit increases from **3,756 to 3,801 exact functions**. It retains
the same three non-exact and 827 unlisted functions. Full relocation discrepancy
records remain byte-identical: 80 preexisting mismatches and three unresolved
targets. The new functions have no new mismatches or unresolved targets.

The US coverage and progress checks pass at **4,520 of 18,086 functions /
352,712 of 5,782,424 bytes**. The increase is exactly 45 functions and
1,936 matched bytes. The official inventory generator was used to split
`func_01EC3498`'s proven 32-byte extent from the independent 12-byte neighbor
`func_01EC34B8`; the neighbor remains unmatched. This adds one function to the
inventory denominator and corrects the previous twelve-byte overcredit.
Only these two officially generated inventory rows and the 45 new verified US
map rows were adopted; all unrelated upstream rows and ordering are preserved.
The official map generator's 59 unrelated baseline differences remain excluded.

**Draft review limitation:** PAL retail inputs are unavailable. PAL sources,
map, report and README progress are unchanged from upstream. The PAL coverage
check fails because the 45 new US source functions lack PAL map rows. No PAL
match, mismatch or regional equivalence is invented. A contributor with the
PAL inputs must regenerate and review PAL mapping before this draft is merged.
The current CI workflow runs both regional checks, so this limitation prevents
a green progress-report job until the PAL work is completed.

All seventeen open PR patches were checked against the complete function set;
no direct source/function overlap was found. The deferred `func_01EEEDA0`
scheduling near miss and all scratch attempts are excluded from this commit.
Its local claim was released. No game launch, desktop input or upstream merge
was performed. Matching work is paused after this publication batch.

| Function | Verified retail bytes |
| --- | ---: |
| `func_001221D8` | 108 |
| `func_0014ADD8` | 56 |
| `func_0014C368` | 68 |
| `func_0014D010` | 68 |
| `func_0014DE80` | 84 |
| `func_01E9B268` | 40 |
| `func_01EA0610` | 40 |
| `func_01EA47E8` | 40 |
| `func_01EA4EE8` | 32 |
| `func_01EA71C8` | 36 |
| `func_01EA88A0` | 36 |
| `func_01EA9800` | 36 |
| `func_01EA9D98` | 72 |
| `func_01EA9FE8` | 52 |
| `func_01EAA020` | 52 |
| `func_01EAA060` | 52 |
| `func_01EAA0D0` | 96 |
| `func_01EB0D78` | 28 |
| `func_01EB4DB0` | 28 |
| `func_01EB4DE8` | 36 |
| `func_01EB4E40` | 36 |
| `func_01EB4FF0` | 36 |
| `func_01EB7288` | 36 |
| `func_01EB72B0` | 36 |
| `func_01EB72D8` | 36 |
| `func_01EB84B8` | 36 |
| `func_01EBDED0` | 32 |
| `func_01EBDEF0` | 32 |
| `func_01EC2840` | 40 |
| `func_01EC3498` | 32 |
| `func_01EC52B8` | 36 |
| `func_01EC9B08` | 40 |
| `func_01ED5548` | 36 |
| `func_01ED5570` | 32 |
| `func_01ED5638` | 32 |
| `func_01ED8500` | 40 |
| `func_01ED9BE8` | 32 |
| `func_01EDA098` | 28 |
| `func_01EDB030` | 36 |
| `func_01EDB388` | 36 |
| `func_01EED4D8` | 40 |
| `func_01EEE000` | 40 |
| `func_01EF21FC` | 32 |
| `func_01EFA2A4` | 36 |
| `func_01F07154` | 28 |
