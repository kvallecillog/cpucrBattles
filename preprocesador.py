#!/usr/bin/env python

"""
Preprocessor .ASM files for CPUCR Architecture.

"""
__author__ = "Kenneth Vallecillo Gonzalez"
__copyright__ = "Copyright 2015"
__credits__ = ["Kenneth Vallecillo", "Lochi Yu", "Enrique Coen", "Diego Valverde"]
__license__ = "GPL"
__version__ = "1.0.1"
__maintainer__ = "Kenneth Vallecillo Gonzalez"
__email__ = "kvallecillog@gmail.com"
__status__ = "WIP: Working In Progress"

import re
from collections import Counter
###################################################################################################################
# '''
#     Clase FileProcessor
#     Descripcion:
#         La clase FileProcessor se encapsula los metodos y atributos del modulo preprocesador.
#         Metodos principales de la clase FileProcessor son:
#             1-delete_comments()
#             2-
#             3-
#     Entradas: Archivo original del .ASM
#     Salidas: Archivo procesado sin comentarios.
#     Fecha: 30/08/15.
#     Revision: 1.0.1
# '''
###################################################################################################################
'''Metodo para borrar comentarios del archivo raw. Contiene el archivo sin comentarios.
# Entradas: Archivo original del .ASM
# Salidas: Archivo procesado sin comentarios.
# Fecha: 30/08/15.
# Revision: 1.0.1
'''
###################################################################################################################
print("Inicio del analisis de sintaxis \n")


class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def lines_mapper(raw_file_name, lines_counter, data_list):
    raw_file = open(raw_file_name, 'r')
    lines_raw_file_lines = raw_file.readlines()
    lines_raw_file_name = 'lines_raw_file_name.ASM'
    lines_raw_file = open(lines_raw_file_name, 'w+')
    for line in lines_raw_file_lines:
        lines_counter += 1
        counter_string = str(lines_counter) + " " + line
        lines_raw_file.writelines(counter_string)
        data_list.append(counter_string)

    lines_raw_file.close()

    return data_list


def delete_blanks(data_list):
    delete_blanks_list = []
    deleted_blanks_file_name = 'deleted_blanks_file.ASM'
    non_blanks_file = open(deleted_blanks_file_name, 'w+')
    blank_regex = re.compile(r'^\d+\s+$')

    for x in range(0, len(data_list)):

        data_list_x = ''.join(data_list[x])
        blank_non_comment_regex = re.match(blank_regex, data_list_x)

        if not blank_non_comment_regex:
            non_blanks_file.writelines(data_list_x)
            delete_blanks_list.append(data_list_x)

    return delete_blanks_list


def delete_comments(data_list):
    # Se crea el objeto non_comments_file para escritura, este archivo contiene el .ASM sin comentarios.
    deleted_comments_file_name = 'deleted_comments_file.ASM'
    non_comments_file = open(deleted_comments_file_name, 'w+')
    comment_regex = re.compile(r'\s??;.*')
    # Se lee linea por linea el archivo ASM raw_file para determinar si la linea es un comentario o no.

    for x in range(0, len(data_list)):
        data_list_x = ''.join(data_list[x])
        data_list_x = re.sub(comment_regex, "", data_list_x)
        data_list[x] = data_list_x

    data_list = delete_blanks(data_list)
    for x in range(0, len(data_list)):
        data_list_x = ''.join(data_list[x])
        non_comments_file.writelines(data_list_x)

    non_comments_file.close()

    return data_list


def delete_spaces(data_list):
    # Se crea el objeto non_comments_file para escritura, este archivo contiene el .ASM sin comentarios.
    deleted_spaces_file_name = 'deleted_spaces_file.ASM'
    deleted_spaces_file = open(deleted_spaces_file_name, 'w+')
    spaces_regex = re.compile(r' +')
    for x in range(0, len(data_list)):
        data_list_x = "".join(data_list[x])
        data_list_x = re.sub(spaces_regex, ' ', data_list_x)
        data_list[x] = data_list_x
        deleted_spaces_file.writelines(data_list[x])

    return data_list


