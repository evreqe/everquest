import re

mapOffset = 0

buildDate = ""
buildTime = ""

functionList = {
    "SizeCXWnd": 0,
    "SizeCSidlScreenWnd": 0,
    "OffsetSpawnStandingState": 0,
    "OffsetSpawnFollowSpawn": 0,
    "OffsetSpawnHPCurrent": 0,
    "OffsetSpawnHPMax": 0,
    "OffsetSpawnManaCurrent": 0,
    "OffsetSpawnManaMax": 0,
    "OffsetSpawnEnduranceCurrent": 0,
    "OffsetSpawnEnduranceMax": 0,
    "OffsetSpawnCharacterZoneClient": 0,
    "OffsetCharacterBase": 0,
    "OffsetCharInfo2Bandolier": 0,
    "WindowHWND": 0,
    "AutoAttack": 0,
    "AutoFire": 0,
    "AutoRun": 0,
    "MouseLook": 0,
    "NetStatus": 0,
    "FlushDxKeyboard": 0,
    "FlushDxMouse": 0,
    "ProcessKeyboardEvent": 0,
    "ProcessMouseEvent": 0,
    "WindowProc": 0,
    "CollisionCallbackForActors": 0,
    "CastRay": 0,
    "CastRay2": 0,
    "DrawNetStatus": 0,
    "ExecuteCmd": 0,
    "DoSpellEffect": 0,
    "PlaySoundAtLocation": 0,
    "GetTime": 0,
    "UpdateLight": 0,
    "GetGaugeValueFromEQ": 0,
    "get_bearing": 0,
    "get_melee_range": 0,
    "vehicle_premove": 0,
    "vehicle_postmove": 0,
    "EQZoneInfo": 0,
    "ControlledSpawn": 0,
    "PlayerSpawn": 0,
    "TargetSpawn": 0,
    "StringTable": 0,
    "StringTable__getString": 0,
    "CDBStr": 0,
    "CDBStr__GetString": 0,
    "EQ_Character": 0,
    "EQ_Character__encum_factor": 0,
    "EQ_Character__TakeFallDamage": 0,
    "EQ_Character__CanIBreathe": 0,
    "EQ_Character__CanISeeInvis": 0,
    "EQ_Character__StunMe": 0,
    "EQ_Character__UnStunMe": 0,
    "EQ_Character__ProcessEnvironment": 0,
    "EQ_Character__TotalSpellAffects": 0,
    "CharacterZoneClient__SetNoGrav": 0,
    "EQ_PC": 0,
    "EQ_PC__DestroyHeldItemOrMoney": 0,
    "EQPlayerManager": 0,
    "EQPlayerManager__GetSpawnByID": 0,
    "EQPlayerManager__GetSpawnByName": 0,
    "EQPlayer__ChangeHeight": 0,
    "EQPlayer__ChangePosition": 0,
    "EQPlayer__GetLevel": 0,
    "EQPlayer__GetActorClient": 0,
    "EQPlayer__FollowPlayerAI": 0,
    "EQPlayer__TurnOffAutoFollow": 0,
    "EQPlayer__UpdateItemSlot": 0,
    "EQPlayer__IsTargetable": 0,
    "EQPlayer__SetNameSpriteState": 0,
    "EQPlayer__SetNameSpriteTint": 0,
    "EQPlayer__ChangeLight": 0,
    "EQPlayer__push_along_heading": 0,
    "EQSwitchManager": 0,
    "EQSwitch__UseSwitch": 0,
    "EQSwitch__ChangeState": 0,
    "EQSpell__SpellAffects": 0,
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
    "CEverQuest__SendNewText": 0,
    "CEverQuest__DropHeldItemOnGround": 0,
    "CDisplay": 0,
    "CDisplay__WriteTextHD2": 0,
    "CDisplay__CreateActor": 0,
    "CDisplay__CreatePlayerActor": 0,
    "CDisplay__DeleteActor": 0,
    "CDisplay__GetIntensity": 0,
    "CDisplay__CreateLight": 0,
    "CDisplay__DeleteLight": 0,
    "CRender": 0,
    "CAlertWnd": 0,
    "CSpellBookWnd": 0,
    "CSpellBookWnd__GetSpellMemTicksLeft": 0,
    "CSpellBookWnd__GetSpellScribeTicksLeft": 0,
}

functionAddress = ""
functionString = ""

insideFunction = 0

