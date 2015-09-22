#!/usr/bin/env python

__author__ = "Kenneth Vallecillo Gonzalez"
__copyright__ = "Copyright 2015"
__credits__ = ["Kenneth Vallecillo", "Lochi Yu", "Enrique Coen", "Diego Valverde"]
__license__ = "GPL"
__version__ = "1.0.1"
__maintainer__ = "Kenneth Vallecillo Gonzalez"
__email__ = "kvallecillog@gmail.com"
__status__ = "WIP: Working In Progress"

'''
    Descripcion: Main del preprocesador para los archivos .ASM.
    Entradas: Archivo original del .ASM
    Salidas: Archivo procesado sin comentarios.
    Fecha: 30/08/15.
    Revision: 1.0.1
'''

import sys
import preprocesador
import assembly_tables

# def main(argv):
def main():

    raw_file_name = 'raw_file.ASM'
    deleted_comments_file_name = 'deleted_comments_file.ASM'
    list_of_comments = 'list_of_comments.list'
    deleted_blanks_file_name = 'deleted_blanks_file_name.ASM'
    checked_inst_file_name = 'checked_inst_file_name.ASM'



    comments_file = preprocesador.open_file(raw_file_name)
    preprocesador.delete_comments(comments_file, deleted_comments_file_name, list_of_comments)

    deleted_comments_file = preprocesador.open_file(deleted_comments_file_name)
    preprocesador.delete_blanks(deleted_comments_file, deleted_blanks_file_name)

    deleted_blanks_file = preprocesador.open_file(deleted_blanks_file_name)
    preprocesador.instruction_checker(deleted_blanks_file, checked_inst_file_name, instruction_hash)



  #  comments_file = preprocesador.open_file(raw_file_name)

if __name__ == "__main__": main()

print("Finished!")