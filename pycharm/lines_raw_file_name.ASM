1 
2 ;***********************************************************************************************************************
3 ; INSTRUCCIONES INMEDIATAS
4 ;***********************************************************************************************************************
5 
6 ;=============================================================
7 ; PRUEBA DE INSTRUCCION LDA INMEDIATA.
8 ;=============================================================
9 * = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
10 ;LDA #1
11 
12 INP @00
13 INP @01
14 INP @02
15 INP @03
16 
17 ;INP @03
18 ;INP @02
19 ;INP @01
20 ;INP @00
21 
22 ;LABEL = @0001
23 ;LABEL = @0002
24 ;BNE LABEL
25 ;BIN0 LDA #LABEL+1
26 ;BIN LDA LABEL+2
27 ;BIN2 LDA (LABEL+10000000)
28 ;LDA #LABEL+1
29 ;LDA LABEL+1
30 ;LDA (LABEL+1)
31 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
32 ;OCT LDA #@02 ; LDA CON ARGUMENTO OCTAL.
33 ;HEX LDA #$03 ; LDA CON ARGUMENTO HEXADECIMAL.
34 ;DEC LDA #4 ; LDA CON ARGUMENTO DECIMAL.
35 ;1234567 INA ;
36 HLT ; INSTRUCCION DE DETENCION.
37 ;=============================================================
38 
39 ;=============================================================
40 ; PRUEBA DE INSTRUCCION ADD INMEDIATA.
41 ;=============================================================
42 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
43 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
44 ;BIN ADD #%000010 ; ADD CON ARGUMENTO BINARIO.
45 ;OCT ADD #@02 ; ADD CON ARGUMENTO OCTACL.
46 ;DEC ADD #2 ; ADD CON ARGUMENTO DECIMAL.
47 ;HEX ADD #$02 ; ADD CON ARGUMENTO HEXADECIMAL.
48 ;HLT ; INSTRUCCION DE DETENCION.
49 ;=============================================================
50 
51 ;=============================================================
52 ; PRUEBA DE INSTRUCCION SUB INMEDIATA.
53 ;=============================================================
54 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
55 ;L1 LDA #10 ; LDA CON ARGUMENTO DECIMAL.
56 ;BIN SUB #%000010 ; SUB CON ARGUMENTO BINARIO.
57 ;OCT SUB #@02 ; SUB CON ARGUMENTO OCTACL.
58 ;DEC SUB #2 ; SUB CON ARGUMENTO DECIMAL.
59 ;HEX SUB #$02 ; SUB CON ARGUMENTO HEXADECIMAL.
60 ;HLT ; INSTRUCCION DE DETENCION.
61 ;=============================================================
62 
63 ;=============================================================
64 ; PRUEBA DE INSTRUCCION AND INMEDIATA.
65 ;=============================================================
66 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
67 ;L1 LDA #%111111 ; LDA CON ARGUMENTO DECIMAL.
68 ;BIN AND #%000111 ; AND CON ARGUMENTO BINARIO.
69 ;OCT AND #@07 ; AND CON ARGUMENTO OCTACL.
70 ;DEC AND #3 ; AND CON ARGUMENTO DECIMAL.
71 ;HEX AND #$01 ; AND CON ARGUMENTO HEXADECIMAL.
72 ;HLT ; INSTRUCCION DE DETENCION.
73 ;=============================================================
74 
75 ;=============================================================
76 ; PRUEBA DE INSTRUCCION ORA INMEDIATA.
77 ;=============================================================
78 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
79 ;L1 LDA #%101000 ; LDA CON ARGUMENTO DECIMAL.
80 ;BIN ORA #%000101 ; ORA CON ARGUMENTO BINARIO.
81 ;OCT ORA #@20 ; ORA CON ARGUMENTO OCTACL.
82 ;DEC ORA #2 ; ORA CON ARGUMENTO DECIMAL.
83 ;HEX ORA #$00 ; ORA CON ARGUMENTO HEXADECIMAL.
84 ;HLT ; INSTRUCCION DE DETENCION.
85 ;=============================================================
86 
87 ;***********************************************************************************************************************
88 
89 
90 ;***********************************************************************************************************************
91 ; INSTRUCCIONES ABSOLUTAS
92 ;***********************************************************************************************************************
93 
94 ;=============================================================
95 ; PRUEBA DE INSTRUCCION LDA ABSOLUTA.
96 ;=============================================================
97 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
98 ;L1 LDA @01 ; LDA ABSOLUTO.
99 ;HLT ; INSTRUCCION DE DETENCION.
100 ;=============================================================
101 
102 ;=============================================================
103 ; PRUEBA DE INSTRUCCION STA ABSOLUTA.
104 ;=============================================================
105 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
106 ;L1 LDA #7 ; LDA INMEDIATO.
107 ;L2 STA @0020 ; STA ABSOLUTO.
108 ;L3 ADD #1 ; LDA INMEDIATO.
109 ;L4 LDA @0020 ; LDA ABSOLUTO.
110 ;HLT ; INSTRUCCION DE DETENCION.
111 ;=============================================================
112 
113 ;=============================================================
114 ; PRUEBA DE INSTRUCCION ADD ABSOLUTA.
115 ;=============================================================
116 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
117 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
118 ;L2 STA @0020 ; STA ABSOLUTO.
119 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
120 ;L4 ADD @0020 ; ADD ABSOLUTA.
121 ;HLT ; INSTRUCCION DE DETENCION.
122 ;=============================================================
123 
124 ;=============================================================
125 ; PRUEBA DE INSTRUCCION SUB ABSOLUTA.
126 ;=============================================================
127 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
128 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
129 ;L2 STA @0020 ; STA ABSOLUTO.
130 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
131 ;L4 SUB @0020 ; SUB ABSOLUTA.
132 ;HLT ; INSTRUCCION DE DETENCION.
133 ;=============================================================
134 
135 ;=============================================================
136 ; PRUEBA DE INSTRUCCION AND ABSOLUTA.
137 ;=============================================================
138 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
139 ;L1 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
140 ;L2 STA @0020 ; STA ABSOLUTO.
141 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
142 ;L4 AND @0020 ; AND ABSOLUTAL.
143 ;HLT ; INSTRUCCION DE DETENCION.
144 ;=============================================================
145 
146 ;=============================================================
147 ; PRUEBA DE INSTRUCCION ORA ABSOLUTA.
148 ;=============================================================
149 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
150 ;L1 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
151 ;L2 STA @0020 ; STA ABSOLUTO.
152 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
153 ;L4 ORA @0020 ; ORA ABSOLUTA.
154 ;HLT ; INSTRUCCION DE DETENCION.
155 ;=============================================================
156 
157 ;***********************************************************************************************************************
158 
159 ;***********************************************************************************************************************
160 ; INSTRUCCIONES INDIRECTAS
161 ;***********************************************************************************************************************
162 ;=============================================================
163 ; PRUEBA DE INSTRUCCION LDA INDIRECTA.
164 ;=============================================================
165 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
166 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
167 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
168 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
169 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
170 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
171 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @0102.
172 ;L7 LDA (@0010) ; LDA INDIRECTO.
173 ;HLT ; INSTRUCCION DE DETENCION.
174 ;=============================================================
175 
176 ;=============================================================
177 ; PRUEBA DE INSTRUCCION STA INDIRECTA.
178 ;=============================================================
179 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
180 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
181 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
182 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
183 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
184 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
185 ;L6 STA (@0010) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
186 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
187 ;L8 LDA @2211 ; LDA ABSOLUTO.
188 ;HLT ; INSTRUCCION DE DETENCION.
189 ;=============================================================
190 
191 ;=============================================================
192 ; PRUEBA DE INSTRUCCION ADD INDIRECTA.
193 ;=============================================================
194 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
195 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
196 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
197 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
198 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
199 ;L5 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
200 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
201 ;L7 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
202 ;L8 ADD (@0010) ; ADD INDIRECTO, ESCRITURA DE 7 A @0102.
203 ;L9 LDA @2211 ; LDA ABSOLUTO.
204 ;HLT ; INSTRUCCION DE DETENCION.
205 ;=============================================================
206 
207 ;=============================================================
208 ; PRUEBA DE INSTRUCCION SUB INDIRECTA.
209 ;=============================================================
210 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
211 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
212 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
213 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
214 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
215 ;L5 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
216 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
217 ;L7 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
218 ;L8 SUB (@0010) ; SUB INDIRECTO.
219 ;L9 LDA @2211 ; LDA ABSOLUTO.
220 ;HLT ; INSTRUCCION DE DETENCION.
221 ;=============================================================
222 
223 ;=============================================================
224 ; PRUEBA DE INSTRUCCION AND INDIRECTA.
225 ;=============================================================
226 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
227 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
228 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
229 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
230 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
231 ;L5 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
232 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
233 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
234 ;L8 AND (@0010) ; AND INDIRECTO.
235 ;L9 LDA @2211 ; LDA ABSOLUTO.
236 ;HLT ; INSTRUCCION DE DETENCION.
237 ;=============================================================
238 
239 ;=============================================================
240 ; PRUEBA DE INSTRUCCION ORA INDIRECTA.
241 ;=============================================================
242 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
243 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
244 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
245 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
246 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
247 ;L5 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
248 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
249 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
250 ;L8 ORA (@0010) ; ORA INDIRECTO.
251 ;L9 LDA @2211 ; LDA ABSOLUTO.
252 ;HLT ; INSTRUCCION DE DETENCION.
253 ;=============================================================
254 ;***********************************************************************************************************************
255 
256 ;***********************************************************************************************************************
257 ; INSTRUCCIONES DE ACUMULADOR
258 ;***********************************************************************************************************************
259 
260 ;=============================================================
261 ; PRUEBA DE INSTRUCCION CLA DE ACUMULADOR.
262 ;=============================================================
263 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
264 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
265 ;L2 CLA ; CLA DE ACUMULADOR, LIMPIA EL ACUMULADOR.
266 ;HLT ; INSTRUCCION DE DETENCION.
267 ;=============================================================
268 
269 ;=============================================================
270 ; PRUEBA DE INSTRUCCION CPA DE ACUMULADOR.
271 ;=============================================================
272 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
273 ;L1 LDA #%111000 ; LDA CON ARGUMENTO DECIMAL.
274 ;L2 CPA ; CPA DE ACUMULADOR, COMPLEMENTA EL ACUMULADOR.
275 ;HLT ; INSTRUCCION DE DETENCION.
276 ;=============================================================
277 
278 ;=============================================================
279 ; PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
280 ;=============================================================
281 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
282 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
283 ;L2 INA ; INA DE ACUMULADOR, INCREMENTA EL ACUMULADOR EN 1.
284 ;HLT ; INSTRUCCION DE DETENCION.
285 ;=============================================================
286 
287 ;=============================================================
288 ; PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
289 ;=============================================================
290 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
291 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
292 ;L2 DCA ; DCA DE ACUMULADOR, DECREMENTO EL ACUMULADOR EN 1.
293 ;HLT ; INSTRUCCION DE DETENCION.
294 ;=============================================================
295 
296 ;=============================================================
297 ; PRUEBA DE INSTRUCCION ROL DE ACUMULADOR.
298 ;=============================================================
299 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
300 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
301 ;L2 ROL ; ROL DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA IZQ.
302 ;HLT ; INSTRUCCION DE DETENCION.
303 ;=============================================================
304 
305 ;=============================================================
306 ; PRUEBA DE INSTRUCCION ROR DE ACUMULADOR.
307 ;=============================================================
308 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
309 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
310 ;L2 ROR ; ROR DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA DER.
311 ;HLT ; INSTRUCCION DE DETENCION.
312 ;=============================================================
313 ;***********************************************************************************************************************
314 
315 ;***********************************************************************************************************************
316 ; INSTRUCCIONES DE IMPLICITAS
317 ;***********************************************************************************************************************
318 
319 ;=============================================================
320 ; PRUEBA DE INSTRUCCION SEC IMPLICITA.
321 ;=============================================================
322 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
323 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
324 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
325 ;HLT ; INSTRUCCION DE DETENCION.
326 ;=============================================================
327 
328 ;=============================================================
329 ; PRUEBA DE INSTRUCCION CLC IMPLICITA.
330 ;=============================================================
331 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
332 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
333 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
334 ;L3 CLC ; CLC IMPLICITO, PONE EN BAJO LA BANDERA DE ACARREO.
335 ;HLT ; INSTRUCCION DE DETENCION.
336 ;=============================================================
337 
338 ;=============================================================
339 ; PRUEBA DE INSTRUCCION SEI IMPLICITA.
340 ;=============================================================
341 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
342 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
343 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
344 ;HLT ; INSTRUCCION DE DETENCION.
345 ;=============================================================
346 
347 ;=============================================================
348 ; PRUEBA DE INSTRUCCION CLI IMPLICITA.
349 ;=============================================================
350 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
351 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
352 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
353 ;L3 CLI ; CLI IMPLICITO, PONE EN BAJO LA BANDERA DE INTERRUP.
354 ;HLT ; INSTRUCCION DE DETENCION.
355 ;=============================================================
356 ;***********************************************************************************************************************
357 
358 ;***********************************************************************************************************************
359 ; INSTRUCCIONES DE RELATIVAS
360 ;***********************************************************************************************************************
361 
362 ;=============================================================
363 ; PRUEBA DE INSTRUCCION BEQ RELATIVA.
364 ;=============================================================
365 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
366 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
367 ;L2 BEQ L1 ; SALTA A L1 SI EL ACUMULADOR ES 0.
368 ;HLT ; INSTRUCCION DE DETENCION.
369 ;=============================================================
370 
371 ;=============================================================
372 ; PRUEBA DE INSTRUCCION BNE RELATIVA.
373 ;=============================================================
374 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
375 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
376 ;L2 BNE L1 ; SALTA A L1 SI EL ACUMULADOR ES DISTINTO DE 0.
377 ;HLT ; INSTRUCCION DE DETENCION.
378 ;=============================================================
379 
380 ;=============================================================
381 ; PRUEBA DE INSTRUCCION BCC RELATIVA.
382 ;=============================================================
383 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
384 ;L1 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
385 ;L2 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
386 ;L3 BCC L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 0.
387 ;HLT ; INSTRUCCION DE DETENCION.
388 ;=============================================================
389 
390 ;=============================================================
391 ; PRUEBA DE INSTRUCCION BCS RELATIVA.
392 ;=============================================================
393 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
394 ;L1 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
395 ;L2 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
396 ;L3 BCS L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 1.
397 ;HLT ; INSTRUCCION DE DETENCION.
398 ;=============================================================
399 
400 ;=============================================================
401 ; PRUEBA DE INSTRUCCION BPL RELATIVA.
402 ;=============================================================
403 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
404 ;L1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
405 ;L2 BPL L1 ; SALTA A L1 SI EL ACUMULADOR ES POSITIVO.
406 ;HLT ; INSTRUCCION DE DETENCION.
407 ;=============================================================
408 
409 ;=============================================================
410 ; PRUEBA DE INSTRUCCION BMI RELATIVA.
411 ;=============================================================
412 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
413 ;L1 LDA #%100000 ; LDA CON ARGUMENTO BINARIO NEGATIVO.
414 ;L2 BMI L1 ; SALTA A L1 SI EL ACUMULADOR ES NEGATIVO.
415 ;HLT ; INSTRUCCION DE DETENCION.
416 ;=============================================================
417 
418 ;=============================================================
419 ; PRUEBA DE INSTRUCCION BVC RELATIVA.
420 ;=============================================================
421 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
422 ;L1 LDA #1 ; LDA CON ARGUMENTO BINARIO.
423 ;L2 ADD #1 ; SE AGREGA %001010 AL ACUMULADOR.
424 ;L3 BVC L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 0.
425 ;HLT ; INSTRUCCION DE DETENCION.
426 ;=============================================================
427 
428 ;=============================================================
429 ; PRUEBA DE INSTRUCCION BVS RELATIVA.
430 ;=============================================================
431 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
432 ;L1 LDA #%010110 ; LDA CON ARGUMENTO BINARIO.
433 ;L2 ADD #%001010 ; SE AGREGA %001010 AL ACUMULADOR.
434 ;L3 BVS L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 1.
435 ;HLT ; INSTRUCCION DE DETENCION.
436 ;=============================================================
437 ;***********************************************************************************************************************
438 
439 ;***********************************************************************************************************************
440 ; INSTRUCCIONES DE CONTROL
441 ;***********************************************************************************************************************
442 
443 ;=============================================================
444 ; PRUEBA DE INSTRUCCION HLT DE CONTROL.
445 ;=============================================================
446 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
447 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
448 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
449 ;=============================================================
450 
451 ;=============================================================
452 ; PRUEBA DE INSTRUCCION NOP DE CONTROL.
453 ;=============================================================
454 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
455 ;NOP ; INSTRUCCION DE CONTROL NOP.
456 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
457 ;=============================================================
458 ;***********************************************************************************************************************
459 
460 ;***********************************************************************************************************************
461 ; INSTRUCCIONES DE ENTRADA SALIDA
462 ;***********************************************************************************************************************
463 
464 ;=============================================================
465 ; PRUEBA DE INSTRUCCION OUT DE CONTROL.
466 ;=============================================================
467 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
468 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
469 ;OUT @01 ; ESCRITURA AL PUERTO DE SALIDA CON DIRECCION @01.
470 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
471 ;=============================================================
472 
473 ;=============================================================
474 ; PRUEBA DE INSTRUCCION INP DE CONTROL.
475 ;=============================================================
476 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
477 ;BIN1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
478 ;INP @00 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
479 ;BIN7 LDA #%000111 ; LDA CON ARGUMENTO BINARIO.
480 ;INP @03 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
481 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
482 ;=============================================================
483 
484 ;=============================================================
485 ; PRUEBA DE INSTRUCCION STA INDIRECTA.
486 ;=============================================================
487 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
488 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
489 ;L2 STA @1000 ; STA ABSOLUTO, ESCRITURA A PB.
490 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
491 ;L4 STA @1001 ; STA ABSOLUTO, ESCRITURA A PA.
492 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
493 ;L6 STA (@1000) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
494 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
495 ;L8 LDA @2211 ; LDA ABSOLUTO.
496 ;HLT ; INSTRUCCION DE DETENCION.
497 ;=============================================================
498 
499 
500 ;DBWRD @0000
501 ;WRD @0000
502 ;LALA1 = 66
503 ;UPPER = 55
504 ;LALA2 = 7
505 ;BIN = %001000001000
506 ;OCT = @12
507 ;HEX = $FFFF
508 ;DEC = 10
509 ;LALA2 = @0007
510 ;LALA3 = 11
511 ;LALA4 = %111
512 ;DBWRD @0000
513 ;WRD @0000
514 
515 ;* = @000A DOESNT WORK
516 ;* = * + 1
517 ;PUNT1 = *
518 ;PUNT2 = * + 20
519 ;* = $3FFF
520 ;* = @0010
521 ;DBWRD = $000A
522 ;DBWRD $000A
523 ;WRD $000A
524 
525 
526 ;DBWRD @0100
527 ;WRD @0000
528 
529 ;DBWRD 0
530 ;WRD 0
531 
532 ;DBWRD %100000000000
533 ;WRD %100000
534 
535 ;* = 4096
536 ;* = %000000000000
537 
538 ; TODAS LAS PRUEBAS HAN SIDO CORRECTAMENTE ENSAMBLADAS
539 
540 ; PRUEBA PC DIFERENTE DE 0
541 
542 ;PRUEBA DE NOP
543 ;NOP
544 ;L0 LDA #1
545 ;INP @01
546 ;OUT @01
547 ;INP @01
548 
549 ;LDA @01
550 ;STA @01
551 
552 ;PRUEBA DE STA IND
553 ;L0 LDA #@01
554 
555 ;L1 STA @0300
556 ;L2 LDA #@01
557 ;L3 STA @0301
558 ;L7 LDA #7
559 ;L4 STA (@0300)
560 ;L5 INA
561 ;L6 LDA @0101
562 ;HLT
563 
564 
565 ;PRUEBA AND ABS
566 ;L0 LDA #%000111
567 ;L1 STA @0300
568 ;L2 LDA #%111000
569 ;L3 ORA @0300
570 
571 ;PRUEBA SUB ABS
572 ;L0 LDA #1
573 ;L1 STA @0300
574 ;L2 INA
575 ;L3 SUB @0300
576 
577 ;PRUEBA ADD ABS
578 ;L0 LDA #1
579 ;L1 STA @0300
580 ;L2 INA
581 ;L3 ADD @0300
582 
583 ;PRUEBA DE STA ABS
584 ;L0 LDA #1
585 ;L1 STA @0300
586 ;L2 INA
587 ;L3 LDA @0300
588 
589 ;L0 LDA #01
590 ;L1 ADD @0001
591 
592 ;L0 LDA #63
593 ;L1 ORA #%101001
594 
595 ; PRUEBA DE BCC
596 ;L0 LDA #0
597 ;L1 INA
598 ;L2 BCC L0
599 ;L3 LDA #1
600 
601 
602 ; PRUEBA DE BNE
603 ;L SEC
604 ;L0 CLC
605 ;L1 LDA #0
606 ;L2 INA
607 ;L6 BNE L2
608 ;L4 INA
609 ;L5 LDA #1
610 
611 ; PRUEBA DE BEQ
612 ;L SEC
613 ;L0 CLC
614 ;L1 LDA #0
615 ;L6 BEQ L1
616 ;L4 INA
617 ;L5 LDA #1
618 
619 ;PRUEBA DE LDA INMEDIATA
620 ;L1 LDA #1
621 ;L2 LDA #2
622 ;L3 LDA #3
623 ;L4 LDA #4
624 ;L5 LDA #5
625 
626 ;PRUEBA DE SUB Y ADD INMEDIATAS
627 ;L0 LDA #0
628 ;L1 LDA #63
629 ;L2 SUB #62
630 ;L3 SUB #1
631 ;L4 ADD #1
632 ;L5 ADD #1
633 
634 ;K3 BNE K3
635 ;K5 BNE K3
636 ;K1 SEC
637 ;K2 SEC
638 ;BNE K1
639 ;K3 BNE K3
640 ;K5 BNE K3
641 ;L1 LDA (@0001)
642 ;BNE L1
643 ;L2 LDA @0002
644 ;L3 LDA @0002
645 ;BNE L1
646 ;L1 LDA @0001
647 
648 ;LDA LALA1
649 ;LDA @0001
650 ;L1 LDA BIN
651 ;LDA OCT
652 ;LDA DEC
653 ;LDA HEX
654 ;L1 LDA HEX
655 ;L2 LDA #HEX
656 ;LDA #HEX
657 ;BNE L3
658 ;BMI L1
659 ;LOOP1 BNE L1
660 ;L4 BMI L2
661 ;LDA (BIN)
662 ;LDA (OCT)
663 ;LDA (DEC)
664 ;LDA (HEX)
665 
666 ;LDA %1010
667 ;LDA @12
668 ;LDA 10
669 ;LDA $0A
670 ;LDA (%1010)
671 ;LDA (@12)
672 ;LDA (10)
673 ;LDA ($0A)
674 
675 ;LDA #%1010
676 ;LDA #@12
677 ;LDA #10
678 ;LDA $0A
679 ;LDA #BIN
680 ;LDA #OCT
681 ;LDA #DEC
682 ;LDA #HEX
683 
684 ;IMP SEC
685 ;ACU CLA
686 ;CTR TPA
687 
688 ;INP %1010
689 ;INP @12
690 ;INP 10
691 ;INP $0A
692 ;INP BIN
693 ;INP OCT
694 ;INP DEC
695 ;INP HEX
696 
697 
698 ;LDA %111
699 ;L2 LDA (LALA1)
700 ;L3 LDA (%01)
701 ;LDA (@0001)
702 ;BNE L2
703 ;BMI L3
704 ;LABEL BNE LALA2
705 ;LALA3 BNE LABEL
706 ;BNE LABEL
707 ;BMI LALA2
708 ;LOOP1 CPA
709 ;INA
710 ;ROR
711 ;NOP
712 ;INP LALA1
713 ;L1 INP LALA2
714 ;LABEL LDA (LALA1)
715 ;BNE LABEL
716 ;LABEL XXX LALA1
717 ;LABEL LDA @0001
718 ;LAB1 LDA PERRO
719 ;BNE LABEL
720 ;L1 BNE LALA
721 ;LALA LDA #01
722 ;LDA #$A
723 ;LDA #LABEL
724 ;LABEL LDA #@07
725 ;LABEL1 LDA #@07
726 ;BNE LABEL1
727 ;INP $FF
728 ;OUT %100
729 ;HLT
730 
731 
732 ;LDA #0
733 ;HLT
734 ;HLT
735 ;HLT
736 ;LDA #7
737 ;LDA #7
738 ;LDA #7
739 ;HLT
740 
741 ;BEQ JUMP1
742 ;LDA (@1000)
743 ;SEC
744 ;CLA
745 ;TPA
746 ;INP @77
747 
