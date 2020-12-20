import re

functionList = {
    "Offset_CMapViewMap__Lines": 0,
    "Offset_CMapViewMap__Labels": 0,
}

functionAddress = ""
functionString = ""

insideFunction = 0
numLines = 0

with open("eqgame.asm", "rt") as in_file:
    lines = in_file.readlines()
    for index, line in enumerate(lines):

        if line.find("align 10h") != -1:
            if insideFunction == 0:
                insideFunction = 1
            else:
                insideFunction = 0

        if insideFunction == 1:

            functionString += line
            numLines += 1

        if insideFunction == 0:

            # Offset_CMapViewMap__Lines
            # Offset_CMapViewMap__Labels
            # ----------------------------------------------------------------------------------------------------
            #                 push    ebp
            #                 mov     ebp, esp
            #                 push    0FFFFFFFFh
            #                 push    offset sub_ABCC9E
            #                 mov     eax, large fs:0
            #                 push    eax
            #                 mov     large fs:0, esp
            #                 push    ecx
            #                 push    esi
            #                 mov     esi, ecx
            #                 lea     ecx, [ebp-10h]
            #                 push    offset aMapviewmap ; "MapViewMap"
            #                 mov     [ebp-10h], esi
            #                 call    sub_901250
            #                 push    0
            #                 push    1
            #                 push    0FFFFFFFFh
            #                 lea     eax, [ebp-10h]
            #                 mov     dword ptr [ebp-4], 0
            #                 push    eax
            #                 push    0
            #                 mov     ecx, esi
            #                 call    sub_944DE0
            #                 mov     eax, [ebp-10h]
            #                 mov     dword ptr [ebp-4], 1
            #                 test    eax, eax
            #                 jz      short loc_78387D
            #                 push    eax
            #                 lea     ecx, [ebp-10h]
            #                 call    sub_903680
            #
            # loc_78387D:                             ; CODE XREF: .text:00783872?j
            #                 fldz
            #                 mov     eax, esi
            #                 mov     ecx, [ebp-0Ch]
            #                 mov     dword ptr [esi], offset off_B1E058
            #                 mov     dword ptr [esi+2D0h], 0
            #                 fstp    dword ptr [esi+2B8h]
            #                 mov     dword ptr [esi+1Ch], 480h
            #                 mov     dword ptr [esi+258h], 0    # 0x258 = Lines
            #                 mov     dword ptr [esi+25Ch], 0    # 0x25C = Labels
            #                 mov     dword ptr [esi+260h], 0
            #                 mov     byte ptr [esi+264h], 0
            #                 mov     dword ptr [esi+298h], 0
            #                 mov     dword ptr [esi+29Ch], 0
            #                 mov     dword ptr [esi+2A0h], 0
            #                 mov     dword ptr [esi+274h], 0FF000000h
            #                 mov     dword ptr [esi+278h], 0FF000000h
            #                 mov     dword ptr [esi+27Ch], 0FF000000h
            #                 mov     dword ptr [esi+280h], 0FFFF0000h
            #                 mov     word ptr [esi+2C4h], 101h
            #                 mov     dword ptr [esi+2A4h], 0Fh
            #                 mov     dword ptr [esi+2A8h], 1
            #                 mov     dword ptr [esi+2ACh], 0Ah
            #                 mov     dword ptr [esi+2B0h], 0Ah
            #                 mov     byte ptr [esi+2B4h], 0
            #                 mov     byte ptr [esi+2C6h], 1
            #                 mov     byte ptr [esi+284h], 0
            #                 pop     esi
            #                 mov     large fs:0, ecx
            #                 mov     esp, ebp
            #                 pop     ebp
            #                 retn
            if functionString.find("push    offset aMapviewmap ; \"MapViewMap\"") != -1:
                if functionString.find("offset off_") != -1:
                    print("found aMapviewmap and offset off_")
                    print(functionAddress)
                    matches = re.findall("mov\s+dword ptr \[[a-z]+\+[0-9A-F]+h\], 480h\n\s+mov\s+dword ptr \[[a-z]+\+([0-9A-F]+)h\], 0\n\s+mov\s+dword ptr \[[a-z]+\+([0-9A-F]+)h\], 0\n", functionString, re.MULTILINE)
                    if matches:
                        functionList["Offset_CMapViewMap__Lines"] = "0x" + matches[0][0]
                        functionList["Offset_CMapViewMap__Labels"] = "0x" + matches[0][1]
                        
                        for k, v in sorted(functionList.items()):
                            print(k, v)

            functionString = ""
            numLines = 0

for k, v in sorted(functionList.items()):
    print(k, v)
    if v == 0:
        quit()
