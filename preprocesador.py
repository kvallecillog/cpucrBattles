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


def instruction_checker(data_list, lines_raw_list):
    ##################################################################################################################
    # Instruction checker analiza si la instruccion ingresada esta dentro del conjunto de instrucciones de la CPUCR.
    # Las instruciones son validas en mayuscula o en minuscula,
    ##################################################################################################################
    checked_inst_file_name = 'checked_inst_file_name.ASM'
    checked_inst_file = open(checked_inst_file_name, 'w+')
    #(\s??|@??)
    regex_inst_abs = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\@)[0-7]{1,4}$', re.IGNORECASE)
    regex_inst_ind = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\()(\@)[0-7]{1,4}(\))$', re.IGNORECASE)
    regex_inst_rel = re.compile(r'^(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)$', re.IGNORECASE)
    regex_inst_acum = re.compile(r'^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
    regex_inst_ctrl = re.compile(r'^(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)$', re.IGNORECASE)
    regex_inst_inm = re.compile(r'\b^(LDA|ADD|SUB|AND|ORA)\b(\#)[0-7]{1,2}$', re.IGNORECASE)
    regex_inst_imp = re.compile(r'^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
    regex_inst_io = re.compile(r'^(INP|OUT)$', re.IGNORECASE)


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