# the functions for spawn mana and endurance offsets are identical
# it goes hp, mana, then endurance in that order in the code
# so we find mana first, set this boolean, then find endurance
foundFunctionsForOffsetSpawnManaAndEndurance = 0

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
            # ----------------------------------------------------------------------------------------------------
            # sub_6A9120(v5, (DWORD)"VERSION", (int)&off_BD6000);    # 0x00BD6000
            matches = re.findall("sub_[0-9A-F]+\([0-9a-z]+, \(DWORD\)\"VERSION\", \(int\)&off_([0-9A-F]+)\);", functionString, re.MULTILINE)
            if matches:
                mapOffset = "0x00" + matches[0]
                print("mapOffset", mapOffset)

            # buildDate
            # buildTime
            # ----------------------------------------------------------------------------------------------------
            # sub_8EEB00("Starting EverQuest (Built %s %s)", "Apr 18 2019", "17:51:12");
            if functionString.find("\"Starting EverQuest (Built %s %s)\"") != -1:
                matches = re.findall("sub_[0-9A-F]+\(\"Starting EverQuest \(Built %s %s\)\", \"(\w+\s+\d+\s+\d+)\", \"(\d+:\d+:\d+)\"\);", functionString, re.MULTILINE)
                if matches:
                    buildDate = matches[0][0]
                    buildTime = matches[0][1]
                    print("buildDate", buildDate)
                    print("buildTime", buildTime)

            # SizeCXWnd
            # ----------------------------------------------------------------------------------------------------
            # = &CXWnd::`vftable';    # goto xref, first function in vftable
            #
            # void __thiscall sub_932DD0(_DWORD *this, int a2)
            # {
            #   _DWORD *v2; // esi
            #   _DWORD *v3; // eax
            #   int v4; // eax
            # 
            #   v2 = this;
            #   if ( a2 )
            #   {
            #     if ( !this[149] )
            #     {
            #       v3 = operator new(0x1E8u);    # 0x1E8
            #       if ( v3 )
            #         v4 = sub_911BB0(v3, 0, 0, 0, 0, 0, 0);
            #       else
            #         v4 = 0;
            #       v2[149] = v4;
            #     }
            #     sub_917480(v2[149], a2);
            #   }
            # }
            if functionString.find("= this;") != -1:
                if functionString.find("operator new") != -1:
                    if functionString.find(", 0, 0, 0, 0, 0, 0);") != -1:
                        if functionString.find("= 0;") != -1:
                            matches = re.findall("operator new\(0x([0-9A-F]+)u\);\n\s+if \( [0-9a-z]+ \)\n\s+[0-9a-z]+ = sub_[0-9A-F]+\([0-9a-z]+, 0, 0, 0, 0, 0, 0\);\n\s+else\n\s+[0-9a-z]+ = 0;", functionString, re.MULTILINE)
                            if matches:
                                functionList["SizeCXWnd"] = "0x" + matches[0]

            # SizeCSidlScreenWnd
            # ----------------------------------------------------------------------------------------------------
            # = &CSidlScreenWnd::`vftable';    # goto xref, first function in vftable
            #
            # if ( v8 )
            # {
            #   sub_481880((int)&v26, (int)"%s is a NO DROP item, are you sure you wish to loot it?", (int)(a2 + 1));
            #   if ( dword_DCBC44 )
            #     v20 = dword_DCBC44 + 560;    # 560 dec = 0x230
            #   else
            #     v20 = 0;
            #   sub_7C0B60((int *)dword_104E8F0, v20, 100, (int)&v26, 0xCu, 20000, (int)v8, 1);
            # }
            # return;
            if functionString.find("\"%s is a NO DROP item, are you sure you wish to loot it?\"") != -1:
                if functionString.find("0x283u") != -1:    # 643 You cannot perform that action right now. Please try again in a moment.
                    if functionString.find("0x2C39u") != -1:    # 11321 These item(s) are locked because you were not present when the enemy died. To loot them you will first need to right-click that enemy's corpse to unlock.
                        matches = re.findall("if \( dword_[0-9A-F]+ \)\n\s+[0-9a-z]+ = dword_[0-9A-F]+ \+ (\d+);\n\s+else\n\s+[0-9a-z]+ = 0;", functionString, re.MULTILINE)
                        if matches:
                            functionList["SizeCSidlScreenWnd"] = int(matches[0])

            # OffsetSpawnStandingState
            # ----------------------------------------------------------------------------------------------------
            # if ( sub_5B94A0() )
            # {
            #   v12 = sub_8B5330((int *)dword_E80480, 0x3292u, 0);
            #   if ( sub_8EFD50(a12, (int)v12, 3) || *(_BYTE *)(a11 + 1204) == 110 )    # 1204 dec
            #     sub_5E9200(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
            # }
            if functionString.find("0x3292u") != -1:    # off
                if functionString.find(", 3)") != -1:    # strlen "off" is 3
                    if functionString.find("== 110") != -1:
                        matches = re.findall("if \( sub_[0-9A-F]+\([0-9a-z]+, \(int\)[0-9a-z]+, 3\) \|\| \*\(_BYTE \*\)\([0-9a-z]+ \+ (\d+)\) == 110 \)", functionString, re.MULTILINE)
                        if matches:
                            functionList["OffsetSpawnStandingState"] = int(matches[0])

            # OffsetSpawnFollowSpawn
            # ----------------------------------------------------------------------------------------------------
            # void sub_5A05C0()    # do_follow()    # /follow
            # {
            #   void *v0; // eax
            #   char v1; // al
            #   int v2; // eax
            #   void *v3; // ST18_4
            #   void *v4; // ST18_4
            #   int v5; // eax
            #   void *v6; // ST18_4
            #   char Mem; // [esp+0h] [ebp-100h]
            #
            #   if ( !dword_E80690 || *((_BYTE *)dword_E80690 + 293) )
            #   {
            #     v0 = sub_8B5330((int *)dword_E80480, 0x33A9u, 0);
            #     goto LABEL_16;
            #   }
            #   if ( dword_E80690 == dword_E805BC )
            #   {
            #     v0 = sub_8B5330((int *)dword_E80480, 0x33AAu, 0);
            # LABEL_16:
            #     v6 = v0;
            #     sub_4E5B40();
            #     sub_4E61E0(v6, (LPVOID)0x111, (LPVOID)1, (LPVOID)1, 0);
            #     return;
            #   }
            #   if ( *((float *)dword_E805BC + 6) < -1000.0 )
            #   {
            #     v0 = sub_8B5330((int *)dword_E80480, 0x33ABu, 0);
            #     goto LABEL_16;
            #   }
            #   v1 = *((_BYTE *)dword_E805BC + 1204);
            #   if ( v1 == 102 || *((_BYTE *)dword_E805BC + 1040) )
            #   {
            #     v0 = sub_8B5330((int *)dword_E80480, 0x33ACu, 0);
            #     goto LABEL_16;
            #   }
            #   if ( v1 != 100 )
            #   {
            #     v0 = sub_8B5330((int *)dword_E80480, 0x33ADu, 0);
            #     goto LABEL_16;
            #   }
            #   v2 = sub_65A0F0((char *)dword_E80690, 0);
            #   sub_599A20((int)&Mem, 0x33AEu, v2, 0, 0, 0, 0, 0, 0, 0, 0);
            #   sub_4E5B40();
            #   sub_4E61E0(&Mem, (LPVOID)0x111, (LPVOID)1, (LPVOID)1, 0);
            #   v3 = sub_8B5330((int *)dword_E80480, 0x33AFu, 0);
            #   sub_4E5B40();
            #   sub_4E61E0(v3, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #   v4 = sub_8B5330((int *)dword_E80480, 0x33B0u, 0);
            #   sub_4E5B40();
            #   sub_4E61E0(v4, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #   v5 = sub_64CC00(dword_E80690);
            #   if ( v5 )
            #     *(_DWORD *)(dword_E80694 + 3884) = v5;    # 3884 dec
            #   *((_DWORD *)dword_E805BC + 971) = dword_E80690;
            # }
            if functionString.find("0x33A9u") != -1:    # 13225 You must first target a player to auto-follow.
                if functionString.find("0x33AAu") != -1:    # 13226 You can't auto-follow yourself.
                    if functionString.find("0x33ABu") != -1:    # 13227 You cannot move right now, how could you follow?
                        if functionString.find("0x33ACu") != -1:    # 13228 You are not yourself right now, you cannot follow.
                            if functionString.find("0x33ADu") != -1:    # 13229 Stand up first!
                                if functionString.find("0x33AEu") != -1:    # 13230 You will now auto-follow %1.
                                    if functionString.find("0x33AFu") != -1:    # 13231 *WARNING*: Do NOT use around lava, water, cliffs, or other dangerous areas because you WILL fall into them. You have been warned.
                                        if functionString.find("0x33B0u") != -1:    # 13232 Also, auto-follow works best in wide open areas with low lag.  Twisty areas, lag, and other factors may cause auto-follow to fail.
                                            if functionString.find("< -1000.0") != -1:
                                                matches = re.findall("if \( [0-9a-z]+ \)\n\s+\*\(_DWORD \*\)\(dword_[0-9A-F]+ \+ (\d+)\) = [0-9a-z]+;", functionString, re.MULTILINE)
                                                if matches:
                                                    functionList["OffsetSpawnFollowSpawn"] = int(matches[0])

            # OffsetSpawnHPCurrent
            # OffsetSpawnHPMax
            # ----------------------------------------------------------------------------------------------------
            # GetGaugeValueFromEQ():
            # case 16:
            #   sub_80A8B0(a2);
            #   v5 = -1;
            #   v22 = *((_DWORD *)dword_E7E264 + 2312);
            #   if ( !v22 )
            #     return v5;
            #   v23 = *(_DWORD *)(v22 + 1296);
            #   if ( v23 == -1 )
            #     return v5;
            #   v24 = sub_64FD90((_DWORD **)dword_F2FEE8, v23);
            #   v25 = v24;
            #   if ( !v24 )
            #     return v5;
            #   v26 = (void *)sub_5F4C50(v24 + 164);
            #   sub_8EB2C0(v26);
            #   v5 = 10 * sub_64F750(*(_QWORD *)(v25 + 1416), *(_QWORD *)(v25 + 912));    # 1416 = OffsetSpawnHPCurrent    # 912 = OffsetSpawnHPMax
            #   goto LABEL_175;
            # case 17:
            #
            # ----
            #
            # char __cdecl sub_58A330(unsigned int a1, __int64 a2, __int64 a3, char a4)
            # {
            #   int v4; // eax
            #   int v5; // esi
            #
            #   v4 = sub_64FA30((_DWORD **)dword_F30FE8, a1);
            #   v5 = v4;
            #   if ( !v4 )
            #     return v4;
            #   if ( a4 )
            #     *(_BYTE *)(v4 + 4808) = 1;
            #   if ( (LPVOID)v4 == dword_E7F3F0 )
            #   {
            #     *(_QWORD *)(v4 + 928) = a2;
            #     if ( dword_E7F920 )
            #     {
            #       v4 = sub_8BD2C0((char *)dword_E7F920 + *(_DWORD *)(*((_DWORD *)dword_E7F920 + 2) + 4) + 12);
            #       *(_QWORD *)(v4 + 15248) = a2;
            #     }
            #     goto LABEL_26;
            #   }
            #   LOBYTE(v4) = BYTE4(a2);
            #   if ( *(_BYTE *)(v5 + 293) == 1 )
            #   {
            #     if ( SHIDWORD(a2) > 0 )
            #     {
            # LABEL_18:
            #       if ( a3 )
            #         v4 = (signed int)((double)a2 / ((double)a3 * 0.0099999998));
            #       else
            #         v4 = 0;
            #       *(_QWORD *)(v5 + 928) = v4;
            #       if ( v4 >> 31 <= 0 && (v4 >> 31 < 0 || !v4) )
            #       {
            #         *(_DWORD *)(v5 + 928) = 1;
            #         *(_DWORD *)(v5 + 932) = 0;
            #       }
            #       goto LABEL_25;
            #     }
            #     if ( (a2 < 0 || (unsigned int)a2 <= 0x64) && a3 == 100 )
            #       goto LABEL_12;
            #   }
            #   if ( SHIDWORD(a2) > 0 || a2 >= 0 && (_DWORD)a2 )
            #     goto LABEL_18;
            #   if ( a2 < -126 )
            #   {
            #     *(_DWORD *)(v5 + 928) = -126;
            #     *(_DWORD *)(v5 + 932) = -1;
            #     goto LABEL_25;
            #   }
            # LABEL_12:
            #   *(_QWORD *)(v5 + 928) = a2;
            # LABEL_25:
            #   *(_DWORD *)(v5 + 1368) = 100;
            #   *(_DWORD *)(v5 + 1372) = 0;
            # LABEL_26:
            #   if ( BYTE2(dword_E905D0) )
            #     LOBYTE(v4) = sub_646070((_BYTE *)v5);
            #   return v4;
            # }
            if functionString.find("== 1") != -1:
                if functionString.find("<= 0") != -1:
                    if functionString.find(">= 0") != -1:
                        if functionString.find("== 100") != -1:
                            if functionString.find("* 0.0099999998") != -1:
                                if functionString.find("<= 0") != -1:
                                    if functionString.find("= 1;") != -1:
                                            if functionString.find("= -126;") != -1:
                                                if functionString.find("= -1;") != -1:
                                                    if functionString.find("= 100;") != -1:
                                                        if functionString.find("= 0;") != -1:
                                                            matches = re.findall("\*\(_DWORD \*\)\([0-9a-z]+ \+ (\d+)\) = -126;\n\s+\*\(_DWORD \*\)\([0-9a-z]+ \+ \d+\) = -1;", functionString, re.MULTILINE)
                                                            if matches:
                                                                functionList["OffsetSpawnHPCurrent"] = int(matches[0])
                                                            matches = re.findall("\*\(_DWORD \*\)\([0-9a-z]+ \+ (\d+)\) = 100;\n\s+\*\(_DWORD \*\)\([0-9a-z]+ \+ \d+\) = 0;", functionString, re.MULTILINE)
                                                            if matches:
                                                                functionList["OffsetSpawnHPMax"] = int(matches[0])

            # OffsetSpawnManaCurrent
            # OffsetSpawnManaMax
            # ----------------------------------------------------------------------------------------------------
            # char __cdecl sub_58B3E0(unsigned int a1, signed int a2, int a3, char a4)
            # {
            #   int v4; // eax
            #   int v5; // esi
            #   signed __int64 v6; // rax
            #   signed __int64 v8; // [esp+4h] [ebp-8h]
            #
            #   v4 = sub_64FD90((_DWORD **)dword_F2FEE8, a1);
            #   v5 = v4;
            #   if ( !v4 )
            #     return v4;
            #   if ( a4 )
            #     *(_BYTE *)(v4 + 4800) = 1;
            #   if ( (LPVOID)v4 == dword_E805BC )
            #   {
            #     LOBYTE(v4) = a3;
            #     *(_DWORD *)(v5 + 740) = a2;
            #     *(_DWORD *)(v5 + 976) = a3;
            #     if ( dword_E7E264 )
            #     {
            #       v4 = sub_8BC690((char *)dword_E7E264 + *(_DWORD *)(*((_DWORD *)dword_E7E264 + 2) + 4) + 12);
            #       *(_DWORD *)(v4 + 15628) = a2;
            #     }
            #     goto LABEL_19;
            #   }
            #   LOBYTE(v4) = a2;
            #   if ( *(_BYTE *)(v5 + 293) == 1 && a2 <= 100 && a3 == 100 )
            #     goto LABEL_24;
            #   if ( a2 > 0 )
            #   {
            #     v6 = a3;
            #     v8 = v6;
            #     v4 = HIDWORD(v6) | v6;
            #     if ( v4 )
            #       v4 = (signed int)((double)a2 / ((double)v8 * 0.0099999998));
            #     *(_DWORD *)(v5 + 740) = v4;
            #     if ( v4 <= 0 )
            #       *(_DWORD *)(v5 + 740) = 1;
            #     goto LABEL_18;
            #   }
            #   if ( a2 >= -126 )
            # LABEL_24:
            #     *(_DWORD *)(v5 + 740) = a2;
            #   else
            #     *(_DWORD *)(v5 + 740) = -126;    # 740 = OffsetSpawnManaCurrent
            # LABEL_18:
            #   *(_DWORD *)(v5 + 976) = 100;    # 976 = OffsetSpawnManaMax
            # LABEL_19:
            #   if ( BYTE2(dword_E8F4D0) )
            #     LOBYTE(v4) = sub_6464C0((_BYTE *)v5);
            #   return v4;
            # }
            if functionString.find("== 1") != -1:
                if functionString.find("<= 100") != -1:
                    if functionString.find("== 100") != -1:
                        if functionString.find("* 0.0099999998") != -1:
                            if functionString.find("<= 0") != -1:
                                if functionString.find("= 1;") != -1:
                                    if functionString.find(">= -126") != -1:
                                        if functionString.find("= -126;") != -1:
                                            if functionString.find("= 100;") != -1:
                                                matches = re.findall("\*\(_DWORD \*\)\([0-9a-z]+ \+ (\d+)\) = -126;\nLABEL_\d+:\n\s+\*\(_DWORD \*\)\([0-9a-z]+ \+ (\d+)\) = 100;", functionString, re.MULTILINE)
                                                if matches:
                                                    if foundFunctionsForOffsetSpawnManaAndEndurance == 0:
                                                        foundFunctionsForOffsetSpawnManaAndEndurance = 1
                                                        functionList["OffsetSpawnManaCurrent"] = int(matches[0][0])
                                                        functionList["OffsetSpawnManaMax"] = int(matches[0][1])
                                                    elif foundFunctionsForOffsetSpawnManaAndEndurance == 1:
                                                        foundFunctionsForOffsetSpawnManaAndEndurance = 2
                                                        functionList["OffsetSpawnEnduranceCurrent"] = int(matches[0][0])
                                                        functionList["OffsetSpawnEnduranceMax"] = int(matches[0][1])

            # OffsetSpawnCharacterZoneClient
            # ----------------------------------------------------------------------------------------------------
            # sub_5999F0(*(_DWORD *)(v6 + 1212), 14609, (LPVOID)0x12F);    # 1212 dec = OffsetSpawnCharacterZoneClient
            # return 0;
            if functionString.find("), 14609, (LPVOID)0x12F);") != -1:
                if functionString.find("return 0;") != -1:
                    matches = re.findall("sub_[0-9A-F]+\(\*\(_DWORD \*\)\([0-9a-z]+ \+ (\d+)\), 14609, \(LPVOID\)0x12F\);", functionString, re.MULTILINE)
                    if matches:
                        functionList["OffsetSpawnCharacterZoneClient"] = int(matches[0])

            # OffsetCharacterBase
            # ----------------------------------------------------------------------------------------------------
            # int __thiscall sub_6312C8(_DWORD *this)
            # {
            #   int result; // eax
            #
            #   if ( (char *)this - *(this - 1) - 10316 == dword_E7F920 )    # 10316 dec = OffsetCharacterBase
            #     result = *(_DWORD *)sub_8BDD00();
            #   else
            #     result = 0;
            #   return result;
            # }
            if functionString.find("int result;") != -1:
                if functionString.find("result = 0;") != -1:
                    if functionString.find("this - *(this - 1) - ") != -1:
                        if functionString.find("== dword_") != -1:
                            if functionString.find("return result;") != -1:
                                matches = re.findall("if \( (?:\(char \*\))this - \*\(this - 1\) - (\d+) == dword_[0-9A-F]+ \)", functionString, re.MULTILINE)
                                if matches:
                                    functionList["OffsetCharacterBase"] = int(matches[0])

            # OffsetCharInfo2Bandolier
            # ----------------------------------------------------------------------------------------------------
            # int __thiscall sub_8E3880(char *this, int a2, int a3, _DWORD *a4, int a5)
            # {
            #   _DWORD *v5; // esi
            #   int result; // eax
            #   unsigned int v7; // ebx
            #   signed int v8; // edi
            #   signed int v9; // ebx
            #   int v10; // [esp+0h] [ebp-14h]
            #   unsigned int v11; // [esp+Ch] [ebp-8h]
            #   int v12; // [esp+10h] [ebp-4h]
            #   signed int v13; // [esp+24h] [ebp+10h]
            #
            #   v5 = a4;
            #   result = (int)(this + 30132);
            #   v7 = 0;
            #   v12 = (int)(this + 30132);
            #   v11 = 0;
            #   v8 = 0;
            #   do
            #   {
            #     if ( v7 >= 0x14 )
            #       __debugbreak();
            #     if ( *(_BYTE *)(v8 + result) )
            #     {
            #       *v5 += sub_8F01A0(*v5 + a2, a3 - *v5, (int)"%sBandolier%d=", a5);
            #       if ( v7 >= 0x14 )
            #         __debugbreak();
            #       v13 = 4;
            #       *v5 += sub_8F01A0(*v5 + a2, a3 - *v5, (int)"\"%s\"", v8 + v12);
            #       v9 = v8;
            #       do
            #       {
            #         if ( (unsigned int)v8 >= 0x1900 )
            #           __debugbreak();
            #         *v5 += sub_8F01A0(*v5 + a2, a3 - *v5, (int)"^%d", *(_DWORD *)(v9 + v12 + 32));
            #         v9 += 72;
            #         --v13;
            #       }
            #       while ( v13 );
            #       v7 = v11;
            #       *v5 += sub_8F01A0(*v5 + a2, a3 - *v5, (int)"\n", v10);
            #       result = v12;
            #     }
            #     ++v7;
            #     v8 += 320;
            #     v11 = v7;
            #   }
            #   while ( v8 < 6400 );
            #   return result;
            # }
            if functionString.find("int result;") != -1:
                if functionString.find("\"%sBandolier%d=\"") != -1:
                    if functionString.find("return result;") != -1:
                        matches = re.findall("result = \(int\)\(this \+ (\d+)\);", functionString, re.MULTILINE)
                        if matches:
                            functionList["OffsetCharInfo2Bandolier"] = int(matches[0])

            # AutoAttack
            # ----------------------------------------------------------------------------------------------------
            # "ExecuteCmd has received a CMD_EXITGAME.\n"
            #
            #       if ( byte_F2BCEB )    # 0x00F2BCEB
            #         v37 = (char *)sub_8B4BE0((int *)dword_E7F46C, 0x3052u, 0);    # 12370 Auto attack is on.
            #       else
            #         v37 = (char *)sub_8B4BE0((int *)dword_E7F46C, 0x3053u, 0);    # 12371 Auto attack is off.
            if functionString.find("\"ExecuteCmd has received a CMD_EXITGAME.\\n\"") != -1:
                matches = re.findall("if \( byte_([0-9A-F]+) \)\n\s+[0-9a-z]+ = (?:\(char \*\))sub_[0-9A-F]+\(\(int \*\)dword_[0-9A-F]+, 0x3052u, 0\);", functionString, re.MULTILINE)
                if matches:
                    functionList["AutoAttack"] = "0x00" + matches[0]

            # AutoFire
            # ----------------------------------------------------------------------------------------------------
            # v4 = (char *)byte_F2BCEC ? sub_8B4BE0((int *)dword_E7F46C, 0x116u, 0) : sub_8B4BE0((int *)dword_E7F46C, 0x117u, 0);    # 0x00F2BCEC
            # 278 Auto fire on.
            # 279 Auto fire off.
            if functionString.find("0x116u") != -1:
                if functionString.find("0x117u") != -1:
                    matches = re.findall("byte_([0-9A-F]+) \? sub_[0-9A-F]+", functionString, re.MULTILINE)
                    if matches:
                        functionList["AutoFire"] = "0x00" + matches[0]

            # AutoRun
            # ----------------------------------------------------------------------------------------------------
            # "I died.\n"
            #       sub_561710((int)dword_DCCD58, 7, 1);
            #       dword_E8D058 = 0;    # 0x00E8D058
            if functionString.find("\"I died.\\n\"") != -1:
                matches = re.findall("sub_[0-9A-F]+\(\(int\)dword_[0-9A-F]+, 7, 1\);\n\s+dword_([0-9A-F]+) = 0;\n", functionString, re.MULTILINE)
                if matches:
                    functionList["AutoRun"] = "0x00" + matches[0]

            # MouseLook
            # ----------------------------------------------------------------------------------------------------
            # ("Defaults", "ShowSpellDescriptions", 1, 0);
            # word_E8D03A = 256;    # 0x00E8D03A
            if functionString.find("(\"Defaults\", \"ShowSpellDescriptions\", 1, 0);") != -1:
                matches = re.findall("word_([0-9A-F]+) = 256;\n", functionString, re.MULTILINE)
                if matches:
                    functionList["MouseLook"] = "0x00" + matches[0]

            # NetStatus
            # ----------------------------------------------------------------------------------------------------
            # byte_F30435 = sub_9CFF30("Defaults", "NetStat", 0, 0);    # 0x00F30435
            matches = re.findall("byte_([0-9A-F]+) = sub_[0-9A-F]+\(\"Defaults\", \"NetStat\", 0, 0\);", functionString, re.MULTILINE)
            if matches:
                functionList["NetStatus"] = "0x00" + matches[0]

            # FlushDxKeyboard
            # ----------------------------------------------------------------------------------------------------
            # int sub_6A5C80()    # 0x006A5C80
            # {
            #   int v1; // [esp+14h] [ebp-284h]
            #   char v2; // [esp+18h] [ebp-280h]
            #
            #   v1 = 32;
            #   (*(void (__stdcall **)(int, signed int, char *, int *, _DWORD))(*(_DWORD *)dword_F3FB94 + 40))(
            #     dword_F3FB94,
            #     20,
            #     &v2,
            #     &v1,
            #     0);
            #   dword_E9AEA4 = 0;
            #   dword_E9AEA8 = 0;
            #   byte_E9AEAC = 0;
            #   if ( dword_16D6198 )
            #     sub_929940(dword_16D6198);
            #   return v1;
            # }
            if re.search("[0-9a-z]+ \= 32;", functionString):
                if functionString.find("__stdcall") != -1:
                    if re.search("dword_[0-9A-F]+ \+ 40", functionString):
                        if functionString.find("20,") != -1:
                            if re.search("dword_[0-9A-F]+ \= 0;", functionString):
                                if re.search("byte_[0-9A-F]+ \= 0;", functionString):
                                    if re.search("if \( dword_[0-9A-F]+ \)", functionString):
                                        if re.search("sub_[0-9A-F]+\(dword_[0-9A-F]+\);", functionString):
                                            if re.search("return [0-9a-z]+;", functionString):
                                                functionList["FlushDxKeyboard"] = functionAddress

            # FlushDxMouse
            # ----------------------------------------------------------------------------------------------------
            # signed int sub_6A5900()    # 0x006A5900
            # {
            #   signed int result; // eax
            #   int v1; // [esp+0h] [ebp-A04h]
            #   char v2; // [esp+4h] [ebp-A00h]
            #
            #   v1 = 128;
            #   dword_F3FB84 = 0;
            #   dword_F3FB88 = 0;
            #   if ( dword_F3F150 )
            #     result = (*(int (__stdcall **)(int, signed int, char *, int *, _DWORD))(*(_DWORD *)dword_F3F150 + 40))(
            #                dword_F3F150,
            #                20,
            #                &v2,
            #                &v1,
            #                0) >= 0 ? 1 : 7;
            #   else
            #     result = dword_F3F150 + 7;
            #   return result;
            # }
            if re.search("[0-9a-z]+ \= 128;", functionString):
                if functionString.find("__stdcall") != -1:
                    if re.search("dword_[0-9A-F]+ \+ 40", functionString):
                        if functionString.find("20,") != -1:
                            if functionString.find(">= 0 ? 1 : 7;") != -1:
                                if re.search("result \= dword_[0-9A-F]+ \+ 7;", functionString):
                                    if functionString.find("return result;") != -1:
                                        functionList["FlushDxMouse"] = functionAddress

            # ProcessKeyboardEvent
            # ----------------------------------------------------------------------------------------------------
            # unsigned int __usercall sub_6A77B0@<eax>(double a1@<st7>, double a2@<st6>, double a3@<st5>, double a4@<st4>, double a5@<st3>, double a6@<st2>, double a7@<st1>, double a8@<st0>)
            # {
            #   HWND v8; // eax
            #   unsigned int v10; // edi
            #   char *v11; // esi
            #   char v12; // al
            #   unsigned __int8 v13; // al
            #   char v14; // al
            #   unsigned __int8 v15; // al
            #   char v16; // al
            #   unsigned __int8 v17; // al
            #   char v18; // [esp+Ch] [ebp-294h]
            #   char v19; // [esp+18h] [ebp-288h]
            #   unsigned int v20; // [esp+1Ch] [ebp-284h]
            #   char v21; // [esp+20h] [ebp-280h]
            #
            #   v20 = 32;
            #   v8 = GetForegroundWindow();
            #   if ( !v8 || v8 != hwnd )
            #     return 1;
            #   (*(void (__stdcall **)(int))(*(_DWORD *)dword_F3FB94 + 28))(dword_F3FB94);
            #   if ( (*(int (__stdcall **)(int, signed int, char *, unsigned int *, _DWORD))(*(_DWORD *)dword_F3FB94 + 40))(
            #          dword_F3FB94,
            #          20,
            #          &v21,
            #          &v20,
            #          0) )
            #   {
            #     sub_6A5C80();
            #     return 1;
            #   }
            #   v10 = 0;
            #   if ( v20 )
            #   {
            #     v11 = &v21;
            #     do
            #     {
            #       v18 = *v11;
            #       if ( v11[4] >= 0 )
            #         sub_6A5EC0(a1, a2, a3, a4, a5, a6, a7, a8, v18);
            #       else
            #         sub_6A5CE0(a1, a2, a3, a4, a5, a6, a7, a8, v18);
            #       ++v10;
            #       v11 += 20;
            #     }
            #     while ( v10 < v20 );
            #   }
            #   if ( !(_BYTE)dword_E9AEA4 )
            #     goto LABEL_33;
            #   if ( !(GetAsyncKeyState(16) & 0x8000) )
            #   {
            #     LOBYTE(dword_E9AEA4) = 0;
            #     sub_907350(&v19, 42, 0, SBYTE1(dword_E9AEA4), SBYTE2(dword_E9AEA4));
            #     v12 = sub_908080(&v19);
            #     sub_6A5EC0(a1, a2, a3, a4, a5, a6, a7, a8, v12);
            #     goto LABEL_18;
            #   }
            #   if ( !(_BYTE)dword_E9AEA4 )
            #   {
            # LABEL_33:
            #     if ( GetAsyncKeyState(16) & 0x8000 )
            #     {
            #       LOBYTE(dword_E9AEA4) = 1;
            #       sub_907350(&v19, 42, 1, SBYTE1(dword_E9AEA4), SBYTE2(dword_E9AEA4));
            #       v13 = sub_908080(&v19);
            #       sub_6A5CE0(a1, a2, a3, a4, a5, a6, a7, a8, v13);
            #     }
            #   }
            # LABEL_18:
            #   if ( !BYTE1(dword_E9AEA4) )
            #     goto LABEL_22;
            #   if ( GetAsyncKeyState(17) & 0x8000 )
            #   {
            #     if ( BYTE1(dword_E9AEA4) )
            #       goto LABEL_24;
            # LABEL_22:
            #     if ( GetAsyncKeyState(17) & 0x8000 )
            #     {
            #       BYTE1(dword_E9AEA4) = 1;
            #       sub_907350(&v19, 29, dword_E9AEA4, 1, SBYTE2(dword_E9AEA4));
            #       v15 = sub_908080(&v19);
            #       sub_6A5CE0(a1, a2, a3, a4, a5, a6, a7, a8, v15);
            #     }
            #     goto LABEL_24;
            #   }
            #   BYTE1(dword_E9AEA4) = 0;
            #   sub_907350(&v19, 29, dword_E9AEA4, 0, SBYTE2(dword_E9AEA4));
            #   v14 = sub_908080(&v19);
            #   sub_6A5EC0(a1, a2, a3, a4, a5, a6, a7, a8, v14);
            # LABEL_24:
            #   if ( !BYTE2(dword_E9AEA4) )
            #     goto LABEL_34;
            #   if ( !(GetAsyncKeyState(18) & 0x8000) )
            #   {
            #     BYTE2(dword_E9AEA4) = 0;
            #     sub_907350(&v19, 56, dword_E9AEA4, SBYTE1(dword_E9AEA4), 0);
            #     v16 = sub_908080(&v19);
            #     sub_6A5EC0(a1, a2, a3, a4, a5, a6, a7, a8, v16);
            #     return v20;
            #   }
            #   if ( !BYTE2(dword_E9AEA4) )
            #   {
            # LABEL_34:
            #     if ( GetAsyncKeyState(18) & 0x8000 )
            #     {
            #       BYTE2(dword_E9AEA4) = 1;
            #       sub_907350(&v19, 56, dword_E9AEA4, SBYTE1(dword_E9AEA4), 1);
            #       v17 = sub_908080(&v19);
            #       sub_6A5CE0(a1, a2, a3, a4, a5, a6, a7, a8, v17);
            #     }
            #   }
            #   return v20;
            # }
            if functionString.find("GetForegroundWindow()") != -1:
                if functionString.find("!= hwnd") != -1:
                        if functionString.find("return 1;") != -1:
                            if functionString.find("GetAsyncKeyState(16) & 0x8000") != -1:
                                if functionString.find("GetAsyncKeyState(17) & 0x8000") != -1:
                                    if functionString.find("GetAsyncKeyState(18) & 0x8000") != -1:
                                        functionList["ProcessKeyboardEvent"] = functionAddress

            # ProcessMouseEvent
            # ----------------------------------------------------------------------------------------------------
            # void __usercall sub_5FB500(int a1@<ebp>, int a2@<edi>, double a3@<st7>, double a4@<st6>, double a5@<st5>, double a6@<st4>, double a7@<st3>, double a8@<st2>, double a9@<st1>, double a10@<st0>)
            # {
            #   int v10; // eax
            #   char v11; // bl
            #   HWND v12; // eax
            #   char *v13; // ST04_4
            #   int v14; // edi
            #   int v15; // eax
            #   signed __int64 v16; // rax
            #   char v17; // al
            #   _BYTE *v18; // eax
            #   void *v19; // eax
            #   _BYTE *v20; // eax
            #   HWND v21; // eax
            #   int v22; // eax
            #   int v23; // eax
            #   _BYTE *v24; // eax
            #   _BYTE *v25; // eax
            #   _BYTE *v26; // eax
            #   int v27; // eax
            #   int *v28; // ecx
            #   _BYTE *v29; // eax
            #   char v30; // al
            #   BOOL v31; // eax
            #   _BYTE *v32; // eax
            #   _BYTE *v33; // eax
            #   int v34; // eax
            #   int *v35; // ecx
            #   _BYTE *v36; // eax
            #   char v37; // al
            #   bool v38; // zf
            #   _BYTE *v39; // eax
            #   _BYTE *v40; // eax
            #   int v41; // [esp-4h] [ebp-18h]
            #   struct tagPOINT Point; // [esp+4h] [ebp-10h]
            #   int v43; // [esp+Ch] [ebp-8h]
            #   int v44; // [esp+10h] [ebp-4h]
            #
            #   v10 = *(_DWORD *)(dword_104919C + 1480);
            #   v11 = 0;
            #   if ( v10 == 2 || v10 == 1 || v10 == 5 )
            #   {
            #     v12 = GetForegroundWindow();
            #     if ( v12 )
            #     {
            #       if ( v12 == hwnd )
            #       {
            #         if ( dword_C287F8 && dword_F3F150 )
            #           (*(void (__stdcall **)(int))(*(_DWORD *)dword_F3F150 + 28))(dword_F3F150);
            #         if ( !dword_E8AC50 || *(_DWORD *)(dword_104919C + 1480) != 5 || *((_BYTE *)dword_E8AC50 + 1228) != 102 )
            #         {
            #           if ( byte_ED0FCC[0] )
            #           {
            #             if ( word_E9A8EC )
            #             {
            #               v13 = (char *)sub_8B7230((int *)dword_E8D3C8, 0x2F3Fu, 0);
            #               sub_4E5F10();
            #               sub_4E65B0(v13, (LPVOID)0x111, (LPVOID)1, (LPVOID)1, 0);
            #             }
            #             return;
            #           }
            #           v41 = a2;
            #           v14 = sub_8F1280();
            #           v15 = *(_DWORD *)(dword_104919C + 1480);
            #           if ( v15 != 2 && v15 != 1 )
            #           {
            #             LODWORD(v16) = sub_4CF660((int)dword_E8D11C + 9240, 0, 1);
            #             if ( v16 < 1
            #               || (v17 = *((_BYTE *)dword_E8D11C + *(_DWORD *)(*((_DWORD *)dword_E8D11C + 2) + 4) + 356), v17 == 3)
            #               || v17 == 4 )
            #             {
            #               v11 = 1;
            #               if ( (_BYTE)word_E9A8AA )
            #               {
            #                 LOBYTE(word_E9A8AA) = 0;
            #                 while ( ShowCursor(1) < 0 )
            #                   ;
            #                 SetCursorPos(*(_DWORD *)(dword_16D6198 + 312), *(_DWORD *)(dword_16D6198 + 316));
            #               }
            #               v18 = sub_612200();
            #               if ( sub_6122D0(v18) )
            #               {
            #                 v19 = sub_612200();
            #                 sub_612B60((int)v19, 0, 0);
            #               }
            #             }
            #           }
            #           sub_6A5700();
            #           byte_E9A840 = sub_6A7C30(&Point);
            #           v20 = sub_612200();
            #           if ( sub_6122D0(v20) && !byte_E9A840 && *(_BYTE *)(lParam + 2116) )
            #           {
            #             sub_6A5540();
            #             Point = *(struct tagPOINT *)&qword_E9A82C;
            #             v21 = (HWND)(*(int (**)(void))(*(_DWORD *)lParam + 28))();
            #             if ( !*(_BYTE *)(lParam + 4) )
            #               ClientToScreen(v21, &Point);
            #             SetCursorPos(Point.x, Point.y);
            #             byte_E9A840 = sub_6A7C30(&Point);
            #           }
            #           if ( Point.x >= 0 )
            #           {
            #             v22 = sub_992F80((_DWORD *)lParam);
            #             if ( Point.x <= v22 - 1 )
            #               dword_F3FB7C = Point.x;
            #             else
            #               dword_F3FB7C = sub_992F80((_DWORD *)lParam) - 1;
            #           }
            #           else
            #           {
            #             dword_F3FB7C = 0;
            #           }
            #           if ( Point.y >= 0 )
            #           {
            #             v23 = sub_992F40((_DWORD *)lParam);
            #             if ( Point.y <= v23 - 1 )
            #               dword_F3FB80 = Point.y;
            #             else
            #               dword_F3FB80 = sub_992F40((_DWORD *)lParam) - 1;
            #           }
            #           else
            #           {
            #             dword_F3FB80 = 0;
            #           }
            #           if ( (_BYTE)word_E9A8EC )
            #           {
            #             if ( byte_F3FB9F )
            #               LOBYTE(word_E9A8EC) = 0;
            #           }
            #           else
            #           {
            #             byte_F3FB9F = 0;
            #           }
            #           qword_E9A82C = (signed __int16)dword_F3FB7C;
            #           *(&qword_E9A82C + 1) = (signed __int16)dword_F3FB80;
            #           dword_E9A834 = (signed __int16)dword_F3FB8C;
            #           dword_E9A838 = dword_F3FB84;
            #           dword_E9A83C = dword_F3FB88;
            #           if ( dword_E9A8DC != dword_F3FB7C || dword_E9A8E0 != dword_F3FB80 )
            #           {
            #             dword_E9AE6C = 0;
            #             dword_E9AE64 = sub_8F1280();
            #           }
            #           if ( !v11 )
            #           {
            #             v24 = sub_612200();
            #             if ( !sub_6122D0(v24) || (_BYTE)word_E9A8AA )
            #               sub_5D46F0((float *)dword_104919C, dword_E9A834);
            #           }
            #           if ( (_BYTE)word_E9A8EC )
            #           {
            #             sub_80C5F0(dword_F3FB7C, dword_F3FB80);
            #             if ( !(_BYTE)word_E9A8E4 )
            #             {
            #               dword_F3A03C = sub_8F0E40();
            #               unk_E9A950 = v14;
            #               if ( dword_16D6198 )
            #               {
            #                 if ( (_BYTE)word_E9A8AA || (v25 = sub_612200(), sub_6122D0(v25)) )
            #                 {
            #                   if ( !v11 )
            #                     goto LABEL_63;
            #                 }
            #                 if ( !byte_E9A840 )
            #                   goto LABEL_64;
            #                 if ( dword_DD8A3C != 3 )
            #                 {
            #                   v43 = dword_F3FB7C;
            #                   v44 = dword_F3FB80;
            #                   if ( sub_927830((int *)dword_16D6198, &v43) )
            #                     goto LABEL_64;
            #                 }
            #               }
            #               if ( v11 )
            #               {
            # LABEL_64:
            #                 dword_E8ABC8 = 2;
            #                 goto LABEL_85;
            #               }
            # LABEL_63:
            #               sub_5D3F70(dword_F3FB7C, dword_F3FB80);
            #               goto LABEL_64;
            #             }
            #             if ( (unsigned int)(v14 - unk_E9A950) > 0x2EE && !byte_F395ED )
            #             {
            #               byte_F395ED = 1;
            #               if ( !(_BYTE)word_E9A8AA )
            #               {
            #                 v26 = sub_612200();
            #                 if ( !sub_6122D0(v26) )
            #                 {
            #                   if ( dword_16D6198 )
            #                   {
            #                     v43 = dword_F3FB7C;
            #                     v44 = dword_F3FB80;
            #                     sub_928280((int *)dword_16D6198, &v43);
            #                   }
            #                 }
            #               }
            #             }
            #           }
            #           else
            #           {
            #             if ( (_BYTE)word_E9A8E4 )
            #             {
            #               v27 = sub_8F0E40();
            #               v28 = (int *)dword_16D6198;
            #               dword_F3A03C = v27;
            #               byte_E9A81B = 0;
            #               if ( dword_16D6198 )
            #               {
            #                 if ( ((_BYTE)word_E9A8AA || (v29 = sub_612200(), v30 = sub_6122D0(v29), v28 = (int *)dword_16D6198, v30))
            #                   && !v11
            #                   || ((v43 = dword_F3FB7C, v44 = dword_F3FB80, byte_F395ED == 1) ? (v31 = sub_928390(v28, &v43)) : (v31 = sub_928030(v28, &v43)),
            #                       !v31 && !dword_E9A948 && !v11) )
            #                 {
            #                   sub_5D3080((int *)dword_104919C, a3, a4, a5, a6, a7, a8, a9, a10, dword_F3FB7C, dword_F3FB80);
            #                 }
            #               }
            #               dword_E9A948 = 0;
            #               unk_E9A950 = 0;
            #               dword_E8ABC8 = 2;
            #             }
            #             byte_F395ED = 0;
            #           }
            # LABEL_85:
            #           LOBYTE(word_E9A8E4) = word_E9A8EC;
            #           if ( HIBYTE(word_E9A8EC) )
            #           {
            #             sub_80C5F0(dword_F3FB7C, dword_F3FB80);
            #             if ( HIBYTE(word_E9A8E4) )
            #             {
            #               if ( !(_BYTE)word_E9A8AA )
            #               {
            #                 v33 = sub_612200();
            #                 if ( !sub_6122D0(v33) && (unsigned int)(v14 - dword_E9A94C) > 0x1F4 && !byte_F395EE )
            #                 {
            #                   byte_F395EE = 1;
            #                   if ( dword_16D6198 )
            #                   {
            #                     v43 = dword_F3FB7C;
            #                     v44 = dword_F3FB80;
            #                     sub_928730((int *)dword_16D6198, &v43);
            #                   }
            #                 }
            #               }
            #               goto LABEL_120;
            #             }
            #             dword_F3A03C = sub_8F0E40();
            #             dword_E9A94C = v14;
            #             if ( dword_16D6198 )
            #             {
            #               if ( (_BYTE)word_E9A8AA || (v32 = sub_612200(), sub_6122D0(v32)) )
            #               {
            #                 if ( !v11 )
            #                   goto LABEL_94;
            #               }
            #               if ( dword_DD8A3C != 3 )
            #               {
            #                 v43 = dword_F3FB7C;
            #                 v44 = dword_F3FB80;
            #                 if ( sub_9284B0((int *)dword_16D6198, &v43) )
            #                   goto LABEL_95;
            #               }
            #             }
            #             if ( v11 )
            #             {
            # LABEL_95:
            #               dword_E8ABC8 = 2;
            #               goto LABEL_120;
            #             }
            # LABEL_94:
            #             sub_5D45A0(dword_F3FB7C, dword_F3FB80);
            #             goto LABEL_95;
            #           }
            #           if ( !HIBYTE(word_E9A8E4) )
            #           {
            # LABEL_119:
            #             byte_F395EE = 0;
            # LABEL_120:
            #             HIBYTE(word_E9A8E4) = HIBYTE(word_E9A8EC);
            #             v40 = sub_612200();
            #             if ( sub_6122D0(v40) && !(_BYTE)word_E9A8AA )
            #               sub_5DCE30(v11, a1, v41);
            #             sub_5FBCB0(a3, a4, a5, a6, a7, a8, a9, a10);
            #             return;
            #           }
            #           v34 = sub_8F0E40();
            #           v35 = (int *)dword_16D6198;
            #           dword_F3A03C = v34;
            #           if ( dword_16D6198 )
            #           {
            #             if ( (_BYTE)word_E9A8AA || (v36 = sub_612200(), v37 = sub_6122D0(v36), v35 = (int *)dword_16D6198, v37) )
            #             {
            #               if ( !v11 )
            #                 goto LABEL_117;
            #             }
            #             v43 = dword_F3FB7C;
            #             v44 = dword_F3FB80;
            #             if ( byte_F395EE == 1 )
            #             {
            #               sub_928840(v35, &v43);
            #               goto LABEL_118;
            #             }
            #             if ( sub_928620(v35, &v43) || dword_E9A944 )
            #               goto LABEL_118;
            #             v38 = v11 == 0;
            #           }
            #           else
            #           {
            #             if ( v11 )
            #               goto LABEL_118;
            #             if ( (_BYTE)word_E9A8AA )
            #               goto LABEL_117;
            #             v39 = sub_612200();
            #             if ( sub_6122D0(v39) )
            #               goto LABEL_117;
            #             v38 = dword_E9A944 == 0;
            #           }
            #           if ( v38 )
            # LABEL_117:
            #             sub_5D4010(dword_104919C, a10, a9, dword_F3FB7C, dword_F3FB80);
            # LABEL_118:
            #           dword_E9A944 = 0;
            #           dword_E9A94C = 0;
            #           dword_E8ABC8 = 2;
            #           goto LABEL_119;
            #         }
            #       }
            #     }
            #   }
            # }
            if functionString.find("0x2F3Fu") != -1:    # 12095 Interface locked.  Please use /safelock to unlock it.
                if functionString.find("GetForegroundWindow()") != -1:
                    if functionString.find("== hwnd") != -1:
                            if functionString.find("ShowCursor(1)") != -1:
                                if functionString.find("ClientToScreen") != -1:
                                    if functionString.find("SetCursorPos(Point.x, Point.y);") != -1:    # struct tagPOINT Point;
                                        functionList["ProcessMouseEvent"] = functionAddress

            # WindowProc
            # ----------------------------------------------------------------------------------------------------
            # WndClass.lpfnWndProc = (WNDPROC)sub_XXXXXX;
            if functionString.find("return DefWindowProcA(hWnd") != -1:
                functionList["WindowProc"] = functionAddress

            # CollisionCallbackForActors
            # ----------------------------------------------------------------------------------------------------
            # signed int __cdecl sub_51D6D0(int a1)    # 0x0051D6D0
            # {
            #   int v1; // esi
            #   int v2; // eax
            #   int v3; // eax
            #   _BYTE *v4; // eax
            #   _BYTE *v5; // esi
            #   bool v6; // zf
            #   int v7; // eax
            #   char v8; // al
            #   int v10; // eax
            #
            #   v1 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 32))(a1);
            #   if ( !v1 )
            #     return 1;
            #   v2 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 48))(a1);
            #   if ( v2 == 1 )
            #   {
            #     v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 12))(v1);
            #     if ( !v3 )
            #       return 1;
            #     v4 = (_BYTE *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 68))(v3);
            #     v5 = v4;
            #     if ( !v4 || !sub_97D0E0(v4) && v5[293] != 1 )
            #       return 1;
            #     if ( (*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)v5 + 168))(v5) )
            #       return 1;
            #     v6 = (*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)v5 + 80))(v5) == 0;
            #   }
            #   else
            #   {
            #     if ( v2 != 3 )
            #     {
            #       if ( v2 == 9 )
            #       {
            #         v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 36))(v1);
            #         if ( v10 )
            #         {
            #           if ( *(_BYTE *)(v10 + 152) )
            #             return 0;
            #         }
            #       }
            #       return 1;
            #     }
            #     v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 28))(v1);
            #     if ( !v7 )
            #       return 1;
            #     v8 = *(_BYTE *)(v7 + 38);
            #     if ( v8 == 50 )
            #       return 0;
            #     v6 = v8 == 51;
            #   }
            #   if ( v6 )
            #     return 0;
            #   return 1;
            # }
            if functionString.find("v1 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 32))(a1);") != -1:
                if functionString.find("v2 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 48))(a1);") != -1:
                    if functionString.find("v3 = (*(int (__thiscall **)(int))(*(_DWORD *)v1 + 12))(v1);") != -1:
                        if functionString.find("v4 = (_BYTE *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 68))(v3);") != -1:
                            functionList["CollisionCallbackForActors"] = functionAddress

            # CastRay
            # ----------------------------------------------------------------------------------------------------
            # int __cdecl sub_59BCA0(int a1, float a2, float a3, float a4)
            # {
            #   int v5; // eax
            #   int v6; // [esp-4h] [ebp-14h]
            #   float v7; // [esp+0h] [ebp-10h]
            #   float v8; // [esp+4h] [ebp-Ch]
            #   float v9; // [esp+8h] [ebp-8h]
            #
            #   if ( !a1 )
            #     return 0;
            #   v5 = *(_DWORD *)a1;
            #   v9 = a4;
            #   v8 = a3;
            #   v7 = a2;
            #   (*(void (__thiscall **)(int, int *))(v5 + 136))(a1, &v6);
            #   return sub_59BCF0(a1, a1 + 100, v6, v7, v8, v9);
            # }
            # ....................................................................................................
            # if ( sub_59BB10(*(_DWORD *)(v1 + 3884), *(float *)(v1 + 100), *(float *)(v1 + 104), *(float *)(v1 + 108)) )    # 0x0059BB10
            if functionString.find("0x3194u") != -1:    # 12692 %1 is dead, canceling auto-follow.
                if functionString.find("0x3195u") != -1:    # 12693 %1 is too far away, canceling auto-follow.
                    if functionString.find("15.0 <=") != -1:
                        if functionString.find("30.0 <=") != -1:
                            matches = re.findall("if \( sub_([0-9A-F]+)\(\*\(_DWORD \*\)\([0-9a-z]+ \+ \d+\), \*\(float \*\)\([0-9a-z]+ \+ 100\), \*\(float \*\)\([0-9a-z]+ \+ 104\), \*\(float \*\)\([0-9a-z]+ \+ 108\)\) \)", functionString, re.MULTILINE)
                            if matches:
                                functionList["CastRay"] = "0x00" + matches[0]

            # CastRay2
            # ----------------------------------------------------------------------------------------------------
            # int __usercall sub_59BCF0@<eax>(int a1@<esi>, int a2, int a3, float a4, float a5, float a6)    # 0x0059BCF0
            # {
            #   double v7; // st6
            #   double v8; // st5
            #   double v9; // st2
            #   int v10; // eax
            #   signed int v11; // esi
            #   void **v12; // [esp+0h] [ebp-B8h]
            #   LPVOID lpMem; // [esp+60h] [ebp-58h]
            #   char v14; // [esp+66h] [ebp-52h]
            #   int v15; // [esp+68h] [ebp-50h]
            #   char v16; // [esp+6Ch] [ebp-4Ch]
            #   float v17; // [esp+94h] [ebp-24h]
            #   float v18; // [esp+98h] [ebp-20h]
            #   float v19; // [esp+9Ch] [ebp-1Ch]
            #   float v20; // [esp+A0h] [ebp-18h]
            #   float v21; // [esp+A4h] [ebp-14h]
            #   float v22; // [esp+A8h] [ebp-10h]
            #   int v23; // [esp+B4h] [ebp-4h]
            #
            #   if ( sub_8C4950((_DWORD *)dword_E805A8, dword_E8F1BC) )
            #     return 1;
            #   v7 = *(float *)(a2 + 4);
            #   v8 = *(float *)(a2 + 8);
            #   if ( a3 == dword_BFA8A4 || a3 == dword_BFA8A8 || a3 == dword_BFA898 )
            #     v8 = v8 + 1.0;
            #   if ( flt_E7CEA4 == a4
            #     && flt_E7CEA8 == a5
            #     && flt_E7CEAC == a6
            #     && flt_E7CE98 == *(float *)a2
            #     && flt_E7CE9C == v7
            #     && flt_E7CEA0 == v8 )
            #   {
            #     return dword_E7CEB0;
            #   }
            #   v9 = *(float *)a2;
            #   flt_E7CE98 = *(float *)a2;
            #   v17 = v9;
            #   flt_E7CE9C = v7;
            #   v18 = v7;
            #   flt_E7CEA0 = v8;
            #   v19 = v8;
            #   flt_E7CEA4 = a4;
            #   flt_E7CEA8 = a5;
            #   flt_E7CEAC = a6;
            #   v20 = a4 - v9;
            #   v21 = a5 - v7;
            #   v22 = a6 - v8;
            #   sub_4C6170((float *)&v12, &v17);
            #   v12 = &CCollisionInfoLineSegmentVisibility::`vftable';
            #   v15 = 1;
            #   v14 = 1;
            #   v16 = 0;
            #   v10 = *(_DWORD *)dword_16CA784;
            #   v23 = 0;
            #   if ( (*(unsigned __int8 (__stdcall **)(int))(v10 + 68))(a1)
            #     && (**(unsigned __int8 (__stdcall ***)(void ***))dword_16CA784)(&v12) )
            #   {
            #     dword_E7CEB0 = 0;
            #     v11 = 0;
            #   }
            #   else
            #   {
            #     dword_E7CEB0 = 1;
            #     v11 = 1;
            #   }
            #   v23 = 1;
            #   v12 = &CCollisionInfoBase::`vftable';
            #   LOBYTE(v23) = 4;
            #   if ( lpMem )
            #     sub_8ED480(lpMem);
            #   return v11;
            # }
            if functionString.find("&CCollisionInfoLineSegmentVisibility::`vftable';") != -1:
                if functionString.find("\"*** DISCONNECTING: HitBySpell() is throwing a CMD_EXITGAME at %s:%lu\n\"") == -1:
                    functionList["CastRay2"] = functionAddress

            # DrawNetStatus
            # ----------------------------------------------------------------------------------------------------
            # void __cdecl sub_6279B0(int a1, int a2, LPCRITICAL_SECTION *a3)    # 0x006279B0
            # {
            #   __int64 v3; // kr00_8
            #   double v4; // st7
            #   double v5; // st7
            #   float v6; // ST4C_4
            #   int v7; // [esp+18h] [ebp-118h]
            #   int v8; // [esp+1Ch] [ebp-114h]
            #   int v9; // [esp+1Ch] [ebp-114h]
            #   char v10; // [esp+20h] [ebp-110h]
            #   __int64 v11; // [esp+70h] [ebp-C0h]
            #   __int64 v12; // [esp+78h] [ebp-B8h]
            #   int v13; // [esp+F0h] [ebp-40h]
            #
            #   if ( dword_E806A0 )
            #   {
            #     sub_5BEBB0((float *)&v11);
            #     sub_83B2C0(a3, &v11);
            #     v8 = *(_DWORD *)(dword_C98B84 + 80);
            #     v7 = sub_6281B0(a3) - 500;
            #     if ( (double)v7 < 0.0 )
            #       v7 = 0;
            #     v3 = v11 + v12;
            #     v4 = (double)v7 / (double)v8;
            #     v9 = ((signed int)v11 + (signed int)v12 - dword_F2F590) / 32;
            #     v5 = 1.0 - v4;
            #     if ( v9 )
            #     {
            #       dword_F2F590 = v11 + v12;
            #       dword_F2F594 = HIDWORD(v3);
            #     }
            #     sub_481880((int)&v10, (int)"%0.2f%%", COERCE_UNSIGNED_INT64(v5 * 100.0));
            #     sub_5350B0(&v10, (unsigned __int16)a1, (unsigned __int16)a2, (LPVOID)0xC);    # CDisplay__WriteTextHD2
            #     sub_481880((int)&v10, (int)"%ldms", v13);
            #     sub_5350B0(&v10, (unsigned __int16)a1 + 64, (unsigned __int16)a2, (LPVOID)0xC);    # CDisplay__WriteTextHD2
            #     v6 = v5;
            #     sub_627E50(a1, a2 + 16, 128, 3, v6, v9);
            #   }
            # }
            if functionString.find("\"%0.2f%%\"") != -1:
                if functionString.find("\"%ldms\"") != -1:
                    functionList["DrawNetStatus"] = functionAddress

            # ExecuteCmd
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("\"ExecuteCmd has received a CMD_EXITGAME.\\n\"") != -1:
                if functionString.find("\"help.html\"") != -1:
                    functionList["ExecuteCmd"] = functionAddress

            # DoSpellEffect
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("\"Source\"") != -1:
                if functionString.find("\"%sSPELL_POINT_DAG\"") != -1:
                    if functionString.find("\"***DAG Error DAG = %08x\"") != -1:
                        functionList["DoSpellEffect"] = functionAddress

            # PlaySoundAtLocation
            # ----------------------------------------------------------------------------------------------------
            # void __stdcall sub_53A330(float a1, float a2, float a3, int a4)    0x0053A330
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
            # ----------------------------------------------------------------------------------------------------
            # DWORD sub_8EEB80()    # 0x008EEB80
            # {
            #   return GetTickCount() - dword_16C8F20;
            # }
            if functionString.find("return GetTickCount() - dword_") != -1:
                functionList["GetTime"] = functionAddress

            # UpdateLight
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("|= 1u") != -1:
                if functionString.find("|= 2u") != -1:
                    if functionString.find("|= 4u") != -1:
                        if functionString.find("|= 8u") != -1:
                            if functionString.find("|= 0x10u") != -1:
                                if functionString.find("|= 0x20u") != -1:
                                    if functionString.find("|= 0x40u") != -1:
                                        if functionString.find("& 0x40") != -1:
                                            if functionString.find("& 0x20") != -1:
                                                if functionString.find("& 0x10") != -1:
                                                    if functionString.find("&= 0xFFFFFFBF") != -1:
                                                        if functionString.find("&= 0xFFFFFFDF") != -1:
                                                            if functionString.find("&= 0xFFFFFFEF") != -1:
                                                                if functionString.find("&= 0xFFFFFFFD") != -1:
                                                                    if functionString.find("&= 0xFFFFFFFE") != -1:
                                                                        if functionString.find("case 1:") != -1:
                                                                            if functionString.find("case 2:") != -1:
                                                                                if functionString.find("case 4:") != -1:
                                                                                    if functionString.find("case 6:") != -1:
                                                                                        functionList["UpdateLight"] = functionAddress

            # GetGaugeValueFromEQ
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("\"%s\\n%s\"") != -1:
                if functionString.find("\"%d%%%%\"") != -1:
                        if functionString.find("\"%s\"") != -1:
                            if functionString.find("\"Total Completed: %d/%d\"") != -1:
                                if functionString.find("\"Category Completed: %d/%d\"") != -1:
                                    if functionString.find("\"Completed: %d/%d\"") != -1:
                                            functionList["GetGaugeValueFromEQ"] = functionAddress

            # get_bearing
            # ----------------------------------------------------------------------------------------------------
            # long double __cdecl sub_59B4D0(float a1, float a2, float a3, float a4)    # 0x0059B4D0
            # {
            #   double v4; // st6
            #   long double v5; // st5
            #   double v6; // st4
            #   long double v7; // st2
            #   long double v8; // rt2
            #   long double v9; // st2
            #   double v10; // st5
            #   long double v11; // st7
            #   long double result; // st7
            #   double v13; // st3
            #
            #   v4 = a3;
            #   v5 = fabs(a1 - a3);
            #   v6 = a2;
            #   v7 = fabs(a2 - a4);
            #   if ( v5 < 0.0000009999999974752427 )
            #     v5 = 0.0000009999999974752427;
            #   v8 = v7;
            #   v9 = v5;
            #   v10 = a4;
            #   v11 = atan2(v8, v9) * 180.0 * 0.3183099014828645;
            #   if ( a1 < v4 )
            #   {
            #     v13 = a1;
            #   }
            #   else
            #   {
            #     if ( a4 >= v6 )
            #       return (90.0 - v11 + 90.0) * 511.5 * 0.0027777778;
            #     if ( a4 <= v6 )
            #       return (v11 + 180.0) * 511.5 * 0.0027777778;
            #     v13 = a1;
            #     v10 = a4;
            #   }
            #   if ( v13 > v4 || v10 > v6 )
            #     result = v11 * 511.5 * 0.0027777778;
            #   else
            #     result = (90.0 - v11 + 270.0) * 511.5 * 0.0027777778;
            #   return result;
            # }
            if functionString.find("fabs") != -1:
                if functionString.find("atan2") != -1:
                    if functionString.find("0.0000009999999974752427") != -1:
                        if functionString.find(" * 180.0 * 0.3183099014828645;") != -1:
                            if functionString.find(" + 90.0) * 511.5 * 0.0027777778;") != -1:
                                if functionString.find(" + 180.0) * 511.5 * 0.0027777778;") != -1:
                                    if functionString.find(" * 511.5 * 0.0027777778;") != -1:
                                        if functionString.find(" + 270.0) * 511.5 * 0.0027777778;") != -1:
                                            functionList["get_bearing"] = functionAddress

            # get_melee_range
            # ----------------------------------------------------------------------------------------------------
            # double __cdecl sub_59BBC0(float *a1, float *a2)    # 0x0059BBC0
            # {
            #   float v3; // ST0C_4
            #   float v4; // ST00_4
            #   float v5; // [esp+4h] [ebp-18h]
            #   float v6; // [esp+8h] [ebp-14h]
            #   float v7; // [esp+10h] [ebp-Ch]
            #   float v8; // [esp+18h] [ebp-4h]
            #   float v9; // [esp+18h] [ebp-4h]
            #   signed int retaddr; // [esp+20h] [ebp+4h]
            #
            #   if ( !a1 || !a2 )
            #     return 14.0;
            #   v8 = sub_65C240(a1);
            #   v6 = sub_65C240(a2);
            #   if ( dword_F3FB6C == -572662307 )
            #   {
            #     dword_F3F15C = retaddr;
            #     if ( retaddr > 286331153 )
            #       *((_BYTE *)&off_C1117D - 2) = 0;
            #   }
            #   v3 = sub_5BF990(a1);
            #   v4 = v3 - sub_5BF990(a2);
            #   v5 = sub_5BFF40(v4);
            #   v9 = (v8 + v6) * 0.75;
            #   if ( v9 < 14.0 )
            #     v9 = 14.0;
            #   v7 = v9 + 2.0 + v5;
            #   if ( v7 > 75.0 )
            #     v7 = 75.0;
            #   return v7;
            # }
            if functionString.find("return 14.0") != -1:
                if functionString.find("== -572662307") != -1:
                    if functionString.find("> 286331153") != -1:
                        if functionString.find("< 14.0") != -1:
                            if functionString.find("= 14.0") != -1:
                                if functionString.find("> 75.0") != -1:
                                    if functionString.find("= 75.0") != -1:
                                        functionList["get_melee_range"] = functionAddress

            # vehicle_premove
            # vehicle_postmove
            # ----------------------------------------------------------------------------------------------------
            # signed int __cdecl sub_580A20(unsigned __int16 *a1)
            # {
            #   int v1; // esi
            #   char v2; // bl
            #   float *v4; // ebx
            #   _DWORD *v5; // eax
            #
            #   v1 = sub_64FA30((_DWORD **)dword_F30FE8, *a1);
            #   if ( v1 )
            #   {
            #     v4 = 0;
            #     if ( a1[1] )
            #       v4 = (float *)sub_64FA30((_DWORD **)dword_F30FE8, a1[1]);
            #     if ( sub_97E300((_DWORD *)v1) )
            #     {
            #       sub_5994E0((float *)(v1 + 100), (_DWORD *)a1 + 1, (_BYTE *)v1, 0, v4);
            #       *(_DWORD *)(v1 + 4812) = *((_DWORD *)dword_E81B64 + 85);
            #       v1 = sub_64C7C0((_DWORD *)v1);
            #     }
            #     else if ( sub_97E310((_DWORD *)v1) )
            #     {
            #       return 1;
            #     }
            #     if ( (*((_DWORD *)a1 + 4) & 0x1FF80000) != 34603008 || (*((_DWORD *)a1 + 2) & 0x3FF) != 66 )
            #     {
            #       sub_5C7C90((_DWORD *)v1);
            #       *(_DWORD *)(v1 + 476) = 0;
            #       sub_97F9B0((float *)v1);    # 0x0097F9B0 = vehicle_premove
            #       v5 = a1 + 2;
            #     }
            #     else
            #     {
            #       *(_DWORD *)(v1 + 476) = 6;
            #       sub_5C7C90((_DWORD *)v1);
            #       sub_97F9B0((float *)v1);    # 0x0097F9B0 = vehicle_premove
            #       *((_DWORD *)a1 + 4) &= 0xE007FFFF;
            #       v5 = a1 + 2;
            #       *((_DWORD *)a1 + 2) &= 0xFFFFFC00;
            #       *((_DWORD *)a1 + 6) &= 0xFFFFE000;
            #       *((_DWORD *)a1 + 5) &= 0xFFFFE000;
            #       *v5 &= 0xFFFFE000;
            #     }
            #     sub_5994E0((float *)(v1 + 100), v5, (_BYTE *)v1, 0, v4);
            #     sub_97FA60((float *)v1, 0);    # 0x0097FA60 = vehicle_postmove
            #     *(_DWORD *)(v1 + 4812) = *((_DWORD *)dword_E81B64 + 85);
            #     sub_5C5560((float *)v1);
            #     return 1;
            #   }
            #   if ( *(_DWORD *)(dword_103DA3C + 1480) == 5
            #     && dword_E7F3F0
            #     && (unsigned int)(*((_DWORD *)dword_E81B64 + 85) - *((_DWORD *)dword_E7F3F0 + 210)) >= 0x3A98 )
            #   {
            #     *((_DWORD *)dword_E7F3F0 + 210) = *((_DWORD *)dword_E81B64 + 85);
            #     if ( *(_DWORD *)dword_E81B60 )
            #     {
            #       word_E81930 = sub_89E000(22786, 0);
            #       LOWORD(dword_E81932) = *a1;
            #       v2 = sub_83EDA0(*(int *)dword_E81B60, 4, &word_E81930, 4u);
            #       j_j_j___free_base(0);
            #       --dword_1070014;
            #       if ( !v2 )
            #       {
            #         sub_4EB5F0((int *)dword_C99C84, (LPCRITICAL_SECTION **)dword_E81B60);
            #         return 0;
            #       }
            #     }
            #     else if ( !byte_E8F09C )
            #     {
            #       sub_8F00D0("Attempt to send message %d on a void connection.", 22786);
            #     }
            #   }
            #   return 0;
            # }
            if functionString.find("return 0;") != -1:
                if functionString.find("return 1;") != -1:
                    if functionString.find("= 6;") != -1:
                        if functionString.find("== 5") != -1:
                            if functionString.find("& 0x3FF) != 66") != -1:
                                if functionString.find(">= 0x3A98") != -1:
                                    matches = re.findall("= 0;\n\s+sub_([0-9A-F]+)\(\(float \*\)[0-9a-z]+\);", functionString, re.MULTILINE)
                                    if matches:
                                        functionList["vehicle_premove"] = "0x00" + matches[0]
                                    matches = re.findall("sub_([0-9A-F]+)\(\(float \*\)[0-9a-z]+, 0\);", functionString, re.MULTILINE)
                                    if matches:
                                        functionList["vehicle_postmove"] = "0x00" + matches[0]

            # EQZoneInfo
            # ----------------------------------------------------------------------------------------------------
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

            # ControlledSpawn
            # ----------------------------------------------------------------------------------------------------
            #            if ( -20001.1 == v83 )
            #              sub_646C10(dword_E7F448, 0.0, 0);    # 0x00E7F448    0x00646C10 = EQPlayer::SetAccel()
            if functionString.find("-20001.1") != -1:
                if functionString.find(", 0.0, 0);") != -1:
                    matches = re.findall("if \( -20001.1 == [0-9a-z]+ \)\n\s+sub_[0-9A-F]+\(dword_([0-9A-F]+), 0.0, 0\);", functionString, re.MULTILINE)
                    if matches:
                        functionList["ControlledSpawn"] = "0x00" + matches[0]

            # PlayerSpawn
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
            # v0 = sub_8B4BE0((int *)dword_E7F46C, 0x3391u, dword_E7F678);    # 0x00E7F678    # 13201 You must first target a corpse to loot!
            if functionString.find("0x3391u") != -1:
                matches = re.findall("sub_[0-9A-F]+\(\(int \*\)dword_[0-9A-F]+, 0x3391u, dword_([0-9A-F]+)\);", functionString, re.MULTILINE)
                if matches:
                    functionList["TargetSpawn"] = "0x00" + matches[0]

            # StringTable
            # ----------------------------------------------------------------------------------------------------
            # switch ( a1 )
            # {
            #   case 1:
            #     result = sub_8B5330((int *)dword_E80480, 0x5DEu, 0);    # 1502 Warrior    # 0x00E80480
            #     break;
            #   case 2:
            #     result = sub_8B5330((int *)dword_E80480, 0x5E2u, 0);    # 1506 Cleric
            #     break;
            #   case 3:
            #     result = sub_8B5330((int *)dword_E80480, 0x5E6u, 0);    # 1510 Paladin
            #     break;
            #   case 4:
            #     result = sub_8B5330((int *)dword_E80480, 0x5EEu, 0);    # 1514 Shadow Knight
            #     break;
            if functionString.find("0x5DEu") != -1:    # 1502 Warrior
                if functionString.find("0x5E2u") != -1:    # 1506 Cleric
                    if functionString.find("0x5E6u") != -1:    # 1510 Paladin
                        if functionString.find("0x5EEu") != -1:    # 1514 Shadow Knight
                            matches = re.findall("result = sub_[0-9A-F]+\(\(int \*\)dword_([0-9A-F]+), 0x5DEu, 0\);", functionString, re.MULTILINE)
                            if matches:
                                functionList["StringTable"] = "0x00" + matches[0]

            # StringTable__getString
            # ----------------------------------------------------------------------------------------------------
            # void *__thiscall sub_8B5330(int *this, unsigned int a2, _BYTE *a3)    # 0x008B5330
            # {
            #   unsigned int *v3; // eax
            #   void *result; // eax
            #
            #   v3 = sub_8B52D0(this, a2, 0, this[2]);
            #   if ( v3 )
            #   {
            #     if ( a3 )
            #       *a3 = 1;
            #     result = (void *)v3[1];
            #   }
            #   else
            #   {
            #     sub_481880((int)&unk_108CA10, (int)"%s (%d)", (int)off_C5C5DC);
            #     if ( a3 )
            #       *a3 = 0;
            #     result = &unk_108CA10;
            #   }
            #   return result;
            # }
            if functionString.find("%s (%d)") != -1:
                if re.search("sub_[0-9A-F]+\(\(int\)&unk_[0-9A-F]+, \(int\)\"%s \(%d\)\", \(int\)off_[0-9A-F]+\);", functionString):
                    functionList["StringTable__getString"] = functionAddress

            # CDBStr
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
            # char *__thiscall sub_52FC80(_DWORD *this, unsigned int a2, unsigned int a3, _BYTE *a4)    # 0x0052FC80
            # {
            #   _DWORD *v4; // esi
            #   _DWORD *v5; // ecx
            #   LPVOID *v6; // esi
            #   LPVOID *v7; // ecx
            #
            #   v4 = this;
            #   v5 = *(_DWORD **)(*this + 4 * (a3 % this[1]));
            #   if ( !v5 )
            #     goto LABEL_4;
            #   while ( v5[1] != a3 )
            #   {
            #     v5 = (_DWORD *)v5[2];
            #     if ( !v5 )
            #       goto LABEL_4;
            #   }
            #   v7 = *(LPVOID **)(*(_DWORD *)*v5 + 4 * (a2 % *(_DWORD *)(*v5 + 4)));
            #   if ( !v7 )
            #   {
            # LABEL_4:
            #     if ( a4 )
            #       *a4 = 0;
            #     v6 = (LPVOID *)(v4 + 4);
            #     sub_8EDB10(v6, (int)"Unknown DB String %d-%d", a2);
            #     v7 = v6;
            #     return sub_8EB790(v7);
            #   }
            #   while ( v7[1] != (LPVOID)a2 )
            #   {
            #     v7 = (LPVOID *)v7[2];
            #     if ( !v7 )
            #       goto LABEL_4;
            #   }
            #   if ( !a4 )
            #     return sub_8EB790(v7);
            #   *a4 = 1;
            #   return sub_8EB790(v7);
            # }
            if functionString.find("\"Unknown DB String %d-%d\"") != -1:
                functionList["CDBStr__GetString"] = functionAddress

            # EQ_Character
            # ----------------------------------------------------------------------------------------------------
            # if ( *((_DWORD *)v2 + 142) == 1
            #   && (*(unsigned __int8 (**)(void))(*(_DWORD *)((char *)dword_E7E264
            #                                               + *(_DWORD *)(*((_DWORD *)dword_E7E264 + 2) + 4)    # 0x00E7E264
            #                                               + 8)
            #                                   + 148))() )
            # {
            if functionString.find("0x1DE3u") != -1:    # 7651 Open Polls
                if functionString.find("\"%s ( %d )\"") != -1:
                    matches = re.findall("\+ \*\(_DWORD \*\)\(\*\(\(_DWORD \*\)dword_([0-9A-F]+) \+ 2\) \+ 4\)", functionString, re.MULTILINE)
                    if matches:
                        functionList["EQ_Character"] = "0x00" + matches[0]

            # EQ_Character__encum_factor
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("0x3067u") != -1:    # 12391 You are no longer encumbered.
                if functionString.find("0x3068u") != -1:    # 12392 You are encumbered!
                    if functionString.find(">= 0.2") != -1:
                        if functionString.find(">= 50.0") != -1:
                            if functionString.find("< 0.33000001") != -1:
                                if functionString.find("< 100.0") != -1:
                                    if functionString.find("= 0.75;") != -1:
                                        if functionString.find("= 0.5;") != -1:
                                            if functionString.find("return 1.0;") != -1:
                                                functionList["EQ_Character__encum_factor"] = functionAddress

            # EQ_Character__TakeFallDamage
            # ----------------------------------------------------------------------------------------------------
            # v8 = (int)a1;
            # v9 = 0;
            # v10 = (double)(signed int)a1[5] * 0.0099999998;
            # if ( !*((_BYTE *)dword_E805BC + 364) )
            # {
            #   *((_BYTE *)dword_E805BC + 364) = 1;
            #   return 0;
            # }
            # v23 = 1.0;
            # v30 = 0;
            # v12 = v10 + a8 - 1.5;
            # v13 = 0.0;
            # if ( v12 >= 9.0 )
            # {
            #   v9 = 200000;
            #   goto LABEL_5;
            # }
            if functionString.find("* 0.0099999998;") != -1:
                if functionString.find(">= 9.0") != -1:
                    if functionString.find("= 200000;") != -1:
                        if functionString.find("0xE4u, 1, 0, 1, 1) / 100;") != -1:
                            if functionString.find("1, 0, 1, 1, 0);") != -1:
                                functionList["EQ_Character__TakeFallDamage"] = functionAddress

            # EQ_Character__CanIBreathe
            # ----------------------------------------------------------------------------------------------------
            # bool __thiscall sub_4DD9D0(void *this)    # 0x004DD9D0
            # {
            #   int v1; // esi
            #   signed int v2; // edi
            #   bool result; // al
            #
            #   v1 = (int)this;
            #   v2 = 0;
            #   if ( sub_8C4A30((_DWORD *)dword_E805A8, *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 356)) )
            #     v2 = 1;
            #   if ( (*(_BYTE *)(*(_DWORD *)(v1 + 8) + 160) >= 5u || v2)
            #     && *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 8)) + 15600) != dword_BE383C
            #     && *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 8)) + 15600) != dword_BE37A8
            #     && *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 8)) + 15600) != dword_BE37D0 )
            #   {
            #     result = sub_4C2410(v1, 0xEu, 1, 0, 1, 1) > 0;    # EQ_Character__TotalSpellAffects(EQ_SPELL_AFFECT_BREATHE_UNDERWATER, 1, 0, 1, 1,);
            #   }
            #   else
            #   {
            #     result = 1;
            #   }
            #   return result;
            # }
            if functionString.find("bool result;") != -1:
                if functionString.find(">= 5u ||") != -1:
                    if functionString.find("0xEu, 1, 0, 1, 1) > 0;") != -1:
                        if functionString.find("result = 1;") != -1:
                            if functionString.find("return result;") != -1:
                                functionList["EQ_Character__CanIBreathe"] = functionAddress


            # EQ_Character__CanISeeInvis
            # ----------------------------------------------------------------------------------------------------
            # int __thiscall sub_4DE840(_DWORD *this)    # 0x004DE840
            # {
            #   int v1; // esi
            #   int v2; // ecx
            #   int v3; // edi
            #   int v4; // ecx
            #   int result; // eax
            #   int v6; // ecx
            #   char v7; // [esp+18h] [ebp-4h]
            #
            #   v1 = (int)this;
            #   v2 = this[2];
            #   if ( v2 && (*(unsigned __int8 (**)(void))(*(_DWORD *)v2 + 224))() )
            #     v3 = 3001;
            #   else
            #     v3 = sub_4C2410(v1, 0xDu, 1, 0, 1, 1);    # EQ_Character__TotalSpellAffects(EQ_SPELL_AFFECT_SEE_INVISIBLE, 1, 0, 1, 1,);
            #   if ( sub_4C2410(v1, 0x42u, 1, 0, 1, 1) <= 0 )
            #   {
            #     v4 = *(_DWORD *)(v1 + 8);
            #     if ( v4
            #       && *(_DWORD *)(*(int (__stdcall **)(char *))(*(_DWORD *)v4 + 136))(&v7) != dword_BE3770
            #       && *(_DWORD *)(*(int (__stdcall **)(char *))(**(_DWORD **)(v1 + 8) + 136))(&v7) != dword_BE38D4
            #       && *(_DWORD *)(*(int (__stdcall **)(char *))(**(_DWORD **)(v1 + 8) + 136))(&v7) != dword_BE39EC )
            #     {
            #       *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 8)) + 15332) = 255;
            #     }
            #   }
            #   else
            #   {
            #     *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 8)) + 15332) = 0;
            #   }
            #   if ( sub_4C2410(v1, 0x41u, 1, 0, 1, 1) <= 0 )
            #   {
            #     v6 = *(_DWORD *)(v1 + 8);
            #     if ( v6
            #       && (*(_DWORD *)(*(int (__stdcall **)(char *))(*(_DWORD *)v6 + 136))(&v7) == dword_BE3770
            #        || *(_DWORD *)(*(int (__stdcall **)(char *))(**(_DWORD **)(v1 + 8) + 136))(&v7) == dword_BE375C
            #        || *(_DWORD *)(*(int (__stdcall **)(char *))(**(_DWORD **)(v1 + 8) + 136))(&v7) == dword_BE3764
            #        || *(_DWORD *)(*(int (__stdcall **)(char *))(**(_DWORD **)(v1 + 8) + 136))(&v7) == dword_BE3760) )
            #     {
            #       *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 8)) + 15304) = 255;
            #     }
            #     result = v3;
            #   }
            #   else
            #   {
            #     *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 8)) + 15304) = 0;
            #     result = v3;
            #   }
            #   return result;
            # }
            if functionString.find("int result;") != -1:
                if functionString.find("= 3001;") != -1:
                    if functionString.find("0xDu, 1, 0, 1, 1);") != -1:
                        if functionString.find("0x42u, 1, 0, 1, 1) <= 0 )") != -1:
                            if functionString.find("0x41u, 1, 0, 1, 1) <= 0 )") != -1:
                                if functionString.find("= 255;") != -1:
                                    if functionString.find("return result;") != -1:
                                        functionList["EQ_Character__CanISeeInvis"] = functionAddress

            # EQ_Character__StunMe
            # ----------------------------------------------------------------------------------------------------
            # void __thiscall sub_4D3340(_DWORD *this, unsigned int a2, int a3, int a4, char a5)    # 0x004D3340
            # {
            #   _DWORD *v5; // esi
            #   unsigned int v6; // edi
            #   int v7; // eax
            #   int v8; // eax
            #   int v9; // ecx
            #   unsigned int v10; // eax
            #   int v11; // eax
            #   void *v12; // ST04_4
            #
            #   v5 = this;
            #   if ( this[2] && sub_4C2410((int)this, 0x28u, 1, 0, 1, 1) <= 0 )
            #   {
            #     sub_4C2410((int)v5, 0xE5u, 1, 0, 1, 1);
            #     v6 = a2;
            #     if ( a2 < 0x3E8 )
            #     {
            #       v7 = v5[2];
            #       if ( !v7 || *(_BYTE *)(v7 + 293) )
            #         return;
            #       v6 = 1000;
            #     }
            #     if ( !*(_DWORD *)(v5[2] + 1016) )
            #     {
            #       v8 = sub_8EEF60();
            #       v9 = v5[2];
            #       v10 = v6 + v8;
            #       if ( *(_DWORD *)(v9 + 1016) < v10 )
            #         *(_DWORD *)(v9 + 1016) = v10;
            #       *((_BYTE *)v5 + *(_DWORD *)(v5[1] + 4) + 352) = 1;
            #       sub_53C6F0(dword_E806A0, 23);
            #       *(float *)(v5[2] + 124) = 0.0;
            #       v11 = sub_64CC00((_DWORD *)v5[2]);
            #       if ( v11 )
            #         *(float *)(v11 + 124) = 0.0;
            #       if ( !sub_97B540(&unk_E8F3C0, 0x1Au) )
            #       {
            #         v12 = sub_8B5330((int *)dword_E80480, 0x30BFu, 0);
            #         sub_4E5B40();
            #         sub_4E61E0(v12, (LPVOID)0x154, (LPVOID)1, (LPVOID)1, 0);
            #       }
            #       if ( a5 )
            #         *(float *)(v5[2] + 140) = 32.0;
            #     }
            #   }
            # }
            if functionString.find("0x30BFu") != -1:    # 12479 You are stunned!
                if functionString.find("0x28u, 1, 0, 1, 1)") != -1:
                    if functionString.find("0xE5u, 1, 0, 1, 1)") != -1:
                        if functionString.find("= 1000;") != -1:
                            if functionString.find("= 32.0;") != -1:
                                functionList["EQ_Character__StunMe"] = functionAddress

            # EQ_Character__UnStunMe
            # ----------------------------------------------------------------------------------------------------
            # void __thiscall sub_4D3460(_DWORD *this)    # 0x004D3460
            # {
            #   _DWORD *v1; // esi
            #   void *v2; // ST04_4
            #
            #   v1 = this;
            #   sub_53C690(dword_E806A0);
            #   *(_DWORD *)(v1[2] + 1016) = 0;
            #   *((_BYTE *)v1 + *(_DWORD *)(v1[1] + 4) + 352) = 0;
            #   if ( !sub_97B540(&unk_E8F3C0, 0x1Au) )
            #   {
            #     v2 = sub_8B5330((int *)dword_E80480, 0x30C0u, 0);    # 12480 You are no longer stunned.
            #     sub_4E5B40();
            #     sub_4E61E0(v2, (LPVOID)0x154, (LPVOID)1, (LPVOID)1, 0);
            #   }
            # }
            if functionString.find("0x30C0u") != -1:    # 12480 You are no longer stunned.
                if functionString.find("0x1Au") != -1:
                    if functionString.find("0x154") != -1:
                        if functionString.find("= 0;") != -1:
                            functionList["EQ_Character__UnStunMe"] = functionAddress

            # EQ_Character__ProcessEnvironment
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("= 1.0;") != -1:
                if functionString.find("= -6;") != -1:
                    if functionString.find(">= 3u") != -1:
                        if functionString.find("!= 5") != -1:
                            if functionString.find("== 3") != -1:
                                if functionString.find("== 7") != -1:
                                    if functionString.find("= 3;") != -1:
                                        if functionString.find("> 1000") != -1:
                                            if functionString.find("& 0x7FFF;") != -1:
                                                if functionString.find("== 78") != -1:
                                                    if functionString.find("= 5;") != -1:
                                                        if functionString.find("= -12;") != -1:
                                                            if functionString.find("!= 4") != -1:
                                                                if functionString.find("!= 8") != -1:
                                                                    if functionString.find("= -10;") != -1:
                                                                        if functionString.find("< 10") != -1:
                                                                            if functionString.find("= 10;") != -1:
                                                                                if functionString.find("1, 0, 1, 1, 0);") != -1:
                                                                                    if functionString.find("/ 3;") != -1:
                                                                                        functionList["EQ_Character__ProcessEnvironment"] = functionAddress

            # EQ_Character__TotalSpellAffects
            # ----------------------------------------------------------------------------------------------------
            # bool __thiscall sub_4DD9D0(void *this)    # EQ_Character__CanIBreathe
            # {
            #   int v1; // esi
            #   signed int v2; // edi
            #   bool result; // al
            #
            #   v1 = (int)this;
            #   v2 = 0;
            #   if ( sub_8C4A30((_DWORD *)dword_E805A8, *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 356)) )
            #     v2 = 1;
            #   if ( (*(_BYTE *)(*(_DWORD *)(v1 + 8) + 160) >= 5u || v2)
            #     && *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 8)) + 15600) != dword_BE383C
            #     && *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 8)) + 15600) != dword_BE37A8
            #     && *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v1 + 4) + 4) + v1 + 8)) + 15600) != dword_BE37D0 )
            #   {
            #     result = sub_4C2410(v1, 0xEu, 1, 0, 1, 1) > 0;    # 0x004C2410
            #   }
            #   else
            #   {
            #     result = 1;
            #   }
            #   return result;
            # }
            if functionString.find("bool result;") != -1:
                if functionString.find(">= 5u ||") != -1:
                    if functionString.find("0xEu, 1, 0, 1, 1) > 0;") != -1:
                        if functionString.find("result = 1;") != -1:
                            if functionString.find("return result;") != -1:
                                matches = re.findall("result = sub_([0-9A-F]+)\([0-9a-z]+, 0xEu, 1, 0, 1, 1\) > 0;", functionString, re.MULTILINE)
                                if matches:
                                    functionList["EQ_Character__TotalSpellAffects"] = "0x00" + matches[0]

            # CharacterZoneClient__SetNoGrav
            # ----------------------------------------------------------------------------------------------------
            # void __thiscall sub_4B8960(_DWORD *this, int a2)    # 0x004B8960
            # {
            #   _DWORD *v2; // edi
            #   _BYTE *v3; // ecx
            #   unsigned int v4; // esi
            #   _DWORD *v5; // eax
            #   int v6; // eax
            #   _DWORD *v7; // eax
            #
            #   v2 = this;
            #   v3 = (_BYTE *)this[2];
            #   if ( v3 )
            #   {
            #     if ( v3[293]
            #       || (*(unsigned __int8 (**)(void))(*(_DWORD *)v3 + 224))()
            #       || !sub_8C4A80((_DWORD *)dword_E805A8, *(_DWORD *)((char *)v2 + *(_DWORD *)(v2[1] + 4) + 356)) && !byte_E8E5CC )
            #     {
            #       v4 = a2 != 0 ? 5 : 2;
            #     }
            #     else
            #     {
            #       v4 = 0;
            #     }
            #     if ( *(_DWORD *)((*(int (**)(void))(*(_DWORD *)v2[2] + 120))() + 12) == 1 )
            #       v4 = 1;
            #     v5 = (_DWORD *)(*(int (**)(void))(*(_DWORD *)v2[2] + 120))();
            #     sub_97DFA0(v5, v4);
            #     if ( sub_97D130((_DWORD *)v2[2]) )
            #     {
            #       v6 = sub_97D130((_DWORD *)v2[2]);
            #       v7 = (_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 120))(v6);
            #       sub_97DFA0(v7, v4);
            #     }
            #   }
            # }
            if functionString.find("!= 0 ? 5 : 2;") != -1:
                if functionString.find("= 0;") != -1:
                    if functionString.find("= 1;") != -1:
                        if functionString.find("== 1") != -1:
                            functionList["CharacterZoneClient__SetNoGrav"] = functionAddress

            # EQ_PC
            # ----------------------------------------------------------------------------------------------------
            # void *__thiscall sub_832810(_DWORD *this)
            # {
            #   _DWORD *v1; // esi
            #   void *result; // eax
            #   int *v3; // ecx
            #   char *v4; // eax
            #   LPVOID *v5; // eax
            #   LPVOID lpMem; // [esp+4h] [ebp-14h]
            #   void *v7; // [esp+8h] [ebp-10h]
            #   int v8; // [esp+14h] [ebp-4h]
            #
            #   v1 = this;
            #   result = (void *)this[6];
            #   if ( (signed int)result < 0 || (signed int)result >= 6 || !dword_E8D11C || byte_E9A7FC )    # 0x00E8D11C
            #   {
            #     v7 = 0;
            #     v8 = 2;
            #     sub_8EFE70(&v7, (int)"groupmember%d", (char)result);
            #     sub_832240((char *)v1, &v7, (volatile signed __int32 **)v1 + 5);
            #     result = v7;
            #     v8 = 3;
            #     if ( !v7 )
            #       return result;
            #     return (void *)sub_8EF7E0(result);
            #   }
            #   v3 = (int *)*((_DWORD *)dword_E8D11C + 2569);
            #   if ( v3 )
            #   {
            #     v4 = sub_608320(v3, (int)result, *((_DWORD *)dword_E8D11C + 2312));
            #     v5 = sub_8ED3B0(&lpMem, v4);
            #     v8 = 0;
            #     sub_832240((char *)v1, v5, (volatile signed __int32 **)v1 + 5);
            #     result = lpMem;
            #     v8 = 1;
            #     if ( lpMem )
            #       return (void *)sub_8EF7E0(result);
            #   }
            #   return result;
            # }
            if functionString.find("\"groupmember%d\"") != -1:
                if functionString.find(">= 6") != -1:
                    matches = re.findall("\|\| \!dword_([0-9A-F]+)", functionString, re.MULTILINE)
                    if matches:
                        functionList["EQ_PC"] = "0x00" + matches[0]

            # EQ_PC__DestroyHeldItemOrMoney
            # ----------------------------------------------------------------------------------------------------
            # _DWORD *__usercall sub_636A20@<eax>(unsigned int a1@<ecx>, double a2@<st0>)
            # {
            #   int v2; // edi
            #   _DWORD *v3; // eax
            #   int v4; // ecx
            #   int v5; // eax
            #   volatile signed __int32 *v6; // esi
            #   int v7; // ST10_4
            #   int v8; // eax
            #   char v9; // bl
            #   int v10; // eax
            #   _DWORD *result; // eax
            #   int v12; // eax
            #   int v13; // eax
            #   int v14; // ecx
            #   bool v15; // zf
            #   bool v16; // sf
            #   int v17; // eax
            #   signed int v18; // ebx
            #   int v19; // esi
            #   int v20; // eax
            #   int v21; // ecx
            #   int v22; // eax
            #   int v23; // eax
            #   int v24; // ecx
            #   int v25; // eax
            #   void *v26; // eax
            #   char v27; // bl
            #   int v28; // [esp+Ch] [ebp-54h]
            #   int v29; // [esp+10h] [ebp-50h]
            #   int v30; // [esp+14h] [ebp-4Ch]
            #   int v31; // [esp+18h] [ebp-48h]
            #   int v32; // [esp+1Ch] [ebp-44h]
            #   __int16 v33; // [esp+20h] [ebp-40h]
            #   int v34; // [esp+24h] [ebp-3Ch]
            #   int v35; // [esp+30h] [ebp-30h]
            #   int v36; // [esp+38h] [ebp-28h]
            #   int v37; // [esp+3Ch] [ebp-24h]
            #   int v38; // [esp+40h] [ebp-20h]
            #   int v39; // [esp+44h] [ebp-1Ch]
            #   int v40; // [esp+48h] [ebp-18h]
            #   int v41; // [esp+4Ch] [ebp-14h]
            #   bool v42; // [esp+53h] [ebp-Dh]
            #   int v43; // [esp+5Ch] [ebp-4h]
            #
            #   v2 = a1;
            #   v41 = a1;
            #   v3 = sub_4B4300((_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 4) + a1 + 8), &v40, 33);
            #   v4 = v40;
            #   v42 = *v3 != 0;
            #   if ( v40 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v40 + 4), 0xFFFFFFFF) && v4 )
            #     (*(void (__stdcall **)(signed int))(*(_DWORD *)v4 + 4))(1);
            #   if ( v42 )
            #   {
            #     v31 = -1;
            #     v32 = -1;
            #     v33 = -1;
            #     v5 = sub_8BE590((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 8) + 4) + v2 + 12));
            #     sub_8C7840((_BYTE *)(v5 + 20), (int)&v37, 0, 33, -1, -1);
            #     v28 = v37;
            #     v29 = v38;
            #     v30 = v39;
            #     v34 = 0;
            #     if ( !sub_987AE0(&unk_E9BC20, 0x2Eu) )
            #     {
            #       sub_4B4300((char *)dword_E8D11C + *(_DWORD *)(*((_DWORD *)dword_E8D11C + 2) + 4) + 8, &v40, 33);
            #       v6 = (volatile signed __int32 *)v40;
            #       v43 = 0;
            #       if ( v40 )
            #       {
            #         v7 = *(_DWORD *)(v40 + 144);
            #         v8 = sub_89B200((void *)v40);
            #         sub_636E60(v8, v7);
            #       }
            #       v43 = -1;
            #       if ( v6 && !_InterlockedDecrement(v6 + 1) )
            #         (*(void (__thiscall **)(volatile signed __int32 *, signed int))(*v6 + 4))(v6, 1);
            #     }
            #     if ( *(_DWORD *)dword_E8D1B4 )
            #     {
            #       word_E8D1B8 = sub_89F370(31419, 0);
            #       qmemcpy(&dword_E8D1BA, &v28, 0x1Cu);
            #       v9 = sub_83FC50(*(int *)dword_E8D1B4, 4, &word_E8D1B8, 0x1Eu);
            #       j_j_j___free_base(0);
            #       --dword_107B774;
            #       if ( !v9 )
            #         sub_4EBB90((_DWORD *)dword_CA6E74, (LPCRITICAL_SECTION **)dword_E8D1B4);
            #       v2 = v41;
            #     }
            #     else if ( !byte_E9A7FC )
            #     {
            #       sub_8F15B0("Attempt to send message %d on a void connection.", 31419);
            #     }
            #     *((_BYTE *)dword_E8D3BC + 16) = 0;
            #     v10 = sub_8BE590((_DWORD *)(v2 + *(_DWORD *)(*(_DWORD *)(v2 + 8) + 4) + 12));
            #     result = sub_4E2E90((unsigned int *)(v10 + 20), 0x21u);
            #     if ( dword_E8D11C )
            #       result = sub_62E9A0(v2, a2);
            #   }
            #   else
            #   {
            #     result = dword_E8D3BC;
            #     if ( *((_BYTE *)dword_E8D3BC + 17) )
            #     {
            #       v12 = *(_DWORD *)(v2 + 8);
            #       v36 = 0;
            #       v35 = 0;
            #       v13 = sub_8BE590((_DWORD *)(*(_DWORD *)(v12 + 4) + v2 + 12));
            #       v14 = v2 + 12;
            #       v15 = *(_DWORD *)(v13 + 14920) == 0;
            #       v16 = *(_DWORD *)(v13 + 14920) < 0;
            #       v17 = *(_DWORD *)(*(_DWORD *)(v2 + 8) + 4);
            #       if ( v16 || v15 )
            #       {
            #         v20 = sub_8BE590((_DWORD *)(v17 + v14));
            #         v21 = v2 + 12;
            #         v15 = *(_DWORD *)(v20 + 14924) == 0;
            #         v16 = *(_DWORD *)(v20 + 14924) < 0;
            #         v22 = *(_DWORD *)(*(_DWORD *)(v2 + 8) + 4);
            #         if ( v16 || v15 )
            #         {
            #           v23 = sub_8BE590((_DWORD *)(v22 + v21));
            #           v24 = v2 + 12;
            #           v15 = *(_DWORD *)(v23 + 14928) == 0;
            #           v16 = *(_DWORD *)(v23 + 14928) < 0;
            #           v25 = *(_DWORD *)(*(_DWORD *)(v2 + 8) + 4);
            #           if ( v16 || v15 )
            #           {
            #             result = (_DWORD *)sub_8BE590((_DWORD *)(v25 + v24));
            #             if ( result[3733] <= 0 )
            #               goto LABEL_38;
            #             v18 = 0;
            #             result = (_DWORD *)sub_8BE590((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 8) + 4) + v2 + 12));
            #             v41 = 4025;
            #             v19 = result[3733];
            #           }
            #           else
            #           {
            #             v18 = 1;
            #             result = (_DWORD *)sub_8BE590((_DWORD *)(v25 + v24));
            #             v41 = 4024;
            #             v19 = result[3732];
            #           }
            #         }
            #         else
            #         {
            #           v18 = 2;
            #           result = (_DWORD *)sub_8BE590((_DWORD *)(v22 + v21));
            #           v41 = 4023;
            #           v19 = result[3731];
            #         }
            #       }
            #       else
            #       {
            #         v18 = 3;
            #         result = (_DWORD *)sub_8BE590((_DWORD *)(v17 + v14));
            #         v41 = 4022;
            #         v19 = result[3730];
            #       }
            #       if ( v19 > 0 )
            #       {
            #         if ( !sub_987AE0(&unk_E9BC20, 0x2Eu) )
            #         {
            #           v26 = sub_8B7230((int *)dword_E8D3C8, v41, 0);
            #           sub_636E60((int)v26, v19);
            #         }
            #         if ( *(_DWORD *)dword_E8D1B4 )
            #         {
            #           word_E8D1B8 = sub_89F370(31809, 0);
            #           dword_E8D1BA = 0;
            #           LODWORD(qword_E8D1BE) = -1;
            #           HIDWORD(qword_E8D1BE) = v18;
            #           dword_E8D1C6 = v18;
            #           dword_E8D1CA = v19;
            #           v27 = sub_83FC50(*(int *)dword_E8D1B4, 4, &word_E8D1B8, 0x16u);
            #           j_j_j___free_base(0);
            #           --dword_107B774;
            #           if ( !v27 )
            #             sub_4EBB90((_DWORD *)dword_CA6E74, (LPCRITICAL_SECTION **)dword_E8D1B4);
            #         }
            #         else if ( !byte_E9A7FC )
            #         {
            #           sub_8F15B0("Attempt to send message %d on a void connection.", 31809);
            #         }
            #         *((_BYTE *)dword_E8D3BC + 17) = 0;
            #         *(_DWORD *)(sub_8BE590((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 8) + 4) + v2 + 12)) + 14920) = 0;
            #         *(_DWORD *)(sub_8BE590((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 8) + 4) + v2 + 12)) + 14924) = 0;
            #         *(_DWORD *)(sub_8BE590((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 8) + 4) + v2 + 12)) + 14928) = 0;
            #         result = (_DWORD *)sub_8BE590((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 8) + 4) + v2 + 12));
            #         result[3733] = 0;
            #       }
            #     }
            #   }
            # LABEL_38:
            #   *(_BYTE *)(v2 + 9252) = 1;
            #   return result;
            # }
            if functionString.find(", 0, 33, -1, -1);") != -1:
                if functionString.find("= 4022;") != -1:
                    if functionString.find("= 4023;") != -1:
                        if functionString.find("= 4024;") != -1:
                            if functionString.find("= 4025;") != -1:
                                if functionString.find("= 0;") != -1:
                                    if functionString.find("= 1;") != -1:
                                        if functionString.find("= 2;") != -1:
                                            if functionString.find("= 3;") != -1:
                                                functionList["EQ_PC__DestroyHeldItemOrMoney"] = functionAddress

            # EQPlayerManager
            # EQPlayerManager__GetSpawnByID
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
            # sub_8EEBD0((int)&v18, 64, (int)"%s`s_Mount00", (int)(v10 + 164));
            # v11 = (char *)sub_64F6B0((_DWORD **)dword_F2EED8, (int)&v18);    # 0x0064F6B0
            if functionString.find("\"%s`s_Mount00\"") != -1:
                matches = re.findall("[0-9a-z]+ = \(char \*\)sub_([0-9A-F]+)\(\(_DWORD \*\*\)dword_[0-9A-F]+, \(int\)&[0-9a-z]+\);", functionString, re.MULTILINE)
                if matches:
                    functionList["EQPlayerManager__GetSpawnByName"] = "0x00" + matches[0]

            # EQPlayer__ChangeHeight
            # ----------------------------------------------------------------------------------------------------
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

            # EQPlayer__ChangePosition
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("0x30D1u") != -1:    # 12497 Your attempt to apply poison has been cancelled.
                if functionString.find("== 100") != -1:
                    if functionString.find("== 110") != -1:
                        if functionString.find("== 111") != -1:
                            if functionString.find("case 0x64u:") != -1:
                                if functionString.find("case 0x69u:") != -1:
                                    if functionString.find("case 0x6Eu:") != -1:
                                        if functionString.find("case 0x6Fu:") != -1:
                                            if functionString.find("case 0x73u:") != -1:
                                                functionList["EQPlayer__ChangePosition"] = functionAddress

            # EQPlayer__GetLevel
            # ----------------------------------------------------------------------------------------------------
            # if ( !(unsigned __int8)sub_642DC0(v7) && !v7[110] )
            # {
            #   v135 = sub_659850(v7);    # 0x00659850
            #   sub_4A4110(&v178, (int)" (Lvl: %d)", v135);
            # }
            if functionString.find("\" (Lvl: %d)\"") != -1:
                    matches = re.findall("sub_([0-9A-F]+)\([0-9a-z]+\);\n\s+sub_[0-9A-F]+\(&[0-9a-z]+, \(int\)\" \(Lvl: %d\)\", [0-9a-z]+\);", functionString, re.MULTILINE)
                    if matches:
                        functionList["EQPlayer__GetLevel"] = "0x00" + matches[0]

            # EQPlayer__GetActorClient
            # ----------------------------------------------------------------------------------------------------
            # for ( l = sub_650330((_DWORD *)dword_F30EE8); l; l = sub_592CC0((_DWORD *)l) )
            # {
            #   a12 = 0.0;
            #   sub_658030((float *)l, 0.0, 1.0);
            #   v105 = (_DWORD *)sub_5928C0((char *)l);    # 0x005928C0
            #   if ( sub_592AB0(v105) )
            #   {
            #     *(_DWORD *)&v309[8] = 1;
            #     *(_DWORD *)&v309[4] = v106;
            #     a12 = *(float *)(l + 472);
            #     *(float *)&v309[4] = *(float *)(l + 472);
            #     v107 = sub_5928C0((char *)l);    # 0x005928C0
            #     sub_488260((int)v107, *(float *)&v309[4], 1);
            #   }
            # }
            if functionString.find("\"*** DISCONNECTING: %s\\n\"") != -1:
                matches = re.findall("[0-9a-z]+ = 0.0;\n\s+sub_[0-9A-F]+\(\(float \*\)\w+, 0.0, 1.0\);\n\s+[0-9a-z]+ = \(_DWORD \*\)sub_([0-9A-F]+)\(\(char \*\)\w+\);\n\s+if \( sub_[0-9A-F]+\([0-9a-z]+\) \)", functionString, re.MULTILINE)
                if matches:
                    functionList["EQPlayer__GetActorClient"] = "0x00" + matches[0]

            # EQPlayer__FollowPlayerAI
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("0x3194u") != -1:    # 12692 %1 is dead, canceling auto-follow.
                if functionString.find("0x3195u") != -1:    # 12693 %1 is too far away, canceling auto-follow.
                    if functionString.find("> 200.0") != -1:
                        if functionString.find(">= 20.0") != -1:
                            if functionString.find("+ 15.0 <=") != -1:
                                if functionString.find("+ 30.0 <=") != -1:
                                    functionList["EQPlayer__FollowPlayerAI"] = functionAddress

            # EQPlayer__TurnOffAutoFollow
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("0x3196u") != -1:    # 12694 You are no longer auto-following %1.
                if functionString.find("= 0.0;") != -1:    # 12693 %1 is too far away, canceling auto-follow.
                    if functionString.find("= 0;") != -1:
                        functionList["EQPlayer__TurnOffAutoFollow"] = functionAddress

            # EQPlayer__UpdateItemSlot
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("IT36") != -1:
                if functionString.find("IT159") != -1:
                    if functionString.find("IT10758") != -1:
                        if functionString.find("IT10742") != -1:
                            functionList["EQPlayer__UpdateItemSlot"] = functionAddress

            # EQPlayer__IsTargetable
            # ----------------------------------------------------------------------------------------------------
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

            # EQPlayer__SetNameSpriteState
            # ----------------------------------------------------------------------------------------------------
            # (*(void (__stdcall **)(_DWORD, char *, char *))(*(_DWORD *)v177 + 400))(0, v185, &v190);
            # 400 = CActorInterface->ChangeBoneStringSprite() virtual function
            if functionString.find("\"!\"") != -1:
                if functionString.find("\"%s [%d %s]\\n%s\"") != -1:
                    if functionString.find("\" - %d%%\"") != -1:
                        if functionString.find("\" - %lld%%\"") != -1:
                            if functionString.find("\"%d - \"") != -1:
                                if functionString.find("0x301Au") != -1:    # 12314  LFG
                                    if functionString.find("0x3017") != -1:    # 12311  AFK 
                                        if functionString.find("0x8C0u") != -1:    # 2240  LD
                                            if functionString.find("0x2FEu") != -1:    # 766 Offline
                                                if functionString.find("0x157Fu") != -1:    # 5503 Trader
                                                    if functionString.find("0x17A7u") != -1:    # 6055 Buyer
                                                        functionList["EQPlayer__SetNameSpriteState"] = functionAddress

            # EQPlayer__SetNameSpriteTint
            # ----------------------------------------------------------------------------------------------------
            # (*(void (__cdecl **)(unsigned __int8 *))(**((_DWORD **)v3 + 1090) + 404))(&v18);
            # 404 = CActorInterface->SetNameColor() virtual function
            # 404 = EQData::_SPAWNINFO::mActorClient->pcactorex->SetNameColor()
            if functionString.find("= -7755;") != -1:
                if functionString.find("= 6072;") != -1:
                    if functionString.find("= -4259;") != -1:
                        if functionString.find("= -23020;") != -1:
                            if functionString.find("= 16639;") != -1:
                                if functionString.find("= -31416;") != -1:
                                    if functionString.find("= 15723;") != -1:
                                        if functionString.find("= -31416;") != -1:
                                            if functionString.find("= 7590;") != -1:
                                                if functionString.find("= 26367;") != -1:
                                                    if functionString.find("* 0.2 * 1000.0);") != -1:
                                                        functionList["EQPlayer__SetNameSpriteTint"] = functionAddress

            # EQPlayer__ChangeLight
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("* 6.2800002 * 0.001953125;") != -1:
                if functionString.find("* 2.0;") != -1:
                    if functionString.find("== 5") != -1:
                        if functionString.find("== 6") != -1:
                            if functionString.find("== 7") != -1:
                                if functionString.find("== 8") != -1:
                                    if functionString.find("== 9") != -1:
                                        if functionString.find("== 10") != -1:
                                            functionList["EQPlayer__ChangeLight"] = functionAddress

            # EQPlayer__push_along_heading
            # ----------------------------------------------------------------------------------------------------
            # int __thiscall sub_5C61F0(float *this, float a2)    # 0x005C61F0
            # {
            #   float *v2; // esi
            #   double v3; // st7
            #   double v4; // st7
            #   int result; // eax
            #
            #   v2 = this;
            #   v3 = this[32];
            #   (*(void (__stdcall **)(float))(*(_DWORD *)dword_16CB880 + 12))(this[32]);
            #   v2[28] = v3 * a2 + v2[28];
            #   v4 = v2[32];
            #   result = (*(int (__stdcall **)(float))(*(_DWORD *)dword_16CB880 + 8))(v2[32]);
            #   v2[29] = v4 * a2 + v2[29];
            #   return result;
            # }
            # ////////////////////////////////////////////////////////////////////////////////////////////////////
            # int __thiscall sub_64A920(float *this, char a2)    # EQPlayer__DoSwimJump
            # {
            #   float *v2; // esi
            #   int result; // eax
            #
            #   v2 = this;
            #   result = sub_65AD60(this);
            #   if ( (_BYTE)result )
            #   {
            #     result = *((_DWORD *)dword_E81B64 + 85) + 1500;
            #     *((_DWORD *)v2 + 151) = result;
            #     if ( a2 )
            #     {
            #       result = sub_5C58E0(v2);
            #       if ( result )
            #       {
            #         v2[30] = v2[5] * 3.0 + v2[30];
            #         result = sub_5C61F0(v2, 1.0);    # 0x005C61F0
            #       }
            #     }
            #   }
            #   return result;
            # }
            if functionString.find("int result;") != -1:
                if functionString.find("if ( result )") != -1:
                    if functionString.find("result = sub_") != -1:
                        if functionString.find("return result;") != -1:
                            matches = re.findall("if \( result \)\n\s+{\n\s+[0-9a-z]+\[\d+\] = [0-9a-z]+\[\d+\] \* 3.0 \+ [0-9a-z]+\[\d+\];\n\s+result = sub_([0-9A-F]+)\([0-9a-z]+, 1.0\);", functionString, re.MULTILINE)
                            if matches:
                                functionList["EQPlayer__push_along_heading"] = "0x00" + matches[0]

            # EQSwitchManager
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("!= 57") != -1:
                if functionString.find("!= 58") != -1:
                    if functionString.find("!= -97") != -1:
                        if functionString.find("!= -96") != -1:
                            if functionString.find("!= -95") != -1:
                                if functionString.find("== 2") != -1:
                                    if functionString.find("== 3") != -1:
                                        functionList["EQSwitch__ChangeState"] = functionAddress

            # EQSpell__SpellAffects
            # ----------------------------------------------------------------------------------------------------
            # void __userpurge sub_4B7FA0(_DWORD *a1@<ecx>, double a2@<st0>, int a3)
            # {
            #   int v3; // edi
            #   int v4; // eax
            #   unsigned int v5; // ebp
            #   int v6; // eax
            #   int v7; // ebx
            #   int v8; // esi
            #   _DWORD *v9; // esi
            #   unsigned __int8 v10; // al
            #   int v11; // eax
            #   unsigned __int8 v12; // al
            #   int v13; // eax
            #   char v14; // al
            #   signed int v15; // eax
            #   char v16; // al
            #   signed int v17; // eax
            #   unsigned __int8 v18; // al
            #   int v19; // eax
            #   char v20; // al
            #   signed int v21; // eax
            #   int v22; // eax
            #   _DWORD *v23; // ecx
            #   int v24; // [esp+10h] [ebp-4h]
            #
            #   v3 = (int)a1;
            #   v4 = a1[2];
            #   if ( v4 && !*(_BYTE *)(v4 + 293) && !byte_E8DF9C )
            #   {
            #     sub_4B8310(a1, 0);
            #     v5 = 0;
            #     if ( sub_4B7F60((_DWORD *)v3) )
            #     {
            #       while ( 1 )
            #       {
            #         v6 = sub_4B7DD0((_DWORD *)v3, v5);
            #         v7 = v6;
            #         if ( !*(_BYTE *)v6 )
            #           goto LABEL_45;
            #         v8 = *(_DWORD *)(v6 + 8);
            #         v24 = *(_DWORD *)(v6 + 8);
            #         if ( !sub_564550(v8) )
            #           goto LABEL_45;
            #         v9 = (_DWORD *)(*(int (__stdcall **)(int))(*(_DWORD *)dword_F31660 + 32))(v8);
            #         if ( !v9 )
            #           goto LABEL_45;
            #         if ( !a3 )
            #           goto LABEL_30;
            #         if ( a3 != 2 )
            #           break;
            #         if ( !sub_5668E0(v9, 67)
            #           && !sub_5668E0(v9, 31)
            #           && !sub_5668E0(v9, 58)
            #           && !sub_5668E0(v9, 73)
            #           && !sub_5668E0(v9, 64)
            #           && !sub_5668E0(v9, 156) )
            #         {
            #           goto LABEL_30;
            #         }
            #         if ( !sub_565DA0(v9) )
            #           goto LABEL_19;
            #         v10 = sub_5668E0(v9, 58);
            #         v11 = sub_4B3E10(v9, v10 - 1);
            #         sub_4B87B0(v3, a2, (int)v9, v24, *(_DWORD *)(v11 + 4), v7, 0);
            # LABEL_45:
            #         if ( (signed int)++v5 >= (unsigned __int8)sub_4B7F60((_DWORD *)v3) )
            #           goto LABEL_46;
            #       }
            #       if ( *(_DWORD *)(v7 + 12) != -4 )
            #       {
            #         if ( !sub_5668E0(v9, 67)
            #           && !sub_5668E0(v9, 31)
            #           && !sub_5668E0(v9, 58)
            #           && !sub_5668E0(v9, 22)
            #           && !sub_5668E0(v9, 23)
            #           && !sub_5668E0(v9, 73)
            #           && !sub_5668E0(v9, 64)
            #           && !sub_5668E0(v9, 156) )
            #         {
            #           goto LABEL_30;
            #         }
            #         if ( sub_565DA0(v9) )
            #         {
            #           v12 = sub_5668E0(v9, 58);
            #           v13 = sub_4B3E10(v9, v12 - 1);
            #           sub_4B87B0(v3, a2, (int)v9, v24, *(_DWORD *)(v13 + 4), v7, 0);
            # LABEL_30:
            #           v14 = sub_5668E0(v9, 3);
            #           if ( v14 )
            #           {
            #             v15 = sub_4C14B0((_DWORD *)v3, (int)v9, *(_BYTE *)(v7 + 1), v14 - 1, 0, v5, 0, 0, -1, 1);
            #             sub_4B8310((_DWORD *)v3, v15);
            #           }
            #           v16 = sub_5668E0(v9, 99);
            #           if ( v16 )
            #           {
            #             v17 = sub_4C14B0((_DWORD *)v3, (int)v9, *(_BYTE *)(v7 + 1), v16 - 1, 0, v5, 0, 0, -1, 1);
            #             sub_4B8310((_DWORD *)v3, v17);
            #           }
            #           if ( sub_5668E0(v9, 34) || sub_5668E0(v9, 20) )
            #             *(_BYTE *)(*(_DWORD *)(v3 + 8) + 397) = 1;
            #           v18 = sub_5668E0(v9, 57);
            #           if ( v18 )
            #           {
            #             v19 = sub_4B3E10(v9, v18 - 1);
            #             sub_4B8960((_DWORD *)v3, *(_DWORD *)(v19 + 8));
            #           }
            #           v20 = sub_5668E0(v9, 87);
            #           if ( v20 )
            #           {
            #             v21 = sub_4C14B0((_DWORD *)v3, (int)v9, *(_BYTE *)(v7 + 1), v20 - 1, 0, v5, 0, 0, -1, 1);
            #             sub_539230((float *)dword_E806A0, v21);
            #           }
            #           if ( sub_5668E0(v9, 65) )
            #             *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 4) + 4) + v3 + 8)) + 15304) = 0;
            #           if ( sub_5668E0(v9, 66) )
            #             *(_DWORD *)(sub_8BC690((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 4) + 4) + v3 + 8)) + 15332) = 0;
            #           goto LABEL_45;
            #         }
            #       }
            # LABEL_19:
            #       a2 = sub_4BCBF0(v7, 0, 0);
            #       goto LABEL_45;
            #     }
            # LABEL_46:
            #     v22 = sub_4C2410(v3, 0x63u, 1, 0, 1, 1);
            #     v23 = (_DWORD *)v3;
            #     if ( v22 >= 0 )
            #     {
            #       v22 = sub_4C2410(v3, 3u, 1, 0, 1, 1);
            #       v23 = (_DWORD *)v3;
            #     }
            #     sub_4B8310(v23, v22);
            #     *(_BYTE *)(v3 + 12) = 1;
            #   }
            # }
            if functionString.find(", 67)") != -1:
                if functionString.find(", 31)") != -1:
                    if functionString.find(", 58)") != -1:
                        if functionString.find(", 22)") != -1:
                            if functionString.find(", 23)") != -1:
                                if functionString.find(", 73)") != -1:
                                    if functionString.find(", 64)") != -1:
                                        if functionString.find(", 156)") != -1:
                                            if functionString.find(", 3)") != -1:
                                                if functionString.find(", 99)") != -1:
                                                    if functionString.find(", 34)") != -1:
                                                        if functionString.find(", 20)") != -1:
                                                            if functionString.find(", 57)") != -1:
                                                                if functionString.find(", 87)") != -1:
                                                                    if functionString.find(", 65)") != -1:
                                                                        if functionString.find(", 66)") != -1:
                                                                            if functionString.find("0x63u, 1, 0, 1, 1);") != -1:
                                                                                if functionString.find("3u, 1, 0, 1, 1);") != -1:
                                                                                    if functionString.find("0, 0, -1, 1);") != -1:
                                                                                        if functionString.find("!= -4") != -1:
                                                                                            if functionString.find("while ( 1 )") != -1:
                                                                                                functionList["EQSpell__SpellAffects"] = functionAddress

            # CXWndManager
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("\"DoAllDrawing() failed\\n\"") != -1:
                if functionString.find("-939523968") != -1:
                    if functionString.find("GetTickCount();") != -1:
                        functionList["CXWndManager__DrawWindows"] = functionAddress

            # CXWnd__IsReallyVisible
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
            # sub_8EEB00("Gamestate at crash = %d\n", *(_DWORD *)(dword_103C944 + 1480));    # 0x0103C944
            if functionString.find("\"Gamestate at crash = %d\\n\"") != -1:
                matches = re.findall("sub_[0-9A-F]+\(\"Gamestate at crash = %d.n\", \*\(_DWORD \*\)\(dword_([0-9A-F]+) \+ \d+\)\);", functionString, re.MULTILINE)
                if matches:
                    functionList["CEverQuest"] = "0x0" + matches[0]

            # CEverQuest__DoPercentConvert
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("0x21Au") != -1:    # 538 You may not use that command while dead.
                if functionString.find("0x305Cu") != -1:    # 12380 That is not a valid command.  Please use /help.
                    if functionString.find("\"%s %s\"") != -1:
                        if functionString.find("\"#%s %s\"") != -1:
                            functionList["CEverQuest__InterpretCmd"] = functionAddress

            # CEverQuest__dsp_chat
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("while ( ShowCursor(1) < 0 )") != -1:
                if functionString.find("SetCursorPos") != -1:
                    if functionString.find("\"POINT1\"") != -1:
                        if functionString.find("\"POINT2\"") != -1:
                            if functionString.find("\"POINT3\"") != -1:
                                if functionString.find("\"POINT4\"") != -1:
                                    if functionString.find("0x3020u") != -1: # 12320 You currently cannot drop items.  Goto General Options or use /fastdrop to enable dropping.
                                        functionList["CEverQuest__LMouseUp"] = functionAddress

            # CEverQuest__RMouseUp
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("fabs") != -1:
                if functionString.find(" = 53.0;") != -1:
                    if functionString.find(" = 212.0;") != -1:
                        if functionString.find(" = 100.0;") != -1:
                            if functionString.find(" * 0.2 * 90.0 + 10.0;") != -1:
                                functionList["CEverQuest__HandleMouseWheel"] = functionAddress

            # CEverQuest__StartCasting
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("8152") != -1:    # 8152 %1 begins singing %2.
                if functionString.find("12205") != -1:    # 12205 You begin casting %1.
                    if functionString.find("12206") != -1:    # 12206 %1 begins casting %2.
                        if functionString.find(", 0, 500);") != -1:
                            if functionString.find(", 99);") != -1:
                                functionList["CEverQuest__StartCasting"] = functionAddress

            # CEverQuest__SendNewText
            # ----------------------------------------------------------------------------------------------------
            # void __cdecl sub_59D4C0(int a1, const char *a2)    # do_say(EQPlayer *, char *)
            # {
            #   int v2; // eax
            #   double v3; // st7
            #   LPVOID v4; // esi
            #   double v5; // st6
            #   int v6; // eax
            #   double v7; // st5
            #   double v8; // st7
            #   char *v9; // edx
            #   char *v10; // esi
            #   char v11; // al
            #   void *v12; // [esp+8h] [ebp-187Ch]
            #   float v13; // [esp+Ch] [ebp-1878h]
            #   float v14; // [esp+10h] [ebp-1874h]
            #   float v15; // [esp+14h] [ebp-1870h]
            #   float v16; // [esp+1Ch] [ebp-1868h]
            #   char v17; // [esp+20h] [ebp-1864h]
            #   char v18; // [esp+24h] [ebp-1860h]
            #   char v19[4096]; // [esp+884h] [ebp-1000h]
            #
            #   strcpy((char *)(dword_103DA3C + 95780), a2);
            #   if ( dword_E7F444 && *((_BYTE *)dword_E7F444 + 293) == 1 )
            #   {
            #     v2 = *(_DWORD *)dword_E7F444;
            #     v16 = *((float *)dword_E7F444 + 27);
            #     if ( *(_DWORD *)(*(int (__stdcall **)(char *))(v2 + 136))(&v17) != dword_BFB8A4
            #       && *(_DWORD *)(*(int (__stdcall **)(char *))(*(_DWORD *)dword_E7F444 + 136))(&v17) != dword_BFB8A8
            #       && *(_DWORD *)(*(int (__stdcall **)(char *))(*(_DWORD *)dword_E7F444 + 136))(&v17) != dword_BFB898 )
            #     {
            #       v3 = v16;
            #     }
            #     else
            #     {
            #       v3 = v16 + 1.0;
            #     }
            #     v4 = dword_E7F3F0;
            #     v5 = *((float *)dword_E7F444 + 26);
            #     if ( dword_E7F3F0
            #       && (v6 = *(_DWORD *)dword_E7F3F0,
            #           v7 = v3,
            #           v8 = *((float *)dword_E7F444 + 25),
            #           v15 = v7,
            #           v14 = v5,
            #           v13 = v8,
            #           (*(void (__thiscall **)(LPVOID, void **))(v6 + 136))(dword_E7F3F0, &v12),
            #           sub_59ADF0((int)v4, (int)v4 + 100, (int)v12, v13, v14, v15)) )
            #     {
            #       sub_5DDCB0((LPVOID)8, (char *)dword_E7F444 + 164, (char *)(dword_103DA3C + 95780), 0);    # 0x005DDCB0
            #       if ( !sub_4C2500((int)dword_E7F920 + 9240, 0x4Bu, 1, 0, 1, 1) )
            #       {
            #         v9 = (char *)(dword_103DA3C + 95780);
            #         v10 = &v19[-dword_103DA3C - 95780];
            #         do
            #         {
            #           v11 = *v9++;
            #           v9[(_DWORD)v10 - 1] = v11;
            #         }
            #         while ( v11 );
            #         sub_5E8770(v19, 1);
            #         sub_598B20((int)&v18, 0x331Eu, (int)v19, 0, 0, 0, 0, 0, 0, 0, 0);
            #         v15 = 0.0;
            #         LODWORD(v14) = 1;
            #         LODWORD(v13) = 1;
            #         v12 = (void *)307;
            #         sub_4E5850();
            #         sub_4E5EF0(&v18, v12, (LPVOID)LODWORD(v13), (LPVOID)LODWORD(v14), (LPVOID)LODWORD(v15));
            #       }
            #     }
            #     else
            #     {
            #       sub_5D1650((char *)dword_103DA3C, 0);
            #     }
            #   }
            #   else
            #   {
            #     sub_5D1650((char *)dword_103DA3C, 0);
            #   }
            # }
            if functionString.find("0x4Bu, 1, 0, 1, 1)") != -1:    # TotalSpellAffects() with 75 = Ventriloquism
                if functionString.find("0x331Eu") != -1:    # 13086 You say, '%1'
                    if functionString.find("307;") != -1:    # CEverQuest__dsp_chat() with 307 text color
                        if functionString.find("strcpy") != -1:
                            matches = re.findall("sub_([0-9A-F]+)\(\(LPVOID\)8,", functionString, re.MULTILINE)
                            if matches:
                                functionList["CEverQuest__SendNewText"] = "0x00" + matches[0]

            # CEverQuest__DropHeldItemOnGround
            # ----------------------------------------------------------------------------------------------------
            # _DWORD *__stdcall sub_5D0B10(int a1)
            # {
            #   _DWORD *result; // eax
            #   int v2; // ecx
            #   bool v3; // zf
            #   void (__thiscall ***v4)(LPVOID, _DWORD, signed int, signed int, int); // edi
            #   void *v5; // ecx
            #   void (__thiscall **v6)(LPVOID, _DWORD, signed int, signed int, int); // esi
            #   int v7; // eax
            #   int v8; // ecx
            #   int v9; // eax
            #   char v10; // bl
            #   int v11; // [esp+4h] [ebp-14h]
            #   bool v12; // [esp+Bh] [ebp-Dh]
            #   int v13; // [esp+14h] [ebp-4h]
            #
            #   result = sub_4B4300((char *)dword_E8D11C + *(_DWORD *)(*((_DWORD *)dword_E8D11C + 2) + 4) + 8, &v11, 33);
            #   v2 = v11;
            #   v12 = *result == 0;
            #   if ( v11 )
            #   {
            #     result = (_DWORD *)_InterlockedExchangeAdd((volatile signed __int32 *)(v11 + 4), 0xFFFFFFFF);
            #     if ( !result )
            #     {
            #       if ( v2 )
            #         result = (_DWORD *)(*(int (__stdcall **)(signed int))(*(_DWORD *)v2 + 4))(1);
            #     }
            #   }
            #   if ( !v12 )
            #   {
            #     v3 = a1 == 0;
            #     *((_BYTE *)dword_E8D3BC + 16) = 0;
            #     if ( !v3 )
            #     {
            #       v4 = (void (__thiscall ***)(LPVOID, _DWORD, signed int, signed int, int))sub_4E5F10();
            #       v5 = (void *)*sub_4B4300((char *)dword_E8D11C + *(_DWORD *)(*((_DWORD *)dword_E8D11C + 2) + 4) + 8, &a1, 33);
            #       v6 = *v4;
            #       v13 = 0;
            #       v7 = sub_89B200(v5);
            #       (*v6)(v4, 0, 9058, 15, v7);
            #       v8 = a1;
            #       v13 = -1;
            #       if ( a1 )
            #       {
            #         if ( !_InterlockedDecrement((volatile signed __int32 *)(a1 + 4)) && v8 )
            #           (*(void (__stdcall **)(signed int))(*(_DWORD *)v8 + 4))(1);
            #       }
            #     }
            #     v9 = sub_8BE590((char *)dword_E8D11C + *(_DWORD *)(*((_DWORD *)dword_E8D11C + 2) + 4) + 12);
            #     sub_4E2E90((unsigned int *)(v9 + 20), 0x21u);
            #     if ( !byte_E9A7FC && !dword_E9A940 )
            #     {
            #       if ( *(_DWORD *)dword_E8D1B4 )
            #       {
            #         word_E8D1B8 = sub_89F370(21544, 0);
            #         v10 = sub_83FC50(*(int *)dword_E8D1B4, 4, &word_E8D1B8, 2u);
            #         j_j_j___free_base(0);
            #         --dword_107B774;
            #         if ( !v10 )
            #           sub_4EBB90((_DWORD *)dword_CA6E74, (LPCRITICAL_SECTION **)dword_E8D1B4);
            #       }
            #       else
            #       {
            #         sub_8F15B0("Attempt to send message %d on a void connection.", 21544);
            #       }
            #     }
            #     result = dword_E8D11C;
            #     *((_BYTE *)dword_E8D11C + 9252) = 1;
            #   }
            #   return result;
            # }
            if functionString.find("0, 9058, 15,") != -1:
                if functionString.find(", 33);") != -1:
                    if functionString.find("= *result == 0;") != -1:
                        if functionString.find(", 0xFFFFFFFF);") != -1:
                            if functionString.find("result = dword_") != -1:
                                if functionString.find("return result;") != -1:
                                    functionList["CEverQuest__DropHeldItemOnGround"] = functionAddress

            # CDisplay
            # ----------------------------------------------------------------------------------------------------
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
            # ----------------------------------------------------------------------------------------------------
            # int __cdecl sub_5350B0(void *a1, int a2, int a3, LPVOID lpMem)    # 0x005350B0
            # {
            #   signed int v4; // edx
            #   void *v5; // esi
            #   bool v6; // zf
            #   bool v7; // sf
            #   unsigned __int8 v8; // of
            #   int v9; // eax
            #   int v11; // [esp+4h] [ebp-1Ch]
            #   int v12; // [esp+8h] [ebp-18h]
            #   int v13; // [esp+Ch] [ebp-14h]
            #   int v14; // [esp+10h] [ebp-10h]
            #   int v15; // [esp+1Ch] [ebp-4h]
            #
            #   if ( (signed int)lpMem <= 255 )
            #   {
            #     switch ( (unsigned int)lpMem )
            #     {
            #       case 0u:
            #       case 0x14u:
            #         v5 = (void *)-16777216;
            #         break;
            #       case 2u:
            #         v5 = (void *)-16744448;
            #         break;
            #       case 4u:
            #         v5 = (void *)-16777088;
            #         break;
            #       case 5u:
            #         v5 = (void *)-1048336;
            #         break;
            #       case 6u:
            #         v5 = (void *)-8355712;
            #         break;
            #       case 7u:
            #         v5 = (void *)-2039584;
            #         break;
            #       case 0xAu:
            #         v5 = (void *)-986896;
            #         break;
            #       case 0xCu:
            #         v5 = (void *)-6250336;
            #         break;
            #       case 0xDu:
            #         v5 = (void *)-1048576;
            #         break;
            #       case 0xEu:
            #         v5 = (void *)-16715776;
            #         break;
            #       case 0xFu:
            #         v5 = (void *)-987136;
            #         break;
            #       case 0x10u:
            #         v5 = (void *)-16776976;
            #         break;
            #       case 0x11u:
            #         v5 = (void *)-16777041;
            #         break;
            #       case 0x12u:
            #         v5 = (void *)-16715536;
            #         break;
            #       case 0x15u:
            #         v5 = &unk_F0A000;
            #         break;
            #       case 0x16u:
            #         v5 = &loc_806020;
            #         break;
            #       default:
            #         v5 = (void *)-10461088;
            #         break;
            #     }
            #   }
            #   else
            #   {
            #     v4 = (signed int)lpMem - 256;
            #     if ( (_DWORD)((_DWORD)lpMem - 256) > 125 || v4 < 0 )
            #       v4 = 0;
            #     byte_DCC5C9[4 * v4];
            #     v5 = (void *)(((unsigned __int8)byte_DCC5C8[4 * v4] | (((unsigned __int8)byte_DCC5C9[4 * v4] | ((unsigned __int8)byte_DCC5CA[4 * v4] << 8)) << 8)) & 0xFF00 | (((unsigned __int8)byte_DCC5C8[4 * v4] | 0xFFFFFF00) << 16) | (unsigned __int8)(((unsigned __int8)byte_DCC5C8[4 * v4] | (((unsigned __int8)byte_DCC5C9[4 * v4] | ((unsigned int)(unsigned __int8)byte_DCC5CA[4 * v4] << 8)) << 8)) >> 16));
            #   }
            #   if ( dword_16C9938 )
            #   {
            #     v14 = 0;
            #     v13 = 0;
            #     v12 = a3;
            #     v11 = a2;
            #     v14 = *(_DWORD *)(dword_16C9938 + 280);
            #     v13 = *(_DWORD *)(dword_16C9938 + 276);
            #     sub_8EB050(&lpMem, a1);
            #     v8 = __OFSUB__(*(_DWORD *)(dword_16C9938 + 284), 2);
            #     v6 = *(_DWORD *)(dword_16C9938 + 284) == 2;
            #     v7 = *(_DWORD *)(dword_16C9938 + 284) - 2 < 0;
            #     v15 = 0;
            #     if ( (unsigned __int8)(v7 ^ v8) | v6 || (v9 = *(_DWORD *)(dword_16C9938 + 288)) == 0 )
            #       sub_477830((void *)(dword_16C9938 + 284));
            #     sub_9116C0(*(_DWORD **)(v9 + 8), &lpMem, a2, a3, *(_DWORD *)(dword_16C9938 + 276) - a2, (int)&v11, (int)v5, 1, 0);
            #     v15 = 1;
            #     if ( lpMem )
            #       sub_8ED480(lpMem);
            #   }
            #   return 1;
            # }
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
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("\"PLAYER_1\"") != -1:
                if functionString.find("\"BBBOARD\"") != -1:
                    if functionString.find("\"IT\"") != -1:
                        functionList["CDisplay__CreateActor"] = functionAddress

            # CDisplay__CreatePlayerActor
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("\"CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. actor_tag=%s\\n\"") != -1:
                if functionString.find("\"OBP_SPELLTREE_ACTORDEF\"") != -1:
                    if functionString.find("\"HUM_ACTORDEF\"") != -1:
                        if functionString.find("\"HUF_ACTORDEF\"") != -1:
                            functionList["CDisplay__CreatePlayerActor"] = functionAddress

            # CDisplay__DeleteActor
            # ----------------------------------------------------------------------------------------------------
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

            # CDisplay__GetIntensity
            # ----------------------------------------------------------------------------------------------------
            # char __stdcall sub_535020(char a1)    # 0x00535020
            # {
            #   char result; // al
            #
            #   switch ( a1 )
            #   {
            #     case 1:
            #       result = 1;
            #       break;
            #     case 2:
            #       result = 2;
            #       break;
            #     case 3:
            #     case 9:
            #       result = 3;
            #       break;
            #     case 4:
            #       result = 6;
            #       break;
            #     case 5:
            #     case 0xA:
            #       result = 7;
            #       break;
            #     case 6:
            #       result = 8;
            #       break;
            #     case 7:
            #     case 0xB:
            #       result = 9;
            #       break;
            #     case 8:
            #       result = 10;
            #       break;
            #     case 0xC:
            #     case 0xE:
            #       result = 4;
            #       break;
            #     case 0xD:
            #     case 0xF:
            #       result = 5;
            #       break;
            #     default:
            #       result = 0;
            #       break;
            #   }
            #   return result;
            # }
            if functionString.find("char result;") != -1:
                if functionString.find("switch ( a1 )") != -1:
                    if functionString.find("case 1:") != -1:
                        if functionString.find("case 2:") != -1:
                            if functionString.find("case 3:") != -1:
                                if functionString.find("case 4:") != -1:
                                    if functionString.find("case 5:") != -1:
                                        if functionString.find("case 6:") != -1:
                                            if functionString.find("case 7:") != -1:
                                                if functionString.find("case 8:") != -1:
                                                    if functionString.find("case 9:") != -1:
                                                        if functionString.find("case 0xA:") != -1:
                                                            if functionString.find("case 0xB:") != -1:
                                                                if functionString.find("case 0xC:") != -1:
                                                                    if functionString.find("case 0xD:") != -1:
                                                                        if functionString.find("case 0xE:") != -1:
                                                                            if functionString.find("case 0xF:") != -1:
                                                                                if functionString.find("result = 0;") != -1:
                                                                                    if functionString.find("result = 1;") != -1:
                                                                                        if functionString.find("result = 2;") != -1:
                                                                                            if functionString.find("result = 3;") != -1:
                                                                                                if functionString.find("result = 4;") != -1:
                                                                                                    if functionString.find("result = 5;") != -1:
                                                                                                            if functionString.find("result = 6;") != -1:
                                                                                                                if functionString.find("result = 7;") != -1:
                                                                                                                    if functionString.find("result = 8;") != -1:
                                                                                                                        if functionString.find("result = 9;") != -1:
                                                                                                                            if functionString.find("result = 10;") != -1:
                                                                                                                                if functionString.find("return result;") != -1:
                                                                                                                                    functionList["CDisplay__GetIntensity"] = functionAddress

            # CDisplay__CreateLight
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("int result;") != -1:
                if functionString.find("switch") != -1:
                    if functionString.find("case") != -1:
                        if functionString.find("= 25.0;") != -1:
                            if functionString.find("= 100.0;") != -1:
                                if functionString.find("= 200.0;") != -1:
                                    if functionString.find("= 400.0;") != -1:
                                        if functionString.find("= 150.0;") != -1:
                                            if functionString.find("return result;") != -1:
                                                functionList["CDisplay__CreateLight"] = functionAddress

            # CDisplay__DeleteLight
            # ----------------------------------------------------------------------------------------------------
            # v1 = this;
            # if ( !sub_5352D0(dword_E806A0) || !byte_E8F34D || v1 != (_DWORD *)dword_E80694 && byte_E8E5D4 )
            #   return;
            # v2 = v1[1092];
            # v3 = 0;
            # if ( v2 )
            # {
            #   sub_538770(dword_E806A0, v2);    # 0x00538770
            #   v1[1092] = 0;
            #   v3 = 1;
            # }
            # v4 = *((float *)v1 + 32) * 6.2800002 * 0.001953125;
            if functionString.find("* 6.2800002 * 0.001953125;") != -1:
                if functionString.find("* 2.0;") != -1:
                    if functionString.find("== 5") != -1:
                        if functionString.find("== 6") != -1:
                            if functionString.find("== 7") != -1:
                                if functionString.find("== 8") != -1:
                                    if functionString.find("== 9") != -1:
                                        if functionString.find("== 10") != -1:
                                            matches = re.findall("if \( [0-9a-z]+ \)\n\s+{\n\s+sub_([0-9A-F]+)\(dword_[0-9A-F]+, [0-9a-z]+\);", functionString, re.MULTILINE)
                                            if matches:
                                                functionList["CDisplay__DeleteLight"] = "0x00" + matches[0]

            # CRender
            # ----------------------------------------------------------------------------------------------------
            # HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam
            # if ( !(*(unsigned __int8 (__stdcall **)(signed int))(*(_DWORD *)dword_16C9768 + 100))(1) )    # 0x016C9768
            if functionString.find("return DefWindowProcA") != -1:
                if functionString.find("\"ResetDevice() failed!\"") != -1:
                    matches = re.findall("\(\*\(_DWORD \*\)dword_([0-9A-F]+) \+ 100\)\)", functionString, re.MULTILINE)
                    if matches:
                        functionList["CRender"] = "0x0" + matches[0]

            # CAlertWnd
            # ----------------------------------------------------------------------------------------------------
            # if ( a7 == v74 )
            # {
            #   if ( *(_BYTE *)(v74 + 500) )
            #   {
            #     byte_E8F66B = 1;
            #     v123 = "Alerts triggered by first use of a window will be suppressed from now on.";
            #   }
            #   else
            #   {
            #     byte_E8F66B = 0;
            #     v123 = "Alerts triggered by first use of a window will be displayed from now on.";
            #   }
            #   sub_4E5B40();
            #   sub_4E61E0(v123, (LPVOID)0x111, (LPVOID)1, (LPVOID)1, 0);
            #   sub_6C64A0((_DWORD *)dword_DCC180, (unsigned __int8)byte_E8F66B);
            #   sub_921AB0("Defaults", "HideFirstUseAlerts", byte_E8F66B);
            #   return 0;
            # }
            if functionString.find("\"Alerts triggered by first use of a window will be suppressed from now on.\"") != -1:
                if functionString.find("\"Alerts triggered by first use of a window will be displayed from now on.\"") != -1:
                    if functionString.find("\"HideFirstUseAlerts\"") != -1:
                        matches = re.findall("sub_[0-9A-F]+\(\(_DWORD \*\)dword_([0-9A-F]+), \(unsigned __int8\)byte_[0-9A-F]+\);\n\s+sub_[0-9A-F]+\(\"Defaults\", \"HideFirstUseAlerts\", byte_[0-9A-F]+\);\n\s+return 0;", functionString, re.MULTILINE)
                        if matches:
                            functionList["CAlertWnd"] = "0x0" + matches[0]

            # CSpellBookWnd
            # ----------------------------------------------------------------------------------------------------
            # void __cdecl sub_5ADB30(int a1, char *a2)
            # {
            #   int v2; // eax
            #   const char *v3; // eax
            #   const char *v4; // eax
            #   char *v5; // ST04_4
            #   signed int v6; // ecx
            #
            #   if ( sub_5B85B0() )
            #   {
            #     v2 = sub_8BD2C0((char *)dword_E7F920 + *(_DWORD *)(*((_DWORD *)dword_E7F920 + 2) + 4) + 12);
            #     if ( v2 )
            #     {
            #       if ( !*(_DWORD *)(v2 + 15376) )
            #       {
            #         if ( sub_915540((_BYTE *)dword_DCD514) && !*a2 )
            #         {
            #           (*(void (**)(void))(*(_DWORD *)dword_DCD514 + 148))();    # 0x00DCD514
            #           return;
            #         }
            #         if ( strlen(a2) )
            #         {
            #           v3 = (const char *)sub_8B5EB0((int *)dword_E81B68, 0x22B3u, 0);
            #           if ( !_stricmp(a2, v3) )
            #           {
            #             if ( sub_915540((_BYTE *)dword_DCD514) )
            #               (*(void (**)(void))(*(_DWORD *)dword_DCD514 + 148))();    # 0x00DCD514
            #             return;
            #           }
            #           v4 = (const char *)sub_8B5EB0((int *)dword_E81B68, 0x22B2u, 0);
            #           _stricmp(a2, v4);
            #         }
            #         if ( sub_4D6BC0((_DWORD *)dword_E7F920 + 2310) )
            #         {
            #           if ( dword_E7F448 && *(float *)(dword_E7F448 + 124) > 0.0099999998 )
            #           {
            #             v5 = (char *)sub_8B5EB0((int *)dword_E81B68, 0x2F35u, 0);
            #             sub_4E5850();
            #             sub_4E5EF0(v5, (LPVOID)0x111, (LPVOID)1, (LPVOID)1, 0);
            #           }
            #           else if ( *((_BYTE *)dword_E7F3F0 + 1551) != 105 )
            #           {
            #             if ( !sub_915540((_BYTE *)dword_DCD514) )    # 0x00DCD514
            #               (*(void (**)(void))(*(_DWORD *)dword_DCD514 + 144))();    # 0x00DCD514
            #             if ( strlen(a2) )
            #             {
            #               v6 = sub_995C4D((int)a2) - 1;
            #               if ( v6 >= 1 )
            #               {
            #                 if ( v6 % 2 )
            #                   --v6;
            #                 sub_7FA360((_BYTE *)dword_DCD514, v6);    # 0x00DCD514
            #               }
            #               else
            #               {
            #                 sub_7FA360((_BYTE *)dword_DCD514, 0);    # 0x00DCD514
            #               }
            #             }
            #           }
            #         }
            #       }
            #     }
            #   }
            # }
            if functionString.find("0x2F35u") != -1:    # 12085 You must be completely stopped before doing this action.
                if functionString.find("0x22B2u") != -1:    # 8882 open
                    if functionString.find("0x22B3u") != -1:    # 8883 close
                        if functionString.find("> 0.0099999998") != -1:
                            matches = re.findall("dword_([0-9A-F]+) \+ 148\)\)\(\);", functionString, re.MULTILINE)
                            if matches:
                                functionList["CSpellBookWnd"] = "0x00" + matches[0]

            # CSpellBookWnd__GetSpellMemTicksLeft
            # ----------------------------------------------------------------------------------------------------
            # int __thiscall sub_7FA800(_DWORD *this)
            # {
            #   _DWORD *v1; // esi
            #   int result; // eax
            #   unsigned int v3; // edx
            #   unsigned int v4; // eax
            #   int v5; // ebx
            #   int v6; // edi
            #   char v7; // bl
            #   int v8; // [esp+4h] [ebp-4h]
            #
            #   v1 = this;
            #   if ( this[145] == -1 )
            #     return 0;
            #   v3 = *((_DWORD *)dword_E81B64 + 85);
            #   v4 = this[148];
            #   if ( v3 < v4 )
            #     return (signed int)(1000 * (v4 - v3)) / (signed int)(v4 - this[147]);
            #   ++dword_F2DE00;
            #   v8 = 41;
            #   if ( (unsigned int)((*(_DWORD *)(dword_103DA3C + 235044) - *(_DWORD *)(dword_103DA3C + 235040)) >> 2) < 0x14 )
            #     sub_69ACA0((_DWORD *)(dword_103DA3C + 235040), (unsigned int *)&v8);
            #   v5 = v1[146];
            #   v6 = v1[145];
            #   if ( *(_DWORD *)dword_E81B60 )
            #   {
            #     word_E81930 = sub_89E000(7000, 0);
            #     dword_E81932 = v6;
            #     LODWORD(qword_E81936) = v5;
            #     HIDWORD(qword_E81936) = 2;
            #     dword_E8193E = 0;
            #     v7 = sub_83EDA0(*(int *)dword_E81B60, 4, &word_E81930, 0x12u);
            #     j_j_j___free_base(0);
            #     --dword_1070014;
            #     if ( !v7 )
            #       sub_4EB5F0((int *)dword_C99C84, (LPCRITICAL_SECTION **)dword_E81B60);
            #   }
            #   else if ( !byte_E8F09C )
            #   {
            #     sub_8F00D0("Attempt to send message %d on a void connection.", 7000);
            #   }
            #   (*(void (**)(void))(*(_DWORD *)dword_DCCF90 + 148))();
            #   v1[147] = -1;
            #   result = 0;
            #   v1[148] = -1;
            #   v1[145] = -1;
            #   v1[146] = -1;
            #   return result;
            # }
            if functionString.find("int result;") != -1:
                if functionString.find("return 0;") != -1:
                    if functionString.find("result = 0;") != -1:
                        if functionString.find("return result;") != -1:
                            matches = re.findall("if \( [0-9a-z]+ < [0-9a-z]+ \)\n\s+return \(signed int\)\(1000 \* \([0-9a-z]+ - [0-9a-z]+\)\) / \(signed int\)\([0-9a-z]+ - this\[\d+\]\);", functionString, re.MULTILINE)
                            if matches:
                                functionList["CSpellBookWnd__GetSpellMemTicksLeft"] = functionAddress

            # CSpellBookWnd__GetSpellScribeTicksLeft
            # ----------------------------------------------------------------------------------------------------
            # int __thiscall sub_7FA960(_DWORD *this)    # 0x007FA960
            # {
            #   _DWORD *v1; // esi
            #   int result; // eax
            #   int v3; // ecx
            #   int v4; // eax
            #   unsigned int v5; // ebx
            #   int v6; // edi
            #   char v7; // bl
            #   int v8; // [esp+4h] [ebp-4h]
            #
            #   v1 = this;
            #   if ( this[149] == -1 )
            #     return 0;
            #   v3 = *((_DWORD *)dword_E81B64 + 85);
            #   if ( (unsigned int)(*((_DWORD *)dword_E81B64 + 85) - dword_1050B1C) > 1 )
            #   {
            #     v1[150] -= 3;
            #     dword_1050B1C = v3;
            #   }
            #   v4 = v1[150];
            #   if ( v4 > 0 )
            #     return 1000 * v4 / 92;
            #   ++dword_F2DE00;
            #   v8 = 43;
            #   if ( (unsigned int)((*(_DWORD *)(dword_103DA3C + 235044) - *(_DWORD *)(dword_103DA3C + 235040)) >> 2) < 0x14 )
            #     sub_69ACA0((_DWORD *)(dword_103DA3C + 235040), (unsigned int *)&v8);
            #   v5 = v1[146];
            #   v6 = v1[149];
            #   if ( *(_DWORD *)dword_E81B60 )
            #   {
            #     word_E81930 = sub_89E000(7000, 0);
            #     dword_E81932 = v6;
            #     qword_E81936 = v5;
            #     dword_E8193E = 0;
            #     v7 = sub_83EDA0(*(int *)dword_E81B60, 4, &word_E81930, 0x12u);
            #     j_j_j___free_base(0);
            #     --dword_1070014;
            #     if ( !v7 )
            #       sub_4EB5F0((int *)dword_C99C84, (LPCRITICAL_SECTION **)dword_E81B60);
            #   }
            #   else if ( !byte_E8F09C )
            #   {
            #     sub_8F00D0("Attempt to send message %d on a void connection.", 7000);
            #   }
            #   v1[146] = -1;
            #   result = 0;
            #   v1[149] = -1;
            #   v1[150] = 0;
            #   dword_1050B1C = 0;
            #   return result;
            # }
            if functionString.find("int result;") != -1:
                if functionString.find("return 0;") != -1:
                    if functionString.find("result = 0;") != -1:
                        if functionString.find("return result;") != -1:
                            matches = re.findall("if \( [0-9a-z]+ > 0 \)\n\s+return 1000 \* [0-9a-z]+ / 92;", functionString, re.MULTILINE)
                            if matches:
                                functionList["CSpellBookWnd__GetSpellScribeTicksLeft"] = functionAddress

            functionString = ""

