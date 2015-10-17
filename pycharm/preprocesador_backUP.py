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
        # num_line = data_list_x.split(" ")

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


def label_checker(data_list, lines_raw_list):
    print("Checking labels\n")

    # Se identifica si se esta utilizando como etiqueta una palabra reservada.

    regex_res_word = re.compile(r"\b(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
                     DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
                     RTS|SEC|SEI|STA|SUB|TAP|TPA)\b", re.IGNORECASE)

    regex_label_abs_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)((\@)[0-7]{1,4}|[a-zA-Z]\w{1,7})$', re.IGNORECASE)
    regex_inst_abs = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)((\@)[0-7]{1,4}|[a-zA-Z]\w{1,7})$', re.IGNORECASE)

    regex_label_ind_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|[a-zA-Z]\w{1,7})(\))$', re.IGNORECASE)
    regex_inst_ind = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|[a-zA-Z]\w{1,7})(\))$', re.IGNORECASE)

    regex_label_inm_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)[0-7]{1,2}$', re.IGNORECASE)
    regex_inst_inm = re.compile(r'\b^(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)[0-7]{1,2}$', re.IGNORECASE)

    regex_label_io_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(INP|OUT)\b(\s)(\@)[0-7]{1,2}$', re.IGNORECASE)
    regex_inst_io = re.compile(r'^(INP|OUT)\b(\s)(\@)[0-7]{1,2}$', re.IGNORECASE)

    regex_label_rel_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)$', re.IGNORECASE)
    regex_inst_rel = re.compile(r'^(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)$', re.IGNORECASE)

    regex_label_acum_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
    regex_inst_acum = re.compile(r'^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)

    regex_label_ctrl_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)$', re.IGNORECASE)
    regex_inst_ctrl = re.compile(r'^(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)$', re.IGNORECASE)

    regex_label_imp_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
    regex_inst_imp = re.compile(r'^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)


    for x in range(0, len(data_list)):

        data_list_x = ''.join(data_list[x])
        num_line = data_list_x.split(" ")
        non_num_line = " ".join(num_line[1:len(num_line)])
        num_line_int = int(num_line[0])
        num_line_int_0 = int(num_line[0]) - 1
        data_source_line = lines_raw_list[num_line_int_0]
        data_source_line_list = data_source_line.split(" ")
        data_source_line_n = " ".join(data_source_line_list[1:len(data_source_line_list)])

        cont_res_word_dic = Counter(w.lower() for w in re.findall(regex_res_word, non_num_line))
        print(cont_res_word_dic)
        cont_res_word_int = sum(cont_res_word_dic.values())

        if cont_res_word_int > 1:
            print("Error!:"+str(cont_res_word_int-1)+" Reserved words as a label")
            print(num_line_int,"|",non_num_line)

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
                    print("Es una instruccion direccionamiento absoluto")
                    print(num_line_int,"|", data_source_line_n)

            else:

                if label_inst_abs_match or label_inst_ind_match or \
                        label_inst_inm_match or label_inst_io_match \
                        or label_inst_rel_match or label_inst_acum_match \
                        or label_inst_ctrl_match or label_inst_imp_match:
                    print("Cumple con la condicion de etiqueta de 8 caracteres + instruccion")

                    if label_inst_abs_match:
                        print("Es una instruccion de direccionamiento absoluto")
                        print(num_line_int,"|", data_source_line_n)
                    if label_inst_ind_match:
                        print("Es una instruccion de direccionamiento indirecto")
                        print(num_line_int,"|", data_source_line_n)
                    if label_inst_inm_match:
                        print("Es una instruccion de direccionamiento inmediato")
                        print(num_line_int,"|", data_source_line_n)
                    if label_inst_io_match:
                        print("Es una instruccion de direccionamiento entrada/salida")
                        print(num_line_int,"|", data_source_line_n)
                    if label_inst_rel_match:
                        print("Es una instruccion de direccionamiento relativo")
                        print(num_line_int,"|", data_source_line_n)
                    if label_inst_acum_match:
                        print("Es una instruccion de direccionamiento acumulador")
                        print(num_line_int,"|", data_source_line_n)
                    if label_inst_ctrl_match:
                        print("Es una instruccion de direccionamiento control")
                        print(num_line_int,"|", data_source_line_n)
                    if label_inst_imp_match:
                        print("Es una instruccion de direccionamiento implicito")
                        print(num_line_int,"|", data_source_line_n)

                else:
                    print("Error: No es un formato de etiqueta + instruccion valido.")
                    print(num_line_int,"|", data_source_line_n)

        else:
            print("Error!: instruction in the line")
            print(num_line_int,"|", data_source_line_n)


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


   # #regex_label = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\@)[0-7]{1,4}$', re.IGNORECASE)
   #  # Los simbolos utilizados para representar etiquetas variables direcciones
   #  # y constantes pueden tener hasta 8 caracteres alfanumericos siempre que
   #  #  el primero sea una letra.
   #
   #  regex_abs_ins_1 = re.compile(r'^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)((\@)[0-7]{1,4})$', re.IGNORECASE)
   #
   #  regex_abs_ins_2 = re.compile(r'^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)([a-zA-Z](\w{1,7})?)$', re.IGNORECASE)
   #
   #  regex_abs_ins_3 = re.compile(r'^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)([a-zA-Z](\w{1,7})?)(\+)(\d*)$', re.IGNORECASE)
   #
   #  regex_abs_ins_4 = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)((\@)[0-7]{1,4})$', re.IGNORECASE)
   #
   #  regex_abs_ins_5 = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)([a-zA-Z](\w{1,7})?)$', re.IGNORECASE)
   #
   #  regex_abs_ins_6 = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)([a-zA-Z](\w{1,7})?)(\+)(\d*)$', re.IGNORECASE)
   #
   #  regex_res_word_end = re.compile(r'^.*\s(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
   #                   DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
   #                   RTS|SEC|SEI|STA|SUB|TAP|TPA)\s(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
   #                   DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
   #                   RTS|SEC|SEI|STA|SUB|TAP|TPA)(\+?)(\d*)', re.IGNORECASE)
   #
   #  regex_res_word_ini = re.compile(r'^(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
   #                   DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
   #                   RTS|SEC|SEI|STA|SUB|TAP|TPA)(\s)(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
   #                   DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
   #                   RTS|SEC|SEI|STA|SUB|TAP|TPA)(.*)', re.IGNORECASE)
   #
   #  regex_res_word = re.compile(r'.*(\b(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
   #                   DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
   #                   RTS|SEC|SEI|STA|SUB|TAP|TPA)\b){2,}', re.IGNORECASE)
   #
   #  # regex_abs_ins_1 = re.compile(r'^([a-zA-Z]\w{1,7})\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)((\@)[0-7]{1,4}|([a-zA-Z]\w{1,7}))$', re.IGNORECASE)
   #  #
   #  # regex_abs_ins_1 = re.compile(r'^([a-zA-Z]\w{1,7})\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)((\@)[0-7]{1,4}|([a-zA-Z]\w{1,7}))$', re.IGNORECASE)
   #  #
   #  #
   #  #
   #  #
   #  # regex_inst_test = re.compile(r'^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)((\@|\(|\#)?(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
   #  #                 DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
   #  #                 RTS|SEC|SEI|STA|SUB|TAP|TPA))$', re.IGNORECASE)
   #  #
   #  # regex_label_ind_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|[a-zA-Z]\w{1,7})(\))$', re.IGNORECASE)
   #  # regex_inst_ind = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|[a-zA-Z]\w{1,7})(\))$', re.IGNORECASE)
   #  #
   #  # regex_label_inm_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)[0-7]{1,2}$', re.IGNORECASE)
   #  # regex_inst_inm = re.compile(r'\b^(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)[0-7]{1,2}$', re.IGNORECASE)
   #  #
   #  # regex_label_io_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(INP|OUT)\b(\s)(\@)[0-7]{1,2}$', re.IGNORECASE)
   #  # regex_inst_io = re.compile(r'^(INP|OUT)\b(\s)(\@)[0-7]{1,2}$', re.IGNORECASE)
   #  #
   #  # regex_label_rel_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)$', re.IGNORECASE)
   #  # regex_inst_rel = re.compile(r'^(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)$', re.IGNORECASE)
   #  #
   #  # regex_label_acum_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
   #  # regex_inst_acum = re.compile(r'^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
   #  #
   #  # regex_label_ctrl_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)$', re.IGNORECASE)
   #  # regex_inst_ctrl = re.compile(r'^(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)$', re.IGNORECASE)
   #  #
   #  # regex_label_imp_inst = re.compile(r'^[a-zA-Z]\w{1,7}\s(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
   #  # regex_inst_imp = re.compile(r'^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
   #  #
   #  # regex_resword_ini = re.compile(r'\b^(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
   #  #                 DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
   #  #                 RTS|SEC|SEI|STA|SUB|TAP|TPA)\s.*', re.IGNORECASE)
   #  #
   #  # regex_resword_fin = re.compile(r'\b$((\()(LDA)(\)))', re.IGNORECASE)
   #
   #
   #  for x in range(0, len(data_list)):
   #
   #      data_list_x = ''.join(data_list[x])
   #      #print(data_list_x)
   #      num_line = data_list_x.split(" ")
   #      non_num_line = " ".join(num_line[1:len(num_line)])
   #      num_line_int = int(num_line[0])
   #      num_line_int_0 = int(num_line[0]) - 1
   #      data_source_line = lines_raw_list[num_line_int_0]
   #      data_source_line_list = data_source_line.split(" ")
   #      data_source_line_n = " ".join(data_source_line_list[1:len(data_source_line_list)])
   #
   #      match_abs_ins_1 = re.match(regex_abs_ins_1, non_num_line)
   #      match_abs_ins_2 = re.match(regex_abs_ins_2, non_num_line)
   #      match_abs_ins_3 = re.match(regex_abs_ins_3, non_num_line)
   #      match_abs_ins_4 = re.match(regex_abs_ins_4, non_num_line)
   #      match_abs_ins_5 = re.match(regex_abs_ins_5, non_num_line)
   #      match_abs_ins_6 = re.match(regex_abs_ins_6, non_num_line)
   #
   #      match_res_word_ini = re.match(regex_res_word_ini, non_num_line)
   #      match_res_word_end = re.match(regex_res_word_end, non_num_line)
   #
   #      match_res_word = re.match(regex_res_word, non_num_line)
   #      cont_res_word_dic = Counter(w.lower() for w in re.findall(r"\b(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
   #                   DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
   #                   RTS|SEC|SEI|STA|SUB|TAP|TPA)\b", non_num_line))
   #      print(cont_res_word_dic)
   #      cont_res_word_int = sum(cont_res_word_dic.values())
   #
   #      if cont_res_word_int>1:
   #          print(cont_res_word_int,"Error!: Reserved word as label")
   #          print(non_num_line)
   #      elif cont_res_word_int==1:
   #          print(cont_res_word_int,"OK!: Labels and instrucions are valid")
   #          print(non_num_line)
   #      else:
   #          print(cont_res_word_int, "Error!: None instruction in the line")
   #          print(non_num_line)
   #
   #      # for key in cont_res_word.keys():
   #      #     print(cont_res_word.get(key))
   #
   #      # if match_abs_ins_1:
   #      #     print("match_abs_ins_1")
   #      #     print("Inst with numeric address")
   #      #     print(num_line_int, "|", non_num_line)
   #      # elif match_abs_ins_2:
   #      #     print("match_abs_ins_2")
   #      #     if not match_res_word:
   #      #         print("Inst with label address")
   #      #         print(num_line_int, "|", non_num_line)
   #      #     else:
   #      #         print("Invalid inst+label, using reserved end word")
   #      #         print(num_line_int, "|", bcolors.FAIL + non_num_line + bcolors.ENDC)
   #      #
   #      # elif match_abs_ins_3:
   #      #     print("match_abs_ins_3")
   #      #     if not match_res_word:
   #      #         print("Inst with label + num address")
   #      #         print(num_line_int, "|", non_num_line)
   #      #     else:
   #      #         print("Invalid inst+label, using reserved end word")
   #      #         print(num_line_int, "|", bcolors.FAIL + non_num_line + bcolors.ENDC)
   #      #
   #      # elif match_abs_ins_4:
   #      #     print("match_abs_ins_4")
   #      #     if not match_res_word:
   #      #         print("Label + Inst + num address")
   #      #         print(num_line_int, "|", non_num_line)
   #      #     else:
   #      #         print("Invalid label + inst, using reserved ini word")
   #      #         print(num_line_int, "|", bcolors.FAIL + non_num_line + bcolors.ENDC)
   #      #
   #      # elif match_abs_ins_5:
   #      #     print("match_abs_ins_5")
   #      #     if match_res_word:
   #      #         print("Invalid label + inst + label, using reserved ini word")
   #      #         print(num_line_int, "|", bcolors.FAIL + non_num_line + bcolors.ENDC)
   #      #     # elif match_res_word_end:
   #      #     #     print("Invalid label + inst + label, using reserved end word")
   #      #     #     print(num_line_int, "|", bcolors.FAIL + non_num_line + bcolors.ENDC)
   #      #     else:
   #      #         print("Label + Inst + Label")
   #      #         print(num_line_int, "|", non_num_line)
   #      #
   #      #
   #      # elif match_abs_ins_6:
   #      #     print("match_abs_ins_6")
   #      #     print("Label + Inst + Label + num adress")
   #      #     print(num_line_int, "|", non_num_line)
   #      #
   #      # else:
   #      #     print("Invalid instruction format")
   #      #     print(num_line_int, "|", bcolors.FAIL + non_num_line + bcolors.ENDC)
   #
   #      # label_inst_ind_match = re.match(regex_label_ind_inst, non_num_line)
   #      # inst_ind_match = re.match(regex_inst_ind, non_num_line)
   #      #
   #      # label_inst_inm_match = re.match(regex_label_inm_inst, non_num_line)
   #      # inst_inm_match = re.match(regex_inst_inm, non_num_line)
   #      #
   #      # label_inst_io_match = re.match(regex_label_io_inst, non_num_line)
   #      # inst_io_match = re.match(regex_inst_io, non_num_line)
   #      #
   #      # label_inst_rel_match = re.match(regex_label_rel_inst, non_num_line)
   #      # inst_rel_match = re.match(regex_inst_rel, non_num_line)
   #      #
   #      # label_inst_acum_match = re.match(regex_label_acum_inst, non_num_line)
   #      # inst_acum_match = re.match(regex_inst_acum, non_num_line)
   #      #
   #      # label_inst_ctrl_match = re.match(regex_label_ctrl_inst, non_num_line)
   #      # inst_ctrl_match = re.match(regex_inst_ctrl, non_num_line)
   #      #
   #      # label_inst_imp_match = re.match(regex_label_imp_inst, non_num_line)
   #      # inst_imp_match = re.match(regex_inst_imp, non_num_line)
   #      #
   #      # resword_match_ini = re.match(regex_resword_ini, non_num_line)
   #      # resword_match_fin = re.match(regex_resword_fin, non_num_line)
   #
   #
   #      # if label_inst_abs_111_match or inst_ind_match or inst_inm_match or inst_io_match\
   #      #         or inst_rel_match or inst_acum_match or inst_ctrl_match or inst_imp_match:
   #      #
   #      #     print("Cumple con la condicion de instruccion")
   #      #
   #      #     if not inst_abs_match_test:
   #      #         print("Es una instruccion valida")
   #      #         print(non_num_line)
   #      #
   #      #     else:
   #      #         print("Etiqueta invalida 1")
   #      #         print(non_num_line)
   #      #
   #      # elif inst_abs_match_test:
   #      #     print("Es una instruccion con etiqueta invalida")
   #      #     print(non_num_line)
   #      #     break
   #      #
   #      # else:
   #      #
   #      #     if not resword_match_ini:
   #      #
   #      #         if label_inst_abs_match or label_inst_ind_match or \
   #      #                 label_inst_inm_match or label_inst_io_match \
   #      #                 or label_inst_rel_match or label_inst_acum_match \
   #      #                 or label_inst_ctrl_match or label_inst_imp_match:
   #      #             print("Cumple con la condicion de etiqueta de 8 caracteres + instruccion")
   #      #
   #      #             if label_inst_abs_match:
   #      #                 print("Es una instruccion de direccionamiento absoluto")
   #      #                 print(non_num_line)
   #      #             if label_inst_ind_match:
   #      #                 print("Es una instruccion de direccionamiento indirecto")
   #      #                 print(non_num_line)
   #      #             if label_inst_inm_match:
   #      #                 print("Es una instruccion de direccionamiento inmediato")
   #      #                 print(non_num_line)
   #      #             if label_inst_io_match:
   #      #                 print("Es una instruccion de direccionamiento entrada/salida")
   #      #                 print(non_num_line)
   #      #             if label_inst_rel_match:
   #      #                 print("Es una instruccion de direccionamiento relativo")
   #      #                 print(non_num_line)
   #      #             if label_inst_acum_match:
   #      #                 print("Es una instruccion de direccionamiento acumulador")
   #      #                 print(non_num_line)
   #      #             if label_inst_ctrl_match:
   #      #                 print("Es una instruccion de direccionamiento control")
   #      #                 print(non_num_line)
   #      #             if label_inst_imp_match:
   #      #                 print("Es una instruccion de direccionamiento implicito")
   #      #                 print(non_num_line)
   #      #
   #      #         else:
   #      #             print("Error: No es un formato de etiqueta + instruccion valido.")
   #      #             print(non_num_line)
   #      #     else:
   #      #         print("Error: Palabra reservada utilizada como etiqueta.")
   #      #         print(non_num_line)