def init_checker(data_list, lines_raw_list):

    delete_init_list = []

    const_dic = dict()
    const_dic.clear()
    regex_pos_def = re.compile(r"^(\*)(\s)(\=)(\s)((\@)([0-7]{1,4}))$", re.IGNORECASE)
    regex_pos_assign = re.compile(r"^([a-zA-Z](\w{1,7})?)(\s)(\=)(\s)(\*)$", re.IGNORECASE)
    regex_init_res_words = re.compile(r"\b^((DBWRD)|(WRD))\b(\s)((\@)[0-7]{1,4})$", re.IGNORECASE)
    regex_init_const = re.compile(r"^([a-zA-Z](\w{1,7})?)(\s)(\=)(\s)((\@)([0-7]{1,4}))$", re.IGNORECASE)

    regex_res_word = re.compile(r"\b(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
                     DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
                     RTS|SEC|SEI|STA|SUB|TAP|TPA)\b", re.IGNORECASE)

    pos_cont_dec = 0
    pos_cont = False

    for x in range(0, len(data_list)):

        data_list_x = ''.join(data_list[x])
        num_line = data_list_x.split(" ")
        non_num_line = " ".join(num_line[1:len(num_line)])
        num_line_int = int(num_line[0])
        num_line_int_0 = int(num_line[0]) - 1
        data_source_line = lines_raw_list[num_line_int_0]
        data_source_line_list = data_source_line.split(" ")
        data_source_line_n = " ".join(data_source_line_list[1:len(data_source_line_list)])

        pos_def_match = re.match(regex_pos_def, non_num_line)
        pos_assign_match = re.match(regex_pos_assign, non_num_line)

        init_const_match = re.match(regex_init_const, non_num_line)
        init_res_words_match = re.match(regex_init_res_words, non_num_line)

        cont_res_word_dic = Counter(w.lower() for w in re.findall(regex_res_word, non_num_line))

        cont_res_word_int = sum(cont_res_word_dic.values())

        if pos_def_match or pos_assign_match or init_res_words_match or init_const_match:

            if cont_res_word_int == 0:

                if pos_def_match:

                    pos_cont_oct = pos_def_match.group(7)
                    pos_cont_dec = int(pos_cont_oct,8)
                    print("AK7 CONTADOR",pos_cont_dec)

                    print("OPERANDO!:", pos_def_match.group(7))
                    pos_cont = True
                    print("Position counter")
                    print(num_line_int, "|", non_num_line)

                elif pos_assign_match:

                    print("Constant assign")
                    print(num_line_int, "|", non_num_line)

                elif init_res_words_match:

                    print("DBWORD or WRD reserved words")
                    print(num_line_int, "|", non_num_line)

                elif init_const_match:

                    const_oct = init_const_match.group(8)
                    const_dec = int(const_oct,8)
                    const_dic[init_const_match.group(1)] = const_oct
                    print("AK7 CONSTANTE",const_dec,init_const_match.group(1))

                    print("kkkkkkkkkkkkk!:", init_const_match.group(8) )
                    print("Constant assign explicit")
                    print(num_line_int, "|", non_num_line)

            else:

                print("Error!:" + str(cont_res_word_int - 1) + " Reserved words as a label")
                print(num_line_int, "|", non_num_line)

        else:

            if pos_cont:
                #pos_cont_oct = pos_def_match.group(0)



                print("No match")
                print(num_line_int, "|", non_num_line)
                delete_init_list.append(data_list_x)
            elif not pos_cont and (x == len(data_list)-1):

                print("Error: No position counter defined (Example, * = @0000)")
                print("Please define a position counter!")

    hash_init = []
    print("diccionario", const_dic)

    return hash_init, delete_init_list, pos_cont_dec, const_dic


