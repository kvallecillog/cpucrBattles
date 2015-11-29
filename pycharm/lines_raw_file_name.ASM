1 
2 ;***********************************************************************************************************************
3 ; INSTRUCCIONES INMEDIATAS
4 ;***********************************************************************************************************************
5 
6 ;=============================================================
7 ; PRUEBA DE INSTRUCCION LDA INMEDIATA.
8 ;=============================================================
9 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
10 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
11 ;OCT LDA #@02 ; LDA CON ARGUMENTO OCTAL.
12 ;HEX LDA #$03 ; LDA CON ARGUMENTO HEXADECIMAL.
13 ;DEC LDA #4 ; LDA CON ARGUMENTO DECIMAL.
14 ;HLT ; INSTRUCCION DE DETENCION.
15 ;=============================================================
16 
17 ;=============================================================
18 ; PRUEBA DE INSTRUCCION ADD INMEDIATA.
19 ;=============================================================
20 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
21 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
22 ;BIN ADD #%000010 ; ADD CON ARGUMENTO BINARIO.
23 ;OCT ADD #@02 ; ADD CON ARGUMENTO OCTACL.
24 ;DEC ADD #2 ; ADD CON ARGUMENTO DECIMAL.
25 ;HEX ADD #$02 ; ADD CON ARGUMENTO HEXADECIMAL.
26 ;HLT ; INSTRUCCION DE DETENCION.
27 ;=============================================================
28 
29 ;=============================================================
30 ; PRUEBA DE INSTRUCCION SUB INMEDIATA.
31 ;=============================================================
32 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
33 ;L1 LDA #10 ; LDA CON ARGUMENTO DECIMAL.
34 ;BIN SUB #%000010 ; SUB CON ARGUMENTO BINARIO.
35 ;OCT SUB #@02 ; SUB CON ARGUMENTO OCTACL.
36 ;DEC SUB #2 ; SUB CON ARGUMENTO DECIMAL.
37 ;HEX SUB #$02 ; SUB CON ARGUMENTO HEXADECIMAL.
38 ;HLT ; INSTRUCCION DE DETENCION.
39 ;=============================================================
40 
41 ;=============================================================
42 ; PRUEBA DE INSTRUCCION AND INMEDIATA.
43 ;=============================================================
44 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
45 ;L1 LDA #%111111 ; LDA CON ARGUMENTO DECIMAL.
46 ;BIN AND #%000111 ; AND CON ARGUMENTO BINARIO.
47 ;OCT AND #@07 ; AND CON ARGUMENTO OCTACL.
48 ;DEC AND #3 ; AND CON ARGUMENTO DECIMAL.
49 ;HEX AND #$01 ; AND CON ARGUMENTO HEXADECIMAL.
50 ;HLT ; INSTRUCCION DE DETENCION.
51 ;=============================================================
52 
53 ;=============================================================
54 ; PRUEBA DE INSTRUCCION ORA INMEDIATA.
55 ;=============================================================
56 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
57 ;L1 LDA #%101000 ; LDA CON ARGUMENTO DECIMAL.
58 ;BIN ORA #%000101 ; ORA CON ARGUMENTO BINARIO.
59 ;OCT ORA #@20 ; ORA CON ARGUMENTO OCTACL.
60 ;DEC ORA #2 ; ORA CON ARGUMENTO DECIMAL.
61 ;HEX ORA #$00 ; ORA CON ARGUMENTO HEXADECIMAL.
62 ;HLT ; INSTRUCCION DE DETENCION.
63 ;=============================================================
64 
65 ;***********************************************************************************************************************
66 
67 
68 ;***********************************************************************************************************************
69 ; INSTRUCCIONES ABSOLUTAS
70 ;***********************************************************************************************************************
71 
72 ;=============================================================
73 ; PRUEBA DE INSTRUCCION LDA ABSOLUTA.
74 ;=============================================================
75 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
76 ;L1 LDA @01 ; LDA ABSOLUTO.
77 ;HLT ; INSTRUCCION DE DETENCION.
78 ;=============================================================
79 
80 ;=============================================================
81 ; PRUEBA DE INSTRUCCION STA ABSOLUTA.
82 ;=============================================================
83 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
84 ;L1 LDA #7 ; LDA INMEDIATO.
85 ;L2 STA @0020 ; STA ABSOLUTO.
86 ;L3 ADD #1 ; LDA INMEDIATO.
87 ;L4 LDA @0020 ; LDA ABSOLUTO.
88 ;HLT ; INSTRUCCION DE DETENCION.
89 ;=============================================================
90 
91 ;=============================================================
92 ; PRUEBA DE INSTRUCCION ADD ABSOLUTA.
93 ;=============================================================
94 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
95 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
96 ;L2 STA @0020 ; STA ABSOLUTO.
97 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
98 ;L4 ADD @0020 ; ADD ABSOLUTA.
99 ;HLT ; INSTRUCCION DE DETENCION.
100 ;=============================================================
101 
102 ;=============================================================
103 ; PRUEBA DE INSTRUCCION SUB ABSOLUTA.
104 ;=============================================================
105 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
106 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
107 ;L2 STA @0020 ; STA ABSOLUTO.
108 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
109 ;L4 SUB @0020 ; SUB ABSOLUTA.
110 ;HLT ; INSTRUCCION DE DETENCION.
111 ;=============================================================
112 
113 ;=============================================================
114 ; PRUEBA DE INSTRUCCION AND ABSOLUTA.
115 ;=============================================================
116 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
117 ;L1 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
118 ;L2 STA @0020 ; STA ABSOLUTO.
119 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
120 ;L4 AND @0020 ; AND ABSOLUTAL.
121 ;HLT ; INSTRUCCION DE DETENCION.
122 ;=============================================================
123 
124 ;=============================================================
125 ; PRUEBA DE INSTRUCCION ORA ABSOLUTA.
126 ;=============================================================
127 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
128 ;L1 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
129 ;L2 STA @0020 ; STA ABSOLUTO.
130 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
131 ;L4 ORA @0020 ; ORA ABSOLUTA.
132 ;HLT ; INSTRUCCION DE DETENCION.
133 ;=============================================================
134 
135 ;***********************************************************************************************************************
136 
137 ;***********************************************************************************************************************
138 ; INSTRUCCIONES INDIRECTAS
139 ;***********************************************************************************************************************
140 ;=============================================================
141 ; PRUEBA DE INSTRUCCION LDA INDIRECTA.
142 ;=============================================================
143 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
144 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
145 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
146 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
147 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
148 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
149 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @0102.
150 ;L7 LDA (@0010) ; LDA INDIRECTO.
151 ;HLT ; INSTRUCCION DE DETENCION.
152 ;=============================================================
153 
154 ;=============================================================
155 ; PRUEBA DE INSTRUCCION STA INDIRECTA.
156 ;=============================================================
157 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
158 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
159 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
160 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
161 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
162 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
163 ;L6 STA (@0010) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
164 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
165 ;L8 LDA @2211 ; LDA ABSOLUTO.
166 ;HLT ; INSTRUCCION DE DETENCION.
167 ;=============================================================
168 
169 ;=============================================================
170 ; PRUEBA DE INSTRUCCION ADD INDIRECTA.
171 ;=============================================================
172 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
173 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
174 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
175 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
176 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
177 ;L5 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
178 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
179 ;L7 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
180 ;L8 ADD (@0010) ; ADD INDIRECTO, ESCRITURA DE 7 A @0102.
181 ;L9 LDA @2211 ; LDA ABSOLUTO.
182 ;HLT ; INSTRUCCION DE DETENCION.
183 ;=============================================================
184 
185 ;=============================================================
186 ; PRUEBA DE INSTRUCCION SUB INDIRECTA.
187 ;=============================================================
188 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
189 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
190 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
191 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
192 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
193 ;L5 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
194 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
195 ;L7 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
196 ;L8 SUB (@0010) ; SUB INDIRECTO.
197 ;L9 LDA @2211 ; LDA ABSOLUTO.
198 ;HLT ; INSTRUCCION DE DETENCION.
199 ;=============================================================
200 
201 ;=============================================================
202 ; PRUEBA DE INSTRUCCION AND INDIRECTA.
203 ;=============================================================
204 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
205 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
206 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
207 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
208 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
209 ;L5 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
210 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
211 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
212 ;L8 AND (@0010) ; AND INDIRECTO.
213 ;L9 LDA @2211 ; LDA ABSOLUTO.
214 ;HLT ; INSTRUCCION DE DETENCION.
215 ;=============================================================
216 
217 ;=============================================================
218 ; PRUEBA DE INSTRUCCION ORA INDIRECTA.
219 ;=============================================================
220 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
221 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
222 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
223 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
224 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
225 ;L5 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
226 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
227 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
228 ;L8 ORA (@0010) ; ORA INDIRECTO.
229 ;L9 LDA @2211 ; LDA ABSOLUTO.
230 ;HLT ; INSTRUCCION DE DETENCION.
231 ;=============================================================
232 ;***********************************************************************************************************************
233 
234 ;***********************************************************************************************************************
235 ; INSTRUCCIONES DE ACUMULADOR
236 ;***********************************************************************************************************************
237 
238 ;=============================================================
239 ; PRUEBA DE INSTRUCCION CLA DE ACUMULADOR.
240 ;=============================================================
241 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
242 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
243 ;L2 CLA ; CLA DE ACUMULADOR, LIMPIA EL ACUMULADOR.
244 ;HLT ; INSTRUCCION DE DETENCION.
245 ;=============================================================
246 
247 ;=============================================================
248 ; PRUEBA DE INSTRUCCION CPA DE ACUMULADOR.
249 ;=============================================================
250 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
251 ;L1 LDA #%111000 ; LDA CON ARGUMENTO DECIMAL.
252 ;L2 CPA ; CPA DE ACUMULADOR, COMPLEMENTA EL ACUMULADOR.
253 ;HLT ; INSTRUCCION DE DETENCION.
254 ;=============================================================
255 
256 ;=============================================================
257 ; PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
258 ;=============================================================
259 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
260 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
261 ;L2 INA ; INA DE ACUMULADOR, INCREMENTA EL ACUMULADOR EN 1.
262 ;HLT ; INSTRUCCION DE DETENCION.
263 ;=============================================================
264 
265 ;=============================================================
266 ; PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
267 ;=============================================================
268 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
269 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
270 ;L2 DCA ; DCA DE ACUMULADOR, DECREMENTO EL ACUMULADOR EN 1.
271 ;HLT ; INSTRUCCION DE DETENCION.
272 ;=============================================================
273 
274 ;=============================================================
275 ; PRUEBA DE INSTRUCCION ROL DE ACUMULADOR.
276 ;=============================================================
277 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
278 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
279 ;L2 ROL ; ROL DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA IZQ.
280 ;HLT ; INSTRUCCION DE DETENCION.
281 ;=============================================================
282 
283 ;=============================================================
284 ; PRUEBA DE INSTRUCCION ROR DE ACUMULADOR.
285 ;=============================================================
286 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
287 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
288 ;L2 ROR ; ROR DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA DER.
289 ;HLT ; INSTRUCCION DE DETENCION.
290 ;=============================================================
291 ;***********************************************************************************************************************
292 
293 ;***********************************************************************************************************************
294 ; INSTRUCCIONES DE IMPLICITAS
295 ;***********************************************************************************************************************
296 
297 ;=============================================================
298 ; PRUEBA DE INSTRUCCION SEC IMPLICITA.
299 ;=============================================================
300 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
301 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
302 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
303 ;HLT ; INSTRUCCION DE DETENCION.
304 ;=============================================================
305 
306 ;=============================================================
307 ; PRUEBA DE INSTRUCCION CLC IMPLICITA.
308 ;=============================================================
309 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
310 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
311 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
312 ;L3 CLC ; CLC IMPLICITO, PONE EN BAJO LA BANDERA DE ACARREO.
313 ;HLT ; INSTRUCCION DE DETENCION.
314 ;=============================================================
315 
316 ;=============================================================
317 ; PRUEBA DE INSTRUCCION SEI IMPLICITA.
318 ;=============================================================
319 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
320 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
321 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
322 ;HLT ; INSTRUCCION DE DETENCION.
323 ;=============================================================
324 
325 ;=============================================================
326 ; PRUEBA DE INSTRUCCION CLI IMPLICITA.
327 ;=============================================================
328 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
329 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
330 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
331 ;L3 CLI ; CLI IMPLICITO, PONE EN BAJO LA BANDERA DE INTERRUP.
332 ;HLT ; INSTRUCCION DE DETENCION.
333 ;=============================================================
334 ;***********************************************************************************************************************
335 
336 ;***********************************************************************************************************************
337 ; INSTRUCCIONES DE RELATIVAS
338 ;***********************************************************************************************************************
339 ; PRUEBA DE BEQ
340 ;L SEC
341 ;L0 CLC
342 ;L1 LDA #0
343 ;L6 BEQ L1
344 ;L4 INA
345 ;L5 LDA #1
346 
347 ;=============================================================
348 ; PRUEBA DE INSTRUCCION BEQ RELATIVA.
349 ;=============================================================
350 * = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
351 L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
352 L2 BEQ L1 ; SALTA A L1 SI EL ACUMULADOR ES 0.
353 HLT ; INSTRUCCION DE DETENCION.
354 ;=============================================================
355 
356 
357 
358 
359 
360 
361 
362 
363 
364 
365 
366 
367 
368 
369 
370 
371 
372 
373 ;DBWRD @0000
374 ;WRD @0000
375 ;LALA1 = 66
376 ;UPPER = 55
377 ;LALA2 = 7
378 ;BIN = %001000001000
379 ;OCT = @12
380 ;HEX = $FFFF
381 ;DEC = 10
382 ;LALA2 = @0007
383 ;LALA3 = 11
384 ;LALA4 = %111
385 ;DBWRD @0000
386 ;WRD @0000
387 
388 ;* = @000A DOESNT WORK
389 ;* = * + 1
390 ;PUNT1 = *
391 ;PUNT2 = * + 20
392 ;* = $3FFF
393 ;* = @0010
394 ;DBWRD = $000A
395 ;DBWRD $000A
396 ;WRD $000A
397 
398 
399 ;DBWRD @0100
400 ;WRD @0000
401 
402 ;DBWRD 0
403 ;WRD 0
404 
405 ;DBWRD %100000000000
406 ;WRD %100000
407 
408 ;* = 4096
409 ;* = %000000000000
410 
411 ; TODAS LAS PRUEBAS HAN SIDO CORRECTAMENTE ENSAMBLADAS
412 
413 ; PRUEBA PC DIFERENTE DE 0
414 
415 ;PRUEBA DE NOP
416 ;NOP
417 ;L0 LDA #1
418 ;INP @01
419 ;OUT @01
420 ;INP @01
421 
422 ;LDA @01
423 ;STA @01
424 
425 ;PRUEBA DE STA IND
426 ;L0 LDA #@01
427 
428 ;L1 STA @0300
429 ;L2 LDA #@01
430 ;L3 STA @0301
431 ;L7 LDA #7
432 ;L4 STA (@0300)
433 ;L5 INA
434 ;L6 LDA @0101
435 ;HLT
436 
437 
438 ;PRUEBA AND ABS
439 ;L0 LDA #%000111
440 ;L1 STA @0300
441 ;L2 LDA #%111000
442 ;L3 ORA @0300
443 
444 ;PRUEBA SUB ABS
445 ;L0 LDA #1
446 ;L1 STA @0300
447 ;L2 INA
448 ;L3 SUB @0300
449 
450 ;PRUEBA ADD ABS
451 ;L0 LDA #1
452 ;L1 STA @0300
453 ;L2 INA
454 ;L3 ADD @0300
455 
456 ;PRUEBA DE STA ABS
457 ;L0 LDA #1
458 ;L1 STA @0300
459 ;L2 INA
460 ;L3 LDA @0300
461 
462 ;L0 LDA #01
463 ;L1 ADD @0001
464 
465 ;L0 LDA #63
466 ;L1 ORA #%101001
467 
468 ; PRUEBA DE BCC
469 ;L0 LDA #0
470 ;L1 INA
471 ;L2 BCC L0
472 ;L3 LDA #1
473 
474 
475 ; PRUEBA DE BNE
476 ;L SEC
477 ;L0 CLC
478 ;L1 LDA #0
479 ;L2 INA
480 ;L6 BNE L2
481 ;L4 INA
482 ;L5 LDA #1
483 
484 ; PRUEBA DE BEQ
485 ;L SEC
486 ;L0 CLC
487 ;L1 LDA #0
488 ;L6 BEQ L1
489 ;L4 INA
490 ;L5 LDA #1
491 
492 ;PRUEBA DE LDA INMEDIATA
493 ;L1 LDA #1
494 ;L2 LDA #2
495 ;L3 LDA #3
496 ;L4 LDA #4
497 ;L5 LDA #5
498 
499 ;PRUEBA DE SUB Y ADD INMEDIATAS
500 ;L0 LDA #0
501 ;L1 LDA #63
502 ;L2 SUB #62
503 ;L3 SUB #1
504 ;L4 ADD #1
505 ;L5 ADD #1
506 
507 ;K3 BNE K3
508 ;K5 BNE K3
509 ;K1 SEC
510 ;K2 SEC
511 ;BNE K1
512 ;K3 BNE K3
513 ;K5 BNE K3
514 ;L1 LDA (@0001)
515 ;BNE L1
516 ;L2 LDA @0002
517 ;L3 LDA @0002
518 ;BNE L1
519 ;L1 LDA @0001
520 
521 ;LDA LALA1
522 ;LDA @0001
523 ;L1 LDA BIN
524 ;LDA OCT
525 ;LDA DEC
526 ;LDA HEX
527 ;L1 LDA HEX
528 ;L2 LDA #HEX
529 ;LDA #HEX
530 ;BNE L3
531 ;BMI L1
532 ;LOOP1 BNE L1
533 ;L4 BMI L2
534 ;LDA (BIN)
535 ;LDA (OCT)
536 ;LDA (DEC)
537 ;LDA (HEX)
538 
539 ;LDA %1010
540 ;LDA @12
541 ;LDA 10
542 ;LDA $0A
543 ;LDA (%1010)
544 ;LDA (@12)
545 ;LDA (10)
546 ;LDA ($0A)
547 
548 ;LDA #%1010
549 ;LDA #@12
550 ;LDA #10
551 ;LDA $0A
552 ;LDA #BIN
553 ;LDA #OCT
554 ;LDA #DEC
555 ;LDA #HEX
556 
557 ;IMP SEC
558 ;ACU CLA
559 ;CTR TPA
560 
561 ;INP %1010
562 ;INP @12
563 ;INP 10
564 ;INP $0A
565 ;INP BIN
566 ;INP OCT
567 ;INP DEC
568 ;INP HEX
569 
570 
571 ;LDA %111
572 ;L2 LDA (LALA1)
573 ;L3 LDA (%01)
574 ;LDA (@0001)
575 ;BNE L2
576 ;BMI L3
577 ;LABEL BNE LALA2
578 ;LALA3 BNE LABEL
579 ;BNE LABEL
580 ;BMI LALA2
581 ;LOOP1 CPA
582 ;INA
583 ;ROR
584 ;NOP
585 ;INP LALA1
586 ;L1 INP LALA2
587 ;LABEL LDA (LALA1)
588 ;BNE LABEL
589 ;LABEL XXX LALA1
590 ;LABEL LDA @0001
591 ;LAB1 LDA PERRO
592 ;BNE LABEL
593 ;L1 BNE LALA
594 ;LALA LDA #01
595 ;LDA #$A
596 ;LDA #LABEL
597 ;LABEL LDA #@07
598 ;LABEL1 LDA #@07
599 ;BNE LABEL1
600 ;INP $FF
601 ;OUT %100
602 ;HLT
603 
604 
605 ;LDA #0
606 ;HLT
607 ;HLT
608 ;HLT
609 ;LDA #7
610 ;LDA #7
611 ;LDA #7
612 ;HLT
613 
614 ;BEQ JUMP1
615 ;LDA (@1000)
616 ;SEC
617 ;CLA
618 ;TPA
619 ;INP @77
620 