if mapOffset != 0:
    with open("eqgame.map", "rt") as in_file:
        lines = in_file.readlines()
        for index, line in enumerate(lines):

            # WindowHWND
            # ----------------------------------------------------------------------------------------------------
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
    out_file.write("    EQ_SIZE_CXWnd = " + functionList["SizeCXWnd"] + ";\n")
    out_file.write("    EQ_SIZE_CSidlScreenWnd = " + hex(functionList["SizeCSidlScreenWnd"]) + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_OFFSET_SPAWN_STANDING_STATE             = " + hex(functionList["OffsetSpawnStandingState"]) + ";\n")
    out_file.write("    EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = " + hex(functionList["OffsetSpawnFollowSpawn"]) + ";\n")
    out_file.write("    EQ_OFFSET_SPAWN_HP_CURRENT                 = " + hex(functionList["OffsetSpawnHPCurrent"]) + ";\n")
    out_file.write("    EQ_OFFSET_SPAWN_HP_MAX                     = " + hex(functionList["OffsetSpawnHPMax"]) + ";\n")
    out_file.write("    EQ_OFFSET_SPAWN_MANA_CURRENT               = " + hex(functionList["OffsetSpawnManaCurrent"]) + ";\n")
    out_file.write("    EQ_OFFSET_SPAWN_MANA_MAX                   = " + hex(functionList["OffsetSpawnManaMax"]) + ";\n")
    out_file.write("    EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = " + hex(functionList["OffsetSpawnEnduranceCurrent"]) + ";\n")
    out_file.write("    EQ_OFFSET_SPAWN_ENDURANCE_MAX              = " + hex(functionList["OffsetSpawnEnduranceMax"]) + ";\n")
    out_file.write("    EQ_OFFSET_SPAWN_CharacterZoneClient        = " + hex(functionList["OffsetSpawnCharacterZoneClient"]) + ";\n")
    out_file.write("    EQ_OFFSET_EQ_Character____CharacterBase    = " + hex(functionList["OffsetCharacterBase"]) + ";\n")
    out_file.write("    EQ_OFFSET_CharInfo2__Bandolier             = " + hex(functionList["OffsetCharInfo2Bandolier"]) + ";\n")
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
    out_file.write("    EQ_ADDRESS_POINTER_ControlledSpawn    = " + functionList["ControlledSpawn"] + ";\n")
    out_file.write("    EQ_ADDRESS_POINTER_PlayerSpawn        = " + functionList["PlayerSpawn"] + ";\n")
    out_file.write("    EQ_ADDRESS_POINTER_TargetSpawn        = " + functionList["TargetSpawn"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_FlushDxKeyboard               = " + functionList["FlushDxKeyboard"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_FlushDxMouse                  = " + functionList["FlushDxMouse"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent          = " + functionList["ProcessKeyboardEvent"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_ProcessMouseEvent             = " + functionList["ProcessMouseEvent"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_WindowProc                    = " + functionList["WindowProc"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = " + functionList["CollisionCallbackForActors"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CastRay                       = " + functionList["CastRay"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CastRay2                      = " + functionList["CastRay2"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = " + functionList["DrawNetStatus"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = " + functionList["ExecuteCmd"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_DoSpellEffect                 = " + functionList["DoSpellEffect"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = " + functionList["PlaySoundAtLocation"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_GetTime                       = " + functionList["GetTime"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_UpdateLight                   = " + functionList["UpdateLight"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = " + functionList["GetGaugeValueFromEQ"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_get_bearing                   = " + functionList["get_bearing"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_get_melee_range               = " + functionList["get_melee_range"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_StringTable = " + functionList["StringTable"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_StringTable__getString    = " + functionList["StringTable__getString"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CDBStr = " + functionList["CDBStr"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDBStr__GetString    = " + functionList["CDBStr__GetString"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_EQ_Character = " + functionList["EQ_Character"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = " + functionList["EQ_Character__encum_factor"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = " + functionList["EQ_Character__TakeFallDamage"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = " + functionList["EQ_Character__CanIBreathe"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = " + functionList["EQ_Character__CanISeeInvis"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = " + functionList["EQ_Character__StunMe"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = " + functionList["EQ_Character__UnStunMe"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = " + functionList["EQ_Character__ProcessEnvironment"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQ_Character__TotalSpellAffects     = " + functionList["EQ_Character__TotalSpellAffects"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav    = " + functionList["CharacterZoneClient__SetNoGrav"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_EQ_PC = " + functionList["EQ_PC"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney    = " + functionList["EQ_PC__DestroyHeldItemOrMoney"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_EQPlayerManager = " + functionList["EQPlayerManager"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = " + functionList["EQPlayerManager__GetSpawnByID"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = " + functionList["EQPlayerManager__GetSpawnByName"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = " + functionList["EQPlayer__ChangeHeight"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = " + functionList["EQPlayer__ChangePosition"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = " + functionList["EQPlayer__GetLevel"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = " + functionList["EQPlayer__GetActorClient"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = " + functionList["EQPlayer__FollowPlayerAI"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = " + functionList["EQPlayer__TurnOffAutoFollow"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = " + functionList["EQPlayer__UpdateItemSlot"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = " + functionList["EQPlayer__IsTargetable"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = " + functionList["EQPlayer__SetNameSpriteState"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = " + functionList["EQPlayer__SetNameSpriteTint"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = " + functionList["EQPlayer__ChangeLight"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading    = " + functionList["EQPlayer__push_along_heading"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_EQSwitchManager = " + functionList["EQSwitchManager"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = " + functionList["EQSwitch__UseSwitch"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = " + functionList["EQSwitch__ChangeState"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = " + functionList["EQSpell__SpellAffects"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CXWndManager = " + functionList["CXWndManager"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = " + functionList["CXWndManager__DrawWindows"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = " + functionList["CXWnd__IsReallyVisible"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CEverQuest = " + functionList["CEverQuest"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert        = " + functionList["CEverQuest__DoPercentConvert"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone               = " + functionList["CEverQuest__EnterZone"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd            = " + functionList["CEverQuest__InterpretCmd"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat                = " + functionList["CEverQuest__dsp_chat"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState            = " + functionList["CEverQuest__SetGameState"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp                = " + functionList["CEverQuest__LMouseUp"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp                = " + functionList["CEverQuest__RMouseUp"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel        = " + functionList["CEverQuest__HandleMouseWheel"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting            = " + functionList["CEverQuest__StartCasting"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText             = " + functionList["CEverQuest__SendNewText"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround    = " + functionList["CEverQuest__DropHeldItemOnGround"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CDisplay = " + functionList["CDisplay"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = " + functionList["CDisplay__WriteTextHD2"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = " + functionList["CDisplay__CreateActor"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = " + functionList["CDisplay__CreatePlayerActor"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = " + functionList["CDisplay__DeleteActor"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = " + functionList["CDisplay__GetIntensity"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = " + functionList["CDisplay__CreateLight"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = " + functionList["CDisplay__DeleteLight"] + ";\n")
    out_file.write("\n")
    out_file.write("    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime\n")
    out_file.write("    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CRender = " + functionList["CRender"] + ";\n")
    out_file.write("    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime\n")
    out_file.write("    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime\n")
    out_file.write("    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime\n")
    out_file.write("    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CAlertWnd = " + functionList["CAlertWnd"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CSpellBookWnd = " + functionList["CSpellBookWnd"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = " + functionList["CSpellBookWnd__GetSpellMemTicksLeft"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = " + functionList["CSpellBookWnd__GetSpellScribeTicksLeft"] + ";\n")
    out_file.write("}\n")