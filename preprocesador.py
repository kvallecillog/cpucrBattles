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
from collections import Counter
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


# Clase para definir colores de las impresiones de pantalla.
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
    # Este metodo se encarga de obtener los datos del archivo fuente.
    # Se lee el ASM original sin modificaciones y se ingresa a una lista.
    # Luego se mapean los numeros de linea en la primera columna de izquierda derecha.

    # Se lee el archivo fuente y se crea un objeto file de lectura.
    raw_file = open(raw_file_name, 'r')

    # Se lee linea por linea del objeto file ASM original.
    lines_raw_file_lines = raw_file.readlines()

    # Se ingresa el nombre del archivo a leer. !!!!! Cambiar esta HardCoded!
    lines_raw_file_name = 'lines_raw_file_name.ASM'

    # Se crea un nuevo objeto file para escritura, contiene las lineas mapeadas.
    lines_raw_file = open(lines_raw_file_name, 'w+')

    # Se lee linea a linea del archivo ASM original.
    for line in lines_raw_file_lines:
        # Se crea un contador para mapear el numero de linea leida.
        lines_counter += 1

        # Se crea el string con el numero de linea mas el contenido original.
        counter_string = str(lines_counter) + " " + line

        # Se escribe en el archivo el nuevo string
        lines_raw_file.writelines(counter_string)

        # Se agrega a la lista el nuevo string.
        data_list.append(counter_string)

    # Se cierra el objeto file de lectura.
    lines_raw_file.close()

    # Se retorna la lista que contiene las nuevas lineas con los numeros mapeados.
    return data_list


def delete_blanks(data_list):
    # Se encarga de eliminar las lineas blancas, sin contenido,
    # de la lista del archivo fuente original, se crea una nueva lista.

    # Se declara la lista que solo contiene lineas con datos.
    delete_blanks_list = []

    # Se crea un objeto file que solo contiene lineas con datos.
    deleted_blanks_file_name = 'deleted_blanks_file.ASM'
    non_blanks_file = open(deleted_blanks_file_name, 'w+')

    # Se define la regex que identifica lineas blancas sin datos.
    blank_regex = re.compile(r'^\d+\s+$')

    # Se lee cada indice de la lista.
    for x in range(0, len(data_list)):

        # Se convierte a string el indice leido.
        data_list_x = ''.join(data_list[x])
        # Si la regex identifica una linea en blanca devuelve verdadero.
        blank_non_comment_regex = re.match(blank_regex, data_list_x)

        # Si no es una linea en blanco ingresela a la lista y al archivo.
        if not blank_non_comment_regex:
            non_blanks_file.writelines(data_list_x)
            delete_blanks_list.append(data_list_x)
            # Si es una linea blanca no haga nada.

    # Retorne la lista final sin lineas blancas.
    return delete_blanks_list


def delete_comments(data_list):
    # Se encarga de detectar y eliminar comentarios linea por linea del .ASM

    # Se crea el objeto non_comments_file para escritura, este archivo contiene el .ASM sin comentarios.
    deleted_comments_file_name = 'deleted_comments_file.ASM'
    non_comments_file = open(deleted_comments_file_name, 'w+')

    # La regex se encarga de encontrar comentarios identificados por el semicolon, ";"
    comment_regex = re.compile(r'\s??;.*')

    # Se lee linea por linea el archivo ASM raw_file para determinar si la linea es un comentario o no.
    for x in range(0, len(data_list)):
        data_list_x = ''.join(data_list[x])
        # Se eliminan los comentarios del string.
        data_list_x = re.sub(comment_regex, "", data_list_x)
        # Se ingresa el nuevo string a su posicion original en la lista.
        data_list[x] = data_list_x
    # Se eliminan las nuevas lineas en blanco generados.
    data_list = delete_blanks(data_list)
    for x in range(0, len(data_list)):
        data_list_x = ''.join(data_list[x])
        # Se escribe en el archivo las lineas sin comentarios.
        non_comments_file.writelines(data_list_x)

    # Se cierra el archivo sin comentarios
    non_comments_file.close()

    # Se retorna la lista sin comentarios y sin lineas en blanco.
    return data_list


