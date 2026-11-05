# Work in Progress – RAC4 PAL

Diese Datei bündelt die vorhandenen Worker-Manifeste des aktuellen Abschlusses. **Strict-Match (Worker)** bedeutet, dass der Worker Byte-Match und Materialprüfung als bestanden gemeldet hat. Für den PR zählt die Funktion erst nach dem zentralen Audit der finalen Quelle. Teil Entwürfe und Near-Misses sind kein Matching-Fortschritt im Projektbericht.

## Zusammenfassung

- Funktionen mit Worker-Strict-Match: **35**
- Funktionen mit Teilentwurf oder Near-Miss: **140**
- Zurückgestellte oder verworfene Kandidaten: **3**
- Geprüfte Kandidaten ohne verwertbaren C-Entwurf: **5**
- Zugewiesene Kandidaten ohne dokumentierten Entwurf: **6**
- Eindeutige Funktionen in dieser Übersicht: **189**

Die drei letzten Workers haben nach der Abschlussanweisung nur noch ihre jeweils bereits geöffnete Funktion bearbeitet. Es werden keine weiteren Funktionen oder Subagents gestartet. Der PR enthält alle zentral bestandenen Funktionen auch dann, wenn es weniger als 50 sind.

## Funktionsübersicht

| Funktion | Status | Retail-Bytes | Beste Quelle | Varianten | Verbleibender Unterschied / Nachweis | Paket |
|---|---|---:|---|---:|---|---|
| `func_003F5738` | Teilentwurf / Near-Miss | 400 | `build/try/func_003F5738/candidate7.c` | - | - | batch08 |
| `func_003F64B0` | Teilentwurf / Near-Miss | 572 | `build/try/func_003F64B0/s2-1.c` | 1 | Structural: the catalogue entry merges a 336-byte function and a separate 236-byte function; one plain-C symbol cannot represent both. | orchestrator/paseo |
| `func_003F6F00` | Teilentwurf / Near-Miss | 396 | `build/try/func_003F6F00/candidate3.c` | - | - | batch08 |
| `func_003F7B38` | Zugewiesen; kein dokumentierter Entwurf | 832 | `-` | - | Nach Abschlussanweisung keine neue Funktion mehr beginnen. | orchestrator/paseo-batch09 |
| `func_003F7E78` | Zurückgestellt / verworfen | 808 | `-` | 0 | Two independent stack-frame entries at 0x3F7E7C and 0x3F8070; no single C function covers the catalogue range. | orchestrator/paseo-next |
| `func_003F88D8` | Geprüft; kein verwertbarer C-Entwurf | - | `-` | 0 | Complete 96-byte function is followed by unlabelled code blocks; the 612-byte catalogue region is not one standalone C function | orchestrator/paseo |
| `func_003F99D0` | Zurückgestellt / verworfen | 892 | `-` | 0 | Withheld without drafting: allocator wall with no new type/layout evidence and no understood family template. | orchestrator/paseo-batch09 |
| `func_003FEF38` | Teilentwurf / Near-Miss | 840 | `build/try/func_003FEF38/paseo09c_p03_sbox_byte_offsets.c` | 3 | Normal first-draft plus two-correction budget exhausted; 20-byte code-generation difference remains. | orchestrator/paseo-batch09 |
| `func_00408110` | Teilentwurf / Near-Miss | 332 | `build/try/func_00408110/p2.c` | - | - | batch08 |
| `func_0040A600` | Teilentwurf / Near-Miss | 384 | `build/try/func_0040A600/p5.c` | - | - | batch08 |
| `func_0040B808` | Teilentwurf / Near-Miss | 316 | `build/try/func_0040B808/candidate3.c` | - | - | batch08 |
| `func_0040D948` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo/b-candidates/0040D948.c` | 8 | best SIZE ours 540 / disc 572 | orchestrator/paseo |
| `func_0040F5D0` | Teilentwurf / Near-Miss | 336 | `build/try/func_0040F5D0/b_4.c` | - | - | batch08 |
| `func_0040F930` | Zurückgestellt / verworfen | 764 | `-` | 0 | Catalogue range contains two functions: main body at 0x40F930 and a separate prolog at 0x40FB98 with a 148-byte unaligned-copy helper through 0x40FC28. | orchestrator/paseo-next |
| `func_00410338` | Teilentwurf / Near-Miss | 296 | `build/try/func_00410338/b_3.c` | - | - | batch08 |
| `func_00410830` | Teilentwurf / Near-Miss | 356 | `build/try/func_00410830/p1.c` | - | - | batch08 |
| `func_00410ED0` | Teilentwurf / Near-Miss | 284 | `build/try/func_00410ED0/p4.c` | - | - | batch08 |
| `func_00415808` | Teilentwurf / Near-Miss | 892 | `build/try/paseo-batch09-a/func_00415808/p04_three_links.c` | 4 | 68 bytes. GCC coalesces the three independent linked-list walks into shorter beqz/movn/movz sequences; retail preserves separate lw/beql/nop chains at 0041592C-0041596C, 00415980-004159CC and 004159E8-00415A34. | orchestrator/paseo-batch09 |
| `func_00428F68` | Teilentwurf / Near-Miss | 288 | `build/try/func_00428F68/b_3.c` | - | - | batch08 |
| `func_00429508` | Teilentwurf / Near-Miss | 356 | `build/try/func_00429508/p7.c` | - | - | batch08 |
| `func_0042BB38` | Teilentwurf / Near-Miss | 384 | `build/try/func_0042BB38/p5.c` | - | - | batch08 |
| `func_00439330` | Strict-Match; Endaudit bestanden | - | `build/try/func_00439330/p7.c` | 7 | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | orchestrator/paseo |
| `func_00439BB8` | Teilentwurf / Near-Miss | 304 | `build/try/func_00439BB8/candidate.c` | - | - | batch08 |
| `func_00439F98` | Teilentwurf / Near-Miss | 348 | `build/try/func_00439F98/candidate7.c` | - | - | batch08 |
| `func_004492A8` | Teilentwurf / Near-Miss | 304 | `build/try/func_004492A8/p2.c` | - | - | batch08 |
| `func_004495D8` | Teilentwurf / Near-Miss | 388 | `build/try/func_004495D8/candidate20.c` | - | - | batch08 |
| `func_0044AAB8` | Strict-Match; Endaudit bestanden | 436 | `src/pal/game/0044AAB8.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_0044D690` | Teilentwurf / Near-Miss | 356 | `build/try/func_0044D690/p2.c` | - | - | batch08 |
| `func_0044DD78` | Teilentwurf / Near-Miss | 328 | `build/try/func_0044DD78/p3.c` | - | - | batch08 |
| `func_0044DEC0` | Teilentwurf / Near-Miss | 280 | `build/try/func_0044DEC0/candidate5.c` | - | - | batch08 |
| `func_0044E5B0` | Strict-Match; Endaudit bestanden | 324 | `src/pal/game/0044E5B0.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_00451788` | Teilentwurf / Near-Miss | 612 | `build/try/func_00451788/paseoa-1.c` | 6 | SIZE 612/616; variants 1/5/6 are byte-identical and one float initialization copy plus register allocation remains unresolved. | orchestrator/paseo |
| `func_0045D420` | Teilentwurf / Near-Miss | - | `build/try/func_0045D420/p6.c` | 8 | Search and nine record copies reconstructed; remaining base-register schedule differs | orchestrator/paseo |
| `func_0045FCB0` | Teilentwurf / Near-Miss | 576 | `build/try/func_0045FCB0/paseo-next-a-7.c` | 7 | Initial constant restored to 0x78, but pre-decrement, bgtz register and existing branch/register scheduling remain; no new ABI or layout evidence. | orchestrator/paseo-next |
| `func_0045FF18` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo-next/b-candidates/0045FF18-v2.c` | 2 | SIZE ours 636 / disc 756 (identical emission in both forms) | orchestrator/paseo-next |
| `func_00460DE8` | Teilentwurf / Near-Miss | 344 | `build/try/func_00460DE8/p9.c` | - | - | batch08 |
| `func_00461AF8` | Teilentwurf / Near-Miss | 364 | `build/try/func_00461AF8/p7.c` | - | - | batch08 |
| `func_00462518` | Teilentwurf / Near-Miss | 300 | `build/try/func_00462518/candidate.c` | - | - | batch08 |
| `func_00463150` | Teilentwurf / Near-Miss | 356 | `build/try/func_00463150/p6.c` | - | - | batch08 |
| `func_00464E28` | Strict-Match; Endaudit bestanden | 400 | `src/pal/game/00464E28.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_00466A20` | Strict-Match; Endaudit bestanden | 312 | `src/pal/game/00466A20.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_00469D70` | Teilentwurf / Near-Miss | 340 | `build/try/func_00469D70/candidate2.c` | - | - | batch08 |
| `func_0046B918` | Teilentwurf / Near-Miss | 280 | `build/try/func_0046B918/p2.c` | - | - | batch08 |
| `func_0046C1F0` | Teilentwurf / Near-Miss | 296 | `build/try/func_0046C1F0/b_3.c` | - | - | batch08 |
| `func_0046C810` | Teilentwurf / Near-Miss | 304 | `build/try/func_0046C810/candidate2.c` | - | - | batch08 |
| `func_0046F9E0` | Teilentwurf / Near-Miss | 284 | `build/try/func_0046F9E0/b_7.c` | - | - | batch08 |
| `func_00470088` | Teilentwurf / Near-Miss | 288 | `build/try/func_00470088/b_1.c` | - | - | batch08 |
| `func_00470480` | Teilentwurf / Near-Miss | 364 | `build/try/func_00470480/p4.c` | - | - | batch08 |
| `func_00479228` | Zugewiesen; kein dokumentierter Entwurf | 884 | `-` | - | Nach Abschlussanweisung keine neue Funktion mehr beginnen. | orchestrator/paseo-batch09 |
| `func_00481900` | Teilentwurf / Near-Miss | 324 | `build/try/func_00481900/candidate4.c` | - | - | batch08 |
| `func_00481A48` | Teilentwurf / Near-Miss | 328 | `build/try/func_00481A48/b_5.c` | - | - | batch08 |
| `func_00485948` | Strict-Match; Endaudit bestanden | - | `build/orchestrator/paseo/b-candidates/00485948.c` | 6 | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | orchestrator/paseo |
| `func_00489BE8` | Teilentwurf / Near-Miss | 324 | `build/try/func_00489BE8/p2.c` | - | - | batch08 |
| `func_00489F90` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo/b-candidates/00489F90.c` | 7 | best SIZE ours 612 / disc 616 | orchestrator/paseo |
| `func_0048AF50` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo-next/b-candidates/0048AF50-v2.c` | 3 | SIZE ours 752 / disc 764 | orchestrator/paseo-next |
| `func_0048C2F8` | Strict-Match; Endaudit bestanden | 292 | `src/pal/game/0048C2F8.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_0048CEF8` | Teilentwurf / Near-Miss | 384 | `build/try/func_0048CEF8/p2.c` | - | - | batch08 |
| `func_0048E530` | Teilentwurf / Near-Miss | 592 | `build/try/func_0048E530/paseoa-8.c` | 8 | Exact size with corrected pointer offsets; 257 bytes/98 words differ in register allocation, stack slots and search layout. | orchestrator/paseo |
| `func_0048FF78` | Geprüft; kein verwertbarer C-Entwurf | - | `-` | 0 | Not drafted | orchestrator/paseo-next |
| `func_00490418` | Teilentwurf / Near-Miss | 288 | `build/try/func_00490418/candidate3.c` | - | - | batch08 |
| `func_004980B0` | Teilentwurf / Near-Miss | 288 | `build/try/func_004980B0/b_6.c` | - | - | batch08 |
| `func_00499468` | Teilentwurf / Near-Miss | 352 | `build/try/func_00499468/p3.c` | - | - | batch08 |
| `func_004997D0` | Teilentwurf / Near-Miss | 284 | `build/try/func_004997D0/candidate5.c` | - | - | batch08 |
| `func_0049BA80` | Strict-Match; Endaudit bestanden | 540 | `src/pal/game/0049BA80.c` | 4 | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | orchestrator/paseo |
| `func_0049C698` | Teilentwurf / Near-Miss | 336 | `build/try/func_0049C698/b_11.c` | - | - | batch08 |
| `func_0049E710` | Teilentwurf / Near-Miss | 316 | `build/try/func_0049E710/p9.c` | - | - | batch08 |
| `func_0049E850` | Geprüft; kein verwertbarer C-Entwurf | - | `-` | 0 | Not drafted | orchestrator/paseo-next |
| `func_0049EE78` | Strict-Match; Endaudit bestanden | 376 | `src/pal/game/0049EE78.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004A0028` | Strict-Match; Endaudit bestanden | 388 | `src/pal/game/004A0028.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004A0230` | Strict-Match; Endaudit bestanden | 356 | `src/pal/game/004A0230.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004A1430` | Teilentwurf / Near-Miss | 376 | `build/try/func_004A1430/p8.c` | - | - | batch08 |
| `func_004A15A8` | Strict-Match; Endaudit bestanden | - | `src/pal/game/004A15A8.c` | 1 | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | orchestrator/paseo |
| `func_004A1720` | Strict-Match; Endaudit bestanden | 376 | `src/pal/game/004A1720.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004A1B58` | Teilentwurf / Near-Miss | 336 | `build/try/func_004A1B58/candidate9.c` | - | - | batch08 |
| `func_004A2468` | Geprüft; kein verwertbarer C-Entwurf | - | `-` | 0 | Not drafted | orchestrator/paseo-next |
| `func_004A2E90` | Teilentwurf / Near-Miss | 340 | `build/try/func_004A2E90/p3.c` | - | - | batch08 |
| `func_004A3408` | Teilentwurf / Near-Miss | 296 | `build/try/func_004A3408/candidate6.c` | - | - | batch08 |
| `func_004A5C70` | Teilentwurf / Near-Miss | - | `build/try/func_004A5C70/p4.c` | 6 | Correct size, two branch-local lookup call sites and f32[2] table form; index/found allocation remains | orchestrator/paseo |
| `func_004A6490` | Teilentwurf / Near-Miss | - | `build/try/func_004A6490/p3.c` | 5 | Record size 0x50 and nested vector transitions corrected; float register/branch schedule remains | orchestrator/paseo |
| `func_004A6C78` | Zugewiesen; kein dokumentierter Entwurf | 868 | `-` | - | Nach Abschlussanweisung keine neue Funktion mehr beginnen. | orchestrator/paseo-batch09 |
| `func_004A8FF0` | Teilentwurf / Near-Miss | 292 | `build/try/func_004A8FF0/candidate2.c` | - | - | batch08 |
| `func_004A9760` | Teilentwurf / Near-Miss | 292 | `build/try/func_004A9760/p2.c` | - | - | batch08 |
| `func_004A9A30` | Teilentwurf / Near-Miss | 260 | `build/try/func_004A9A30/b_4.c` | - | - | batch08 |
| `func_004A9CE0` | Teilentwurf / Near-Miss | 308 | `build/try/func_004A9CE0/candidate3.c` | - | - | batch08 |
| `func_004AA2E0` | Teilentwurf / Near-Miss | 856 | `build/try/func_004AA2E0/p04_float_lifetime.c` | 4 | Initial draft plus three corrections exhausted; two-word size and float/register lifetime differences remain. | orchestrator/paseo-batch09 |
| `func_004AB800` | Teilentwurf / Near-Miss | 304 | `build/try/func_004AB800/p3.c` | - | - | batch08 |
| `func_004AE2D8` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo/b-candidates/004AE2D8.c` | 3 | best SIZE ours 576 / disc 572 | orchestrator/paseo |
| `func_004AECE8` | Strict-Match; Endaudit bestanden | 444 | `src/pal/game/004AECE8.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004AFA88` | Teilentwurf / Near-Miss | 308 | `build/try/func_004AFA88/candidate.c` | - | - | batch08 |
| `func_004AFBC0` | Teilentwurf / Near-Miss | 336 | `build/try/func_004AFBC0/p2.c` | - | - | batch08 |
| `func_004B15A0` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo/b-candidates/004B15A0.c` | 8 | best SIZE ours 612 / disc 608 | orchestrator/paseo |
| `func_004B1978` | Teilentwurf / Near-Miss | - | `build/try/func_004B1978/p4.c` | 6 | Lookup values, float constants and late pointer increments reconstructed; frame/schedule remains | orchestrator/paseo |
| `func_004B34D8` | Teilentwurf / Near-Miss | 224 | `build/try/func_004B34D8/b_3.c` | - | - | batch08 |
| `func_004B3B48` | Teilentwurf / Near-Miss | 392 | `build/try/func_004B3B48/candidate3.c` | - | - | batch08 |
| `func_004B6B90` | Strict-Match; Endaudit bestanden | 200 | `src/pal/game/004B6B90.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004B6EE0` | Zugewiesen; kein dokumentierter Entwurf | 900 | `-` | - | Nach Abschlussanweisung keine neue Funktion mehr beginnen. | orchestrator/paseo-batch09 |
| `func_004B9048` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo/b-candidates/004B9048.c` | 8 | best SIZE ours 616 / disc 624 | orchestrator/paseo |
| `func_004B9B40` | Teilentwurf / Near-Miss | 884 | `build/try/func_004B9B40/p04_signed_kind.c` | 4 | Initial draft plus three corrections exhausted; 28 bytes of branch-layout and scheduling differences remain. | orchestrator/paseo-batch09 |
| `func_004BA130` | Strict-Match; Endaudit bestanden | 236 | `src/pal/game/004BA130.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004BA330` | Teilentwurf / Near-Miss | 284 | `build/try/func_004BA330/p3.c` | - | - | batch08 |
| `func_004BB770` | Teilentwurf / Near-Miss | 832 | `build/try/func_004BB770/p01_ui_init.c` | 3 | Two identical emissions; only descriptor-table/handle s0-s1 allocation remains. | orchestrator/paseo-batch09 |
| `func_004BC100` | Teilentwurf / Near-Miss | 348 | `build/try/func_004BC100/p3.c` | - | - | batch08 |
| `func_004BD810` | Teilentwurf / Near-Miss | 204 | `build/try/func_004BD810/candidate4.c` | - | - | batch08 |
| `func_004BEBF8` | Teilentwurf / Near-Miss | 620 | `build/try/func_004BEBF8/paseoa-7.c` | 8 | Exact size; 227 bytes/86 words differ in early-mode register lifetime and shared-path layout. | orchestrator/paseo |
| `func_004BEE68` | Zugewiesen; kein dokumentierter Entwurf | 820 | `-` | - | Nach Abschlussanweisung keine neue Funktion mehr beginnen. | orchestrator/paseo-batch09 |
| `func_004C0708` | Teilentwurf / Near-Miss | 384 | `build/try/func_004C0708/p8.c` | - | - | batch08 |
| `func_004C1F18` | Teilentwurf / Near-Miss | 372 | `build/try/func_004C1F18/p3.c` | - | - | batch08 |
| `func_004C3438` | Teilentwurf / Near-Miss | 320 | `build/try/func_004C3438/candidate3.c` | - | - | batch08 |
| `func_004C37C8` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo/b-candidates/004C37C8.c` | 8 | best BYTES 308/576 (116 words differ) | orchestrator/paseo |
| `func_004C4B08` | Teilentwurf / Near-Miss | 356 | `build/try/func_004C4B08/p5.c` | - | - | batch08 |
| `func_004C67C8` | Teilentwurf / Near-Miss | 384 | `build/try/func_004C67C8/p1.c` | - | - | batch08 |
| `func_004C6E98` | Teilentwurf / Near-Miss | 324 | `build/try/func_004C6E98/b_9.c` | - | - | batch08 |
| `func_004C7798` | Teilentwurf / Near-Miss | 368 | `build/try/func_004C7798/p8.c` | - | - | batch08 |
| `func_004C84D0` | Teilentwurf / Near-Miss | 320 | `build/try/func_004C84D0/p11.c` | - | - | batch08 |
| `func_004CA168` | Strict-Match; Endaudit bestanden | 392 | `src/pal/game/004CA168.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004CC7D8` | Strict-Match; Endaudit bestanden | 604 | `build/try/func_004CC7D8/paseo-next-a-8.c` | 8 | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | orchestrator/paseo-next |
| `func_004CD2F0` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo-next/b-candidates/004CD2F0-v3.c` | 3 | BYTES 124/812 (54 words; variants 2 and 3 identical) | orchestrator/paseo-next |
| `func_004CD8A0` | Strict-Match; Endaudit bestanden | 276 | `src/pal/game/004CD8A0.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004CEB68` | Strict-Match; Endaudit bestanden | 308 | `src/pal/game/004CEB68.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004CFF40` | Strict-Match; Endaudit bestanden | 320 | `src/pal/game/004CFF40.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004D0C20` | Teilentwurf / Near-Miss | 320 | `build/try/func_004D0C20/b_3.c` | - | - | batch08 |
| `func_004D1480` | Teilentwurf / Near-Miss | 584 | `build/try/func_004D1480/paseo-next-a-2.c` | 4 | Lookup-path layout and register scheduling; named visible result restored exact size, early lookup pointer and nested lookup both regressed. | orchestrator/paseo-next |
| `func_004D2618` | Teilentwurf / Near-Miss | 600 | `build/try/func_004D2618/paseoa-2.c` | 6 | 58 bytes/31 words differ; variants 2/3/6 are byte-identical and saved-register/global-access scheduling remains unresolved. | orchestrator/paseo |
| `func_004D3290` | Zugewiesen; kein dokumentierter Entwurf | 852 | `-` | - | Nach Abschlussanweisung keine neue Funktion mehr beginnen. | orchestrator/paseo-batch09 |
| `func_004D3AD0` | Strict-Match; Endaudit bestanden | 368 | `src/pal/game/004D3AD0.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004D5B70` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo/b-candidates/004D5B70.c` | 4 | best SIZE ours 544 / disc 548 | orchestrator/paseo |
| `func_004D5D98` | Teilentwurf / Near-Miss | 828 | `build/try/func_004D5D98/paseo09c_p06_ui_entry_contract.c` | 8 | 0x006C/0x0070: candidate loads and branches on v0; retail uses v1 for record[0].; 0x0148: color-branch displacement is 0x1F in the candidate and 0x20 in retail.; 0x015C and 0x01D8: retail schedules daddu s1,s0 after the first color-handle call; the candidate … | orchestrator/paseo-batch09 |
| `func_004D6590` | Teilentwurf / Near-Miss | 320 | `build/try/func_004D6590/candidate2.c` | - | - | batch08 |
| `func_004D6920` | Strict-Match; Endaudit bestanden | 392 | `src/pal/game/004D6920.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004D7290` | Strict-Match; Endaudit bestanden | 296 | `src/pal/game/004D7290.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_004D7E58` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo-next/b-candidates/004D7E58.c` | 4 | SIZE ours 756 / disc 764 | orchestrator/paseo-next |
| `func_004D8AD8` | Teilentwurf / Near-Miss | 384 | `build/try/func_004D8AD8/candidate2.c` | - | - | batch08 |
| `func_004D8DF8` | Teilentwurf / Near-Miss | 376 | `build/try/func_004D8DF8/p6.c` | - | - | batch08 |
| `func_004D9178` | Teilentwurf / Near-Miss | 276 | `build/try/func_004D9178/p3.c` | - | - | batch08 |
| `func_004D9F60` | Teilentwurf / Near-Miss | 544 | `build/try/func_004D9F60/s1-2.c` | 8 | Exact size; 63 bytes differ in saved-register coloring and temporary reuse. | orchestrator/paseo |
| `func_004DB1F8` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo-next/b-candidates/004DB1F8-v2.c` | 3 | BYTES 249/780 (85 words) | orchestrator/paseo-next |
| `func_004DB508` | Teilentwurf / Near-Miss | 332 | `build/try/func_004DB508/b_2.c` | - | - | batch08 |
| `func_004DB660` | Strict-Match; Endaudit bestanden | - | `build/orchestrator/paseo/b-candidates/004DB660.c` | 4 | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | orchestrator/paseo |
| `func_004DCDC0` | Strict-Match; Endaudit bestanden | 792 | `build/orchestrator/paseo-next/b-candidates/004DCDC0-v2.c` | 2 | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | orchestrator/paseo-next |
| `func_004DD908` | Teilentwurf / Near-Miss | 308 | `build/try/func_004DD908/candidate3.c` | - | - | batch08 |
| `func_004DFD38` | Teilentwurf / Near-Miss | 288 | `build/try/func_004DFD38/p6.c` | - | - | batch08 |
| `func_004E58F8` | Teilentwurf / Near-Miss | 324 | `build/try/func_004E58F8/b_2.c` | - | - | batch08 |
| `func_004E5D18` | Teilentwurf / Near-Miss | 196 | `build/try/func_004E5D18/b_5.c` | - | - | batch08 |
| `func_004E9200` | Teilentwurf / Near-Miss | 340 | `build/try/func_004E9200/candidate2.c` | - | - | batch08 |
| `func_004EF820` | Teilentwurf / Near-Miss | 360 | `build/try/func_004EF820/p11.c` | - | - | batch08 |
| `func_004F00E0` | Teilentwurf / Near-Miss | 868 | `build/try/func_004F00E0/p02_conditional_moves.c` | 3 | Normal correction budget exhausted; conditional moves, saved-register allocation and call-delay scheduling remain. | orchestrator/paseo-batch09 |
| `func_004F2780` | Teilentwurf / Near-Miss | 300 | `build/try/func_004F2780/b_4.c` | - | - | batch08 |
| `func_004F4288` | Teilentwurf / Near-Miss | 364 | `build/try/func_004F4288/p7.c` | - | - | batch08 |
| `func_004F4BE0` | Teilentwurf / Near-Miss | 556 | `build/try/func_004F4BE0/s2-8.c` | 8 | Five bytes/two words differ in emission order around the func_00126E20 delay slot. | orchestrator/paseo |
| `func_004F55C0` | Teilentwurf / Near-Miss | - | `build/try/func_004F55C0/p3.c` | 4 | Initial and final value selection corrected; remaining control-flow/address schedule differs | orchestrator/paseo |
| `func_004F6BD0` | Teilentwurf / Near-Miss | 304 | `build/try/func_004F6BD0/candidate4.c` | - | - | batch08 |
| `func_004FC068` | Strict-Match; Endaudit bestanden | 552 | `build/try/func_004FC068/paseo-next-a-10.c` | 10 | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | orchestrator/paseo-next |
| `func_004FCE40` | Teilentwurf / Near-Miss | 356 | `build/try/func_004FCE40/p13.c` | - | - | batch08 |
| `func_004FD1D0` | Teilentwurf / Near-Miss | 296 | `build/try/func_004FD1D0/b_3.c` | - | - | batch08 |
| `func_004FEBB8` | Teilentwurf / Near-Miss | 300 | `build/try/func_004FEBB8/paseo-next-a-11.c` | 13 | 27 words of index/list/string register coloring after correcting the call to three explicit arguments: string, current 0x40-byte entry and entry+0x38 length. Three consecutive source forms emitted identical bytes. | orchestrator/paseo-next |
| `func_005027A0` | Teilentwurf / Near-Miss | 224 | `build/try/func_005027A0/candidate5.c` | - | - | batch08 |
| `func_00503AF8` | Teilentwurf / Near-Miss | 856 | `build/try/func_00503AF8/paseo09c_p04_switch.c` | 5 | Two consecutive identical emissions; case-zero multiply and register allocation remain unresolved. | orchestrator/paseo-batch09 |
| `func_00503E50` | Teilentwurf / Near-Miss | 548 | `build/try/func_00503E50/s1-2.c` | 5 | 259 bytes/92 words differ; variants 2/4/5 are byte-identical and arg3 spill selection remains unresolved. | orchestrator/paseo |
| `func_00504468` | Teilentwurf / Near-Miss | 820 | `build/try/func_00504468/p03_split_count.c` | 4 | Initial draft plus three corrections exhausted; header-address and manager-path allocation remains unresolved. | orchestrator/paseo-batch09 |
| `func_005049B8` | Strict-Match; Endaudit bestanden | 312 | `src/pal/game/005049B8.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_00504CC8` | Teilentwurf / Near-Miss | 204 | `build/try/func_00504CC8/p2.c` | - | - | batch08 |
| `func_005061B0` | Strict-Match; Endaudit bestanden | 276 | `src/pal/game/005061B0.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_00506760` | Strict-Match; Endaudit bestanden | 276 | `src/pal/game/00506760.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_005079C8` | Teilentwurf / Near-Miss | 324 | `build/try/func_005079C8/candidate2.c` | - | - | batch08 |
| `func_0050CF28` | Teilentwurf / Near-Miss | 276 | `build/try/func_0050CF28/p10.c` | - | - | batch08 |
| `func_0050DA40` | Teilentwurf / Near-Miss | 284 | `build/try/func_0050DA40/b_5.c` | - | - | batch08 |
| `func_0050DD30` | Teilentwurf / Near-Miss | 280 | `build/try/func_0050DD30/candidate6.c` | - | - | batch08 |
| `func_0050F508` | Teilentwurf / Near-Miss | 880 | `build/try/func_0050F508/paseo09c_p01_render.c` | 3 | Normal variant budget exhausted; separate signed-alpha fade paths and object+0xC 64-bit shift remain unresolved. | orchestrator/paseo-batch09 |
| `func_00511740` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo/b-candidates/00511740.c` | 8 | best BYTES 94/548 (43 words differ) | orchestrator/paseo |
| `func_00513AC8` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo-next/b-candidates/00513AC8-v3.c` | 3 | SIZE ours 672 / disc 784 | orchestrator/paseo-next |
| `func_00517210` | Teilentwurf / Near-Miss | 388 | `build/try/func_00517210/candidate19.c` | - | - | batch08 |
| `func_00518C90` | Teilentwurf / Near-Miss | 892 | `build/try/func_00518C90/p03_second_if_tree.c` | 4 | Initial draft plus three corrections exhausted; case-store tail merging and branch layout remain unresolved. | orchestrator/paseo-batch09 |
| `func_0051CCC0` | Strict-Match; Endaudit bestanden | 296 | `src/pal/game/0051CCC0.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_0051CDF0` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo/b-candidates/0051CDF0.c` | 8 | best SIZE ours 584 / disc 592 | orchestrator/paseo |
| `func_00522518` | Strict-Match; Endaudit bestanden | 344 | `src/pal/game/00522518.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_00524030` | Teilentwurf / Near-Miss | - | `build/orchestrator/paseo/b-candidates/00524030.c` | 8 | best BYTES 272/600 (86 words differ) | orchestrator/paseo |
| `func_00526EA8` | Strict-Match; Endaudit bestanden | 384 | `src/pal/game/00526EA8.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_00528248` | Teilentwurf / Near-Miss | 368 | `build/try/func_00528248/p2.c` | - | - | batch08 |
| `func_00535E60` | Teilentwurf / Near-Miss | 304 | `build/try/func_00535E60/p2.c` | - | - | batch08 |
| `func_005412B0` | Teilentwurf / Near-Miss | - | `build/try/func_005412B0/p4.c` | 6 | Object layout corrected through f51@0x51; register allocation and State/neg scheduling remain | orchestrator/paseo |
| `func_005433D0` | Teilentwurf / Near-Miss | 580 | `build/try/func_005433D0/s2-8.c` | 8 | Exact size and correct float sequence; 156 bytes/79 words differ in integer allocation, threshold addressing and branch scheduling. | orchestrator/paseo |
| `func_00545844` | Geprüft; kein verwertbarer C-Entwurf | - | `-` | 0 | Entry begins mid-dataflow with live v0/s0/s1 and no function prologue; no standalone C candidate | orchestrator/paseo |
| `func_00548190` | Teilentwurf / Near-Miss | 320 | `build/try/func_00548190/candidate.c` | - | - | batch08 |
| `func_005488C8` | Teilentwurf / Near-Miss | 752 | `build/try/func_005488C8/paseo-next-a-3.c` | 4 | 100 words of loop/register scheduling; signed field fixes preserved size, direct globals restored exact size, shared final call regressed to 744 bytes. | orchestrator/paseo-next |
| `func_00548BB8` | Teilentwurf / Near-Miss | 896 | `build/try/func_00548BB8/paseo09c_p03_rows.c` | 3 | Normal first-draft plus two-correction budget exhausted; 190 words still differ in global materialization and register scheduling. | orchestrator/paseo-batch09 |
| `func_005497E8` | Teilentwurf / Near-Miss | 276 | `build/try/func_005497E8/b_2.c` | - | - | batch08 |
| `func_0054B328` | Teilentwurf / Near-Miss | 328 | `build/try/func_0054B328/candidate4.c` | - | - | batch08 |
| `func_0054D7B8` | Strict-Match; Endaudit bestanden | 360 | `src/pal/game/0054D7B8.c` | - | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | batch08 |
| `func_0054E1C8` | Strict-Match; Endaudit bestanden | - | `build/orchestrator/paseo/b-candidates/0054E1C8.c` | 5 | Finale Quelle, Relokationen, Initialwerte und SHA wurden zentral geprüft. | orchestrator/paseo |

## Nachweise

Die Angaben stammen aus den `*-matches.json`-Manifesten unter `build/batch08/`, `build/orchestrator/paseo/`, `build/orchestrator/paseo-next/` und `build/orchestrator/paseo-batch09/`. Die Quell- und Diffpfade sind lokale Scratch-Nachweise und keine zusätzlichen PR-Dateien. Der finale PR-Audit wird separat unter `build/` abgelegt; veröffentlicht werden nur erlaubte Quellen und Metadaten.
