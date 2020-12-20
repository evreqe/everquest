import re

functionList = {
    "Offset_EQCharacter__ExtendedTargetList": 0,
}

functionAddress = ""
functionString = ""

insideFunction = 0
numLines = 0

with open("eqgame.asm", "rt") as in_file:
    lines = in_file.readlines()
    for index, line in enumerate(lines):

        if re.search("sub_[0-9A-F]+\s+proc near", line):
            insideFunction = 1

        if re.search("sub_[0-9A-F]+\s+endp", line):
            insideFunction = 0
            numLines += 1

        if line.find("proc near") != -1:
            matches = re.findall("sub_([0-9A-F]+)\s+proc near", line)
            if matches:
                functionAddress = "0x00" + matches[0]
                # print(functionAddress)

        if insideFunction == 1:

            functionString += line
            numLines += 1

        if insideFunction == 0:

            # Offset_EQCharacter__ExtendedTargetList
            # ----------------------------------------------------------------------------------------------------
            # sub_646FD0      proc near               ; CODE XREF: sub_5CBE00+73B?p
            #                                         ; sub_61CB00+5AF?p ...
            #                 mov     eax, [ecx+2838h]    # 0x2838
            #                 mov     al, [eax+14h]       # 0x284C = EQ_OFFSET_EQ_Character____GroupInfo = EQ_OFFSET_EQ_Character____ExtendedTargetList + 0x14
            #                 retn
            # sub_646FD0      endp
            if numLines > 2 and numLines < 10:
                if functionString.find("mov     al, [eax+14h]") != -1:
                    print(functionAddress)
                    print(functionString)
                    matches = re.findall("mov\s+eax, \[ecx\+(\d+)h\]\n\s+mov\s+al, \[eax\+14h\]\n\s+retn", functionString, re.MULTILINE)
                    if matches:
                        print(matches[0])
                        functionList["Offset_EQCharacter__ExtendedTargetList"] = int(matches[0])

            functionString = ""
            numLines = 0

for k, v in sorted(functionList.items()):
    print(k, v)
    if v == 0:
        quit()
