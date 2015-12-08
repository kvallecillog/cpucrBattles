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
28 BNE L1+1
29 L1 INA
30 HLT ; INSTRUCCION DE DETENCION.
31 ;=============================================================
32 
33 ;=============================================================
34 ;#2 PRUEBA DE INSTRUCCION ADD INMEDIATA.
35 ;=============================================================
36 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
37 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
38 ;BIN ADD #%000010 ; ADD CON ARGUMENTO BINARIO.
39 ;OCT ADD #@02 ; ADD CON ARGUMENTO OCTACL.
40 ;DEC ADD #2 ; ADD CON ARGUMENTO DECIMAL.
41 ;HEX ADD #$02 ; ADD CON ARGUMENTO HEXADECIMAL.
42 ;HLT ; INSTRUCCION DE DETENCION.
43 ;=============================================================
44 
45 ;=============================================================
46 ;#3 PRUEBA DE INSTRUCCION SUB INMEDIATA.
47 ;=============================================================
48 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
49 ;L1 LDA #10 ; LDA CON ARGUMENTO DECIMAL.
50 ;BIN SUB #%000010 ; SUB CON ARGUMENTO BINARIO.
51 ;OCT SUB #@02 ; SUB CON ARGUMENTO OCTACL.
52 ;DEC SUB #2 ; SUB CON ARGUMENTO DECIMAL.
53 ;HEX SUB #$02 ; SUB CON ARGUMENTO HEXADECIMAL.
54 ;HLT ; INSTRUCCION DE DETENCION.
55 ;=============================================================
56 
57 ;=============================================================
58 ;#4 PRUEBA DE INSTRUCCION AND INMEDIATA.
59 ;=============================================================
60 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
61 ;L1 LDA #%111111 ; LDA CON ARGUMENTO DECIMAL.
62 ;BIN AND #%000111 ; AND CON ARGUMENTO BINARIO.
63 ;OCT AND #@07 ; AND CON ARGUMENTO OCTACL.
64 ;DEC AND #3 ; AND CON ARGUMENTO DECIMAL.
65 ;HEX AND #$01 ; AND CON ARGUMENTO HEXADECIMAL.
66 ;HLT ; INSTRUCCION DE DETENCION.
67 ;=============================================================
68 
69 ;=============================================================
70 ;#5 PRUEBA DE INSTRUCCION ORA INMEDIATA.
71 ;=============================================================
72 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
73 ;L1 LDA #%101000 ; LDA CON ARGUMENTO DECIMAL.
74 ;BIN ORA #%000101 ; ORA CON ARGUMENTO BINARIO.
75 ;OCT ORA #@20 ; ORA CON ARGUMENTO OCTACL.
76 ;DEC ORA #2 ; ORA CON ARGUMENTO DECIMAL.
77 ;HEX ORA #$00 ; ORA CON ARGUMENTO HEXADECIMAL.
78 ;HLT ; INSTRUCCION DE DETENCION.
79 ;=============================================================
80 
81 ;***********************************************************************************************************************
82 
83 
84 ;***********************************************************************************************************************
85 ; INSTRUCCIONES ABSOLUTAS
86 ;***********************************************************************************************************************
87 
88 ;=============================================================
89 ;#6 PRUEBA DE INSTRUCCION LDA ABSOLUTA.
90 ;=============================================================
91 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
92 ;L1 LDA @01 ; LDA ABSOLUTO.
93 ;HLT ; INSTRUCCION DE DETENCION.
94 ;=============================================================
95 
96 ;=============================================================
97 ;#7 PRUEBA DE INSTRUCCION STA ABSOLUTA.
98 ;=============================================================
99 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
100 ;L1 LDA #7 ; LDA INMEDIATO.
101 ;L2 STA @0020 ; STA ABSOLUTO.
102 ;L3 ADD #1 ; LDA INMEDIATO.
103 ;L4 LDA @0020 ; LDA ABSOLUTO.
104 ;HLT ; INSTRUCCION DE DETENCION.
105 ;=============================================================
106 
107 ;=============================================================
108 ;#8 PRUEBA DE INSTRUCCION ADD ABSOLUTA.
109 ;=============================================================
110 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
111 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
112 ;L2 STA @0020 ; STA ABSOLUTO.
113 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
114 ;L4 ADD @0020 ; ADD ABSOLUTA.
115 ;HLT ; INSTRUCCION DE DETENCION.
116 ;=============================================================
117 
118 ;=============================================================
119 ;#9 PRUEBA DE INSTRUCCION SUB ABSOLUTA.
120 ;=============================================================
121 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
122 ;L1 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
123 ;L2 STA @0020 ; STA ABSOLUTO.
124 ;L3 LDA #2 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
125 ;L4 SUB @0020 ; SUB ABSOLUTA.
126 ;HLT ; INSTRUCCION DE DETENCION.
127 ;=============================================================
128 
129 ;=============================================================
130 ;#10 PRUEBA DE INSTRUCCION AND ABSOLUTA.
131 ;=============================================================
132 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
133 ;L1 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
134 ;L2 STA @0020 ; STA ABSOLUTO.
135 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
136 ;L4 AND @0020 ; AND ABSOLUTAL.
137 ;HLT ; INSTRUCCION DE DETENCION.
138 ;=============================================================
139 
140 ;=============================================================
141 ;#12 PRUEBA DE INSTRUCCION ORA ABSOLUTA.
142 ;=============================================================
143 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
144 ;L1 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
145 ;L2 STA @0020 ; STA ABSOLUTO.
146 ;L3 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO BINARIO.
147 ;L4 ORA @0020 ; ORA ABSOLUTA.
148 ;HLT ; INSTRUCCION DE DETENCION.
149 ;=============================================================
150 
151 ;***********************************************************************************************************************
152 
153 ;***********************************************************************************************************************
154 ;#13 INSTRUCCIONES INDIRECTAS
155 ;***********************************************************************************************************************
156 ;=============================================================
157 ; PRUEBA DE INSTRUCCION LDA INDIRECTA.
158 ;=============================================================
159 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
160 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
161 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
162 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
163 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
164 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
165 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @0102.
166 ;L7 LDA (@0010) ; LDA INDIRECTO.
167 ;HLT ; INSTRUCCION DE DETENCION.
168 ;=============================================================
169 
170 ;=============================================================
171 ;#14 PRUEBA DE INSTRUCCION STA INDIRECTA.
172 ;=============================================================
173 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
174 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
175 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
176 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
177 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
178 ;L5 LDA #7 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
179 ;L6 STA (@0010) ; STA INDIRECTO, ESCRITURA DE 7 A @0102.
180 ;L7 ADD #1 ; ADD INMEDIATO CON ARGUMENTO DECIMAL.
181 ;L8 LDA @2211 ; LDA ABSOLUTO.
182 ;HLT ; INSTRUCCION DE DETENCION.
183 ;=============================================================
184 
185 ;=============================================================
186 ;#15 PRUEBA DE INSTRUCCION ADD INDIRECTA.
187 ;=============================================================
188 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
189 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
190 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
191 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
192 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
193 ;L5 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
194 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
195 ;L7 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
196 ;L8 ADD (@0010) ; ADD INDIRECTO, ESCRITURA DE 7 A @0102.
197 ;L9 LDA @2211 ; LDA ABSOLUTO.
198 ;HLT ; INSTRUCCION DE DETENCION.
199 ;=============================================================
200 
201 ;=============================================================
202 ;#16 PRUEBA DE INSTRUCCION SUB INDIRECTA.
203 ;=============================================================
204 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
205 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
206 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
207 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
208 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
209 ;L5 LDA #1 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
210 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
211 ;L7 LDA #6 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
212 ;L8 SUB (@0010) ; SUB INDIRECTO.
213 ;L9 LDA @2211 ; LDA ABSOLUTO.
214 ;HLT ; INSTRUCCION DE DETENCION.
215 ;=============================================================
216 
217 ;=============================================================
218 ;#17 PRUEBA DE INSTRUCCION AND INDIRECTA.
219 ;=============================================================
220 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
221 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
222 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
223 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
224 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
225 ;L5 LDA #%111111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
226 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
227 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
228 ;L8 AND (@0010) ; AND INDIRECTO.
229 ;L9 LDA @2211 ; LDA ABSOLUTO.
230 ;HLT ; INSTRUCCION DE DETENCION.
231 ;=============================================================
232 
233 ;=============================================================
234 ;#18 PRUEBA DE INSTRUCCION ORA INDIRECTA.
235 ;=============================================================
236 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
237 ;L1 LDA #@11 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
238 ;L2 STA @0010 ; STA ABSOLUTO, ESCRITURA A PB.
239 ;L3 LDA #@22 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
240 ;L4 STA @0011 ; STA ABSOLUTO, ESCRITURA A PA.
241 ;L5 LDA #%111000 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
242 ;L6 STA @2211 ; STA ABSOLUTO, ESCRITURA DE 7 A @2211
243 ;L7 LDA #%000111 ; LDA INMEDIATO CON ARGUMENTO DECIMAL.
244 ;L8 ORA (@0010) ; ORA INDIRECTO.
245 ;L9 LDA @2211 ; LDA ABSOLUTO.
246 ;HLT ; INSTRUCCION DE DETENCION.
247 ;=============================================================
248 ;***********************************************************************************************************************
249 
250 ;***********************************************************************************************************************
251 ; INSTRUCCIONES DE ACUMULADOR
252 ;***********************************************************************************************************************
253 
254 ;=============================================================
255 ;#19 PRUEBA DE INSTRUCCION CLA DE ACUMULADOR.
256 ;=============================================================
257 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
258 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
259 ;L2 CLA ; CLA DE ACUMULADOR, LIMPIA EL ACUMULADOR.
260 ;HLT ; INSTRUCCION DE DETENCION.
261 ;=============================================================
262 
263 ;=============================================================
264 ;#20 PRUEBA DE INSTRUCCION CPA DE ACUMULADOR.
265 ;=============================================================
266 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
267 ;L1 LDA #%111000 ; LDA CON ARGUMENTO DECIMAL.
268 ;L2 CPA ; CPA DE ACUMULADOR, COMPLEMENTA EL ACUMULADOR.
269 ;HLT ; INSTRUCCION DE DETENCION.
270 ;=============================================================
271 
272 ;=============================================================
273 ;#21 PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
274 ;=============================================================
275 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
276 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
277 ;L2 INA ; INA DE ACUMULADOR, INCREMENTA EL ACUMULADOR EN 1.
278 ;HLT ; INSTRUCCION DE DETENCION.
279 ;=============================================================
280 
281 ;=============================================================
282 ;#22 PRUEBA DE INSTRUCCION INA DE ACUMULADOR.
283 ;=============================================================
284 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
285 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
286 ;L2 DCA ; DCA DE ACUMULADOR, DECREMENTO EL ACUMULADOR EN 1.
287 ;HLT ; INSTRUCCION DE DETENCION.
288 ;=============================================================
289 
290 ;=============================================================
291 ;#23 PRUEBA DE INSTRUCCION ROL DE ACUMULADOR.
292 ;=============================================================
293 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
294 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
295 ;L2 ROL ; ROL DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA IZQ.
296 ;HLT ; INSTRUCCION DE DETENCION.
297 ;=============================================================
298 
299 ;=============================================================
300 ;#24 PRUEBA DE INSTRUCCION ROR DE ACUMULADOR.
301 ;=============================================================
302 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
303 ;L1 LDA #%111011 ; LDA CON ARGUMENTO DECIMAL.
304 ;L2 ROR ; ROR DE ACUMULADOR, ROTA EL ACUMULADOR HACIA LA DER.
305 ;HLT ; INSTRUCCION DE DETENCION.
306 ;=============================================================
307 ;***********************************************************************************************************************
308 
309 ;***********************************************************************************************************************
310 ; INSTRUCCIONES DE IMPLICITAS
311 ;***********************************************************************************************************************
312 
313 ;=============================================================
314 ;#25 PRUEBA DE INSTRUCCION SEC IMPLICITA.
315 ;=============================================================
316 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
317 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
318 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
319 ;HLT ; INSTRUCCION DE DETENCION.
320 ;=============================================================
321 
322 ;=============================================================
323 ;#26 PRUEBA DE INSTRUCCION CLC IMPLICITA.
324 ;=============================================================
325 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
326 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
327 ;L2 SEC ; SEC IMPLICITO, PONE EN ALTO LA BANDERA DE ACARREO.
328 ;L3 CLC ; CLC IMPLICITO, PONE EN BAJO LA BANDERA DE ACARREO.
329 ;HLT ; INSTRUCCION DE DETENCION.
330 ;=============================================================
331 
332 ;=============================================================
333 ;#27 PRUEBA DE INSTRUCCION SEI IMPLICITA.
334 ;=============================================================
335 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
336 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
337 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
338 ;HLT ; INSTRUCCION DE DETENCION.
339 ;=============================================================
340 
341 ;=============================================================
342 ;#28 PRUEBA DE INSTRUCCION CLI IMPLICITA.
343 ;=============================================================
344 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
345 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
346 ;L2 SEI ; SEI IMPLICITO, PONE EN ALTO LA BANDERA DE INTERRUP.
347 ;L3 CLI ; CLI IMPLICITO, PONE EN BAJO LA BANDERA DE INTERRUP.
348 ;HLT ; INSTRUCCION DE DETENCION.
349 ;=============================================================
350 ;***********************************************************************************************************************
351 
352 ;***********************************************************************************************************************
353 ; INSTRUCCIONES DE RELATIVAS
354 ;***********************************************************************************************************************
355 
356 ;=============================================================
357 ;#29 PRUEBA DE INSTRUCCION BEQ RELATIVA.
358 ;=============================================================
359 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
360 ;L1 LDA #0 ; LDA CON ARGUMENTO DECIMAL.
361 ;L2 BEQ L1 ; SALTA A L1 SI EL ACUMULADOR ES 0.
362 ;HLT ; INSTRUCCION DE DETENCION.
363 ;=============================================================
364 
365 ;=============================================================
366 ;#30 PRUEBA DE INSTRUCCION BNE RELATIVA.
367 ;=============================================================
368 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
369 ;L1 LDA #1 ; LDA CON ARGUMENTO DECIMAL.
370 ;L2 BNE L1 ; SALTA A L1 SI EL ACUMULADOR ES DISTINTO DE 0.
371 ;HLT ; INSTRUCCION DE DETENCION.
372 ;=============================================================
373 
374 ;=============================================================
375 ;#31 PRUEBA DE INSTRUCCION BCC RELATIVA.
376 ;=============================================================
377 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
378 ;L1 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
379 ;L2 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
380 ;L3 BCC L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 0.
381 ;HLT ; INSTRUCCION DE DETENCION.
382 ;=============================================================
383 
384 ;=============================================================
385 ;#32 PRUEBA DE INSTRUCCION BCS RELATIVA.
386 ;=============================================================
387 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
388 ;L1 CLC ; PONE EN BAJO LA BANDERA DE ACARREO.
389 ;L2 SEC ; PONE EN ALTO LA BANDERA DE ACARREO.
390 ;L3 BCS L2 ; SALTA A L1 SI LA BANDERA DE ACARREO ES 1.
391 ;HLT ; INSTRUCCION DE DETENCION.
392 ;=============================================================
393 
394 ;=============================================================
395 ;#33 PRUEBA DE INSTRUCCION BPL RELATIVA.
396 ;=============================================================
397 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
398 ;L1 LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
399 ;L2 BPL L1 ; SALTA A L1 SI EL ACUMULADOR ES POSITIVO.
400 ;HLT ; INSTRUCCION DE DETENCION.
401 ;=============================================================
402 
403 ;=============================================================
404 ;#34 PRUEBA DE INSTRUCCION BMI RELATIVA.
405 ;=============================================================
406 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
407 ;L1 LDA #%100000 ; LDA CON ARGUMENTO BINARIO NEGATIVO.
408 ;L2 BMI L1 ; SALTA A L1 SI EL ACUMULADOR ES NEGATIVO.
409 ;HLT ; INSTRUCCION DE DETENCION.
410 ;=============================================================
411 
412 ;=============================================================
413 ;#35 PRUEBA DE INSTRUCCION BVC RELATIVA.
414 ;=============================================================
415 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
416 ;L1 LDA #1 ; LDA CON ARGUMENTO BINARIO.
417 ;L2 ADD #1 ; SE AGREGA %001010 AL ACUMULADOR.
418 ;L3 BVC L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 0.
419 ;HLT ; INSTRUCCION DE DETENCION.
420 ;=============================================================
421 
422 ;=============================================================
423 ;#36 PRUEBA DE INSTRUCCION BVS RELATIVA.
424 ;=============================================================
425 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
426 ;L1 LDA #%010110 ; LDA CON ARGUMENTO BINARIO.
427 ;L2 ADD #%001010 ; SE AGREGA %001010 AL ACUMULADOR.
428 ;L3 BVS L1 ; SALTA A L1 SI LA BANDERA DE REBASE ES 1.
429 ;HLT ; INSTRUCCION DE DETENCION.
430 ;=============================================================
431 ;***********************************************************************************************************************
432 
433 ;***********************************************************************************************************************
434 ; INSTRUCCIONES DE CONTROL
435 ;***********************************************************************************************************************
436 
437 ;=============================================================
438 ;#37 PRUEBA DE INSTRUCCION HLT DE CONTROL.
439 ;=============================================================
440 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
441 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
442 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
443 ;=============================================================
444 
445 ;=============================================================
446 ;#38 PRUEBA DE INSTRUCCION NOP DE CONTROL.
447 ;=============================================================
448 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
449 ;NOP ; INSTRUCCION DE CONTROL NOP.
450 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
451 ;=============================================================
452 ;***********************************************************************************************************************
453 
454 ;***********************************************************************************************************************
455 ;#39 INSTRUCCIONES DE ENTRADA SALIDA
456 ;***********************************************************************************************************************
457 
458 ;=============================================================
459 ; PRUEBA DE INSTRUCCION OUT DE CONTROL.
460 ;=============================================================
461 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
462 ;BIN LDA #%000001 ; LDA CON ARGUMENTO BINARIO.
463 ;OUT @01 ; ESCRITURA AL PUERTO DE SALIDA CON DIRECCION @01.
464 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
465 ;=============================================================
466 
467 ;=============================================================
468 ;#40 PRUEBA DE INSTRUCCION INP DE CONTROL.
469 ;=============================================================
470 ;* = @0000 ; DECLARACION DEL PUNTERO DE POSICION.
471 ;BIN1 LDA #%000110 ; LDA CON ARGUMENTO BINARIO.
472 ;INP @00 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
473 ;INP @01 ; CARGA DEL PUERTO DE ENTRADA AL ACUMULADOR @01.
474 ;HLT ; INSTRUCCION DE CONTROL HTL, DETIENE LA EJECUCION.
475 ;=============================================================