def delete_spaces(data_list):
    # Se encarga de eliminar los multiespacios, e identaciones.

    # Se crea el objeto non_comments_file para escritura, este archivo contiene el .ASM sin comentarios.
    deleted_spaces_file_name = 'deleted_spaces_file.ASM'
    deleted_spaces_file = open(deleted_spaces_file_name, 'w+')
    # Regex que identifica los multiples espacios.
    spaces_regex = re.compile(r' +')

    # Se recorre cada indice de la lista para identificar multiples espacios.
    for x in range(0, len(data_list)):
        data_list_x = "".join(data_list[x])
        # Se sustituyen por un unico espacio.
        data_list_x = re.sub(spaces_regex, ' ', data_list_x)
        # Se sustituye el string sin multiples espacios en el indice original.
        data_list[x] = data_list_x
        # Se escribe la linea sin multiples espacios al nuevo archivo.
        deleted_spaces_file.writelines(data_list[x])

    # Se retorna la lista sin multiples espacios.
    return data_list


def init_checker(data_list, lines_raw_list):
    # Inicializacion de la lista que contiene el programa principal
    # La seccion de inicializacion no esta contenida en esta lista.
    delete_init_list = []

    # Inicializacion el diccionario de constantes.
    const_dic = dict()

    # Limpia la memoria del diccionario
    const_dic.clear()

    # Regex para identificar el contador de posicion de memoria.
    # Un ejemplo de declaracion de contador de posicion de memoria:
    # * = @7777; Notese que debe declararse con espacios blancos.
    regex_pos_def = re.compile(r"^(\*)(\s)(\=)(\s)((\@)([0-7]{1,4}))$", re.IGNORECASE)

    # Regex para identificar declaraciones de constantes.
    # Un ejemplo de declaracion de constantes:
    # CONST = @7777 ; Notese que debe declararse con espacios en blanco.
    regex_pos_assign = re.compile(r"^([a-zA-Z](\w{1,7})?)(\s)(\=)(\s)(\*)$", re.IGNORECASE)

    # Regex para identificar el contador de posicion de memoria.
    # Un ejemplo de declaracion de contador de posicion de memoria:
    # * = @7777; Notese que debe declararse con espacios blancos.
    regex_pos_def_plus = re.compile(r"^(\*)(\s)(\=)(\s)(\*)(\s)(\+)(\s)(\d*)$", re.IGNORECASE)

    # Regex para identificar declaraciones de constantes.
    # Un ejemplo de declaracion de constantes:
    # CONST = @7777 ; Notese que debe declararse con espacios en blanco.
    regex_pos_assign_plus = re.compile(r"^([a-zA-Z](\w{1,7})?)(\s)(\=)(\s)((\*)(\s)(\+)(\s)(\d*))$", re.IGNORECASE)

    # Regex para identificar constantes en tiempo de ejecucion,DBWRD, WRD.
    # Un ejemplo de declaracion de constantes en tiempo de ejecucion:
    # DBWRD @7777; Notese que debe declararse con espacios en blanco.
    # WRD @77; Notese que debe de ser 1 palabra, 6 bits maximo.
    regex_init_res_words = re.compile(r"\b^((DBWRD)|(WRD))\b(\s)((\@)[0-7]{1,4})$", re.IGNORECASE)

    regex_init_const = re.compile(r"^([a-zA-Z](\w{1,7})?)(\s)(\=)(\s)((\@)([0-7]{1,4}))$", re.IGNORECASE)

    regex_res_word = re.compile(r"\b(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
                     DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
                     RTS|SEC|SEI|STA|SUB|TAP|TPA)\b", re.IGNORECASE)

    pos_cont_dec = 0
    pos_cont = False

    for x in range(0, len(data_list)):

        data_list_x = ''.join(data_list[x])
        num_line = data_list_x.split(" ")
        non_num_line = " ".join(num_line[1:len(num_line)])
        num_line_int = int(num_line[0])
        num_line_int_0 = int(num_line[0]) - 1
        data_source_line = lines_raw_list[num_line_int_0]
        data_source_line_list = data_source_line.split(" ")
        data_source_line_n = " ".join(data_source_line_list[1:len(data_source_line_list)])

        pos_def_match = re.match(regex_pos_def, non_num_line)
        pos_assign_match = re.match(regex_pos_assign, non_num_line)

        pos_def_match_plus = re.match(regex_pos_def_plus, non_num_line)
        pos_assign_match_plus = re.match(regex_pos_assign_plus, non_num_line)

        init_const_match = re.match(regex_init_const, non_num_line)
        init_res_words_match = re.match(regex_init_res_words, non_num_line)

        cont_res_word_dic = Counter(w.lower() for w in re.findall(regex_res_word, non_num_line))

        cont_res_word_int = sum(cont_res_word_dic.values())

        if pos_def_match or pos_assign_match or pos_def_match_plus or pos_assign_match_plus or \
                init_res_words_match or init_const_match:

            if cont_res_word_int == 0:

                # * = @0000
                if pos_def_match:

                    pos_cont_oct = pos_def_match.group(7)
                    pos_cont_dec = int(pos_cont_oct, 8)
                    print("Position counter declaration:", pos_cont_oct)

                    # print("Value:", pos_def_match.group(7))
                    pos_cont = True
                    print("Position counter line:")
                    print(num_line_int, "|", non_num_line)

                # CONST = *
                elif pos_assign_match:

                    const_dic[pos_assign_match.group(1)] = pos_cont_dec
                    # print("Constant assignation dictionary:", const_dic)
                    print("Constant assignation line:")
                    print(num_line_int, "|", non_num_line)

                # * = * + 1
                elif pos_def_match_plus:

                    print("Before position counter decimal declaration", pos_cont_dec)
                    pos_cont_dec = pos_cont_dec + int(pos_def_match_plus.group(9))
                    # print("Position counter declaration:", pos_cont_dec)
                    print("Before position counter decimal declaration", pos_cont_dec)
                    # print("Value:", pos_def_match.group(7))
                    pos_cont = True
                    print("Position counter line:")
                    print(num_line_int, "|", non_num_line)

                # CONST = * + 1
                elif pos_assign_match_plus:

                    print("Before position counter decimal assignation", pos_cont_dec)
                    pos_cont_dec = pos_cont_dec + int(pos_assign_match_plus.group(11))
                    const_dic[pos_assign_match_plus.group(1)] = pos_cont_dec
                    print("After position counter decimal assignation", pos_cont_dec)
                    # print("Constant assignation dictionary:", const_dic)
                    print("Constant assignation line:")
                    print(num_line_int, "|", non_num_line)


                elif init_res_words_match:

                    print("DBWORD or WRD reserved words")
                    print(num_line_int, "|", non_num_line)

                elif init_const_match:

                    const_oct = init_const_match.group(8)
                    const_dec = int(const_oct, 8)
                    const_dic[init_const_match.group(1)] = const_oct
                    print("Constant declaration:", init_const_match.group(1), ":", const_oct)
                    print("Constant assign line:")
                    print(num_line_int, "|", non_num_line)

            else:

                print("Error!:" + str(cont_res_word_int - 1) + " Reserved words as a label")
                print(num_line_int, "|", non_num_line)

        else:

            if pos_cont:
                # pos_cont_oct = pos_def_match.group(0)



                print("Warning: No matching line!")
                print(num_line_int, "|", non_num_line)
                delete_init_list.append(data_list_x)
            elif not pos_cont and (x == len(data_list) - 1):

                print("Error: No position counter defined (Example, * = @0000)")
                print("Please define a position counter!")

    hash_init = []

    print("\nConstant extracted, dictionary (Decimal):", const_dic)

    print("\nList without init data:", delete_init_list)

    print("\n" + bcolors.FAIL + "\nPosition counter for main program:" + str(pos_cont_dec) + bcolors.ENDC, "\n")

    return hash_init, delete_init_list, pos_cont_dec, const_dic


