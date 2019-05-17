import re

mapOffset = 0

buildDate = ""
buildTime = ""

functionList = {
    "WindowHWND": 0,
    "AutoAttack": 0,
    "AutoFire": 0,
    "AutoRun": 0,
    "MouseLook": 0,
    "NetStatus": 0,
    "CollisionCallbackForActors": 0,
    "CastRay": 0,
    "CastRay2": 0,
    "DrawNetStatus": 0,
    "ExecuteCmd": 0,
    "PlayerSpawn": 0,
    "TargetSpawn": 0,
    "EQPlayerManager": 0,
    "EQPlayerManager__GetSpawnByID": 0,
    "EQPlayerManager__GetSpawnByName": 0,
    "EQPlayer__ChangeHeight": 0,
    "EQPlayer__GetLevel": 0,
    "CXWndManager": 0,
    "CXWndManager__DrawWindows": 0,
    "CEverQuest": 0,
    "CEverQuest__DoPercentConvert": 0,
    "CEverQuest__EnterZone": 0,
    "CEverQuest__InterpretCmd": 0,
    "CEverQuest__dsp_chat": 0,
    "CEverQuest__SetGameState": 0,
    "CDisplay": 0,
    "CDisplay__WriteTextHD2": 0,
    "CRender": 0,
}

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

            # mapOffset
            # sub_6A9120(v5, (DWORD)"VERSION", (int)&off_BD6000);    # 0x00BD6000
            matches = re.findall("sub_[0-9A-F]+\([0-9a-z]+, \(DWORD\)\"VERSION\", \(int\)&off_([0-9A-F]+)\);", functionString, re.MULTILINE)
            if matches:
                mapOffset = "0x00" + matches[0]
                print("mapOffset", mapOffset)

            # buildDate
            # buildTime
            # sub_8EEB00("Starting EverQuest (Built %s %s)", "Apr 18 2019", "17:51:12");
            if functionString.find("\"Starting EverQuest (Built %s %s)\"") != -1:
                matches = re.findall("sub_[0-9A-F]+\(\"Starting EverQuest \(Built %s %s\)\", \"(\w+\s+\d+\s+\d+)\", \"(\d+:\d+:\d+)\"\);", functionString, re.MULTILINE)
                if matches:
                    buildDate = matches[0][0]
                    buildTime = matches[0][1]
                    print("buildDate", buildDate)
                    print("buildTime", buildTime)

            # AutoAttack
            # "ExecuteCmd has received a CMD_EXITGAME.\n"
            # ------if ( byte_F2BCEB )    # 0x00F2BCEB
            # --------v37 = sub_8B4BE0((int *)dword_E7F46C, 0x3052u, 0);
            # ------else
            # --------v37 = sub_8B4BE0((int *)dword_E7F46C, 0x3053u, 0);
            if functionString.find("\"ExecuteCmd has received a CMD_EXITGAME.\\n\"") != -1:
                matches = re.findall("if \( byte_([0-9A-F]+) \)\n\s+[0-9a-z]+ = sub_[0-9A-F]+\(\(int \*\)dword_[0-9A-F]+, 0x3052u, 0\);\n", functionString, re.MULTILINE)
                if matches:
                    functionList["AutoAttack"] = "0x00" + matches[0]

            # AutoFire
            # v4 = byte_F2BCEC ? sub_8B4BE0((int *)dword_E7F46C, 0x116u, 0) : sub_8B4BE0((int *)dword_E7F46C, 0x117u, 0);    # 0x00F2BCEC
            # 278 Auto fire on.
            # 279 Auto fire off.
            if functionString.find("0x116u") != -1:
                if functionString.find("0x117u") != -1:
                    matches = re.findall("[0-9a-z]+ = byte_([0-9A-F]+) \? sub_[0-9A-F]+", functionString, re.MULTILINE)
                    if matches:
                        functionList["AutoFire"] = "0x00" + matches[0]

            # AutoRun
            # "I died.\n"
            # ------sub_561710((int)dword_DCCD58, 7, 1);
            # ------dword_E8D058 = 0;    # 0x00E8D058
            if functionString.find("\"I died.\\n\"") != -1:
                matches = re.findall("sub_[0-9A-F]+\(\(int\)dword_[0-9A-F]+, 7, 1\);\n\s+dword_([0-9A-F]+) = 0;\n", functionString, re.MULTILINE)
                if matches:
                    functionList["AutoRun"] = "0x00" + matches[0]

            # MouseLook
            # ("Defaults", "ShowSpellDescriptions", 1, 0);
            # word_E8D03A = 256;    # 0x00E8D03A
            if functionString.find("(\"Defaults\", \"ShowSpellDescriptions\", 1, 0);") != -1:
                matches = re.findall("word_([0-9A-F]+) = 256;\n", functionString, re.MULTILINE)
                if matches:
                    functionList["MouseLook"] = "0x00" + matches[0]

            # NetStatus
            # byte_F30435 = sub_9CFF30("Defaults", "NetStat", 0, 0);    # 0x00F30435
            matches = re.findall("byte_([0-9A-F]+) = sub_[0-9A-F]+\(\"Defaults\", \"NetStat\", 0, 0\);", functionString, re.MULTILINE)
            if matches:
                functionList["NetStatus"] = "0x00" + matches[0]

            # CollisionCallbackForActors
            if functionString.find("v1 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 32))(a1);") != -1:
                if functionString.find("v2 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 48))(a1);") != -1:
                    if functionString.find("v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 12))(v1);") != -1:
                        if functionString.find("v4 = (_BYTE *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 68))(v3);") != -1:
                            functionList["CollisionCallbackForActors"] = functionAddress

            # CastRay
            # if ( sub_59BB10(*(_DWORD *)(v1 + 3884), *(float *)(v1 + 100), *(float *)(v1 + 104), *(float *)(v1 + 108)) )    # 0x0059BB10
            if functionString.find("0x3194u") != -1:    # 12692 %1 is dead, canceling auto-follow.
                if functionString.find("0x3195u") != -1:    # 12693 %1 is too far away, canceling auto-follow.
                    if functionString.find("15.0 <=") != -1:
                        if functionString.find("30.0 <=") != -1:
                            matches = re.findall("if \( sub_([0-9A-F]+)\(\*\(_DWORD \*\)\([0-9a-z]+ \+ \d+\), \*\(float \*\)\([0-9a-z]+ \+ 100\), \*\(float \*\)\([0-9a-z]+ \+ 104\), \*\(float \*\)\([0-9a-z]+ \+ 108\)\) \)", functionString, re.MULTILINE)
                            if matches:
                                functionList["CastRay"] = "0x00" + matches[0]

            # CastRay2
            if functionString.find("&CCollisionInfoLineSegmentVisibility::`vftable';") != -1:
                if functionString.find("\"*** DISCONNECTING: HitBySpell() is throwing a CMD_EXITGAME at %s:%lu\n\"") == -1:
                    functionList["CastRay2"] = functionAddress

            # DrawNetStatus
            if functionString.find("\"%0.2f%%\"") != -1:
                if functionString.find("\"%ldms\"") != -1:
                    functionList["DrawNetStatus"] = functionAddress

            # ExecuteCmd
            if functionString.find("\"ExecuteCmd has received a CMD_EXITGAME.\\n\"") != -1:
                if functionString.find("\"help.html\"") != -1:
                    functionList["ExecuteCmd"] = functionAddress

            # PlayerSpawn
            # if ( dword_E7F5A4 )
            #   sub_8EEB00(
            #     "Local Player's World location at time of crash: %f, %f, %f.\n",
            #     *((float *)dword_E7F5A4 + 25),
            #     *((float *)dword_E7F5A4 + 26),
            #     *((float *)dword_E7F5A4 + 27));    # 0x00E7F5A4
            if functionString.find("\"Local Player's World location at time of crash: %f, %f, %f.\\n\"") != -1:
                matches = re.findall("\*\(\(float \*\)dword_([0-9A-F]+) \+ 27\)\);", functionString, re.MULTILINE)
                if matches:
                    functionList["PlayerSpawn"] = "0x00" + matches[0]

            # TargetSpawn
            # v0 = sub_8B4BE0((int *)dword_E7F46C, 0x3391u, dword_E7F678);    # 0x00E7F678    # 13201 You must first target a corpse to loot!
            if functionString.find("0x3391u") != -1:
                matches = re.findall("[0-9a-z]+ = sub_[0-9A-F]+\(\(int \*\)dword_[0-9A-F]+, 0x3391u, dword_([0-9A-F]+)\);", functionString, re.MULTILINE)
                if matches:
                    functionList["TargetSpawn"] = "0x00" + matches[0]

            # EQPlayerManager
            # EQPlayerManager__GetSpawnByID
            # result = sub_64F690((_DWORD **)dword_F2EED8, *(_DWORD *)(a2 + 16));    # 0x0064F690    # 0x00F2EED8
            # if ( result )
            # {
            #   sub_481AD0((int)&v5, (int)"%s has invited you to join a fellowship, do you wish to accept?", result + 164);
            #   if ( v3 )
            #     v4 = (int)(v3 + 560);
            #   else
            #     v4 = 0;
            #   result = sub_7C0770((int *)dword_104D8E0, v4, 1, (int)&v5, 0xCu, 100000, 0, 0);
            # }
            if functionString.find("\"%s has invited you to join a fellowship, do you wish to accept?\"") != -1:
                matches = re.findall("result = sub_([0-9A-F]+)\(\(_DWORD \*\*\)dword_([0-9A-F]+), \*\(_DWORD \*\)", functionString, re.MULTILINE)
                if matches:
                    functionList["EQPlayerManager__GetSpawnByID"] = "0x00" + matches[0][0]
                    functionList["EQPlayerManager"]               = "0x00" + matches[0][1]

            # EQPlayerManager__GetSpawnByName
            # sub_8EEBD0((int)&v18, 64, (int)"%s`s_Mount00", (int)(v10 + 164));
            # v11 = (char *)sub_64F6B0((_DWORD **)dword_F2EED8, (int)&v18);    # 0x0064F6B0
            if functionString.find("\"%s`s_Mount00\"") != -1:
                matches = re.findall("[0-9a-z]+ = \(char \*\)sub_([0-9A-F]+)\(\(_DWORD \*\*\)dword_[0-9A-F]+, \(int\)&[0-9a-z]+\);", functionString, re.MULTILINE)
                if matches:
                    functionList["EQPlayerManager__GetSpawnByName"] = "0x00" + matches[0]

            # EQPlayer__ChangeHeight
            # v9 = (char *)sub_8B4BE0((int *)dword_E7F46C, 0x32A3u, 0);
            # sub_5BA5A0((int)&Mem, v9, (int)&v15, -1, 0);
            # sub_4E5DA0();
            # sub_4E6440(&Mem, (LPVOID)0x111, (LPVOID)1, (LPVOID)1, 0);
            # v10 = v13;
            # v11 = v12;
            # sub_6572C0(v2, v11, v10, 1.0, 0);    # 0x006572C0
            if functionString.find("0x32A3u") != -1:    # 12963 %1's height changed from %2 to %3.
                if functionString.find("0x32A4u") != -1:    # 12964 Requesting to change %1's height from %2 to %3.
                    matches = re.findall("sub_([0-9A-F]+)\([0-9a-z]+, [0-9a-z]+, [0-9a-z]+, 1.0, 0\);", functionString, re.MULTILINE)
                    if matches:
                        functionList["EQPlayer__ChangeHeight"] = "0x00" + matches[0]

            # EQPlayer__GetLevel
            # if ( !(unsigned __int8)sub_642DC0(v7) && !v7[110] )
            # {
            #   v135 = sub_659850(v7);    # 0x00659850
            #   sub_4A4110(&v178, (int)" (Lvl: %d)", v135);
            # }
            if functionString.find(" (Lvl: %d)") != -1:
                    matches = re.findall("[0-9a-z]+ = sub_([0-9A-F]+)\([0-9a-z]+\);\n\s+sub_[0-9A-F]+\(&[0-9a-z]+, \(int\)\" \(Lvl: %d\)\", [0-9a-z]+\);", functionString, re.MULTILINE)
                    if matches:
                        functionList["EQPlayer__GetLevel"] = "0x00" + matches[0]

            # CXWndManager
            # if ( dword_16C8928 )
            #   sub_9195E0((_BYTE *)dword_16C8928);    # 0x016C8928
            # sub_8EEB00("Resetting UI.");
            # sub_8EEB00("Resetting character select UI.");
            if functionString.find("\"Resetting UI.\"") != -1:
                if functionString.find("\"UI Reset.\"") != -1:
                    matches = re.findall("sub_[0-9A-F]+\(\(_BYTE \*\)dword_([0-9A-F]+)\);", functionString, re.MULTILINE)
                    if matches:
                        functionList["CXWndManager"] = "0x0" + matches[0]

            # CXWndManager__DrawWindows
            if functionString.find("\"DoAllDrawing() failed\\n\"") != -1:
                if functionString.find("-939523968") != -1:
                    if functionString.find("GetTickCount();") != -1:
                        functionList["CXWndManager__DrawWindows"] = functionAddress

            # CEverQuest
            # sub_8EEB00("Gamestate at crash = %d\n", *(_DWORD *)(dword_103C944 + 1480));    # 0x0103C944
            if functionString.find("\"Gamestate at crash = %d\\n\"") != -1:
                matches = re.findall("sub_[0-9A-F]+\(\"Gamestate at crash = %d.n\", \*\(_DWORD \*\)\(dword_([0-9A-F]+) \+ \d+\)\);", functionString, re.MULTILINE)
                if matches:
                    functionList["CEverQuest"] = "0x0" + matches[0]

            # CEverQuest__DoPercentConvert
            # strcpy(v83, "Pet");
            if functionString.find("0x1A6Fu") != -1:    # 6767 Corpse
                if functionString.find("0x1A70u") != -1:    # 6768 NPC
                    if functionString.find("0x1A71u") != -1:    # 6769 Race
                        if functionString.find("strcpy") != -1:
                            if functionString.find("\"Pet\"") != -1:
                                matches = re.findall("strcpy\([0-9a-z]+, \"Pet\"\);", functionString, re.MULTILINE)
                                if matches:
                                    functionList["CEverQuest__DoPercentConvert"] = functionAddress

            # CEverQuest__EnterZone
            # sub_8EEB00("Initializing world.");
            # sub_530C30((int)dword_E7F68C, (int)v2, v3);
            # if ( *(_DWORD *)dword_E7F68C == 1 )
            # {
            #   sub_8EEB00("ERROR: Failed to initialize world!");
            #   *((_DWORD *)v2 + 369) = 1;
            # }
            # else
            # {
            #   sub_8EEB00("Resetting cameras.");
            #   (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E8E67C + 24))(11.0);
            #   (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E8E67C + 32))(500.0);
            #   (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E8E67C + 16))(-1.0);
            #   (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E8E67C + 20))(-7.9990001);
            #   (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E8E67C + 40))(90.0);
            #   sub_8EEB00("Resetting overlays.");
            #   dword_E7F628 = 0;
            #   dword_E7F634 = 0;
            #   dword_E7F62C = 0;
            #   dword_E7F630 = 0;
            #   dword_F2BCF4 = 0;
            #   sub_6A3EA0();
            #   sub_8EEB00("Zone initialized.");
            # }
            if functionString.find("\"Initializing world.\"") != -1:
                if functionString.find("\"Zone initialized.\"") != -1:
                    functionList["CEverQuest__EnterZone"] = functionAddress

            # CEverQuest__InterpretCmd
            if functionString.find("0x21Au") != -1:    # 538 You may not use that command while dead.
                if functionString.find("0x305Cu") != -1:    # 12380 That is not a valid command.  Please use /help.
                    if functionString.find("\"%s %s\"") != -1:
                        if functionString.find("\"#%s %s\"") != -1:
                            functionList["CEverQuest__InterpretCmd"] = functionAddress

            # CEverQuest__dsp_chat
            if functionString.find("\"%s\"") != -1:
                if functionString.find("346") != -1:
                    if functionString.find("& 1") != -1:
                        if functionString.find("& 2") != -1:
                            if functionString.find("& 4") != -1:
                                if functionString.find("& 8") != -1:
                                    if functionString.find("= 3;") != -1:
                                        if functionString.find("= 4;") != -1:
                                            if functionString.find("= 7;") != -1:
                                                    if functionString.find("= 9;") != -1:
                                                        if functionString.find("= 10;") != -1:
                                                            if functionString.find("= 11;") != -1:
                                                                if functionString.find("= 12;") != -1:
                                                                    if functionString.find("= 13;") != -1:
                                                                        if functionString.find("= 14;") != -1:
                                                                            if functionString.find("= 15;") != -1:
                                                                                if functionString.find("= 16;") != -1:
                                                                                    if functionString.find("&= 0xFFFFFFF7;") != -1:
                                                                                        if functionString.find("&= 0xFFFFFFFB;") != -1:
                                                                                            if functionString.find("&= 0xFFFFFFFD;") != -1:
                                                                                                functionList["CEverQuest__dsp_chat"] = functionAddress

            # CEverQuest__SetGameState
            # if ( a2 == 5 )
            # {
            #   sub_599080();
            #   sub_5990A0(538);
            #   sub_5990A0(539);
            #   sub_5990A0(540);
            #   sub_5990A0(541);
            #   sub_5990A0(543);
            #   result = sub_5990A0(542);
            # }
            if functionString.find("== 1") != -1:
                if functionString.find("== 2") != -1:
                    if functionString.find("== 5") != -1:
                        if functionString.find("(538);") != -1:
                            if functionString.find("(539);") != -1:
                                if functionString.find("(540);") != -1:
                                    if functionString.find("(541);") != -1:
                                        if functionString.find("(361);") != -1:
                                            if functionString.find("(534);") != -1:
                                                if functionString.find("(406);") != -1:
                                                    if functionString.find("(4);") != -1:
                                                        if functionString.find("(543);") != -1:
                                                            if functionString.find("(542);") != -1:
                                                                if functionString.find("(5);") != -1:
                                                                    matches = re.findall("result = sub_[0-9A-F]+\(542\);", functionString, re.MULTILINE)
                                                                    if matches:
                                                                        functionList["CEverQuest__SetGameState"] = functionAddress

            # CDisplay
            # *(_DWORD *)v12 = 1413693791;
            # *((_DWORD *)v12 + 1) = 1162105423;
            # *((_WORD *)v12 + 4) = 70;
            # sub_533A50(*(float *)&dword_E7F68C, a1, a2, a3, a4, a5, a6, a7, 0.0, a8, 0, 1, 2, 1, 0);    # 0x00E7F68C
            if functionString.find("1413693791") != -1:
                if functionString.find("1162105423") != -1:
                    matches = re.findall("sub_[0-9A-F]+\(\*\(float \*\)&dword_([0-9A-F]+), [0-9a-z]+, [0-9a-z]+, [0-9a-z]+, [0-9a-z]+, [0-9a-z]+, [0-9a-z]+, [0-9a-z]+, 0.0, [0-9a-z]+, 0, 1, 2, 1, 0\);", functionString, re.MULTILINE)
                    if matches:
                        functionList["CDisplay"] = "0x0" + matches[0]

            # CDisplay__WriteTextHD2
            if functionString.find("> 125") != -1:
                if functionString.find("<= 255") != -1:
                    if functionString.find("-16777216") != -1:
                        if functionString.find("-16744448") != -1:
                            if functionString.find("-16777088") != -1:
                                if functionString.find("-1048336") != -1:
                                    if functionString.find("-8355712") != -1:
                                        if functionString.find("-2039584") != -1:
                                            if functionString.find("-986896") != -1:
                                                if functionString.find("-6250336") != -1:
                                                    if functionString.find("-1048576") != -1:
                                                        if functionString.find("-16715776") != -1:
                                                            if functionString.find("-987136") != -1:
                                                                if functionString.find("-16776976") != -1:
                                                                    if functionString.find("-16777041") != -1:
                                                                        if functionString.find("-16715536") != -1:
                                                                            if functionString.find("-10461088") != -1:
                                                                                functionList["CDisplay__WriteTextHD2"] = functionAddress

            # CRender
            # HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam
            # if ( !(*(unsigned __int8 (__stdcall **)(signed int))(*(_DWORD *)dword_16C9768 + 100))(1) )    # 0x016C9768
            if functionString.find("return DefWindowProcA") != -1:
                if functionString.find("\"ResetDevice() failed!\"") != -1:
                    matches = re.findall("\(\*\(_DWORD \*\)dword_([0-9A-F]+) \+ 100\)\)", functionString, re.MULTILINE)
                    if matches:
                        functionList["CRender"] = "0x0" + matches[0]
            
            functionString = ""

