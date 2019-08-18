import re

functionAddress = ""
functionString = ""

insideFunction = 0

with open("eqgame.c", "rt") as in_file:
    lines = in_file.readlines()
    for index, line in enumerate(lines):

        if line == "{\n":
            insideFunction = 1

        if line == "}\n":
            insideFunction = 0

        if line.find("//----- (") != -1:
            matches = re.findall("([0-9A-F]+)", line)
            if matches:
                functionAddress = "0x" + matches[0]
                # print(functionAddress)

        if insideFunction == 1:

            functionString += line

        if insideFunction == 0:

            if functionString.find("DD84D0") != -1:    # address
                if functionString.find("sub_8B7230") != -1:    # StringTable__getString()
                    if re.search("0x[0-9A-F]+u", functionString):
                        print(functionAddress)

            functionString = ""