1 
2 ;***********************************************************************************************************************
3 ; INSTRUCCIONES INMEDIATAS
4 ;***********************************************************************************************************************
5 
6 ;=============================================================
7 ; PRUEBA DE INSTRUCCION LDA INMEDIATA.
8 ;=============================================================
9 * = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
10 LABEL = @0010
11 BIN0 LDA #LABEL+1
12 BIN LDA LABEL+2
13 BIN2 LDA (LABEL+10000000)
14 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
15 ;OCT LDA #@02 ; LDA CON ARGUMENTO OCTAL.
16 ;HEX LDA #$03 ; LDA CON ARGUMENTO HEXADECIMAL.
17 ;DEC LDA #4 ; LDA CON ARGUMENTO DECIMAL.
18 ;1234567 INA ;
19 HLT ; INSTRUCCION DE DETENCION.
20 ;=============================================================
21 
22 ;=============================================================
23 ; PRUEBA DE INSTRUCCION ADD INMEDIATA.
24 ;=============================================================
25 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
26 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
27 ;BIN ADD #%000010 ; ADD CON ARGUMENTO BINARIO.
28 ;OCT ADD #@02 ; ADD CON ARGUMENTO OCTACL.
29 ;DEC ADD #2 ; ADD CON ARGUMENTO DECIMAL.
30 ;HEX ADD #$02 ; ADD CON ARGUMENTO HEXADECIMAL.
31 ;HLT ; INSTRUCCION DE DETENCION.
32 ;=============================================================
33 
34 ;=============================================================
35 ; PRUEBA DE INSTRUCCION SUB INMEDIATA.
36 ;=============================================================
37 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
38 ;L1 LDA #10 ; LDA CON ARGUMENTO DECIMAL.
39 ;BIN SUB #%000010 ; SUB CON ARGUMENTO BINARIO.
40 ;OCT SUB #@02 ; SUB CON ARGUMENTO OCTACL.
41 ;DEC SUB #2 ; SUB CON ARGUMENTO DECIMAL.
42 ;HEX SUB #$02 ; SUB CON ARGUMENTO HEXADECIMAL.
43 ;HLT ; INSTRUCCION DE DETENCION.
44 ;=============================================================
45 
46 ;=============================================================
47 ; PRUEBA DE INSTRUCCION AND INMEDIATA.
48 ;=============================================================
49 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
50 ;L1 LDA #%111111 ; LDA CON ARGUMENTO DECIMAL.
51 ;BIN AND #%000111 ; AND CON ARGUMENTO BINARIO.
52 ;OCT AND #@07 ; AND CON ARGUMENTO OCTACL.
53 ;DEC AND #3 ; AND CON ARGUMENTO DECIMAL.
54 ;HEX AND #$01 ; AND CON ARGUMENTO HEXADECIMAL.
55 ;HLT ; INSTRUCCION DE DETENCION.
56 ;=============================================================
57 
58 ;=============================================================
59 ; PRUEBA DE INSTRUCCION ORA INMEDIATA.
60 ;=============================================================
61 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
62 ;L1 LDA #%101000 ; LDA CON ARGUMENTO DECIMAL.
63 ;BIN ORA #%000101 ; ORA CON ARGUMENTO BINARIO.
64 ;OCT ORA #@20 ; ORA CON ARGUMENTO OCTACL.
65 ;DEC ORA #2 ; ORA CON ARGUMENTO DECIMAL.
66 ;HEX ORA #$00 ; ORA CON ARGUMENTO HEXADECIMAL.
67 ;HLT ; INSTRUCCION DE DETENCION.
68 ;=============================================================
69 
70 ;***********************************************************************************************************************
71 
72 
73 ;***********************************************************************************************************************
74 ; INSTRUCCIONES ABSOLUTAS
75 ;***********************************************************************************************************************
76 
77 ;=============================================================
78 ; PRUEBA DE INSTRUCCION LDA ABSOLUTA.
79 ;=============================================================
80 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
81 ;L1 LDA @01 ; LDA ABSOLUTO.
82 ;HLT ; INSTRUCCION DE DETENCION.
83 ;=============================================================
84 
85 ;=============================================================
86 ; PRUEBA DE INSTRUCCION STA ABSOLUTA.
87 ;=============================================================
88 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
89 ;L1 LDA #7 ; LDA INMEDIATO.
90 ;L2 STA @0020 ; STA ABSOLUTO.
91 ;L3 ADD #1 ; LDA INMEDIATO.
92 ;L4 LDA @0020 ; LDA ABSOLUTO.
93 ;HLT ; INSTRUCCION DE DETENCION.
94 ;=============================================================
95 
96 ;=============================================================
97 ; PRUEBA DE INSTRUCCION ADD ABSOLUTA.
98 ;=============================================================
99 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
100 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
101 ;L2 STA @0020 ; STA ABSOLUTO.
102 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
103 ;L4 ADD @0020 ; ADD ABSOLUTA.
104 ;HLT ; INSTRUCCION DE DETENCION.
105 ;=============================================================
106 
107 ;=============================================================
108 ; PRUEBA DE INSTRUCCION SUB ABSOLUTA.
109 ;=============================================================
110 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
111 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
112 ;L2 STA @0020 ; STA ABSOLUTO.
113 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
114 ;L4 SUB @0020 ; SUB ABSOLUTA.
115 ;HLT ; INSTRUCCION DE DETENCION.
116 ;=============================================================
117 
118 ;=============================================================
119 ; PRUEBA DE INSTRUCCION AND ABSOLUTA.
120 ;=============================================================
121 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
122 ;L1 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
123 ;L2 STA @0020 ; STA ABSOLUTO.
124 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
125 ;L4 AND @0020 ; AND ABSOLUTAL.
126 ;HLT ; INSTRUCCION DE DETENCION.
127 ;=============================================================
128 
129 ;=============================================================
130 ; PRUEBA DE INSTRUCCION ORA ABSOLUTA.
131 ;=============================================================
132 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
133 ;L1 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
134 ;L2 STA @0020 ; STA ABSOLUTO.
135 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
136 ;L4 ORA @0020 ; ORA ABSOLUTA.
137 ;HLT ; INSTRUCCION DE DETENCION.
138 ;=============================================================
139 
140 ;***********************************************************************************************************************
141 
142 ;***********************************************************************************************************************
143 ; INSTRUCCIONES INDIRECTAS
144 ;***********************************************************************************************************************
145 ;=============================================================
146 ; PRUEBA DE INSTRUCCION LDA INDIRECTA.
147 ;=============================================================
148 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
149 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
150 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
151 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
152 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
153 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
154 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @0102.
155 ;L7 LDA (@0010) ; LDA INDIRECTO.
156 ;HLT ; INSTRUCCION DE DETENCION.
157 ;=============================================================
158 
159 ;=============================================================
160 ; PRUEBA DE INSTRUCCION STA INDIRECTA.
161 ;=============================================================
162 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
163 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
164 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
165 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
166 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
167 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
168 ;L6 STA (@0010) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
169 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
170 ;L8 LDA @2211 ; LDA ABSOLUTO.
171 ;HLT ; INSTRUCCION DE DETENCION.
172 ;=============================================================
173 
174 ;=============================================================
175 ; PRUEBA DE INSTRUCCION ADD INDIRECTA.
176 ;=============================================================
177 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
178 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
179 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
180 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
181 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
182 ;L5 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
183 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
184 ;L7 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
185 ;L8 ADD (@0010) ; ADD INDIRECTO, ESCRITURA DE 7 A @0102.
186 ;L9 LDA @2211 ; LDA ABSOLUTO.
187 ;HLT ; INSTRUCCION DE DETENCION.
188 ;=============================================================
189 
190 ;=============================================================
191 ; PRUEBA DE INSTRUCCION SUB INDIRECTA.
192 ;=============================================================
193 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
194 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
195 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
196 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
197 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
198 ;L5 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
199 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
200 ;L7 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
201 ;L8 SUB (@0010) ; SUB INDIRECTO.
202 ;L9 LDA @2211 ; LDA ABSOLUTO.
203 ;HLT ; INSTRUCCION DE DETENCION.
204 ;=============================================================
205 
206 ;=============================================================
207 ; PRUEBA DE INSTRUCCION AND INDIRECTA.
208 ;=============================================================
209 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
210 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
211 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
212 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
213 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
214 ;L5 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
215 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
216 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
217 ;L8 AND (@0010) ; AND INDIRECTO.
218 ;L9 LDA @2211 ; LDA ABSOLUTO.
219 ;HLT ; INSTRUCCION DE DETENCION.
220 ;=============================================================
221 
222 ;=============================================================
223 ; PRUEBA DE INSTRUCCION ORA INDIRECTA.
224 ;=============================================================
225 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
226 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
227 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
228 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
229 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
230 ;L5 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
231 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
232 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
233 ;L8 ORA (@0010) ; ORA INDIRECTO.
234 ;L9 LDA @2211 ; LDA ABSOLUTO.
235 ;HLT ; INSTRUCCION DE DETENCION.
236 ;=============================================================
237 ;***********************************************************************************************************************
238 
239 ;***********************************************************************************************************************
240 ; INSTRUCCIONES DE ACUMULADOR
241 ;***********************************************************************************************************************
242 
243 ;=============================================================
244 ; PRUEBA DE INSTRUCCION CLA DE ACUMULADOR.
245 ;=============================================================
246 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
247 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
248 ;L2 CLA ; CLA DE ACUMULADOR, LIMPIA EL ACUMULADOR.
249 ;HLT ; INSTRUCCION DE DETENCION.
250 ;=============================================================
251 
252 ;=============================================================
253 ; PRUEBA DE INSTRUCCION CPA DE ACUMULADOR.
254 ;=============================================================
255 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
256 ;L1 LDA #%111000 ; LDA CON ARGUMENTO DECIMAL.
257 ;L2 CPA ; CPA DE ACUMULADOR, COMPLEMENTA EL ACUMULADOR.
258 ;HLT ; INSTRUCCION DE DETENCION.
259 ;=============================================================
260 
261 ;=============================================================
262 ; PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
263 ;=============================================================
264 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
265 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
266 ;L2 INA ; INA DE ACUMULADOR, INCREMENTA EL ACUMULADOR EN 1.
267 ;HLT ; INSTRUCCION DE DETENCION.
268 ;=============================================================
269 
270 ;=============================================================
271 ; PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
272 ;=============================================================
273 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
274 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
275 ;L2 DCA ; DCA DE ACUMULADOR, DECREMENTO EL ACUMULADOR EN 1.
276 ;HLT ; INSTRUCCION DE DETENCION.
277 ;=============================================================
278 
279 ;=============================================================
280 ; PRUEBA DE INSTRUCCION ROL DE ACUMULADOR.
281 ;=============================================================
282 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
283 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
284 ;L2 ROL ; ROL DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA IZQ.
285 ;HLT ; INSTRUCCION DE DETENCION.
286 ;=============================================================
287 
288 ;=============================================================
289 ; PRUEBA DE INSTRUCCION ROR DE ACUMULADOR.
290 ;=============================================================
291 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
292 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
293 ;L2 ROR ; ROR DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA DER.
294 ;HLT ; INSTRUCCION DE DETENCION.
295 ;=============================================================
296 ;***********************************************************************************************************************
297 
298 ;***********************************************************************************************************************
299 ; INSTRUCCIONES DE IMPLICITAS
300 ;***********************************************************************************************************************
301 
302 ;=============================================================
303 ; PRUEBA DE INSTRUCCION SEC IMPLICITA.
304 ;=============================================================
305 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
306 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
307 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
308 ;HLT ; INSTRUCCION DE DETENCION.
309 ;=============================================================
310 
311 ;=============================================================
312 ; PRUEBA DE INSTRUCCION CLC IMPLICITA.
313 ;=============================================================
314 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
315 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
316 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
317 ;L3 CLC ; CLC IMPLICITO, PONE EN BAJO LA BANDERA DE ACARREO.
318 ;HLT ; INSTRUCCION DE DETENCION.
319 ;=============================================================
320 
321 ;=============================================================
322 ; PRUEBA DE INSTRUCCION SEI IMPLICITA.
323 ;=============================================================
324 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
325 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
326 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
327 ;HLT ; INSTRUCCION DE DETENCION.
328 ;=============================================================
329 
330 ;=============================================================
331 ; PRUEBA DE INSTRUCCION CLI IMPLICITA.
332 ;=============================================================
333 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
334 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
335 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
336 ;L3 CLI ; CLI IMPLICITO, PONE EN BAJO LA BANDERA DE INTERRUP.
337 ;HLT ; INSTRUCCION DE DETENCION.
338 ;=============================================================
339 ;***********************************************************************************************************************
340 
341 ;***********************************************************************************************************************
342 ; INSTRUCCIONES DE RELATIVAS
343 ;***********************************************************************************************************************
344 
345 ;=============================================================
346 ; PRUEBA DE INSTRUCCION BEQ RELATIVA.
347 ;=============================================================
348 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
349 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
350 ;L2 BEQ L1 ; SALTA A L1 SI EL ACUMULADOR ES 0.
351 ;HLT ; INSTRUCCION DE DETENCION.
352 ;=============================================================
353 
354 ;=============================================================
355 ; PRUEBA DE INSTRUCCION BNE RELATIVA.
356 ;=============================================================
357 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
358 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
359 ;L2 BNE L1 ; SALTA A L1 SI EL ACUMULADOR ES DISTINTO DE 0.
360 ;HLT ; INSTRUCCION DE DETENCION.
361 ;=============================================================
362 
363 ;=============================================================
364 ; PRUEBA DE INSTRUCCION BCC RELATIVA.
365 ;=============================================================
366 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
367 ;L1 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
368 ;L2 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
369 ;L3 BCC L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 0.
370 ;HLT ; INSTRUCCION DE DETENCION.
371 ;=============================================================
372 
373 ;=============================================================
374 ; PRUEBA DE INSTRUCCION BCS RELATIVA.
375 ;=============================================================
376 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
377 ;L1 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
378 ;L2 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
379 ;L3 BCS L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 1.
380 ;HLT ; INSTRUCCION DE DETENCION.
381 ;=============================================================
382 
383 ;=============================================================
384 ; PRUEBA DE INSTRUCCION BPL RELATIVA.
385 ;=============================================================
386 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
387 ;L1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
388 ;L2 BPL L1 ; SALTA A L1 SI EL ACUMULADOR ES POSITIVO.
389 ;HLT ; INSTRUCCION DE DETENCION.
390 ;=============================================================
391 
392 ;=============================================================
393 ; PRUEBA DE INSTRUCCION BMI RELATIVA.
394 ;=============================================================
395 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
396 ;L1 LDA #%100000 ; LDA CON ARGUMENTO BINARIO NEGATIVO.
397 ;L2 BMI L1 ; SALTA A L1 SI EL ACUMULADOR ES NEGATIVO.
398 ;HLT ; INSTRUCCION DE DETENCION.
399 ;=============================================================
400 
401 ;=============================================================
402 ; PRUEBA DE INSTRUCCION BVC RELATIVA.
403 ;=============================================================
404 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
405 ;L1 LDA #1 ; LDA CON ARGUMENTO BINARIO.
406 ;L2 ADD #1 ; SE AGREGA %001010 AL ACUMULADOR.
407 ;L3 BVC L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 0.
408 ;HLT ; INSTRUCCION DE DETENCION.
409 ;=============================================================
410 
411 ;=============================================================
412 ; PRUEBA DE INSTRUCCION BVS RELATIVA.
413 ;=============================================================
414 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
415 ;L1 LDA #%010110 ; LDA CON ARGUMENTO BINARIO.
416 ;L2 ADD #%001010 ; SE AGREGA %001010 AL ACUMULADOR.
417 ;L3 BVS L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 1.
418 ;HLT ; INSTRUCCION DE DETENCION.
419 ;=============================================================
420 ;***********************************************************************************************************************
421 
422 ;***********************************************************************************************************************
423 ; INSTRUCCIONES DE CONTROL
424 ;***********************************************************************************************************************
425 
426 ;=============================================================
427 ; PRUEBA DE INSTRUCCION HLT DE CONTROL.
428 ;=============================================================
429 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
430 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
431 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
432 ;=============================================================
433 
434 ;=============================================================
435 ; PRUEBA DE INSTRUCCION NOP DE CONTROL.
436 ;=============================================================
437 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
438 ;NOP ; INSTRUCCION DE CONTROL NOP.
439 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
440 ;=============================================================
441 ;***********************************************************************************************************************
442 
443 ;***********************************************************************************************************************
444 ; INSTRUCCIONES DE ENTRADA SALIDA
445 ;***********************************************************************************************************************
446 
447 ;=============================================================
448 ; PRUEBA DE INSTRUCCION OUT DE CONTROL.
449 ;=============================================================
450 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
451 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
452 ;OUT @01 ; ESCRITURA AL PUERTO DE SALIDA CON DIRECCION @01.
453 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
454 ;=============================================================
455 
456 ;=============================================================
457 ; PRUEBA DE INSTRUCCION INP DE CONTROL.
458 ;=============================================================
459 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
460 ;BIN1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
461 ;INP @00 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
462 ;BIN7 LDA #%000111 ; LDA CON ARGUMENTO BINARIO.
463 ;INP @03 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
464 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
465 ;=============================================================
466 
467 ;=============================================================
468 ; PRUEBA DE INSTRUCCION STA INDIRECTA.
469 ;=============================================================
470 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
471 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
472 ;L2 STA @1000 ; STA ABSOLUTO, ESCRITURA A PB.
473 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
474 ;L4 STA @1001 ; STA ABSOLUTO, ESCRITURA A PA.
475 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
476 ;L6 STA (@1000) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
477 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
478 ;L8 LDA @2211 ; LDA ABSOLUTO.
479 ;HLT ; INSTRUCCION DE DETENCION.
480 ;=============================================================
481 
482 
483 ;DBWRD @0000
484 ;WRD @0000
485 ;LALA1 = 66
486 ;UPPER = 55
487 ;LALA2 = 7
488 ;BIN = %001000001000
489 ;OCT = @12
490 ;HEX = $FFFF
491 ;DEC = 10
492 ;LALA2 = @0007
493 ;LALA3 = 11
494 ;LALA4 = %111
495 ;DBWRD @0000
496 ;WRD @0000
497 
498 ;* = @000A DOESNT WORK
499 ;* = * + 1
500 ;PUNT1 = *
501 ;PUNT2 = * + 20
502 ;* = $3FFF
503 ;* = @0010
504 ;DBWRD = $000A
505 ;DBWRD $000A
506 ;WRD $000A
507 
508 
509 ;DBWRD @0100
510 ;WRD @0000
511 
512 ;DBWRD 0
513 ;WRD 0
514 
515 ;DBWRD %100000000000
516 ;WRD %100000
517 
518 ;* = 4096
519 ;* = %000000000000
520 
521 ; TODAS LAS PRUEBAS HAN SIDO CORRECTAMENTE ENSAMBLADAS
522 
523 ; PRUEBA PC DIFERENTE DE 0
524 
525 ;PRUEBA DE NOP
526 ;NOP
527 ;L0 LDA #1
528 ;INP @01
529 ;OUT @01
530 ;INP @01
531 
532 ;LDA @01
533 ;STA @01
534 
535 ;PRUEBA DE STA IND
536 ;L0 LDA #@01
537 
538 ;L1 STA @0300
539 ;L2 LDA #@01
540 ;L3 STA @0301
541 ;L7 LDA #7
542 ;L4 STA (@0300)
543 ;L5 INA
544 ;L6 LDA @0101
545 ;HLT
546 
547 
548 ;PRUEBA AND ABS
549 ;L0 LDA #%000111
550 ;L1 STA @0300
551 ;L2 LDA #%111000
552 ;L3 ORA @0300
553 
554 ;PRUEBA SUB ABS
555 ;L0 LDA #1
556 ;L1 STA @0300
557 ;L2 INA
558 ;L3 SUB @0300
559 
560 ;PRUEBA ADD ABS
561 ;L0 LDA #1
562 ;L1 STA @0300
563 ;L2 INA
564 ;L3 ADD @0300
565 
566 ;PRUEBA DE STA ABS
567 ;L0 LDA #1
568 ;L1 STA @0300
569 ;L2 INA
570 ;L3 LDA @0300
571 
572 ;L0 LDA #01
573 ;L1 ADD @0001
574 
575 ;L0 LDA #63
576 ;L1 ORA #%101001
577 
578 ; PRUEBA DE BCC
579 ;L0 LDA #0
580 ;L1 INA
581 ;L2 BCC L0
582 ;L3 LDA #1
583 
584 
585 ; PRUEBA DE BNE
586 ;L SEC
587 ;L0 CLC
588 ;L1 LDA #0
589 ;L2 INA
590 ;L6 BNE L2
591 ;L4 INA
592 ;L5 LDA #1
593 
594 ; PRUEBA DE BEQ
595 ;L SEC
596 ;L0 CLC
597 ;L1 LDA #0
598 ;L6 BEQ L1
599 ;L4 INA
600 ;L5 LDA #1
601 
602 ;PRUEBA DE LDA INMEDIATA
603 ;L1 LDA #1
604 ;L2 LDA #2
605 ;L3 LDA #3
606 ;L4 LDA #4
607 ;L5 LDA #5
608 
609 ;PRUEBA DE SUB Y ADD INMEDIATAS
610 ;L0 LDA #0
611 ;L1 LDA #63
612 ;L2 SUB #62
613 ;L3 SUB #1
614 ;L4 ADD #1
615 ;L5 ADD #1
616 
617 ;K3 BNE K3
618 ;K5 BNE K3
619 ;K1 SEC
620 ;K2 SEC
621 ;BNE K1
622 ;K3 BNE K3
623 ;K5 BNE K3
624 ;L1 LDA (@0001)
625 ;BNE L1
626 ;L2 LDA @0002
627 ;L3 LDA @0002
628 ;BNE L1
629 ;L1 LDA @0001
630 
631 ;LDA LALA1
632 ;LDA @0001
633 ;L1 LDA BIN
634 ;LDA OCT
635 ;LDA DEC
636 ;LDA HEX
637 ;L1 LDA HEX
638 ;L2 LDA #HEX
639 ;LDA #HEX
640 ;BNE L3
641 ;BMI L1
642 ;LOOP1 BNE L1
643 ;L4 BMI L2
644 ;LDA (BIN)
645 ;LDA (OCT)
646 ;LDA (DEC)
647 ;LDA (HEX)
648 
649 ;LDA %1010
650 ;LDA @12
651 ;LDA 10
652 ;LDA $0A
653 ;LDA (%1010)
654 ;LDA (@12)
655 ;LDA (10)
656 ;LDA ($0A)
657 
658 ;LDA #%1010
659 ;LDA #@12
660 ;LDA #10
661 ;LDA $0A
662 ;LDA #BIN
663 ;LDA #OCT
664 ;LDA #DEC
665 ;LDA #HEX
666 
667 ;IMP SEC
668 ;ACU CLA
669 ;CTR TPA
670 
671 ;INP %1010
672 ;INP @12
673 ;INP 10
674 ;INP $0A
675 ;INP BIN
676 ;INP OCT
677 ;INP DEC
678 ;INP HEX
679 
680 
681 ;LDA %111
682 ;L2 LDA (LALA1)
683 ;L3 LDA (%01)
684 ;LDA (@0001)
685 ;BNE L2
686 ;BMI L3
687 ;LABEL BNE LALA2
688 ;LALA3 BNE LABEL
689 ;BNE LABEL
690 ;BMI LALA2
691 ;LOOP1 CPA
692 ;INA
693 ;ROR
694 ;NOP
695 ;INP LALA1
696 ;L1 INP LALA2
697 ;LABEL LDA (LALA1)
698 ;BNE LABEL
699 ;LABEL XXX LALA1
700 ;LABEL LDA @0001
701 ;LAB1 LDA PERRO
702 ;BNE LABEL
703 ;L1 BNE LALA
704 ;LALA LDA #01
705 ;LDA #$A
706 ;LDA #LABEL
707 ;LABEL LDA #@07
708 ;LABEL1 LDA #@07
709 ;BNE LABEL1
710 ;INP $FF
711 ;OUT %100
712 ;HLT
713 
714 
715 ;LDA #0
716 ;HLT
717 ;HLT
718 ;HLT
719 ;LDA #7
720 ;LDA #7
721 ;LDA #7
722 ;HLT
723 
724 ;BEQ JUMP1
725 ;LDA (@1000)
726 ;SEC
727 ;CLA
728 ;TPA
729 ;INP @77
730 
