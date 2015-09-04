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

#import preprocesador
import sys, getopt

# file = preprocesador.FileProcessor()


def main(argv):

   file_input = ''
   file_output = ''
   try:
      opts, args = getopt.getopt(argv,"hi:o:",["ifile=","ofile="])
   except getopt.GetoptError:
      print('test.py -i <inputfile> -o <outputfile>')
      sys.exit(2)
   for opt, arg in opts:
      if opt == '-h':
         print('test.py -i <inputfile> -o <outputfile>')
         sys.exit()
      elif opt in ("-i", "--ifile"):
         file_input = arg
      elif opt in ("-o", "--ofile"):
         file_output = arg
   print('Input file is "', file_input)
   print('Output file is "', file_output)

if __name__ == "__main__":
   main(sys.argv[1:])