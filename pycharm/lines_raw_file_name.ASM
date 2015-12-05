1 
2 ;***********************************************************************************************************************
3 ; INSTRUCCIONES INMEDIATAS
4 ;***********************************************************************************************************************
5 
6 ;=============================================================
7 ; PRUEBA DE INSTRUCCION LDA INMEDIATA.
8 ;=============================================================
9 * = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
10 ;LABEL = @0001
11 LABEL = @0002
12 BNE LABEL
13 ;BIN0 LDA #LABEL+1
14 ;BIN LDA LABEL+2
15 ;BIN2 LDA (LABEL+10000000)
16 ;LDA #LABEL+1
17 ;LDA LABEL+1
18 ;LDA (LABEL+1)
19 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
20 ;OCT LDA #@02 ; LDA CON ARGUMENTO OCTAL.
21 ;HEX LDA #$03 ; LDA CON ARGUMENTO HEXADECIMAL.
22 ;DEC LDA #4 ; LDA CON ARGUMENTO DECIMAL.
23 ;1234567 INA ;
24 HLT ; INSTRUCCION DE DETENCION.
25 ;=============================================================
26 
27 ;=============================================================
28 ; PRUEBA DE INSTRUCCION ADD INMEDIATA.
29 ;=============================================================
30 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
31 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
32 ;BIN ADD #%000010 ; ADD CON ARGUMENTO BINARIO.
33 ;OCT ADD #@02 ; ADD CON ARGUMENTO OCTACL.
34 ;DEC ADD #2 ; ADD CON ARGUMENTO DECIMAL.
35 ;HEX ADD #$02 ; ADD CON ARGUMENTO HEXADECIMAL.
36 ;HLT ; INSTRUCCION DE DETENCION.
37 ;=============================================================
38 
39 ;=============================================================
40 ; PRUEBA DE INSTRUCCION SUB INMEDIATA.
41 ;=============================================================
42 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
43 ;L1 LDA #10 ; LDA CON ARGUMENTO DECIMAL.
44 ;BIN SUB #%000010 ; SUB CON ARGUMENTO BINARIO.
45 ;OCT SUB #@02 ; SUB CON ARGUMENTO OCTACL.
46 ;DEC SUB #2 ; SUB CON ARGUMENTO DECIMAL.
47 ;HEX SUB #$02 ; SUB CON ARGUMENTO HEXADECIMAL.
48 ;HLT ; INSTRUCCION DE DETENCION.
49 ;=============================================================
50 
51 ;=============================================================
52 ; PRUEBA DE INSTRUCCION AND INMEDIATA.
53 ;=============================================================
54 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
55 ;L1 LDA #%111111 ; LDA CON ARGUMENTO DECIMAL.
56 ;BIN AND #%000111 ; AND CON ARGUMENTO BINARIO.
57 ;OCT AND #@07 ; AND CON ARGUMENTO OCTACL.
58 ;DEC AND #3 ; AND CON ARGUMENTO DECIMAL.
59 ;HEX AND #$01 ; AND CON ARGUMENTO HEXADECIMAL.
60 ;HLT ; INSTRUCCION DE DETENCION.
61 ;=============================================================
62 
63 ;=============================================================
64 ; PRUEBA DE INSTRUCCION ORA INMEDIATA.
65 ;=============================================================
66 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
67 ;L1 LDA #%101000 ; LDA CON ARGUMENTO DECIMAL.
68 ;BIN ORA #%000101 ; ORA CON ARGUMENTO BINARIO.
69 ;OCT ORA #@20 ; ORA CON ARGUMENTO OCTACL.
70 ;DEC ORA #2 ; ORA CON ARGUMENTO DECIMAL.
71 ;HEX ORA #$00 ; ORA CON ARGUMENTO HEXADECIMAL.
72 ;HLT ; INSTRUCCION DE DETENCION.
73 ;=============================================================
74 
75 ;***********************************************************************************************************************
76 
77 
78 ;***********************************************************************************************************************
79 ; INSTRUCCIONES ABSOLUTAS
80 ;***********************************************************************************************************************
81 
82 ;=============================================================
83 ; PRUEBA DE INSTRUCCION LDA ABSOLUTA.
84 ;=============================================================
85 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
86 ;L1 LDA @01 ; LDA ABSOLUTO.
87 ;HLT ; INSTRUCCION DE DETENCION.
88 ;=============================================================
89 
90 ;=============================================================
91 ; PRUEBA DE INSTRUCCION STA ABSOLUTA.
92 ;=============================================================
93 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
94 ;L1 LDA #7 ; LDA INMEDIATO.
95 ;L2 STA @0020 ; STA ABSOLUTO.
96 ;L3 ADD #1 ; LDA INMEDIATO.
97 ;L4 LDA @0020 ; LDA ABSOLUTO.
98 ;HLT ; INSTRUCCION DE DETENCION.
99 ;=============================================================
100 
101 ;=============================================================
102 ; PRUEBA DE INSTRUCCION ADD ABSOLUTA.
103 ;=============================================================
104 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
105 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
106 ;L2 STA @0020 ; STA ABSOLUTO.
107 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
108 ;L4 ADD @0020 ; ADD ABSOLUTA.
109 ;HLT ; INSTRUCCION DE DETENCION.
110 ;=============================================================
111 
112 ;=============================================================
113 ; PRUEBA DE INSTRUCCION SUB ABSOLUTA.
114 ;=============================================================
115 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
116 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
117 ;L2 STA @0020 ; STA ABSOLUTO.
118 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
119 ;L4 SUB @0020 ; SUB ABSOLUTA.
120 ;HLT ; INSTRUCCION DE DETENCION.
121 ;=============================================================
122 
123 ;=============================================================
124 ; PRUEBA DE INSTRUCCION AND ABSOLUTA.
125 ;=============================================================
126 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
127 ;L1 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
128 ;L2 STA @0020 ; STA ABSOLUTO.
129 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
130 ;L4 AND @0020 ; AND ABSOLUTAL.
131 ;HLT ; INSTRUCCION DE DETENCION.
132 ;=============================================================
133 
134 ;=============================================================
135 ; PRUEBA DE INSTRUCCION ORA ABSOLUTA.
136 ;=============================================================
137 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
138 ;L1 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
139 ;L2 STA @0020 ; STA ABSOLUTO.
140 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
141 ;L4 ORA @0020 ; ORA ABSOLUTA.
142 ;HLT ; INSTRUCCION DE DETENCION.
143 ;=============================================================
144 
145 ;***********************************************************************************************************************
146 
147 ;***********************************************************************************************************************
148 ; INSTRUCCIONES INDIRECTAS
149 ;***********************************************************************************************************************
150 ;=============================================================
151 ; PRUEBA DE INSTRUCCION LDA INDIRECTA.
152 ;=============================================================
153 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
154 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
155 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
156 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
157 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
158 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
159 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @0102.
160 ;L7 LDA (@0010) ; LDA INDIRECTO.
161 ;HLT ; INSTRUCCION DE DETENCION.
162 ;=============================================================
163 
164 ;=============================================================
165 ; PRUEBA DE INSTRUCCION STA INDIRECTA.
166 ;=============================================================
167 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
168 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
169 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
170 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
171 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
172 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
173 ;L6 STA (@0010) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
174 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
175 ;L8 LDA @2211 ; LDA ABSOLUTO.
176 ;HLT ; INSTRUCCION DE DETENCION.
177 ;=============================================================
178 
179 ;=============================================================
180 ; PRUEBA DE INSTRUCCION ADD INDIRECTA.
181 ;=============================================================
182 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
183 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
184 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
185 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
186 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
187 ;L5 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
188 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
189 ;L7 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
190 ;L8 ADD (@0010) ; ADD INDIRECTO, ESCRITURA DE 7 A @0102.
191 ;L9 LDA @2211 ; LDA ABSOLUTO.
192 ;HLT ; INSTRUCCION DE DETENCION.
193 ;=============================================================
194 
195 ;=============================================================
196 ; PRUEBA DE INSTRUCCION SUB INDIRECTA.
197 ;=============================================================
198 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
199 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
200 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
201 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
202 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
203 ;L5 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
204 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
205 ;L7 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
206 ;L8 SUB (@0010) ; SUB INDIRECTO.
207 ;L9 LDA @2211 ; LDA ABSOLUTO.
208 ;HLT ; INSTRUCCION DE DETENCION.
209 ;=============================================================
210 
211 ;=============================================================
212 ; PRUEBA DE INSTRUCCION AND INDIRECTA.
213 ;=============================================================
214 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
215 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
216 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
217 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
218 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
219 ;L5 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
220 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
221 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
222 ;L8 AND (@0010) ; AND INDIRECTO.
223 ;L9 LDA @2211 ; LDA ABSOLUTO.
224 ;HLT ; INSTRUCCION DE DETENCION.
225 ;=============================================================
226 
227 ;=============================================================
228 ; PRUEBA DE INSTRUCCION ORA INDIRECTA.
229 ;=============================================================
230 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
231 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
232 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
233 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
234 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
235 ;L5 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
236 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
237 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
238 ;L8 ORA (@0010) ; ORA INDIRECTO.
239 ;L9 LDA @2211 ; LDA ABSOLUTO.
240 ;HLT ; INSTRUCCION DE DETENCION.
241 ;=============================================================
242 ;***********************************************************************************************************************
243 
244 ;***********************************************************************************************************************
245 ; INSTRUCCIONES DE ACUMULADOR
246 ;***********************************************************************************************************************
247 
248 ;=============================================================
249 ; PRUEBA DE INSTRUCCION CLA DE ACUMULADOR.
250 ;=============================================================
251 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
252 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
253 ;L2 CLA ; CLA DE ACUMULADOR, LIMPIA EL ACUMULADOR.
254 ;HLT ; INSTRUCCION DE DETENCION.
255 ;=============================================================
256 
257 ;=============================================================
258 ; PRUEBA DE INSTRUCCION CPA DE ACUMULADOR.
259 ;=============================================================
260 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
261 ;L1 LDA #%111000 ; LDA CON ARGUMENTO DECIMAL.
262 ;L2 CPA ; CPA DE ACUMULADOR, COMPLEMENTA EL ACUMULADOR.
263 ;HLT ; INSTRUCCION DE DETENCION.
264 ;=============================================================
265 
266 ;=============================================================
267 ; PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
268 ;=============================================================
269 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
270 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
271 ;L2 INA ; INA DE ACUMULADOR, INCREMENTA EL ACUMULADOR EN 1.
272 ;HLT ; INSTRUCCION DE DETENCION.
273 ;=============================================================
274 
275 ;=============================================================
276 ; PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
277 ;=============================================================
278 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
279 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
280 ;L2 DCA ; DCA DE ACUMULADOR, DECREMENTO EL ACUMULADOR EN 1.
281 ;HLT ; INSTRUCCION DE DETENCION.
282 ;=============================================================
283 
284 ;=============================================================
285 ; PRUEBA DE INSTRUCCION ROL DE ACUMULADOR.
286 ;=============================================================
287 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
288 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
289 ;L2 ROL ; ROL DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA IZQ.
290 ;HLT ; INSTRUCCION DE DETENCION.
291 ;=============================================================
292 
293 ;=============================================================
294 ; PRUEBA DE INSTRUCCION ROR DE ACUMULADOR.
295 ;=============================================================
296 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
297 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
298 ;L2 ROR ; ROR DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA DER.
299 ;HLT ; INSTRUCCION DE DETENCION.
300 ;=============================================================
301 ;***********************************************************************************************************************
302 
303 ;***********************************************************************************************************************
304 ; INSTRUCCIONES DE IMPLICITAS
305 ;***********************************************************************************************************************
306 
307 ;=============================================================
308 ; PRUEBA DE INSTRUCCION SEC IMPLICITA.
309 ;=============================================================
310 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
311 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
312 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
313 ;HLT ; INSTRUCCION DE DETENCION.
314 ;=============================================================
315 
316 ;=============================================================
317 ; PRUEBA DE INSTRUCCION CLC IMPLICITA.
318 ;=============================================================
319 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
320 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
321 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
322 ;L3 CLC ; CLC IMPLICITO, PONE EN BAJO LA BANDERA DE ACARREO.
323 ;HLT ; INSTRUCCION DE DETENCION.
324 ;=============================================================
325 
326 ;=============================================================
327 ; PRUEBA DE INSTRUCCION SEI IMPLICITA.
328 ;=============================================================
329 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
330 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
331 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
332 ;HLT ; INSTRUCCION DE DETENCION.
333 ;=============================================================
334 
335 ;=============================================================
336 ; PRUEBA DE INSTRUCCION CLI IMPLICITA.
337 ;=============================================================
338 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
339 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
340 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
341 ;L3 CLI ; CLI IMPLICITO, PONE EN BAJO LA BANDERA DE INTERRUP.
342 ;HLT ; INSTRUCCION DE DETENCION.
343 ;=============================================================
344 ;***********************************************************************************************************************
345 
346 ;***********************************************************************************************************************
347 ; INSTRUCCIONES DE RELATIVAS
348 ;***********************************************************************************************************************
349 
350 ;=============================================================
351 ; PRUEBA DE INSTRUCCION BEQ RELATIVA.
352 ;=============================================================
353 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
354 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
355 ;L2 BEQ L1 ; SALTA A L1 SI EL ACUMULADOR ES 0.
356 ;HLT ; INSTRUCCION DE DETENCION.
357 ;=============================================================
358 
359 ;=============================================================
360 ; PRUEBA DE INSTRUCCION BNE RELATIVA.
361 ;=============================================================
362 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
363 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
364 ;L2 BNE L1 ; SALTA A L1 SI EL ACUMULADOR ES DISTINTO DE 0.
365 ;HLT ; INSTRUCCION DE DETENCION.
366 ;=============================================================
367 
368 ;=============================================================
369 ; PRUEBA DE INSTRUCCION BCC RELATIVA.
370 ;=============================================================
371 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
372 ;L1 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
373 ;L2 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
374 ;L3 BCC L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 0.
375 ;HLT ; INSTRUCCION DE DETENCION.
376 ;=============================================================
377 
378 ;=============================================================
379 ; PRUEBA DE INSTRUCCION BCS RELATIVA.
380 ;=============================================================
381 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
382 ;L1 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
383 ;L2 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
384 ;L3 BCS L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 1.
385 ;HLT ; INSTRUCCION DE DETENCION.
386 ;=============================================================
387 
388 ;=============================================================
389 ; PRUEBA DE INSTRUCCION BPL RELATIVA.
390 ;=============================================================
391 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
392 ;L1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
393 ;L2 BPL L1 ; SALTA A L1 SI EL ACUMULADOR ES POSITIVO.
394 ;HLT ; INSTRUCCION DE DETENCION.
395 ;=============================================================
396 
397 ;=============================================================
398 ; PRUEBA DE INSTRUCCION BMI RELATIVA.
399 ;=============================================================
400 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
401 ;L1 LDA #%100000 ; LDA CON ARGUMENTO BINARIO NEGATIVO.
402 ;L2 BMI L1 ; SALTA A L1 SI EL ACUMULADOR ES NEGATIVO.
403 ;HLT ; INSTRUCCION DE DETENCION.
404 ;=============================================================
405 
406 ;=============================================================
407 ; PRUEBA DE INSTRUCCION BVC RELATIVA.
408 ;=============================================================
409 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
410 ;L1 LDA #1 ; LDA CON ARGUMENTO BINARIO.
411 ;L2 ADD #1 ; SE AGREGA %001010 AL ACUMULADOR.
412 ;L3 BVC L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 0.
413 ;HLT ; INSTRUCCION DE DETENCION.
414 ;=============================================================
415 
416 ;=============================================================
417 ; PRUEBA DE INSTRUCCION BVS RELATIVA.
418 ;=============================================================
419 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
420 ;L1 LDA #%010110 ; LDA CON ARGUMENTO BINARIO.
421 ;L2 ADD #%001010 ; SE AGREGA %001010 AL ACUMULADOR.
422 ;L3 BVS L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 1.
423 ;HLT ; INSTRUCCION DE DETENCION.
424 ;=============================================================
425 ;***********************************************************************************************************************
426 
427 ;***********************************************************************************************************************
428 ; INSTRUCCIONES DE CONTROL
429 ;***********************************************************************************************************************
430 
431 ;=============================================================
432 ; PRUEBA DE INSTRUCCION HLT DE CONTROL.
433 ;=============================================================
434 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
435 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
436 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
437 ;=============================================================
438 
439 ;=============================================================
440 ; PRUEBA DE INSTRUCCION NOP DE CONTROL.
441 ;=============================================================
442 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
443 ;NOP ; INSTRUCCION DE CONTROL NOP.
444 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
445 ;=============================================================
446 ;***********************************************************************************************************************
447 
448 ;***********************************************************************************************************************
449 ; INSTRUCCIONES DE ENTRADA SALIDA
450 ;***********************************************************************************************************************
451 
452 ;=============================================================
453 ; PRUEBA DE INSTRUCCION OUT DE CONTROL.
454 ;=============================================================
455 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
456 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
457 ;OUT @01 ; ESCRITURA AL PUERTO DE SALIDA CON DIRECCION @01.
458 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
459 ;=============================================================
460 
461 ;=============================================================
462 ; PRUEBA DE INSTRUCCION INP DE CONTROL.
463 ;=============================================================
464 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
465 ;BIN1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
466 ;INP @00 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
467 ;BIN7 LDA #%000111 ; LDA CON ARGUMENTO BINARIO.
468 ;INP @03 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
469 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
470 ;=============================================================
471 
472 ;=============================================================
473 ; PRUEBA DE INSTRUCCION STA INDIRECTA.
474 ;=============================================================
475 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
476 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
477 ;L2 STA @1000 ; STA ABSOLUTO, ESCRITURA A PB.
478 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
479 ;L4 STA @1001 ; STA ABSOLUTO, ESCRITURA A PA.
480 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
481 ;L6 STA (@1000) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
482 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
483 ;L8 LDA @2211 ; LDA ABSOLUTO.
484 ;HLT ; INSTRUCCION DE DETENCION.
485 ;=============================================================
486 
487 
488 ;DBWRD @0000
489 ;WRD @0000
490 ;LALA1 = 66
491 ;UPPER = 55
492 ;LALA2 = 7
493 ;BIN = %001000001000
494 ;OCT = @12
495 ;HEX = $FFFF
496 ;DEC = 10
497 ;LALA2 = @0007
498 ;LALA3 = 11
499 ;LALA4 = %111
500 ;DBWRD @0000
501 ;WRD @0000
502 
503 ;* = @000A DOESNT WORK
504 ;* = * + 1
505 ;PUNT1 = *
506 ;PUNT2 = * + 20
507 ;* = $3FFF
508 ;* = @0010
509 ;DBWRD = $000A
510 ;DBWRD $000A
511 ;WRD $000A
512 
513 
514 ;DBWRD @0100
515 ;WRD @0000
516 
517 ;DBWRD 0
518 ;WRD 0
519 
520 ;DBWRD %100000000000
521 ;WRD %100000
522 
523 ;* = 4096
524 ;* = %000000000000
525 
526 ; TODAS LAS PRUEBAS HAN SIDO CORRECTAMENTE ENSAMBLADAS
527 
528 ; PRUEBA PC DIFERENTE DE 0
529 
530 ;PRUEBA DE NOP
531 ;NOP
532 ;L0 LDA #1
533 ;INP @01
534 ;OUT @01
535 ;INP @01
536 
537 ;LDA @01
538 ;STA @01
539 
540 ;PRUEBA DE STA IND
541 ;L0 LDA #@01
542 
543 ;L1 STA @0300
544 ;L2 LDA #@01
545 ;L3 STA @0301
546 ;L7 LDA #7
547 ;L4 STA (@0300)
548 ;L5 INA
549 ;L6 LDA @0101
550 ;HLT
551 
552 
553 ;PRUEBA AND ABS
554 ;L0 LDA #%000111
555 ;L1 STA @0300
556 ;L2 LDA #%111000
557 ;L3 ORA @0300
558 
559 ;PRUEBA SUB ABS
560 ;L0 LDA #1
561 ;L1 STA @0300
562 ;L2 INA
563 ;L3 SUB @0300
564 
565 ;PRUEBA ADD ABS
566 ;L0 LDA #1
567 ;L1 STA @0300
568 ;L2 INA
569 ;L3 ADD @0300
570 
571 ;PRUEBA DE STA ABS
572 ;L0 LDA #1
573 ;L1 STA @0300
574 ;L2 INA
575 ;L3 LDA @0300
576 
577 ;L0 LDA #01
578 ;L1 ADD @0001
579 
580 ;L0 LDA #63
581 ;L1 ORA #%101001
582 
583 ; PRUEBA DE BCC
584 ;L0 LDA #0
585 ;L1 INA
586 ;L2 BCC L0
587 ;L3 LDA #1
588 
589 
590 ; PRUEBA DE BNE
591 ;L SEC
592 ;L0 CLC
593 ;L1 LDA #0
594 ;L2 INA
595 ;L6 BNE L2
596 ;L4 INA
597 ;L5 LDA #1
598 
599 ; PRUEBA DE BEQ
600 ;L SEC
601 ;L0 CLC
602 ;L1 LDA #0
603 ;L6 BEQ L1
604 ;L4 INA
605 ;L5 LDA #1
606 
607 ;PRUEBA DE LDA INMEDIATA
608 ;L1 LDA #1
609 ;L2 LDA #2
610 ;L3 LDA #3
611 ;L4 LDA #4
612 ;L5 LDA #5
613 
614 ;PRUEBA DE SUB Y ADD INMEDIATAS
615 ;L0 LDA #0
616 ;L1 LDA #63
617 ;L2 SUB #62
618 ;L3 SUB #1
619 ;L4 ADD #1
620 ;L5 ADD #1
621 
622 ;K3 BNE K3
623 ;K5 BNE K3
624 ;K1 SEC
625 ;K2 SEC
626 ;BNE K1
627 ;K3 BNE K3
628 ;K5 BNE K3
629 ;L1 LDA (@0001)
630 ;BNE L1
631 ;L2 LDA @0002
632 ;L3 LDA @0002
633 ;BNE L1
634 ;L1 LDA @0001
635 
636 ;LDA LALA1
637 ;LDA @0001
638 ;L1 LDA BIN
639 ;LDA OCT
640 ;LDA DEC
641 ;LDA HEX
642 ;L1 LDA HEX
643 ;L2 LDA #HEX
644 ;LDA #HEX
645 ;BNE L3
646 ;BMI L1
647 ;LOOP1 BNE L1
648 ;L4 BMI L2
649 ;LDA (BIN)
650 ;LDA (OCT)
651 ;LDA (DEC)
652 ;LDA (HEX)
653 
654 ;LDA %1010
655 ;LDA @12
656 ;LDA 10
657 ;LDA $0A
658 ;LDA (%1010)
659 ;LDA (@12)
660 ;LDA (10)
661 ;LDA ($0A)
662 
663 ;LDA #%1010
664 ;LDA #@12
665 ;LDA #10
666 ;LDA $0A
667 ;LDA #BIN
668 ;LDA #OCT
669 ;LDA #DEC
670 ;LDA #HEX
671 
672 ;IMP SEC
673 ;ACU CLA
674 ;CTR TPA
675 
676 ;INP %1010
677 ;INP @12
678 ;INP 10
679 ;INP $0A
680 ;INP BIN
681 ;INP OCT
682 ;INP DEC
683 ;INP HEX
684 
685 
686 ;LDA %111
687 ;L2 LDA (LALA1)
688 ;L3 LDA (%01)
689 ;LDA (@0001)
690 ;BNE L2
691 ;BMI L3
692 ;LABEL BNE LALA2
693 ;LALA3 BNE LABEL
694 ;BNE LABEL
695 ;BMI LALA2
696 ;LOOP1 CPA
697 ;INA
698 ;ROR
699 ;NOP
700 ;INP LALA1
701 ;L1 INP LALA2
702 ;LABEL LDA (LALA1)
703 ;BNE LABEL
704 ;LABEL XXX LALA1
705 ;LABEL LDA @0001
706 ;LAB1 LDA PERRO
707 ;BNE LABEL
708 ;L1 BNE LALA
709 ;LALA LDA #01
710 ;LDA #$A
711 ;LDA #LABEL
712 ;LABEL LDA #@07
713 ;LABEL1 LDA #@07
714 ;BNE LABEL1
715 ;INP $FF
716 ;OUT %100
717 ;HLT
718 
719 
720 ;LDA #0
721 ;HLT
722 ;HLT
723 ;HLT
724 ;LDA #7
725 ;LDA #7
726 ;LDA #7
727 ;HLT
728 
729 ;BEQ JUMP1
730 ;LDA (@1000)
731 ;SEC
732 ;CLA
733 ;TPA
734 ;INP @77
735 
