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
import argparse
import preprocesador

def main(argv):
###########################################################################
 # Files names
###########################################################################


    # for arg in sys.argv:
    #     print("Argumentos",arg)
    #
    # raw_file_name = sys.argv[1]
    # # try:
    # #     raw_file_name = getopt.getopt(argv)
    # #     print(raw_file_name)
    # #
    # # except:
    raw_file_name = 'raw_file.ASM'
    print("ASM procesado:",raw_file_name,"\n")
###########################################################################
# Global variables
###########################################################################
    lines_counter = 0
    error = 0
    data_list = []
###########################################################################

    lines_raw_list = preprocesador.lines_mapper(raw_file_name, lines_counter, data_list)
    deleted_blanks_list = preprocesador.delete_blanks(lines_raw_list)
    deleted_comments_list = preprocesador.delete_comments(deleted_blanks_list)
    deleted_spaces_list = preprocesador.delete_spaces(deleted_comments_list)
    error_init, error_init_list, deleted_init_list, pos_cont_dec, const_dic, res_words_dic, warning_list = preprocesador.init_checker(deleted_spaces_list, lines_raw_list, error)

    if error_init == 0:

        print("\nInicializacion sin errores:", error_init, "\n")
        error_label, label_list, error_flow_list, num_op_inst_list = preprocesador.label_checker(deleted_init_list, lines_raw_list, error, pos_cont_dec, const_dic)

        if error_label == 0:

            print("\nEjecucion de instrucciones")
            error_inst, fi_list = preprocesador.inst_checker(num_op_inst_list, lines_raw_list, error_label, pos_cont_dec)

            if error_inst == 0:

                print("Programa principal sin errores:", error_inst, "\n")
                obj_list = preprocesador.obj_creator(fi_list, res_words_dic, lines_raw_list)

                # print("Advertencia: ",warning_list[len(warning_list)-1])
            else:

                print("Errores detectados el ASM no pudo ensamblarse!")

        else:

            print("Error detectado en la lista de instruccions: El ASM no fue ensamblado!")
            print("Lista de errores:",error_flow_list)

    else:

        print("Error detectado en la inicializacion: El ASM no fue ensamblado!")
        print("Lista de errores:", error_init_list)

    # cpucr_model = "./cpucr_model.x"
    # os.system(cpucr_model)
    # cpucr_vcd = "gtkwave cpucr_waves_file.gtkw &"
    # os.system(cpucr_vcd)

if __name__ == "__main__": main(sys.argv[1:])

print("\nSe ensamblo y ejecuto correctamente!")