def label_checker(data_list, lines_raw_list, hash_init, pos_cont_dec):
    print("Checking labels\n")

    cont_mem_pos = pos_cont_dec

    # Inicializacion el diccionario de constantes.
    opcode_dic = dict()

    # Inicializacion el diccionario de constantes.
    fsm_dic = {
        'LDA_ABS': '000000', 'STA_ABS': '001000', 'ADD_ABS': '010000', 'SUB_ABS': '011000', 'AND_ABS': '100000',
        'ORA_ABS': '101000', 'JMP_ABS': '110000', 'JSR_ABS': '111000',
        
        'LDA_IND': '000011', 'STA_IND': '001011', 'ADD_IND': '010011', 'SUB_IND': '011011', 'AND_IND': '100011',
        'ORA_IND': '101011', 'JMP_IND': '110011', 'JSR_IND': '111011',

        'LDA_INM': '000001', 'STA_INM': '001001', 'ADD_INM': '010001', 'SUB_INM': '011001', 'AND_INM': '100001',
        'ORA_INM': '101001', 'JMP_INM': '110001', 'JSR_INM': '111001',

        'BEQ_REL': '000010', 'BNE_REL': '001010', 'BCS_REL': '010010', 'BCC_REL': '011010', 'BMI_REL': '100010',
        'BPL_REL': '101010', 'BVS_REL': '110010', 'BVC_REL': '111010',
        
        'SEC_IMP': '010100', 'CLC_IMP': '011100', 'SEI_IMP': '100100', 'CLI_IMP': '101100',
    
        'CLA_ACU': '000101', 'CPA_ACU': '001101', 'INA_ACU': '010101', 'DCA_ACU': '011101', 'ROL_ACU': '100101',
        'ROR_ACU': '101101', 'PLA_ACU': '110101', 'PHA_ACU': '111101',
        
        'TPA_CTR': '000110', 'TAP_CTR': '001110', 'RTI_CTR': '010110', 'RTS_CTR': '011110', 'HTL_CTR': '100110',
        'NOP_CTR': '101110', 'PLS_CTR': '110110', 'PHS_CTR': '111110',
        
        'INP_IO': '000111', 'OUT_IO': '001111'
    }

    # Limpia la memoria del diccionario
    opcode_dic.clear()


    # Se identifica si se esta utilizando como etiqueta una palabra reservada.

    regex_macro = re.compile(r"\b^(MACRO|FINMAC)\b(\s)*.*", re.IGNORECASE)

    regex_res_word = re.compile(r"\b(AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
                     DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
                     RTS|SEC|SEI|STA|SUB|TAP|TPA)\b", re.IGNORECASE)

    regex_label_abs_inst = re.compile(
        r'\b^([a-zA-Z](\w{1,7})?)\b(\s)\b(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(((\@)[0-7]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',
        re.IGNORECASE)
    regex_inst_abs = re.compile(
        r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(((\@)[0-7]{1,4})|([a-zA-Z](\w{1,7})?)(\+?)(\d*))$', re.IGNORECASE)

    regex_label_ind_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))(\))$',
        re.IGNORECASE)
    regex_inst_ind = re.compile(
        r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))(\))$',
        re.IGNORECASE)

    regex_label_inm_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)([0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',
        re.IGNORECASE)
    regex_inst_inm = re.compile(r'\b^(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)([0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',
                                re.IGNORECASE)

    regex_label_io_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(INP|OUT)\b(\s)((\@)[0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)
    regex_inst_io = re.compile(r'\b^(INP|OUT)\b(\s)((\@)[0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)

    regex_label_rel_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s\b(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)\b\s([a-zA-Z](\w{1,7})?)$', re.IGNORECASE)
    regex_inst_rel = re.compile(
        r'\b^(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)\b(\s)([0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)

    regex_label_acum_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
    regex_inst_acum = re.compile(r'\b^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)\b$', re.IGNORECASE)

    regex_label_ctrl_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)$', re.IGNORECASE)
    regex_inst_ctrl = re.compile(r'\b^(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)\b$', re.IGNORECASE)

    regex_label_imp_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(SEC|CLC|SEI|CLI)$', re.IGNORECASE)
    regex_inst_imp = re.compile(r'\b^(SEC|CLC|SEI|CLI)\b$', re.IGNORECASE)

    for i in range(0, 2):

        print("Pass", i)
        for x in range(0, len(data_list)):

            print("MEM position counter updating", cont_mem_pos)
            data_list_x = ''.join(data_list[x])
            num_line = data_list_x.split(" ")
            non_num_line = " ".join(num_line[1:len(num_line)])
            num_line_int = int(num_line[0])
            num_line_int_0 = int(num_line[0]) - 1
            data_source_line = lines_raw_list[num_line_int_0]
            data_source_line_list = data_source_line.split(" ")
            data_source_line_n = " ".join(data_source_line_list[1:len(data_source_line_list)])

            macro_match = re.match(regex_macro, non_num_line)

            if not macro_match:

                cont_res_word_dic = Counter(w.lower() for w in re.findall(regex_res_word, non_num_line))
                cont_res_word_int = sum(cont_res_word_dic.values())

                if cont_res_word_int > 1:

                    # raise Exception('Error: Reserved word as label')
                    print("Error!:" + str(cont_res_word_int - 1) + " Reserved words as a label")
                    print(num_line_int, "|", non_num_line)

                elif cont_res_word_int == 1:
                    print("OK!: Labels and instrucions are valid")

                    label_inst_abs_match = re.match(regex_label_abs_inst, non_num_line)
                    inst_abs_match = re.match(regex_inst_abs, non_num_line)

                    label_inst_ind_match = re.match(regex_label_ind_inst, non_num_line)
                    inst_ind_match = re.match(regex_inst_ind, non_num_line)

                    label_inst_inm_match = re.match(regex_label_inm_inst, non_num_line)
                    inst_inm_match = re.match(regex_inst_inm, non_num_line)

                    label_inst_io_match = re.match(regex_label_io_inst, non_num_line)
                    inst_io_match = re.match(regex_inst_io, non_num_line)

                    label_inst_rel_match = re.match(regex_label_rel_inst, non_num_line)
                    inst_rel_match = re.match(regex_inst_rel, non_num_line)

                    label_inst_acum_match = re.match(regex_label_acum_inst, non_num_line)
                    inst_acum_match = re.match(regex_inst_acum, non_num_line)

                    label_inst_ctrl_match = re.match(regex_label_ctrl_inst, non_num_line)
                    inst_ctrl_match = re.match(regex_inst_ctrl, non_num_line)

                    label_inst_imp_match = re.match(regex_label_imp_inst, non_num_line)
                    inst_imp_match = re.match(regex_inst_imp, non_num_line)

                    if inst_abs_match or inst_ind_match or inst_inm_match or inst_io_match \
                            or inst_rel_match or inst_acum_match or inst_ctrl_match or inst_imp_match:

                        print("Cumple con la condicion de instruccion")
                        if inst_abs_match:
                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento absoluto cuenta con 3 palabras.
                            cont_mem_pos += 3

                            #opcode_dic[PC, inst, opcode, oper] = cont_mem_pos, LDA_ABS,

                            print("OPERANDO!:", inst_abs_match.group(3))
                            print("Es una instruccion direccionamiento pura absoluto")
                            print(num_line_int, "|", data_source_line_n)

                        if inst_ind_match:
                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento indirecto cuenta con 3 palabras.
                            cont_mem_pos += 3
                            # print("OPERANDO!:",inst_abs_match.group(3))
                            print("Es una instruccion direccionamiento pura indirecto")
                            print(num_line_int, "|", data_source_line_n)
                        if inst_inm_match:
                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento inmediato cuenta con 2 palabras.
                            cont_mem_pos += 2
                            # print("OPERANDO!:",inst_abs_match.group(3))
                            print("Es una instruccion direccionamiento pura inmediato")
                            print(num_line_int, "|", data_source_line_n)

                        if inst_io_match:
                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento IO cuenta con 2 palabras.
                            cont_mem_pos += 2
                            # print("OPERANDO!:",inst_abs_match.group(3))
                            print("Es una instruccion direccionamiento pura entrada/salida")
                            print(num_line_int, "|", data_source_line_n)

                        if inst_rel_match:
                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento relativo cuenta con 2 palabras.
                            cont_mem_pos += 2

                            # cont_mem_pos += VALOR DE ETIQUETA

                            # print("OPERANDO!:",inst_abs_match.group(3))
                            print("Es una instruccion direccionamiento pura relativo")
                            print(num_line_int, "|", data_source_line_n)

                        if inst_acum_match:
                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento acumulador cuenta con 1 palabra.
                            cont_mem_pos += 1
                            # print("OPERANDO!:",inst_abs_match.group(1))
                            print("Es una instruccion direccionamiento pura acumulador")
                            print(num_line_int, "|", data_source_line_n)

                        if inst_ctrl_match:
                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento control cuenta con 1 palabra.
                            cont_mem_pos += 1
                            # print("OPERANDO!:",inst_abs_match.group(2))
                            print("Es una instruccion direccionamiento pura control")
                            print(num_line_int, "|", data_source_line_n)

                        if inst_imp_match:
                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento implicito cuenta con 1 palabra.
                            cont_mem_pos += 1
                            # print("OPERANDO!:",inst_abs_match.group(1))
                            print("Es una instruccion direccionamiento pura implicito")
                            print(num_line_int, "|", data_source_line_n)

                    else:

                        if label_inst_abs_match or label_inst_ind_match or \
                                label_inst_inm_match or label_inst_io_match \
                                or label_inst_rel_match or label_inst_acum_match \
                                or label_inst_ctrl_match or label_inst_imp_match:
                            print("Cumple con la condicion de etiqueta de 8 caracteres + instruccion")

                            if label_inst_abs_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento absoluto cuenta con 3 palabras.
                                cont_mem_pos += 3

                                print("OPERANDO!:", label_inst_abs_match.group(6))
                                print("Es una instruccion de direccionamiento absoluto")
                                print(num_line_int, "|", data_source_line_n)

                            if label_inst_ind_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento absoluto cuenta con 3 palabras.
                                cont_mem_pos += 3

                                print("Es una instruccion de direccionamiento indirecto")
                                print(num_line_int, "|", data_source_line_n)

                            if label_inst_inm_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento absoluto cuenta con 3 palabras.
                                cont_mem_pos += 2

                                print("Es una instruccion de direccionamiento inmediato")
                                print(num_line_int, "|", data_source_line_n)

                            if label_inst_io_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento absoluto cuenta con 3 palabras.
                                cont_mem_pos += 2

                                print("Es una instruccion de direccionamiento entrada/salida")
                                print(num_line_int, "|", data_source_line_n)

                            if label_inst_rel_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento absoluto cuenta con 3 palabras.
                                cont_mem_pos += 2

                                print("Es una instruccion de direccionamiento relativo")
                                print(num_line_int, "|", data_source_line_n)

                            if label_inst_acum_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento acumulador cuenta con 1 palabra.
                                cont_mem_pos += 1

                                print("Es una instruccion de direccionamiento acumulador")
                                print(num_line_int, "|", data_source_line_n)

                            if label_inst_ctrl_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento control cuenta con 1 palabra.
                                cont_mem_pos += 1

                                print("Es una instruccion de direccionamiento control")
                                print(num_line_int, "|", data_source_line_n)

                            if label_inst_imp_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento implicito cuenta con 1 palabra.
                                cont_mem_pos += 1

                                print("Es una instruccion de direccionamiento implicito")
                                print(num_line_int, "|", data_source_line_n)

                        else:
                            print("Error: No es un formato de etiqueta + instruccion valido.")
                            print(num_line_int, "|", data_source_line_n)

                else:
                    print("Error!: no valid argument in line")
                    print(num_line_int, "|", data_source_line_n)
            else:
                print("Error: Macro is not supported")
                print(num_line_int, "|", non_num_line)


def instruction_checker(data_list, lines_raw_list):
    ##################################################################################################################
    # Instruction checker analiza si la instruccion ingresada esta dentro del conjunto de instrucciones de la CPUCR.
    # Las instruciones son validas en mayuscula o en minuscula,
    ##################################################################################################################
    checked_inst_file_name = 'checked_inst_file_name.ASM'
    checked_inst_file = open(checked_inst_file_name, 'w+')

    # Direccionamiento absoluto validado sin etiquetas funcionales.
    regex_inst_abs = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\@)[0-7]{1,4}$', re.IGNORECASE)
    # Direccionamiento indirecto validado sin etiquetas funcionales.
    regex_inst_ind = re.compile(r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()(\@)[0-7]{1,4}(\))$', re.IGNORECASE)
    # Direccionamiento inmediato validado sin etiquetas funcionales.
    regex_inst_inm = re.compile(r'\b^(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)[0-7]{1,2}$', re.IGNORECASE)
    # Direccionamiento de entradas y salidas.
    regex_inst_io = re.compile(r'^(INP|OUT)\b(\s)(\@)[0-7]{1,2}$', re.IGNORECASE)
    # Falta la capacidad de etiquetas!
    regex_inst_rel = re.compile(r'^(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)$', re.IGNORECASE)
    regex_inst_acum = re.compile(r'^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
    regex_inst_ctrl = re.compile(r'^(TPA|TAP|RTI|RTS|HTL|NOP|PLS|PHS)$', re.IGNORECASE)
    regex_inst_imp = re.compile(r'^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)

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
