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
390 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
391 ;L1 LDA #%100000 ; LDA CON ARGUMENTO BINARIO NEGATIVO.
392 ;L2 BMI L1 ; SALTA A L1 SI EL ACUMULADOR ES NEGATIVO.
393 ;HLT ; INSTRUCCION DE DETENCION.
394 ;=============================================================
395 
396 ;=============================================================
397 ; PRUEBA DE INSTRUCCION BVC RELATIVA.
398 ;=============================================================
399 * = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
400 L1 LDA #1 ; LDA CON ARGUMENTO BINARIO.
401 L2 ADD #1 ; SE AGREGA %001010 AL ACUMULADOR.
402 L3 BVC L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 0.
403 HLT ; INSTRUCCION DE DETENCION.
404 ;=============================================================
405 
406 ;=============================================================
407 ; PRUEBA DE INSTRUCCION BVS RELATIVA.
408 ;=============================================================
409 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
410 ;L1 LDA #%010110 ; LDA CON ARGUMENTO BINARIO.
411 ;L2 ADD #%001010 ; SE AGREGA %001010 AL ACUMULADOR.
412 ;L3 BVS L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 1.
413 ;HLT ; INSTRUCCION DE DETENCION.
414 ;=============================================================
415 
416 
417 
418 
419 
420 
421 
422 
423 
424 
425 
426 ;DBWRD @0000
427 ;WRD @0000
428 ;LALA1 = 66
429 ;UPPER = 55
430 ;LALA2 = 7
431 ;BIN = %001000001000
432 ;OCT = @12
433 ;HEX = $FFFF
434 ;DEC = 10
435 ;LALA2 = @0007
436 ;LALA3 = 11
437 ;LALA4 = %111
438 ;DBWRD @0000
439 ;WRD @0000
440 
441 ;* = @000A DOESNT WORK
442 ;* = * + 1
443 ;PUNT1 = *
444 ;PUNT2 = * + 20
445 ;* = $3FFF
446 ;* = @0010
447 ;DBWRD = $000A
448 ;DBWRD $000A
449 ;WRD $000A
450 
451 
452 ;DBWRD @0100
453 ;WRD @0000
454 
455 ;DBWRD 0
456 ;WRD 0
457 
458 ;DBWRD %100000000000
459 ;WRD %100000
460 
461 ;* = 4096
462 ;* = %000000000000
463 
464 ; TODAS LAS PRUEBAS HAN SIDO CORRECTAMENTE ENSAMBLADAS
465 
466 ; PRUEBA PC DIFERENTE DE 0
467 
468 ;PRUEBA DE NOP
469 ;NOP
470 ;L0 LDA #1
471 ;INP @01
472 ;OUT @01
473 ;INP @01
474 
475 ;LDA @01
476 ;STA @01
477 
478 ;PRUEBA DE STA IND
479 ;L0 LDA #@01
480 
481 ;L1 STA @0300
482 ;L2 LDA #@01
483 ;L3 STA @0301
484 ;L7 LDA #7
485 ;L4 STA (@0300)
486 ;L5 INA
487 ;L6 LDA @0101
488 ;HLT
489 
490 
491 ;PRUEBA AND ABS
492 ;L0 LDA #%000111
493 ;L1 STA @0300
494 ;L2 LDA #%111000
495 ;L3 ORA @0300
496 
497 ;PRUEBA SUB ABS
498 ;L0 LDA #1
499 ;L1 STA @0300
500 ;L2 INA
501 ;L3 SUB @0300
502 
503 ;PRUEBA ADD ABS
504 ;L0 LDA #1
505 ;L1 STA @0300
506 ;L2 INA
507 ;L3 ADD @0300
508 
509 ;PRUEBA DE STA ABS
510 ;L0 LDA #1
511 ;L1 STA @0300
512 ;L2 INA
513 ;L3 LDA @0300
514 
515 ;L0 LDA #01
516 ;L1 ADD @0001
517 
518 ;L0 LDA #63
519 ;L1 ORA #%101001
520 
521 ; PRUEBA DE BCC
522 ;L0 LDA #0
523 ;L1 INA
524 ;L2 BCC L0
525 ;L3 LDA #1
526 
527 
528 ; PRUEBA DE BNE
529 ;L SEC
530 ;L0 CLC
531 ;L1 LDA #0
532 ;L2 INA
533 ;L6 BNE L2
534 ;L4 INA
535 ;L5 LDA #1
536 
537 ; PRUEBA DE BEQ
538 ;L SEC
539 ;L0 CLC
540 ;L1 LDA #0
541 ;L6 BEQ L1
542 ;L4 INA
543 ;L5 LDA #1
544 
545 ;PRUEBA DE LDA INMEDIATA
546 ;L1 LDA #1
547 ;L2 LDA #2
548 ;L3 LDA #3
549 ;L4 LDA #4
550 ;L5 LDA #5
551 
552 ;PRUEBA DE SUB Y ADD INMEDIATAS
553 ;L0 LDA #0
554 ;L1 LDA #63
555 ;L2 SUB #62
556 ;L3 SUB #1
557 ;L4 ADD #1
558 ;L5 ADD #1
559 
560 ;K3 BNE K3
561 ;K5 BNE K3
562 ;K1 SEC
563 ;K2 SEC
564 ;BNE K1
565 ;K3 BNE K3
566 ;K5 BNE K3
567 ;L1 LDA (@0001)
568 ;BNE L1
569 ;L2 LDA @0002
570 ;L3 LDA @0002
571 ;BNE L1
572 ;L1 LDA @0001
573 
574 ;LDA LALA1
575 ;LDA @0001
576 ;L1 LDA BIN
577 ;LDA OCT
578 ;LDA DEC
579 ;LDA HEX
580 ;L1 LDA HEX
581 ;L2 LDA #HEX
582 ;LDA #HEX
583 ;BNE L3
584 ;BMI L1
585 ;LOOP1 BNE L1
586 ;L4 BMI L2
587 ;LDA (BIN)
588 ;LDA (OCT)
589 ;LDA (DEC)
590 ;LDA (HEX)
591 
592 ;LDA %1010
593 ;LDA @12
594 ;LDA 10
595 ;LDA $0A
596 ;LDA (%1010)
597 ;LDA (@12)
598 ;LDA (10)
599 ;LDA ($0A)
600 
601 ;LDA #%1010
602 ;LDA #@12
603 ;LDA #10
604 ;LDA $0A
605 ;LDA #BIN
606 ;LDA #OCT
607 ;LDA #DEC
608 ;LDA #HEX
609 
610 ;IMP SEC
611 ;ACU CLA
612 ;CTR TPA
613 
614 ;INP %1010
615 ;INP @12
616 ;INP 10
617 ;INP $0A
618 ;INP BIN
619 ;INP OCT
620 ;INP DEC
621 ;INP HEX
622 
623 
624 ;LDA %111
625 ;L2 LDA (LALA1)
626 ;L3 LDA (%01)
627 ;LDA (@0001)
628 ;BNE L2
629 ;BMI L3
630 ;LABEL BNE LALA2
631 ;LALA3 BNE LABEL
632 ;BNE LABEL
633 ;BMI LALA2
634 ;LOOP1 CPA
635 ;INA
636 ;ROR
637 ;NOP
638 ;INP LALA1
639 ;L1 INP LALA2
640 ;LABEL LDA (LALA1)
641 ;BNE LABEL
642 ;LABEL XXX LALA1
643 ;LABEL LDA @0001
644 ;LAB1 LDA PERRO
645 ;BNE LABEL
646 ;L1 BNE LALA
647 ;LALA LDA #01
648 ;LDA #$A
649 ;LDA #LABEL
650 ;LABEL LDA #@07
651 ;LABEL1 LDA #@07
652 ;BNE LABEL1
653 ;INP $FF
654 ;OUT %100
655 ;HLT
656 
657 
658 ;LDA #0
659 ;HLT
660 ;HLT
661 ;HLT
662 ;LDA #7
663 ;LDA #7
664 ;LDA #7
665 ;HLT
666 
667 ;BEQ JUMP1
668 ;LDA (@1000)
669 ;SEC
670 ;CLA
671 ;TPA
672 ;INP @77
673 
