#!/usr/bin/env python

"""
Preprocessor .ASM files for CPUCR Architecture.

"""
__author__ = "Kenneth Vallecillo Gonzalez"
__copyright__ = "Copyright 2015"
__credits__ = ["Kenneth Vallecillo","Lochi Yu", "Enrique Coen", "Diego Valverde"]
__license__ = "GPL"
__version__ = "1.0.1"
__maintainer__ = "Kenneth Vallecillo Gonzalez"
__email__ = "kvallecillog@gmail.com"
__status__ = "WIP: Working In Progress"

import re

class file_processor:

    # def __init__(self):
    #
    #     file.self=file


    ###################################################################################################################
    '''
    Metodo para borrar comentarios del archivo raw. Contiene el archivo sin comentarios.
    # Entradas: Archivo original del .ASM
    # Salidas: Archivo procesado sin comentarios.
    # Fecha: 30/08/15.
    # Revision: 1.0.1
    '''
    ###################################################################################################################

    def delete_comments(self):

        #Se crea el objeto raw_file para lectura que contiene el archivo .ASM sin procesar.
        raw_file=open('raw_file.ASM','r')
        #Se obtienen las lineas del .ASM sin procesar.
        raw_file_lines=raw_file.readlines()
        #Se crea el objeto non_comments_file para escritura, este archivo contiene el .ASM sin comentarios.
        non_comments_file=open('delete_comments_file.ASM','w')

        # Se lee linea por linea el archivo ASM raw_file para determinar si la linea es un comentario o no.
        for line in raw_file_lines:

            # Se escribe la linea leida en el nuevo archivo ASM non_comments_file.
            delete_comments_file.writelines(line)

            # Se buscan los comentarios en la linea actual del .ASM
            comment_regex=re.search(r';.*',line)

            # Si la linea actual es un comentario se elimina la linea del archivo non_comments_file.
            if comment_regex:

                # Si la linea inicia con ";" se elimina del archivo.
                new_line = ""
                line=line.replace(line,new_line)
                non_comments_file.writelines(line)
        # Se cierra el archivo original sin editar.
        raw_file.close()
        # Se cierra el nuevo archivo sin comentarios
        non_comments_file.close()

    ###################################################################################################################


    def main():

        File=File_processor()
        File.delete_comments()
        print("Fin de la ejecucion")

    main()