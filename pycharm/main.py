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
    Salidas: Codigo objeto ensamblado.
    Fecha: 30/08/15.
    Revision: 1.0.1
'''

import sys
import argparse
import preprocesador
import logging


def main(argv):
###########################################################################
# Variables globales
###########################################################################
    global logger
    logger = logging.getLogger()
    logger.setLevel(logging.DEBUG)
    formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
    fh = logging.FileHandler('SES.log')
    fh.setLevel(logging.DEBUG)
    fh.setFormatter(formatter)
    logger.addHandler(fh)
    ch = logging.StreamHandler()
    ch.setLevel(logging.DEBUG)
    ch.setFormatter(formatter)
    logger.addHandler(ch)
    raw_file_name = 'raw_file.ASM'
    logging.info("****************************************")
    logging.info('Sistema de Ensamblado y Ejecucion (SEE)')
    logging.info("****************************************")
    logging.info("========================================")
    logging.info('Inicia la ejecucion del ensamblador')
    logging.info("========================================")
    logging.info('Archivo ASM cargado: '+raw_file_name)
    lines_counter = 0
    error = 0
    data_list = []

    if len(sys.argv) > 1:
        if int(sys.argv[1]) == 16:
         base_output = int(sys.argv[1])
        elif int(sys.argv[1]) == 10:
         base_output = int(sys.argv[1])
        elif int(sys.argv[1]) == 8:
         base_output = int(sys.argv[1])
        elif int(sys.argv[1]) == 2:
         base_output = int(sys.argv[1])
        else:
            logging.warning('Base invalida, se asigno por defecto base: 8')
            base_output = 8
    else:
        logging.warning('Base invalida, se asigno por defecto base: 8')
        base_output = 8

###########################################################################

###########################################################################
# Llamadas a metodos
###########################################################################
    lines_raw_list = preprocesador.lines_mapper(raw_file_name, lines_counter, data_list)
    deleted_blanks_list = preprocesador.delete_blanks(lines_raw_list)
    deleted_comments_list = preprocesador.delete_comments(deleted_blanks_list)
    deleted_spaces_list = preprocesador.delete_spaces(deleted_comments_list)
    error_init, error_init_list, deleted_init_list, pos_cont_dec, const_dic, res_words_dic, warning_list = preprocesador.init_checker(deleted_spaces_list, lines_raw_list, error)

    if error_init == 0:
        logging.info("Etapa de init sin errores: %d", error_init)
        error_label, label_list, error_flow_list, num_op_inst_list = preprocesador.label_checker(deleted_init_list, lines_raw_list, error, pos_cont_dec, const_dic)
        if error_label == 0:
            logging.info("Inicia Etapa de instrucciones!")
            error_inst, fi_list = preprocesador.inst_checker(num_op_inst_list, lines_raw_list, error_label, pos_cont_dec)
            if error_inst == 0:
                logging.info("Etapa de instruc sin errores: %d", error_inst)
                obj_list = preprocesador.obj_creator(fi_list, res_words_dic, lines_raw_list, base_output)
                # print("Advertencia: ",warning_list[len(warning_list)-1])
            else:
                logging.error("Error encontrado en etapa de instrucciones!")
        else:
            logging.error("Error encontrado en etapa de instrucciones!")
            logging.error("Lista de errores encontrados: " + str(error_flow_list))
            logging.error("El ASM no fue ensamblado!")
    else:
        logging.error("Error encontrado en etapa de init!")
        logging.error("Lista de errores encontrados: " + str(error_init_list))
        logging.error("El ASM no fue ensamblado!")

    # cpucr_model = "./cpucr_model.x"
    # os.system(cpucr_model)
    # cpucr_vcd = "gtkwave cpucr_waves_file.gtkw &"
    # os.system(cpucr_vcd)

if __name__ == "__main__": main(sys.argv[1:])
logging.info("Fin de la ejecucion de SEE!")
logging.info("========================================")
logging.info("****************************************")

###########################################################################


