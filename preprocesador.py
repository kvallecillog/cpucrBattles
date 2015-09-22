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

    output_file = open(input_file_name, 'r')
    print("Opening files \n")
    return output_file


print("Deleting comments")


def delete_comments(comments_file, delete_comments_file_name, list_of_comments):
    # Se obtienen las lineas del .ASM sin procesar.
    comments_file_lines = comments_file.readlines()
    # Se crea el objeto non_comments_file para escritura, este archivo contiene el .ASM sin comentarios.
    non_comments_file = open(delete_comments_file_name, 'w')
    # Se crea el objeto list_of_comments_file para escritura, este archivo contiene el .ASM con solo comentarios.
    list_of_comments_file = open(list_of_comments, 'w')

    print("Creating delete_comments_file")

    # Se lee linea por linea el archivo ASM raw_file para determinar si la linea es un comentario o no.
    for line in comments_file_lines:

        # Se buscan los comentarios en la linea actual del .ASM y se remplazan  por un string vacio.
        comment_regex = re.compile(r';.*')
        line = re.sub(comment_regex, "", line)
        non_comments_file.writelines(line)

    # Se cierra el archivo original sin editar.
    #comments_file.close()
    # Se cierra el nuevo archivo sin comentarios
    #non_comments_file.close()
    # Se cierra el nuevo archivo de solo comentarios
    #list_of_comments_file.close()

    return non_comments_file
print("Comments were deleted")


def delete_blanks(deleted_comments_file, deleted_blanks_file_name):
    # Se obtienen las lineas del .ASM sin procesar.
    blanks_file_lines = deleted_comments_file.readlines()
    # Se crea el objeto non_comments_file para escritura, este archivo contiene el .ASM sin comentarios.
    non_blanks_file = open(deleted_blanks_file_name, 'w')

    print("Creating delete_comments_file")

    # Se lee linea por linea el archivo ASM raw_file para determinar si la linea es un comentario o no.
    for line in blanks_file_lines:

        #Se buscan los comentarios en la linea actual del .ASM y se remplazan  por un string vacio.
        # Se buscan los comentarios en la linea actual del .ASM y se remplazan  por un string vacio.
        blank_regex = re.match(r'^\s*$', line)

        if blank_regex:
            print("hola")
        else:
            non_blanks_file.writelines(line)

    return non_blanks_file
print("Comments were deleted")


def instruction_checker(deleted_blanks_file,instruction_hash,):
    # Se comprueban que las instrucciones ingresadas sean validas.