if mapOffset != 0:
    with open("eqgame.map", "rt") as in_file:
        lines = in_file.readlines()
        for index, line in enumerate(lines):

            # WindowHWND
            if line.find("       hWnd\n") != -1:
                matches = re.findall(" \d+:([0-9A-F]+)       hWnd\n", line)
                if matches:
                    hWnd = int(matches[0], 16) + int(mapOffset, 0)
                    functionList["WindowHWND"] = "0x00" + str(hex(hWnd).upper()[2:])

for k, v in functionList.items():
    print(k, v)

print("")

# EQ_InitializeAddresses()
print("void EQ_InitializeAddresses()")
print("{")
print("    // " + buildDate + " " + buildTime)
print("")
print("    EQ_ADDRESS_WindowHWND = " + functionList["WindowHWND"] + ";")
print("")
print("    EQ_ADDRESS_AutoAttack    = " + functionList["AutoAttack"] + ";")
print("    EQ_ADDRESS_AutoRun       = " + functionList["AutoRun"] + ";")
print("    EQ_ADDRESS_MouseLook     = " + functionList["MouseLook"] + ";")
print("    EQ_ADDRESS_NetStatus     = " + functionList["NetStatus"] + ";")
print("")
print("    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = " + functionList["CollisionCallbackForActors"] + ";")
print("    EQ_ADDRESS_FUNCTION_CastRay                       = " + functionList["CastRay"] + ";")
print("    EQ_ADDRESS_FUNCTION_CastRay2                      = " + functionList["CastRay2"] + ";")
print("    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = " + functionList["DrawNetStatus"] + ";")
print("    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = " + functionList["ExecuteCmd"] + ";")
print("")
print("    EQ_ADDRESS_POINTER_PlayerSpawn    = " + functionList["PlayerSpawn"] + ";")
print("    EQ_ADDRESS_POINTER_TargetSpawn    = " + functionList["TargetSpawn"] + ";")
print("")
print("    EQ_ADDRESS_POINTER_EQPlayerManager = " + functionList["EQPlayerManager"] + ";")
print("    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = " + functionList["EQPlayerManager__GetSpawnByID"] + ";")
print("    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = " + functionList["EQPlayerManager__GetSpawnByName"] + ";")
print("")
print("    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = " + functionList["EQPlayer__ChangeHeight"] + ";")
print("    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel        = " + functionList["EQPlayer__GetLevel"] + ";")
print("")
print("    EQ_ADDRESS_POINTER_CXWndManager = " + functionList["CXWndManager"] + ";")
print("    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = " + functionList["CXWndManager__DrawWindows"] + ";")
print("")
print("    EQ_ADDRESS_POINTER_CEverQuest = " + functionList["CEverQuest"] + ";")
print("    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert    = " + functionList["CEverQuest__DoPercentConvert"] + ";")
print("    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone           = " + functionList["CEverQuest__EnterZone"] + ";")
print("    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd        = " + functionList["CEverQuest__InterpretCmd"] + ";")
print("    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat            = " + functionList["CEverQuest__dsp_chat"] + ";")
print("    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState        = " + functionList["CEverQuest__SetGameState"] + ";")
print("")
print("    EQ_ADDRESS_POINTER_CDisplay = " + functionList["CDisplay"] + ";")
print("    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2    = " + functionList["CDisplay__WriteTextHD2"] + ";")
print("")
print("    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime")
print("    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime")
print("")
print("    EQ_ADDRESS_POINTER_CRender = " + functionList["CRender"] + ";")
print("    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime")
print("    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime")
print("    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime")
print("    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime")
print("}")