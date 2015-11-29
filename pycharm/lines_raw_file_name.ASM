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
339 
340 ;=============================================================
341 ; PRUEBA DE INSTRUCCION BEQ RELATIVA.
342 ;=============================================================
343 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
344 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
345 ;L2 BEQ L1 ; SALTA A L1 SI EL ACUMULADOR ES 0.
346 ;HLT ; INSTRUCCION DE DETENCION.
347 ;=============================================================
348 
349 ;=============================================================
350 ; PRUEBA DE INSTRUCCION BNE RELATIVA.
351 ;=============================================================
352 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
353 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
354 ;L2 BNE L1 ; SALTA A L1 SI EL ACUMULADOR ES DISTINTO DE 0.
355 ;HLT ; INSTRUCCION DE DETENCION.
356 ;=============================================================
357 
358 ;=============================================================
359 ; PRUEBA DE INSTRUCCION BCC RELATIVA.
360 ;=============================================================
361 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
362 ;L1 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
363 ;L2 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
364 ;L3 BCC L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 0.
365 ;HLT ; INSTRUCCION DE DETENCION.
366 ;=============================================================
367 
368 ;=============================================================
369 ; PRUEBA DE INSTRUCCION BCS RELATIVA.
370 ;=============================================================
371 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
372 ;L1 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
373 ;L2 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
374 ;L3 BCS L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 1.
375 ;HLT ; INSTRUCCION DE DETENCION.
376 ;=============================================================
377 
378 ;=============================================================
379 ; PRUEBA DE INSTRUCCION BPL RELATIVA.
380 ;=============================================================
381 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
382 ;L1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
383 ;L2 BPL L1 ; SALTA A L1 SI EL ACUMULADOR ES POSITIVO.
384 ;HLT ; INSTRUCCION DE DETENCION.
385 ;=============================================================
386 
387 ;=============================================================
388 ; PRUEBA DE INSTRUCCION BMI RELATIVA.
389 ;=============================================================
390 * = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
391 L1 LDA #%100000 ; LDA CON ARGUMENTO BINARIO NEGATIVO.
392 L2 BMI L1 ; SALTA A L1 SI EL ACUMULADOR ES NEGATIVO.
393 HLT ; INSTRUCCION DE DETENCION.
394 ;=============================================================
395 
396 
397 
398 
399 
400 
401 
402 
403 
404 
405 
406 
407 
408 
409 ;DBWRD @0000
410 ;WRD @0000
411 ;LALA1 = 66
412 ;UPPER = 55
413 ;LALA2 = 7
414 ;BIN = %001000001000
415 ;OCT = @12
416 ;HEX = $FFFF
417 ;DEC = 10
418 ;LALA2 = @0007
419 ;LALA3 = 11
420 ;LALA4 = %111
421 ;DBWRD @0000
422 ;WRD @0000
423 
424 ;* = @000A DOESNT WORK
425 ;* = * + 1
426 ;PUNT1 = *
427 ;PUNT2 = * + 20
428 ;* = $3FFF
429 ;* = @0010
430 ;DBWRD = $000A
431 ;DBWRD $000A
432 ;WRD $000A
433 
434 
435 ;DBWRD @0100
436 ;WRD @0000
437 
438 ;DBWRD 0
439 ;WRD 0
440 
441 ;DBWRD %100000000000
442 ;WRD %100000
443 
444 ;* = 4096
445 ;* = %000000000000
446 
447 ; TODAS LAS PRUEBAS HAN SIDO CORRECTAMENTE ENSAMBLADAS
448 
449 ; PRUEBA PC DIFERENTE DE 0
450 
451 ;PRUEBA DE NOP
452 ;NOP
453 ;L0 LDA #1
454 ;INP @01
455 ;OUT @01
456 ;INP @01
457 
458 ;LDA @01
459 ;STA @01
460 
461 ;PRUEBA DE STA IND
462 ;L0 LDA #@01
463 
464 ;L1 STA @0300
465 ;L2 LDA #@01
466 ;L3 STA @0301
467 ;L7 LDA #7
468 ;L4 STA (@0300)
469 ;L5 INA
470 ;L6 LDA @0101
471 ;HLT
472 
473 
474 ;PRUEBA AND ABS
475 ;L0 LDA #%000111
476 ;L1 STA @0300
477 ;L2 LDA #%111000
478 ;L3 ORA @0300
479 
480 ;PRUEBA SUB ABS
481 ;L0 LDA #1
482 ;L1 STA @0300
483 ;L2 INA
484 ;L3 SUB @0300
485 
486 ;PRUEBA ADD ABS
487 ;L0 LDA #1
488 ;L1 STA @0300
489 ;L2 INA
490 ;L3 ADD @0300
491 
492 ;PRUEBA DE STA ABS
493 ;L0 LDA #1
494 ;L1 STA @0300
495 ;L2 INA
496 ;L3 LDA @0300
497 
498 ;L0 LDA #01
499 ;L1 ADD @0001
500 
501 ;L0 LDA #63
502 ;L1 ORA #%101001
503 
504 ; PRUEBA DE BCC
505 ;L0 LDA #0
506 ;L1 INA
507 ;L2 BCC L0
508 ;L3 LDA #1
509 
510 
511 ; PRUEBA DE BNE
512 ;L SEC
513 ;L0 CLC
514 ;L1 LDA #0
515 ;L2 INA
516 ;L6 BNE L2
517 ;L4 INA
518 ;L5 LDA #1
519 
520 ; PRUEBA DE BEQ
521 ;L SEC
522 ;L0 CLC
523 ;L1 LDA #0
524 ;L6 BEQ L1
525 ;L4 INA
526 ;L5 LDA #1
527 
528 ;PRUEBA DE LDA INMEDIATA
529 ;L1 LDA #1
530 ;L2 LDA #2
531 ;L3 LDA #3
532 ;L4 LDA #4
533 ;L5 LDA #5
534 
535 ;PRUEBA DE SUB Y ADD INMEDIATAS
536 ;L0 LDA #0
537 ;L1 LDA #63
538 ;L2 SUB #62
539 ;L3 SUB #1
540 ;L4 ADD #1
541 ;L5 ADD #1
542 
543 ;K3 BNE K3
544 ;K5 BNE K3
545 ;K1 SEC
546 ;K2 SEC
547 ;BNE K1
548 ;K3 BNE K3
549 ;K5 BNE K3
550 ;L1 LDA (@0001)
551 ;BNE L1
552 ;L2 LDA @0002
553 ;L3 LDA @0002
554 ;BNE L1
555 ;L1 LDA @0001
556 
557 ;LDA LALA1
558 ;LDA @0001
559 ;L1 LDA BIN
560 ;LDA OCT
561 ;LDA DEC
562 ;LDA HEX
563 ;L1 LDA HEX
564 ;L2 LDA #HEX
565 ;LDA #HEX
566 ;BNE L3
567 ;BMI L1
568 ;LOOP1 BNE L1
569 ;L4 BMI L2
570 ;LDA (BIN)
571 ;LDA (OCT)
572 ;LDA (DEC)
573 ;LDA (HEX)
574 
575 ;LDA %1010
576 ;LDA @12
577 ;LDA 10
578 ;LDA $0A
579 ;LDA (%1010)
580 ;LDA (@12)
581 ;LDA (10)
582 ;LDA ($0A)
583 
584 ;LDA #%1010
585 ;LDA #@12
586 ;LDA #10
587 ;LDA $0A
588 ;LDA #BIN
589 ;LDA #OCT
590 ;LDA #DEC
591 ;LDA #HEX
592 
593 ;IMP SEC
594 ;ACU CLA
595 ;CTR TPA
596 
597 ;INP %1010
598 ;INP @12
599 ;INP 10
600 ;INP $0A
601 ;INP BIN
602 ;INP OCT
603 ;INP DEC
604 ;INP HEX
605 
606 
607 ;LDA %111
608 ;L2 LDA (LALA1)
609 ;L3 LDA (%01)
610 ;LDA (@0001)
611 ;BNE L2
612 ;BMI L3
613 ;LABEL BNE LALA2
614 ;LALA3 BNE LABEL
615 ;BNE LABEL
616 ;BMI LALA2
617 ;LOOP1 CPA
618 ;INA
619 ;ROR
620 ;NOP
621 ;INP LALA1
622 ;L1 INP LALA2
623 ;LABEL LDA (LALA1)
624 ;BNE LABEL
625 ;LABEL XXX LALA1
626 ;LABEL LDA @0001
627 ;LAB1 LDA PERRO
628 ;BNE LABEL
629 ;L1 BNE LALA
630 ;LALA LDA #01
631 ;LDA #$A
632 ;LDA #LABEL
633 ;LABEL LDA #@07
634 ;LABEL1 LDA #@07
635 ;BNE LABEL1
636 ;INP $FF
637 ;OUT %100
638 ;HLT
639 
640 
641 ;LDA #0
642 ;HLT
643 ;HLT
644 ;HLT
645 ;LDA #7
646 ;LDA #7
647 ;LDA #7
648 ;HLT
649 
650 ;BEQ JUMP1
651 ;LDA (@1000)
652 ;SEC
653 ;CLA
654 ;TPA
655 ;INP @77
656 
