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
    "DoSpellEffect": 0,
    "PlaySoundAtLocation": 0,
    "GetTime": 0,
    "EQZoneInfo": 0,
    "PlayerSpawn": 0,
    "TargetSpawn": 0,
    "StringTable": 0,
    "StringTable__getString": 0,
    "CDBStr": 0,
    "CDBStr__GetString": 0,
    "EQPlayerManager": 0,
    "EQPlayerManager__GetSpawnByID": 0,
    "EQPlayerManager__GetSpawnByName": 0,
    "EQPlayer__ChangeHeight": 0,
    "EQPlayer__GetLevel": 0,
    "EQPlayer__FollowPlayerAI": 0,
    "EQPlayer__UpdateItemSlot": 0,
    "EQPlayer__IsTargetable": 0,
    "EQSwitchManager": 0,
    "EQSwitch__UseSwitch": 0,
    "EQSwitch__ChangeState": 0,
    "CXWndManager": 0,
    "CXWndManager__DrawWindows": 0,
    "CXWnd__IsReallyVisible": 0,
    "CEverQuest": 0,
    "CEverQuest__DoPercentConvert": 0,
    "CEverQuest__EnterZone": 0,
    "CEverQuest__InterpretCmd": 0,
    "CEverQuest__dsp_chat": 0,
    "CEverQuest__SetGameState": 0,
    "CEverQuest__LMouseUp": 0,
    "CEverQuest__RMouseUp": 0,
    "CEverQuest__HandleMouseWheel": 0,
    "CEverQuest__StartCasting": 0,
    "CDisplay": 0,
    "CDisplay__WriteTextHD2": 0,
    "CDisplay__CreateActor": 0,
    "CDisplay__CreatePlayerActor": 0,
    "CDisplay__DeleteActor": 0,
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

            # DoSpellEffect
            if functionString.find("\"Source\"") != -1:
                if functionString.find("\"%sSPELL_POINT_DAG\"") != -1:
                    if functionString.find("\"***DAG Error DAG = %08x\"") != -1:
                        functionList["DoSpellEffect"] = functionAddress

            # PlaySoundAtLocation
            # void __stdcall sub_53A330(float a1, float a2, float a3, int a4)    # 0x0053A330
            # {
            #   char v4; // [esp+0h] [ebp-30h]
            #   float v5; // [esp+10h] [ebp-20h]
            #   float v6; // [esp+14h] [ebp-1Ch]
            #   float v7; // [esp+18h] [ebp-18h]
            #   float v8; // [esp+1Ch] [ebp-14h]
            #   float v9; // [esp+20h] [ebp-10h]
            #   int v10; // [esp+28h] [ebp-8h]
            #
            #   sub_671CD0((float *)&v4);
            #   v5 = a1;
            #   v6 = a2;
            #   v7 = a3;
            #   v8 = 5.0;
            #   v9 = 80.0;
            #   v10 = 0;
            #   sub_561A20(dword_DCDD68, a4, (int)&v4);
            # }
            if functionString.find("= a1;") != -1:
                if functionString.find("= a2;") != -1:
                    if functionString.find("= a3;") != -1:
                        if functionString.find("= 5.0;") != -1:
                            if functionString.find("= 80.0;") != -1:
                                if functionString.find("= 0;") != -1:
                                    if functionString.find(", a4,") != -1:
                                        functionList["PlaySoundAtLocation"] = functionAddress

            # GetTime
            # DWORD sub_8EEB80()    # 0x008EEB80
            # {
            #   return GetTickCount() - dword_16C8F20;
            # }
            if functionString.find("return GetTickCount() - ") != -1:
                matches = re.findall("return GetTickCount\(\) - dword_([0-9A-F]+);", functionString, re.MULTILINE)
                if matches:
                    functionList["GetTime"] = functionAddress

            # EQZoneInfo
            # if ( dword_E816AC )
            # {
            #   sub_8F0550("Item done, MSG_WEATHER_EVENT received.\n");
            #   v1008 = a15;
            #   dword_E8F63C = 1;
            #   if ( a15 )
            #     sub_593A70(byte_E8F240, *(_BYTE *)(v1008 + 12));    # 0x00E8F240
            #   v100 = sub_65F720();
            #   sub_65FC10(v100, (_DWORD *)v1008);
            # }
            if functionString.find("\"Item done, MSG_WEATHER_EVENT received.\\n\"") != -1:
                matches = re.findall("sub_[0-9A-F]+\(\"Item done, MSG_WEATHER_EVENT received..n\"\);\n.*\n.*\n.*\n.*sub_[0-9A-F]+\(byte_([0-9A-F]+),", functionString, re.MULTILINE)
                if matches:
                    functionList["EQZoneInfo"] = "0x00" + matches[0]

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

            # StringTable
            # switch ( a1 )
            # {
            #   case 1:
            #     result = sub_8B5330((int *)dword_E80480, 0x5DEu, 0);    # 0x00E80480
            #     break;
            #   case 2:
            #     result = sub_8B5330((int *)dword_E80480, 0x5E2u, 0);
            #     break;
            #   case 3:
            #     result = sub_8B5330((int *)dword_E80480, 0x5E6u, 0);
            #     break;
            #   case 4:
            #     result = sub_8B5330((int *)dword_E80480, 0x5EEu, 0);
            #     break;
            if functionString.find("0x5DEu") != -1:    # 1502 Warrior
                if functionString.find("0x5E2u") != -1:    # 1506 Cleric
                    if functionString.find("0x5E6u") != -1:    # 1510 Paladin
                        if functionString.find("0x5EEu") != -1:    # 1514 Shadow Knight
                            matches = re.findall("result = sub_[0-9A-F]+\(\(int \*\)dword_([0-9A-F]+), 0x5DEu, 0\);", functionString, re.MULTILINE)
                            if matches:
                                functionList["StringTable"] = "0x00" + matches[0]

            # StringTable__getString
            # sub_4818F0((int)&unk_108DA10, (int)"%s (%d)", (int)off_C5D5DC);
            if functionString.find("%s (%d)") != -1:
                if re.search("sub_[0-9A-F]+\(\(int\)&unk_[0-9A-F]+, \(int\)\"%s \(%d\)\", \(int\)off_[0-9A-F]+\);", functionString):
                    functionList["StringTable__getString"] = functionAddress

            # CDBStr
            # v3 = "Unknown AA";
            # if ( dword_DCBB6C )    # 0x00DCBB6C
            #   v3 = sub_52FC80(dword_DCBB6C, this[4], 1u, 0);    # 0x00DCBB6C
            # sub_599A20((int)&v8, 0xE6Fu, (int)v3, 0, 0, 0, 0, 0, 0, 0, 0);
            # sub_8EB050(&lpMem, &v8);
            if functionString.find("Unknown AA") != -1:
                if functionString.find("0xE6Fu") != -1:    # 3695 AA: %1
                    matches = re.findall("[0-9a-z]+ = sub_[0-9A-F]+\(dword_([0-9A-F]+), this\[\d+\], 1u, 0\);", functionString, re.MULTILINE)
                    if matches:
                        functionList["CDBStr"] = "0x00" + matches[0]

            # CDBStr__GetString
            if functionString.find("\"Unknown DB String %d-%d\"") != -1:
                functionList["CDBStr__GetString"] = functionAddress

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
            if functionString.find("\" (Lvl: %d)\"") != -1:
                    matches = re.findall("[0-9a-z]+ = sub_([0-9A-F]+)\([0-9a-z]+\);\n\s+sub_[0-9A-F]+\(&[0-9a-z]+, \(int\)\" \(Lvl: %d\)\", [0-9a-z]+\);", functionString, re.MULTILINE)
                    if matches:
                        functionList["EQPlayer__GetLevel"] = "0x00" + matches[0]

            # EQPlayer__FollowPlayerAI
            if functionString.find("0x3194u") != -1:    # 12692 %1 is dead, canceling auto-follow.
                if functionString.find("0x3195u") != -1:    # 12693 %1 is too far away, canceling auto-follow.
                    if functionString.find("> 200.0") != -1:
                        if functionString.find(">= 20.0") != -1:
                            if functionString.find("+ 15.0 <=") != -1:
                                if functionString.find("+ 30.0 <=") != -1:
                                    functionList["EQPlayer__FollowPlayerAI"] = functionAddress

            # EQPlayer__UpdateItemSlot
            if functionString.find("IT36") != -1:
                if functionString.find("IT159") != -1:
                    if functionString.find("IT10758") != -1:
                        if functionString.find("IT10742") != -1:
                            functionList["EQPlayer__UpdateItemSlot"] = functionAddress

            # EQPlayer__IsTargetable
            # if ( !sub_97D670(v2) || sub_6574C0((int *)dword_E805BC, (int *)v3, 1) )    # 0x0097D670
            # {
            #   v4 = sub_8B5330((int *)dword_E80480, 0x12Fu, 0);
            #   sub_4E5B40();
            #   sub_4E61E0(v4, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            # }
            # else
            # {
            #   dword_E80690 = v3;
            # }
            if functionString.find("0x12Fu") != -1:    # 303 I don't see anyone by that name around here...
                matches = re.findall("if \( \!sub_([0-9A-F]+)\([0-9a-z]+\) \|\| sub_[0-9A-F]+\(\(int \*\)dword_[0-9A-F]+, \(int \*\)[0-9a-z]+, 1\) \)", functionString, re.MULTILINE)
                if matches:
                    functionList["EQPlayer__IsTargetable"] = "0x00" + matches[0]

            # EQSwitchManager
            # sub_8C5830((_DWORD *)dword_E815A8, a2, (int)&v6);
            # v2 = &v5;
            # do
            # v3 = (v2++)[1];
            # while ( v3 );
            # *(_DWORD *)v2 = 1769435999;
            # *((_DWORD *)v2 + 1) = 1701340020;
            # *((_DWORD *)v2 + 2) = 2020879987;
            # *((_WORD *)v2 + 6) = 116;
            # sub_5CDC50(dword_E7F110, a1);
            # return sub_5CD400((int *)dword_E7F110, &v6, 0);    # 0x00E7F110
            if functionString.find("= 1769435999;") != -1:
                if functionString.find("= 1701340020;") != -1:
                    if functionString.find("= 2020879987;") != -1:
                        if functionString.find("= 116;") != -1:
                            matches = re.findall("sub_[0-9A-F]+\(\(int \*\)dword_([0-9A-F]+), &[0-9a-z]+, 0\);", functionString, re.MULTILINE)
                            if matches:
                                functionList["EQSwitchManager"] = "0x00" + matches[0]

            # EQSwitch__UseSwitch
            if functionString.find("!= 54") != -1:
                if functionString.find("!= 55") != -1:
                    if functionString.find("== -98") != -1:
                        if functionString.find("== -99") != -1:
                            if functionString.find(" * 0.0099999998") != -1:
                                if functionString.find(", 4,") != -1:
                                    if functionString.find(", 3,") != -1:
                                        if functionString.find(", 2,") != -1:
                                            if functionString.find("1462, (LPVOID)0xA);") != -1:    # 1462 You can't reach that, get closer.
                                                functionList["EQSwitch__UseSwitch"] = functionAddress

            # EQSwitch__ChangeState
            if functionString.find("!= 57") != -1:
                if functionString.find("!= 58") != -1:
                    if functionString.find("!= -97") != -1:
                        if functionString.find("!= -96") != -1:
                            if functionString.find("!= -95") != -1:
                                if functionString.find("== 2") != -1:
                                    if functionString.find("== 3") != -1:
                                        functionList["EQSwitch__ChangeState"] = functionAddress

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

            # CXWnd__IsReallyVisible
            # v4 = this;
            # if ( !sub_917EF0((int)this) )    # 0x00917EF0
            #   return 1;
            # if ( v4[733]
            #   && dword_E815BC
            #   && *((_DWORD *)dword_E815BC + 347) == *((_DWORD *)v4 + 185)
            #   && (dword_F30F80 && *(_BYTE *)dword_F30F80 || v4[668]) )
            # {
            #   v5 = sub_8B6670((int *)dword_E81480, 0x1553u, 0);
            #   sub_4E5910();
            #   sub_4E5FB0(v5, (LPVOID)0xF, (LPVOID)1, (LPVOID)1, 0);
            #   return 0;
            # }
            if functionString.find("0x1553u") != -1:    # 5459 Manually zooming and panning is disabled when the map is in Find mode and the "Auto-Find" button is active.  If you wish to manually adjust the map while in Find mode, then disable the "Auto-Find" button.
                if functionString.find(" * 1.5;") != -1:
                    if functionString.find(" * 0.66666669;") != -1:
                        if functionString.find(" < 1.0 )") != -1:
                            matches = re.findall("if \( \!sub_([0-9A-F]+)\(\(int\)this\) \)\n\s+return 1;", functionString, re.MULTILINE)
                            if matches:
                                functionList["CXWnd__IsReallyVisible"] = "0x00" + matches[0]

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

            # CEverQuest__LMouseUp
            if functionString.find("while ( ShowCursor(1) < 0 )") != -1:
                if functionString.find("SetCursorPos") != -1:
                    if functionString.find("\"POINT1\"") != -1:
                        if functionString.find("\"POINT2\"") != -1:
                            if functionString.find("\"POINT3\"") != -1:
                                if functionString.find("\"POINT4\"") != -1:
                                    if functionString.find("0x3020u") != -1: # 12320 You currently cannot drop items.  Goto General Options or use /fastdrop to enable dropping.
                                        functionList["CEverQuest__LMouseUp"] = functionAddress

            # CEverQuest__RMouseUp
            if functionString.find("while ( ShowCursor(1) < 0 )") != -1:
                if functionString.find("SetCursorPos") != -1:
                    if functionString.find("-572662307") != -1:
                        if functionString.find("858993459") != -1:
                            if functionString.find("572662306") != -1:
                                functionList["CEverQuest__RMouseUp"] = functionAddress

            # CEverQuest__HandleMouseWheel
            # v19 = 100.0;
            # v20 = fabs(v3[379] - v18);
            # if ( v20 < 5.0 )
            #   v19 = v20 * 0.2 * 90.0 + 10.0;
            if functionString.find("fabs") != -1:
                if functionString.find(" = 53.0;") != -1:
                    if functionString.find(" = 212.0;") != -1:
                        if functionString.find(" = 100.0;") != -1:
                            if functionString.find(" * 0.2 * 90.0 + 10.0;") != -1:
                                functionList["CEverQuest__HandleMouseWheel"] = functionAddress

            # CEverQuest__StartCasting
            if functionString.find("8152") != -1:    # 8152 %1 begins singing %2.
                if functionString.find("12205") != -1:    # 12205 You begin casting %1.
                    if functionString.find("12206") != -1:    # 12206 %1 begins casting %2.
                        if functionString.find(", 0, 500);") != -1:
                            if functionString.find(", 99);") != -1:
                                functionList["CEverQuest__StartCasting"] = functionAddress

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

            # CDisplay__CreateActor
            if functionString.find("\"PLAYER_1\"") != -1:
                if functionString.find("\"BBBOARD\"") != -1:
                    if functionString.find("\"IT\"") != -1:
                        functionList["CDisplay__CreateActor"] = functionAddress

            # CDisplay__CreatePlayerActor
            if functionString.find("\"CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. actor_tag=%s\\n\"") != -1:
                if functionString.find("\"OBP_SPELLTREE_ACTORDEF\"") != -1:
                    if functionString.find("\"HUM_ACTORDEF\"") != -1:
                        if functionString.find("\"HUF_ACTORDEF\"") != -1:
                            functionList["CDisplay__CreatePlayerActor"] = functionAddress

            # CDisplay__DeleteActor
            # void __userpurge sub_5380F0(int a1@<ecx>, double a2@<st0>, int a3)    # 0x005380F0
            # {
            #   _DWORD **v3; // edi
            #   _DWORD *v4; // eax
            #   int v5; // eax
            #
            #   v3 = (_DWORD **)a1;
            #   if ( a3 )
            #   {
            #     *(_DWORD *)(a1 + 348) = 0;
            #     v4 = dword_E805BC;
            #     if ( dword_E805BC && *((_DWORD *)dword_E805BC + 1091) == a3 )
            #     {
            #       if ( dword_DCBC48 )
            #       {
            #         sub_7A6730(dword_DCBC48, a2, 0, 1);
            #         v4 = dword_E805BC;
            #       }
            #       if ( dword_DCBC28 )
            #       {
            #         sub_786EB0((int)dword_DCBC28, a2, 0, (LPVOID)1);
            #         v4 = dword_E805BC;
            #       }
            #     }
            #     if ( dword_DCC1BC == a3 )
            #     {
            #       if ( v4 && (v5 = v4[1091], v5 != dword_DCC1BC) )
            #         sub_537F50(v3, v5);
            #       else
            #         sub_537F50(v3, 0);
            #     }
            #     (*(void (__stdcall **)(int))(*(_DWORD *)dword_16CA77C + 108))(a3);
            #   }
            # }
            if re.search("\(\*\(void \(__stdcall \*\*\)\(int\)\)\(\*\(_DWORD \*\)dword_[0-9A-F]+ \+ 108\)\)\(\w+\d+\);", functionString):
                if functionString.find(", 0, 1);") != -1:
                    if functionString.find(", 0);") != -1:
                        if functionString.find(", 0, (LPVOID)1);") != -1:
                            functionList["CDisplay__DeleteActor"] = functionAddress

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

