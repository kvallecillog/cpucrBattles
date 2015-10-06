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


# def main(argv):
def main():
    ###########################################################################################
    # Files names
    ###########################################################################################
    raw_file_name = 'raw_file.ASM'
    ###########################################################################################
    # Global variables
    ###########################################################################################
    lines_counter = 0
    data_list = []
    ###########################################################################################
    OK = 0
    lines_raw_list = preprocesador.lines_mapper(raw_file_name, lines_counter, data_list)
    deleted_blanks_list = preprocesador.delete_blanks(lines_raw_list)
    deleted_comments_list = preprocesador.delete_comments(deleted_blanks_list)
    deleted_spaces_list = preprocesador.delete_spaces(deleted_comments_list)
    inst_check_list = preprocesador.instruction_checker(deleted_spaces_list, lines_raw_list)

if __name__ == "__main__": main()

print("\nAnalisis de sintaxis finalizado!")
