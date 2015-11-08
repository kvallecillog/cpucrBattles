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


def init_checker(data_list, lines_raw_list,error):
    # Inicializacion de la lista que contiene el programa principal
    # La seccion de inicializacion no esta contenida en esta lista.
    delete_init_list = []

    # Inicializacion de la lista que contiene los errores del init.
    error_init_list = []

    # Inicializacion el diccionario de constantes.
    const_dic = dict()

    # Limpia la memoria del diccionario
    const_dic.clear()

    # Regex para identificar el contador de posicion de memoria.
    # Un ejemplo de declaracion de contador de posicion de memoria:
    # * = @7777; Notese que debe declararse con espacios blancos.
    regex_pos_def = re.compile(r"^(\*)(\s)(\=)(\s)(((\@)([0-7]{1,4}))|((\$)([0-9A-Fa-f]{1,4}))|(\d*)|((\%)([0-1]{1,12})))$", re.IGNORECASE)

    # Regex para identificar declaraciones de constantes.
    # Un ejemplo de declaracion de constantes:
    # CONST = @7777 ; Notese que debe declararse con espacios en blanco.
    regex_pos_assign = re.compile(r"^([a-zA-Z](\w{1,7})?)(\s)(\=)(\s)(\*)$", re.IGNORECASE)

    # Regex para identificar el contador de posicion de memoria.
    # Un ejemplo de declaracion de contador de posicion de memoria:
    # * = * + 1; Notese que debe declararse con espacios blancos.
    regex_pos_def_plus = re.compile(r"^(\*)(\s)(\=)(\s)(\*)(\s)(\+)(\s)(\d*)$", re.IGNORECASE)

    # Regex para identificar declaraciones de constantes.
    # Un ejemplo de declaracion de constantes:
    # CONST = * + 1 ; Notese que debe declararse con espacios en blanco.
    regex_pos_assign_plus = re.compile(r"^([a-zA-Z](\w{1,7})?)(\s)(\=)(\s)((\*)(\s)(\+)(\s)(\d*))$", re.IGNORECASE)

    # Regex para identificar constantes en tiempo de ejecucion,DBWRD, WRD.
    # Un ejemplo de declaracion de constantes en tiempo de ejecucion:
    # DBWRD @7777; Notese que debe declararse con espacios en blanco.
    # WRD @77; Notese que debe de ser 1 palabra, 6 bits maximo.
    regex_init_res_words = re.compile(r"\b^((DBWRD)|(WRD))\b(\s)((\@)[0-7]{1,4})$", re.IGNORECASE)

    regex_init_const = re.compile(r"^([a-zA-Z](\w{1,7})?)(\s)(\=)(\s)(((\@)([0-7]{1,4}))|((\$)([0-9A-Fa-f]{1,4}))|(\d*)|((\%)([0-1]{1,12})))$", re.IGNORECASE)

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

                # * = @0000, * = $0000, * = %000000000000, * = 0
                if pos_def_match:

                    print("Catching pcs")
                    print(pos_def_match.group(13))
                    # Octal pc
                    if pos_def_match.group(6):

                        print("Position counter hex declaration:", pos_def_match.group(6))
                        pos_cont_oct = pos_def_match.group(5)[1:]
                        pos_cont_dec = int(pos_cont_oct, 8)
                        print("Position counter oct declaration:", pos_cont_oct)
                        print("Position counter dec declaration:", pos_cont_dec)

                        # print("Value:", pos_def_match.group(7))
                        pos_cont = True
                        print("Position counter line:")
                        print(num_line_int, "|", non_num_line)

                    # Hexadecimal pc
                    elif pos_def_match.group(9):

                        print("Position counter hex declaration:", pos_def_match.group(9))
                        pos_cont_hex = pos_def_match.group(9)[1:]
                        pos_cont_dec = int(pos_cont_hex, 16)
                        print("Position counter hex declaration:", pos_cont_hex)
                        print("Position counter dec declaration:", pos_cont_dec)

                        # print("Value:", pos_def_match.group(7))
                        pos_cont = True
                        print("Position counter line:")
                        print(num_line_int, "|", non_num_line)


                    # Decimal PC
                    elif pos_def_match.group(12):

                        print("Position counter dec declaration:", pos_def_match.group(12))
                        pos_cont_dec_str = pos_def_match.group(12)
                        pos_cont_dec_int = int(pos_cont_dec_str)
                        print("Position counter dec declaration:", pos_cont_dec_int)

                        # print("Value:", pos_def_match.group(7))
                        pos_cont = True
                        print("Position counter line:")
                        print(num_line_int, "|", non_num_line)

                    elif pos_def_match.group(13):

                        print("Position counter dec declaration:", pos_def_match.group(13))
                        pos_cont_bin = pos_def_match.group(13)[1:]
                        pos_cont_dec = int(pos_cont_bin,2)
                        print("Position counter dec declaration:", pos_cont_dec)

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
                
                #  CONST = @0001
                elif init_const_match:

                    # const_oct = init_const_match.group(8)
                    # const_dec = int(const_oct, 8)
                    # const_dic[init_const_match.group(1)] = const_dec
                    # print("Constant declaration:", init_const_match.group(1), ":", const_oct)
                    # print("Constant assign line:")
                    # print(num_line_int, "|", non_num_line)

                    print(init_const_match.group(5))
                    # Octal CONST
                    if init_const_match.group(7):

                        print("CONST OCT declaration:", init_const_match.group(7))
                        const_oct = init_const_match.group(6)[1:]
                        const_dec = int(const_oct, 8)
                        const_dic[init_const_match.group(1)] = const_dec
                        print("CONST oct declaration:", const_oct)
                        print("CONST dec declaration:", const_dec)
                        print("CONST line:")
                        print(num_line_int, "|", non_num_line)

                    # Hexadecimal CONST
                    elif init_const_match.group(10):

                        print("CONST HEX declaration:", init_const_match.group(10))
                        const_hex = init_const_match.group(10)[1:]
                        const_dec = int(const_hex, 16)
                        const_dic[init_const_match.group(1)] = const_dec
                        print("CONST hex declaration:", const_hex)
                        print("CONST dec declaration:", const_dec)
                        print("CONST line:")
                        print(num_line_int, "|", non_num_line)

                    # Decimal CONST
                    elif init_const_match.group(13):

                        print("CONST DEC declaration:", init_const_match.group(13))
                        const_dec_str = init_const_match.group(13)
                        const_dec_int = int(const_dec_str)
                        const_dic[init_const_match.group(1)] = const_dec_int
                        print("CONST dec declaration:", const_dec_int)
                        print(num_line_int, "|", non_num_line)

                    # Binary CONST
                    elif init_const_match.group(14):

                        print("CONST BIN declaration:", init_const_match.group(14))
                        const_bin = init_const_match.group(14)[1:]
                        const_dec = int(const_bin,2)
                        const_dic[init_const_match.group(1)] = const_dec
                        print("CONST dec declaration:", const_dec)
                        print("CONST line:")
                        print(num_line_int, "|", non_num_line)

            else:
                error += 1
                error_res_word = "Error!:" + str(num_line_int) + "|" +non_num_line+ ", palabra reservada utilizada como identificador"
                error_init_list.append(error_res_word)
                print(error_res_word)
                print(num_line_int, "|", non_num_line)

        else:

            if pos_cont:
                # pos_cont_oct = pos_def_match.group(0)
                print("Warning: No matching line!")
                print(num_line_int, "|", non_num_line)
                delete_init_list.append(data_list_x)
            elif not pos_cont and (x == len(data_list) - 1):
                error += 1
                error_pc = "Error: No se definio el puntero de posicion (Ejemplo, * = @0000)"
                error_init_list.append(error_pc)
                print(error_pc)



    print("\nConstant extracted, dictionary (Decimal):", const_dic)

    print("\nList without init data:", delete_init_list)

    print("\n" + bcolors.FAIL + "\nPosition counter for main program:" + str(pos_cont_dec) + bcolors.ENDC, "\n")

    return error, error_init_list, delete_init_list, pos_cont_dec, const_dic


