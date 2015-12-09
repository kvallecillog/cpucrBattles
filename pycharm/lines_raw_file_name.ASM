1 
2 ;***********************************************************************************************************************
3 ; INSTRUCCIONES INMEDIATAS
4 ;***********************************************************************************************************************
5 
6 ;=============================================================
7 ;#1  PRUEBA DE INSTRUCCION LDA INMEDIATA.
8 ;=============================================================
9 * = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
10 CONST = @0000
11 ;CONST2 = 10
12 ;CONST3 = %00001
13 ;CONST4 = $A
14 ;ABS LDA @0000
15 ;BAS LDA CONST1
16 ;L1 INP CONST1
17 ;BUN LDA (CONST2)
18 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
19 ;OCT LDA #@02 ; LDA CON ARGUMENTO OCTAL.
20 ;HEX LDA #$03 ; LDA CON ARGUMENTO HEXADECIMAL.
21 ;DEC LDA #4 ; LDA CON ARGUMENTO DECIMAL.
22 ;L1 BNE L3+1
23 ;L3 INA
24 ;L1 SEC
25 ;L4 NOP
26 ;L6 CLA
27 ;INP CONST+1
28 L BNE @03
29 L1 INA
30 ;LDA CONST
31 ;BNE 14
32 HLT ; INSTRUCCION DE DETENCION.
33 ;=============================================================
34 
35 ;=============================================================
36 ;#2 PRUEBA DE INSTRUCCION ADD INMEDIATA.
37 ;=============================================================
38 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
39 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
40 ;BIN ADD #%000010 ; ADD CON ARGUMENTO BINARIO.
41 ;OCT ADD #@02 ; ADD CON ARGUMENTO OCTACL.
42 ;DEC ADD #2 ; ADD CON ARGUMENTO DECIMAL.
43 ;HEX ADD #$02 ; ADD CON ARGUMENTO HEXADECIMAL.
44 ;HLT ; INSTRUCCION DE DETENCION.
45 ;=============================================================
46 
47 ;=============================================================
48 ;#3 PRUEBA DE INSTRUCCION SUB INMEDIATA.
49 ;=============================================================
50 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
51 ;L1 LDA #10 ; LDA CON ARGUMENTO DECIMAL.
52 ;BIN SUB #%000010 ; SUB CON ARGUMENTO BINARIO.
53 ;OCT SUB #@02 ; SUB CON ARGUMENTO OCTACL.
54 ;DEC SUB #2 ; SUB CON ARGUMENTO DECIMAL.
55 ;HEX SUB #$02 ; SUB CON ARGUMENTO HEXADECIMAL.
56 ;HLT ; INSTRUCCION DE DETENCION.
57 ;=============================================================
58 
59 ;=============================================================
60 ;#4 PRUEBA DE INSTRUCCION AND INMEDIATA.
61 ;=============================================================
62 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
63 ;L1 LDA #%111111 ; LDA CON ARGUMENTO DECIMAL.
64 ;BIN AND #%000111 ; AND CON ARGUMENTO BINARIO.
65 ;OCT AND #@07 ; AND CON ARGUMENTO OCTACL.
66 ;DEC AND #3 ; AND CON ARGUMENTO DECIMAL.
67 ;HEX AND #$01 ; AND CON ARGUMENTO HEXADECIMAL.
68 ;HLT ; INSTRUCCION DE DETENCION.
69 ;=============================================================
70 
71 ;=============================================================
72 ;#5 PRUEBA DE INSTRUCCION ORA INMEDIATA.
73 ;=============================================================
74 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
75 ;L1 LDA #%101000 ; LDA CON ARGUMENTO DECIMAL.
76 ;BIN ORA #%000101 ; ORA CON ARGUMENTO BINARIO.
77 ;OCT ORA #@20 ; ORA CON ARGUMENTO OCTACL.
78 ;DEC ORA #2 ; ORA CON ARGUMENTO DECIMAL.
79 ;HEX ORA #$00 ; ORA CON ARGUMENTO HEXADECIMAL.
80 ;HLT ; INSTRUCCION DE DETENCION.
81 ;=============================================================
82 
83 ;***********************************************************************************************************************
84 
85 
86 ;***********************************************************************************************************************
87 ; INSTRUCCIONES ABSOLUTAS
88 ;***********************************************************************************************************************
89 
90 ;=============================================================
91 ;#6 PRUEBA DE INSTRUCCION LDA ABSOLUTA.
92 ;=============================================================
93 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
94 ;L1 LDA @01 ; LDA ABSOLUTO.
95 ;HLT ; INSTRUCCION DE DETENCION.
96 ;=============================================================
97 
98 ;=============================================================
99 ;#7 PRUEBA DE INSTRUCCION STA ABSOLUTA.
100 ;=============================================================
101 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
102 ;L1 LDA #7 ; LDA INMEDIATO.
103 ;L2 STA @0020 ; STA ABSOLUTO.
104 ;L3 ADD #1 ; LDA INMEDIATO.
105 ;L4 LDA @0020 ; LDA ABSOLUTO.
106 ;HLT ; INSTRUCCION DE DETENCION.
107 ;=============================================================
108 
109 ;=============================================================
110 ;#8 PRUEBA DE INSTRUCCION ADD ABSOLUTA.
111 ;=============================================================
112 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
113 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
114 ;L2 STA @0020 ; STA ABSOLUTO.
115 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
116 ;L4 ADD @0020 ; ADD ABSOLUTA.
117 ;HLT ; INSTRUCCION DE DETENCION.
118 ;=============================================================
119 
120 ;=============================================================
121 ;#9 PRUEBA DE INSTRUCCION SUB ABSOLUTA.
122 ;=============================================================
123 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
124 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
125 ;L2 STA @0020 ; STA ABSOLUTO.
126 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
127 ;L4 SUB @0020 ; SUB ABSOLUTA.
128 ;HLT ; INSTRUCCION DE DETENCION.
129 ;=============================================================
130 
131 ;=============================================================
132 ;#10 PRUEBA DE INSTRUCCION AND ABSOLUTA.
133 ;=============================================================
134 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
135 ;L1 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
136 ;L2 STA @0020 ; STA ABSOLUTO.
137 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
138 ;L4 AND @0020 ; AND ABSOLUTAL.
139 ;HLT ; INSTRUCCION DE DETENCION.
140 ;=============================================================
141 
142 ;=============================================================
143 ;#12 PRUEBA DE INSTRUCCION ORA ABSOLUTA.
144 ;=============================================================
145 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
146 ;L1 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
147 ;L2 STA @0020 ; STA ABSOLUTO.
148 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
149 ;L4 ORA @0020 ; ORA ABSOLUTA.
150 ;HLT ; INSTRUCCION DE DETENCION.
151 ;=============================================================
152 
153 ;***********************************************************************************************************************
154 
155 ;***********************************************************************************************************************
156 ;#13 INSTRUCCIONES INDIRECTAS
157 ;***********************************************************************************************************************
158 ;=============================================================
159 ; PRUEBA DE INSTRUCCION LDA INDIRECTA.
160 ;=============================================================
161 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
162 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
163 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
164 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
165 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
166 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
167 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @0102.
168 ;L7 LDA (@0010) ; LDA INDIRECTO.
169 ;HLT ; INSTRUCCION DE DETENCION.
170 ;=============================================================
171 
172 ;=============================================================
173 ;#14 PRUEBA DE INSTRUCCION STA INDIRECTA.
174 ;=============================================================
175 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
176 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
177 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
178 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
179 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
180 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
181 ;L6 STA (@0010) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
182 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
183 ;L8 LDA @2211 ; LDA ABSOLUTO.
184 ;HLT ; INSTRUCCION DE DETENCION.
185 ;=============================================================
186 
187 ;=============================================================
188 ;#15 PRUEBA DE INSTRUCCION ADD INDIRECTA.
189 ;=============================================================
190 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
191 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
192 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
193 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
194 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
195 ;L5 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
196 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
197 ;L7 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
198 ;L8 ADD (@0010) ; ADD INDIRECTO, ESCRITURA DE 7 A @0102.
199 ;L9 LDA @2211 ; LDA ABSOLUTO.
200 ;HLT ; INSTRUCCION DE DETENCION.
201 ;=============================================================
202 
203 ;=============================================================
204 ;#16 PRUEBA DE INSTRUCCION SUB INDIRECTA.
205 ;=============================================================
206 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
207 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
208 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
209 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
210 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
211 ;L5 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
212 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
213 ;L7 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
214 ;L8 SUB (@0010) ; SUB INDIRECTO.
215 ;L9 LDA @2211 ; LDA ABSOLUTO.
216 ;HLT ; INSTRUCCION DE DETENCION.
217 ;=============================================================
218 
219 ;=============================================================
220 ;#17 PRUEBA DE INSTRUCCION AND INDIRECTA.
221 ;=============================================================
222 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
223 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
224 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
225 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
226 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
227 ;L5 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
228 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
229 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
230 ;L8 AND (@0010) ; AND INDIRECTO.
231 ;L9 LDA @2211 ; LDA ABSOLUTO.
232 ;HLT ; INSTRUCCION DE DETENCION.
233 ;=============================================================
234 
235 ;=============================================================
236 ;#18 PRUEBA DE INSTRUCCION ORA INDIRECTA.
237 ;=============================================================
238 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
239 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
240 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
241 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
242 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
243 ;L5 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
244 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
245 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
246 ;L8 ORA (@0010) ; ORA INDIRECTO.
247 ;L9 LDA @2211 ; LDA ABSOLUTO.
248 ;HLT ; INSTRUCCION DE DETENCION.
249 ;=============================================================
250 ;***********************************************************************************************************************
251 
252 ;***********************************************************************************************************************
253 ; INSTRUCCIONES DE ACUMULADOR
254 ;***********************************************************************************************************************
255 
256 ;=============================================================
257 ;#19 PRUEBA DE INSTRUCCION CLA DE ACUMULADOR.
258 ;=============================================================
259 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
260 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
261 ;L2 CLA ; CLA DE ACUMULADOR, LIMPIA EL ACUMULADOR.
262 ;HLT ; INSTRUCCION DE DETENCION.
263 ;=============================================================
264 
265 ;=============================================================
266 ;#20 PRUEBA DE INSTRUCCION CPA DE ACUMULADOR.
267 ;=============================================================
268 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
269 ;L1 LDA #%111000 ; LDA CON ARGUMENTO DECIMAL.
270 ;L2 CPA ; CPA DE ACUMULADOR, COMPLEMENTA EL ACUMULADOR.
271 ;HLT ; INSTRUCCION DE DETENCION.
272 ;=============================================================
273 
274 ;=============================================================
275 ;#21 PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
276 ;=============================================================
277 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
278 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
279 ;L2 INA ; INA DE ACUMULADOR, INCREMENTA EL ACUMULADOR EN 1.
280 ;HLT ; INSTRUCCION DE DETENCION.
281 ;=============================================================
282 
283 ;=============================================================
284 ;#22 PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
285 ;=============================================================
286 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
287 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
288 ;L2 DCA ; DCA DE ACUMULADOR, DECREMENTO EL ACUMULADOR EN 1.
289 ;HLT ; INSTRUCCION DE DETENCION.
290 ;=============================================================
291 
292 ;=============================================================
293 ;#23 PRUEBA DE INSTRUCCION ROL DE ACUMULADOR.
294 ;=============================================================
295 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
296 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
297 ;L2 ROL ; ROL DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA IZQ.
298 ;HLT ; INSTRUCCION DE DETENCION.
299 ;=============================================================
300 
301 ;=============================================================
302 ;#24 PRUEBA DE INSTRUCCION ROR DE ACUMULADOR.
303 ;=============================================================
304 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
305 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
306 ;L2 ROR ; ROR DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA DER.
307 ;HLT ; INSTRUCCION DE DETENCION.
308 ;=============================================================
309 ;***********************************************************************************************************************
310 
311 ;***********************************************************************************************************************
312 ; INSTRUCCIONES DE IMPLICITAS
313 ;***********************************************************************************************************************
314 
315 ;=============================================================
316 ;#25 PRUEBA DE INSTRUCCION SEC IMPLICITA.
317 ;=============================================================
318 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
319 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
320 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
321 ;HLT ; INSTRUCCION DE DETENCION.
322 ;=============================================================
323 
324 ;=============================================================
325 ;#26 PRUEBA DE INSTRUCCION CLC IMPLICITA.
326 ;=============================================================
327 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
328 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
329 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
330 ;L3 CLC ; CLC IMPLICITO, PONE EN BAJO LA BANDERA DE ACARREO.
331 ;HLT ; INSTRUCCION DE DETENCION.
332 ;=============================================================
333 
334 ;=============================================================
335 ;#27 PRUEBA DE INSTRUCCION SEI IMPLICITA.
336 ;=============================================================
337 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
338 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
339 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
340 ;HLT ; INSTRUCCION DE DETENCION.
341 ;=============================================================
342 
343 ;=============================================================
344 ;#28 PRUEBA DE INSTRUCCION CLI IMPLICITA.
345 ;=============================================================
346 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
347 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
348 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
349 ;L3 CLI ; CLI IMPLICITO, PONE EN BAJO LA BANDERA DE INTERRUP.
350 ;HLT ; INSTRUCCION DE DETENCION.
351 ;=============================================================
352 ;***********************************************************************************************************************
353 
354 ;***********************************************************************************************************************
355 ; INSTRUCCIONES DE RELATIVAS
356 ;***********************************************************************************************************************
357 
358 ;=============================================================
359 ;#29 PRUEBA DE INSTRUCCION BEQ RELATIVA.
360 ;=============================================================
361 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
362 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
363 ;L2 BEQ L1 ; SALTA A L1 SI EL ACUMULADOR ES 0.
364 ;HLT ; INSTRUCCION DE DETENCION.
365 ;=============================================================
366 
367 ;=============================================================
368 ;#30 PRUEBA DE INSTRUCCION BNE RELATIVA.
369 ;=============================================================
370 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
371 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
372 ;L2 BNE L1 ; SALTA A L1 SI EL ACUMULADOR ES DISTINTO DE 0.
373 ;HLT ; INSTRUCCION DE DETENCION.
374 ;=============================================================
375 
376 ;=============================================================
377 ;#31 PRUEBA DE INSTRUCCION BCC RELATIVA.
378 ;=============================================================
379 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
380 ;L1 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
381 ;L2 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
382 ;L3 BCC L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 0.
383 ;HLT ; INSTRUCCION DE DETENCION.
384 ;=============================================================
385 
386 ;=============================================================
387 ;#32 PRUEBA DE INSTRUCCION BCS RELATIVA.
388 ;=============================================================
389 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
390 ;L1 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
391 ;L2 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
392 ;L3 BCS L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 1.
393 ;HLT ; INSTRUCCION DE DETENCION.
394 ;=============================================================
395 
396 ;=============================================================
397 ;#33 PRUEBA DE INSTRUCCION BPL RELATIVA.
398 ;=============================================================
399 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
400 ;L1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
401 ;L2 BPL L1 ; SALTA A L1 SI EL ACUMULADOR ES POSITIVO.
402 ;HLT ; INSTRUCCION DE DETENCION.
403 ;=============================================================
404 
405 ;=============================================================
406 ;#34 PRUEBA DE INSTRUCCION BMI RELATIVA.
407 ;=============================================================
408 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
409 ;L1 LDA #%100000 ; LDA CON ARGUMENTO BINARIO NEGATIVO.
410 ;L2 BMI L1 ; SALTA A L1 SI EL ACUMULADOR ES NEGATIVO.
411 ;HLT ; INSTRUCCION DE DETENCION.
412 ;=============================================================
413 
414 ;=============================================================
415 ;#35 PRUEBA DE INSTRUCCION BVC RELATIVA.
416 ;=============================================================
417 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
418 ;L1 LDA #1 ; LDA CON ARGUMENTO BINARIO.
419 ;L2 ADD #1 ; SE AGREGA %001010 AL ACUMULADOR.
420 ;L3 BVC L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 0.
421 ;HLT ; INSTRUCCION DE DETENCION.
422 ;=============================================================
423 
424 ;=============================================================
425 ;#36 PRUEBA DE INSTRUCCION BVS RELATIVA.
426 ;=============================================================
427 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
428 ;L1 LDA #%010110 ; LDA CON ARGUMENTO BINARIO.
429 ;L2 ADD #%001010 ; SE AGREGA %001010 AL ACUMULADOR.
430 ;L3 BVS L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 1.
431 ;HLT ; INSTRUCCION DE DETENCION.
432 ;=============================================================
433 ;***********************************************************************************************************************
434 
435 ;***********************************************************************************************************************
436 ; INSTRUCCIONES DE CONTROL
437 ;***********************************************************************************************************************
438 
439 ;=============================================================
440 ;#37 PRUEBA DE INSTRUCCION HLT DE CONTROL.
441 ;=============================================================
442 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
443 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
444 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
445 ;=============================================================
446 
447 ;=============================================================
448 ;#38 PRUEBA DE INSTRUCCION NOP DE CONTROL.
449 ;=============================================================
450 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
451 ;NOP ; INSTRUCCION DE CONTROL NOP.
452 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
453 ;=============================================================
454 ;***********************************************************************************************************************
455 
456 ;***********************************************************************************************************************
457 ;#39 INSTRUCCIONES DE ENTRADA SALIDA
458 ;***********************************************************************************************************************
459 
460 ;=============================================================
461 ; PRUEBA DE INSTRUCCION OUT DE CONTROL.
462 ;=============================================================
463 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
464 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
465 ;OUT @01 ; ESCRITURA AL PUERTO DE SALIDA CON DIRECCION @01.
466 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
467 ;=============================================================
468 
469 ;=============================================================
470 ;#40 PRUEBA DE INSTRUCCION INP DE CONTROL.
471 ;=============================================================
472 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
473 ;BIN1 LDA #%000110 ; LDA CON ARGUMENTO BINARIO.
474 ;INP @00 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
475 ;INP @01 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
476 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
477 ;=============================================================
