__author__ = 'kenneth'

import re

def def_to_int():

    definitions_file_name = 'definitions.cpp'
    definitions_file = open(definitions_file_name, 'r')
    definitions_file_name_dec = 'definitions_dec.cpp'
    definitions_file_dec = open(definitions_file_name_dec, 'w+')
    definitions_file_lines = definitions_file.readlines()

    opcode_regex = re.compile(r'[0-9]+')
    for line in definitions_file_lines:
        # print("Definitions line:", line)
        opcode_match = re.search(opcode_regex, line)

        if opcode_match:
            #print("OK")
            # print(opcode_match.group())
            opcode_int = str(int(opcode_match.group(), 2))
            line = re.sub(opcode_regex, opcode_int, line)
            print("Dec int:", line)
            definitions_file_dec.writelines(line)
            # line = re.sub(opcode_regex, ' ', line)


def main():

    def_to_int()

if __name__ == "__main__": main()
