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
16 OUT @01
17 STA @1000
18 ;INP @03
19 ;INP @02
20 ;INP @01
21 ;INP @00
22 
23 ;LABEL = @0001
24 ;LABEL = @0002
25 ;BNE LABEL
26 ;BIN0 LDA #LABEL+1
27 ;BIN LDA LABEL+2
28 ;BIN2 LDA (LABEL+10000000)
29 ;LDA #LABEL+1
30 ;LDA LABEL+1
31 ;LDA (LABEL+1)
32 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
33 ;OCT LDA #@02 ; LDA CON ARGUMENTO OCTAL.
34 ;HEX LDA #$03 ; LDA CON ARGUMENTO HEXADECIMAL.
35 ;DEC LDA #4 ; LDA CON ARGUMENTO DECIMAL.
36 ;1234567 INA ;
37 HLT ; INSTRUCCION DE DETENCION.
38 ;=============================================================
39 
40 ;=============================================================
41 ; PRUEBA DE INSTRUCCION ADD INMEDIATA.
42 ;=============================================================
43 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
44 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
45 ;BIN ADD #%000010 ; ADD CON ARGUMENTO BINARIO.
46 ;OCT ADD #@02 ; ADD CON ARGUMENTO OCTACL.
47 ;DEC ADD #2 ; ADD CON ARGUMENTO DECIMAL.
48 ;HEX ADD #$02 ; ADD CON ARGUMENTO HEXADECIMAL.
49 ;HLT ; INSTRUCCION DE DETENCION.
50 ;=============================================================
51 
52 ;=============================================================
53 ; PRUEBA DE INSTRUCCION SUB INMEDIATA.
54 ;=============================================================
55 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
56 ;L1 LDA #10 ; LDA CON ARGUMENTO DECIMAL.
57 ;BIN SUB #%000010 ; SUB CON ARGUMENTO BINARIO.
58 ;OCT SUB #@02 ; SUB CON ARGUMENTO OCTACL.
59 ;DEC SUB #2 ; SUB CON ARGUMENTO DECIMAL.
60 ;HEX SUB #$02 ; SUB CON ARGUMENTO HEXADECIMAL.
61 ;HLT ; INSTRUCCION DE DETENCION.
62 ;=============================================================
63 
64 ;=============================================================
65 ; PRUEBA DE INSTRUCCION AND INMEDIATA.
66 ;=============================================================
67 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
68 ;L1 LDA #%111111 ; LDA CON ARGUMENTO DECIMAL.
69 ;BIN AND #%000111 ; AND CON ARGUMENTO BINARIO.
70 ;OCT AND #@07 ; AND CON ARGUMENTO OCTACL.
71 ;DEC AND #3 ; AND CON ARGUMENTO DECIMAL.
72 ;HEX AND #$01 ; AND CON ARGUMENTO HEXADECIMAL.
73 ;HLT ; INSTRUCCION DE DETENCION.
74 ;=============================================================
75 
76 ;=============================================================
77 ; PRUEBA DE INSTRUCCION ORA INMEDIATA.
78 ;=============================================================
79 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
80 ;L1 LDA #%101000 ; LDA CON ARGUMENTO DECIMAL.
81 ;BIN ORA #%000101 ; ORA CON ARGUMENTO BINARIO.
82 ;OCT ORA #@20 ; ORA CON ARGUMENTO OCTACL.
83 ;DEC ORA #2 ; ORA CON ARGUMENTO DECIMAL.
84 ;HEX ORA #$00 ; ORA CON ARGUMENTO HEXADECIMAL.
85 ;HLT ; INSTRUCCION DE DETENCION.
86 ;=============================================================
87 
88 ;***********************************************************************************************************************
89 
90 
91 ;***********************************************************************************************************************
92 ; INSTRUCCIONES ABSOLUTAS
93 ;***********************************************************************************************************************
94 
95 ;=============================================================
96 ; PRUEBA DE INSTRUCCION LDA ABSOLUTA.
97 ;=============================================================
98 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
99 ;L1 LDA @01 ; LDA ABSOLUTO.
100 ;HLT ; INSTRUCCION DE DETENCION.
101 ;=============================================================
102 
103 ;=============================================================
104 ; PRUEBA DE INSTRUCCION STA ABSOLUTA.
105 ;=============================================================
106 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
107 ;L1 LDA #7 ; LDA INMEDIATO.
108 ;L2 STA @0020 ; STA ABSOLUTO.
109 ;L3 ADD #1 ; LDA INMEDIATO.
110 ;L4 LDA @0020 ; LDA ABSOLUTO.
111 ;HLT ; INSTRUCCION DE DETENCION.
112 ;=============================================================
113 
114 ;=============================================================
115 ; PRUEBA DE INSTRUCCION ADD ABSOLUTA.
116 ;=============================================================
117 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
118 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
119 ;L2 STA @0020 ; STA ABSOLUTO.
120 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
121 ;L4 ADD @0020 ; ADD ABSOLUTA.
122 ;HLT ; INSTRUCCION DE DETENCION.
123 ;=============================================================
124 
125 ;=============================================================
126 ; PRUEBA DE INSTRUCCION SUB ABSOLUTA.
127 ;=============================================================
128 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
129 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
130 ;L2 STA @0020 ; STA ABSOLUTO.
131 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
132 ;L4 SUB @0020 ; SUB ABSOLUTA.
133 ;HLT ; INSTRUCCION DE DETENCION.
134 ;=============================================================
135 
136 ;=============================================================
137 ; PRUEBA DE INSTRUCCION AND ABSOLUTA.
138 ;=============================================================
139 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
140 ;L1 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
141 ;L2 STA @0020 ; STA ABSOLUTO.
142 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
143 ;L4 AND @0020 ; AND ABSOLUTAL.
144 ;HLT ; INSTRUCCION DE DETENCION.
145 ;=============================================================
146 
147 ;=============================================================
148 ; PRUEBA DE INSTRUCCION ORA ABSOLUTA.
149 ;=============================================================
150 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
151 ;L1 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
152 ;L2 STA @0020 ; STA ABSOLUTO.
153 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
154 ;L4 ORA @0020 ; ORA ABSOLUTA.
155 ;HLT ; INSTRUCCION DE DETENCION.
156 ;=============================================================
157 
158 ;***********************************************************************************************************************
159 
160 ;***********************************************************************************************************************
161 ; INSTRUCCIONES INDIRECTAS
162 ;***********************************************************************************************************************
163 ;=============================================================
164 ; PRUEBA DE INSTRUCCION LDA INDIRECTA.
165 ;=============================================================
166 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
167 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
168 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
169 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
170 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
171 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
172 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @0102.
173 ;L7 LDA (@0010) ; LDA INDIRECTO.
174 ;HLT ; INSTRUCCION DE DETENCION.
175 ;=============================================================
176 
177 ;=============================================================
178 ; PRUEBA DE INSTRUCCION STA INDIRECTA.
179 ;=============================================================
180 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
181 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
182 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
183 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
184 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
185 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
186 ;L6 STA (@0010) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
187 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
188 ;L8 LDA @2211 ; LDA ABSOLUTO.
189 ;HLT ; INSTRUCCION DE DETENCION.
190 ;=============================================================
191 
192 ;=============================================================
193 ; PRUEBA DE INSTRUCCION ADD INDIRECTA.
194 ;=============================================================
195 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
196 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
197 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
198 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
199 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
200 ;L5 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
201 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
202 ;L7 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
203 ;L8 ADD (@0010) ; ADD INDIRECTO, ESCRITURA DE 7 A @0102.
204 ;L9 LDA @2211 ; LDA ABSOLUTO.
205 ;HLT ; INSTRUCCION DE DETENCION.
206 ;=============================================================
207 
208 ;=============================================================
209 ; PRUEBA DE INSTRUCCION SUB INDIRECTA.
210 ;=============================================================
211 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
212 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
213 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
214 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
215 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
216 ;L5 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
217 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
218 ;L7 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
219 ;L8 SUB (@0010) ; SUB INDIRECTO.
220 ;L9 LDA @2211 ; LDA ABSOLUTO.
221 ;HLT ; INSTRUCCION DE DETENCION.
222 ;=============================================================
223 
224 ;=============================================================
225 ; PRUEBA DE INSTRUCCION AND INDIRECTA.
226 ;=============================================================
227 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
228 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
229 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
230 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
231 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
232 ;L5 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
233 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
234 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
235 ;L8 AND (@0010) ; AND INDIRECTO.
236 ;L9 LDA @2211 ; LDA ABSOLUTO.
237 ;HLT ; INSTRUCCION DE DETENCION.
238 ;=============================================================
239 
240 ;=============================================================
241 ; PRUEBA DE INSTRUCCION ORA INDIRECTA.
242 ;=============================================================
243 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
244 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
245 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
246 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
247 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
248 ;L5 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
249 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
250 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
251 ;L8 ORA (@0010) ; ORA INDIRECTO.
252 ;L9 LDA @2211 ; LDA ABSOLUTO.
253 ;HLT ; INSTRUCCION DE DETENCION.
254 ;=============================================================
255 ;***********************************************************************************************************************
256 
257 ;***********************************************************************************************************************
258 ; INSTRUCCIONES DE ACUMULADOR
259 ;***********************************************************************************************************************
260 
261 ;=============================================================
262 ; PRUEBA DE INSTRUCCION CLA DE ACUMULADOR.
263 ;=============================================================
264 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
265 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
266 ;L2 CLA ; CLA DE ACUMULADOR, LIMPIA EL ACUMULADOR.
267 ;HLT ; INSTRUCCION DE DETENCION.
268 ;=============================================================
269 
270 ;=============================================================
271 ; PRUEBA DE INSTRUCCION CPA DE ACUMULADOR.
272 ;=============================================================
273 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
274 ;L1 LDA #%111000 ; LDA CON ARGUMENTO DECIMAL.
275 ;L2 CPA ; CPA DE ACUMULADOR, COMPLEMENTA EL ACUMULADOR.
276 ;HLT ; INSTRUCCION DE DETENCION.
277 ;=============================================================
278 
279 ;=============================================================
280 ; PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
281 ;=============================================================
282 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
283 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
284 ;L2 INA ; INA DE ACUMULADOR, INCREMENTA EL ACUMULADOR EN 1.
285 ;HLT ; INSTRUCCION DE DETENCION.
286 ;=============================================================
287 
288 ;=============================================================
289 ; PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
290 ;=============================================================
291 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
292 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
293 ;L2 DCA ; DCA DE ACUMULADOR, DECREMENTO EL ACUMULADOR EN 1.
294 ;HLT ; INSTRUCCION DE DETENCION.
295 ;=============================================================
296 
297 ;=============================================================
298 ; PRUEBA DE INSTRUCCION ROL DE ACUMULADOR.
299 ;=============================================================
300 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
301 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
302 ;L2 ROL ; ROL DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA IZQ.
303 ;HLT ; INSTRUCCION DE DETENCION.
304 ;=============================================================
305 
306 ;=============================================================
307 ; PRUEBA DE INSTRUCCION ROR DE ACUMULADOR.
308 ;=============================================================
309 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
310 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
311 ;L2 ROR ; ROR DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA DER.
312 ;HLT ; INSTRUCCION DE DETENCION.
313 ;=============================================================
314 ;***********************************************************************************************************************
315 
316 ;***********************************************************************************************************************
317 ; INSTRUCCIONES DE IMPLICITAS
318 ;***********************************************************************************************************************
319 
320 ;=============================================================
321 ; PRUEBA DE INSTRUCCION SEC IMPLICITA.
322 ;=============================================================
323 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
324 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
325 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
326 ;HLT ; INSTRUCCION DE DETENCION.
327 ;=============================================================
328 
329 ;=============================================================
330 ; PRUEBA DE INSTRUCCION CLC IMPLICITA.
331 ;=============================================================
332 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
333 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
334 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
335 ;L3 CLC ; CLC IMPLICITO, PONE EN BAJO LA BANDERA DE ACARREO.
336 ;HLT ; INSTRUCCION DE DETENCION.
337 ;=============================================================
338 
339 ;=============================================================
340 ; PRUEBA DE INSTRUCCION SEI IMPLICITA.
341 ;=============================================================
342 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
343 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
344 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
345 ;HLT ; INSTRUCCION DE DETENCION.
346 ;=============================================================
347 
348 ;=============================================================
349 ; PRUEBA DE INSTRUCCION CLI IMPLICITA.
350 ;=============================================================
351 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
352 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
353 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
354 ;L3 CLI ; CLI IMPLICITO, PONE EN BAJO LA BANDERA DE INTERRUP.
355 ;HLT ; INSTRUCCION DE DETENCION.
356 ;=============================================================
357 ;***********************************************************************************************************************
358 
359 ;***********************************************************************************************************************
360 ; INSTRUCCIONES DE RELATIVAS
361 ;***********************************************************************************************************************
362 
363 ;=============================================================
364 ; PRUEBA DE INSTRUCCION BEQ RELATIVA.
365 ;=============================================================
366 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
367 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
368 ;L2 BEQ L1 ; SALTA A L1 SI EL ACUMULADOR ES 0.
369 ;HLT ; INSTRUCCION DE DETENCION.
370 ;=============================================================
371 
372 ;=============================================================
373 ; PRUEBA DE INSTRUCCION BNE RELATIVA.
374 ;=============================================================
375 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
376 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
377 ;L2 BNE L1 ; SALTA A L1 SI EL ACUMULADOR ES DISTINTO DE 0.
378 ;HLT ; INSTRUCCION DE DETENCION.
379 ;=============================================================
380 
381 ;=============================================================
382 ; PRUEBA DE INSTRUCCION BCC RELATIVA.
383 ;=============================================================
384 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
385 ;L1 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
386 ;L2 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
387 ;L3 BCC L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 0.
388 ;HLT ; INSTRUCCION DE DETENCION.
389 ;=============================================================
390 
391 ;=============================================================
392 ; PRUEBA DE INSTRUCCION BCS RELATIVA.
393 ;=============================================================
394 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
395 ;L1 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
396 ;L2 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
397 ;L3 BCS L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 1.
398 ;HLT ; INSTRUCCION DE DETENCION.
399 ;=============================================================
400 
401 ;=============================================================
402 ; PRUEBA DE INSTRUCCION BPL RELATIVA.
403 ;=============================================================
404 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
405 ;L1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
406 ;L2 BPL L1 ; SALTA A L1 SI EL ACUMULADOR ES POSITIVO.
407 ;HLT ; INSTRUCCION DE DETENCION.
408 ;=============================================================
409 
410 ;=============================================================
411 ; PRUEBA DE INSTRUCCION BMI RELATIVA.
412 ;=============================================================
413 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
414 ;L1 LDA #%100000 ; LDA CON ARGUMENTO BINARIO NEGATIVO.
415 ;L2 BMI L1 ; SALTA A L1 SI EL ACUMULADOR ES NEGATIVO.
416 ;HLT ; INSTRUCCION DE DETENCION.
417 ;=============================================================
418 
419 ;=============================================================
420 ; PRUEBA DE INSTRUCCION BVC RELATIVA.
421 ;=============================================================
422 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
423 ;L1 LDA #1 ; LDA CON ARGUMENTO BINARIO.
424 ;L2 ADD #1 ; SE AGREGA %001010 AL ACUMULADOR.
425 ;L3 BVC L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 0.
426 ;HLT ; INSTRUCCION DE DETENCION.
427 ;=============================================================
428 
429 ;=============================================================
430 ; PRUEBA DE INSTRUCCION BVS RELATIVA.
431 ;=============================================================
432 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
433 ;L1 LDA #%010110 ; LDA CON ARGUMENTO BINARIO.
434 ;L2 ADD #%001010 ; SE AGREGA %001010 AL ACUMULADOR.
435 ;L3 BVS L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 1.
436 ;HLT ; INSTRUCCION DE DETENCION.
437 ;=============================================================
438 ;***********************************************************************************************************************
439 
440 ;***********************************************************************************************************************
441 ; INSTRUCCIONES DE CONTROL
442 ;***********************************************************************************************************************
443 
444 ;=============================================================
445 ; PRUEBA DE INSTRUCCION HLT DE CONTROL.
446 ;=============================================================
447 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
448 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
449 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
450 ;=============================================================
451 
452 ;=============================================================
453 ; PRUEBA DE INSTRUCCION NOP DE CONTROL.
454 ;=============================================================
455 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
456 ;NOP ; INSTRUCCION DE CONTROL NOP.
457 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
458 ;=============================================================
459 ;***********************************************************************************************************************
460 
461 ;***********************************************************************************************************************
462 ; INSTRUCCIONES DE ENTRADA SALIDA
463 ;***********************************************************************************************************************
464 
465 ;=============================================================
466 ; PRUEBA DE INSTRUCCION OUT DE CONTROL.
467 ;=============================================================
468 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
469 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
470 ;OUT @01 ; ESCRITURA AL PUERTO DE SALIDA CON DIRECCION @01.
471 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
472 ;=============================================================
473 
474 ;=============================================================
475 ; PRUEBA DE INSTRUCCION INP DE CONTROL.
476 ;=============================================================
477 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
478 ;BIN1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
479 ;INP @00 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
480 ;BIN7 LDA #%000111 ; LDA CON ARGUMENTO BINARIO.
481 ;INP @03 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
482 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
483 ;=============================================================
484 
485 ;=============================================================
486 ; PRUEBA DE INSTRUCCION STA INDIRECTA.
487 ;=============================================================
488 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
489 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
490 ;L2 STA @1000 ; STA ABSOLUTO, ESCRITURA A PB.
491 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
492 ;L4 STA @1001 ; STA ABSOLUTO, ESCRITURA A PA.
493 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
494 ;L6 STA (@1000) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
495 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
496 ;L8 LDA @2211 ; LDA ABSOLUTO.
497 ;HLT ; INSTRUCCION DE DETENCION.
498 ;=============================================================
499 
500 
501 ;DBWRD @0000
502 ;WRD @0000
503 ;LALA1 = 66
504 ;UPPER = 55
505 ;LALA2 = 7
506 ;BIN = %001000001000
507 ;OCT = @12
508 ;HEX = $FFFF
509 ;DEC = 10
510 ;LALA2 = @0007
511 ;LALA3 = 11
512 ;LALA4 = %111
513 ;DBWRD @0000
514 ;WRD @0000
515 
516 ;* = @000A DOESNT WORK
517 ;* = * + 1
518 ;PUNT1 = *
519 ;PUNT2 = * + 20
520 ;* = $3FFF
521 ;* = @0010
522 ;DBWRD = $000A
523 ;DBWRD $000A
524 ;WRD $000A
525 
526 
527 ;DBWRD @0100
528 ;WRD @0000
529 
530 ;DBWRD 0
531 ;WRD 0
532 
533 ;DBWRD %100000000000
534 ;WRD %100000
535 
536 ;* = 4096
537 ;* = %000000000000
538 
539 ; TODAS LAS PRUEBAS HAN SIDO CORRECTAMENTE ENSAMBLADAS
540 
541 ; PRUEBA PC DIFERENTE DE 0
542 
543 ;PRUEBA DE NOP
544 ;NOP
545 ;L0 LDA #1
546 ;INP @01
547 ;OUT @01
548 ;INP @01
549 
550 ;LDA @01
551 ;STA @01
552 
553 ;PRUEBA DE STA IND
554 ;L0 LDA #@01
555 
556 ;L1 STA @0300
557 ;L2 LDA #@01
558 ;L3 STA @0301
559 ;L7 LDA #7
560 ;L4 STA (@0300)
561 ;L5 INA
562 ;L6 LDA @0101
563 ;HLT
564 
565 
566 ;PRUEBA AND ABS
567 ;L0 LDA #%000111
568 ;L1 STA @0300
569 ;L2 LDA #%111000
570 ;L3 ORA @0300
571 
572 ;PRUEBA SUB ABS
573 ;L0 LDA #1
574 ;L1 STA @0300
575 ;L2 INA
576 ;L3 SUB @0300
577 
578 ;PRUEBA ADD ABS
579 ;L0 LDA #1
580 ;L1 STA @0300
581 ;L2 INA
582 ;L3 ADD @0300
583 
584 ;PRUEBA DE STA ABS
585 ;L0 LDA #1
586 ;L1 STA @0300
587 ;L2 INA
588 ;L3 LDA @0300
589 
590 ;L0 LDA #01
591 ;L1 ADD @0001
592 
593 ;L0 LDA #63
594 ;L1 ORA #%101001
595 
596 ; PRUEBA DE BCC
597 ;L0 LDA #0
598 ;L1 INA
599 ;L2 BCC L0
600 ;L3 LDA #1
601 
602 
603 ; PRUEBA DE BNE
604 ;L SEC
605 ;L0 CLC
606 ;L1 LDA #0
607 ;L2 INA
608 ;L6 BNE L2
609 ;L4 INA
610 ;L5 LDA #1
611 
612 ; PRUEBA DE BEQ
613 ;L SEC
614 ;L0 CLC
615 ;L1 LDA #0
616 ;L6 BEQ L1
617 ;L4 INA
618 ;L5 LDA #1
619 
620 ;PRUEBA DE LDA INMEDIATA
621 ;L1 LDA #1
622 ;L2 LDA #2
623 ;L3 LDA #3
624 ;L4 LDA #4
625 ;L5 LDA #5
626 
627 ;PRUEBA DE SUB Y ADD INMEDIATAS
628 ;L0 LDA #0
629 ;L1 LDA #63
630 ;L2 SUB #62
631 ;L3 SUB #1
632 ;L4 ADD #1
633 ;L5 ADD #1
634 
635 ;K3 BNE K3
636 ;K5 BNE K3
637 ;K1 SEC
638 ;K2 SEC
639 ;BNE K1
640 ;K3 BNE K3
641 ;K5 BNE K3
642 ;L1 LDA (@0001)
643 ;BNE L1
644 ;L2 LDA @0002
645 ;L3 LDA @0002
646 ;BNE L1
647 ;L1 LDA @0001
648 
649 ;LDA LALA1
650 ;LDA @0001
651 ;L1 LDA BIN
652 ;LDA OCT
653 ;LDA DEC
654 ;LDA HEX
655 ;L1 LDA HEX
656 ;L2 LDA #HEX
657 ;LDA #HEX
658 ;BNE L3
659 ;BMI L1
660 ;LOOP1 BNE L1
661 ;L4 BMI L2
662 ;LDA (BIN)
663 ;LDA (OCT)
664 ;LDA (DEC)
665 ;LDA (HEX)
666 
667 ;LDA %1010
668 ;LDA @12
669 ;LDA 10
670 ;LDA $0A
671 ;LDA (%1010)
672 ;LDA (@12)
673 ;LDA (10)
674 ;LDA ($0A)
675 
676 ;LDA #%1010
677 ;LDA #@12
678 ;LDA #10
679 ;LDA $0A
680 ;LDA #BIN
681 ;LDA #OCT
682 ;LDA #DEC
683 ;LDA #HEX
684 
685 ;IMP SEC
686 ;ACU CLA
687 ;CTR TPA
688 
689 ;INP %1010
690 ;INP @12
691 ;INP 10
692 ;INP $0A
693 ;INP BIN
694 ;INP OCT
695 ;INP DEC
696 ;INP HEX
697 
698 
699 ;LDA %111
700 ;L2 LDA (LALA1)
701 ;L3 LDA (%01)
702 ;LDA (@0001)
703 ;BNE L2
704 ;BMI L3
705 ;LABEL BNE LALA2
706 ;LALA3 BNE LABEL
707 ;BNE LABEL
708 ;BMI LALA2
709 ;LOOP1 CPA
710 ;INA
711 ;ROR
712 ;NOP
713 ;INP LALA1
714 ;L1 INP LALA2
715 ;LABEL LDA (LALA1)
716 ;BNE LABEL
717 ;LABEL XXX LALA1
718 ;LABEL LDA @0001
719 ;LAB1 LDA PERRO
720 ;BNE LABEL
721 ;L1 BNE LALA
722 ;LALA LDA #01
723 ;LDA #$A
724 ;LDA #LABEL
725 ;LABEL LDA #@07
726 ;LABEL1 LDA #@07
727 ;BNE LABEL1
728 ;INP $FF
729 ;OUT %100
730 ;HLT
731 
732 
733 ;LDA #0
734 ;HLT
735 ;HLT
736 ;HLT
737 ;LDA #7
738 ;LDA #7
739 ;LDA #7
740 ;HLT
741 
742 ;BEQ JUMP1
743 ;LDA (@1000)
744 ;SEC
745 ;CLA
746 ;TPA
747 ;INP @77
748 