def label_checker(data_list, lines_raw_list, hash_init, pos_cont_dec):
    print("Checking labels\n")

    cont_mem_pos = pos_cont_dec

    # Se identifica si se esta utilizando como etiqueta una palabra reservada.

    regex_macro = re.compile(r"\b^(MACRO|FINMAC)\b(\s)*.*", re.IGNORECASE)

    regex_res_word = re.compile(r"\b(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
                     DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
                     RTS|SEC|SEI|STA|SUB|TAP|TPA)\b", re.IGNORECASE)

    regex_label_abs_inst = re.compile(r'\b^([a-zA-Z](\w{1,7})?)\b(\s)\b(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(((\@)[0-7]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',re.IGNORECASE)
    regex_inst_abs = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(((\@)[0-7]{1,4})|([a-zA-Z](\w{1,7})?)(\+?)(\d*))$', re.IGNORECASE)

    regex_label_ind_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))(\))$',re.IGNORECASE)
    regex_inst_ind = re.compile(
        r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))(\))$',re.IGNORECASE)

    regex_label_inm_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)([0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',re.IGNORECASE)
    regex_inst_inm = re.compile(r'\b^(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)([0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',re.IGNORECASE)

    regex_label_io_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(INP|OUT)\b(\s)((\@)[0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)
    regex_inst_io = re.compile(r'\b^(INP|OUT)\b(\s)((\@)[0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)

    regex_label_rel_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s\b(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)\b\s([a-zA-Z](\w{1,7})?)$', re.IGNORECASE)
    regex_inst_rel = re.compile(r'\b^(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)\b(\s)([0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)

    regex_label_acum_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
    regex_inst_acum = re.compile(r'\b^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)\b$', re.IGNORECASE)

    regex_label_ctrl_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)$', re.IGNORECASE)
    regex_inst_ctrl = re.compile(r'\b^(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)\b$', re.IGNORECASE)

    regex_label_imp_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(SEC|CLC|SEI|CLI)$', re.IGNORECASE)
    regex_inst_imp = re.compile(r'\b^(SEC|CLC|SEI|CLI)\b$', re.IGNORECASE)

    for x in range(0, len(data_list)):

        print( "MEM position counter updating", cont_mem_pos)
        data_list_x = ''.join(data_list[x])
        num_line = data_list_x.split(" ")
        non_num_line = " ".join(num_line[1:len(num_line)])
        num_line_int = int(num_line[0])
        num_line_int_0 = int(num_line[0]) - 1
        data_source_line = lines_raw_list[num_line_int_0]
        data_source_line_list = data_source_line.split(" ")
        data_source_line_n = " ".join(data_source_line_list[1:len(data_source_line_list)])

        macro_match = re.match(regex_macro, non_num_line)

        if not macro_match:

            cont_res_word_dic = Counter(w.lower() for w in re.findall(regex_res_word, non_num_line))
            cont_res_word_int = sum(cont_res_word_dic.values())

            if cont_res_word_int > 1:

                # raise Exception('Error: Reserved word as label')
                print("Error!:" + str(cont_res_word_int - 1) + " Reserved words as a label")
                print(num_line_int, "|", non_num_line)

            elif cont_res_word_int == 1:
                print("OK!: Labels and instrucions are valid")

                label_inst_abs_match = re.match(regex_label_abs_inst, non_num_line)
                inst_abs_match = re.match(regex_inst_abs, non_num_line)

                label_inst_ind_match = re.match(regex_label_ind_inst, non_num_line)
                inst_ind_match = re.match(regex_inst_ind, non_num_line)

                label_inst_inm_match = re.match(regex_label_inm_inst, non_num_line)
                inst_inm_match = re.match(regex_inst_inm, non_num_line)

                label_inst_io_match = re.match(regex_label_io_inst, non_num_line)
                inst_io_match = re.match(regex_inst_io, non_num_line)

                label_inst_rel_match = re.match(regex_label_rel_inst, non_num_line)
                inst_rel_match = re.match(regex_inst_rel, non_num_line)

                label_inst_acum_match = re.match(regex_label_acum_inst, non_num_line)
                inst_acum_match = re.match(regex_inst_acum, non_num_line)

                label_inst_ctrl_match = re.match(regex_label_ctrl_inst, non_num_line)
                inst_ctrl_match = re.match(regex_inst_ctrl, non_num_line)

                label_inst_imp_match = re.match(regex_label_imp_inst, non_num_line)
                inst_imp_match = re.match(regex_inst_imp, non_num_line)

                if inst_abs_match or inst_ind_match or inst_inm_match or inst_io_match \
                        or inst_rel_match or inst_acum_match or inst_ctrl_match or inst_imp_match:

                    print("Cumple con la condicion de instruccion")
                    if inst_abs_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento absoluto cuenta con 3 palabras.
                        cont_mem_pos += 3
                        print("OPERANDO!:", inst_abs_match.group(3))
                        print("Es una instruccion direccionamiento pura absoluto")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_ind_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento indirecto cuenta con 3 palabras.
                        cont_mem_pos += 3
                        # print("OPERANDO!:",inst_abs_match.group(3))
                        print("Es una instruccion direccionamiento pura indirecto")
                        print(num_line_int, "|", data_source_line_n)
                    if inst_inm_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento inmediato cuenta con 2 palabras.
                        cont_mem_pos += 2
                        # print("OPERANDO!:",inst_abs_match.group(3))
                        print("Es una instruccion direccionamiento pura inmediato")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_io_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento IO cuenta con 2 palabras.
                        cont_mem_pos += 2
                        # print("OPERANDO!:",inst_abs_match.group(3))
                        print("Es una instruccion direccionamiento pura entrada/salida")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_rel_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento relativo cuenta con 2 palabras.
                        cont_mem_pos += 2

                        # cont_mem_pos += VALOR DE ETIQUETA

                        # print("OPERANDO!:",inst_abs_match.group(3))
                        print("Es una instruccion direccionamiento pura relativo")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_acum_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento acumulador cuenta con 1 palabra.
                        cont_mem_pos += 1
                        # print("OPERANDO!:",inst_abs_match.group(1))
                        print("Es una instruccion direccionamiento pura acumulador")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_ctrl_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento control cuenta con 1 palabra.
                        cont_mem_pos += 1
                        # print("OPERANDO!:",inst_abs_match.group(2))
                        print("Es una instruccion direccionamiento pura control")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_imp_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento implicito cuenta con 1 palabra.
                        cont_mem_pos += 1
                        # print("OPERANDO!:",inst_abs_match.group(1))
                        print("Es una instruccion direccionamiento pura implicito")
                        print(num_line_int, "|", data_source_line_n)

                else:

                    if label_inst_abs_match or label_inst_ind_match or \
                            label_inst_inm_match or label_inst_io_match \
                            or label_inst_rel_match or label_inst_acum_match \
                            or label_inst_ctrl_match or label_inst_imp_match:
                        print("Cumple con la condicion de etiqueta de 8 caracteres + instruccion")

                        if label_inst_abs_match:

                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento absoluto cuenta con 3 palabras.
                            cont_mem_pos += 3

                            print("OPERANDO!:", label_inst_abs_match.group(6))
                            print("Es una instruccion de direccionamiento absoluto")
                            print(num_line_int, "|", data_source_line_n)

                        if label_inst_ind_match:

                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento absoluto cuenta con 3 palabras.
                            cont_mem_pos += 3


                            print("Es una instruccion de direccionamiento indirecto")
                            print(num_line_int, "|", data_source_line_n)

                        if label_inst_inm_match:

                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento absoluto cuenta con 3 palabras.
                            cont_mem_pos += 2

                            print("Es una instruccion de direccionamiento inmediato")
                            print(num_line_int, "|", data_source_line_n)

                        if label_inst_io_match:

                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento absoluto cuenta con 3 palabras.
                            cont_mem_pos += 2

                            print("Es una instruccion de direccionamiento entrada/salida")
                            print(num_line_int, "|", data_source_line_n)

                        if label_inst_rel_match:

                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento absoluto cuenta con 3 palabras.
                            cont_mem_pos += 2

                            print("Es una instruccion de direccionamiento relativo")
                            print(num_line_int, "|", data_source_line_n)

                        if label_inst_acum_match:

                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento acumulador cuenta con 1 palabra.
                            cont_mem_pos += 1

                            print("Es una instruccion de direccionamiento acumulador")
                            print(num_line_int, "|", data_source_line_n)

                        if label_inst_ctrl_match:

                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento control cuenta con 1 palabra.
                            cont_mem_pos += 1

                            print("Es una instruccion de direccionamiento control")
                            print(num_line_int, "|", data_source_line_n)

                        if label_inst_imp_match:

                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento implicito cuenta con 1 palabra.
                            cont_mem_pos += 1

                            print("Es una instruccion de direccionamiento implicito")
                            print(num_line_int, "|", data_source_line_n)

                    else:
                        print("Error: No es un formato de etiqueta + instruccion valido.")
                        print(num_line_int, "|", data_source_line_n)

            else:
                print("Error!: no instruction in the line")
                print(num_line_int, "|", data_source_line_n)
        else:
            print("Error: Macro is not supported")
            print(num_line_int, "|", non_num_line)


def instruction_checker(data_list, lines_raw_list):
    ##################################################################################################################
    # Instruction checker analiza si la instruccion ingresada esta dentro del conjunto de instrucciones de la CPUCR.
    # Las instruciones son validas en mayuscula o en minuscula,
    ##################################################################################################################
    checked_inst_file_name = 'checked_inst_file_name.ASM'
    checked_inst_file = open(checked_inst_file_name, 'w+')

    # Direccionamiento absoluto validado sin etiquetas funcionales.
    regex_inst_abs = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\@)[0-7]{1,4}$', re.IGNORECASE)
    # Direccionamiento indirecto validado sin etiquetas funcionales.
    regex_inst_ind = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()(\@)[0-7]{1,4}(\))$', re.IGNORECASE)
    # Direccionamiento inmediato validado sin etiquetas funcionales.
    regex_inst_inm = re.compile(r'\b^(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)[0-7]{1,2}$', re.IGNORECASE)
    # Direccionamiento de entradas y salidas.
    regex_inst_io = re.compile(r'^(INP|OUT)\b(\s)(\@)[0-7]{1,2}$', re.IGNORECASE)
    # Falta la capacidad de etiquetas!
    regex_inst_rel = re.compile(r'^(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)$', re.IGNORECASE)
    regex_inst_acum = re.compile(r'^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
    regex_inst_ctrl = re.compile(r'^(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)$', re.IGNORECASE)
    regex_inst_imp = re.compile(r'^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)

    for x in range(0, len(data_list)):

        data_list_x = ''.join(data_list[x])
        num_line = data_list_x.split(" ")
        non_num_line = " ".join(num_line[1:len(num_line)])

        inst_ind_match = re.match(regex_inst_ind, non_num_line)
        inst_abs_match = re.match(regex_inst_abs, non_num_line)
        inst_rel_match = re.match(regex_inst_rel, non_num_line)
        inst_acum_match = re.match(regex_inst_acum, non_num_line)
        inst_ctrl_match = re.match(regex_inst_ctrl, non_num_line)
        inst_inm_match = re.match(regex_inst_inm, non_num_line)
        inst_imp_match = re.match(regex_inst_imp, non_num_line)
        inst_io_match = re.match(regex_inst_io, non_num_line)

        num_line_int = int(num_line[0]) - 1
        data_source_line = lines_raw_list[num_line_int]
        data_source_line_list = data_source_line.split(" ")
        data_source_line_n = " ".join(data_source_line_list[1:len(data_source_line_list)])

        if inst_ind_match or inst_abs_match or inst_rel_match or inst_acum_match \
                or inst_ctrl_match or inst_inm_match \
                or inst_imp_match or inst_io_match:

            print(x, bcolors.OKBLUE + "Ok: Instruccion valida en línea #" + num_line[
                0] + "->" + data_source_line_n + bcolors.ENDC)

            if inst_ind_match:
                print(x, "Es una instruccion de direccionamiento indirecto\n")

            if inst_abs_match:
                print(x, "Es una instruccion de direccionamiento absoluto\n")

            if inst_rel_match:
                print(x, "Es una instruccion de direccionamiento relativo\n")

            if inst_acum_match:
                print(x, "Es una instruccion de direccionamiento de acumulador\n")

            if inst_inm_match:
                print(x, "Es una instruccion de direccionamiento inmediato\n")

            if inst_ctrl_match:
                print(x, "Es una instruccion de direccionamiento de control\n")

            if inst_imp_match:
                print(x, "Es una instruccion de direccionamiento implicito\n")

            if inst_io_match:
                print(x, "Es una instruccion de direccionamiento entrada/salida\n")

        else:

            print(x, bcolors.FAIL + "Error: instruccion invalida en línea #" + num_line[
                0] + "->" + data_source_line_n + bcolors.ENDC)
