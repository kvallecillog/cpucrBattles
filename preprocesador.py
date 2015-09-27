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

#
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
print("Executing Preprocessor")


def open_file(input_file_name):

    output_file = open(input_file_name, 'w+')
    print("Opening files \n")
    return output_file


def lines_mapper(raw_file_name, lines_counter):
    #Se crea el file..
    raw_file = open(raw_file_name, 'r')
    lines_raw_file_lines = raw_file.readlines()
    lines_raw_file_name = 'lines_raw_file_name.ASM'
    lines_raw_file = open(lines_raw_file_name, 'w+')
    for line in lines_raw_file_lines:
        lines_counter += 1
        counter_string = str(lines_counter)+" "+line
        lines_raw_file.writelines(counter_string)

    lines_raw_file.close()

    return lines_raw_file_name

print("Lines printed")


def delete_blanks(lines_raw_file_name):
    lines_raw_file = open(lines_raw_file_name, 'r+')
    # Se obtienen las lineas del .ASM sin procesar.
    blanks_file_lines = lines_raw_file.readlines()
    # Se crea el objeto non_comments_file para escritura, este archivo contiene el .ASM sin comentarios.
    deleted_blanks_file_name = 'deleted_blanks_file_name.ASM'
    non_blanks_file = open(deleted_blanks_file_name, 'w+')

    # Se lee linea por linea el archivo ASM raw_file para determinar si la linea es un comentario o no.
    for line in blanks_file_lines:

        #Se buscan los comentarios en la linea actual del .ASM y se remplazan  por un string vacio.
        # Se buscan los comentarios en la linea actual del .ASM y se remplazan  por un string vacio.

        blank_regex = re.match(r'^\d+\s+$', line)

        if blank_regex:
            print("Blank line detected")
        else:
            non_blanks_file.writelines(line)

    non_blanks_file.close()

    return deleted_blanks_file_name


def delete_comments(deleted_blanks_file_name):

    non_blanks_file = open(deleted_blanks_file_name,'r')
    # Se obtienen las lineas del .ASM sin procesar.
    non_blanks_file = non_blanks_file.readlines()
    # Se crea el objeto non_comments_file para escritura, este archivo contiene el .ASM sin comentarios.
    deleted_comments_file_name = 'deleted_comments_file.ASM'
    non_comments_file = open(deleted_comments_file_name, 'w+')
    # Se crea el objeto list_of_comments_file para escritura, este archivo contiene el .ASM con solo comentarios.
    list_of_comments_name = 'list_of_comments.list'
    list_of_comments_file = open(list_of_comments_name, 'w+')

    comment_regex = re.compile(r';.*')
    # Se lee linea por linea el archivo ASM raw_file para determinar si la linea es un comentario o no.

    for line in non_blanks_file:

        # Se buscan los comentarios en la linea actual del .ASM y se remplazan  por un string vacio.

#        comment_line = line.split(" ")
        #print(num_line[0])
        # non_num_line = " ".join(num_line[1:len(num_line)])
        # non_num_line_list = non_num_line.split(" ")
        # print(non_num_line_list[0])

        line = re.sub(comment_regex, "", line)
        #lines = str(comment_line[3])

        non_blanks_file.writelines(line)

    non_comments_file.close()
    return non_blanks_file


def instruction_checker(non_blanks_file):

    # Se comprueban que las instrucciones ingresadas sean validas.

    # Se obtienen las lineas del .ASM sin lineas en blanco.
 #   checked_inst_file_name = 'checked_inst_file_name.ASM'
#    checked_inst_file = open(checked_inst_file_name, 'w')
    inst_file_lines = non_blanks_file.readlines()

    for line in inst_file_lines:

        #inst_regex = re.compile(r'(LDA)')

        num_line = line.split(" ")
        #print(num_line[0])
        non_num_line = " ".join(num_line[1:len(num_line)])
        non_num_line_list = non_num_line.split(" ")
        print(non_num_line_list[0])
        #inst_regex_match = re.match(inst_regex,non_num_line[1])
        #print("Instrucción invalida en línea: ", "#", num_line[0], "Instrucción ingresada: ", num_line[2])
        # print(num_line[6])
        # if inst_regex_match:
        #     print(num_line)
        # else:
        #     print("Instruccion invalida, error en línea")
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
