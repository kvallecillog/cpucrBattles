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


def lines_mapper(raw_file_name, lines_counter, data_list):
    raw_file = open(raw_file_name, 'r')
    lines_raw_file_lines = raw_file.readlines()
    lines_raw_file_name = 'lines_raw_file_name.ASM'
    lines_raw_file = open(lines_raw_file_name, 'w+')
    for line in lines_raw_file_lines:
        lines_counter += 1
        counter_string = str(lines_counter)+" "+line
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
        #num_line = data_list_x.split(" ")

        if not blank_non_comment_regex:

            non_blanks_file.writelines(data_list_x)
            delete_blanks_list.append(data_list_x)

    return delete_blanks_list


def delete_comments(data_list):

    # Se crea el objeto non_comments_file para escritura, este archivo contiene el .ASM sin comentarios.
    deleted_comments_file_name = 'deleted_comments_file.ASM'
    non_comments_file = open(deleted_comments_file_name, 'w+')
    comment_regex = re.compile(r';.*')
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


def delete_spaces (data_list):
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

    # Se comprueban que las instrucciones ingresadas sean validas.
    # Se obtienen las lineas del .ASM sin lineas en blanco.
    checked_inst_file_name = 'checked_inst_file_name.ASM'
    checked_inst_file = open(checked_inst_file_name, 'w+')

    inst_regex = re.compile(r'(LDA)')
    for x in range(0, len(data_list)):

        data_list_x = ''.join(data_list[x])
        num_line = data_list_x.split(" ")
        non_num_line = " ".join(num_line[1:len(num_line)])
        inst_regex_match = re.match(inst_regex, non_num_line)

        num_line_int = int(num_line[0]) - 1
        data_source_line = lines_raw_list[num_line_int]
        data_source_line_list = data_source_line.split(" ")
        data_source_line_n = " ".join(data_source_line_list[1:len(data_source_line_list)])


        if not inst_regex_match:
            print("Instruccion invalida, error en línea", "#", num_line[0], "->", data_source_line_n)

    #print(lines_raw_list)
# AND
# BCC
# BCS
# BEQ
# BMI
# BNE
# BPL
# BVC
# BVS
# CLA
# CLC
# CLI
# CPA
# DCA
# HLT
# INA
# INP
# JMP
# JSR
# LDA
# NOP
# ORA
# OUT
# PHA
# PHS
# PLA
# PLS
# ROL
# ROR
# RTI
# RTS
# SEC
# SEI
# STA
# SUB
# TAP
# TPA
#