for k, v in sorted(functionList.items()):
    print(k, v)

# EQ_InitializeAddresses()
with open("addresses.txt", "w") as out_file:
    out_file.write("void EQ_InitializeAddresses()\n")
    out_file.write("{\n")
    out_file.write("    // " + buildDate + " " + buildTime + "\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_WindowHWND = " + functionList["WindowHWND"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_AutoAttack    = " + functionList["AutoAttack"] + ";\n")
    out_file.write("    EQ_ADDRESS_AutoFire      = " + functionList["AutoFire"] + ";\n")
    out_file.write("    EQ_ADDRESS_AutoRun       = " + functionList["AutoRun"] + ";\n")
    out_file.write("    EQ_ADDRESS_MouseLook     = " + functionList["MouseLook"] + ";\n")
    out_file.write("    EQ_ADDRESS_NetStatus     = " + functionList["NetStatus"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_EQZoneInfo = " + functionList["EQZoneInfo"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = " + functionList["CollisionCallbackForActors"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CastRay                       = " + functionList["CastRay"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CastRay2                      = " + functionList["CastRay2"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = " + functionList["DrawNetStatus"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = " + functionList["ExecuteCmd"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_PlayerSpawn    = " + functionList["PlayerSpawn"] + ";\n")
    out_file.write("    EQ_ADDRESS_POINTER_TargetSpawn    = " + functionList["TargetSpawn"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_EQPlayerManager = " + functionList["EQPlayerManager"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = " + functionList["EQPlayerManager__GetSpawnByID"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = " + functionList["EQPlayerManager__GetSpawnByName"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = " + functionList["EQPlayer__ChangeHeight"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel        = " + functionList["EQPlayer__GetLevel"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CXWndManager = " + functionList["CXWndManager"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = " + functionList["CXWndManager__DrawWindows"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CEverQuest = " + functionList["CEverQuest"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert    = " + functionList["CEverQuest__DoPercentConvert"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone           = " + functionList["CEverQuest__EnterZone"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd        = " + functionList["CEverQuest__InterpretCmd"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat            = " + functionList["CEverQuest__dsp_chat"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState        = " + functionList["CEverQuest__SetGameState"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp            = " + functionList["CEverQuest__LMouseUp"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp            = " + functionList["CEverQuest__RMouseUp"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel    = " + functionList["CEverQuest__HandleMouseWheel"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CDisplay = " + functionList["CDisplay"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = " + functionList["CDisplay__WriteTextHD2"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = " + functionList["CDisplay__CreateActor"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = " + functionList["CDisplay__CreatePlayerActor"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = " + functionList["CDisplay__DeleteActor"] + ";\n")
    out_file.write("\n")
    out_file.write("    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime\n")
    out_file.write("    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CRender = " + functionList["CRender"] + ";\n")
    out_file.write("    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime\n")
    out_file.write("    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime\n")
    out_file.write("    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime\n")
    out_file.write("    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime\n")
    out_file.write("}\n")