def label_checker(data_list, lines_raw_list, error, pos_cont_dec,const_dic):

    print("Checking labels\n")

    cont_mem_pos = pos_cont_dec

    # Inicializacion el diccionario de constantes.
    label_dic = const_dic
    fsm_dic = dict()
    error_list = []
    # opcode_dic = dict()
    # opcode_dic.clear()
    pc_list = []
    fi_list = []


    # Se identifica si se esta utilizando como etiqueta una palabra reservada.

    regex_macro = re.compile(r"\b^(MACRO|FINMAC)\b(\s)*.*", re.IGNORECASE)

    regex_oper_lab = re.compile(r"^([a-zA-Z](\w{1,7})?)(\+?)(\d*)$", re.IGNORECASE)
    regex_oper_dec = re.compile(r"^([0-9]+)$", re.IGNORECASE)
    regex_oper_oct = re.compile(r"^(\@)([0-7]{1,4})$", re.IGNORECASE)
    regex_oper_bin = re.compile(r"^(\%)([0-1]{1,6})$", re.IGNORECASE)
    regex_oper_hex = re.compile(r"^(\$)([0-9A-Fa-f]{1,4})$", re.IGNORECASE)

    regex_res_word = re.compile(r"\b(ADD|AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
                     DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
                     RTS|SEC|SEI|STA|SUB|TAP|TPA)\b", re.IGNORECASE)

    regex_label_abs_inst = re.compile(
        r'\b^([a-zA-Z](\w{1,7})?)\b(\s)\b(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(((\@)[0-7]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',
        re.IGNORECASE)
    regex_inst_abs = re.compile(
        r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(((\@)([0-7]{1,4}))|([a-zA-Z](\w{1,7})?)(\+?)(\d*))$',
        re.IGNORECASE)

    regex_label_ind_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))(\))$',
        re.IGNORECASE)
    regex_inst_ind = re.compile(
        r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))(\))$',
        re.IGNORECASE)

    # Cambios para aceptar operandos hexadecimales.
    regex_label_inm_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)(((\@)[0-7]{1,2}|(\%)[0-1]{1,6}|[0-9]+|(\$)[0-9A-Fa-f]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',
        re.IGNORECASE)
    regex_inst_inm = re.compile(
        r'\b^(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)(((\@)[0-7]{1,2}|(\%)[0-1]{1,6}|[0-9]+|(\$)[0-9A-Fa-f]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',
        re.IGNORECASE)

    regex_label_io_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(INP|OUT)\b(\s)(((\@)[0-7]{1,2}|(\%)[0-1]{1,6}|[0-9]+|(\$)[0-9A-Fa-f]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)
    regex_inst_io = re.compile(r'\b^(INP|OUT)\b(\s)(((\@)[0-7]{1,2}|(\%)[0-1]{1,6}|[0-9]+|(\$)[0-9A-Fa-f]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)

    regex_label_rel_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s\b(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)\b\s([a-zA-Z](\w{1,7})?)$', re.IGNORECASE)
    regex_inst_rel = re.compile(
        r'\b^(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)\b(\s)([0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)

    regex_label_acum_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
    regex_inst_acum = re.compile(r'\b^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)\b$', re.IGNORECASE)

    regex_label_ctrl_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(TPA|TAP|RTI|RTS|HLT|NOP|PLS|PHS)$', re.IGNORECASE)
    regex_inst_ctrl = re.compile(r'\b^(TPA|TAP|RTI|RTS|HLT|NOP|PLS|PHS)\b$', re.IGNORECASE)

    regex_label_imp_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(SEC|CLC|SEI|CLI)$', re.IGNORECASE)
    regex_inst_imp = re.compile(r'\b^(SEC|CLC|SEI|CLI)\b$', re.IGNORECASE)

    for i in range(0, 2):


        for x in range(0, len(data_list)):

            if error == 0:
                print("\n\nData_list",data_list[x], end = '')
                print("MEM position counter updating:", cont_mem_pos)
                data_list_x =''.join(data_list[x])
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

                    if cont_res_word_int > 1 or cont_res_word_int < 1 :

                        error += 1
                        if cont_res_word_int < 1:

                            error_no_inst = "Error!: No hay instruccion en la linea: "+str(num_line_int) + " | "+ non_num_line
                            error_list.append(error_no_inst)
                            print(error_no_inst)
                            print(num_line_int, "|", non_num_line)
                        else:

                            error_mul_inst = "Error!: Multiples palabras reservadas en la linea: "+str(num_line_int) + " | "+ non_num_line
                            error_list.append(error_mul_inst)
                            print("Error!:" + str(cont_res_word_int - 1) + " Error multiples palabras reservadas")
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

                        if label_inst_abs_match or label_inst_ind_match or \
                                label_inst_inm_match or label_inst_io_match \
                                or label_inst_rel_match or label_inst_acum_match \
                                or label_inst_ctrl_match or label_inst_imp_match:
                            print("Cumple con la condicion de etiqueta de 8 caracteres + instruccion")

                            if label_inst_abs_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento absoluto cuenta con 3 palabras.
                                cont_mem_pos += 3

                                print("Operand!:", label_inst_abs_match.group(6))
                                print("Es una instruccion de direccionamiento absoluto")
                                print(num_line_int, "|", data_source_line_n)
                                
                                #####################################################
                                
                                if i == 0:
                                    print("label_inst_abs_match iter: ", i)
                                    label_abs = label_inst_abs_match.group(1)

                                    if label_abs in label_dic:
                                        error_id_dup = "Error, identificador: "+label_abs+", duplicado.\n"
                                        error += 1
                                        error_list.append(error_id_dup)

                                    else:

                                        label_dic[label_abs] = cont_mem_pos
                                        print("Es una instruccion de direccionamiento absediato")
                                        print("Etiqueta ingresada al diccionario:", label_dic)
                                        print(num_line_int, "|", data_source_line_n, end='')

                                        const_abs = label_inst_abs_match.group(6)

                                        oper_lab_match = re.match(regex_oper_lab, const_abs)

                                        print("CONST remplazada: ", const_abs)
                                        if oper_lab_match:

                                            if const_abs in label_dic:
                                                const_abs_dec = int(label_dic[const_abs])
                                                const_abs_oct = format(const_abs_dec, '#06o')[2:]
                                                oper_abs ="@"+const_abs_oct
                                                print("Valor decimal de CONST: ", oper_abs)
                                                # oper_abs = format(oper_abs, '#08b')[-6:]
                                                label_regex = re.compile(r'\b'+re.escape(const_abs)+r'\b', re.IGNORECASE)
                                                data_list_x = re.sub(label_regex,oper_abs, data_list_x)
                                                # print("Linea con CONST actualizada: ",data_list_x)
                                                data_list[x] = data_list_x
                                                print("Linea con CONST actualizada:", data_list, end='' )
                                                cont_mem_pos += 2
                                            else:
                                                error_cont_id = "Error, identificador"+label_abs+" no definido"
                                        else:
                                            print("Horror")
                                else:

                                    print("label_inst_abs_match iter: ", i)
                                    label_abs = label_inst_abs_match.group(1)+" "
                                    print("label_abs", label_abs)
                                    label_regex = re.compile(r'\b'+re.escape(label_abs)+r'\b', re.IGNORECASE)
                                    data_list_x = re.sub(label_regex,"", data_list_x)
                                    print("data_list_x: ",data_list_x)
                                    data_list[x] = data_list_x
                                    print("data_list", data_list)                              
                                
                                #####################################################

                            elif label_inst_ind_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento absoluto cuenta con 3 palabras.
                                cont_mem_pos += 3

                                print("Es una instruccion de direccionamiento indirecto")
                                print(num_line_int, "|", data_source_line_n)

                            # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                            # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                            elif label_inst_inm_match:
                                if i == 0:
                                    print("label_inst_inm_match iter: ", i)
                                    label_inm = label_inst_inm_match.group(1)

                                    if label_inm in label_dic:
                                        error_id_dup = "Error, identificador: "+label_inm+", duplicado.\n"
                                        error += 1
                                        error_list.append(error_id_dup)

                                    else:

                                        label_dic[label_inm] = cont_mem_pos
                                        print("Es una instruccion de direccionamiento inmediato")
                                        print("Etiqueta ingresada al diccionario:", label_dic)
                                        print(num_line_int, "|", data_source_line_n, end='')

                                        const_inm = label_inst_inm_match.group(6)

                                        oper_lab_match = re.match(regex_oper_lab, const_inm)

                                        print("CONST remplazada: ", const_inm)
                                        if oper_lab_match:
                                            
                                            if const_inm in label_dic:
                                                oper_inm =str(label_dic[const_inm])
                                                print("Valor decimal de CONST: ", oper_inm)
                                                # oper_inm = format(oper_inm, '#08b')[-6:]
                                                label_regex = re.compile(r'\b'+re.escape(const_inm)+r'\b', re.IGNORECASE)
                                                data_list_x = re.sub(label_regex,oper_inm, data_list_x)
                                                # print("Linea con CONST actualizada: ",data_list_x)
                                                data_list[x] = data_list_x
                                                print("Linea con CONST actualizada:", data_list, end='' )
                                                cont_mem_pos += 2
                                            else:
                                                error_cont_id = "Error, identificador"+label_inm+" no definido"
                                        else:
                                            print("Horror")
                                else:

                                    print("label_inst_inm_match iter: ", i)
                                    label_inm = label_inst_inm_match.group(1)+" "
                                    print("label_inm", label_inm)
                                    label_regex = re.compile(r'\b'+re.escape(label_inm)+r'\b', re.IGNORECASE)
                                    data_list_x = re.sub(label_regex,"", data_list_x)
                                    print("data_list_x: ",data_list_x)
                                    data_list[x] = data_list_x
                                    print("data_list", data_list)


                                # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                                # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                            elif label_inst_io_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento absoluto cuenta con 3 palabras.
                                cont_mem_pos += 2

                                print("Es una instruccion de direccionamiento entrada/salida")
                                print(num_line_int, "|", data_source_line_n)

                            elif label_inst_rel_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento absoluto cuenta con 3 palabras.
                                
                                if i == 0:
                                    print("label_inst_rel_match iter: ", i)
                                    label_rel = label_inst_rel_match.group(1)

                                    if label_rel in label_dic:

                                        error_id_dup = "Error, identificador: "+label_rel+", duplicado.\n"
                                        error += 1
                                        error_list.append(error_id_dup)

                                    else:

                                        label_dic[label_rel] = cont_mem_pos
                                        print("Es una instruccion de direccionamiento relediato")
                                        print("Etiqueta ingresada al diccionario:", label_dic)
                                        print(num_line_int, "|", data_source_line_n)
                                        cont_mem_pos += 2

                                else:
                                    print("label_inst_rel_match iter: ", i)

                                print("Es una instruccion de direccionamiento relativo")
                                print(num_line_int, "|", data_source_line_n)

                            elif label_inst_acum_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento acumulador cuenta con 1 palabra.
                                cont_mem_pos += 1

                                print("Es una instruccion de direccionamiento acumulador")
                                print(num_line_int, "|", data_source_line_n)

                            elif label_inst_ctrl_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento control cuenta con 1 palabra.
                                cont_mem_pos += 1

                                print("Es una instruccion de direccionamiento control")
                                print(num_line_int, "|", data_source_line_n)

                            elif label_inst_imp_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento implicito cuenta con 1 palabra.
                                cont_mem_pos += 1

                                print("Es una instruccion de direccionamiento implicito")
                                print(num_line_int, "|", data_source_line_n)

                            else:
                                error += 1
                                print("Error!: No valid instruction format.")
                                print(num_line_int, "|", data_source_line_n)


                        elif inst_abs_match or inst_ind_match or inst_inm_match or inst_io_match \
                                or inst_rel_match or inst_acum_match or inst_ctrl_match or inst_imp_match:

                            print("This is an Instruction+Argument entry")

                            if inst_abs_match:

                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento absoluto cuenta con 3 palabras.

                                pc_list.append(cont_mem_pos)

                                inst_abs_key = inst_abs_match.group(1) + "_ABS"

                                print("The opcode for this instruct is:", opcode_dic[inst_abs_key])
                                opcode_abs = opcode_dic[inst_abs_key]

                                oper_abs = inst_abs_match.group(4)

                                oper_dec_match = re.match(regex_oper_dec, oper_abs)
                                if oper_dec_match:
                                    oper_dec = int(oper_dec_match.group(1))
                                    oper_dec_bin = format(oper_dec, '#014b')[-12:]
                                    print("Decimal Operand: ", oper_dec_match.group(1))
                                    print("Decimal to bin Operand: ", oper_dec_bin)
                                    oper_abs_12b = oper_dec_bin

                                oper_oct_match = re.match(regex_oper_oct, oper_abs)
                                if oper_oct_match:
                                    oper_oct = int(oper_oct_match.group(2), 8)
                                    oper_oct_bin = format(oper_oct, '#014b')[-12:]
                                    print("Octal Operand: ", oper_oct)
                                    print("Octal to bin Operand: ", oper_oct_bin)
                                    oper_abs_12b = oper_oct_bin

                                oper_bin_match = re.match(regex_oper_bin, oper_abs)
                                if oper_bin_match:
                                    oper_bin = int(oper_bin_match.group(2), 2)
                                    oper_bin_bin = format(oper_bin, '#014b')[-12:]
                                    print("Binary Operand: ", oper_bin_match.group(2))
                                    print("Bin 2 bin: ", oper_bin_bin)
                                    oper_abs_12b = oper_bin_bin

                                oper_hex_match = re.match(regex_oper_hex, oper_abs)
                                if oper_hex_match:
                                    oper_hex = int(oper_hex_match.group(2), 16)
                                    oper_hex_hex = format(oper_hex, '#08b')[-6:]
                                    print("hexa Operand: ", oper_hex_match.group(2))
                                    print("hex 2 hex: ", oper_hex_hex)
                                    oper_abs_12b = oper_hex_hex


                                # inst_abs_dic = dict(opcode=opcode_abs, oper=oper_abs_12b)
                                # fsm_dic[cont_mem_pos] = inst_abs_dic

                                abs_fi = str(cont_mem_pos) + " " + str(opcode_abs) + " " + str(oper_abs_12b)
                                cont_mem_pos += 3
                                fi_list.append(abs_fi)

                                # fsm_dic[PC, opcode, oper] = cont_mem_pos,opcode_abs,oper_abs
                                # print("FSM DICTIONARY:",fsm_dic)
                                # print("Operand!:", inst_abs_match.group(3))
                                print("This is an absolute instruction+argument:")
                                print(num_line_int, "|", data_source_line_n)

                            elif inst_ind_match:

                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento indirecto cuenta con 3 palabras.

                                pc_list.append(cont_mem_pos)

                                inst_ind_key = inst_ind_match.group(1) + "_IND"
                                print("The opcode for this instruct is:", opcode_dic[inst_ind_key])

                                opcode_ind = opcode_dic[inst_ind_key]
                                oper_ind = inst_ind_match.group(4)
                                inst_ind_dic = dict(opcode=opcode_ind, oper=oper_ind)
                                fsm_dic[cont_mem_pos] = inst_ind_dic

                                oper_dec_match = re.match(regex_oper_dec, oper_ind)
                                if oper_dec_match:
                                    oper_dec = int(oper_dec_match.group(1))
                                    oper_dec_bin = format(oper_dec, '#014b')[-12:]
                                    print("Decimal Operand: ", oper_dec_match.group(1))
                                    print("Decimal to bin Operand: ", oper_dec_bin)
                                    oper_abs_12b = oper_dec_bin

                                oper_oct_match = re.match(regex_oper_oct, oper_ind)
                                if oper_oct_match:
                                    oper_oct = int(oper_oct_match.group(2), 8)
                                    oper_oct_bin = format(oper_oct, '#014b')[-12:]
                                    print("Octal Operand: ", oper_oct)
                                    print("Octal to bin Operand: ", oper_oct_bin)
                                    oper_abs_12b = oper_oct_bin

                                oper_bin_match = re.match(regex_oper_bin, oper_ind)
                                if oper_bin_match:
                                    oper_bin = int(oper_bin_match.group(2), 2)
                                    oper_bin_bin = format(oper_bin, '#014b')[-12:]
                                    print("Binary Operand: ", oper_bin_match.group(2))
                                    print("Bin 2 bin: ", oper_bin_bin)
                                    oper_abs_12b = oper_bin_bin

                                oper_hex_match = re.match(regex_oper_hex, oper_ind)
                                if oper_hex_match:
                                    oper_hex = int(oper_hex_match.group(2), 16)
                                    oper_hex_hex = format(oper_hex, '#08b')[-6:]
                                    print("hexa Operand: ", oper_hex_match.group(2))
                                    print("hex 2 hex: ", oper_hex_hex)
                                    oper_abs_12b = oper_hex_hex

                                ind_fi = str(cont_mem_pos) + " " + str(opcode_ind) + " " + str(oper_abs_12b)
                                cont_mem_pos += 3
                                fi_list.append(ind_fi)


                                # fsm_dic.update(cont_mem_pos=inst_ind_dic)
                                # fsm_dic.update(pc=cont_mem_pos, opcode=opcode_ind, oper=oper_ind)

                                # print("FSM DICTIONARY:",fsm_dic)

                                # print("Operand!:",inst_abs_match.group(3))
                                print("This is an indirect instruction+argument:")
                                print(num_line_int, "|", data_source_line_n)



                            # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                            # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                            elif inst_inm_match:

                                oper_inm = inst_inm_match.group(4)

                                oper_lab_match = re.match(regex_oper_lab, oper_inm)

                                if oper_lab_match:

                                    oper_lab = oper_lab_match.group(1)
                                    print("Decimal oper_lab: ", oper_lab)

                                print("This is an inmediate instruction+argument:")
                                print(num_line_int, "|", data_source_line_n)


                            # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                            # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

                            elif inst_io_match:

                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento IO cuenta con 2 palabras.

                                pc_list.append(cont_mem_pos)

                                inst_io_key = inst_io_match.group(1) + "_IO"
                                print("The opcode for this instruct is:", opcode_dic[inst_io_key])

                                opcode_io = opcode_dic[inst_io_key]
                                oper_io = inst_io_match.group(4)

                                # oper_oct_match = re.match(regex_oper_oct, oper_io)
                                # if oper_oct_match:
                                #     oper_oct = int(oper_oct_match.group(2), 8)
                                #     oper_oct_bin = format(oper_oct, '#014b')[-6:]
                                #     print("Octal Operand: ", oper_oct)
                                #     print("Octal to bin Operand: ", oper_oct_bin)
                                #     oper_abs_12b = oper_oct_bin+"XXXXXX"
                                #

                                oper_dec_match = re.match(regex_oper_dec, oper_io)
                                if oper_dec_match:
                                    oper_dec = int(oper_dec_match.group(1))
                                    oper_dec_bin = format(oper_dec, '#08b')[-6:]
                                    print("Decimal Operand: ", oper_dec_match.group(1))
                                    print("Decimal to bin Operand: ", oper_dec_bin)
                                    oper_abs_12b = oper_dec_bin+"XXXXXX"


                                oper_oct_match = re.match(regex_oper_oct, oper_io)
                                if oper_oct_match:
                                    oper_oct = int(oper_oct_match.group(2), 8)
                                    oper_oct_bin = format(oper_oct, '#08b')[-6:]
                                    print("Octal Operand: ", oper_oct)
                                    print("Octal to bin Operand: ", oper_oct_bin)
                                    oper_abs_12b = oper_oct_bin+"XXXXXX"


                                oper_bin_match = re.match(regex_oper_bin, oper_io)
                                if oper_bin_match:
                                    oper_bin = int(oper_bin_match.group(2), 2)
                                    oper_bin_bin = format(oper_bin, '#08b')[-6:]
                                    print("Binary Operand: ", oper_bin_match.group(2))
                                    print("Bin 2 bin: ", oper_bin_bin)
                                    oper_abs_12b = oper_bin_bin+"XXXXXX"

                                oper_hex_match = re.match(regex_oper_hex, oper_io)
                                if oper_hex_match:
                                    oper_hex = int(oper_hex_match.group(2), 16)
                                    oper_hex_hex = format(oper_hex, '#08b')[-6:]
                                    print("hexa Operand: ", oper_hex_match.group(2))
                                    print("hex 2 hex: ", oper_hex_hex)
                                    oper_abs_12b = oper_hex_hex+"XXXXXX"

                                # inst_io_dic = dict(opcode=opcode_io, oper=oper_abs_12b)
                                # fsm_dic[cont_mem_pos] = inst_io_dic

                                io_fi = str(cont_mem_pos) + " " + str(opcode_io) + " " + str(oper_abs_12b)
                                cont_mem_pos += 2
                                fi_list.append(io_fi)


                                # print("Operand!:",inst_abs_match.group(3))
                                print("This is an IO instruction+argument:")
                                print(num_line_int, "|", data_source_line_n)

                            # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                            # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

                            elif inst_rel_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento relativo cuenta con 2 palabras.


                                # # Se eliminan los comentarios del string.
                                # data_list_x = re.sub(comment_regex, "", data_list_x)
                                # # Se ingresa el nuevo string a su posicion original en la lista.
                                # data_list[x] = data_list_x
                                if i == 0:
                                    print("Bne iter", i)
                                    pc_list.append(cont_mem_pos)
                                    cont_mem_pos += 2
                                else:
                                    print("Bne iter", i)

                                    print("BNE data_list[x]: ", data_list[x])
                                    label_rel = inst_rel_match.group(4)
                                    print("Label_rel", label_rel)

                                    if label_rel in label_dic:
                                        oper_rel = "#"+str(label_dic[label_rel])
                                        print("oper_rel", oper_rel)
                                        # oper_rel = format(oper_rel, '#08b')[-6:]
                                        label_regex = re.compile(r'\b'+re.escape(label_rel)+r'\b', re.IGNORECASE)
                                        data_list_x = re.sub(label_regex,oper_rel, data_list_x)
                                        print("data_list_x: ",data_list_x)
                                        data_list[x] = data_list_x
                                        print("data_list", data_list )


                                # print("Operand!:",inst_abs_match.group(3))
                                print("This is a relative instruction+argument:")
                                print(num_line_int, "|", data_source_line_n)
                            # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
                            # EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

                            elif inst_acum_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento acumulador cuenta con 1 palabra.

                                pc_list.append(cont_mem_pos)

                                inst_acum_key = inst_acum_match.group(1) + "_ACU"
                                print("The opcode for this instruct is:", opcode_dic[inst_acum_key])

                                # opcode_acum = opcode_dic[inst_acum_key]
                                # oper_acum = ""
                                # fsm_dic.update(pc=cont_mem_pos, opcode=opcode_acum, oper=oper_acum)
                                # print("FSM DICTIONARY:",fsm_dic)

                                opcode_acum = opcode_dic[inst_acum_key]
                                oper_acum = "XXXXXXXXXXXX"
                                inst_acum_dic = dict(opcode=opcode_acum, oper=oper_acum)
                                fsm_dic[cont_mem_pos] = inst_acum_dic

                                acum_fi = str(cont_mem_pos) + " " + str(opcode_acum) + " " + str(oper_acum)
                                cont_mem_pos += 1
                                fi_list.append(acum_fi)


                                # print("Operand!:",inst_abs_match.group(1))
                                print("This is an accumulator instruction+argument:")
                                print(num_line_int, "|", data_source_line_n)

                            elif inst_ctrl_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento control cuenta con 1 palabra.

                                pc_list.append(cont_mem_pos)

                                inst_ctrl_key = inst_ctrl_match.group(1) + "_CTR"
                                print("The opcode for this instruct is:", opcode_dic[inst_ctrl_key])

                                # opcode_ctrl = opcode_dic[inst_ctrl_key]
                                # oper_ctrl = "XXXXXXXXXXXX"
                                # fsm_dic.update(pc=cont_mem_pos, opcode=opcode_ctrl, oper=oper_ctrl)
                                # print("FSM DICTIONARY:",fsm_dic)

                                opcode_ctrl = opcode_dic[inst_ctrl_key]
                                oper_ctrl = "XXXXXXXXXXXX"
                                inst_ctrl_dic = dict(opcode=opcode_ctrl, oper=oper_ctrl)
                                fsm_dic[cont_mem_pos] = inst_ctrl_dic

                                ctrl_fi = str(cont_mem_pos) + " " + str(opcode_ctrl) + " " + str(oper_ctrl)
                                cont_mem_pos += 1
                                fi_list.append(ctrl_fi)

                                # print("Operand!:",inst_abs_match.group(2))
                                print("This is an control instruction+argument:")
                                print(num_line_int, "|", data_source_line_n)

                            elif inst_imp_match:
                                # Actualizacion del contador de posicion de memoria.
                                # El direccionamiento implicito cuenta con 1 palabra.

                                pc_list.append(cont_mem_pos)

                                inst_imp_key = inst_imp_match.group(1) + "_IMP"
                                print("The opcode for this instruct is:", opcode_dic[inst_imp_key])

                                # opcode_imp = opcode_dic[inst_imp_key]
                                # oper_ctrl = "XXXXXXXXXXXX"
                                # fsm_dic.update(pc=cont_mem_pos, opcode=opcode_imp, oper=oper_ctrl)
                                # print("FSM DICTIONARY:",fsm_dic)

                                opcode_imp = opcode_dic[inst_imp_key]
                                oper_imp = "XXXXXXXXXXXX"
                                inst_imp_dic = dict(opcode=opcode_imp, oper=oper_imp)
                                fsm_dic[cont_mem_pos] = inst_imp_dic

                                imp_fi = str(cont_mem_pos) + " " + str(opcode_imp) + " " + str(oper_imp)
                                cont_mem_pos += 1
                                fi_list.append(imp_fi)

                                # print("Operand!:",inst_abs_match.group(1))
                                print("This is an implicit instruction+argument:")
                                print(num_line_int, "|", data_source_line_n)

                        else:
                            error += 1
                            print("Error!: No valid argument in line")
                            print(num_line_int, "|", data_source_line_n)
                else:
                    error += 1
                    error_macro = "Error!: Macro is not supported: "+str(num_line_int)+ " | " + non_num_line
                    error_list.append(error_macro)
                    print(error_macro)

            else:
                # print("Error, identificador duplicado",error_list)
                break
    return error, fi_list, error_list


def inst_checker(data_list, lines_raw_list, error, pos_cont_dec):
    global label_rel
    print("Checking instructions\n")

    cont_mem_pos = pos_cont_dec

    # Inicializacion el diccionario de constantes.
    fsm_dic = dict()
    label_dic = dict()
    # opcode_dic = dict()
    # opcode_dic.clear()
    pc_list = []
    fi_list = []

    # Inicializacion el diccionario de constantes.
    opcode_dic = dict(LDA_INM='000000', ADD_INM='010000', SUB_INM='011000', AND_INM='100000',
                      ORA_INM='101000',

                      LDA_ABS='000001', STA_ABS='001001', ADD_ABS='010001', SUB_ABS='011001', AND_ABS='100001',
                      ORA_ABS='101001', JMP_ABS='110001', JSR_ABS='111001', 

                      BEQ_REL='000010', BNE_REL='001010', BCS_REL='010010', BCC_REL='011010', BMI_REL='100010',
                      BPL_REL='101010', BVS_REL='110010', BVC_REL='111010',

                      LDA_IND='000011', STA_IND='001011', ADD_IND='010011', SUB_IND='011011', AND_IND='100011',
                      ORA_IND='101011', JMP_IND='110011', JSR_IND='111011',

                      SEC_IMP='010100', CLC_IMP='011100', SEI_IMP='100100', CLI_IMP='101100',

                      CLA_ACU='000101', CPA_ACU='001101', INA_ACU='010101', DCA_ACU='011101', ROL_ACU='100101',
                      ROR_ACU='101101', PLA_ACU='110101', PHA_ACU='111101',

                      TPA_CTR='000110', TAP_CTR='001110', RTI_CTR='010110', RTS_CTR='011110', HLT_CTR='100110',
                      NOP_CTR='101110', PLS_CTR='110110', PHS_CTR='111110',

                      INP_IO='000111', OUT_IO='001111')

    # Limpia la memoria del diccionario



    # Se identifica si se esta utilizando como etiqueta una palabra reservada.

    regex_macro = re.compile(r"\b^(MACRO|FINMAC)\b(\s)*.*", re.IGNORECASE)

    regex_oper_dec = re.compile(r"^([0-9]+)$", re.IGNORECASE)
    regex_oper_oct = re.compile(r"^(\@)([0-7]{1,4})$", re.IGNORECASE)
    regex_oper_bin = re.compile(r"^(\%)([0-1]{1,6})$", re.IGNORECASE)
    regex_oper_hex = re.compile(r"^(\$)([0-9A-Fa-f]{1,4})$", re.IGNORECASE)

    regex_res_word = re.compile(r"\b(ADD|AND|BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS|CLA|CLC|CLI|CPA|\
                     DCA|HLT|INA|INP|JMP|JSR|LDA|NOP|ORA|OUT|PHA|PHS|PLA|PLS|ROL|ROR|RTI|\
                     RTS|SEC|SEI|STA|SUB|TAP|TPA)\b", re.IGNORECASE)

    regex_label_abs_inst = re.compile(
        r'\b^([a-zA-Z](\w{1,7})?)\b(\s)\b(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(((\@)[0-7]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',
        re.IGNORECASE)
    regex_inst_abs = re.compile(
        r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(((\@)([0-7]{1,4}))|([a-zA-Z](\w{1,7})?)(\+?)(\d*))$',
        re.IGNORECASE)

    regex_label_ind_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))(\))$',
        re.IGNORECASE)
    regex_inst_ind = re.compile(
        r'\b^(LDA|STA|ADD|SUB|AND|ORA|JMP|JSR)\b(\s)(\()((\@)[0-7]{1,4}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))(\))$',
        re.IGNORECASE)

    # Cambios para aceptar operandos hexadecimales.
    regex_label_inm_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)(((\@)[0-7]{1,2}|(\%)[0-1]{1,6}|[0-9]+|(\$)[0-9A-Fa-f]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',
        re.IGNORECASE)
    regex_inst_inm = re.compile(
        r'\b^(LDA|ADD|SUB|AND|ORA)\b(\s)(\#)(((\@)[0-7]{1,2}|(\%)[0-1]{1,6}|[0-9]+|(\$)[0-9A-Fa-f]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$',
        re.IGNORECASE)

    regex_label_io_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s(INP|OUT)\b(\s)(((\@)[0-7]{1,2}|(\%)[0-1]{1,6}|[0-9]+|(\$)[0-9A-Fa-f]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)
    regex_inst_io = re.compile(r'\b^(INP|OUT)\b(\s)(((\@)[0-7]{1,2}|(\%)[0-1]{1,6}|[0-9]+|(\$)[0-9A-Fa-f]{1,4})|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)

    regex_label_rel_inst = re.compile(
        r'^([a-zA-Z](\w{1,7})?)\s\b(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)\b\s([a-zA-Z](\w{1,7})?)$', re.IGNORECASE)
    regex_inst_rel = re.compile(
        r'\b^(BCC|BCS|BEQ|BMI|BNE|BPL|BVC|BVS)\b(\s)([0-7]{1,2}|(([a-zA-Z](\w{1,7})?)(\+?)(\d*)))$', re.IGNORECASE)

    regex_label_acum_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)$', re.IGNORECASE)
    regex_inst_acum = re.compile(r'\b^(CLA|CPA|INA|DCA|ROL|ROR|PLA|PHA)\b$', re.IGNORECASE)

    regex_label_ctrl_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(TPA|TAP|RTI|RTS|HLT|NOP|PLS|PHS)$', re.IGNORECASE)
    regex_inst_ctrl = re.compile(r'\b^(TPA|TAP|RTI|RTS|HLT|NOP|PLS|PHS)\b$', re.IGNORECASE)

    regex_label_imp_inst = re.compile(r'^([a-zA-Z](\w{1,7})?)\s(SEC|CLC|SEI|CLI)$', re.IGNORECASE)
    regex_inst_imp = re.compile(r'\b^(SEC|CLC|SEI|CLI)\b$', re.IGNORECASE)


    for x in range(0, len(data_list)):

        print("MEM position counter updating:", cont_mem_pos)
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
                error += 1
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

                    print("This is an Instruction+Argument entry")

                    if inst_abs_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento absoluto cuenta con 3 palabras.

                        pc_list.append(cont_mem_pos)

                        inst_abs_key = inst_abs_match.group(1) + "_ABS"

                        print("The opcode for this instruct is:", opcode_dic[inst_abs_key])
                        opcode_abs = opcode_dic[inst_abs_key]

                        oper_abs = inst_abs_match.group(4)

                        oper_dec_match = re.match(regex_oper_dec, oper_abs)
                        if oper_dec_match:
                            oper_dec = int(oper_dec_match.group(1))
                            oper_dec_bin = format(oper_dec, '#014b')[-12:]
                            print("Decimal Operand: ", oper_dec_match.group(1))
                            print("Decimal to bin Operand: ", oper_dec_bin)
                            oper_abs_12b = oper_dec_bin

                        oper_oct_match = re.match(regex_oper_oct, oper_abs)
                        if oper_oct_match:
                            oper_oct = int(oper_oct_match.group(2), 8)
                            oper_oct_bin = format(oper_oct, '#014b')[-12:]
                            print("Octal Operand: ", oper_oct)
                            print("Octal to bin Operand: ", oper_oct_bin)
                            oper_abs_12b = oper_oct_bin

                        oper_bin_match = re.match(regex_oper_bin, oper_abs)
                        if oper_bin_match:
                            oper_bin = int(oper_bin_match.group(2), 2)
                            oper_bin_bin = format(oper_bin, '#014b')[-12:]
                            print("Binary Operand: ", oper_bin_match.group(2))
                            print("Bin 2 bin: ", oper_bin_bin)
                            oper_abs_12b = oper_bin_bin

                        oper_hex_match = re.match(regex_oper_hex, oper_abs)
                        if oper_hex_match:
                            oper_hex = int(oper_hex_match.group(2), 16)
                            oper_hex_hex = format(oper_hex, '#08b')[-6:]
                            print("hexa Operand: ", oper_hex_match.group(2))
                            print("hex 2 hex: ", oper_hex_hex)
                            oper_abs_12b = oper_hex_hex


                        # inst_abs_dic = dict(opcode=opcode_abs, oper=oper_abs_12b)
                        # fsm_dic[cont_mem_pos] = inst_abs_dic

                        abs_fi = str(cont_mem_pos) + " " + str(opcode_abs) + " " + str(oper_abs_12b)
                        cont_mem_pos += 3
                        fi_list.append(abs_fi)

                        # fsm_dic[PC, opcode, oper] = cont_mem_pos,opcode_abs,oper_abs
                        # print("FSM DICTIONARY:",fsm_dic)
                        # print("Operand!:", inst_abs_match.group(3))
                        print("This is an absolute instruction+argument:")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_ind_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento indirecto cuenta con 3 palabras.

                        pc_list.append(cont_mem_pos)

                        inst_ind_key = inst_ind_match.group(1) + "_IND"
                        print("The opcode for this instruct is:", opcode_dic[inst_ind_key])

                        opcode_ind = opcode_dic[inst_ind_key]
                        oper_ind = inst_ind_match.group(4)
                        inst_ind_dic = dict(opcode=opcode_ind, oper=oper_ind)
                        fsm_dic[cont_mem_pos] = inst_ind_dic

                        oper_dec_match = re.match(regex_oper_dec, oper_ind)
                        if oper_dec_match:
                            oper_dec = int(oper_dec_match.group(1))
                            oper_dec_bin = format(oper_dec, '#014b')[-12:]
                            print("Decimal Operand: ", oper_dec_match.group(1))
                            print("Decimal to bin Operand: ", oper_dec_bin)
                            oper_abs_12b = oper_dec_bin

                        oper_oct_match = re.match(regex_oper_oct, oper_ind)
                        if oper_oct_match:
                            oper_oct = int(oper_oct_match.group(2), 8)
                            oper_oct_bin = format(oper_oct, '#014b')[-12:]
                            print("Octal Operand: ", oper_oct)
                            print("Octal to bin Operand: ", oper_oct_bin)
                            oper_abs_12b = oper_oct_bin

                        oper_bin_match = re.match(regex_oper_bin, oper_ind)
                        if oper_bin_match:
                            oper_bin = int(oper_bin_match.group(2), 2)
                            oper_bin_bin = format(oper_bin, '#014b')[-12:]
                            print("Binary Operand: ", oper_bin_match.group(2))
                            print("Bin 2 bin: ", oper_bin_bin)
                            oper_abs_12b = oper_bin_bin

                        oper_hex_match = re.match(regex_oper_hex, oper_ind)
                        if oper_hex_match:
                            oper_hex = int(oper_hex_match.group(2), 16)
                            oper_hex_hex = format(oper_hex, '#08b')[-6:]
                            print("hexa Operand: ", oper_hex_match.group(2))
                            print("hex 2 hex: ", oper_hex_hex)
                            oper_abs_12b = oper_hex_hex

                        ind_fi = str(cont_mem_pos) + " " + str(opcode_ind) + " " + str(oper_abs_12b)
                        cont_mem_pos += 3
                        fi_list.append(ind_fi)


                        # fsm_dic.update(cont_mem_pos=inst_ind_dic)
                        # fsm_dic.update(pc=cont_mem_pos, opcode=opcode_ind, oper=oper_ind)

                        # print("FSM DICTIONARY:",fsm_dic)

                        # print("Operand!:",inst_abs_match.group(3))
                        print("This is an indirect instruction+argument:")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_inm_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento inmediato cuenta con 2 palabras.

                        pc_list.append(cont_mem_pos)

                        inst_inm_key = inst_inm_match.group(1) + "_INM"
                        print("The opcode for this instruct is:", opcode_dic[inst_inm_key])

                        # opcode_inm = opcode_dic[inst_inm_key]
                        # oper_inm = inst_inm_match.group(4)
                        # fsm_dic.update(pc=cont_mem_pos, opcode=opcode_inm, oper=oper_inm)

                        opcode_inm = opcode_dic[inst_inm_key]
                        oper_inm = inst_inm_match.group(4)
                        inst_inm_dic = dict(opcode=opcode_inm, oper=oper_inm)
                        fsm_dic[cont_mem_pos] = inst_inm_dic

                        oper_dec_match = re.match(regex_oper_dec, oper_inm)
                        if oper_dec_match:
                            oper_dec = int(oper_dec_match.group(1))
                            oper_dec_bin = format(oper_dec, '#08b')[-6:]
                            print("Decimal Operand: ", oper_dec_match.group(1))
                            print("Decimal to bin Operand: ", oper_dec_bin)
                            oper_abs_12b = oper_dec_bin+"XXXXXX"


                        oper_oct_match = re.match(regex_oper_oct, oper_inm)
                        if oper_oct_match:
                            oper_oct = int(oper_oct_match.group(2), 8)
                            oper_oct_bin = format(oper_oct, '#08b')[-6:]
                            print("Octal Operand: ", oper_oct)
                            print("Octal to bin Operand: ", oper_oct_bin)
                            oper_abs_12b = oper_oct_bin+"XXXXXX"


                        oper_bin_match = re.match(regex_oper_bin, oper_inm)
                        if oper_bin_match:
                            oper_bin = int(oper_bin_match.group(2), 2)
                            oper_bin_bin = format(oper_bin, '#08b')[-6:]
                            print("Binary Operand: ", oper_bin_match.group(2))
                            print("Bin 2 bin: ", oper_bin_bin)
                            oper_abs_12b = oper_bin_bin+"XXXXXX"

                        oper_hex_match = re.match(regex_oper_hex, oper_inm)
                        if oper_hex_match:
                            oper_hex = int(oper_hex_match.group(2), 16)
                            oper_hex_hex = format(oper_hex, '#08b')[-6:]
                            print("hexa Operand: ", oper_hex_match.group(2))
                            print("hex 2 hex: ", oper_hex_hex)
                            oper_abs_12b = oper_hex_hex+"XXXXXX"


                        inm_fi = str(cont_mem_pos) + " " + str(opcode_inm) + " " + str(oper_abs_12b)
                        cont_mem_pos += 2
                        fi_list.append(inm_fi)

                        # print("FSM DICTIONARY:",fsm_dic)

                        # print("Operand!:",inst_abs_match.group(3))
                        print("This is an inmediate instruction+argument:")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_io_match:

                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento IO cuenta con 2 palabras.

                        pc_list.append(cont_mem_pos)

                        inst_io_key = inst_io_match.group(1) + "_IO"
                        print("The opcode for this instruct is:", opcode_dic[inst_io_key])

                        opcode_io = opcode_dic[inst_io_key]
                        oper_io = inst_io_match.group(4)

                        # oper_oct_match = re.match(regex_oper_oct, oper_io)
                        # if oper_oct_match:
                        #     oper_oct = int(oper_oct_match.group(2), 8)
                        #     oper_oct_bin = format(oper_oct, '#014b')[-6:]
                        #     print("Octal Operand: ", oper_oct)
                        #     print("Octal to bin Operand: ", oper_oct_bin)
                        #     oper_abs_12b = oper_oct_bin+"XXXXXX"
                        #

                        oper_dec_match = re.match(regex_oper_dec, oper_io)
                        if oper_dec_match:
                            oper_dec = int(oper_dec_match.group(1))
                            oper_dec_bin = format(oper_dec, '#08b')[-6:]
                            print("Decimal Operand: ", oper_dec_match.group(1))
                            print("Decimal to bin Operand: ", oper_dec_bin)
                            oper_abs_12b = oper_dec_bin+"XXXXXX"


                        oper_oct_match = re.match(regex_oper_oct, oper_io)
                        if oper_oct_match:
                            oper_oct = int(oper_oct_match.group(2), 8)
                            oper_oct_bin = format(oper_oct, '#08b')[-6:]
                            print("Octal Operand: ", oper_oct)
                            print("Octal to bin Operand: ", oper_oct_bin)
                            oper_abs_12b = oper_oct_bin+"XXXXXX"


                        oper_bin_match = re.match(regex_oper_bin, oper_io)
                        if oper_bin_match:
                            oper_bin = int(oper_bin_match.group(2), 2)
                            oper_bin_bin = format(oper_bin, '#08b')[-6:]
                            print("Binary Operand: ", oper_bin_match.group(2))
                            print("Bin 2 bin: ", oper_bin_bin)
                            oper_abs_12b = oper_bin_bin+"XXXXXX"

                        oper_hex_match = re.match(regex_oper_hex, oper_io)
                        if oper_hex_match:
                            oper_hex = int(oper_hex_match.group(2), 16)
                            oper_hex_hex = format(oper_hex, '#08b')[-6:]
                            print("hexa Operand: ", oper_hex_match.group(2))
                            print("hex 2 hex: ", oper_hex_hex)
                            oper_abs_12b = oper_hex_hex+"XXXXXX"

                        # inst_io_dic = dict(opcode=opcode_io, oper=oper_abs_12b)
                        # fsm_dic[cont_mem_pos] = inst_io_dic

                        io_fi = str(cont_mem_pos) + " " + str(opcode_io) + " " + str(oper_abs_12b)
                        cont_mem_pos += 2
                        fi_list.append(io_fi)


                        # print("Operand!:",inst_abs_match.group(3))
                        print("This is an IO instruction+argument:")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_rel_match:
                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento relativo cuenta con 2 palabras.

                        pc_list.append(cont_mem_pos)

                        label_rel = inst_rel_match.group(4)
                        print("Label_rel", label_rel)

                        if label_rel in label_dic:
                            oper_rel = label_dic[label_rel]
                            print("oper_rel", oper_rel)
                            oper_rel = format(oper_rel, '#08b')[-6:]

                        inst_rel_key = inst_rel_match.group(1) + "_REL"
                        print("The opcode for this instruct is:", opcode_dic[inst_rel_key])

                        # opcode_rel = opcode_dic[inst_rel_key]
                        # # cont_mem_pos += VALOR DE ETIQUETA
                        # oper_rel = inst_rel_match.group(4)
                        # fsm_dic.update(pc=cont_mem_pos, opcode=opcode_rel, oper=oper_rel)
                        # print("FSM DICTIONARY:",fsm_dic)

                        opcode_rel = opcode_dic[inst_rel_key]
                        # oper_rel = inst_rel_match.group(4)
                        inst_rel_dic = dict(opcode=opcode_rel, oper=oper_rel)
                        fsm_dic[cont_mem_pos] = inst_rel_dic

                        rel_fi = str(cont_mem_pos) + " " + str(opcode_rel) + " " + str(oper_rel)
                        cont_mem_pos += 2
                        fi_list.append(rel_fi)

                        # print("Operand!:",inst_abs_match.group(3))
                        print("This is a relative instruction+argument:")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_acum_match:
                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento acumulador cuenta con 1 palabra.

                        pc_list.append(cont_mem_pos)

                        inst_acum_key = inst_acum_match.group(1) + "_ACU"
                        print("The opcode for this instruct is:", opcode_dic[inst_acum_key])

                        # opcode_acum = opcode_dic[inst_acum_key]
                        # oper_acum = ""
                        # fsm_dic.update(pc=cont_mem_pos, opcode=opcode_acum, oper=oper_acum)
                        # print("FSM DICTIONARY:",fsm_dic)

                        opcode_acum = opcode_dic[inst_acum_key]
                        oper_acum = "XXXXXXXXXXXX"
                        inst_acum_dic = dict(opcode=opcode_acum, oper=oper_acum)
                        fsm_dic[cont_mem_pos] = inst_acum_dic

                        acum_fi = str(cont_mem_pos) + " " + str(opcode_acum) + " " + str(oper_acum)
                        cont_mem_pos += 1
                        fi_list.append(acum_fi)


                        # print("Operand!:",inst_abs_match.group(1))
                        print("This is an accumulator instruction+argument:")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_ctrl_match:
                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento control cuenta con 1 palabra.

                        pc_list.append(cont_mem_pos)

                        inst_ctrl_key = inst_ctrl_match.group(1) + "_CTR"
                        print("The opcode for this instruct is:", opcode_dic[inst_ctrl_key])

                        # opcode_ctrl = opcode_dic[inst_ctrl_key]
                        # oper_ctrl = "XXXXXXXXXXXX"
                        # fsm_dic.update(pc=cont_mem_pos, opcode=opcode_ctrl, oper=oper_ctrl)
                        # print("FSM DICTIONARY:",fsm_dic)

                        opcode_ctrl = opcode_dic[inst_ctrl_key]
                        oper_ctrl = "XXXXXXXXXXXX"
                        inst_ctrl_dic = dict(opcode=opcode_ctrl, oper=oper_ctrl)
                        fsm_dic[cont_mem_pos] = inst_ctrl_dic

                        ctrl_fi = str(cont_mem_pos) + " " + str(opcode_ctrl) + " " + str(oper_ctrl)
                        cont_mem_pos += 1
                        fi_list.append(ctrl_fi)

                        # print("Operand!:",inst_abs_match.group(2))
                        print("This is an control instruction+argument:")
                        print(num_line_int, "|", data_source_line_n)

                    if inst_imp_match:
                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento implicito cuenta con 1 palabra.

                        pc_list.append(cont_mem_pos)

                        inst_imp_key = inst_imp_match.group(1) + "_IMP"
                        print("The opcode for this instruct is:", opcode_dic[inst_imp_key])

                        # opcode_imp = opcode_dic[inst_imp_key]
                        # oper_ctrl = "XXXXXXXXXXXX"
                        # fsm_dic.update(pc=cont_mem_pos, opcode=opcode_imp, oper=oper_ctrl)
                        # print("FSM DICTIONARY:",fsm_dic)

                        opcode_imp = opcode_dic[inst_imp_key]
                        oper_imp = "XXXXXXXXXXXX"
                        inst_imp_dic = dict(opcode=opcode_imp, oper=oper_imp)
                        fsm_dic[cont_mem_pos] = inst_imp_dic

                        imp_fi = str(cont_mem_pos) + " " + str(opcode_imp) + " " + str(oper_imp)
                        cont_mem_pos += 1
                        fi_list.append(imp_fi)

                        # print("Operand!:",inst_abs_match.group(1))
                        print("This is an implicit instruction+argument:")
                        print(num_line_int, "|", data_source_line_n)

                elif label_inst_abs_match or label_inst_ind_match or \
                        label_inst_inm_match or label_inst_io_match \
                        or label_inst_rel_match or label_inst_acum_match \
                        or label_inst_ctrl_match or label_inst_imp_match:
                    print("Cumple con la condicion de etiqueta de 8 caracteres + instruccion")

                    if label_inst_abs_match:
                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento absoluto cuenta con 3 palabras.
                        cont_mem_pos += 3

                        print("Operand!:", label_inst_abs_match.group(6))
                        print("Es una instruccion de direccionamiento absoluto")
                        print(num_line_int, "|", data_source_line_n)

                    if label_inst_ind_match:
                        # Actualizacion del contador de posicion de memoria.
                        # El direccionamiento absoluto cuenta con 3 palabras.
                        cont_mem_pos += 3

                        print("Es una instruccion de direccionamiento indirecto")
                        print(num_line_int, "|", data_source_line_n)

                    if label_inst_inm_match:

                        label_inm = label_inst_inm_match.group(1)

                        if label_inm in label_dic:

                            print("Error, se esta utilizando la etiqueta: "+label_inm+", en 2 ocasiones.\n")
                            error += 1

                        else:
                            cont_mem_pos += 2
                            label_dic[label_inm] = cont_mem_pos
                            print("Es una instruccion de direccionamiento inmediato")
                            print("Etiqueta:", label_inm)
                            print(num_line_int, "|", data_source_line_n)


                            # Actualizacion del contador de posicion de memoria.
                            # El direccionamiento absoluto cuenta con 3 palabras.




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
                    error += 1
                    print("Error!: No valid instruction format.")
                    print(num_line_int, "|", data_source_line_n)

            else:
                error += 1
                print("Error!: No valid argument in line")
                print(num_line_int, "|", data_source_line_n)
        else:
            error += 1
            print("Error!: Macro is not supported")
            print(num_line_int, "|", non_num_line)

    # print("PC list:", pc_list)
    # print("Format instruction list:",fi_list)
    # print("FINAL FSM DICTIONARY:", fsm_dic)
    #print("Error's detected:", error,"\n")
    #print("Error's detected:", error,"\n")
    return error, fi_list



def obj_creator(fi_list, lines_raw_list):
    # print(fi_list)

    ram_init_file_name = '../clion/ram_init.txt'
    ram_init_file = open(ram_init_file_name, 'w+')

    object_file_name = 'file.obj'
    object_file = open(object_file_name, 'w+')
    pc_file_name = '../clion/pc_init.txt'
    pc_file = open(pc_file_name, 'w+')
    pc_x = ""
    base = 10
    cero = "0"
    base_address = 10
    obj_line_dic = {}
    cont_pos = 0
    dont_care = "XXXXXX"
    # address_int, write_count, opcode_int, operand_pb_int, operand_pa_int = 0

    for fi in fi_list:

        tokens = fi.split()

        address = int(tokens[0])
        if cont_pos == 0:
            pc_x = str(address)
            pc_file.writelines(pc_x)

        opcode = int_2_base(tokens[1],base)
        # print("Addres, opcode:", address, opcode)
        operand = tokens[2]
        operand_pa = operand[0:6]
        operand_pb = operand[6:12]
        # print("Operand,pa,pb", operand, operand_pa, operand_pb)
        address_pos = address

        if operand_pa != dont_care and operand_pb != dont_care:

            # operand_pa_int = int(operand_pa,2)
            # operand_pb_int = int(operand_pb,2)

            operand_pa_int = int_2_base(operand_pa,base)
            operand_pb_int = int_2_base(operand_pb,base)

            mem_data_vec = str(opcode), str(operand_pa_int), str(operand_pb_int)

            for mem_data in mem_data_vec:
                # print("Address: ", address_pos)
                mem_address_pos = address_2_base(address_pos, base_address)
                obj_line = str(mem_address_pos) + " " + mem_data+"\n"
                # obj_line_dic[mem_address_pos].append(mem_data)
                # obj_line_dic = {mem_address_pos:mem_data}
                obj_line_dic[mem_address_pos] = mem_data
                print("Obj line: ", obj_line)
                object_file.writelines(obj_line)
                address_pos += 1

        if operand_pa != dont_care and operand_pb == dont_care:

            operand_pa_int = int_2_base(operand_pa, base)
            mem_data_vec = str(opcode), str(operand_pa_int)
            address_pos = address

            for mem_data in mem_data_vec:
                # print("Address: ", address_pos)
                mem_address_pos = address_2_base(address_pos, base_address)
                obj_line = str(mem_address_pos) + " " + mem_data +"\n"
                # obj_line_dic = {mem_address_pos:mem_data}
                # obj_line_dic[mem_address_pos].append(mem_data)
                obj_line_dic[mem_address_pos] = mem_data
                print("Obj line: ", obj_line)
                object_file.writelines(obj_line)
                address_pos += 1

        if operand_pa == dont_care and operand_pb == dont_care:

            mem_data = str(opcode)
            mem_address_pos = address_2_base(address_pos, base_address)
            obj_line = str(mem_address_pos) + " " + mem_data +"\n"
            # obj_line_dic = {mem_address_pos:mem_data}
            # obj_line_dic[mem_address_pos].append(mem_data)
            obj_line_dic[mem_address_pos] = mem_data
            print("Obj line: ", obj_line)
            object_file.writelines(obj_line)
            address_pos += 1
        cont_pos += 1


    for i in range(0, 4096):

        if i in obj_line_dic:
            ram_init_file.writelines(obj_line_dic[i]+"\n")
            print("obj dic", obj_line_dic[i])
        else:
            ram_init_file.writelines(cero+"\n")

    print("\nram_init_file_name:", ram_init_file_name)
    print("\npc_file_name:", pc_file_name)

def int_2_base(number, base):

    if base == 2:

        number_bin = format(int(number, 2), '#08b')[-6:]

        # print(number_bin)
        return number_bin

    elif base == 8:

        number_oct = oct(int(number,2))
        # print(number_oct)
        return number_oct

    elif base == 10:

        number_dec = int(number,2)
        # print(number_hex)
        return number_dec

    elif base == 16:


        number_hex = format(int(number,2), 'x') # hex(int(number,2))[-6:]
        # print(number_hex)
        return number_hex

def address_2_base(number, base):

    if base == 2:

        number_bin = format(int(number, 2), '#08b')[-6:]

        # print(number_bin)
        return number_bin

    elif base == 8:

        number_oct = oct(int(number))
        # print(number_oct)
        return number_oct

    elif base == 10:

        number_dec = int(number)
        # print(number_hex)
        return number_dec

    elif base == 16:

        number_hex = hex(int(number))
        # print(number_hex)
        return number_hex