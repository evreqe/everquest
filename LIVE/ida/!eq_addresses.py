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
#   "OffsetCharacterGroupInfo": 0,
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
    "AreAlertWindowsModified": 0,
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
    "CharacterZoneClient__SetNoGrav": 0,
    "CharacterZoneClient__TotalSpellAffects": 0,
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
    "EQPlayer__AllowedToAttack": 0,
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
    "CEverQuest__RightClickedOnPlayer": 0,
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
    "CAlertStackWnd": 0,
    "CAlertHistoryWnd": 0,
    "CBazaarSearchWnd": 0,
    "CBazaarSearchWnd__AddItemToList": 0,
    "CBazaarSearchWnd__BuyItem": 0,
    "CBazaarSearchWnd__doQuery": 0,
    "CBazaarConfirmationWnd": 0,
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
                if functionString.find(", 0x283u,") != -1 or functionString.find(", 643,") != -1:    # 643 You cannot perform that action right now. Please try again in a moment.
                    if functionString.find(", 0x2C39u,") != -1 or functionString.find(", 11321,") != -1:    # 11321 These item(s) are locked because you were not present when the enemy died. To loot them you will first need to right-click that enemy's corpse to unlock.
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
            if functionString.find(", 0x3292u,") != -1 or functionString.find(", 12946,") != -1:    # 12946: off
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
            if functionString.find(", 0x33A9u,") != -1 or functionString.find(", 13225,") != -1:    # 13225 You must first target a player to auto-follow.
                if functionString.find(", 0x33AAu,") != -1 or functionString.find(", 13226,") != -1:    # 13226 You can't auto-follow yourself.
                    if functionString.find(", 0x33ABu,") != -1 or functionString.find(", 13227,") != -1:    # 13227 You cannot move right now, how could you follow?
                        if functionString.find(", 0x33ACu,") != -1 or functionString.find(", 13228,") != -1:    # 13228 You are not yourself right now, you cannot follow.
                            if functionString.find(", 0x33ADu,") != -1 or functionString.find(", 13229,") != -1:    # 13229 Stand up first!
                                if functionString.find(", 0x33AEu,") != -1 or functionString.find(", 13230,") != -1:    # 13230 You will now auto-follow %1.
                                    if functionString.find(", 0x33AFu,") != -1 or functionString.find(", 13231,") != -1:    # 13231 *WARNING*: Do NOT use around lava, water, cliffs, or other dangerous areas because you WILL fall into them. You have been warned.
                                        if functionString.find(", 0x33B0u,") != -1 or functionString.find(", 13232,") != -1:    # 13232 Also, auto-follow works best in wide open areas with low lag.  Twisty areas, lag, and other factors may cause auto-follow to fail.
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
            # --------------------------------------------------
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
                    if functionString.find("== 100") != -1:
                        if functionString.find("* 0.0099999998") != -1:
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

            # OffsetCharacterGroupInfo
            # ----------------------------------------------------------------------------------------------------
            # void sub_5B5900()    # /groupleader
            # {
            #   int v0; // eax
            #   char *v1; // ST18_4
            #   int v2; // ecx
            #   void *v3; // eax
            #   char v4; // [esp+0h] [ebp-200h]
            #
            #   v0 = *((_DWORD *)dword_E85F94 + 2569);    # OffsetCharacterGroupInfo
            #   if ( v0 )
            #   {
            #     v2 = *(_DWORD *)(v0 + 28);
            #     if ( v2 )
            #       v3 = sub_8EDE00((LPVOID *)(v2 + 4));
            #     else
            #       v3 = sub_8B7EA0((int *)dword_E861A0, 0x4C0u, 0);
            #     sub_59A680((int)&v4, 7603, (int)v3, 0, 0, 0, 0, 0, 0, 0, 0);
            #     sub_4E4C80();
            #     sub_4E5350(&v4, (LPVOID)0xF, (LPVOID)1, (LPVOID)1, 0);
            #   }
            #   else
            #   {
            #     v1 = (char *)sub_8B7EA0((int *)dword_E861A0, 0xCDCu, 0);
            #     sub_4E4C80();
            #     sub_4E5350(v1, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #   }
            # }
            #if functionString.find(", 0, 0, 0, 0, 0, 0, 0, 0);") != -1:
            #    if functionString.find("0xF,") != -1:
            #        if functionString.find("0xD,") != -1:
            #            if functionString.find(", 7603,") != -1 or functionString.find(", 0x1DB3u,") != -1:    # 7603 Leader: %1
            #                if functionString.find(", 0x4C0u,") != -1 or functionString.find(", 1216,") != -1:    # 1216 None
            #                    if functionString.find(", 0xCDCu,") != -1 or functionString.find(", 3292,") != -1:    # 3292 You must be in a group to perform this action.
            #                        matches = re.findall("[0-9a-z]+ = \*\(\(_DWORD \*\)dword_[0-9A-F]+ \+ (\d+)\);", functionString, re.MULTILINE)
            #                        if matches:
            #                            functionList["OffsetCharacterGroupInfo"] = int(matches[0])

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
            if functionString.find("\"%sBandolier%d=\"") != -1:
                matches = re.findall("this \+ (\d+)", functionString, re.MULTILINE)
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
                if functionString.find(", 0x3052u,") != -1 or functionString.find(", 12370,") != -1:
                    if functionString.find(", 0x3053u,") != -1 or functionString.find(", 12371,") != -1:
                        matches = re.findall("if \( byte_([0-9A-F]+) \)\n\s+[0-9a-z]+ = (?:.*?)?sub_[0-9A-F]+\((?:.*?)?dword_[0-9A-F]+, (?:0x3052u|12370), 0\);", functionString, re.MULTILINE)
                        if matches:
                            functionList["AutoAttack"] = "0x00" + matches[0]

            # AutoFire
            # ----------------------------------------------------------------------------------------------------
            # v4 = (char *)byte_F2BCEC ? sub_8B4BE0((int *)dword_E7F46C, 0x116u, 0) : sub_8B4BE0((int *)dword_E7F46C, 0x117u, 0);    # 0x00F2BCEC
            # 278 Auto fire on.
            # 279 Auto fire off.
            if functionString.find(", 0x116u,") != -1 or functionString.find(", 278,") != -1:
                if functionString.find(", 0x117u,") != -1 or functionString.find(", 279,") != -1:
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
            if functionString.find(", 0x2F3Fu,") != -1 or functionString.find(", 12095,") != -1:    # 12095 Interface locked.  Please use /safelock to unlock it.
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
            if functionString.find(", 0x3194u,") != -1 or functionString.find(", 12692,") != -1:    # 12692 %1 is dead, canceling auto-follow.
                if functionString.find(", 0x3195u,") != -1 or functionString.find(", 12693,") != -1:    # 12693 %1 is too far away, canceling auto-follow.
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
                                        if functionString.find("|= 0x80u") != -1:
                                            if functionString.find("& 0x40") != -1:
                                                if functionString.find("& 0x20") != -1:
                                                    if functionString.find("& 0x10") != -1:
                                                        if functionString.find("case 1:") != -1:
                                                            if functionString.find("case 2:") != -1:
                                                                if functionString.find("case 3:") != -1:
                                                                    if functionString.find("case 4:") != -1:
                                                                        if functionString.find("case 5:") != -1:
                                                                            if functionString.find("case 6:") != -1:
                                                                                if functionString.find("case 7:") != -1:
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
                        if functionString.find("180.0") != -1:
                            if functionString.find("0.3183099014828645") != -1:
                                if functionString.find("90.0") != -1:
                                    if functionString.find("270.0") != -1:
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
            # void __stdcall sub_5F1520(int a1)
            # {
            #   int v1; // esi
            #   int v2; // edi
            #   char v3; // bl
            #   char v4; // [esp+8h] [ebp-200h]
            #
            #   if ( a1 && !*(_BYTE *)(a1 + 293) )
            #   {
            #     if ( sub_53CD90(a1, dword_E8F3A0, 1.0) >= 20.0 )    # 0x00E8F3A0
            #     {
            #       sub_59AEB0((int)&v4, 0x305Au, a1 + 164, 0, 0, 0, 0, 0, 0, 0, 0);
            #       sub_4E61E0();
            #       sub_4E6880(&v4, (LPVOID)0x111, (LPVOID)1, (LPVOID)1, 0);
            #     }
            #     else
            #     {
            #       v1 = *(_DWORD *)(a1 + 336);
            #       v2 = *((_DWORD *)dword_E8F348 + 84);
            #       if ( *(_DWORD *)dword_E918C8 )
            #       {
            #         word_E8EFD0 = sub_8A1CB0(18767, 0);
            #         dword_E8EFD2 = v1;
            #         LODWORD(qword_E8EFD6) = v2;
            #         v3 = sub_8426C0(*(int *)dword_E918C8, 4, &word_E8EFD0, 0xAu);
            #         j_j_j___free_base(0);
            #         --dword_107FC7C;
            #         if ( !v3 )
            #           sub_4EBCE0((_DWORD *)dword_CAAE64, (LPCRITICAL_SECTION **)dword_E918C8);
            #       }
            #       else if ( !byte_E9ED04 )
            #       {
            #         sub_8F3F50("Attempt to send message %d on a void connection.", 18767);
            #       }
            #     }
            #   }
            # }
            if functionString.find(", 0x305Au,") != -1 or functionString.find(", 12378,") != -1:    # 12378 %1 is too far away to inspect.  Get closer.
                if functionString.find(", 1.0) >= 20.0 )") != -1:
                    matches = re.findall(", dword_([0-9A-F]+), 1.0\) >= 20.0 \)", functionString, re.MULTILINE)
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
            if functionString.find(", 0x3391u,") != -1 or functionString.find(", 13201,") != -1:    # # 13201 You must first target a corpse to loot!
                matches = re.findall("sub_[0-9A-F]+\((?:.*?)?dword_[0-9A-F]+, (?:0x3391u|13201), dword_([0-9A-F]+)\);", functionString, re.MULTILINE)
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
            if functionString.find(", 0x5DEu,") != -1 or functionString.find(", 1502,") != -1:    # 1502 Warrior
                if functionString.find(", 0x5E2u,") != -1 or functionString.find(", 1506,") != -1:    # 1506 Cleric
                    if functionString.find(", 0x5E6u,") != -1 or functionString.find(", 1510,") != -1:    # 1510 Paladin
                        if functionString.find(", 0x5EEu,") != -1 or functionString.find(", 1514,") != -1:    # 1514 Shadow Knight
                            matches = re.findall("result = sub_[0-9A-F]+\((?:.*?)?dword_([0-9A-F]+), (?:0x5DEu|1502), 0\);", functionString, re.MULTILINE)
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
                if re.search("&unk_[0-9A-F]+, (?:.*?)?\"%s \(%d\)\", (?:.*?)?off_[0-9A-F]+", functionString):
                    functionList["StringTable__getString"] = functionAddress

            # CDBStr
            # ----------------------------------------------------------------------------------------------------
            # v3 = "Unknown AA";
            # if ( dword_DCBB6C )    # 0x00DCBB6C
            #   v3 = sub_52FC80(dword_DCBB6C, this[4], 1u, 0);    # 0x00DCBB6C
            # sub_599A20((int)&v8, 0xE6Fu, (int)v3, 0, 0, 0, 0, 0, 0, 0, 0);
            # sub_8EB050(&lpMem, &v8);
            if functionString.find("Unknown AA") != -1:
                if functionString.find(", 0xE6Fu,") != -1 or functionString.find(", 3695,") != -1:    # 3695 AA: %1
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
            if functionString.find(", 0x1DE3u,") != -1 or functionString.find(", 7651,") != -1:    # 7651 Open Polls
                if functionString.find("\"%s ( %d )\"") != -1:
                    matches = re.findall("\+ \*\(_DWORD \*\)\(\*\(\(_DWORD \*\)dword_([0-9A-F]+) \+ 2\) \+ 4\)", functionString, re.MULTILINE)
                    if matches:
                        functionList["EQ_Character"] = "0x00" + matches[0]

            # EQ_Character__encum_factor
            # ----------------------------------------------------------------------------------------------------
            if functionString.find("0x3067u") != -1 or functionString.find(", 12391,") != -1:    # 12391 You are no longer encumbered.
                if functionString.find("0x3068u") != -1 or functionString.find(", 12392,") != -1:    # 12392 You are encumbered!
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
            # int __userpurge sub_4D8100@<eax>(_DWORD *a1@<ecx>, double a2@<st7>, double a3@<st6>, double a4@<st5>, double a5@<st4>, double a6@<st3>, long double a7@<st2>, float a8)
            # {
            #   int v8; // ebp
            #   int v9; // ebx
            #   double v10; // st7
            #   double v12; // st7
            #   double v13; // st6
            #   _DWORD *v14; // ecx
            #   signed int v15; // edi
            #   int v16; // eax
            #   int v17; // esi
            #   char v18; // bl
            #   __int16 v19; // [esp+8h] [ebp-30h]
            #   __int16 v20; // [esp+Ah] [ebp-2Eh]
            #   int v21; // [esp+Ch] [ebp-2Ch]
            #   int v22; // [esp+10h] [ebp-28h]
            #   float v23; // [esp+14h] [ebp-24h]
            #   float v24; // [esp+18h] [ebp-20h]
            #   float v25; // [esp+1Ch] [ebp-1Ch]
            #   float v26; // [esp+20h] [ebp-18h]
            #   char v27; // [esp+24h] [ebp-14h]
            #   int v28; // [esp+2Dh] [ebp-Bh]
            #   char v29; // [esp+31h] [ebp-7h]
            #   int v30; // [esp+32h] [ebp-6h]
            #
            #   v8 = (int)a1;
            #   v9 = 0;
            #   v10 = (double)(signed int)a1[5] * 0.0099999998;
            #   if ( !*((_BYTE *)dword_E81244 + 372) )
            #   {
            #     *((_BYTE *)dword_E81244 + 372) = 1;
            #     return 0;
            #   }
            #   v23 = 1.0;
            #   v30 = 0;
            #   v12 = v10 + a8 - 1.5;
            #   v13 = 0.0;
            #   if ( v12 >= 9.0 )
            #   {
            #     v9 = 200000;
            #     goto LABEL_5;
            #   }
            #   if ( v12 > 0.0 )
            #   {
            #     v13 = 10.0 * v12;
            #     v15 = (signed int)(v12 * (10.0 * v12));
            #     if ( v15 > 0 )
            #     {
            #       v15 -= v15 * a1[44] / (a1[44] + 1000);
            #       LOBYTE(v16) = sub_4D14D0(a1, 0x27u);
            #       if ( v16 > 0 )
            #       {
            #         v17 = *(_DWORD *)(sub_8BBA60((_DWORD *)(*(_DWORD *)(*(_DWORD *)(v8 + 4) + 4) + v8 + 8)) + 14260);
            #         v15 += -v17 - v17 * sub_4C1BF0(v8, 0xE4u, 1, 0, 1, 1) / 100;
            #         if ( *(_DWORD *)dword_E81230 )
            #         {
            #           word_E81030 = sub_89C850(18347, 0);
            #           v18 = sub_83D500(*(int *)dword_E81230, 4, &word_E81030, 2u);
            #           j_j_j___free_base(0);
            #           --dword_1071B24;
            #           if ( !v18 )
            #           {
            #             sub_4EAE80((_DWORD *)dword_C9CD3C, (LPCRITICAL_SECTION **)dword_E81230);
            #             v9 = v15 <= 0 ? 0 : v15;
            #             goto LABEL_5;
            #           }
            #         }
            #         else if ( !byte_E90BC4 )
            #         {
            #           sub_8EE420("Attempt to send message %d on a void connection.", 18347);
            #         }
            #       }
            #     }
            #     v9 = v15 <= 0 ? 0 : v15;
            #   }
            # LABEL_5:
            #   v14 = *(_DWORD **)(v8 + 8);
            #   if ( v14 && sub_986BD0(v14) )
            #     v9 = v9 < 200 ? 0 : v9;
            #   if ( byte_E911C6 )
            #     return 0;
            #   if ( v9 > 0 )
            #   {
            #     v19 = *(_WORD *)(*(_DWORD *)(v8 + 8) + 336);
            #     v20 = 0;
            #     v21 = 0;
            #     v24 = 0.0;
            #     v25 = 0.0;
            #     v26 = 0.0;
            #     v22 = v9;
            #     v27 = -4;
            #     v28 = -1;
            #     v29 = -1;
            #     v9 = sub_4D8CB0(
            #            (void (__thiscall *)(int **, int *))v8,
            #            a2,
            #            a3,
            #            a4,
            #            a5,
            #            a6,
            #            a7,
            #            v13,
            #            0.0,
            #            v9,
            #            (int)&v19,
            #            1,
            #            0,
            #            1,
            #            1,
            #            0);
            #   }
            #   return v9;
            # }
            if functionString.find("= 200000;") != -1:
                if functionString.find("0xE4u, 1, 0, 1, 1) / 100;") != -1:
                    if functionString.find(">= 9.0") != -1:
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
            #     result = sub_4C2410(v1, 0xEu, 1, 0, 1, 1) > 0;    # CharacterZoneClient__TotalSpellAffects(EQ_SPELL_AFFECT_BREATHE_UNDERWATER, 1, 0, 1, 1,);
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
            #     v3 = sub_4C2410(v1, 0xDu, 1, 0, 1, 1);    # CharacterZoneClient__TotalSpellAffects(EQ_SPELL_AFFECT_SEE_INVISIBLE, 1, 0, 1, 1,);
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
            if functionString.find(", 0x30BFu, ") != -1 or functionString.find(", 12479,") != -1:    # 12479 You are stunned!
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
            if functionString.find(", 0x30C0u,") != -1 or functionString.find(", 12480,") != -1:    # 12480 You are no longer stunned.
                if functionString.find("0x1Au") != -1:
                    if functionString.find("0x154") != -1:
                        if functionString.find("= 0;") != -1:
                            functionList["EQ_Character__UnStunMe"] = functionAddress

            # EQ_Character__ProcessEnvironment
            # ----------------------------------------------------------------------------------------------------
            # void __usercall sub_4DD9D0(int a1@<ecx>, double a2@<st7>, double a3@<st6>, double a4@<st5>, double a5@<st4>, double a6@<st3>, long double a7@<st2>, double a8@<st1>, double a9@<st0>)
            # {
            #   int v9; // edi
            #   int v10; // esi
            #   int v11; // ebp
            #   unsigned __int8 v12; // bl
            #   int v13; // ecx
            #   int v14; // eax
            #   int v15; // edx
            #   int v16; // eax
            #   char v17; // bl
            #   signed int v18; // [esp+10h] [ebp-38h]
            #   char v19; // [esp+14h] [ebp-34h]
            #   __int16 v20; // [esp+18h] [ebp-30h]
            #   __int16 v21; // [esp+1Ah] [ebp-2Eh]
            #   int v22; // [esp+1Ch] [ebp-2Ch]
            #   int v23; // [esp+20h] [ebp-28h]
            #   char v28; // [esp+34h] [ebp-14h]
            #   int v29; // [esp+3Dh] [ebp-Bh]
            #   char v30; // [esp+41h] [ebp-7h]
            #   int v31; // [esp+42h] [ebp-6h]
            #
            #   __asm { fld1 }
            #   v9 = a1;
            #   v31 = 0;
            #   __asm { fstp    [esp+48h+var_24] }
            #   v10 = 0;
            #   v19 = -6;
            #   v11 = *(_DWORD *)(a1 + 8);
            #   v12 = *(_BYTE *)(v11 + 162);
            #   if ( v12 >= 3u && v12 != 5 )
            #   {
            #     if ( v12 == 3 || v12 == 7 )
            #     {
            #       v18 = 3;
            #       v13 = *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4);
            #       v14 = *(_DWORD *)(v11 + 560);
            #       v15 = *(_DWORD *)(v13 + v9 + 692);
            #       if ( v14 > 1000 )
            #         v14 = *(_DWORD *)(v11 + 560) & 0x7FFF;
            #       v16 = v14 - 200;
            #       if ( v16 )
            #       {
            #         if ( v16 == 78 )
            #           v18 = 5;
            #       }
            #       else
            #       {
            #         v15 = *(_DWORD *)(v13 + v9 + 684);
            #         v19 = -12;
            #       }
            #       v10 = dword_E96198 - v15 / v18;
            #       if ( v10 < dword_E9619C )
            #         v10 = dword_E9619C;
            #     }
            #     if ( v12 != 4 && v12 != 8 )
            #     {
            #       v17 = v19;
            #     }
            #     else
            #     {
            #       v17 = -10;
            #       v10 = 50 - *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v9 + 4) + 4) + v9 + 696) / 3;
            #       if ( v10 < 10 )
            #       {
            #         v10 = 10;
            # LABEL_19:
            #         __asm { fldz }
            #         v20 = *(_WORD *)(v11 + 336);
            #         v21 = 0;
            #         v22 = 0;
            #         __asm
            #         {
            #           fst     [esp+5Ch+var_20]
            #           fst     [esp+60h+var_1C]
            #           fstp    [esp+64h+var_18]
            #         }
            #         v23 = v10;
            #         v28 = v17;
            #         v29 = -1;
            #         v30 = -1;
            #         sub_4D8B50((char *)v9, a2, a3, a4, a5, a6, a7, a8, a9, v10, (int)&v20, 1, 0, 1, 1, 0);
            #         return;
            #       }
            #     }
            #     if ( v10 <= 0 )
            #       return;
            #     goto LABEL_19;
            #   }
            # }
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
                                                                            if functionString.find("/ 3;") != -1:
                                                                                functionList["EQ_Character__ProcessEnvironment"] = functionAddress

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

            # CharacterZoneClient__TotalSpellAffects
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
                                matches = re.findall("result = sub_([0-9A-F]+)\(", functionString, re.MULTILINE)
                                if matches:
                                    functionList["CharacterZoneClient__TotalSpellAffects"] = "0x00" + matches[0]

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
            # void __thiscall sub_711410(void *this, int a2)
            # {
            #   void *v2; // esi
            #   int v3; // eax
            #   char v4; // [esp+4h] [ebp-100h]
            #
            #   v2 = this;
            #   if ( a2 )
            #   {
            #     v3 = sub_651340((_DWORD **)dword_F37AE8, *(_DWORD *)(a2 + 16));
            #     if ( v3 )
            #     {
            #       sub_481020((int)&v4, "%s has invited you to join a fellowship, do you wish to accept?", v3 + 164);
            #       sub_7C2810((int *)dword_10564F0, v2 != 0 ? (unsigned int)v2 + 544 : 0, 1, (int)&v4, 0xCu, 100000, 0, 0);
            #     }
            #   }
            # }
            if functionString.find("\"%s has invited you to join a fellowship, do you wish to accept?\"") != -1:
                matches = re.findall("[0-9a-z]+ = sub_([0-9A-F]+)\(\(_DWORD \*\*\)dword_([0-9A-F]+), ", functionString, re.MULTILINE)
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
            if functionString.find(", 0x32A3u,") != -1 or functionString.find(", 12963,") != -1:    # 12963 %1's height changed from %2 to %3.
                if functionString.find(", 0x32A4u,") != -1 or functionString.find(", 12964,") != -1:    # 12964 Requesting to change %1's height from %2 to %3.
                    matches = re.findall("sub_([0-9A-F]+)\([0-9a-z]+, [0-9a-z]+, [0-9a-z]+, 1.0, 0\);", functionString, re.MULTILINE)
                    if matches:
                        functionList["EQPlayer__ChangeHeight"] = "0x00" + matches[0]

            # EQPlayer__ChangePosition
            # ----------------------------------------------------------------------------------------------------
            # double __userpurge sub_659CE0@<st0>(int a1@<ecx>, int a2@<ebp>, int a3@<esi>, double result@<st0>, double st6_0@<st1>, double a6@<st2>, double a7@<st3>, double a8@<st4>, double a9@<st5>, double a10@<st6>, double a11@<st7>, float a5)
            # {
            #   unsigned __int8 v12; // bh
            #   _DWORD *v14; // eax
            #   int v15; // ebp
            #   char *v16; // ST08_4
            #   char v17; // al
            #   char v19; // al
            #   char v22; // bl
            #   int v23; // eax
            #   int v26; // eax
            #   char v27; // al
            #   _DWORD *v30; // eax
            #   int v31; // eax
            #   float v32; // ST0C_4
            #   char v35; // al
            #   _DWORD *v36; // eax
            #   int v37; // eax
            #   _DWORD *v39; // eax
            #   _DWORD *v41; // eax
            #   _DWORD *v43; // eax
            #   int v44; // eax
            #   float v45; // ST0C_4
            #   int v48; // eax
            #   _DWORD *v49; // eax
            #   int v50; // eax
            #   float v51; // ST0C_4
            #   _DWORD *v52; // eax
            #   int v53; // ST18_4
            #   _DWORD *v54; // eax
            #   int v55; // eax
            #   int v56; // esi
            #   _DWORD *v59; // eax
            #   int v61; // eax
            #   _DWORD *v62; // eax
            #   int v63; // [esp+10h] [ebp-2Ch]
            #   int v64; // [esp+14h] [ebp-28h]
            #   signed int v65; // [esp+24h] [ebp-18h]
            #   float v66; // [esp+28h] [ebp-14h]
            #   int v67; // [esp+2Ch] [ebp-10h]
            #   int v68; // [esp+30h] [ebp-Ch]
            #
            #   v12 = LOBYTE(a5);
            #   _EDI = (_BYTE *)a1;
            #   if ( *(_BYTE *)(a1 + 1521) != LOBYTE(a5) )
            #   {
            #     if ( LOBYTE(a5) != 115 )
            #       *(_BYTE *)(a1 + 1320) = 0;
            #     if ( LOBYTE(a5) != 110 || !sub_986BD0((_DWORD *)a1) )
            #     {
            #       v64 = a2;
            #       v63 = a3;
            #       v14 = (_DWORD *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI);
            #       v15 = sub_64CD90(v14);
            #       if ( _EDI == (_BYTE *)dword_E8131C )
            #       {
            #         dword_E90C90 = 0;
            #         if ( _EDI == dword_E81244 )
            #         {
            #           if ( dword_E90E18 )
            #             sub_5D3890((void *)dword_F3554C, 0, 1);
            #           if ( dword_E90C94 )
            #           {
            #             v16 = (char *)sub_8B4830(dword_E81028, 12497, 0);
            #             sub_4E4FB0();
            #             sub_4E56A0(v16, (LPVOID)0x111, (LPVOID)1, (LPVOID)1, 0);
            #             dword_E90C94 = 0;
            #             LOWORD(v67) = -1;
            #             dword_E90C98 = -1;
            #             dword_E90C9C = -1;
            #             dword_E90CA0 = v67;
            #           }
            #           if ( _EDI[1521] == 110 )
            #             sub_5F0BC0((volatile signed __int32 *)dword_F3554C);
            #         }
            #         if ( sub_535C90(dword_E81024) )
            #         {
            #           v17 = _EDI[1521];
            #           if ( v17 != 100 || LOBYTE(a5) != 111 )
            #           {
            #             if ( v17 == 111 && (LOBYTE(a5) == 100 || LOBYTE(a5) == 110) )
            #             {
            #               _EDI[1521] = LOBYTE(a5);
            #               result = sub_5CA0D0((int)_EDI, v15, a7, a8, result, a6, st6_0, (int)(_EDI + 100), 0);
            #               if ( !v27 )
            #                 goto LABEL_62;
            #               __asm
            #               {
            #                 fld     dword ptr [edi+6Ch]
            #                 fstp    [esp+2Ch+arg_0]
            #                 fld     dword ptr [edi+138h]
            #                 fstp    [esp+2Ch+var_1C]
            #               }
            #               _EAX = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI);
            #               __asm
            #               {
            #                 fld     dword ptr [eax+12C0h]
            #                 fsub    [esp+2Ch+arg_0]
            #                 fcomp   [esp+2Ch+var_1C]
            #                 fnstsw  ax
            #               }
            #               if ( !__SETP__(BYTE1(_EAX) & 5, 0) )
            #               {
            # LABEL_62:
            #                 _EDI[1521] = 111;
            #                 return result;
            #               }
            #               _EDI[1521] = 111;
            #             }
            #           }
            #           else
            #           {
            #             _ESI = (int)(_EDI + 100);
            #             _EDI[1521] = 111;
            #             result = sub_5CA0D0((int)_EDI, v15, a7, a8, result, a6, st6_0, (int)(_EDI + 100), 0);
            #             if ( !v19 )
            #               goto LABEL_63;
            #             __asm
            #             {
            #               fld     dword ptr [edi+6Ch]
            #               fstp    [esp+2Ch+arg_0]
            #               fld     dword ptr [edi+138h]
            #               fstp    [esp+2Ch+var_1C]
            #             }
            #             _EAX = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI);
            #             __asm
            #             {
            #               fld     dword ptr [eax+12C0h]
            #               fsub    [esp+2Ch+arg_0]
            #               fcomp   [esp+2Ch+var_1C]
            #               fnstsw  ax
            #             }
            #             if ( __SETP__(BYTE1(_EAX) & 5, 0) )
            #             {
            #               _EDI[1521] = 100;
            #             }
            #             else
            #             {
            # LABEL_63:
            #               v23 = *(_DWORD *)_EDI;
            #               _EDI[1521] = 100;
            #               (*(void (__thiscall **)(_BYTE *))(v23 + 148))(_EDI);
            #               __asm
            #               {
            #                 fadd    dword ptr [esi+8]
            #                 fstp    dword ptr [esi+8]
            #               }
            #               *((float *)_EDI + 27) = _ET1;
            #               if ( *((_DWORD *)_EDI + 1093) )
            #               {
            #                 _EAX = sub_486C50((float *)_EDI + 997);
            #                 __asm
            #                 {
            #                   fld     dword ptr [eax]
            #                   fstp    [esp+2Ch+var_18]
            #                   fld     dword ptr [eax+4]
            #                   fstp    [esp+2Ch+var_14]
            #                   fld     dword ptr [eax+8]
            #                 }
            #                 v26 = *(_DWORD *)_EDI;
            #                 __asm { fstp    [esp+2Ch+var_10] }
            #                 (*(void (__thiscall **)(_BYTE *))(v26 + 148))(_EDI);
            #                 __asm
            #                 {
            #                   fadd    [esp+2Ch+var_10]
            #                   fstp    [esp+30h+var_10]
            #                 }
            #                 result = sub_486BA0(&v65);
            #               }
            #             }
            #           }
            #         }
            #       }
            #       if ( v15 )
            #       {
            #         LOWORD(v68) = *((_WORD *)_EDI + 168);
            #         HIWORD(v68) = 14;
            #         if ( *(_DWORD *)dword_E81230 )
            #         {
            #           word_E81030 = sub_89C850(6241, 0);
            #           dword_E81032 = v68;
            #           qword_E81036 = v12;
            #           v22 = sub_83D500(*(int *)dword_E81230, 4, &word_E81030, 0xEu);
            #           j_j_j___free_base(0);
            #           --dword_1071B24;
            #           if ( !v22 )
            #             sub_4EAE80((_DWORD *)dword_C9CD3C, (LPCRITICAL_SECTION **)dword_E81230);
            #         }
            #         else if ( !byte_E90BC4 )
            #         {
            #           sub_8EE420("Attempt to send message %d on a void connection.", 6241);
            #         }
            #         *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v15 + 8) + 4) + v15 + 364) = v12;
            #       }
            #       switch ( v12 )
            #       {
            #         case 0x64u:
            #           v35 = _EDI[1521];
            #           if ( v35 == 111 )
            #           {
            #             v41 = (_DWORD *)(*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)_EDI + 68))(_EDI, v63, v64);
            #             v37 = sub_64E270(v41);
            #             __asm { fld1 }
            #             v66 = 0.0;
            #             v65 = 255;
            #             __asm { fstp    [esp+20h+var_20] }
            #             goto LABEL_58;
            #           }
            #           if ( v35 == 105 || *(_DWORD *)((*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI) + 4536) == 36 )
            #           {
            #             v39 = (_DWORD *)(*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)_EDI + 68))(_EDI, v63, v64);
            #             v37 = sub_64E270(v39);
            #             __asm { fld1 }
            #             v66 = 0.0;
            #             v65 = 255;
            #             __asm { fstp    [esp+20h+var_20] }
            #             goto LABEL_58;
            #           }
            #           if ( _EDI[1521] != 102 )
            #           {
            #             v36 = (_DWORD *)(*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)_EDI + 68))(_EDI, v63, v64);
            #             v37 = sub_64E270(v36);
            #             __asm { fld1 }
            #             v66 = 0.0;
            #             v65 = 255;
            #             __asm { fstp    [esp+20h+var_20] }
            #             goto LABEL_58;
            #           }
            #           break;
            #         case 0x69u:
            #           v43 = (_DWORD *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI);
            #           v44 = sub_64E270(v43);
            #           __asm
            #           {
            #             fld1
            #             fstp    [esp+3Ch+var_3C]
            #           }
            #           (*(void (__thiscall **)(int, signed int, signed int, _DWORD, _DWORD, signed int, signed int, _DWORD))(*(_DWORD *)v44 + 12))(
            #             v44,
            #             36,
            #             1,
            #             0,
            #             LODWORD(v45),
            #             1,
            #             255,
            #             0);
            #           __asm
            #           {
            #             fldz
            #             fst     dword ptr [edi+7Ch]
            #           }
            #           *((float *)_EDI + 31) = _ET1;
            #           __asm { fstp    dword ptr [edi+8Ch] }
            #           *((float *)_EDI + 35) = _ET1;
            #           break;
            #         case 0x6Eu:
            #           v30 = (_DWORD *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI);
            #           v31 = sub_64E270(v30);
            #           __asm
            #           {
            #             fld1
            #             fstp    [esp+3Ch+var_3C]
            #           }
            #           (*(void (__thiscall **)(int, signed int, signed int, _DWORD, _DWORD, signed int, signed int, _DWORD))(*(_DWORD *)v31 + 12))(
            #             v31,
            #             33,
            #             1,
            #             0,
            #             LODWORD(v32),
            #             1,
            #             255,
            #             0);
            #           __asm
            #           {
            #             fldz
            #             fst     dword ptr [edi+7Ch]
            #           }
            #           *((float *)_EDI + 31) = _ET1;
            #           __asm { fstp    dword ptr [edi+8Ch] }
            #           *((float *)_EDI + 35) = _ET1;
            #           *((_DWORD *)_EDI + 270) = *((_DWORD *)dword_E81024 + 85);
            #           break;
            #         case 0x6Fu:
            #           if ( *(_DWORD *)((*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI) + 4536) != 24
            #             && *(_DWORD *)((*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI) + 4536) != 22 )
            #           {
            #             v59 = (_DWORD *)(*(int (__thiscall **)(_BYTE *, int, int))(*(_DWORD *)_EDI + 68))(_EDI, v63, v64);
            #             v37 = sub_64E270(v59);
            #             __asm { fld1 }
            #             v66 = 0.0;
            #             v65 = 255;
            #             __asm { fstp    [esp+20h+var_20] }
            # LABEL_58:
            #             (*(void (__thiscall **)(int))(*(_DWORD *)v37 + 12))(v37);
            #           }
            #           break;
            #         case 0x73u:
            #           if ( sub_986BD0(_EDI) )
            #           {
            #             (*(void (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 96))(_EDI);
            #             if ( dword_E81020 )
            #             {
            #               if ( dword_E81244 == _EDI )
            #               {
            #                 v48 = sub_4BBEF0(113, 0, 0);
            #                 result = sub_4BC300(v48, 0, 0);
            #               }
            #             }
            #           }
            #           if ( *(_DWORD *)((*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI) + 4536) != 16 )
            #           {
            #             v49 = (_DWORD *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI);
            #             v50 = sub_64E270(v49);
            #             __asm
            #             {
            #               fld1
            #               fstp    [esp+3Ch+var_3C]
            #             }
            #             (*(void (__thiscall **)(int, signed int, signed int, _DWORD, _DWORD, signed int, signed int, _DWORD))(*(_DWORD *)v50 + 12))(
            #               v50,
            #               16,
            #               1,
            #               0,
            #               LODWORD(v51),
            #               1,
            #               255,
            #               0);
            #             v52 = (_DWORD *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI);
            #             if ( sub_64E1B0(v52) )
            #             {
            #               if ( *((_DWORD *)_EDI + 1093) )
            #               {
            #                 v53 = *((_DWORD *)_EDI + 1093);
            #                 v54 = (_DWORD *)(*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI);
            #                 v55 = sub_64E1B0(v54);
            #                 v56 = sub_47F3A0(v55, result, v53) + *((_DWORD *)dword_E81024 + 85);
            #                 *(_DWORD *)((*(int (__thiscall **)(_BYTE *))(*(_DWORD *)_EDI + 68))(_EDI) + 4768) = v56;
            #               }
            #             }
            #           }
            #           __asm
            #           {
            #             fldz
            #             fst     dword ptr [edi+7Ch]
            #           }
            #           *((float *)_EDI + 31) = _ET1;
            #           __asm { fstp    dword ptr [edi+8Ch] }
            #           *((float *)_EDI + 35) = _ET1;
            #           break;
            #         default:
            #           break;
            #       }
            #       v61 = *(_DWORD *)_EDI;
            #       _EDI[1521] = v12;
            #       v62 = (_DWORD *)(*(int (__thiscall **)(_BYTE *))(v61 + 68))(_EDI);
            #       sub_64A2C0(v62);
            #     }
            #   }
            #   return result;
            # }
            if functionString.find(", 0x30D1u,") != -1 or functionString.find(", 12497,") != -1:    # 12497 Your attempt to apply poison has been cancelled.
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
                    matches = re.findall("sub_([0-9A-F]+)\([0-9a-z]+\);\n\s+sub_[0-9A-F]+\((?:.*?)?&[0-9a-z]+, (?:.*?)?\" \(Lvl: %d\)\", [0-9a-z]+\);", functionString, re.MULTILINE)
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
                matches = re.findall("[0-9a-z]+ = 0.0;\n\s+sub_[0-9A-F]+\(\(float \*\)\w+, 0.0, 1.0\);\n\s+[0-9a-z]+ = (?:.*?)?sub_([0-9A-F]+)\(\(char \*\)\w+\);\n\s+if \( sub_[0-9A-F]+\([0-9a-z]+\) \)", functionString, re.MULTILINE)
                if matches:
                    functionList["EQPlayer__GetActorClient"] = "0x00" + matches[0]

            # EQPlayer__FollowPlayerAI
            # ----------------------------------------------------------------------------------------------------
            if functionString.find(", 0x3194u,") != -1 or functionString.find(", 12692,") != -1:    # 12692 %1 is dead, canceling auto-follow.
                if functionString.find(", 0x3195u,") != -1 or functionString.find(", 12693,") != -1:    # 12693 %1 is too far away, canceling auto-follow.
                    if functionString.find("> 200.0") != -1:
                        if functionString.find(">= 20.0") != -1:
                            if functionString.find("+ 15.0 <=") != -1:
                                if functionString.find("+ 30.0 <=") != -1:
                                    functionList["EQPlayer__FollowPlayerAI"] = functionAddress

            # EQPlayer__TurnOffAutoFollow
            # ----------------------------------------------------------------------------------------------------
            if functionString.find(", 0x3196u,") != -1 or functionString.find(", 12694,") != -1:    # 12694 You are no longer auto-following %1.
                if functionString.find("= 0.0;") != -1:
                    if functionString.find("= 0;") != -1:
                        if functionString.find("= 1;") != -1:
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
            # void __stdcall sub_604990(int a1)
            # {
            #   signed int v1; // eax
            #   int v2; // eax
            #   void *v3; // esi
            #   char *v4; // ST04_4
            #
            #   v1 = sub_630380(dword_E81020, a1);
            #   v2 = sub_6513F0((_DWORD **)dword_F32B08, v1);
            #   v3 = (void *)v2;
            #   if ( v2 )
            #   {
            #     if ( !sub_987110(v2) || sub_658DE0((int *)dword_E81244, (int *)v3, 1) )    # 0x00987110
            #     {
            #       v4 = (char *)sub_8B4830(dword_E81028, 303, 0);
            #       sub_4E4FB0();
            #       sub_4E56A0(v4, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #     }
            #     else
            #     {
            #       dword_E81318 = v3;
            #     }
            #   }
            # }
            if functionString.find(", 0x12Fu,") != -1 or functionString.find(", 303,") != -1:    # 303 I don't see anyone by that name around here...
                matches = re.findall("if \( \!sub_([0-9A-F]+)\([0-9a-z]+\) \|\| sub_[0-9A-F]+\(\(int \*\)dword_[0-9A-F]+, \(int \*\)[0-9a-z]+, 1\) \)", functionString, re.MULTILINE)
                if matches:
                    functionList["EQPlayer__IsTargetable"] = "0x00" + matches[0]

            # EQPlayer__SetNameSpriteState
            # ----------------------------------------------------------------------------------------------------
            # (*(void (__stdcall **)(_DWORD, char *, char *))(*(_DWORD *)v177 + 400))(0, v185, &v190);
            # 400 = CActorInterface->ChangeBoneStringSprite() virtual function
            # ----------------------------------------------------------------------------------------------------
            # signed int __thiscall sub_6462F0(_BYTE *this, char a2)
            # {
            #   _BYTE *v2; // ebx
            #   int v3; // ecx
            #   int v4; // ecx
            #   int v6; // eax
            #   int v7; // ecx
            #   int v8; // ecx
            #   char v9; // al
            #   int v10; // esi
            #   char *v11; // eax
            #   int v12; // ecx
            #   char *v13; // eax
            #   void *v14; // ST18_4
            #   unsigned __int8 v15; // al
            #   int v16; // eax
            #   char *v17; // ecx
            #   char v18; // al
            #   unsigned int v19; // eax
            #   const char *v20; // esi
            #   unsigned int v21; // edx
            #   char *v22; // edi
            #   char v23; // al
            #   char *v24; // edi
            #   char v25; // al
            #   __int16 v26; // ax
            #   const char *v27; // esi
            #   unsigned int v28; // edx
            #   char *v29; // edi
            #   char v30; // al
            #   char *v31; // edi
            #   char v32; // al
            #   char *v33; // ebp
            #   const char *v34; // esi
            #   unsigned int v35; // edx
            #   char *v36; // edi
            #   char v37; // al
            #   char v38; // al
            #   const char *v39; // esi
            #   unsigned int v40; // edx
            #   char *v41; // edi
            #   char v42; // al
            #   char v43; // al
            #   unsigned int v44; // edx
            #   char *v45; // edi
            #   char v46; // cl
            #   char v47; // cl
            #   char *v48; // edi
            #   char v49; // cl
            #   unsigned int v50; // edx
            #   char *v51; // edi
            #   char v52; // cl
            #   char *v53; // esi
            #   int v54; // ecx
            #   char *v55; // edi
            #   char v56; // cl
            #   unsigned int v57; // edx
            #   char *v58; // edi
            #   char v59; // cl
            #   char *v60; // esi
            #   int v61; // ecx
            #   char *v62; // edi
            #   char v63; // cl
            #   _DWORD *v64; // ecx
            #   const char *v65; // esi
            #   unsigned int v66; // edx
            #   char *v67; // edi
            #   char v68; // al
            #   const char *v69; // esi
            #   int v70; // ecx
            #   char *v71; // edi
            #   char v72; // al
            #   const char *v73; // esi
            #   unsigned int v74; // edx
            #   char *v75; // edi
            #   char v76; // al
            #   char v77; // ch
            #   char *v78; // edi
            #   char v79; // cl
            #   char v80; // al
            #   const char *v81; // esi
            #   int v82; // ecx
            #   const char *v83; // esi
            #   unsigned int v84; // edx
            #   char *v85; // edi
            #   char v86; // al
            #   const char *v87; // esi
            #   int v88; // ecx
            #   const char *v89; // esi
            #   unsigned int v90; // edx
            #   char *v91; // edi
            #   char v92; // al
            #   const char *v93; // esi
            #   int v94; // ecx
            #   const char *v95; // esi
            #   unsigned int v96; // edx
            #   char *v97; // edi
            #   char v98; // al
            #   const char *v99; // esi
            #   int v100; // ecx
            #   signed int v101; // eax
            #   unsigned int v102; // edx
            #   char *v103; // edi
            #   char v104; // al
            #   char *v105; // esi
            #   int v106; // ecx
            #   int v107; // edx
            #   char *v108; // ecx
            #   char v109; // al
            #   const char *v110; // esi
            #   unsigned int v111; // edx
            #   char *v112; // edi
            #   char v113; // al
            #   const char *v114; // esi
            #   int v115; // ecx
            #   char *v116; // edi
            #   char v117; // al
            #   signed __int16 v118; // ax
            #   _DWORD *v119; // ebp
            #   int v120; // ecx
            #   signed int v121; // edx
            #   _DWORD *v122; // eax
            #   signed int v123; // edx
            #   _DWORD *v124; // eax
            #   char *v125; // edi
            #   char v126; // al
            #   signed int v127; // esi
            #   _DWORD *v128; // edx
            #   signed int v129; // eax
            #   signed int v130; // eax
            #   _DWORD *v131; // edx
            #   unsigned int v132; // edx
            #   char *v133; // edi
            #   char v134; // al
            #   char *v135; // edi
            #   char v136; // al
            #   unsigned int v137; // edx
            #   char *v138; // edi
            #   char v139; // al
            #   char *v140; // esi
            #   int v141; // ecx
            #   char *v142; // edi
            #   char v143; // al
            #   unsigned int v144; // edx
            #   char *v145; // edi
            #   char v146; // al
            #   char *v147; // esi
            #   int v148; // ecx
            #   int v149; // eax
            #   _DWORD *v150; // ecx
            #   signed int v151; // edx
            #   signed int v152; // edx
            #   _DWORD *v153; // ecx
            #   signed int v154; // edx
            #   _DWORD *v155; // ecx
            #   signed int v156; // edx
            #   _DWORD *v157; // ecx
            #   unsigned int v158; // edx
            #   char *v159; // edi
            #   char v160; // al
            #   char *v161; // esi
            #   int v162; // ecx
            #   char *v163; // edi
            #   char v164; // al
            #   char *v165; // eax
            #   char *v166; // edx
            #   char v167; // cl
            #   char *v168; // ecx
            #   char v169; // al
            #   char v170; // cl
            #   char *v171; // ecx
            #   char v172; // al
            #   unsigned int v173; // edx
            #   char *v174; // edi
            #   char v175; // al
            #   char *v176; // esi
            #   int v177; // ecx
            #   char v178; // al
            #   int v179; // ecx
            #   int v180; // edx
            #   char v181; // al
            #   char v182; // [esp+20h] [ebp-28B8h]
            #   char v183; // [esp+33h] [ebp-28A5h]
            #   char v184; // [esp+33h] [ebp-28A5h]
            #   char v185; // [esp+34h] [ebp-28A4h]
            #   char v186[32]; // [esp+38h] [ebp-28A0h]
            #   char v187[512]; // [esp+58h] [ebp-2880h]
            #   char v188[128]; // [esp+258h] [ebp-2680h]
            #   char v189; // [esp+2D8h] [ebp-2600h]
            #   char v190; // [esp+4D8h] [ebp-2400h]
            #   char v191; // [esp+8D7h] [ebp-2001h]
            #   char v192; // [esp+8D8h] [ebp-2000h]
            #
            #   v2 = this;
            #   if ( !this[4912] )
            #     return 0;
            #   if ( !sub_535C90(dword_E81024) )
            #   {
            #     v3 = *((_DWORD *)v2 + 1093);
            #     if ( v3 && (*(unsigned __int8 (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 424))(0) )
            #     {
            #       v4 = *((_DWORD *)v2 + 1093);
            #       if ( v4 )
            #       {
            #         v192 = 0;
            #         (*(void (__stdcall **)(_DWORD, _DWORD, char *))(*(_DWORD *)v4 + 400))(0, 0, &v192);
            #       }
            #     }
            #     return 0;
            #   }
            #   if ( v2[293]
            #     && (*(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C14748
            #      && !*((_DWORD *)v2 + 279)
            #      || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C1493C
            #      && !*((_DWORD *)v2 + 279)
            #      || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C149E0
            #      && !*((_DWORD *)v2 + 279)
            #      || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C149E4
            #      && !*((_DWORD *)v2 + 279)
            #      || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C146F4
            #      || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C14738
            #      || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C14918
            #      || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C148FC
            #      || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C14738) )
            #   {
            #     if ( (*(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C14748
            #        || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C149E0
            #        || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C149E4)
            #       && *((_DWORD *)v2 + 1134) == 16
            #       || (v6 = *((_DWORD *)v2 + 1134), v6 == 33)
            #       || v6 == 38
            #       || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C148FC
            #       || *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(*(_DWORD *)v2 + 136))(v2, &v185) == dword_C14738 )
            #     {
            #       v7 = *((_DWORD *)v2 + 1093);
            #       if ( !v7 || !(*(unsigned __int8 (__stdcall **)(_DWORD))(*(_DWORD *)v7 + 424))(0) )
            #         return 1;
            # LABEL_32:
            #       v8 = *((_DWORD *)v2 + 1093);
            #       if ( v8 )
            #       {
            #         v192 = 0;
            #         (*(void (__stdcall **)(_DWORD, _DWORD, char *))(*(_DWORD *)v8 + 400))(0, 0, &v192);
            #       }
            #       return 1;
            #     }
            #   }
            #   v9 = v2[896];
            #   v188[0] = 0;
            #   if ( v9 )
            #     sub_8EE5B0(v188, "!", 0x80u);
            #   v10 = (int)(v2 + 164);
            #   v11 = (char *)sub_5F5C40((_DWORD *)dword_F3554C, (_WORD)v2 + 164);
            #   sub_8EE5B0(v188, v11, 0x80u);
            #   v12 = *((_DWORD *)v2 + 1093);
            #   if ( !v12 || !(*(unsigned __int8 (__stdcall **)(_DWORD))(*(_DWORD *)v12 + 424))(0) )
            #     return 0;
            #   if ( dword_DCE92C && *(_DWORD *)(dword_F3554C + 1480) == 1 )
            #   {
            #     if ( *((_DWORD *)v2 + 336) > 1000 && sub_8C36D0((_DWORD *)dword_E80E88, *((_DWORD *)v2 + 336)) )
            #     {
            #       v13 = (char *)sub_8C36D0((_DWORD *)dword_E80E88, *((_DWORD *)v2 + 336));
            #       sub_8EE5E0(&v189, v13, 0x200u);
            #     }
            #     else
            #     {
            #       sub_8C3710((_DWORD *)dword_E80E88, *((_DWORD *)v2 + 336), (int)&v189, 0);
            #     }
            #     v14 = sub_5EFB50(*((_DWORD *)v2 + 1003));
            #     v15 = sub_65B860(v2);
            #     sub_480D30((int)&v190, "%s [%d %s]\n%s", v2 + 164, v15, v14, &v189);
            #     sub_64E610(v2, 0, &v190);
            #     sub_6471C0(v2, (int)v2, v10, v182);
            #     return 1;
            #   }
            #   if ( !a2 || dword_E91FAC <= 0 && v2[293] != 1 )
            #     goto LABEL_32;
            #   v16 = *(_DWORD *)v2;
            #   v187[0] = 0;
            #   if ( *(_DWORD *)(*(int (__thiscall **)(_BYTE *, char *))(v16 + 136))(v2, &v185) >= dword_C14A2C )
            #   {
            #     v17 = &v187[-v10];
            #     do
            #     {
            #       v18 = *(_BYTE *)v10++;
            #       v17[v10 - 1] = v18;
            #     }
            #     while ( v18 );
            #     goto LABEL_248;
            #   }
            #   if ( !v2[293] )
            #   {
            #     v183 = 1;
            #     if ( !v2[8232] || (v19 = *((_DWORD *)v2 + 212)) != 0 && !((v19 >> 1) & 1) )
            #       v183 = 0;
            #     if ( v2[620] )
            #     {
            #       v20 = (const char *)sub_8B4830(dword_E81028, 766, 0);
            #       v21 = strlen(v20) + 1;
            #       v22 = &v186[31];
            #       do
            #         v23 = (v22++)[1];
            #       while ( v23 );
            #       qmemcpy(v22, v20, v21);
            #       v24 = &v186[31];
            #       do
            #         v25 = (v24++)[1];
            #       while ( v25 );
            #       v26 = *(_WORD *)" ";
            #       strcpy(v24, " ");
            #     }
            #     else
            #     {
            #       v26 = *(_WORD *)" ";
            #     }
            #     if ( *((_DWORD *)v2 + 373) == 1 )
            #     {
            #       v27 = (const char *)sub_8B4830(dword_E81028, 5503, 0);
            #       v28 = strlen(v27) + 1;
            #       v29 = &v186[31];
            #       do
            #         v30 = (v29++)[1];
            #       while ( v30 );
            #       qmemcpy(v29, v27, v28);
            #       v31 = &v186[31];
            #       do
            #         v32 = (v31++)[1];
            #       while ( v32 );
            #       v26 = *(_WORD *)" ";
            #       v33 = (char *)dword_1053AB0;
            #     }
            #     else if ( *((_DWORD *)v2 + 231) == 1 )
            #     {
            #       v34 = (const char *)sub_8B4830(dword_E81028, 6055, 0);
            #       v35 = strlen(v34) + 1;
            #       v36 = &v186[31];
            #       do
            #         v37 = (v36++)[1];
            #       while ( v37 );
            #       qmemcpy(v36, v34, v35);
            #       v31 = &v186[31];
            #       do
            #         v38 = (v31++)[1];
            #       while ( v38 );
            #       v26 = *(_WORD *)" ";
            #       v33 = (char *)dword_1053AB0;
            #     }
            #     else
            #     {
            #       v33 = (char *)dword_1053AB0;
            #       if ( v2 == dword_E81244 && dword_1053AB0 && *(_BYTE *)(dword_1053AB0 + 208) )
            #       {
            #         if ( !sub_816F20((char *)dword_1053AB0) )
            #         {
            #           v26 = *(_WORD *)" ";
            #           v33 = (char *)dword_1053AB0;
            #           goto LABEL_94;
            #         }
            #         v39 = (const char *)sub_816F20((char *)dword_1053AB0);
            #         v40 = strlen(v39) + 1;
            #         v41 = &v186[31];
            #         do
            #           v42 = (v41++)[1];
            #         while ( v42 );
            #         qmemcpy(v41, v39, v40);
            #         v31 = &v186[31];
            #         do
            #           v43 = (v31++)[1];
            #         while ( v43 );
            #         v26 = *(_WORD *)" ";
            #         v33 = (char *)dword_1053AB0;
            #       }
            #       else
            #       {
            #         if ( dword_E91FAC <= 3 || !v2[449] )
            #           goto LABEL_94;
            #         v44 = strlen(v2 + 449) + 1;
            #         v45 = &v186[31];
            #         do
            #           v46 = (v45++)[1];
            #         while ( v46 );
            #         qmemcpy(v45, v2 + 449, v44);
            #         v31 = &v186[31];
            #         do
            #           v47 = (v31++)[1];
            #         while ( v47 );
            #       }
            #     }
            #     *(_WORD *)v31 = v26;
            # LABEL_94:
            #     if ( *((_DWORD *)v2 + 387) <= 0 )
            #     {
            #       v57 = strlen(v188) + 1;
            #       v58 = &v186[31];
            #       do
            #         v59 = (v58++)[1];
            #       while ( v59 );
            #       qmemcpy(v58, v188, 4 * (v57 >> 2));
            #       v60 = &v188[4 * (v57 >> 2)];
            #       v61 = v57 & 3;
            #       qmemcpy(&v58[4 * (v57 >> 2)], v60, v61);
            #       v10 = (int)&v60[v61];
            #     }
            #     else
            #     {
            #       v48 = &v186[31];
            #       do
            #         v49 = (v48++)[1];
            #       while ( v49 );
            #       strcpy(v48, "(");
            #       v50 = strlen(v188) + 1;
            #       v51 = &v186[31];
            #       do
            #         v52 = (v51++)[1];
            #       while ( v52 );
            #       qmemcpy(v51, v188, 4 * (v50 >> 2));
            #       v53 = &v188[4 * (v50 >> 2)];
            #       v54 = v50 & 3;
            #       qmemcpy(&v51[4 * (v50 >> 2)], v53, v54);
            #       v10 = (int)&v53[v54];
            #       v55 = &v186[31];
            #       do
            #         v56 = (v55++)[1];
            #       while ( v56 );
            #       *(_WORD *)v55 = 41;
            #     }
            #     if ( dword_E91FAC == 2 || dword_E91FAC == 3 || dword_E91FAC == 4 || dword_E91FAC == 6 )
            #     {
            #       v10 = (int)(v2 + 56);
            #       if ( &v2[strlen(v2 + 56) + 57] != v2 + 57 )
            #       {
            #         v62 = &v186[31];
            #         do
            #           v63 = (v62++)[1];
            #         while ( v63 );
            #         v64 = (_DWORD *)dword_F3554C;
            #         *(_WORD *)v62 = v26;
            #         v65 = (const char *)sub_5F5C40(v64, (_WORD)v2 + 56);
            #         v66 = strlen(v65) + 1;
            #         v67 = &v186[31];
            #         do
            #           v68 = (v67++)[1];
            #         while ( v68 );
            #         v26 = *(_WORD *)" ";
            #         v33 = (char *)dword_1053AB0;
            #         qmemcpy(v67, v65, 4 * (v66 >> 2));
            #         v69 = &v65[4 * (v66 >> 2)];
            #         v70 = v66 & 3;
            #         qmemcpy(&v67[4 * (v66 >> 2)], v69, v70);
            #         v10 = (int)&v69[v70];
            #       }
            #     }
            #     if ( v2 == dword_E81244 && v33 && v33[208] )
            #     {
            #       if ( !sub_816F30(v33) )
            #       {
            # LABEL_137:
            #         if ( v2[1256] )
            #         {
            #           v83 = (const char *)sub_8B4830(dword_E81028, 12314, 0);
            #           v84 = strlen(v83) + 1;
            #           v85 = &v186[31];
            #           do
            #             v86 = (v85++)[1];
            #           while ( v86 );
            #           qmemcpy(v85, v83, 4 * (v84 >> 2));
            #           v87 = &v83[4 * (v84 >> 2)];
            #           v88 = v84 & 3;
            #           qmemcpy(&v85[4 * (v84 >> 2)], v87, v88);
            #           v10 = (int)&v87[v88];
            #         }
            #         if ( !sub_4E20E0(v2) )
            #         {
            #           if ( *((_DWORD *)v2 + 218) )
            #           {
            #             v89 = (const char *)sub_8B4830(dword_E81028, 12311, 0);
            #             v90 = strlen(v89) + 1;
            #             v91 = &v186[31];
            #             do
            #               v92 = (v91++)[1];
            #             while ( v92 );
            #             qmemcpy(v91, v89, 4 * (v90 >> 2));
            #             v93 = &v89[4 * (v90 >> 2)];
            #             v94 = v90 & 3;
            #             qmemcpy(&v91[4 * (v90 >> 2)], v93, v94);
            #             v10 = (int)&v93[v94];
            #           }
            #           if ( v2[1332] )
            #           {
            #             v95 = (const char *)sub_8B4830(dword_E81028, 2240, 0);
            #             v96 = strlen(v95) + 1;
            #             v97 = &v186[31];
            #             do
            #               v98 = (v97++)[1];
            #             while ( v98 );
            #             qmemcpy(v97, v95, 4 * (v96 >> 2));
            #             v99 = &v95[4 * (v96 >> 2)];
            #             v100 = v96 & 3;
            #             qmemcpy(&v97[4 * (v96 >> 2)], v99, v100);
            #             v10 = (int)&v99[v100];
            #           }
            #         }
            #         if ( BYTE2(dword_E920FC) && dword_E81318 == v2 )
            #         {
            #           if ( dword_E81318 == dword_E81244 )
            #           {
            #             v101 = sub_650D70(*((_QWORD *)dword_E81318 + 103), *((_QWORD *)dword_E81318 + 122));
            #             sub_480D30((int)v186, " - %d%%", v101);
            #           }
            #           else
            #           {
            #             sub_480D30((int)v186, " - %lld%%", *((_QWORD *)dword_E81318 + 103));
            #           }
            #           v102 = strlen(v186) + 1;
            #           v103 = &v186[31];
            #           do
            #             v104 = (v103++)[1];
            #           while ( v104 );
            #           qmemcpy(v103, v186, 4 * (v102 >> 2));
            #           v105 = &v186[4 * (v102 >> 2)];
            #           v106 = v102 & 3;
            #           qmemcpy(&v103[4 * (v102 >> 2)], v105, v106);
            #           v10 = (int)&v105[v106];
            #         }
            #         if ( dword_E91FAC != 3 && dword_E91FAC != 4 )
            #           goto LABEL_248;
            #         if ( v183 != 1 )
            #           goto LABEL_248;
            #         v107 = *((_DWORD *)v2 + 150);
            #         v10 = *((_DWORD *)v2 + 151);
            #         if ( !*((_QWORD *)v2 + 75) )
            #           goto LABEL_248;
            #         v108 = &v186[31];
            #         do
            #           v109 = (v108++)[1];
            #         while ( v109 );
            #         *(_WORD *)v108 = 15370;
            #         v108[2] = 0;
            #         v110 = sub_4AAC90(dword_E87400, v107, v10);
            #         v111 = strlen(v110) + 1;
            #         v112 = &v186[31];
            #         do
            #           v113 = (v112++)[1];
            #         while ( v113 );
            #         qmemcpy(v112, v110, 4 * (v111 >> 2));
            #         v114 = &v110[4 * (v111 >> 2)];
            #         v115 = v111 & 3;
            #         qmemcpy(&v112[4 * (v111 >> 2)], v114, v115);
            #         v10 = (int)&v114[v115];
            #         v116 = &v186[31];
            #         do
            #           v117 = (v116++)[1];
            #         while ( v117 );
            #         v118 = *(_WORD *)">";
            #         goto LABEL_247;
            #       }
            #       if ( strlen((const char *)sub_816F30((char *)dword_1053AB0)) && *(_BYTE *)sub_816F30((char *)dword_1053AB0) != 44 )
            #       {
            #         v71 = &v186[31];
            #         do
            #           v72 = (v71++)[1];
            #         while ( v72 );
            #         strcpy(v71, " ");
            #       }
            #       v73 = (const char *)sub_816F30((char *)dword_1053AB0);
            #       v74 = strlen(v73) + 1;
            #       v75 = &v186[31];
            #       do
            #         v76 = (v75++)[1];
            #       while ( v76 );
            #     }
            #     else
            #     {
            #       if ( dword_E91FAC <= 3 )
            #         goto LABEL_137;
            #       v77 = v2[1356];
            #       if ( !v77 )
            #         goto LABEL_137;
            #       if ( &v2[strlen(v2 + 1356) + 1357] != v2 + 1357 && v77 != 44 )
            #       {
            #         v78 = &v186[31];
            #         do
            #           v79 = (v78++)[1];
            #         while ( v79 );
            #         *(_WORD *)v78 = v26;
            #       }
            #       v73 = v2 + 1356;
            #       v74 = strlen(v2 + 1356) + 1;
            #       v75 = &v186[31];
            #       do
            #         v80 = (v75++)[1];
            #       while ( v80 );
            #     }
            #     qmemcpy(v75, v73, 4 * (v74 >> 2));
            #     v81 = &v73[4 * (v74 >> 2)];
            #     v82 = v74 & 3;
            #     qmemcpy(&v75[4 * (v74 >> 2)], v81, v82);
            #     v10 = (int)&v81[v82];
            #     goto LABEL_137;
            #   }
            #   v184 = 0;
            #   sub_480D30((int)v187, Directory);
            #   v119 = dword_E81244;
            #   v120 = *((_DWORD *)v2 + 84);
            #   v121 = 0;
            #   v122 = (char *)dword_E81244 + 3896;
            #   while ( *v122 != v120 )
            #   {
            #     ++v121;
            #     ++v122;
            #     if ( v121 >= 1 )
            #     {
            #       v123 = 0;
            #       v124 = (char *)dword_E81244 + 3900;
            #       while ( *v124 != v120 )
            #       {
            #         ++v123;
            #         ++v124;
            #         if ( v123 >= 3 )
            #           goto LABEL_179;
            #       }
            #       break;
            #     }
            #   }
            #   v184 = 1;
            #   v125 = &v186[31];
            #   do
            #     v126 = (v125++)[1];
            #   while ( v126 );
            #   *(_DWORD *)v125 = 2113086;
            # LABEL_179:
            #   v127 = -1;
            #   v128 = v119 + 978;
            #   v129 = 0;
            #   while ( *v128 != v120 )
            #   {
            #     ++v129;
            #     ++v128;
            #     if ( v129 >= 3 )
            #       goto LABEL_184;
            #   }
            #   v127 = v129;
            # LABEL_184:
            #   v130 = 0;
            #   v131 = v119 + 981;
            #   while ( *v131 != v120 )
            #   {
            #     ++v130;
            #     ++v131;
            #     if ( v130 >= 3 )
            #       goto LABEL_189;
            #   }
            #   v127 = v130;
            # LABEL_189:
            #   if ( v127 != -1 )
            #   {
            #     sub_480D30((int)v186, "%d - ", v127 + 1);
            #     v132 = strlen(v186) + 1;
            #     v133 = &v186[31];
            #     do
            #       v134 = (v133++)[1];
            #     while ( v134 );
            #     v119 = dword_E81244;
            #     qmemcpy(v133, v186, v132);
            #   }
            #   if ( *((_DWORD *)v2 + 387) <= 0 || v2[293] != 1 )
            #   {
            #     v144 = strlen(v188) + 1;
            #     v145 = &v186[31];
            #     do
            #       v146 = (v145++)[1];
            #     while ( v146 );
            #     qmemcpy(v145, v188, 4 * (v144 >> 2));
            #     v147 = &v188[4 * (v144 >> 2)];
            #     v148 = v144 & 3;
            #     qmemcpy(&v145[4 * (v144 >> 2)], v147, v148);
            #     v10 = (int)&v147[v148];
            #   }
            #   else
            #   {
            #     v135 = &v186[31];
            #     do
            #       v136 = (v135++)[1];
            #     while ( v136 );
            #     strcpy(v135, "(");
            #     v137 = strlen(v188) + 1;
            #     v138 = &v186[31];
            #     do
            #       v139 = (v138++)[1];
            #     while ( v139 );
            #     qmemcpy(v138, v188, 4 * (v137 >> 2));
            #     v140 = &v188[4 * (v137 >> 2)];
            #     v141 = v137 & 3;
            #     qmemcpy(&v138[4 * (v137 >> 2)], v140, v141);
            #     v10 = (int)&v140[v141];
            #     v142 = &v186[31];
            #     do
            #       v143 = (v142++)[1];
            #     while ( v143 );
            #     *(_WORD *)v142 = 41;
            #   }
            #   if ( BYTE2(dword_E920FC) )
            #   {
            #     if ( dword_E81318 != v2 )
            #     {
            #       v149 = *((_DWORD *)v2 + 84);
            #       v150 = v119 + 974;
            #       v151 = 0;
            #       while ( *v150 != v149 )
            #       {
            #         ++v151;
            #         ++v150;
            #         if ( v151 >= 1 )
            #         {
            #           v152 = 0;
            #           v153 = v119 + 975;
            #           while ( *v153 != v149 )
            #           {
            #             ++v152;
            #             ++v153;
            #             if ( v152 >= 3 )
            #             {
            #               v154 = 0;
            #               v155 = v119 + 978;
            #               while ( *v155 != v149 )
            #               {
            #                 ++v154;
            #                 ++v155;
            #                 if ( v154 >= 3 )
            #                 {
            #                   v156 = 0;
            #                   v157 = v119 + 981;
            #                   while ( *v157 != v149 )
            #                   {
            #                     ++v156;
            #                     ++v157;
            #                     if ( v156 >= 3 )
            #                       goto LABEL_223;
            #                   }
            #                   goto LABEL_220;
            #                 }
            #               }
            #               goto LABEL_220;
            #             }
            #           }
            #           break;
            #         }
            #       }
            #     }
            # LABEL_220:
            #     sub_480D30((int)v186, " - %lld%%", *((_DWORD *)v2 + 206), *((_DWORD *)v2 + 207));
            #     v158 = strlen(v186) + 1;
            #     v159 = &v186[31];
            #     do
            #       v160 = (v159++)[1];
            #     while ( v160 );
            #     qmemcpy(v159, v186, 4 * (v158 >> 2));
            #     v161 = &v186[4 * (v158 >> 2)];
            #     v162 = v158 & 3;
            #     qmemcpy(&v159[4 * (v158 >> 2)], v161, v162);
            #     v10 = (int)&v161[v162];
            #   }
            # LABEL_223:
            #   if ( v184 )
            #   {
            #     v163 = &v186[31];
            #     do
            #       v164 = (v163++)[1];
            #     while ( v164 );
            #     *(_DWORD *)v163 = 3947552;
            #   }
            #   if ( *((_DWORD *)v2 + 279) )
            #   {
            #     v165 = (char *)sub_5F5C40((_DWORD *)dword_F3554C, (_WORD)v2 + 56);
            #     v166 = (char *)(v186 - v165);
            #     do
            #     {
            #       v167 = *v165++;
            #       v165[(_DWORD)v166 - 1] = v167;
            #     }
            #     while ( v167 );
            #   }
            #   else
            #   {
            #     v168 = v2 + 56;
            #     do
            #     {
            #       v169 = *v168;
            #       v168[v186 - (v2 + 56)] = *v168;
            #       ++v168;
            #     }
            #     while ( v169 );
            #   }
            #   if ( v2[293] != 1 || !v186[0] )
            #     goto LABEL_248;
            #   v170 = v2[1552];
            #   if ( !v170 )
            #     goto LABEL_255;
            #   if ( *((_BYTE *)dword_E81024 + 11630) )
            #   {
            # LABEL_240:
            #     v171 = &v186[31];
            #     do
            #       v172 = (v171++)[1];
            #     while ( v172 );
            #     *(_WORD *)v171 = 10250;
            #     v171[2] = 0;
            #     v173 = strlen(v186) + 1;
            #     v174 = &v186[31];
            #     do
            #       v175 = (v174++)[1];
            #     while ( v175 );
            #     qmemcpy(v174, v186, 4 * (v173 >> 2));
            #     v176 = &v186[4 * (v173 >> 2)];
            #     v177 = v173 & 3;
            #     qmemcpy(&v174[4 * (v173 >> 2)], v176, v177);
            #     v10 = (int)&v176[v177];
            #     v116 = &v186[31];
            #     do
            #       v178 = (v116++)[1];
            #     while ( v178 );
            #     v118 = 41;
            # LABEL_247:
            #     *(_WORD *)v116 = v118;
            #     goto LABEL_248;
            #   }
            #   if ( !v170 )
            #   {
            # LABEL_255:
            #     if ( *((_DWORD *)v2 + 279) && *((_BYTE *)dword_E81024 + 11629) != 1 )
            #       goto LABEL_248;
            #     goto LABEL_240;
            #   }
            # LABEL_248:
            #   v179 = *((_DWORD *)v2 + 1093);
            #   if ( v179 )
            #   {
            #     v180 = 0;
            #     do
            #     {
            #       v181 = v187[v180++];
            #       *(&v191 + v180) = v181;
            #     }
            #     while ( v181 );
            #     (*(void (__stdcall **)(_DWORD, char *, char *))(*(_DWORD *)v179 + 400))(0, v187, &v192);
            #   }
            #   sub_6471C0(v2, (int)v2, v10, v182);
            #   return 1;
            # }
            if functionString.find("\"!\"") != -1:
                if functionString.find("\"%s [%d %s]\\n%s\"") != -1:
                    if functionString.find("\" - %d%%\"") != -1:
                        if functionString.find("\" - %lld%%\"") != -1:
                            if functionString.find("\"%d - \"") != -1:
                                if functionString.find(", 0x301Au,") != -1 or functionString.find(", 12314,") != -1:    # 12314  LFG
                                    if functionString.find(", 0x3017,") != -1 or functionString.find(", 12311,") != -1:    # 12311  AFK 
                                        if functionString.find(", 0x8C0u,") != -1 or functionString.find(", 2240,") != -1:    # 2240  LD
                                            if functionString.find(", 0x2FEu,") != -1 or functionString.find(", 766,") != -1:    # 766 Offline
                                                if functionString.find(", 0x157Fu,") != -1 or functionString.find(", 5503,") != -1:    # 5503 Trader
                                                    if functionString.find(", 0x17A7u,") != -1 or functionString.find(", 6055,") != -1:    # 6055 Buyer
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
            if functionString.find("= this;") != -1:
                if functionString.find("= this[32];") != -1:
                    if functionString.find(" + 12))(this[32]);") != -1:
                        if functionString.find("[28] =") != -1:
                            if functionString.find("[29] =") != -1:
                                if functionString.find("int result;") != -1:
                                    if functionString.find("return result;") != -1:
                                        functionList["EQPlayer__push_along_heading"] = functionAddress

            # EQPlayer__AllowedToAttack
            # ----------------------------------------------------------------------------------------------------
            # char __thiscall sub_65AFA0(_DWORD *this, int a2, int a3)
            # {
            #   _DWORD *v3; // esi
            #   int v4; // eax
            #   int v5; // edi
            #   int v6; // ebp
            #   char result; // al
            #   int v8; // eax
            #   int v9; // ecx
            #   int v10; // ebx
            #   int v11; // esi
            #   int v12; // ebx
            #   _DWORD *v13; // eax
            #   int v14; // eax
            #   int v15; // eax
            #   int v16; // eax
            #   int v17; // eax
            #   int v18; // esi
            #   bool v19; // bl
            #   bool v20; // al
            #   char v21; // cl
            #   int v22; // ebx
            #   bool v23; // zf
            #   int v24; // ebx
            #   char v25; // al
            #   bool v26; // bl
            #   int v27; // esi
            #   signed int v28; // [esp+Ch] [ebp-10h]
            #   signed int v29; // [esp+10h] [ebp-Ch]
            #   int v30; // [esp+14h] [ebp-8h]
            #   int v31; // [esp+18h] [ebp-4h]
            #   int v32; // [esp+20h] [ebp+4h]
            #   signed int v33; // [esp+20h] [ebp+4h]
            #
            #   v3 = this;
            #   v4 = (*(int (**)(void))(*this + 68))();
            #   v5 = a2;
            #   v6 = v4;
            #   if ( !a2 )
            #     return 0;
            #   v32 = *(_DWORD *)(v4 + 336);
            #   if ( *(_DWORD *)(v5 + 1372) == v32 || sub_65C310((_DWORD *)v5) == v32 )
            #   {
            #     if ( !sub_565700(a3) )
            #       return 0;
            #     v8 = (*(int (__stdcall **)(int))(*(_DWORD *)dword_F423C8 + 32))(a3);
            #     if ( !v8 || *(_BYTE *)(v8 + 384) < 1u )
            #       return 0;
            #   }
            #   v33 = (unsigned __int8)sub_65C270((_DWORD *)v6);
            #   v28 = (unsigned __int8)sub_65C270((_DWORD *)v5);
            #   if ( !*((_BYTE *)v3 + 293) )
            #   {
            #     v9 = v3[182];
            #     if ( v9 )
            #     {
            #       if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v9 + 4) + 4) + v9 + 588) )
            #       {
            #         if ( v3[383] > 0 )
            #         {
            #           if ( v3[383] >= (signed int)(unsigned __int8)sub_65C270((_DWORD *)v5) )
            #             return 1;
            #           return 0;
            #         }
            #         return 1;
            #       }
            #     }
            #   }
            #   if ( !*(_BYTE *)(v5 + 293) )
            #   {
            #     v10 = *(_DWORD *)(v5 + 728);
            #     if ( v10 )
            #     {
            #       if ( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v10 + 4) + 4) + v10 + 588) )
            #       {
            #         if ( *(_DWORD *)(*(_DWORD *)(v10 + 8) + 1532) > 0 )
            #         {
            #           if ( *(_DWORD *)(*(_DWORD *)(v10 + 8) + 1532) >= (signed int)(unsigned __int8)sub_65C270(v3) )
            #             return 1;
            #           return 0;
            #         }
            #         return 1;
            #       }
            #     }
            #   }
            #   v11 = (unsigned __int8)sub_65C270((_DWORD *)v6);
            #   v29 = abs(v11 - (unsigned __int8)sub_65C270((_DWORD *)v5));
            #   if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 80))(v5)
            #     || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 80))(v6) )
            #   {
            #     return 0;
            #   }
            #   v12 = a3;
            #   if ( a3 != -1
            #     && sub_4B4880((_BYTE *)v6)
            #     && *(_BYTE *)(v6 + 162) != *(_BYTE *)(v5 + 162)
            #     && *(_BYTE *)(v5 + 293) == 1
            #     && !*(_BYTE *)(v5 + 1172) )
            #   {
            #     if ( !*(_BYTE *)(v6 + 293) && !*(_BYTE *)(v5 + 672) && !*(_BYTE *)(v5 + 788) )
            #     {
            #       sub_59AE80(*(_DWORD *)(v6 + 728), 14609, (LPVOID)0x12F);
            #       return 0;
            #     }
            #     return 0;
            #   }
            #   if ( *(_BYTE *)(v6 + 532) )
            #   {
            #     if ( *(_BYTE *)(v5 + 532) )
            #     {
            #       if ( !sub_565700(a3) )
            #         return 1;
            #       v13 = (_DWORD *)(*(int (__stdcall **)(int))(*(_DWORD *)dword_F423C8 + 32))(a3);
            #       if ( v13 )
            #       {
            #         if ( !sub_567A90(v13, 25) )
            #           return 1;
            #       }
            #     }
            #   }
            #   if ( v5 == v6 && sub_565700(a3) )
            #     return 1;
            #   if ( *(_BYTE *)(v5 + 293) == 1 )
            #   {
            #     if ( *(_DWORD *)(v5 + 1372) )
            #     {
            #       v14 = sub_65C310((_DWORD *)v5);
            #       v15 = sub_651DD0((_DWORD **)dword_F40C50, v14);
            #       if ( v15 )
            #       {
            #         if ( !*(_BYTE *)(v15 + 293) )
            #         {
            #           v5 = v15;
            #           v28 = (unsigned __int8)sub_65C270((_DWORD *)v15);
            #         }
            #       }
            #     }
            #   }
            #   if ( *(_BYTE *)(v6 + 293) == 1 )
            #   {
            #     if ( *(_DWORD *)(v6 + 1372) )
            #     {
            #       v16 = sub_65C310((_DWORD *)v6);
            #       v17 = sub_651DD0((_DWORD **)dword_F40C50, v16);
            #       if ( v17 )
            #       {
            #         if ( !*(_BYTE *)(v17 + 293) )
            #         {
            #           v6 = v17;
            #           v33 = (unsigned __int8)sub_65C270((_DWORD *)v17);
            #         }
            #       }
            #     }
            #   }
            #   v18 = 0;
            #   v31 = *(unsigned __int8 *)(v6 + 293);
            #   v30 = *(unsigned __int8 *)(v5 + 293);
            #   if ( sub_565700(a3) )
            #   {
            #     v18 = (*(int (__stdcall **)(int))(*(_DWORD *)dword_F423C8 + 32))(a3);
            #     if ( !v18 )
            #       return 0;
            #   }
            #   if ( v30 == 1 || v31 == 1 )
            #     return 1;
            #   if ( byte_E9EEA4 )
            #   {
            #     if ( v18 && *(_BYTE *)(v18 + 384) >= 1u )
            #     {
            #       v19 = sub_4E3280((_BYTE *)v6);
            #       v20 = sub_4E3280((_BYTE *)v5);
            #       v21 = byte_E9F34C;
            #       if ( v20 != v19 && byte_E9F34C )
            #         return 0;
            #       v12 = a3;
            #     }
            #     else
            #     {
            #       v21 = byte_E9F34C;
            #     }
            #     if ( dword_E9EE9C == *(_DWORD *)(v5 + 336) )
            #       return 1;
            #     if ( dword_E9EE9C == *(_DWORD *)(v6 + 336) )
            #       return 1;
            #   }
            #   else
            #   {
            #     v21 = byte_E9F34C;
            #   }
            #   if ( v12 == -1 && !*(_BYTE *)(v5 + 293) && !*(_BYTE *)(v6 + 293) && *(_QWORD *)(v6 + 1328) && *(_QWORD *)(v5 + 1328) )
            #     return 1;
            #   if ( !v18 )
            #   {
            #     v27 = dword_E8D790;
            #     if ( dword_E8D790 == 2 )
            #     {
            #       if ( v21 )
            #       {
            #         if ( v29 <= 8 && v33 >= 6 && v28 >= 6 )
            #           return 1;
            #         return 0;
            #       }
            #     }
            #     else if ( dword_E8D790 == 4 && byte_E9F34C )
            #     {
            #       if ( sub_65C060((_DWORD *)v5, (_DWORD *)v6, 0) )
            #         goto LABEL_118;
            #       v27 = dword_E8D790;
            #     }
            #     if ( !sub_4E3280((_BYTE *)v5) || !sub_4E3280((_BYTE *)v6) )
            #       return 0;
            #     if ( !sub_4E3280((_BYTE *)v5) || !sub_4E3280((_BYTE *)v6) )
            #       return 1;
            #     if ( v29 > 4 )
            #     {
            #       v23 = v27 == 6;
            # LABEL_129:
            #       if ( !v23 )
            #         return 0;
            #     }
            # LABEL_130:
            #     if ( v33 >= 6 && v28 >= 6 )
            #       return 1;
            #     return 0;
            #   }
            #   if ( *(_BYTE *)(v18 + 384) < 1u )
            #   {
            #     v22 = dword_E8D790;
            #     if ( dword_E8D790 == 2 )
            #     {
            #       if ( v21 )
            #       {
            #         if ( v29 <= 8 && v33 >= 6 && v28 >= 6 )
            #           return 1;
            #         return 0;
            #       }
            # LABEL_82:
            #       if ( !sub_4E3280((_BYTE *)v5) || !sub_4E3280((_BYTE *)v6) )
            #         return 0;
            #       if ( !sub_4E3280((_BYTE *)v5) || !sub_4E3280((_BYTE *)v6) )
            #         return 1;
            #       if ( v29 > 4 )
            #       {
            #         v23 = v22 == 6;
            #         goto LABEL_129;
            #       }
            #       goto LABEL_130;
            #     }
            #     if ( dword_E8D790 == 4 )
            #     {
            #       if ( !v21 )
            #         goto LABEL_82;
            #       if ( !sub_65C060((_DWORD *)v5, (_DWORD *)v6, v18) )
            #       {
            #         v22 = dword_E8D790;
            #         goto LABEL_82;
            #       }
            #     }
            #     else if ( dword_E8D790 != 6 || !v21 )
            #     {
            #       goto LABEL_82;
            #     }
            # LABEL_118:
            #     if ( v33 >= 6 && v28 >= 6 || !sub_8C91D0((_DWORD *)dword_E918CC, *(_DWORD *)(v5 + 1288)) )
            #       return 1;
            #     return 0;
            #   }
            #   v24 = sub_65C230((_DWORD *)v5);
            #   if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 224))(v6) )
            #     return 1;
            #   v25 = *(_BYTE *)(v18 + 384);
            #   if ( v25 != 2 )
            #   {
            #     if ( v25 == 1
            #       && sub_568200((_DWORD *)v18)
            #       && !*(_BYTE *)(v5 + 293)
            #       && (!v24 || !sub_4CF1E0((const char *)(v24 + 9240), (char *)(v6 + 164))) )
            #     {
            #       return 0;
            #     }
            # LABEL_102:
            #     v26 = sub_4E3280((_BYTE *)v6);
            #     if ( sub_4E3280((_BYTE *)v5) == v26 && !byte_E9EEA4 )
            #     {
            #       if ( dword_E8D790 == 4
            #         && byte_E9F34C
            #         && !sub_567A90((_DWORD *)v18, 27)
            #         && sub_65C060((_DWORD *)v5, (_DWORD *)v6, v18) )
            #       {
            #         return 0;
            #       }
            #       return 1;
            #     }
            #     return 0;
            #   }
            #   if ( sub_98D350((_BYTE *)v5) || *(_BYTE *)(v5 + 293) == 1 || *(_BYTE *)(v6 + 293) )
            #     return 0;
            #   if ( sub_567A90((_DWORD *)v18, 81) )
            #     goto LABEL_102;
            #   if ( !v24 )
            #     return 0;
            #   result = sub_4CF1E0((const char *)(v24 + 9240), (char *)(v6 + 164));
            #   if ( result )
            #     goto LABEL_102;
            #   return result;
            # }
            if functionString.find("!= -1") != -1:
                if functionString.find("return 0;") != -1:
                    if functionString.find("return 1;") != -1:
                        if functionString.find("return result;") != -1:
                            if functionString.find(", 14609, ") != -1:
                                if functionString.find("0x12F);") != -1:
                                    functionList["EQPlayer__AllowedToAttack"] = functionAddress

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
                            matches = re.findall("return sub_[0-9A-F]+\(\(int \*\)dword_([0-9A-F]+), &[0-9a-z]+, 0\);", functionString, re.MULTILINE)
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
            if functionString.find(", 0x1553u,") != -1 or functionString.find(", 5459,") != -1:    # 5459 Manually zooming and panning is disabled when the map is in Find mode and the "Auto-Find" button is active.  If you wish to manually adjust the map while in Find mode, then disable the "Auto-Find" button.
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
            # char *__stdcall sub_5EA340(char *a1, char a2)
            # {
            #   char *v2; // ebx
            #   int v3; // esi
            #   char *result; // eax
            #   size_t v5; // edi
            #   char v6; // al
            #   int v7; // ebp
            #   char v8; // al
            #   char *v9; // ecx
            #   char v10; // al
            #   unsigned int v11; // edx
            #   char *v12; // edi
            #   char v13; // al
            #   char *v14; // ecx
            #   int v15; // ebx
            #   char v16; // al
            #   _BYTE *v17; // ecx
            #   char v18; // al
            #   int v19; // eax
            #   const char *v20; // esi
            #   unsigned int v21; // edx
            #   char *v22; // edi
            #   char v23; // al
            #   char v24; // al
            #   char v25; // al
            #   char v26; // al
            #   char *v27; // edi
            #   const char *v28; // esi
            #   int v29; // ecx
            #   const char *v30; // edx
            #   const char *v31; // esi
            #   unsigned int v32; // edx
            #   char *v33; // edi
            #   char v34; // al
            #   char *v35; // ecx
            #   int v36; // ebx
            #   char v37; // al
            #   char *v38; // ebx
            #   unsigned __int8 *v39; // eax
            #   _DWORD *v40; // ecx
            #   int v41; // eax
            #   const char *v42; // esi
            #   unsigned int v43; // edx
            #   char *v44; // edi
            #   char v45; // al
            #   char v46; // al
            #   char v47; // al
            #   char v48; // al
            #   char *v49; // edi
            #   const char *v50; // esi
            #   int v51; // ecx
            #   const char *v52; // edx
            #   const char *v53; // esi
            #   unsigned int v54; // edx
            #   char *v55; // edi
            #   char v56; // al
            #   char *v57; // ecx
            #   int v58; // ebx
            #   char v59; // al
            #   unsigned __int8 *v60; // eax
            #   _DWORD *v61; // ecx
            #   int v62; // eax
            #   const char *v63; // esi
            #   unsigned int v64; // edx
            #   char *v65; // edi
            #   char v66; // al
            #   char v67; // al
            #   char v68; // al
            #   char v69; // al
            #   char *v70; // edi
            #   const char *v71; // esi
            #   int v72; // ecx
            #   const char *v73; // edx
            #   const char *v74; // esi
            #   unsigned int v75; // edx
            #   char *v76; // edi
            #   char v77; // al
            #   char *v78; // ecx
            #   int v79; // ebx
            #   char v80; // al
            #   unsigned __int8 *v81; // eax
            #   _DWORD *v82; // ecx
            #   int v83; // eax
            #   const char *v84; // esi
            #   unsigned int v85; // edx
            #   char *v86; // edi
            #   char v87; // al
            #   char v88; // al
            #   char v89; // al
            #   char v90; // al
            #   char *v91; // edi
            #   const char *v92; // esi
            #   int v93; // ecx
            #   const char *v94; // edx
            #   const char *v95; // esi
            #   unsigned int v96; // edx
            #   char *v97; // edi
            #   char v98; // al
            #   char *v99; // ecx
            #   int v100; // ebx
            #   char v101; // al
            #   int v102; // esi
            #   int v103; // ecx
            #   char *v104; // edi
            #   char v105; // al
            #   unsigned int v106; // edx
            #   char *v107; // edi
            #   char v108; // al
            #   char *v109; // ecx
            #   int v110; // ebx
            #   char v111; // al
            #   const char *v112; // esi
            #   unsigned int v113; // edx
            #   char *v114; // edi
            #   char v115; // al
            #   char *v116; // ecx
            #   const char *v117; // esi
            #   unsigned int v118; // edx
            #   char *v119; // edi
            #   char v120; // al
            #   char *v121; // ecx
            #   char v122; // al
            #   unsigned int v123; // edx
            #   char *v124; // edi
            #   char v125; // al
            #   char *v126; // ecx
            #   int v127; // ebx
            #   char v128; // al
            #   _BYTE *v129; // [esp-Ch] [ebp-84Ch]
            #   int v130; // [esp+8h] [ebp-838h]
            #   char *v131; // [esp+Ch] [ebp-834h]
            #   char *v132; // [esp+10h] [ebp-830h]
            #   char *v133; // [esp+14h] [ebp-82Ch]
            #   char *v134; // [esp+18h] [ebp-828h]
            #   char *v135; // [esp+1Ch] [ebp-824h]
            #   char *v136; // [esp+20h] [ebp-820h]
            #   char *v137; // [esp+24h] [ebp-81Ch]
            #   char *v138; // [esp+28h] [ebp-818h]
            #   char *v139; // [esp+2Ch] [ebp-814h]
            #   char *v140; // [esp+30h] [ebp-810h]
            #   char *v141; // [esp+34h] [ebp-80Ch]
            #   char *v142; // [esp+38h] [ebp-808h]
            #   char *v143; // [esp+3Ch] [ebp-804h]
            #   char v144[2048]; // [esp+40h] [ebp-800h]
            #
            #   v2 = a1;
            #   v3 = 0;
            #   v130 = 0;
            #   result = strchr(a1, 37);
            #   if ( result )
            #   {
            #     while ( 1 )
            #     {
            #       v142 = result;
            #       v141 = result;
            #       v5 = result - v2;
            #       v140 = result;
            #       v139 = result;
            #       v138 = result;
            #       v137 = result;
            #       v136 = result;
            #       v135 = result;
            #       v134 = result;
            #       v133 = result;
            #       v132 = result;
            #       v131 = result;
            #       v143 = result + 1;
            #       if ( result - v2 > 1 )
            #       {
            #         v6 = *(result - 1);
            #         v7 = (int)&v2[v5];
            #         if ( v6 != 32 && v6 != 39 )
            #           break;
            #       }
            #       if ( v3 <= 10 )
            #       {
            #         v8 = v2[v5 + 1];
            #         v7 = (int)&v2[v5];
            #         switch ( v8 )
            #         {
            #           case 116:
            #           case 84:
            #             strncpy(v144, v2, v5);
            #             v116 = (char *)dword_E81318;
            #             v144[v5] = 0;
            #             if ( v116 )
            #             {
            #               v117 = (const char *)sub_65BA20(v116, 0);
            #               v118 = strlen(v117) + 1;
            #               v119 = (char *)&v143 + 3;
            #               do
            #                 v120 = (v119++)[1];
            #               while ( v120 );
            #               qmemcpy(v119, v117, v118);
            #             }
            #             else
            #             {
            #               v121 = (char *)&v143 + 3;
            #               do
            #                 v122 = (v121++)[1];
            #               while ( v122 );
            #               *(_DWORD *)v121 = 1735549268;
            #               *((_WORD *)v121 + 2) = 29797;
            #               v121[6] = 0;
            #             }
            #             v123 = strlen(v141 + 2) + 1;
            #             v124 = (char *)&v143 + 3;
            #             do
            #               v125 = (v124++)[1];
            #             while ( v125 );
            #             qmemcpy(v124, v141 + 2, v123);
            #             v126 = v144;
            #             v127 = v2 - v144;
            #             do
            #             {
            #               v128 = *v126++;
            #               v126[v127 - 1] = v128;
            #             }
            #             while ( v128 );
            #             v38 = v142;
            #             break;
            #           case 109:
            #           case 77:
            #             v102 = sub_6513D0((_DWORD *)dword_F32B08);
            #             strncpy(v144, v2, v5);
            #             v144[v5] = 0;
            #             if ( v102 )
            #             {
            #               while ( *(_DWORD *)(v102 + 1116) != *((_DWORD *)dword_E81244 + 84) )
            #               {
            #                 v103 = *(_DWORD *)(v102 + 8);
            #                 if ( v103 )
            #                 {
            #                   v102 = (*(int (**)(void))(*(_DWORD *)v103 + 68))();
            #                   if ( v102 )
            #                     continue;
            #                 }
            #                 goto LABEL_107;
            #               }
            #               v112 = (const char *)sub_65BA20((char *)v102, 0);
            #               v113 = strlen(v112) + 1;
            #               v114 = (char *)&v143 + 3;
            #               do
            #                 v115 = (v114++)[1];
            #               while ( v115 );
            #               qmemcpy(v114, v112, v113);
            #             }
            #             else
            #             {
            # LABEL_107:
            #               v104 = (char *)&v143 + 3;
            #               do
            #                 v105 = (v104++)[1];
            #               while ( v105 );
            #               strcpy(v104, "Pet");
            #             }
            #             v106 = strlen(v139 + 2) + 1;
            #             v107 = (char *)&v143 + 3;
            #             do
            #               v108 = (v107++)[1];
            #             while ( v108 );
            #             qmemcpy(v107, v139 + 2, v106);
            #             v109 = v144;
            #             v110 = v2 - v144;
            #             do
            #             {
            #               v111 = *v109++;
            #               v109[v110 - 1] = v111;
            #             }
            #             while ( v111 );
            #             v38 = v140;
            #             break;
            #           case 115:
            #           case 83:
            #             strncpy(v144, v2, v5);
            #             v81 = (unsigned __int8 *)dword_E81318;
            #             v82 = dword_E81028;
            #             v144[v5] = 0;
            #             v129 = 0;
            #             if ( v81 )
            #             {
            #               v83 = v81[4016];
            #               if ( v83 )
            #               {
            #                 if ( v83 == 1 )
            #                 {
            #                   v84 = (const char *)sub_8B4830(v82, 12210, v129);
            #                   v85 = strlen(v84) + 1;
            #                   v86 = (char *)&v143 + 3;
            #                   do
            #                     v88 = (v86++)[1];
            #                   while ( v88 );
            #                 }
            #                 else
            #                 {
            #                   v84 = (const char *)sub_8B4830(v82, 12211, v129);
            #                   v85 = strlen(v84) + 1;
            #                   v86 = (char *)&v143 + 3;
            #                   do
            #                     v87 = (v86++)[1];
            #                   while ( v87 );
            #                 }
            #               }
            #               else
            #               {
            #                 v84 = (const char *)sub_8B4830(v82, 12209, v129);
            #                 v85 = strlen(v84) + 1;
            #                 v86 = (char *)&v143 + 3;
            #                 do
            #                   v89 = (v86++)[1];
            #                 while ( v89 );
            #               }
            #             }
            #             else
            #             {
            #               v84 = (const char *)sub_8B4830(v82, 12211, v129);
            #               v85 = strlen(v84) + 1;
            #               v86 = (char *)&v143 + 3;
            #               do
            #                 v90 = (v86++)[1];
            #               while ( v90 );
            #             }
            #             qmemcpy(v86, v84, 4 * (v85 >> 2));
            #             v92 = &v84[4 * (v85 >> 2)];
            #             v91 = &v86[4 * (v85 >> 2)];
            #             v93 = v85 & 3;
            #             v94 = v137 + 2;
            #             qmemcpy(v91, v92, v93);
            #             v95 = v94;
            #             v96 = strlen(v94) + 1;
            #             v97 = (char *)&v143 + 3;
            #             do
            #               v98 = (v97++)[1];
            #             while ( v98 );
            #             qmemcpy(v97, v95, v96);
            #             v99 = v144;
            #             v100 = v2 - v144;
            #             do
            #             {
            #               v101 = *v99++;
            #               v99[v100 - 1] = v101;
            #             }
            #             while ( v101 );
            #             v38 = v138;
            #             break;
            #           case 111:
            #           case 79:
            #             strncpy(v144, v2, v5);
            #             v60 = (unsigned __int8 *)dword_E81318;
            #             v61 = dword_E81028;
            #             v144[v5] = 0;
            #             v129 = 0;
            #             if ( v60 )
            #             {
            #               v62 = v60[4016];
            #               if ( v62 )
            #               {
            #                 if ( v62 == 1 )
            #                 {
            #                   v63 = (const char *)sub_8B4830(v61, 12298, v129);
            #                   v64 = strlen(v63) + 1;
            #                   v65 = (char *)&v143 + 3;
            #                   do
            #                     v67 = (v65++)[1];
            #                   while ( v67 );
            #                 }
            #                 else
            #                 {
            #                   v63 = (const char *)sub_8B4830(v61, 6766, v129);
            #                   v64 = strlen(v63) + 1;
            #                   v65 = (char *)&v143 + 3;
            #                   do
            #                     v66 = (v65++)[1];
            #                   while ( v66 );
            #                 }
            #               }
            #               else
            #               {
            #                 v63 = (const char *)sub_8B4830(v61, 12297, v129);
            #                 v64 = strlen(v63) + 1;
            #                 v65 = (char *)&v143 + 3;
            #                 do
            #                   v68 = (v65++)[1];
            #                 while ( v68 );
            #               }
            #             }
            #             else
            #             {
            #               v63 = (const char *)sub_8B4830(v61, 6766, v129);
            #               v64 = strlen(v63) + 1;
            #               v65 = (char *)&v143 + 3;
            #               do
            #                 v69 = (v65++)[1];
            #               while ( v69 );
            #             }
            #             qmemcpy(v65, v63, 4 * (v64 >> 2));
            #             v71 = &v63[4 * (v64 >> 2)];
            #             v70 = &v65[4 * (v64 >> 2)];
            #             v72 = v64 & 3;
            #             v73 = v135 + 2;
            #             qmemcpy(v70, v71, v72);
            #             v74 = v73;
            #             v75 = strlen(v73) + 1;
            #             v76 = (char *)&v143 + 3;
            #             do
            #               v77 = (v76++)[1];
            #             while ( v77 );
            #             qmemcpy(v76, v74, v75);
            #             v78 = v144;
            #             v79 = v2 - v144;
            #             do
            #             {
            #               v80 = *v78++;
            #               v78[v79 - 1] = v80;
            #             }
            #             while ( v80 );
            #             v38 = v136;
            #             break;
            #           case 112:
            #           case 80:
            #             strncpy(v144, v2, v5);
            #             v39 = (unsigned __int8 *)dword_E81318;
            #             v40 = dword_E81028;
            #             v144[v5] = 0;
            #             v129 = 0;
            #             if ( v39 )
            #             {
            #               v41 = v39[4016];
            #               if ( v41 )
            #               {
            #                 if ( v41 == 1 )
            #                 {
            #                   v42 = (const char *)sub_8B4830(v40, 12299, v129);
            #                   v43 = strlen(v42) + 1;
            #                   v44 = (char *)&v143 + 3;
            #                   do
            #                     v46 = (v44++)[1];
            #                   while ( v46 );
            #                 }
            #                 else
            #                 {
            #                   v42 = (const char *)sub_8B4830(v40, 12300, v129);
            #                   v43 = strlen(v42) + 1;
            #                   v44 = (char *)&v143 + 3;
            #                   do
            #                     v45 = (v44++)[1];
            #                   while ( v45 );
            #                 }
            #               }
            #               else
            #               {
            #                 v42 = (const char *)sub_8B4830(v40, 12301, v129);
            #                 v43 = strlen(v42) + 1;
            #                 v44 = (char *)&v143 + 3;
            #                 do
            #                   v47 = (v44++)[1];
            #                 while ( v47 );
            #               }
            #             }
            #             else
            #             {
            #               v42 = (const char *)sub_8B4830(v40, 12300, v129);
            #               v43 = strlen(v42) + 1;
            #               v44 = (char *)&v143 + 3;
            #               do
            #                 v48 = (v44++)[1];
            #               while ( v48 );
            #             }
            #             qmemcpy(v44, v42, 4 * (v43 >> 2));
            #             v50 = &v42[4 * (v43 >> 2)];
            #             v49 = &v44[4 * (v43 >> 2)];
            #             v51 = v43 & 3;
            #             v52 = v133 + 2;
            #             qmemcpy(v49, v50, v51);
            #             v53 = v52;
            #             v54 = strlen(v52) + 1;
            #             v55 = (char *)&v143 + 3;
            #             do
            #               v56 = (v55++)[1];
            #             while ( v56 );
            #             qmemcpy(v55, v53, v54);
            #             v57 = v144;
            #             v58 = v2 - v144;
            #             do
            #             {
            #               v59 = *v57++;
            #               v57[v58 - 1] = v59;
            #             }
            #             while ( v59 );
            #             v38 = v134;
            #             break;
            #           case 114:
            #           case 82:
            #             strncpy(v144, v2, v5);
            #             v17 = dword_E81318;
            #             v144[v5] = 0;
            #             if ( v17 )
            #             {
            #               v18 = v17[293];
            #               if ( v18 )
            #               {
            #                 v129 = 0;
            #                 if ( v18 == 2 )
            #                 {
            #                   v20 = (const char *)sub_8B4830(dword_E81028, 6767, v129);
            #                   v21 = strlen(v20) + 1;
            #                   v22 = (char *)&v143 + 3;
            #                   do
            #                     v24 = (v22++)[1];
            #                   while ( v24 );
            #                 }
            #                 else
            #                 {
            #                   v20 = (const char *)sub_8B4830(dword_E81028, 6768, v129);
            #                   v21 = strlen(v20) + 1;
            #                   v22 = (char *)&v143 + 3;
            #                   do
            #                     v25 = (v22++)[1];
            #                   while ( v25 );
            #                 }
            #               }
            #               else
            #               {
            #                 v19 = *(_DWORD *)v17;
            #                 v129 = v17;
            #                 (*(void (__stdcall **)(_BYTE **))(v19 + 136))(&v129);
            #                 v20 = (const char *)sub_5EFB30((unsigned int)v129);
            #                 v21 = strlen(v20) + 1;
            #                 v22 = (char *)&v143 + 3;
            #                 do
            #                   v23 = (v22++)[1];
            #                 while ( v23 );
            #               }
            #             }
            #             else
            #             {
            #               v20 = (const char *)sub_8B4830(dword_E81028, 6769, 0);
            #               v21 = strlen(v20) + 1;
            #               v22 = (char *)&v143 + 3;
            #               do
            #                 v26 = (v22++)[1];
            #               while ( v26 );
            #             }
            #             qmemcpy(v22, v20, 4 * (v21 >> 2));
            #             v28 = &v20[4 * (v21 >> 2)];
            #             v27 = &v22[4 * (v21 >> 2)];
            #             v29 = v21 & 3;
            #             v30 = v131 + 2;
            #             qmemcpy(v27, v28, v29);
            #             v31 = v30;
            #             v32 = strlen(v30) + 1;
            #             v33 = (char *)&v143 + 3;
            #             do
            #               v34 = (v33++)[1];
            #             while ( v34 );
            #             qmemcpy(v33, v31, v32);
            #             v35 = v144;
            #             v36 = v2 - v144;
            #             do
            #             {
            #               v37 = *v35++;
            #               v35[v36 - 1] = v37;
            #             }
            #             while ( v37 );
            #             v38 = v132;
            #             break;
            #           default:
            #             goto LABEL_19;
            #         }
            #         v2 = v38 + 2;
            #         v3 = v130++ + 1;
            #       }
            #       else
            #       {
            #         v2[v5] = 64;
            #       }
            # LABEL_131:
            #       result = strchr(v143, 37);
            #       if ( !result )
            #         return result;
            #     }
            # LABEL_19:
            #     if ( a2 )
            #     {
            #       strncpy(v144, v2, v5);
            #       v144[v5] = 0;
            #       v9 = (char *)&v143 + 3;
            #       do
            #         v10 = (v9++)[1];
            #       while ( v10 );
            #       *(_DWORD *)v9 = 1413697574;
            #       *((_WORD *)v9 + 2) = 59;
            #       v11 = strlen((const char *)(v7 + 1)) + 1;
            #       v12 = (char *)&v143 + 3;
            #       do
            #         v13 = (v12++)[1];
            #       while ( v13 );
            #       qmemcpy(v12, (const void *)(v7 + 1), v11);
            #       v14 = v144;
            #       v15 = v2 - v144;
            #       do
            #       {
            #         v16 = *v14++;
            #         v14[v15 - 1] = v16;
            #       }
            #       while ( v16 );
            #       v3 = v130;
            #       v2 = (char *)(v7 + 1);
            #     }
            #     goto LABEL_131;
            #   }
            #   return result;
            # }
            if functionString.find(", 0x1A6Fu,") != -1 or functionString.find(", 6767,") != -1:    # 6767 Corpse
                if functionString.find(", 0x1A70u,") != -1 or functionString.find(", 6768,") != -1:    # 6768 NPC
                    if functionString.find(", 0x1A71u,") != -1 or functionString.find(", 6769,") != -1:    # 6769 Race
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
            if functionString.find(", 0x21Au,") != -1 or functionString.find(", 538,") != -1:    # 538 You may not use that command while dead.
                if functionString.find(", 0x305Cu,") != -1 or functionString.find(", 12380,") != -1:    # 12380 That is not a valid command.  Please use /help.
                    if functionString.find("\"%s %s\"") != -1:
                        if functionString.find("\"#%s %s\"") != -1:
                            functionList["CEverQuest__InterpretCmd"] = functionAddress

            # CEverQuest__dsp_chat
            # ----------------------------------------------------------------------------------------------------
            # void __stdcall sub_4E5350(char *a1, LPVOID a2, LPVOID a3, LPVOID lpMem, LPVOID a5)
            # {
            #   char *v5; // esi
            #   void *v6; // edi
            #   volatile signed __int32 **v7; // esi
            #   void *v8; // ecx
            #   signed int v9; // ebx
            #   volatile signed __int32 **v10; // eax
            #   LPVOID *v11; // esi
            #   char *v12; // eax
            #   char *v13; // eax
            #   char *v14; // esi
            #   char *v15; // eax
            #   char *v16; // edi
            #   LPVOID *v17; // eax
            #   LPVOID *v18; // eax
            #   char (*v19)[2]; // eax
            #   LPVOID v20; // [esp+10h] [ebp-14h]
            #   LPVOID v21; // [esp+14h] [ebp-10h]
            #   int v22; // [esp+20h] [ebp-4h]
            #
            #   v21 = 0;
            #   v5 = a1;
            #   if ( strlen(a1) >= 1 )
            #   {
            #     if ( dword_F3A520 )
            #     {
            #       v6 = a2;
            #       if ( a2 != (LPVOID)346 || !sub_9888F0(&unk_E96FC8, 0x1Eu) )
            #       {
            #         if ( (_BYTE)lpMem )
            #           sub_5EA250(v5, 0);
            #         if ( (_BYTE)a5 )
            #         {
            #           v10 = (volatile signed __int32 **)sub_8ED830(&a2, (int)"%s", (char)v5);
            #           v11 = (LPVOID *)v10;
            #           if ( *v10 )
            #             sub_473190(*v10);
            #           v8 = *v11;
            #           v9 = 12;
            #           lpMem = *v11;
            #           v7 = (volatile signed __int32 **)&lpMem;
            #         }
            #         else
            #         {
            #           sub_8ED690(&a5, v5);
            #           v22 = 0;
            #           v21 = (LPVOID)1;
            #           v7 = (volatile signed __int32 **)sub_92F6C0(&v20, (volatile signed __int32 **)&a5);
            #           v8 = lpMem;
            #           v9 = 3;
            #         }
            #         if ( *v7 )
            #         {
            #           sub_473190(*v7);
            #           v8 = lpMem;
            #         }
            #         a1 = (char *)*v7;
            #         v22 = 2;
            #         if ( v9 & 8 )
            #         {
            #           v9 &= 0xFFFFFFF7;
            #           v21 = (LPVOID)v9;
            #           LOBYTE(v22) = 3;
            #           if ( v8 )
            #             sub_8EFAE0(v8);
            #           lpMem = 0;
            #         }
            #         if ( v9 & 4 )
            #         {
            #           v9 &= 0xFFFFFFFB;
            #           v21 = (LPVOID)v9;
            #           LOBYTE(v22) = 4;
            #           if ( a2 )
            #             sub_8EFAE0(a2);
            #           a2 = 0;
            #         }
            #         if ( v9 & 2 )
            #         {
            #           v9 &= 0xFFFFFFFD;
            #           v21 = (LPVOID)v9;
            #           LOBYTE(v22) = 6;
            #           if ( v20 )
            #             sub_8EFAE0(v20);
            #           v20 = 0;
            #         }
            #         LOBYTE(v22) = 7;
            #         if ( v9 & 1 )
            #         {
            #           LOBYTE(v22) = 8;
            #           if ( a5 )
            #             sub_8EFAE0(a5);
            #           a5 = 0;
            #           LOBYTE(v22) = 7;
            #         }
            #         sub_5B8430(&a1, 1);
            #         if ( v6 == (void *)20 )
            #           v6 = (void *)10;
            #         if ( dword_1051498 )
            #         {
            #           v12 = a1;
            #           if ( a1 )
            #           {
            #             sub_473190((volatile signed __int32 *)a1);
            #             v12 = a1;
            #           }
            #           sub_6FC900(dword_1051498, v12, v6);
            #         }
            #         else
            #         {
            #           v13 = (char *)operator new(0x804u);
            #           v14 = v13;
            #           if ( v13 )
            #             memset(v13, 0, 0x804u);
            #           else
            #             v14 = 0;
            #           v15 = (char *)sub_8EDE00((LPVOID *)&a1);
            #           sub_8F1A90(v14, v15, 0x800u);
            #           *((_DWORD *)v14 + 512) = v6;
            #           v16 = (char *)dword_ECC3D8;
            #           if ( (signed int)dword_ECC3D8 >= 0 )
            #           {
            #             sub_4E66E0(&dword_ECC3D8, (int)dword_ECC3D8 + 1);
            #             if ( dword_ECC3DC )
            #             {
            #               dword_ECC3D8 = v16 + 1;
            #               *((_DWORD *)dword_ECC3DC + (_DWORD)v16) = v14;
            #             }
            #           }
            #         }
            #         if ( byte_E96EE9[0] && (_BYTE)a3 )
            #         {
            #           v17 = sub_92FB60(&v21, (int *)&a1, 1);
            #           LOBYTE(v22) = 9;
            #           v18 = (LPVOID *)sub_4779D0((int)&a3, v17, 0);
            #           LOBYTE(v22) = 10;
            #           v19 = sub_8EDE00(v18);
            #           sub_4E4FC0(v19);
            #           LOBYTE(v22) = 11;
            #           if ( a3 )
            #             sub_8EFAE0(a3);
            #           a3 = 0;
            #           LOBYTE(v22) = 12;
            #           if ( v21 )
            #             sub_8EFAE0(v21);
            #         }
            #         v22 = 13;
            #         if ( a1 )
            #           sub_8EFAE0(a1);
            #       }
            #     }
            #   }
            # }
            if functionString.find("\"%s\"") != -1:
                if functionString.find("346") != -1:
                        if functionString.find("& 2") != -1:
                            if functionString.find("& 4") != -1:
                                if functionString.find("& 8") != -1:
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
            # void __userpurge sub_5D3A40(int *a1@<ecx>, double a2@<st7>, double a3@<st6>, double a4@<st5>, double a5@<st4>, double a6@<st3>, double a7@<st2>, double a8@<st1>, double a9@<st0>, int a10, int a11)
            # {
            #   unsigned int v11; // ebx
            #   _BYTE *v12; // eax
            #   _BYTE *v13; // eax
            #   _DWORD *v14; // eax
            #   int v15; // eax
            #   _BYTE *v16; // eax
            #   int v17; // esi
            #   int v18; // edi
            #   _BYTE *v19; // eax
            #   float *v20; // eax
            #   int *v21; // ebx
            #   void *v22; // eax
            #   int v23; // eax
            #   _DWORD *v24; // eax
            #   bool v25; // zf
            #   signed int v26; // ebx
            #   int v27; // eax
            #   void **v28; // eax
            #   void *v29; // ecx
            #   bool v30; // al
            #   char v31; // al
            #   void *v32; // esi
            #   int v33; // eax
            #   int v34; // eax
            #   int v35; // ebx
            #   _DWORD *v36; // eax
            #   unsigned int v37; // ebx
            #   int v38; // eax
            #   void **v39; // eax
            #   void *v40; // ecx
            #   int v41; // eax
            #   bool v42; // bl
            #   int v43; // eax
            #   double v44; // st7
            #   void **v45; // eax
            #   void *v46; // ecx
            #   int v47; // eax
            #   int v48; // ebx
            #   int v49; // eax
            #   double v50; // st7
            #   void **v51; // eax
            #   void *v52; // ecx
            #   int v53; // ebx
            #   int v54; // eax
            #   void **v55; // eax
            #   void *v56; // ecx
            #   int v57; // eax
            #   double v58; // st7
            #   _DWORD *v59; // eax
            #   char *v60; // eax
            #   char v61; // bl
            #   _BYTE *v62; // eax
            #   _BYTE *v63; // eax
            #   int v64; // eax
            #   int **v65; // eax
            #   int v66; // eax
            #   char v67; // al
            #   bool v68; // bl
            #   int v69; // eax
            #   unsigned __int8 **v70; // eax
            #   unsigned __int8 *v71; // ecx
            #   bool v72; // al
            #   bool v73; // bl
            #   char *v74; // eax
            #   char *v75; // ST14_4
            #   int v76; // eax
            #   void **v77; // eax
            #   void *v78; // ecx
            #   int v79; // eax
            #   int v80; // eax
            #   char v81; // cl
            #   int v82; // eax
            #   _DWORD *v83; // eax
            #   int v84; // eax
            #   int v85; // esi
            #   int v86; // eax
            #   int v87; // ebx
            #   float v89; // ST24_4
            #   float v90; // ST20_4
            #   float v91; // ST1C_4
            #   float v92; // ST18_4
            #   float v93; // ST14_4
            #   float v94; // ST10_4
            #   float v95; // ST0C_4
            #   int v97; // eax
            #   int v98; // edx
            #   int *v99; // eax
            #   int v100; // edx
            #   void *v101; // eax
            #   int v102; // edx
            #   int v103; // eax
            #   float *v104; // esi
            #   float *v105; // eax
            #   float *v106; // eax
            #   float *v107; // eax
            #   float *v108; // eax
            #   int v109; // esi
            #   unsigned int v110; // ebx
            #   char v111; // bl
            #   int v112; // esi
            #   int v113; // ebx
            #   char v114; // bl
            #   int *v115; // eax
            #   int v116; // esi
            #   float v118; // ST24_4
            #   float v119; // ST20_4
            #   float v120; // ST1C_4
            #   float v121; // ST18_4
            #   float v122; // ST14_4
            #   float v123; // ST10_4
            #   float v124; // ST0C_4
            #   void *v126; // ecx
            #   char *v127; // ST14_4
            #   void *v128; // eax
            #   int v129; // esi
            #   int v130; // edi
            #   char v131; // bl
            #   int v132; // [esp+20h] [ebp-2E4h]
            #   char v133; // [esp+2Ch] [ebp-2D8h]
            #   char v134; // [esp+22Ch] [ebp-D8h]
            #   char v135; // [esp+24Ch] [ebp-B8h]
            #   char v136; // [esp+26Ch] [ebp-98h]
            #   char v137; // [esp+278h] [ebp-8Ch]
            #   _DWORD v138[5]; // [esp+290h] [ebp-74h]
            #   int v139; // [esp+2A4h] [ebp-60h]
            #   int v140; // [esp+2A8h] [ebp-5Ch]
            #   int v141; // [esp+2ACh] [ebp-58h]
            #   int v142; // [esp+2BCh] [ebp-48h]
            #   char v143; // [esp+2C0h] [ebp-44h]
            #   int v144; // [esp+2C4h] [ebp-40h]
            #   int v145; // [esp+2C8h] [ebp-3Ch]
            #   int v146; // [esp+2D4h] [ebp-30h]
            #   char v147; // [esp+2D8h] [ebp-2Ch]
            #   int v148; // [esp+2E4h] [ebp-20h]
            #   int v149; // [esp+2E8h] [ebp-1Ch]
            #   float v150; // [esp+2ECh] [ebp-18h]
            #   int v153; // [esp+300h] [ebp-4h]
            #   float v154; // [esp+304h] [ebp+0h]
            #   int v156; // [esp+30Ch] [ebp+8h]
            #   float v157; // [esp+310h] [ebp+Ch]
            #   float v160; // [esp+31Ch] [ebp+18h]
            #   int v163; // [esp+328h] [ebp+24h]
            #   float v164; // [esp+32Ch] [ebp+28h]
            #   float v167; // [esp+338h] [ebp+34h]
            #   float v170; // [esp+344h] [ebp+40h]
            #   unsigned int v173; // [esp+350h] [ebp+4Ch]
            #   float v174; // [esp+354h] [ebp+50h]
            #   float v175[2]; // [esp+358h] [ebp+54h]
            #   int *v176; // [esp+360h] [ebp+5Ch]
            #   LPVOID lpMem; // [esp+364h] [ebp+60h]
            #   int v178; // [esp+368h] [ebp+64h]
            #
            #   v11 = 0;
            #   v176 = a1;
            #   *(float *)&v178 = 0.0;
            #   byte_E90BE3 = 0;
            #   if ( (_BYTE)word_E90C72 )
            #   {
            #     if ( !HIBYTE(word_E90C72) )
            #     {
            #       LOBYTE(word_E90C72) = 0;
            #       v12 = sub_612920();
            #       if ( !sub_612A00(v12) && *(_DWORD *)(dword_F3554C + 1480) == 5 )
            #       {
            #         while ( ShowCursor(1) < 0 )
            #           ;
            #         SetCursorPos(*(_DWORD *)(dword_16CC524 + 312), *(_DWORD *)(dword_16CC524 + 316));
            #       }
            #     }
            #   }
            #   v13 = sub_612920();
            #   if ( sub_612A00(v13) && (unsigned int)(*((_DWORD *)dword_E81024 + 85) - dword_E90D18) < 0x1F4 )
            #   {
            #     v14 = sub_612920();
            #     sub_613480(v14);
            #     return;
            #   }
            #   v15 = dword_F2F92C;
            #   if ( dword_F2F92C > 0 )
            #     goto LABEL_132;
            #   if ( (_BYTE)word_E90C72 )
            #   {
            # LABEL_131:
            #     if ( v15 <= 0 )
            #       return;
            # LABEL_132:
            #     sub_4C6270((_DWORD *)(dword_F3554C + 235028), 70);
            #     return;
            #   }
            #   v16 = sub_612920();
            #   if ( sub_612A00(v16) || (unsigned int)(*((_DWORD *)dword_E81024 + 85) - dword_E90D18) > 0x2EE )
            #   {
            #     v15 = dword_F2F92C;
            #     goto LABEL_131;
            #   }
            #   if ( dword_DCF094 )
            #     sub_70AE90((_BYTE *)dword_DCF094);
            #   v17 = a10;
            #   v18 = a11;
            #   if ( dword_104C168 )
            #     sub_6EAE00(dword_104C168, a10, a11);
            #   v148 = v17;
            #   v149 = v18;
            #   v163 = 0;
            #   v19 = (_BYTE *)sub_9240E0((_DWORD *)dword_16CC524, &v148, &v163);
            #   if ( v19 && !sub_91EA30(v19) )
            #     return;
            #   if ( v176[368] )
            #   {
            #     v20 = (float *)sub_67A760();
            #     v21 = v176;
            #     sub_6078E0(v176[368], a2, a3, a4, a5, a6, a7, a8, a9, v20 + 101);
            #     sub_990D3E((LPVOID)v21[368]);
            #     v21[368] = 0;
            #     return;
            #   }
            #   v22 = (void *)sub_5DC470((int)&v154, a9, a8, v17, v18);
            #   lpMem = v22;
            #   if ( v22 )
            #   {
            #     if ( v22 != dword_E81244 )
            #     {
            # LABEL_31:
            #       v31 = sub_986B90(v22);
            #       v32 = lpMem;
            #       if ( v31 )
            #       {
            #         v33 = sub_64E190(lpMem);
            #         if ( v33 )
            #           v32 = (void *)v33;
            #       }
            #       sub_5D56B0((int)v176, a9, v32);
            #       return;
            #     }
            #     v23 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #     a9 = sub_4B3150(&v175[1], 33);
            #     v25 = *v24 == 0;
            #     v26 = 1;
            #     v153 = 0;
            #     v178 = 1;
            #     if ( v25 )
            #       goto LABEL_135;
            #     v27 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #     a9 = sub_4B3150(&v173, 33);
            #     v29 = *v28;
            #     v153 = 1;
            #     v26 = 3;
            #     v178 = 3;
            #     v30 = sub_89A910(v29);
            #     HIBYTE(a11) = 1;
            #     if ( !v30 )
            # LABEL_135:
            #       HIBYTE(a11) = 0;
            #     if ( v26 & 2 )
            #     {
            #       v26 &= 0xFFFFFFFD;
            #       sub_592520(&v173);
            #     }
            #     v153 = -1;
            #     v11 = v26 & 0xFFFFFFFE;
            #     sub_592520(&v175[1]);
            #     if ( !HIBYTE(a11) )
            #     {
            #       v22 = lpMem;
            #       goto LABEL_31;
            #     }
            #   }
            #   if ( sub_986BC0(dword_E81244) || dword_E81258 )
            #     goto LABEL_109;
            #   v34 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #   a9 = sub_4B3150(&v175[1], 33);
            #   v35 = v11 | 4;
            #   if ( !*v36 || v17 > dword_E90B98 || v18 > dword_E90B9C || v17 < dword_E90B90 || (HIBYTE(a11) = 1, v18 < dword_E90B94) )
            #     HIBYTE(a11) = 0;
            #   v37 = v35 & 0xFFFFFFFB;
            #   v173 = v37;
            #   sub_592520(&v175[1]);
            #   if ( !HIBYTE(a11) )
            #   {
            #     v81 = *((_BYTE *)dword_E81024 + 17);
            #     if ( v81 )
            #     {
            #       if ( a10 <= dword_E90B98 && v18 <= dword_E90B9C && a10 >= dword_E90B90 && v18 >= dword_E90B94 )
            #         return;
            #       v17 = a10;
            #       if ( v81 )
            #         goto LABEL_136;
            #     }
            #     v82 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #     a9 = sub_4B3150(&v175[1], 33);
            #     LOBYTE(v37) = v37 | 0x20;
            #     HIBYTE(a11) = 1;
            #     if ( *v83 )
            # LABEL_136:
            #       HIBYTE(a11) = 0;
            #     if ( v37 & 0x20 )
            #       sub_592520(&v175[1]);
            #     if ( HIBYTE(a11) )
            #     {
            #       if ( dword_DCE924 && *(_DWORD *)(dword_DCE924 + 180) )
            #         return;
            #       v84 = sub_539030(dword_E81024, (int)&v154, a9, a8, v17, v18, 0, (int)&v164, (int)&v136);
            #       v85 = v84;
            #       if ( v84 )
            #       {
            #         (*(void (__thiscall **)(int, float *))(*(_DWORD *)v84 + 128))(v84, &v154);
            #         if ( (*(int (__thiscall **)(int))(*(_DWORD *)v85 + 32))(v85)
            #           && (v86 = (*(int (__thiscall **)(int))(*(_DWORD *)v85 + 32))(v85),
            #               (v87 = (*(int (__thiscall **)(int))(*(_DWORD *)v86 + 36))(v86)) != 0) )
            #         {
            #           if ( !(*(int (__thiscall **)(int))(*(_DWORD *)v85 + 260))(v85) )
            #             goto LABEL_137;
            #           _EAX = dword_E81244;
            #           __asm
            #           {
            #             fld     dword ptr [eax+6Ch]
            #             fld     dword ptr [eax+68h]
            #             fld     dword ptr [eax+64h]
            #             fld     dword ptr [eax+13Ch]
            #             fstp    [ebp+68h+arg_4]
            #             fld1
            #             fstp    [esp+368h+var_350]; float
            #             fld     [ebp+68h+var_38]
            #             fstp    [esp+368h+var_354]; float
            #             fld     [ebp+68h+var_3C]
            #             fstp    [esp+368h+var_358]; float
            #             fld     [ebp+68h+var_40]
            #             fstp    [esp+368h+var_35C]; float
            #             fxch    st(2)
            #             fstp    [esp+368h+var_360]; float
            #             fstp    [esp+368h+var_364]; float
            #             fstp    [esp+368h+var_368]; float
            #           }
            #           sub_53C760(v95, v94, v93, v92, v91, v90, v89);
            #           __asm
            #           {
            #             fld     [ebp+68h+arg_4]
            #             fadd    ds:flt_ABF4D0
            #             fcompp
            #             fnstsw  ax
            #           }
            #           if ( _AX & 0x4100 )
            #             goto LABEL_137;
            #           v97 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v85 + 392))(v85, "POINT1");
            #           v98 = *(_DWORD *)v85;
            #           a11 = v97;
            #           v99 = (int *)(*(int (__thiscall **)(int, const char *))(v98 + 392))(v85, "POINT2");
            #           v100 = *(_DWORD *)v85;
            #           v176 = v99;
            #           v101 = (void *)(*(int (__thiscall **)(int, const char *))(v100 + 392))(v85, "POINT3");
            #           v102 = *(_DWORD *)v85;
            #           lpMem = v101;
            #           v103 = (*(int (__thiscall **)(int, const char *))(v102 + 392))(v85, "POINT4");
            #           LODWORD(v175[1]) = v103;
            #           if ( *(float *)&a11 == 0.0 )
            #             goto LABEL_137;
            #           if ( !v176 )
            #             goto LABEL_137;
            #           if ( !lpMem )
            #             goto LABEL_137;
            #           if ( !v103 )
            #             goto LABEL_137;
            #           v104 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v85 + 260))(v85);
            #           v105 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)a11 + 8))(a11);
            #           sub_5FFE80(v104, (float *)&v147, v105);
            #           v106 = (float *)(*(int (**)(void))(*v176 + 8))();
            #           sub_5FFE80(v104, &v160, v106);
            #           v107 = (float *)(*(int (**)(void))(*(_DWORD *)lpMem + 8))();
            #           sub_5FFE80(v104, &v150, v107);
            #           v108 = (float *)(*(int (**)(void))(*(_DWORD *)LODWORD(v175[1]) + 8))();
            #           sub_5FFE80(v104, &v157, v108);
            #           __asm
            #           {
            #             fld     [ebp+68h+var_50]
            #             fld     [ebp+68h+var_80]
            #             fsub    st(1), st
            #             fxch    st(1)
            #             fstp    [ebp+68h+var_34]
            #             fld     [ebp+68h+var_4C]
            #             fld     [ebp+68h+var_7C]
            #             fsub    st(1), st
            #             fxch    st(1)
            #             fstp    [ebp+68h+var_30]
            #             fld     [ebp+68h+var_48]
            #             fld     [ebp+68h+var_78]
            #             fsub    st(1), st
            #             fxch    st(1)
            #             fstp    [ebp+68h+var_2C]
            #             fld     [ebp+68h+var_5C]
            #             fsubrp  st(3), st
            #             fxch    st(2)
            #             fstp    [ebp+68h+var_28]
            #             fsubr   [ebp+68h+var_58]
            #             fstp    [ebp+68h+var_24]
            #             fsubr   [ebp+68h+var_54]
            #             fstp    [ebp+68h+var_20]
            #           }
            #           sub_4C5F30(&v167, &v174, &v170);
            #           sub_5C9CA0(&v174);
            #           sub_5FE5E0((float *)&v135, (float *)&v147, &v160, &v157);
            #           sub_5FE5E0((float *)&v134, &v157, &v160, &v150);
            #           __asm
            #           {
            #             fld     [ebp+68h+var_18]
            #             fld     ds:flt_ABD7CC
            #             fmul    st(1), st
            #             fld     dword ptr [ebp+54h]
            #             fmul    st, st(1)
            #             fld     [ebp+68h+anonymous_0+4]
            #             fmulp   st(2), st
            #             fld     st(2)
            #             fld     [ebp+68h+var_40]
            #             fadd    st(1), st
            #             fxch    st(1)
            #             fstp    [ebp+68h+var_28]
            #             fld     st(1)
            #             fld     [ebp+68h+var_3C]
            #             fadd    st(1), st
            #             fxch    st(1)
            #             fstp    [ebp+68h+var_24]
            #             fld     st(3)
            #             fld     [ebp+68h+var_38]
            #             fadd    st(1), st
            #             fxch    st(1)
            #             fstp    [ebp+68h+var_20]
            #             fxch    st(2)
            #             fsubrp  st(5), st
            #             fxch    st(4)
            #             fstp    [ebp+68h+var_34]
            #             fxch    st(3)
            #             fsubrp  st(1), st
            #             fstp    [ebp+68h+var_30]
            #             fsubp   st(1), st
            #             fstp    [ebp+68h+var_2C]
            #           }
            #           sub_4C6420((float *)&v137, &v170, &v167);
            #           __asm
            #           {
            #             fldz
            #             fstp    [ebp+68h+var_4]
            #           }
            #           if ( sub_5FF310(&v137, (int)&v135, (int)&v178) || sub_5FF310(&v137, (int)&v134, (int)&v178) )
            #           {
            #             v109 = *(_DWORD *)(v87 + 36);
            #             v110 = *(_DWORD *)(v87 + 40);
            #             if ( *(_DWORD *)dword_E81230 )
            #             {
            #               word_E81030 = sub_89C850(23406, 0);
            #               dword_E81032 = v109;
            #               qword_E81036 = v110;
            #               v111 = sub_83D500(*(int *)dword_E81230, 4, &word_E81030, 0xEu);
            #               j_j_j___free_base(0);
            #               --dword_1071B24;
            #               if ( !v111 )
            #               {
            #                 sub_4EAE80((_DWORD *)dword_C9CD3C, (LPCRITICAL_SECTION **)dword_E81230);
            #                 sub_5F85C0(a9, a8, a10, v18);
            #                 return;
            #               }
            # LABEL_114:
            #               sub_83A320(*(int *)dword_E81230);
            #               sub_5F85C0(a9, a8, a10, v18);
            #               return;
            #             }
            #             if ( !byte_E90BC4 )
            #               sub_8EE420("Attempt to send message %d on a void connection.", 23406);
            #           }
            #           else
            #           {
            # LABEL_137:
            #             if ( sub_5C6440((float *)v87, (float *)dword_E81244) )
            #             {
            #               v112 = *(_DWORD *)(v87 + 36);
            #               v113 = *(_DWORD *)(v87 + 40);
            #               if ( *(_DWORD *)dword_E81230 )
            #               {
            #                 word_E81030 = sub_89C850(18464, 0);
            #                 dword_E81032 = v112;
            #                 LODWORD(qword_E81036) = v113;
            #                 HIDWORD(qword_E81036) = -1;
            #                 v114 = sub_83D500(*(int *)dword_E81230, 4, &word_E81030, 0xEu);
            #                 j_j_j___free_base(0);
            #                 --dword_1071B24;
            #                 if ( !v114 )
            #                 {
            #                   sub_4EAE80((_DWORD *)dword_C9CD3C, (LPCRITICAL_SECTION **)dword_E81230);
            #                   sub_5F85C0(a9, a8, a10, v18);
            #                   return;
            #                 }
            #                 goto LABEL_114;
            #               }
            #               if ( !byte_E90BC4 )
            #                 sub_8EE420("Attempt to send message %d on a void connection.", 18464);
            #             }
            #           }
            #         }
            #         else
            #         {
            #           v115 = (int *)sub_59A490();
            #           v116 = sub_59A6E0(v115, v85);
            #           if ( v116 )
            #           {
            #             _ECX = dword_E81244;
            #             __asm
            #             {
            #               fld     dword ptr [ecx+6Ch]
            #               fld     dword ptr [ecx+68h]
            #               fld     dword ptr [ecx+64h]
            #               fld1
            #               fstp    [esp+368h+var_350]; float
            #               fld     [ebp+68h+var_60]
            #               fstp    [esp+368h+var_354]; float
            #               fld     [ebp+68h+var_64]
            #               fstp    [esp+368h+var_358]; float
            #               fld     [ebp+68h+var_68]
            #               fstp    [esp+368h+var_35C]; float
            #               fxch    st(2)
            #               fstp    [esp+368h+var_360]; float
            #               fstp    [esp+368h+var_364]; float
            #               fstp    [esp+368h+var_368]; float
            #             }
            #             sub_53C760(v124, v123, v122, v121, v120, v119, v118);
            #             __asm
            #             {
            #               fcomp   ds:flt_ABF4D0
            #               fnstsw  ax
            #             }
            #             if ( !__SETP__(HIBYTE(_AX) & 5, 0) )
            #             {
            #               v126 = *(void **)(v116 + 8);
            #               if ( v126 && sub_898E20(v126) == 1 && sub_897510(*(void **)(v116 + 8)) == 53 )
            #               {
            #                 v127 = (char *)sub_8B4830(dword_E81028, 5472, 0);
            #                 sub_4E4FB0();
            #                 sub_4E56A0(v127, (LPVOID)0xF, (LPVOID)1, (LPVOID)1, 0);
            #                 v128 = sub_8B4830(dword_E81028, 5472, 0);
            #                 sub_7BEE80((int *)dword_1051510, 0, 11, (int)v128, 1u, -1, 0, 1);
            #                 return;
            #               }
            #               v129 = *(_DWORD *)(v116 + 12);
            #               v130 = *((_DWORD *)dword_E81244 + 84);
            #               ++dword_F2F92C;
            #               ++dword_F2F930;
            #               LOBYTE(v146) = 0;
            #               sub_4C5DC0((_DWORD *)(dword_F3554C + 235028), 3);
            #               sub_4C5DA0((_DWORD *)(dword_F3554C + 235028), 13);
            #               if ( !byte_E90BC4 && !dword_E90D08 )
            #               {
            #                 if ( *(_DWORD *)dword_E81230 )
            #                 {
            #                   word_E81030 = sub_89C850(18234, 0);
            #                   dword_E81032 = v129;
            #                   LODWORD(qword_E81036) = v130;
            #                   HIDWORD(qword_E81036) = v146;
            #                   v131 = sub_83D500(*(int *)dword_E81230, 4, &word_E81030, 0xEu);
            #                   j_j_j___free_base(0);
            #                   --dword_1071B24;
            #                   if ( !v131 )
            #                   {
            #                     sub_4EAE80((_DWORD *)dword_C9CD3C, (LPCRITICAL_SECTION **)dword_E81230);
            #                     (*(void (**)(void))(*(_DWORD *)dword_DCF008 + 144))();
            #                     return;
            #                   }
            #                 }
            #                 else
            #                 {
            #                   sub_8EE420("Attempt to send message %d on a void connection.", 18234);
            #                 }
            #               }
            #               (*(void (**)(void))(*(_DWORD *)dword_DCF008 + 144))();
            #               return;
            #             }
            #           }
            #         }
            #       }
            #     }
            # LABEL_109:
            #     sub_5F85C0(a9, a8, a10, v18);
            #     return;
            #   }
            #   v38 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #   sub_4B3150(&a10, 33);
            #   v40 = *v39;
            #   v153 = 2;
            #   v41 = sub_898E20(v40);
            #   v153 = -1;
            #   v42 = v41 == 0;
            #   sub_592520(&a10);
            #   if ( v42 )
            #   {
            #     v43 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #     v44 = sub_4B3150(&a10, 33);
            #     v46 = *v45;
            #     v153 = 3;
            #     v47 = sub_897EB0(v46);
            #     v153 = -1;
            #     v48 = v47;
            #     sub_592520(&a10);
            #     if ( v48 == 12 || v48 == 33 || v48 == 39 )
            #     {
            #       sub_5F85C0(v44, a8, v17, v18);
            #       return;
            #     }
            #   }
            #   v49 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #   v50 = sub_4B3150(&v175[1], 33);
            #   v52 = *v51;
            #   v53 = v173 | 8;
            #   v153 = 4;
            #   v178 = v173 | 8;
            #   HIBYTE(a10) = sub_89A910(v52)
            #              && (*((_DWORD *)sub_663F50(v50) + 537) != -1
            #               && !(((unsigned int)sub_926DF0((_BYTE *)dword_16CC524) >> 1) & 1)
            #               || (v54 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4),
            #                   v50 = sub_4B3150(&a11, 33),
            #                   v56 = *v55,
            #                   v53 |= 0x10u,
            #                   v153 = 5,
            #                   v178 = v53,
            #                   !sub_89A2C0(v56)));
            #   if ( v53 & 0x10 )
            #     sub_592520(&a11);
            #   v153 = -1;
            #   sub_592520(&v175[1]);
            #   if ( !HIBYTE(a10) )
            #   {
            #     v64 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #     sub_4B3150(&a10, 33);
            #     v66 = **v65;
            #     v153 = 7;
            #     v67 = (*(int (__stdcall **)(signed int, signed int, _DWORD, signed int))(v66 + 28))(1, 1, 0, 1);
            #     v153 = -1;
            #     v68 = v67 == 0;
            #     sub_592520(&a10);
            #     if ( v68 )
            #       return;
            #     v69 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #     sub_4B3150(&a10, 33);
            #     v71 = *v70;
            #     v153 = 8;
            #     v72 = sub_89A7C0(v71, 1);
            #     v153 = -1;
            #     v73 = v72;
            #     sub_592520(&a10);
            #     if ( v73 )
            #     {
            #       v74 = (char *)sub_8B4830(dword_E81028, 7697, 0);
            #     }
            #     else
            #     {
            #       if ( dword_E92278 == 1 )
            #       {
            #         sub_5D14B0(dword_E92278);
            #         return;
            #       }
            #       if ( dword_E92278 != -1 )
            #       {
            #         v76 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #         sub_4B3150(&a10, 33);
            #         v78 = *v77;
            #         v153 = 9;
            #         v79 = sub_898730(v78);
            #         sub_59A7C0((int)&v133, 9057, v79, 0, 0, 0, 0, 0, 0, 0, v132);
            #         v153 = -1;
            #         sub_592520(&a10);
            #         if ( dword_F3554C )
            #           v80 = dword_F3554C + 8;
            #         else
            #           v80 = 0;
            #         sub_7BEE80((int *)dword_1051510, v80, 108, (int)&v133, 0xCu, 20000, 0, 1);
            #         return;
            #       }
            #       v74 = (char *)sub_8B4830(dword_E81028, 12320, 0);
            #     }
            #     v75 = v74;
            #     sub_4E4FB0();
            #     sub_4E56A0(v75, (LPVOID)0x111, (LPVOID)1, (LPVOID)1, 0);
            #     return;
            #   }
            #   if ( !*((_BYTE *)sub_663F50(v50) + 2164) )
            #   {
            #     sub_5FE6C0(v138);
            #     v142 = 1;
            #     v57 = *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4);
            #     v58 = sub_4B3150(&a10, 33);
            #     v60 = (char *)(*v59 + 256);
            #     v153 = 6;
            #     sub_8F1E60(v138, v60);
            #     v153 = -1;
            #     sub_592520(&a10);
            #     v139 = 0;
            #     HIWORD(v175[0]) = 33;
            #     LOWORD(v175[1]) = -1;
            #     LOWORD(v156) = -1;
            #     v140 = *(_DWORD *)((char *)v175 + 2);
            #     v141 = v156;
            #     v143 = 1;
            #     v144 = v17;
            #     v145 = v18;
            #     if ( *(_DWORD *)dword_E81230 )
            #     {
            #       word_E81030 = sub_89C850(5608, 0);
            #       qmemcpy(&dword_E81032, v138, 0x3Cu);
            #       v61 = sub_83D500(*(int *)dword_E81230, 4, &word_E81030, 0x3Eu);
            #       j_j_j___free_base(0);
            #       --dword_1071B24;
            #       if ( v61 )
            #         sub_83A320(*(int *)dword_E81230);
            #       else
            #         sub_4EAE80((_DWORD *)dword_C9CD3C, (LPCRITICAL_SECTION **)dword_E81230);
            #       v62 = sub_663F50(v58);
            #       sub_667C80(v62);
            #     }
            #     else
            #     {
            #       if ( !byte_E90BC4 )
            #         sub_8EE420("Attempt to send message %d on a void connection.", 5608);
            #       v63 = sub_663F50(v58);
            #       sub_667C80(v63);
            #     }
            #   }
            # }
            if functionString.find("while ( ShowCursor(1) < 0 )") != -1:
                if functionString.find("SetCursorPos") != -1:
                    if functionString.find("\"POINT1\"") != -1:
                        if functionString.find("\"POINT2\"") != -1:
                            if functionString.find("\"POINT3\"") != -1:
                                if functionString.find("\"POINT4\"") != -1:
                                    if functionString.find(", 0x3020u,") != -1 or functionString.find(", 12320,") != -1: # 12320 You currently cannot drop items.  Goto General Options or use /fastdrop to enable dropping.
                                        functionList["CEverQuest__LMouseUp"] = functionAddress

            # CEverQuest__RMouseUp
            # ----------------------------------------------------------------------------------------------------
            # void __userpurge sub_5D49C0(int a1@<ecx>, double a2@<st0>, long double st6_0@<st1>, int a3, int a4)
            # {
            #   int v5; // ecx
            #   _DWORD *v6; // eax
            #   int v7; // edx
            #   signed int v8; // esi
            #   _BYTE *v9; // eax
            #   _BYTE *v10; // eax
            #   int v11; // ebx
            #   int v12; // ebp
            #   int v13; // eax
            #   int v14; // edi
            #   int v15; // ST1C_4
            #   int *v16; // eax
            #   int v17; // esi
            #   float *v18; // eax
            #   double v19; // st7
            #   int v20; // eax
            #   double v21; // st4
            #   double v22; // st5
            #   double v23; // rt1
            #   double v24; // st4
            #   int v25; // ST0C_4
            #   int v26; // ST08_4
            #   _DWORD *v27; // eax
            #   _WORD *v28; // ebp
            #   char v29; // bl
            #   int v30; // eax
            #   _DWORD *v31; // esi
            #   int v32; // ST0C_4
            #   int v33; // ST08_4
            #   _DWORD *v34; // eax
            #   _WORD *v35; // ebp
            #   char v36; // bl
            #   int v37; // eax
            #   _BYTE *v38; // edi
            #   float *v39; // esi
            #   float v40; // [esp+14h] [ebp-660h]
            #   float v41; // [esp+18h] [ebp-65Ch]
            #   float v42; // [esp+1Ch] [ebp-658h]
            #   float v43; // [esp+20h] [ebp-654h]
            #   float v44; // [esp+24h] [ebp-650h]
            #   float v45; // [esp+28h] [ebp-64Ch]
            #   int v46; // [esp+2Ch] [ebp-648h]
            #   int v47; // [esp+30h] [ebp-644h]
            #   int v48; // [esp+34h] [ebp-640h]
            #   int v49; // [esp+38h] [ebp-63Ch]
            #   char v50; // [esp+3Ch] [ebp-638h]
            #   char v51; // [esp+4Ah] [ebp-62Ah]
            #   char v52; // [esp+5Ch] [ebp-618h]
            #   char v53; // [esp+68h] [ebp-60Ch]
            #   char v54; // [esp+74h] [ebp-600h]
            #   char v55; // [esp+374h] [ebp-300h]
            #
            #   v47 = a1;
            #   if ( dword_F3633C == -572662307 && *((_BYTE *)&off_C06EC5 - 2) )
            #   {
            #     v5 = 0;
            #     v6 = (_DWORD *)572662306;
            #     v7 = 0;
            #     v8 = 32;
            #     do
            #     {
            #       v5 += *v6;
            #       v6 += 2;
            #       v7 += *(v6 - 1);
            #       --v8;
            #     }
            #     while ( v8 );
            #     *((_BYTE *)&off_C06EC5 - 2) = v7 + v5 == 858993459;
            #   }
            #   if ( sub_535C90(dword_E81024) )
            #   {
            #     byte_E90BE3 = 0;
            #     if ( !(_BYTE)word_E90C72 )
            #       goto LABEL_60;
            #     if ( HIBYTE(word_E90C72) )
            #     {
            #       LOBYTE(word_E90C72) = 0;
            #       if ( *(_DWORD *)(dword_F3554C + 1480) == 5 )
            #       {
            #         v9 = sub_612920();
            #         if ( !sub_612A00(v9) )
            #         {
            #           while ( ShowCursor(1) < 0 )
            #             ;
            #           SetCursorPos(*(_DWORD *)(dword_16CC524 + 312), *(_DWORD *)(dword_16CC524 + 316));
            #         }
            #       }
            #       if ( (unsigned int)(*((_DWORD *)dword_E81024 + 85) - dword_E90D14) > 0x1F4 )
            #       {
            #         sub_6A4FB0();
            #         return;
            #       }
            #     }
            #     if ( !(_BYTE)word_E90C72 )
            #     {
            # LABEL_60:
            #       v10 = sub_612920();
            #       if ( !sub_612A00(v10) )
            #       {
            #         v11 = a4;
            #         v12 = a3;
            #         v13 = sub_539030(dword_E81024, a3, a2, st6_0, a3, a4, 0, (int)&v53, (int)&v52);
            #         v14 = v13;
            #         if ( v13 )
            #         {
            #           v15 = v13;
            #           v16 = (int *)sub_5C6CB0();
            #           v17 = sub_5C6E90(v16, v15);
            #           if ( v17 )
            #           {
            #             v18 = (float *)(*(int (__thiscall **)(int))(*(_DWORD *)v14 + 124))(v14);
            #             v43 = *v18;
            #             v44 = v18[1];
            #             v19 = v18[2];
            #             v20 = *(_DWORD *)v14;
            #             v45 = v19;
            #             (*(void (__thiscall **)(int))(v20 + 96))(v14);
            #             v21 = v44 - *((float *)dword_E81244 + 26);
            #             v22 = v45 - *((float *)dword_E81244 + 27);
            #             v23 = v21 * v21;
            #             v24 = v43 - *((float *)dword_E81244 + 25);
            #             st6_0 = sqrt(v23 + v24 * v24 + v22 * v22);
            #             a2 = v19 + *((float *)dword_E81244 + 79) + 50.0;
            #             if ( st6_0 <= a2 || *((_DWORD *)sub_663F50(a2) + 537) == *(_DWORD *)(v17 + 36) )
            #             {
            #               v40 = -6.8056469e38/*NaN*/;
            #               v25 = *(_DWORD *)(v17 + 40);
            #               v41 = -6.8056469e38/*NaN*/;
            #               v26 = *(_DWORD *)(v17 + 36);
            #               LOWORD(v42) = -1;
            #               v27 = sub_8F1AD0(&v51);
            #               sub_5FE710(&v54, (int)v27, &v40, v26, v25, a3, a4, 0, -1);
            #               if ( *(_DWORD *)dword_E81230 )
            #               {
            #                 v28 = operator new[](0x302u);
            #                 *v28 = sub_89C850(27805, 0);
            #                 qmemcpy(v28 + 1, &v54, 0x300u);
            #                 v29 = sub_83D500(*(int *)dword_E81230, 4, v28, 0x302u);
            #                 j_j_j___free_base(v28);
            #                 --dword_1071B24;
            #                 if ( v29 )
            #                   sub_83A320(*(int *)dword_E81230);
            #                 else
            #                   sub_4EAE80((_DWORD *)dword_C9CD3C, (LPCRITICAL_SECTION **)dword_E81230);
            #                 v11 = a4;
            #                 v12 = a3;
            #               }
            #               else if ( !byte_E90BC4 )
            #               {
            #                 sub_8EE420("Attempt to send message %d on a void connection.", 27805);
            #               }
            #             }
            #           }
            #         }
            #         if ( (!dword_DCE92C || *(_DWORD *)(dword_F3554C + 1480) != 1) && *(_DWORD *)(dword_F3554C + 1480) != 2 )
            #         {
            #           if ( dword_104C168 )
            #             sub_6EAE00(dword_104C168, v12, v11);
            #           v48 = v12;
            #           v49 = v11;
            #           v46 = 0;
            #           if ( !sub_9240E0((_DWORD *)dword_16CC524, &v48, &v46) )
            #           {
            #             if ( *(_DWORD *)(v47 + 1472) )
            #             {
            #               sub_5F99F0((LPVOID *)v47);
            #               return;
            #             }
            #             v30 = sub_5DC470(v12, a2, st6_0, v12, v11);
            #             v31 = (_DWORD *)v30;
            #             if ( !v30 )
            #               goto LABEL_52;
            #             if ( *(_DWORD *)(v30 + 424) != -1 )
            #             {
            #               v40 = *(float *)(v30 + 100);
            #               v41 = *(float *)(v30 + 104);
            #               v42 = *(float *)(v30 + 108);
            #               a2 = sub_5CEC80(&v40, (float *)dword_E81244 + 25);
            #               if ( a2 > 60.0 && *((_DWORD *)sub_663F50(a2) + 537) != v31[106] )
            #               {
            # LABEL_52:
            #                 v37 = sub_5F8580(v12, a2, st6_0, v12, v11, (int)&v50, (int)&v40);
            #                 if ( v37 )
            #                 {
            #                   if ( *(_BYTE *)(v37 + 38) == -95 )
            #                   {
            #                     v38 = (_BYTE *)dword_DCE8F8;
            #                     if ( dword_DCE8F8 )
            #                     {
            #                       v39 = (float *)dword_E81244;
            #                       if ( v39[79] + 20.0 >= sub_5CEC80((float *)&v50, (float *)dword_E81244 + 25) && !v38[208] )
            #                         (*(void (__thiscall **)(_BYTE *, signed int, signed int, signed int))(*(_DWORD *)v38 + 216))(
            #                           v38,
            #                           1,
            #                           1,
            #                           1);
            #                     }
            #                   }
            #                 }
            #                 return;
            #               }
            #               if ( ((unsigned int)sub_926DF0((_BYTE *)dword_16CC524) >> 1) & 1
            #                 || !sub_65BCF0(v31) && !sub_65BD40(v31)
            #                 || (a2 = 20.0, !(unsigned __int8)sub_65B3B0((int)dword_E81244, (int)v31, 0, 20.0)) )
            #               {
            #                 v40 = -6.8056469e38/*NaN*/;
            #                 v32 = v31[332];
            #                 v41 = -6.8056469e38/*NaN*/;
            #                 v33 = v31[106];
            #                 LOWORD(v42) = -1;
            #                 v34 = sub_8F1AD0(&v51);
            #                 sub_5FE710(&v55, (int)v34, &v40, v33, v32, v12, v11, 0, -1);
            #                 if ( *(_DWORD *)dword_E81230 )
            #                 {
            #                   v35 = operator new[](0x302u);
            #                   *v35 = sub_89C850(27805, 0);
            #                   qmemcpy(v35 + 1, &v55, 0x300u);
            #                   v36 = sub_83D500(*(int *)dword_E81230, 4, v35, 0x302u);
            #                   j_j_j___free_base(v35);
            #                   --dword_1071B24;
            #                   if ( v36 )
            #                     sub_83A320(*(int *)dword_E81230);
            #                   else
            #                     sub_4EAE80((_DWORD *)dword_C9CD3C, (LPCRITICAL_SECTION **)dword_E81230);
            #                   v11 = a4;
            #                   v12 = a3;
            #                 }
            #                 else if ( !byte_E90BC4 )
            #                 {
            #                   sub_8EE420("Attempt to send message %d on a void connection.", 27805);
            #                 }
            #                 goto LABEL_52;
            #               }
            #             }
            #             sub_5D5F90(v31, 0);
            #             goto LABEL_52;
            #           }
            #         }
            #       }
            #     }
            #   }
            # }
            if functionString.find("while ( ShowCursor(1) < 0 )") != -1:
                if functionString.find("SetCursorPos") != -1:
                    if functionString.find("-572662307") != -1:
                        if functionString.find("858993459") != -1:
                            if functionString.find("572662306") != -1:
                                functionList["CEverQuest__RMouseUp"] = functionAddress

            # CEverQuest__HandleMouseWheel
            # ----------------------------------------------------------------------------------------------------
            # void __thiscall sub_5D50A0(float *this, int a2)
            # {
            #   int v2; // edi
            #   float *v3; // esi
            #   _DWORD *v4; // eax
            #   double v5; // st7
            #   int v6; // eax
            #   long double v7; // st7
            #   bool v8; // c0
            #   bool v9; // c3
            #   double v10; // st6
            #   long double v11; // st5
            #   double v12; // st4
            #   double v13; // st6
            #   double v14; // rt1
            #   long double v15; // st4
            #   long double v16; // rt2
            #   double v17; // st4
            #   long double v18; // st6
            #   long double v19; // st3
            #   long double v20; // st2
            #   int v21; // eax
            #   bool v22; // c0
            #   double v23; // st6
            #   long double v24; // rtt
            #   long double v25; // st3
            #   long double v26; // st6
            #   long double v27; // st4
            #   double v28; // st7
            #   long double v29; // st6
            #   float v30; // ST04_4
            #   long double v31; // st7
            #   long double v32; // st6
            #   float v33; // ST04_4
            #   double v34; // rt1
            #   long double v35; // rt2
            #   long double v36; // st5
            #   float v37; // [esp+10h] [ebp-1Ch]
            #   float v38; // [esp+14h] [ebp-18h]
            #   float v39; // [esp+18h] [ebp-14h]
            #   float v40; // [esp+1Ch] [ebp-10h]
            #   float v41; // [esp+1Ch] [ebp-10h]
            #   float v42; // [esp+34h] [ebp+8h]
            #   float v43; // [esp+34h] [ebp+8h]
            #
            #   v2 = *((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + TlsIndex);
            #   v3 = this;
            #   if ( dword_F2F9D4 > *(_DWORD *)(v2 + 4) )
            #   {
            #     _Init_thread_header(&dword_F2F9D4);
            #     if ( dword_F2F9D4 == -1 )
            #     {
            #       dword_F2F9D0 = sub_8EE0E0();
            #       _Init_thread_footer(&dword_F2F9D4);
            #     }
            #   }
            #   if ( dword_F2F9DC > *(_DWORD *)(v2 + 4) )
            #   {
            #     _Init_thread_header(&dword_F2F9DC);
            #     if ( dword_F2F9DC == -1 )
            #     {
            #       dword_F2F9D8 = sub_8EE0E0();
            #       _Init_thread_footer(&dword_F2F9DC);
            #     }
            #   }
            #   v40 = *(float *)(dword_E922B4 + 52);
            #   v39 = 3.0;
            #   v38 = 53.0;
            #   v4 = sub_663F50(53.0);
            #   if ( sub_8D5E50(v4[536]) )
            #     v38 = 212.0;
            #   if ( dword_E81244 && sub_64E1B0(dword_E81244) )
            #     v39 = *(float *)(sub_64E1B0(dword_E81244) + 80);
            #   v37 = (double)(unsigned int)(sub_8EE0E0() - dword_F2F9D0);
            #   dword_F2F9D0 = sub_8EE0E0();
            #   if ( !sub_535C90(dword_E81024) )
            #   {
            #     v3[379] = v40;
            #     return;
            #   }
            #   if ( *(_DWORD *)(dword_F3554C + 1480) == 1 || dword_DCE94C != 6 && dword_DCE94C )
            #   {
            #     (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E922B4 + 24))(0.0);
            #     v3[379] = 0.0;
            #     return;
            #   }
            #   if ( !dword_E81020 || sub_8A6110(dword_E81020) >= 70 )
            #   {
            #     (*(void (__stdcall **)(float))(*(_DWORD *)dword_E922B4 + 24))(COERCE_FLOAT(LODWORD(v39)));
            #     v3[379] = v39;
            #     return;
            #   }
            #   if ( dword_E9223C )
            #   {
            #     v5 = 0.0;
            #     if ( a2 <= 0 )
            #     {
            #       if ( a2 >= 0 )
            #       {
            #         v18 = v40;
            #         v11 = v39;
            #         v17 = v38;
            # LABEL_34:
            #         v19 = 100.0;
            #         v20 = fabs(v3[379] - v18);
            #         if ( v20 < 5.0 )
            #           v19 = v20 * 18.0 + 10.0;
            #         v24 = v19 * v37 * 0.001;
            #         v25 = v18;
            #         v26 = v24;
            #         if ( v25 <= v3[379] )
            #         {
            #           v34 = v17;
            #           v27 = v25;
            #           v28 = v34;
            #           if ( v25 >= v3[379] )
            #             return;
            #           if ( dword_DCE94C != 6 )
            #           {
            #             v32 = v25;
            #             if ( !dword_DCE94C )
            #             {
            #               v41 = v11;
            #               sub_538470(6);
            #               if ( dword_E81244 )
            #               {
            #                 (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E922B4 + 20))(*((float *)dword_E81244 + 36));
            #                 (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E922B4 + 32))(*((float *)dword_E81244 + 32));
            #                 if ( !HIBYTE(word_E90C72) )
            #                 {
            #                   HIBYTE(word_E90C72) = 1;
            #                   (*(void (__stdcall **)(LPVOID))(*(_DWORD *)dword_E922B4 + 8))(dword_E81244);
            #                   HIBYTE(word_E90C72) = 0;
            #                 }
            #               }
            #               goto LABEL_59;
            #             }
            # LABEL_61:
            #             v31 = v32;
            #             goto LABEL_62;
            #           }
            #           if ( v25 < v28 )
            #           {
            #             v35 = v11;
            #             v36 = v26 + v25;
            #             v32 = v35;
            #             if ( v36 <= v28 )
            #             {
            #               v28 = v36;
            #               if ( v3[379] < v36 )
            #                 v28 = v3[379];
            #             }
            #             if ( v32 <= v28 )
            #               goto LABEL_52;
            #             goto LABEL_61;
            #           }
            #         }
            #         else
            #         {
            #           v27 = v25;
            #           if ( dword_DCE94C == 6 )
            #           {
            #             if ( v25 > v11 )
            #             {
            #               v28 = v11;
            #               v29 = v25 - v26;
            #               if ( v29 < v11 )
            #               {
            # LABEL_52:
            #                 v30 = v28;
            #                 (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E922B4 + 24))(LODWORD(v30));
            #                 return;
            #               }
            #               v31 = v29;
            #               if ( v29 < v3[379] )
            #               {
            #                 (*(void (__stdcall **)(float))(*(_DWORD *)dword_E922B4 + 24))(v3[379]);
            #                 return;
            #               }
            # LABEL_62:
            #               v33 = v31;
            #               (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_E922B4 + 24))(LODWORD(v33));
            #               return;
            #             }
            #             v41 = v5;
            #             sub_538470(0);
            #             if ( dword_E81244 )
            #               *((float *)dword_E81244 + 36) = *(float *)(dword_E922B4 + 48);
            #             if ( !(*(unsigned __int8 (**)(void))(*(_DWORD *)dword_E8131C + 88))() )
            #               *(float *)(dword_E8131C + 144) = *(float *)(dword_E922B4 + 48);
            # LABEL_59:
            #             (*(void (__stdcall **)(float))(*(_DWORD *)dword_E922B4 + 24))(COERCE_FLOAT(LODWORD(v41)));
            #             return;
            #           }
            #         }
            #         v32 = v27;
            #         goto LABEL_61;
            #       }
            #       v43 = 1.0;
            #       if ( (unsigned int)(sub_8EE0E0() - dword_F2F9D8) < 0x32 )
            #         v43 = 5.0;
            #       v21 = sub_8EE0E0();
            #       v7 = v40;
            #       v22 = v40 < (double)v3[379];
            #       dword_F2F9D8 = v21;
            #       if ( v22 )
            #         v23 = v3[379] + v43;
            #       else
            #         v23 = v43 + v7;
            #       v3[379] = v23;
            #       v13 = v38;
            #       if ( v38 < (double)v3[379] )
            #         v3[379] = v38;
            #       v11 = v39;
            #       if ( v39 > (double)v3[379] )
            #         v3[379] = v39;
            #       v12 = 0.0;
            #     }
            #     else
            #     {
            #       v42 = 1.0;
            #       if ( (unsigned int)(sub_8EE0E0() - dword_F2F9D8) < 0x32 )
            #         v42 = 5.0;
            #       v6 = sub_8EE0E0();
            #       v7 = v40;
            #       v8 = v40 < (double)v3[379];
            #       v9 = v40 == v3[379];
            #       dword_F2F9D8 = v6;
            #       if ( v8 || v9 )
            #         v10 = v40;
            #       else
            #         v10 = v3[379];
            #       v3[379] = v10 - v42;
            #       if ( v3[379] < 0.0 )
            #         v3[379] = 0.0;
            #       v11 = v39;
            #       v12 = 0.0;
            #       v13 = v38;
            #     }
            #     v14 = v12;
            #     v15 = v7;
            #     v5 = v14;
            #     v16 = v15;
            #     v17 = v13;
            #     v18 = v16;
            #     goto LABEL_34;
            #   }
            #   if ( dword_DCE94C == 6 )
            #   {
            #     (*(void (__stdcall **)(float))(*(_DWORD *)dword_E922B4 + 24))(COERCE_FLOAT(LODWORD(v39)));
            #     v3[379] = v39;
            #     sub_538470(0);
            #     if ( dword_E81244 )
            #       *((float *)dword_E81244 + 36) = 0.0;
            #   }
            # }
            if functionString.find("= fabs(") != -1:
                if functionString.find(" = 53.0;") != -1:
                    if functionString.find(" = 212.0;") != -1:
                        if functionString.find(" = 100.0;") != -1:
                            if functionString.find("< 5.0") != -1:
                                if functionString.find("+ 10.0;") != -1:
                                    functionList["CEverQuest__HandleMouseWheel"] = functionAddress

            # CEverQuest__StartCasting
            # ----------------------------------------------------------------------------------------------------
            # void __userpurge sub_5DEBB0(float a1@<ecx>, double a2@<st0>, int *a3)
            # {
            #   int *v3; // edi
            #   int v4; // esi
            #   double v5; // st7
            #   void (__stdcall *v6)(_DWORD); // eax
            #   double v7; // st7
            #   double v8; // st7
            #   float v9; // ST18_4
            #   double v10; // st7
            #   float v11; // ST2C_4
            #   char v12; // al
            #   double v13; // st7
            #   int v14; // ebx
            #   int v15; // eax
            #   int v16; // eax
            #   int v17; // eax
            #   int v18; // eax
            #   char v19; // al
            #   float v20; // eax
            #   _DWORD *v21; // esi
            #   char *v22; // eax
            #   volatile signed __int32 **v23; // esi
            #   signed int v24; // eax
            #   volatile signed __int32 *v25; // esi
            #   char *v26; // edi
            #   LPVOID v27; // esi
            #   LPVOID v28; // edi
            #   CHAR *v29; // eax
            #   _DWORD *v30; // eax
            #   void (__thiscall **v31)(LPVOID, char *, signed int, signed int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // edx
            #   int v32; // ST0C_4
            #   char *v33; // ecx
            #   unsigned int v34; // edi
            #   _BYTE *v35; // edi
            #   LPVOID v36; // esi
            #   _DWORD *v37; // eax
            #   void (__thiscall **v38)(LPVOID, char *, signed int, signed int, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // edx
            #   int v39; // ST10_4
            #   char *v40; // ecx
            #   int v41; // eax
            #   _BYTE *v42; // edi
            #   LPVOID v43; // esi
            #   _DWORD *v44; // eax
            #   void (__thiscall **v45)(LPVOID, char *, signed int, signed int, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // edx
            #   int v46; // ST10_4
            #   _BYTE *v47; // edi
            #   LPVOID v48; // esi
            #   _DWORD *v49; // eax
            #   void (__thiscall **v50)(LPVOID, char *, signed int, signed int, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // edx
            #   int v51; // ST10_4
            #   _BYTE *v52; // edi
            #   LPVOID v53; // esi
            #   _DWORD *v54; // eax
            #   void (__thiscall **v55)(LPVOID, char *, signed int, signed int, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // edx
            #   int v56; // ST10_4
            #   signed int v57; // [esp-8h] [ebp-80h]
            #   signed int v58; // [esp-4h] [ebp-7Ch]
            #   int v59; // [esp+0h] [ebp-78h]
            #   char v60; // [esp+34h] [ebp-44h]
            #   char v61; // [esp+44h] [ebp-34h]
            #   int v62; // [esp+48h] [ebp-30h]
            #   float v63; // [esp+4Ch] [ebp-2Ch]
            #   float v64; // [esp+50h] [ebp-28h]
            #   volatile signed __int32 *v65; // [esp+54h] [ebp-24h]
            #   char v66; // [esp+58h] [ebp-20h]
            #   float v67; // [esp+5Ch] [ebp-1Ch]
            #   float v68; // [esp+60h] [ebp-18h]
            #   float v69; // [esp+64h] [ebp-14h]
            #   bool v70; // [esp+6Bh] [ebp-Dh]
            #   int v71; // [esp+74h] [ebp-4h]
            #   float v72; // [esp+80h] [ebp+8h]
            #   int v73; // [esp+80h] [ebp+8h]
            #   int *v74; // [esp+80h] [ebp+8h]
            #   char *v75; // [esp+80h] [ebp+8h]
            #   char *v76; // [esp+80h] [ebp+8h]
            #   char *v77; // [esp+80h] [ebp+8h]
            #   char *v78; // [esp+80h] [ebp+8h]
            #   char *v79; // [esp+80h] [ebp+8h]
            #   char v80; // [esp+83h] [ebp+Bh]
            #
            #   v3 = a3;
            #   v65 = 0;
            #   v69 = a1;
            #   v4 = sub_6513F0((_DWORD **)dword_F32B08, *((unsigned __int16 *)a3 + 2));
            #   if ( !v4 )
            #     return;
            #   if ( *a3 == -1 )
            #   {
            #     v69 = (double)*(unsigned int *)((char *)a3 + 6);
            #     v72 = *(float *)(v4 + 100);
            #     v5 = *(float *)(v4 + 128);
            #     (*(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_16CD370 + 12))(*(float *)(v4 + 128));
            #     v6 = *(void (__stdcall **)(_DWORD))(*(_DWORD *)dword_16CD370 + 8);
            #     *(float *)&v73 = v5 * v69 + v72;
            #     v67 = *(float *)(v4 + 104);
            #     v7 = *(float *)(v4 + 128);
            #     v6(*(float *)(v4 + 128));
            #     v8 = v7 * v69 + v67;
            #     v69 = v8;
            #     *(float *)&v62 = -1.0;
            #     v63 = -1.0;
            #     v64 = 1.0;
            #     v9 = v8;
            #     v10 = sub_535D50((int)dword_E81024, *(float *)&v73, v9, *(float *)(v4 + 108), 0.0, (int)&v62, 0, 0, COERCE_INT(1.0))
            #         + 3.0;
            #     v68 = v10;
            #     v11 = v10;
            #     v12 = sub_535D10(*(float *)&v73, v69, v11, 0);
            #     if ( v12 && v12 != 3 && v12 != 7 )
            #     {
            #       v13 = sub_53CB80(*(float *)&v73, v69, v68);
            #       v67 = v13;
            #       if ( -9.9999999e26 != v13 )
            #       {
            #         v62 = v73;
            #         v63 = v69;
            #         v64 = v68;
            #         sub_5FADA0(2, (int)&unk_DFA390, 61, v4, 0, 0, (float *)&v62, 0, 500);
            #         sub_53AD80(*(float *)&v73, v69, v67, 99);
            #       }
            #     }
            #     return;
            #   }
            #   if ( sub_564EB0(*a3) )
            #     v14 = (*(int (__stdcall **)(int))(*(_DWORD *)dword_F34280 + 32))(*a3);
            #   else
            #     v14 = 0;
            #   v15 = sub_4F19E0((char *)dword_F34280, *a3);
            #   v74 = (int *)v15;
            #   if ( v14 && v15 )
            #   {
            #     if ( sub_5670A0((_DWORD *)v14) )
            #     {
            #       v16 = *((_DWORD *)dword_E81024 + 85);
            #       *(_DWORD *)(v4 + 3980) = 1250;
            #       *(_DWORD *)(v4 + 3976) = v16 + 1000;
            #       *(_DWORD *)(v4 + 3984) = *v3;
            #       v17 = sub_64E270((_DWORD *)v4);
            #       (*(void (__thiscall **)(int, _DWORD, signed int, _DWORD, _DWORD, signed int, _DWORD, _DWORD))(*(_DWORD *)v17 + 12))(
            #         v17,
            #         *(unsigned __int8 *)(v14 + 400),
            #         1,
            #         0,
            #         1.0,
            #         1,
            #         *(unsigned __int8 *)(v14 + 401),
            #         0);
            #       return;
            #     }
            #     v18 = sub_647B10((_DWORD *)v4, a2, *(unsigned __int8 *)(v14 + 400), *(unsigned __int8 *)(v14 + 401), 1);
            #     sub_5FB720(0, (_DWORD *)v14, v74, v4, (float *)v4, 0, 0, *(int *)((char *)v3 + 6) + v18);
            #     v70 = v4 == (_DWORD)dword_E81244;
            #     if ( (LPVOID)v4 == dword_E81244
            #       && *(unsigned int *)((char *)v3 + 6) > 0x64
            #       && !*((_DWORD *)dword_E81244 + 292)
            #       && *((_DWORD *)dword_E81244 + 293) == -1 )
            #     {
            #       *((_DWORD *)dword_E81244 + 293) = *v3;
            #       *((_DWORD *)dword_E81244 + 292) = *(int *)((char *)v3 + 6) + sub_8EE0E0();
            #     }
            #     if ( (*((_BYTE *)v3 + 10) || !sub_984C90(&unk_E91FE8, 0x2Du))
            #       && !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 152))(v4) )
            #     {
            #       v19 = sub_566E90((_BYTE *)v14, dword_C07E38);
            #       if ( *(_DWORD *)(v4 + 4012) != dword_C07E38
            #         || *(_BYTE *)(v14 + 352)
            #         || (v80 = 1, (unsigned __int8)(v19 - 1) > 0xFDu) )
            #       {
            #         v80 = 0;
            #       }
            #       v20 = COERCE_FLOAT(sub_984C90(&unk_E91FE8, 9u));
            #       v67 = v20;
            #       if ( !v70 )
            #       {
            #         if ( dword_E81020 && (v33 = (char *)*((_DWORD *)dword_E81020 + 2569)) != 0 )
            #         {
            #           v34 = sub_608B70(v33, v4);
            #           v20 = v67;
            #         }
            #         else
            #         {
            #           v34 = 0;
            #         }
            #         if ( v80 )
            #         {
            #           if ( v20 != 0.0 && (!v34 || LODWORD(v20) != 3) )
            #             return;
            #           v35 = sub_5F5C40((_DWORD *)LODWORD(v69), v4 + 164);
            #           *v35 = toupper((char)*v35);
            #           if ( dword_E81020 )
            #             v76 = (char *)dword_E81020 + *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4) + 8;
            #           else
            #             v76 = (char *)dword_E81020;
            #           v36 = sub_4E4FB0();
            #           v37 = sub_5FF1A0((_DWORD *)v14, &v61, 0);
            #           v38 = *(void (__thiscall ***)(LPVOID, char *, signed int, signed int, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v36;
            #           v39 = v37[1];
            #           v71 = 4;
            #           (*v38)(v36, v76, 8152, 378, v35, v39, 0, 0, 0, 0, 0, 0, 0, 0);
            #           v40 = &v61;
            #         }
            #         else if ( sub_4B33C0((_BYTE *)v4) )
            #         {
            #           v41 = sub_984C90(&unk_E91FE8, 7u);
            #           if ( v41 && (!v34 || v41 != 3) )
            #             return;
            #           v42 = sub_5F5C40((_DWORD *)LODWORD(v69), v4 + 164);
            #           *v42 = toupper((char)*v42);
            #           if ( dword_E81020 )
            #             v77 = (char *)dword_E81020 + *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4) + 8;
            #           else
            #             v77 = (char *)dword_E81020;
            #           v43 = sub_4E4FB0();
            #           v44 = sub_5FF1A0((_DWORD *)v14, &v61, 0);
            #           v45 = *(void (__thiscall ***)(LPVOID, char *, signed int, signed int, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v43;
            #           v46 = v44[1];
            #           v71 = 5;
            #           (*v45)(v43, v77, 12206, 288, v42, v46, 0, 0, 0, 0, 0, 0, 0, 0);
            #           v40 = &v61;
            #         }
            #         else if ( *(_DWORD *)(v4 + 1116) )
            #         {
            #           if ( sub_984C90(&unk_E91FE8, 0x16u) )
            #             return;
            #           v47 = sub_5F5C40((_DWORD *)LODWORD(v69), v4 + 164);
            #           *v47 = toupper((char)*v47);
            #           if ( dword_E81020 )
            #             v78 = (char *)dword_E81020 + *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4) + 8;
            #           else
            #             v78 = (char *)dword_E81020;
            #           v48 = sub_4E4FB0();
            #           v49 = sub_5FF1A0((_DWORD *)v14, &v61, 0);
            #           v50 = *(void (__thiscall ***)(LPVOID, char *, signed int, signed int, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v48;
            #           v51 = v49[1];
            #           v71 = 6;
            #           (*v50)(v48, v78, 12206, 336, v47, v51, 0, 0, 0, 0, 0, 0, 0, 0);
            #           v40 = &v61;
            #         }
            #         else
            #         {
            #           if ( sub_984C90(&unk_E91FE8, 8u) )
            #             return;
            #           v52 = sub_5F5C40((_DWORD *)LODWORD(v69), v4 + 164);
            #           *v52 = toupper((char)*v52);
            #           if ( dword_E81020 )
            #             v79 = (char *)dword_E81020 + *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4) + 8;
            #           else
            #             v79 = (char *)dword_E81020;
            #           v53 = sub_4E4FB0();
            #           v54 = sub_5FF1A0((_DWORD *)v14, &v60, 0);
            #           v55 = *(void (__thiscall ***)(LPVOID, char *, signed int, signed int, _BYTE *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v53;
            #           v56 = v54[1];
            #           v71 = 7;
            #           (*v55)(v53, v79, 12206, 288, v52, v56, 0, 0, 0, 0, 0, 0, 0, 0);
            #           v40 = &v60;
            #         }
            #         sub_504500(v40);
            #         return;
            #       }
            #       v21 = dword_E81244;
            #       if ( sub_4C64C0((int)dword_E81244 + 1168) )
            #       {
            #         if ( dword_E81020 )
            #           v22 = (char *)dword_E81020 + 9240;
            #         else
            #           v22 = 0;
            #         v23 = (volatile signed __int32 **)sub_655950(v21 + 292, &v66, (int)v22);
            #         v24 = 1;
            #       }
            #       else
            #       {
            #         v68 = 0.0;
            #         v23 = (volatile signed __int32 **)&v68;
            #         v24 = 2;
            #       }
            #       v25 = *v23;
            #       v65 = v25;
            #       if ( v25 )
            #         _InterlockedIncrement(v25 + 1);
            #       v71 = 0;
            #       if ( v24 & 2 )
            #       {
            #         LODWORD(v69) = v24 & 0xFFFFFFFD;
            #         sub_592520(&v68);
            #         LOBYTE(v24) = LOBYTE(v69);
            #       }
            #       if ( v24 & 1 )
            #         sub_592520(&v66);
            #       if ( v80 )
            #       {
            #         if ( LODWORD(v67) == 1 )
            #         {
            # LABEL_57:
            #           sub_592520(&v65);
            #           return;
            #         }
            #         if ( dword_E81020 )
            #           v26 = (char *)dword_E81020 + *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4) + 8;
            #         else
            #           v26 = 0;
            #         v27 = sub_4E4FB0();
            #         v59 = sub_5FF1A0((_DWORD *)v14, &v61, 0)[1];
            #         LOBYTE(v71) = 1;
            #         v58 = 378;
            #         v57 = 8065;
            #       }
            #       else
            #       {
            #         if ( v25 )
            #         {
            #           if ( dword_E81020 )
            #             v75 = (char *)dword_E81020 + *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4) + 8;
            #           else
            #             v75 = 0;
            #           v28 = sub_4E4FB0();
            #           v29 = sub_8992E0((void *)v25, 0);
            #           v30 = sub_5FF1A0((_DWORD *)v14, &v61, v29);
            #           v31 = *(void (__thiscall ***)(LPVOID, char *, signed int, signed int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v28;
            #           v32 = v30[1];
            #           LOBYTE(v71) = 2;
            #           (*v31)(v28, v75, 12205, 264, v32, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            #           goto LABEL_56;
            #         }
            #         if ( dword_E81020 )
            #           v26 = (char *)dword_E81020 + *(_DWORD *)(*((_DWORD *)dword_E81020 + 2) + 4) + 8;
            #         else
            #           v26 = 0;
            #         v27 = sub_4E4FB0();
            #         v59 = sub_5FF1A0((_DWORD *)v14, &v61, 0)[1];
            #         LOBYTE(v71) = 3;
            #         v58 = 264;
            #         v57 = 12205;
            #       }
            #       (**(void (__thiscall ***)(LPVOID, char *, signed int, signed int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v27)(
            #         v27,
            #         v26,
            #         v57,
            #         v58,
            #         v59,
            #         0,
            #         0,
            #         0,
            #         0,
            #         0,
            #         0,
            #         0,
            #         0,
            #         0);
            # LABEL_56:
            #       sub_504500(&v61);
            #       goto LABEL_57;
            #     }
            #   }
            # }
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
                if functionString.find(", 0x331Eu,") != -1 or functionString.find(", 13086,") != -1:    # 13086 You say, '%1'
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
                    if functionString.find(", 0x21u);") != -1:
                        if functionString.find(", 0xFFFFFFFF);") != -1:
                            if functionString.find("result = ") != -1:
                                if functionString.find("return result;") != -1:
                                    functionList["CEverQuest__DropHeldItemOnGround"] = functionAddress

            # CEverquest__RightClickedOnPlayer
            # ----------------------------------------------------------------------------------------------------
            # void __stdcall sub_5D5EB0(LPVOID a1, char a2)
            # {
            #   LPVOID v2; // ecx
            #   double v3; // st7
            #   int v4; // eax
            #   int v5; // esi
            #   int v6; // ST28_4
            #   _DWORD *v7; // eax
            #   char v8; // al
            #   int v9; // eax
            #   int v10; // esi
            #   char v11; // bl
            #   char v12; // bl
            #   int v13; // eax
            #   int v14; // eax
            #   int v15; // esi
            #   char *v16; // ST18_4
            #   char *v17; // ST18_4
            #   char v18; // bl
            #   void *v19; // eax
            #   int v20; // esi
            #   char *v21; // ST18_4
            #   char *v22; // eax
            #   char *v23; // ST18_4
            #   char v24; // bl
            #   _DWORD *v25; // esi
            #   char *v26; // ST18_4
            #   int v27; // esi
            #   char v28; // bl
            #   float v29; // ST28_4
            #   char *v30; // ST18_4
            #   char *v31; // ST18_4
            #   int v32; // eax
            #   int v33; // esi
            #   int v34; // edi
            #   char v35; // bl
            #   int v36; // esi
            #   int v37; // edi
            #   char v38; // bl
            #   char *v39; // ST18_4
            #   char *v40; // ST18_4
            #   char v41; // bl
            #   char *v42; // ST18_4
            #   void *v43; // [esp-8h] [ebp-440h]
            #   int v44; // [esp+1Ch] [ebp-41Ch]
            #   char v45; // [esp+20h] [ebp-418h]
            #   int v46; // [esp+2Ch] [ebp-40Ch]
            #   int v47; // [esp+38h] [ebp-400h]
            #   int v48; // [esp+44h] [ebp-3F4h]
            #   int v49; // [esp+50h] [ebp-3E8h]
            #   int v50; // [esp+54h] [ebp-3E4h]
            #   int v51; // [esp+58h] [ebp-3E0h]
            #   int v52; // [esp+78h] [ebp-3C0h]
            #   int v53; // [esp+7Ch] [ebp-3BCh]
            #   char v54; // [esp+80h] [ebp-3B8h]
            #   float v55; // [esp+210h] [ebp-228h]
            #   char v56; // [esp+238h] [ebp-200h]
            #
            #   if ( !sub_5D1280() )
            #     sub_4C6170((_DWORD *)(dword_F3A520 + 235028), 66);
            #   if ( !sub_5D1280() )
            #     return;
            #   v2 = dword_E862A4;
            #   if ( a1 == dword_E862A4 || !dword_E862A4 || !a1 )
            #   {
            # LABEL_143:
            #     if ( !*((_BYTE *)dword_E85F9C + 16) )
            #     {
            #       if ( byte_E96F78 )
            #         sub_5F0860((int)a1);
            #     }
            #     return;
            #   }
            #   v3 = 20.0;
            #   if ( *((_BYTE *)a1 + 293) >= 2u )
            #   {
            #     *(_BYTE *)(dword_DD409C + 729) = dword_E9624C;
            #     if ( sub_5F1210((int)a1, 0) )
            #       return;
            #     goto LABEL_137;
            #   }
            #   v4 = *((_DWORD *)a1 + 999);
            #   if ( v4 == dword_C0CEBC )
            #   {
            #     if ( (*(int (**)(void))(*(_DWORD *)((char *)dword_E85F94 + *(_DWORD *)(*((_DWORD *)dword_E85F94 + 2) + 4) + 8) + 96))() & 0x20
            #       && sub_65B310((int)dword_E862A4, (int)a1, 1, 20.0) )
            #     {
            #       sub_4A6620(dword_E8BE08, (int)a1);
            #       return;
            #     }
            #     goto LABEL_137;
            #   }
            #   if ( v4 == dword_C0CEE8 )
            #   {
            #     v5 = sub_66EB00((int *)dword_E85F9C + 2913, "MMTW_MerchantWnd");
            #     if ( v5 && sub_65B310((int)dword_E862A4, (int)a1, 1, 20.0) )
            #     {
            #       v6 = *((_DWORD *)a1 + 84);
            #       v7 = sub_61B550();
            #       sub_61D7A0(v7, v6);
            #       (*(void (__thiscall **)(int, signed int, signed int, signed int))(*(_DWORD *)v5 + 216))(v5, 1, 1, 1);
            #     }
            #     goto LABEL_137;
            #   }
            #   if ( v4 == dword_C0CEB0 || v4 == dword_C0CEB8 || v4 == dword_C0CED8 || v4 == dword_C0CEDC )
            #     goto LABEL_126;
            #   if ( v4 == dword_C0CEC0 )
            #   {
            #     v8 = (*(int (**)(void))(*(_DWORD *)((char *)dword_E85F94 + *(_DWORD *)(*((_DWORD *)dword_E85F94 + 2) + 4) + 8) + 96))();
            #     v2 = dword_E862A4;
            #     if ( v8 & 0x20 )
            #       goto LABEL_126;
            #     v3 = 20.0;
            #   }
            #   v9 = *((_DWORD *)a1 + 999);
            #   if ( v9 == dword_C0CEE4 || v9 == dword_C0CEF0 )
            #   {
            # LABEL_126:
            #     if ( !dword_E862A8 && sub_65B310((int)v2, (int)a1, 1, 20.0) )
            #     {
            #       sub_4D2D50((_DWORD *)dword_E85F94 + 2310, 0, 0);
            #       dword_F34910 = 0;
            #       sub_6A5B80();
            #       ++dword_F34910;
            #       sub_4C5D50((_DWORD *)(dword_F3A520 + 235028), 47);
            #       v50 = *((_DWORD *)a1 + 84);
            #       v51 = *((_DWORD *)dword_E862A4 + 84);
            #       if ( byte_F34907 )
            #       {
            #         sub_5CF190(&hwnd, 0);
            #         v39 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x5BAu, 0);
            #         sub_4E4C80();
            #         sub_4E5350(v39, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #       }
            #       if ( byte_F34908 )
            #       {
            #         sub_5CF200(&hwnd, 0);
            #         v40 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x117u, 0);
            #         sub_4E4C80();
            #         sub_4E5350(v40, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #       }
            #       if ( *(_DWORD *)dword_E861A4 )
            #       {
            #         word_E85FA0 = sub_89FEA0(16489, 0);
            #         qmemcpy(&dword_E85FA2, &v50, 0x24u);
            #         v41 = sub_840970(*(int *)dword_E861A4, 4, &word_E85FA0, 0x26u);
            #         j_j_j___free_base(0);
            #         --dword_1076B04;
            #         if ( !v41 )
            #           sub_4EADF0((_DWORD *)dword_CA1D1C, (LPCRITICAL_SECTION **)dword_E861A4);
            #       }
            #       else if ( !byte_E95BA4 )
            #       {
            #         sub_8F18D0("Attempt to send message %d on a void connection.", 16489);
            #       }
            #       return;
            #     }
            # LABEL_137:
            #     if ( *(_DWORD *)(*(int (__thiscall **)(LPVOID, char *))(*(_DWORD *)a1 + 136))(a1, &v45) < dword_C0CE00
            #       && !sub_98AC90((int)a1) )
            #     {
            #       return;
            #     }
            #     if ( a2 && sub_53C630((int)dword_E862A4, (int)a1, 1.0) > 20.0 )
            #     {
            #       v42 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x7Cu, 0);
            #       sub_4E4C80();
            #       sub_4E5350(v42, (LPVOID)0xF, (LPVOID)1, (LPVOID)1, 0);
            #     }
            #     else
            #     {
            #       sub_59F3D0(a1, (int)" ");
            #     }
            #     goto LABEL_143;
            #   }
            #   if ( v9 == dword_C0CEC8 || v9 == dword_C0CEF4 || v9 == dword_C0CECC )
            #   {
            #     if ( !dword_E862A8 )
            #     {
            #       v29 = v3;
            #       if ( sub_65B310((int)v2, (int)a1, 1, v29) )
            #       {
            #         sub_4D2D50((_DWORD *)dword_E85F94 + 2310, 0, 0);
            #         dword_F34910 = 0;
            #         sub_6A5B80();
            #         ++dword_F34910;
            #         sub_4C5D50((_DWORD *)(dword_F3A520 + 235028), 48);
            #         if ( byte_F34907 )
            #         {
            #           sub_5CF190(&hwnd, 0);
            #           v30 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x5BAu, 0);
            #           sub_4E4C80();
            #           sub_4E5350(v30, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #         }
            #         if ( byte_F34908 )
            #         {
            #           sub_5CF200(&hwnd, 0);
            #           v31 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x117u, 0);
            #           sub_4E4C80();
            #           sub_4E5350(v31, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #         }
            #         v32 = *((_DWORD *)a1 + 999);
            #         if ( v32 == dword_C0CEC8 || v32 == dword_C0CEF4 )
            #         {
            #           v36 = *((_DWORD *)a1 + 84);
            #           v37 = *((_DWORD *)dword_E862A4 + 84);
            #           if ( *(_DWORD *)dword_E861A4 )
            #           {
            #             word_E85FA0 = sub_89FEA0(6722, 0);
            #             dword_E85FA2 = v37;
            #             LODWORD(qword_E85FA6) = v36;
            #             HIDWORD(qword_E85FA6) = v49;
            #             v38 = sub_840970(*(int *)dword_E861A4, 4, &word_E85FA0, 0xEu);
            #             j_j_j___free_base(0);
            #             --dword_1076B04;
            #             if ( !v38 )
            #               sub_4EADF0((_DWORD *)dword_CA1D1C, (LPCRITICAL_SECTION **)dword_E861A4);
            #           }
            #           else if ( !byte_E95BA4 )
            #           {
            #             sub_8F18D0("Attempt to send message %d on a void connection.", 6722);
            #           }
            #         }
            #         else if ( v32 == dword_C0CECC )
            #         {
            #           v33 = *((_DWORD *)a1 + 84);
            #           v34 = *((_DWORD *)dword_E862A4 + 84);
            #           if ( *(_DWORD *)dword_E861A4 )
            #           {
            #             word_E85FA0 = sub_89FEA0(15372, 0);
            #             dword_E85FA2 = v34;
            #             LODWORD(qword_E85FA6) = v33;
            #             HIDWORD(qword_E85FA6) = v48;
            #             v35 = sub_840970(*(int *)dword_E861A4, 4, &word_E85FA0, 0xEu);
            #             j_j_j___free_base(0);
            #             --dword_1076B04;
            #             if ( !v35 )
            #               sub_4EADF0((_DWORD *)dword_CA1D1C, (LPCRITICAL_SECTION **)dword_E861A4);
            #           }
            #           else if ( !byte_E95BA4 )
            #           {
            #             sub_8F18D0("Attempt to send message %d on a void connection.", 15372);
            #           }
            #         }
            #         return;
            #       }
            #     }
            #     goto LABEL_137;
            #   }
            #   if ( (*(unsigned __int8 (__thiscall **)(LPVOID))(*(_DWORD *)a1 + 88))(a1) && *((_BYTE *)a1 + 293) == 1 )
            #   {
            #     v10 = *((_DWORD *)a1 + 84);
            #     if ( (LPVOID)dword_E86300 == a1 )
            #     {
            #       LOBYTE(v44) = 0;
            #       if ( *(_DWORD *)dword_E861A4 )
            #       {
            #         word_E85FA0 = sub_89FEA0(9218, 0);
            #         dword_E85FA2 = v10;
            #         LODWORD(qword_E85FA6) = v44;
            #         v11 = sub_840970(*(int *)dword_E861A4, 4, &word_E85FA0, 0xAu);
            #         j_j_j___free_base(0);
            #         --dword_1076B04;
            #         if ( !v11 )
            #           sub_4EADF0((_DWORD *)dword_CA1D1C, (LPCRITICAL_SECTION **)dword_E861A4);
            #       }
            #       else if ( !byte_E95BA4 )
            #       {
            #         sub_8F18D0("Attempt to send message %d on a void connection.", 9218);
            #       }
            #       dword_E86300 = (int)dword_E862A4;
            #       *((float *)a1 + 31) = 0.0;
            #       *((float *)a1 + 35) = 0.0;
            #       return;
            #     }
            #     if ( !sub_98A740(dword_E862A4) || (LPVOID)sub_98A740(dword_E862A4) != a1 )
            #       return;
            #     LOBYTE(v44) = 1;
            #     if ( *(_DWORD *)dword_E861A4 )
            #     {
            #       word_E85FA0 = sub_89FEA0(9218, 0);
            #       dword_E85FA2 = v10;
            #       LODWORD(qword_E85FA6) = v44;
            #       v12 = sub_840970(*(int *)dword_E861A4, 4, &word_E85FA0, 0xAu);
            #       j_j_j___free_base(0);
            #       --dword_1076B04;
            #       if ( v12 )
            #         return;
            #       goto LABEL_43;
            #     }
            #     if ( !byte_E95BA4 )
            #       sub_8F18D0("Attempt to send message %d on a void connection.", 9218);
            #     return;
            #   }
            #   v13 = *((_DWORD *)a1 + 999);
            #   if ( v13 == dword_C0CEAC )
            #   {
            #     if ( !dword_E862B4 && sub_65B310((int)dword_E862A4, (int)a1, 1, 20.0) )
            #     {
            #       sub_6D00F0((_BYTE *)dword_DD3BC4, (int)a1);
            #       return;
            #     }
            #     goto LABEL_137;
            #   }
            #   if ( v13 == dword_C0CED4 )
            #   {
            #     if ( !dword_E862B4 && sub_65B310((int)dword_E862A4, (int)a1, 1, 20.0) )
            #     {
            #       if ( dword_10526B0 )
            #         sub_725EE0(dword_10526B0, 20.0, (int)a1);
            #       return;
            #     }
            #     goto LABEL_137;
            #   }
            #   if ( v13 >= dword_C0CE68 && v13 <= dword_C0CEA8 )
            #   {
            #     if ( sub_65B310((int)dword_E862A4, (int)a1, 1, 20.0) )
            #     {
            #       v14 = sub_8BF110((char *)dword_E85F94 + *(_DWORD *)(*((_DWORD *)dword_E85F94 + 2) + 4) + 12);
            #       v15 = *((_DWORD *)a1 + 999);
            #       if ( dword_C0CE68 + *(_DWORD *)(v14 + 14828) - dword_C0CE20 == v15 )
            #       {
            #         if ( !dword_E862B0 )
            #         {
            #           sub_4D2D50((_DWORD *)dword_E85F94 + 2310, 0, 0);
            #           dword_F34910 = 0;
            #           sub_6A5B80();
            #           ++dword_F34910;
            #           sub_4C5D50((_DWORD *)(dword_F3A520 + 235028), 49);
            #           v52 = *((_DWORD *)a1 + 84);
            #           v53 = *((_DWORD *)dword_E862A4 + 84);
            #           memset(&v54, 0, 0x190u);
            #           v55 = 0.0;
            #           if ( byte_F34907 )
            #           {
            #             sub_5CF190(&hwnd, 0);
            #             v16 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x5BAu, 0);
            #             sub_4E4C80();
            #             sub_4E5350(v16, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #           }
            #           if ( byte_F34908 )
            #           {
            #             sub_5CF200(&hwnd, 0);
            #             v17 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x117u, 0);
            #             sub_4E4C80();
            #             sub_4E5350(v17, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #           }
            #           if ( *(_DWORD *)dword_E861A4 )
            #           {
            #             word_E85FA0 = sub_89FEA0(9903, 0);
            #             qmemcpy(&dword_E85FA2, &v52, 0x1C0u);
            #             v18 = sub_840970(*(int *)dword_E861A4, 4, &word_E85FA0, 0x1C2u);
            #             j_j_j___free_base(0);
            #             --dword_1076B04;
            #             if ( !v18 )
            #               sub_4EADF0((_DWORD *)dword_CA1D1C, (LPCRITICAL_SECTION **)dword_E861A4);
            #           }
            #           else if ( !byte_E95BA4 )
            #           {
            #             sub_8F18D0("Attempt to send message %d on a void connection.", 9903);
            #           }
            #         }
            #       }
            #       else
            #       {
            #         v19 = sub_5EFA60(dword_C0CE20 + v15 - dword_C0CE68);
            #         sub_59A680((int)&v56, 1467, (int)v19, 0, 0, 0, 0, 0, 0, 0, 0);
            #         sub_4E4C80();
            #         sub_4E5350(&v56, (LPVOID)0xA, (LPVOID)1, (LPVOID)1, 0);
            #       }
            #     }
            #     goto LABEL_137;
            #   }
            #   if ( !*((_DWORD *)a1 + 166) && (!sub_64E110(a1) || !*(_DWORD *)(sub_64E110(a1) + 664)) )
            #   {
            #     if ( !*((_DWORD *)a1 + 121) )
            #     {
            #       if ( *((_DWORD *)a1 + 999) == dword_C0CEE0
            #         && dword_1052000
            #         && sub_65B310((int)dword_E862A4, (int)a1, 1, 20.0)
            #         && byte_E96F30 )
            #       {
            #         (*(void (**)(void))(*(_DWORD *)dword_1052000 + 144))();
            #         sub_933080(dword_1052000);
            #         return;
            #       }
            #       goto LABEL_137;
            #     }
            #     if ( dword_E862A8 || !sub_65B310((int)dword_E862A4, (int)a1, 1, 20.0) )
            #       goto LABEL_137;
            #     sub_4D2D50((_DWORD *)dword_E85F94 + 2310, 0, 0);
            #     dword_F34910 = 0;
            #     sub_6A5B80();
            #     ++dword_F34910;
            #     sub_4C5D50((_DWORD *)(dword_F3A520 + 235028), 51);
            #     v20 = *((_DWORD *)a1 + 84);
            #     if ( byte_F34907 )
            #     {
            #       sub_5CF190(&hwnd, 0);
            #       v21 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x5BAu, 0);
            #       sub_4E4C80();
            #       sub_4E5350(v21, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #     }
            #     if ( byte_F34908 )
            #       goto LABEL_79;
            #     if ( *((_DWORD *)dword_E862A4 + 84) != *((_DWORD *)a1 + 84) )
            #     {
            #       if ( *(_DWORD *)dword_E861A4 )
            #       {
            #         word_E85FA0 = sub_89FEA0(17894, 0);
            #         dword_E85FA2 = 11;
            #         LODWORD(qword_E85FA6) = v20;
            #         HIDWORD(qword_E85FA6) = v47;
            #         v24 = sub_840970(*(int *)dword_E861A4, 4, &word_E85FA0, 0xEu);
            #         j_j_j___free_base(0);
            #         --dword_1076B04;
            #         if ( !v24 )
            #           sub_4EADF0((_DWORD *)dword_CA1D1C, (LPCRITICAL_SECTION **)dword_E861A4);
            #       }
            #       else if ( !byte_E95BA4 )
            #       {
            #         sub_8F18D0("Attempt to send message %d on a void connection.", 17894);
            #       }
            #       return;
            #     }
            #     goto LABEL_81;
            #   }
            #   if ( dword_E862A8 )
            #     goto LABEL_137;
            #   v25 = a1;
            #   if ( sub_64E110(a1) && *(_DWORD *)(sub_64E110(a1) + 664) )
            #     v25 = (_DWORD *)sub_64E110(a1);
            #   if ( !sub_65B310((int)dword_E862A4, (int)v25, 1, 20.0) )
            #     goto LABEL_137;
            #   sub_4D2D50((_DWORD *)dword_E85F94 + 2310, 0, 0);
            #   dword_F34910 = 0;
            #   sub_6A5B80();
            #   ++dword_F34910;
            #   sub_4C5D50((_DWORD *)(dword_F3A520 + 235028), 50);
            #   if ( byte_F34907 )
            #   {
            #     sub_5CF190(&hwnd, 0);
            #     v26 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x5BAu, 0);
            #     sub_4E4C80();
            #     sub_4E5350(v26, (LPVOID)0xD, (LPVOID)1, (LPVOID)1, 0);
            #   }
            #   if ( byte_F34908 )
            #   {
            # LABEL_79:
            #     sub_5CF200(&hwnd, 0);
            #     v43 = (void *)13;
            #     v22 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x117u, 0);
            # LABEL_82:
            #     v23 = v22;
            #     sub_4E4C80();
            #     sub_4E5350(v23, v43, (LPVOID)1, (LPVOID)1, 0);
            #     return;
            #   }
            #   v27 = v25[84];
            #   if ( *((_DWORD *)dword_E862A4 + 84) == v27 )
            #   {
            # LABEL_81:
            #     v43 = (void *)10;
            #     v22 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x5BDu, 0);
            #     goto LABEL_82;
            #   }
            #   LOBYTE(v46) = 0;
            #   if ( *(_DWORD *)dword_E861A4 )
            #   {
            #     word_E85FA0 = sub_89FEA0(20371, 0);
            #     dword_E85FA2 = 28;
            #     LODWORD(qword_E85FA6) = v27;
            #     HIDWORD(qword_E85FA6) = v46;
            #     v28 = sub_840970(*(int *)dword_E861A4, 4, &word_E85FA0, 0xEu);
            #     j_j_j___free_base(0);
            #     --dword_1076B04;
            #     if ( v28 )
            #     {
            #       sub_83D780(*(int *)dword_E861A4);
            #       return;
            #     }
            # LABEL_43:
            #     sub_4EADF0((_DWORD *)dword_CA1D1C, (LPCRITICAL_SECTION **)dword_E861A4);
            #     return;
            #   }
            #   if ( !byte_E95BA4 )
            #     sub_8F18D0("Attempt to send message %d on a void connection.", 20371);
            # }
            if functionString.find("\"MMTW_MerchantWnd\"") != -1:
                if functionString.find(", 0x5BAu,") != -1 or functionString.find(", 1466,") != -1:
                    if functionString.find(", 0x5BDu,") != -1 or functionString.find(", 1469,") != -1:
                        if functionString.find("> 20.0") != -1:
                            functionList["CEverQuest__RightClickedOnPlayer"] = functionAddress

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
            if functionString.find("<= 255") != -1:
                if functionString.find(" - 2 < 0;") != -1:
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
                        if functionString.find(", 0, 1u);") != -1:
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

            # CAlertStackWnd
            # AreAlertWindowsModified
            # ----------------------------------------------------------------------------------------------------
            # bool sub_541710()    # AreAlertWindowsModified    0x00541710
            # {
            #   return dword_DDD0E4
            #       && sub_6C9120((_DWORD *)dword_DDD0E4)    # CAlertWnd
            #       && dword_DDD0CC
            #       && sub_6C8260((_DWORD *)dword_DDD0CC)    # CAlertStackWnd    0x00DDD0CC
            #       && dword_DDD154
            #       && sub_6C7720((_DWORD *)dword_DDD154);   # CAlertHistoryWnd
            # }
            if functionString.find("return dword_") != -1:
                if functionString.find("&& sub_") != -1:
                    if functionString.find("&& dword_") != -1:
                        matches = re.findall("return dword_[0-9A-F]+\n\s+&& sub_[0-9A-F]+\(\(_DWORD \*\)dword_[0-9A-F]+\)\n\s+&& dword_[0-9A-F]+\n\s+&& sub_[0-9A-F]+\(\(_DWORD \*\)dword_([0-9A-F]+)\)\n\s+&& dword_[0-9A-F]+\n\s+&& sub_[0-9A-F]+\(\(_DWORD \*\)dword_[0-9A-F]+\);", functionString, re.MULTILINE)
                        if matches:
                            functionList["CAlertStackWnd"] = "0x0" + matches[0]
                            functionList["AreAlertWindowsModified"] = functionAddress

            # CAlertHistoryWnd
            # ----------------------------------------------------------------------------------------------------
            # bool sub_541710()
            # {
            #   return dword_DDD0E4
            #       && sub_6C9120((_DWORD *)dword_DDD0E4)    # CAlertWnd
            #       && dword_DDD0CC
            #       && sub_6C8260((_DWORD *)dword_DDD0CC)    # CAlertStackWnd
            #       && dword_DDD154
            #       && sub_6C7720((_DWORD *)dword_DDD154);   # CAlertHistoryWnd
            # }
            if functionString.find("return dword_") != -1:
                if functionString.find("&& sub_") != -1:
                    if functionString.find("&& dword_") != -1:
                        matches = re.findall("return dword_[0-9A-F]+\n\s+&& sub_[0-9A-F]+\(\(_DWORD \*\)dword_[0-9A-F]+\)\n\s+&& dword_[0-9A-F]+\n\s+&& sub_[0-9A-F]+\(\(_DWORD \*\)dword_[0-9A-F]+\)\n\s+&& dword_[0-9A-F]+\n\s+&& sub_[0-9A-F]+\(\(_DWORD \*\)dword_([0-9A-F]+)\);", functionString, re.MULTILINE)
                        if matches:
                            functionList["CAlertHistoryWnd"] = "0x0" + matches[0]
                            functionList["AreAlertWindowsModified"] = functionAddress

            # CBazaarSearchWnd
            # ----------------------------------------------------------------------------------------------------
            # 0x00DD40AC
            # void __usercall sub_588570(int a1@<ebx>, int a2@<edi>, double a3@<st0>, int a4, unsigned int a5, int *a6, int a7)
            # {
            #   char *v7; // ST1C_4
            #   int v8; // eax
            #   int v9; // ST10_4
            #   int v10; // eax
            #   char *v11; // ST1C_4
            #   int v12; // eax
            #   float v13; // ST18_4
            #   bool v14; // zf
            #   unsigned int v15; // ebx
            #   void *v16; // eax
            #   __int16 v17; // ax
            #   LPVOID *v18; // eax
            #   char (*v19)[2]; // eax
            #   int v20; // eax
            #   void *v21; // edi
            #   volatile signed __int32 **v22; // eax
            #   volatile signed __int32 **v23; // eax
            #   volatile signed __int32 **v24; // eax
            #   volatile signed __int32 **v25; // eax
            #   volatile signed __int32 **v26; // eax
            #   volatile signed __int32 **v27; // eax
            #   volatile signed __int32 **v28; // eax
            #   volatile signed __int32 **v29; // eax
            #   volatile signed __int32 **v30; // eax
            #   char *v31; // ST18_4
            #   int v32; // ecx
            #   char v33; // [esp+1Ch] [ebp-24Ch]
            #   char v34; // [esp+11Ch] [ebp-14Ch]
            #   int *v35; // [esp+21Ch] [ebp-4Ch]
            #   int v36; // [esp+220h] [ebp-48h]
            #   int v37; // [esp+224h] [ebp-44h]
            #   int *v38; // [esp+228h] [ebp-40h]
            #   int v39; // [esp+22Ch] [ebp-3Ch]
            #   int v40; // [esp+230h] [ebp-38h]
            #   int v41; // [esp+234h] [ebp-34h]
            #   int v42; // [esp+238h] [ebp-30h]
            #   int v43; // [esp+23Ch] [ebp-2Ch]
            #   int v44; // [esp+240h] [ebp-28h]
            #   __int64 v45; // [esp+244h] [ebp-24h]
            #   __int64 v46; // [esp+24Ch] [ebp-1Ch]
            #   LPVOID v47; // [esp+254h] [ebp-14h]
            #   LPVOID lpMem; // [esp+258h] [ebp-10h]
            #   int v49; // [esp+264h] [ebp-4h]
            #
            #   if ( !dword_E85F94 )
            #     return;
            #   if ( a5 > 0x51E6 )
            #   {
            #     if ( a5 == 24935 )
            #     {
            #       v35 = a6;
            #       v36 = a7;
            #       v37 = 0;
            #       sub_6DE250((_DWORD *)dword_DD40AC, &v35);    # 0x00DD40AC
            #     }
            #     return;
            #   }
            #   if ( a5 == 20966 )
            #   {
            #     v38 = a6;
            #     v39 = a7;
            #     v40 = 0;
            #     sub_6DE3A0((_DWORD *)dword_DD40AC, &v38);    # 0x00DD40AC
            #     return;
            #   }
            #   if ( a5 == 1514 )
            #   {
            #     if ( *a6 != 21 )
            #     {
            #       sub_6E1DE0((void **)dword_DD38D0, a6);
            #       return;
            #     }
            #     v32 = a6[17];
            #     if ( v32 == 1 )
            #     {
            #       sub_59A680((int)&v34, 6735, (int)(a6 + 1), 0, 0, 0, 0, 0, 0, 0, 0);
            #     }
            #     else
            #     {
            #       if ( v32 != 2 )
            #         return;
            #       sub_59A680((int)&v34, 6736, (int)(a6 + 1), 0, 0, 0, 0, 0, 0, 0, 0);
            #     }
            #     sub_6E27D0((void **)dword_DD38D0, &v34, (LPVOID)0xF);
            #     return;
            #   }
            #   if ( a5 != 20371 )
            #     return;
            #   switch ( *a6 )
            #   {
            #     case 9:
            #       if ( sub_8C7270((_DWORD *)dword_E85E68, dword_E96DC4) )
            #       {
            #         v7 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x1A6Au, 0);
            #         sub_4E4C80();
            #         sub_4E5350(v7, (LPVOID)0xA, (LPVOID)1, (LPVOID)1, 0);
            #       }
            #       unknown_libname_66(a6[3], &unk_1094558, 10);
            #       v9 = v8;
            #       unknown_libname_66(a6[2], byte_1094538, 10);
            #       sub_59A680((int)&v33, 6763, v10, v9, 0, 0, 0, 0, 0, 0, 0);
            #       sub_4E4C80();
            #       sub_4E5350(&v33, (LPVOID)0xA, (LPVOID)1, (LPVOID)1, 0);
            #       if ( sub_8C7270((_DWORD *)dword_E85E68, dword_E96DC4) )
            #       {
            #         v11 = (char *)sub_8B7EA0((int *)dword_E861A0, 0x1A6Cu, 0);
            #         sub_4E4C80();
            #         sub_4E5350(v11, (LPVOID)0xA, (LPVOID)1, (LPVOID)1, 0);
            #       }
            #       return;
            #     case 10:
            #       if ( a6[1] )
            #       {
            #         sub_4A9780(&hwnd);
            #         sub_593860(&hwnd);
            #         dword_E95DC8[dword_E95DF0] = 18;
            #         dword_E95DA0[dword_E95DF0] = sub_8F1160();
            #         if ( !a6[2] )
            #         {
            #           if ( dword_DD38B0 )
            #             sub_4A3F00((int *)dword_DD38B0);
            #           v15 = ((unsigned int)a6[68] + a6[70] * (unsigned __int64)(unsigned int)a6[67]) >> 32;
            #           a2 = a6[68] + a6[70] * a6[67];
            #           if ( sub_63A110(dword_E85F94, (unsigned int)a6[68] + a6[70] * (unsigned __int64)(unsigned int)a6[67]) )
            #           {
            #             sub_5622B0(dword_DD5980, 138, 0);
            #           }
            #           else
            #           {
            #             *(_DWORD *)(sub_8BF110((char *)dword_E85F94 + *(_DWORD *)(*((_DWORD *)dword_E85F94 + 2) + 4) + 12) + 14916) = 0;
            #             *(_DWORD *)(sub_8BF110((char *)dword_E85F94 + *(_DWORD *)(*((_DWORD *)dword_E85F94 + 2) + 4) + 12) + 14912) = 0;
            #             *(_DWORD *)(sub_8BF110((char *)dword_E85F94 + *(_DWORD *)(*((_DWORD *)dword_E85F94 + 2) + 4) + 12) + 14908) = 0;
            #             *(_DWORD *)(sub_8BF110((char *)dword_E85F94 + *(_DWORD *)(*((_DWORD *)dword_E85F94 + 2) + 4) + 12) + 14904) = 0;
            #           }
            #           v16 = sub_59A8B0(__PAIR__(v15, a2));
            #           sub_8ED690(&v47, v16);
            #           v17 = *((_WORD *)a6 + 138);
            #           v49 = 0;
            #           if ( v17 )
            #           {
            #             v18 = sub_8ED830(&lpMem, (int)" and %hu vouchers", v17);
            #             LOBYTE(v49) = 1;
            #             sub_8EE070(&v47, v18);
            #             LOBYTE(v49) = 2;
            #             if ( lpMem )
            #               sub_8EFAE0(lpMem);
            #             LOBYTE(v49) = 0;
            #           }
            #           v19 = sub_8EDE00(&v47);
            #           sub_59A680((int)&v33, 787, (int)v19, (int)(a6 + 21), 0, 0, 0, 0, 0, 0, 0);
            #           sub_4E4C80();
            #           sub_4E5350(&v33, (LPVOID)0x114, (LPVOID)1, (LPVOID)1, 0);
            #           v49 = 3;
            #           if ( v47 )
            #             sub_8EFAE0(v47);
            #           v49 = -1;
            #         }
            #         sub_62EF00(a2, a3);
            #       }
            #       else
            #       {
            #         v42 = 0;
            #         v43 = 0;
            #         v44 = 0;
            #         v41 = a6[4];
            #         v45 = (unsigned int)a6[70];
            #         v14 = a6[2] == 0;
            #         v46 = (unsigned int)a6[67] * (signed __int64)(signed int)v45;
            #         sub_79F4D0(dword_DD40A0, a3, (int)&v41, v14);
            #       }
            #       v20 = a6[2];
            #       if ( v20 == 2 )
            #         goto LABEL_68;
            #       v47 = 0;
            #       v49 = 4;
            #       v21 = (void *)276;
            #       if ( v20 )
            #       {
            #         switch ( v20 )
            #         {
            #           case 1:
            #             v23 = (volatile signed __int32 **)sub_8ED830(
            #                                                 &lpMem,
            #                                                 (int)"Your attempt to purchase %d %s(s) from %s was unsuccessful.",
            #                                                 a6[70]);
            #             LOBYTE(v49) = 7;
            #             sub_8ED8C0((volatile signed __int32 **)&v47, v23);
            #             LOBYTE(v49) = 8;
            #             break;
            #           case 3:
            #             v24 = (volatile signed __int32 **)sub_8ED830(
            #                                                 &lpMem,
            #                                                 (int)"Your attempt to purchase %d %s(s) from %s failed because your bazaa"
            #                                                      "r data is out of date.",
            #                                                 a6[70]);
            #             LOBYTE(v49) = 9;
            #             sub_8ED8C0((volatile signed __int32 **)&v47, v24);
            #             LOBYTE(v49) = 10;
            #             if ( lpMem )
            #               sub_8EFAE0(lpMem);
            #             v14 = a6[1] == 0;
            #             LOBYTE(v49) = 4;
            #             if ( v14 )
            #               sub_8EE390((int *)&v47, " Please close and re-open the merchant window to get the latest trader data.");
            #             else
            #               sub_8EE390((int *)&v47, " Please run the search again to get the latest bazaar data.");
            #             goto LABEL_65;
            #           case 4:
            #             v25 = (volatile signed __int32 **)sub_8ED830(
            #                                                 &lpMem,
            #                                                 (int)"Your attempt to purchase %d %s(s) from %s failed because you alread"
            #                                                      "y possess that lore item.",
            #                                                 a6[70]);
            #             LOBYTE(v49) = 11;
            #             sub_8ED8C0((volatile signed __int32 **)&v47, v25);
            #             LOBYTE(v49) = 12;
            #             break;
            #           case 5:
            #             v26 = (volatile signed __int32 **)sub_8ED830(
            #                                                 &lpMem,
            #                                                 (int)"Your attempt to purchase %d %s(s) from %s failed because you are at"
            #                                                      " the parcel cap and will be unable to have items mailed to you unti"
            #                                                      "l you retrieve items from your parcels.",
            #                                                 a6[70]);
            #             LOBYTE(v49) = 13;
            #             sub_8ED8C0((volatile signed __int32 **)&v47, v26);
            #             LOBYTE(v49) = 14;
            #             break;
            #           case 6:
            #             v27 = (volatile signed __int32 **)sub_8ED830(
            #                                                 &lpMem,
            #                                                 (int)"Your attempt to purchase %d %s(s) from %s failed because you alread"
            #                                                      "y have a bazaar transaction pending. Please wait a few seconds and try again.",
            #                                                 a6[70]);
            #             LOBYTE(v49) = 15;
            #             sub_8ED8C0((volatile signed __int32 **)&v47, v27);
            #             LOBYTE(v49) = 16;
            #             break;
            #           case 7:
            #             v28 = (volatile signed __int32 **)sub_8ED830(
            #                                                 &lpMem,
            #                                                 (int)"Your attempt to purchase %d %s(s) from %s failed because you do not"
            #                                                      " have the required funds.",
            #                                                 a6[70]);
            #             LOBYTE(v49) = 17;
            #             sub_8ED8C0((volatile signed __int32 **)&v47, v28);
            #             LOBYTE(v49) = 18;
            #             break;
            #           case 8:
            #             v29 = (volatile signed __int32 **)sub_8ED830(
            #                                                 &lpMem,
            #                                                 (int)"Your attempt to purchase %d %s(s) from %s failed because you do not"
            #                                                      " have the required tokens.",
            #                                                 a6[70]);
            #             LOBYTE(v49) = 19;
            #             sub_8ED8C0((volatile signed __int32 **)&v47, v29);
            #             LOBYTE(v49) = 20;
            #             break;
            #           case 9:
            #             v30 = (volatile signed __int32 **)sub_8ED830(
            #                                                 &lpMem,
            #                                                 (int)"Your attempt to purchase %d %s(s) from %s failed because the Krono "
            #                                                      "was not successfully transferred.",
            #                                                 a6[70]);
            #             LOBYTE(v49) = 21;
            #             sub_8ED8C0((volatile signed __int32 **)&v47, v30);
            #             LOBYTE(v49) = 22;
            #             break;
            #           default:
            #             goto LABEL_66;
            #         }
            #         if ( lpMem )
            #           sub_8EFAE0(lpMem);
            #         LOBYTE(v49) = 4;
            # LABEL_65:
            #         v21 = (void *)13;
            #         goto LABEL_66;
            #       }
            #       v22 = (volatile signed __int32 **)sub_8ED830(&lpMem, (int)"You successfully purchased %d %s(s) from %s.", a6[70]);
            #       LOBYTE(v49) = 5;
            #       sub_8ED8C0((volatile signed __int32 **)&v47, v22);
            #       LOBYTE(v49) = 6;
            #       if ( lpMem )
            #         sub_8EFAE0(lpMem);
            #       v14 = a6[1] == 1;
            #       LOBYTE(v49) = 4;
            #       if ( v14 )
            #         sub_8EE390((int *)&v47, " The item has been sent to your parcels.");
            #       else
            #         sub_8EE390((int *)&v47, " The item has been added to your inventory.");
            # LABEL_66:
            #       v31 = (char *)sub_8EDE00(&v47);
            #       sub_4E4C80();
            #       sub_4E5350(v31, v21, (LPVOID)1, (LPVOID)1, 0);
            #       v49 = 23;
            #       if ( v47 )
            #         sub_8EFAE0(v47);
            # LABEL_68:
            #       *((_BYTE *)dword_E85F94 + 9252) = 1;
            #       *((_BYTE *)dword_E85F94 + 9588) = 0;
            #       return;
            #     case 24:
            #       sub_6DE4C0((int *)dword_DD40AC, a6 + 1);    # 0x00DD40AC
            #       return;
            #     case 25:
            #       sub_6DE510((int *)dword_DD40AC, a6[1]);    # 0x00DD40AC
            #       return;
            #     case 28:
            #       if ( !dword_E862A8 )
            #       {
            #         v12 = sub_651340((_DWORD **)dword_F37AE8, a6[1]);
            #         if ( v12 )
            #         {
            #           if ( *((_BYTE *)a6 + 8) )
            #           {
            #             __asm
            #             {
            #               fld1
            #               fstp    dword ptr [esp+268h+var_268]; float
            #             }
            #             sub_79D450((float *)dword_DD40A0, v12, v13, 1, 0, 0, 0, 0);
            #           }
            #           else
            #           {
            #             dword_F34910 = 0;
            #             sub_6A5B80();
            #           }
            #         }
            #       }
            #       return;
            #     default:
            #       sub_6DE220((_DWORD *)dword_DD40AC, a1, a6, a7);    # 0x00DD40AC
            #       return;
            #   }
            # }
            if functionString.find("\" The item has been sent to your parcels.\"") != -1:
                if functionString.find("\" The item has been added to your inventory.\"") != -1:
                    matches = re.findall("default:\n\s+sub_[0-9A-F]+\(\(_DWORD \*\)dword_([0-9A-F]+), [0-9a-z]+, [0-9a-z]+, [0-9a-z]+\);\n\s+return;", functionString, re.MULTILINE)
                    if matches:
                        functionList["CBazaarSearchWnd"] = "0x00" + matches[0]

            # CBazaarSearchWnd__AddItemToList
            # ----------------------------------------------------------------------------------------------------
            # void __thiscall sub_6DB0B0(_DWORD *this, char *a2, int a3, char *a4, int a5, int a6, int a7, LPVOID a8, int a9, LPVOID lpMem, int a11, char *a12)
            # {
            #   void *v12; // eax
            #   _DWORD *v13; // edi
            #   int v14; // edx
            #   signed int v15; // ecx
            #   LPVOID v16; // ebx
            #   char *v17; // ST14_4
            #   int v18; // esi
            #   int v19; // eax
            #   LPVOID *v20; // esi
            #   LPVOID v21; // eax
            #   void *v22; // eax
            #   _DWORD *v23; // ecx
            #   unsigned int v24; // eax
            #   void *v25; // eax
            #   _DWORD *v26; // ecx
            #   unsigned int v27; // eax
            #   void *v28; // eax
            #   _DWORD *v29; // ecx
            #   void *v30; // eax
            #   _DWORD *v31; // ecx
            #   _DWORD *v32; // ecx
            #   int v33; // eax
            #   int v34; // eax
            #   int v35; // eax
            #   int v36; // ebx
            #   int v37; // [esp+8h] [ebp-14h]
            #   LPVOID v38; // [esp+Ch] [ebp-10h]
            #   int v39; // [esp+18h] [ebp-4h]
            #   unsigned int v40; // [esp+24h] [ebp+8h]
            #   unsigned int v41; // [esp+24h] [ebp+8h]
            #   unsigned int v42; // [esp+24h] [ebp+8h]
            #
            #   v12 = 0;
            #   v13 = this;
            #   v38 = 0;
            #   v14 = this[9354];
            #   v39 = 0;
            #   v15 = *(_DWORD *)(v14 + 476);
            #   v37 = v15;
            #   if ( v15 < 200 )
            #   {
            #     v16 = lpMem;
            #     if ( (signed int)lpMem > 0 )
            #     {
            #       v17 = a12;
            #       v18 = (int)&v13[46 * v15];
            #       *(_DWORD *)(v18 + 748) = a8;
            #       *(_DWORD *)(v18 + 752) = a9;
            #       *(_DWORD *)(v18 + 740) = a3;
            #       v19 = a11;
            #       *(_DWORD *)(v18 + 756) = v16;
            #       *(_DWORD *)(v18 + 744) = 0;
            #       *(_DWORD *)(v18 + 760) = v19;
            #       sub_8F5360((_BYTE *)(v18 + 764), v17);
            #       *(_DWORD *)(v18 + 728) = a5;
            #       *(_DWORD *)(v18 + 732) = a6;
            #       v13[46 * (v37 + 4)] = a7;
            #       sub_8F1A90((char *)(v18 + 664), a2, 0x40u);
            #       sub_8F1A90((char *)(v18 + 600), a4, 0x40u);
            #       sub_8ED690(&lpMem, Directory);
            #       v20 = (LPVOID *)sub_91AAB0((_DWORD *)v13[9354], (int)&lpMem, -1, v37, v37 >> 31, 0, 0);
            #       LOBYTE(v39) = 3;
            #       if ( lpMem )
            #         sub_8EFAE0(lpMem);
            #       LOBYTE(v39) = 0;
            #       v21 = sub_70E870((int *)dword_1051DB8, (signed int)a8);
            #       sub_91B730((_DWORD *)v13[9354], (int)v20, 0, (int)v21);
            #       sub_8ED690(&a8, a2);
            #       sub_91B6B0((_DWORD *)v13[9354], v20, 1, (volatile signed __int32 **)&a8);
            #       LOBYTE(v39) = 5;
            #       if ( a8 )
            #         sub_8EFAE0(a8);
            #       LOBYTE(v39) = 0;
            #       sub_8EF980(&v38, (int)&unk_AC3A58, (char)v16);
            #       sub_91B6B0((_DWORD *)v13[9354], v20, 2, (volatile signed __int32 **)&v38);
            #       v40 = a3 % 0x3E8u;
            #       unknown_libname_66(a3 / 0x3E8u, byte_1094538, 10);
            #       sub_8ED690(&a8, v22);
            #       v23 = (_DWORD *)v13[9354];
            #       LOBYTE(v39) = 6;
            #       sub_91B6B0(v23, v20, 3, (volatile signed __int32 **)&a8);
            #       LOBYTE(v39) = 7;
            #       if ( a8 )
            #         sub_8EFAE0(a8);
            #       LOBYTE(v39) = 0;
            #       v24 = v40 / 0x64;
            #       v41 = v40 % 0x64;
            #       unknown_libname_66(v24, byte_1094538, 10);
            #       sub_8ED690(&a8, v25);
            #       v26 = (_DWORD *)v13[9354];
            #       LOBYTE(v39) = 8;
            #       sub_91B6B0(v26, v20, 4, (volatile signed __int32 **)&a8);
            #       LOBYTE(v39) = 9;
            #       if ( a8 )
            #         sub_8EFAE0(a8);
            #       LOBYTE(v39) = 0;
            #       v27 = v41 / 0xA;
            #       v42 = v41 % 0xA;
            #       unknown_libname_66(v27, byte_1094538, 10);
            #       sub_8ED690(&a8, v28);
            #       v29 = (_DWORD *)v13[9354];
            #       LOBYTE(v39) = 10;
            #       sub_91B6B0(v29, v20, 5, (volatile signed __int32 **)&a8);
            #       LOBYTE(v39) = 11;
            #       if ( a8 )
            #         sub_8EFAE0(a8);
            #       LOBYTE(v39) = 0;
            #       unknown_libname_66(v42, byte_1094538, 10);
            #       sub_8ED690(&a8, v30);
            #       v31 = (_DWORD *)v13[9354];
            #       LOBYTE(v39) = 12;
            #       sub_91B6B0(v31, v20, 6, (volatile signed __int32 **)&a8);
            #       LOBYTE(v39) = 13;
            #       if ( a8 )
            #         sub_8EFAE0(a8);
            #       LOBYTE(v39) = 0;
            #       sub_8ED690(&a8, a4);
            #       v32 = (_DWORD *)v13[9354];
            #       LOBYTE(v39) = 14;
            #       sub_91B6B0(v32, v20, 7, (volatile signed __int32 **)&a8);
            #       LOBYTE(v39) = 15;
            #       if ( a8 )
            #         sub_8EFAE0(a8);
            #       v33 = v13[9363];
            #       LOBYTE(v39) = 0;
            #       if ( v33 )
            #       {
            #         v34 = sub_9355D0(dword_16D1508, *(_DWORD *)(v33 + 144));
            #         v35 = sub_938530(dword_16D1508, (int)v13, v34, 0);
            #         v36 = v35;
            #         if ( v35 )
            #         {
            #           sub_924340(v35, 1, 0);
            #           (*(void (__thiscall **)(int, signed int, signed int, signed int))(*(_DWORD *)v36 + 216))(v36, 1, 1, 1);
            #           sub_91B960((char *)v13[9354], v20, 8, v36);
            #         }
            #       }
            #       if ( v38 )
            #         sub_8EFAE0(v38);
            #       v38 = 0;
            #       if ( a11 )
            #         sub_8EF980(&v38, (int)&unk_AC3A58, a11);
            #       sub_91B6B0((_DWORD *)v13[9354], v20, 9, (volatile signed __int32 **)&v38);
            #       v12 = v38;
            #     }
            #   }
            #   v39 = 16;
            #   if ( v12 )
            #     sub_8EFAE0(v12);
            # }
            if re.search("if \( [0-9a-z]+ \< 200 \)", functionString):
                if functionString.find(">> 31, 0, 0);") != -1:
                    functionList["CBazaarSearchWnd__AddItemToList"] = functionAddress

            # CBazaarSearchWnd__BuyItem
            # ----------------------------------------------------------------------------------------------------
            # char __thiscall sub_6DBE80(_DWORD *this, int a2)
            # {
            #   int v2; // esi
            #   signed int v3; // eax
            #   char *v4; // ecx
            #   void *v5; // eax
            #   int v6; // eax
            #   void *v7; // ecx
            #   int v8; // ST00_4
            #   void *v10; // [esp-20h] [ebp-34h]
            #   char *v11; // [esp-1Ch] [ebp-30h]
            #   void *v12; // [esp-18h] [ebp-2Ch]
            #   void *v13; // [esp-14h] [ebp-28h]
            #   void *v14; // [esp-10h] [ebp-24h]
            #   int v15; // [esp-Ch] [ebp-20h]
            #   char *v16; // [esp-8h] [ebp-1Ch]
            #   int v17; // [esp-4h] [ebp-18h]
            #   int v18; // [esp+10h] [ebp-4h]
            #
            #   v2 = (int)this;
            #   v3 = this[148];
            #   if ( v3 < 0 || v3 >= 200 || !dword_DD38B0 )
            #     return 0;
            #   v17 = a2;
            #   v4 = (char *)&this[46 * v3];
            #   v16 = v4 + 764;
            #   v15 = *((_DWORD *)v4 + 188);
            #   v5 = (void *)*(unsigned __int16 *)(v2 + 596);
            #   v14 = (void *)*((_DWORD *)v4 + 182);
            #   v13 = (void *)*((_DWORD *)v4 + 185);
            #   v12 = v5;
            #   v11 = v4;
            #   sub_8ED690((LPVOID *)&v11, v4 + 600);
            #   v6 = 184 * *(_DWORD *)(v2 + 592);
            #   v10 = v7;
            #   v18 = 0;
            #   sub_8ED690(&v10, (void *)(v2 + v6 + 664));
            #   v8 = *(_DWORD *)(184 * *(_DWORD *)(v2 + 592) + v2 + 748);
            #   v18 = -1;
            #   sub_4A3B00((char *)dword_DD38B0, v8, v10, v11, v12, v13, v14, v15, v16, v17);
            #   sub_9239B0(v2, (int *)&v14);
            #   sub_925050((_DWORD *)dword_DD38B0, (int)v14, v15, (int)v16, v17);
            #   v17 = 1;
            #   v16 = (char *)1;
            #   v15 = 1;
            #   (*(void (__stdcall **)(signed int, signed int, signed int))(*(_DWORD *)dword_DD38B0 + 216))(1, 1, 1);
            #   sub_9254B0((void *)dword_DD38B0, 1);
            #   return 1;
            # }
            if re.search("[0-9a-z]+ = this\[\d+\];", functionString):
                if re.search("if \( [0-9a-z]+ \< 0 \|\| [0-9a-z]+ \>\= 200 \|\| \!dword_[0-9A-F]+ \)", functionString):
                    if functionString.find("return 0;") != -1:
                        if functionString.find("return 1;") != -1:
                            functionList["CBazaarSearchWnd__BuyItem"] = functionAddress

            # CBazaarSearchWnd__doQuery
            # ----------------------------------------------------------------------------------------------------
            # void __thiscall sub_6DB950(_DWORD *this)
            # {
            #   _DWORD *v1; // esi
            #   int *v2; // ecx
            #   int v3; // ebx
            #   int v4; // edi
            #   int v5; // eax
            #   LPVOID *v6; // eax
            #   char (*v7)[2]; // ecx
            #   char *v8; // edx
            #   char v9; // al
            #   _DWORD **v10; // ecx
            #   int v11; // eax
            #   int v12; // eax
            #   int v13; // eax
            #   int v14; // eax
            #   int v15; // eax
            #   _DWORD **v16; // ecx
            #   int v17; // eax
            #   volatile signed __int32 **v18; // eax
            #   _DWORD *v19; // ecx
            #   int v20; // eax
            #   int v21; // eax
            #   int v22; // eax
            #   int v23; // eax
            #   int v24; // ecx
            #   LPVOID *v25; // eax
            #   char (*v26)[2]; // eax
            #   int v27; // ecx
            #   LPVOID *v28; // eax
            #   char (*v29)[2]; // eax
            #   int v30; // ecx
            #   LPVOID *v31; // eax
            #   char (*v32)[2]; // eax
            #   int v33; // ecx
            #   LPVOID *v34; // eax
            #   char (*v35)[2]; // eax
            #   int v36; // ecx
            #   LPVOID *v37; // eax
            #   char (*v38)[2]; // eax
            #   _DWORD **v39; // ecx
            #   int v40; // eax
            #   int v41; // eax
            #   _DWORD **v42; // ecx
            #   int v43; // eax
            #   int v44; // eax
            #   int v45; // eax
            #   _DWORD **v46; // ecx
            #   int v47; // eax
            #   int v48; // eax
            #   int v49; // eax
            #   int v50; // ecx
            #   char v51; // al
            #   char v52; // bl
            #   char v53[32]; // [esp+Ch] [ebp-B0h]
            #   int v54; // [esp+2Ch] [ebp-90h]
            #   char v55; // [esp+30h] [ebp-8Ch]
            #   int v56; // [esp+3Ch] [ebp-80h]
            #   int v57; // [esp+40h] [ebp-7Ch]
            #   int v58; // [esp+44h] [ebp-78h]
            #   int v59; // [esp+48h] [ebp-74h]
            #   int v60; // [esp+4Ch] [ebp-70h]
            #   int v61; // [esp+50h] [ebp-6Ch]
            #   int v62; // [esp+94h] [ebp-28h]
            #   int v63; // [esp+98h] [ebp-24h]
            #   int v64; // [esp+9Ch] [ebp-20h]
            #   int v65; // [esp+A0h] [ebp-1Ch]
            #   int v66; // [esp+A4h] [ebp-18h]
            #   int v67; // [esp+A8h] [ebp-14h]
            #   int v68; // [esp+ACh] [ebp-10h]
            #   int v69; // [esp+B8h] [ebp-4h]
            #   int v70; // [esp+BCh] [ebp+0h]
            #   int v71; // [esp+C0h] [ebp+4h]
            #   int v72; // [esp+C4h] [ebp+8h]
            #   int v73; // [esp+C8h] [ebp+Ch]
            #   int v74; // [esp+CCh] [ebp+10h]
            #   int v75; // [esp+D0h] [ebp+14h]
            #   int v76; // [esp+D4h] [ebp+18h]
            #   int v77; // [esp+D8h] [ebp+1Ch]
            #   int v78; // [esp+DCh] [ebp+20h]
            #   int v79; // [esp+E0h] [ebp+24h]
            #   LPVOID v80; // [esp+E4h] [ebp+28h]
            #   LPVOID lpMem; // [esp+E8h] [ebp+2Ch]
            #
            #   v1 = this;
            #   sub_6DE8E0(&v54);
            #   v2 = (int *)v1[9354];
            #   v3 = -1;
            #   v70 = 0;
            #   v4 = 0;
            #   v76 = -1;
            #   v77 = -1;
            #   v5 = *v2;
            #   v79 = -1;
            #   v78 = -1;
            #   v75 = 0;
            #   v74 = 0;
            #   v73 = 1;
            #   v72 = 110;
            #   v71 = 20;
            #   (*(void (**)(void))(v5 + 384))();
            #   v6 = (LPVOID *)(*(int (__stdcall **)(LPVOID *))(*(_DWORD *)v1[9384] + 384))(&lpMem);
            #   v69 = 0;
            #   v7 = sub_8EDE00(v6);
            #   v8 = (char *)(v53 - (char *)v7);
            #   do
            #   {
            #     v9 = *(_BYTE *)v7;
            #     v7 = (char (*)[2])((char *)v7 + 1);
            #     (*v7)[(_DWORD)v8 - 1] = v9;
            #   }
            #   while ( v9 );
            #   v69 = 1;
            #   if ( lpMem )
            #     sub_8EFAE0(lpMem);
            #   v10 = (_DWORD **)v1[9378];
            #   v69 = -1;
            #   sub_93D7B0(v10);
            #   if ( v11 )
            #   {
            #     sub_93D7B0((_DWORD **)v1[9378]);
            #     v78 = dword_1050BAC[2 * v12];
            #   }
            #   sub_93D7B0((_DWORD **)v1[9379]);
            #   if ( v13 )
            #   {
            #     sub_93D7B0((_DWORD **)v1[9379]);
            #     v79 = dword_C32974[2 * v14];
            #   }
            #   sub_93D7B0((_DWORD **)v1[9377]);
            #   if ( v15 )
            #   {
            #     sub_93D7B0((_DWORD **)v1[9377]);
            #     v16 = (_DWORD **)v1[9377];
            #     v76 = dword_AE7444[2 * v17];
            #     v18 = (volatile signed __int32 **)sub_93D800(v16, &lpMem);
            #     v19 = (_DWORD *)v1[9354];
            #     v69 = 2;
            #     sub_91AA50(v19, 9, v18);
            #     v69 = 3;
            #     if ( lpMem )
            #       sub_8EFAE0(lpMem);
            #     v69 = -1;
            #   }
            #   sub_93D7B0((_DWORD **)v1[9376]);
            #   if ( v20 )
            #   {
            #     sub_93D7B0((_DWORD **)v1[9376]);
            #     v77 = dword_AE739C[2 * v21];
            #   }
            #   sub_93D7B0((_DWORD **)v1[9380]);
            #   if ( v22 )
            #   {
            #     sub_93D7B0((_DWORD **)v1[9380]);
            #     v3 = dword_AE725C[2 * v23];
            #   }
            #   v24 = v1[9385];
            #   if ( v24 )
            #   {
            #     v25 = (LPVOID *)(*(int (__stdcall **)(LPVOID *))(*(_DWORD *)v24 + 384))(&lpMem);
            #     v69 = 4;
            #     v26 = sub_8EDE00(v25);
            #     v74 = sub_9A1DBD((int)v26);
            #     v69 = 5;
            #     if ( lpMem )
            #       sub_8EFAE0(lpMem);
            #     v69 = -1;
            #   }
            #   v27 = v1[9386];
            #   if ( v27 )
            #   {
            #     v28 = (LPVOID *)(*(int (__stdcall **)(LPVOID *))(*(_DWORD *)v27 + 384))(&lpMem);
            #     v69 = 6;
            #     v29 = sub_8EDE00(v28);
            #     v75 = sub_9A1DBD((int)v29);
            #     v69 = 7;
            #     if ( lpMem )
            #       sub_8EFAE0(lpMem);
            #     v69 = -1;
            #   }
            #   v30 = v1[9387];
            #   if ( v30 )
            #   {
            #     v31 = (LPVOID *)(*(int (__stdcall **)(LPVOID *))(*(_DWORD *)v30 + 384))(&lpMem);
            #     v69 = 8;
            #     v32 = sub_8EDE00(v31);
            #     v72 = sub_9A1DBD((int)v32);
            #     v69 = 9;
            #     if ( lpMem )
            #       sub_8EFAE0(lpMem);
            #     v69 = -1;
            #   }
            #   v33 = v1[9388];
            #   if ( v33 )
            #   {
            #     v34 = (LPVOID *)(*(int (__stdcall **)(LPVOID *))(*(_DWORD *)v33 + 384))(&lpMem);
            #     v69 = 10;
            #     v35 = sub_8EDE00(v34);
            #     v73 = sub_9A1DBD((int)v35);
            #     v69 = 11;
            #     if ( lpMem )
            #       sub_8EFAE0(lpMem);
            #     v69 = -1;
            #   }
            #   v36 = v1[9389];
            #   if ( v36 )
            #   {
            #     v37 = (LPVOID *)(*(int (__stdcall **)(LPVOID *))(*(_DWORD *)v36 + 384))(&v80);
            #     v69 = 12;
            #     v38 = sub_8EDE00(v37);
            #     v71 = sub_9A1DBD((int)v38);
            #     v69 = 13;
            #     if ( v80 )
            #       sub_8EFAE0(v80);
            #     v80 = 0;
            #     v69 = -1;
            #   }
            #   v39 = (_DWORD **)v1[9381];
            #   if ( v39 )
            #   {
            #     sub_93D7B0(v39);
            #     if ( v40 != -1 )
            #     {
            #       sub_93DA40((_DWORD *)v1[9381], v40);
            #       v4 = v41;
            #     }
            #   }
            #   v42 = (_DWORD **)v1[9382];
            #   if ( v42 )
            #   {
            #     sub_93D7B0(v42);
            #     if ( v43 )
            #     {
            #       sub_93D7B0((_DWORD **)v1[9382]);
            #       sub_93DA40((_DWORD *)v1[9382], v44);
            #       v70 = v45;
            #     }
            #   }
            #   v46 = (_DWORD **)v1[9383];
            #   if ( v46 && (sub_93D7B0(v46), v47) )
            #   {
            #     sub_93D7B0((_DWORD **)v1[9383]);
            #     sub_93DA40((_DWORD *)v1[9383], v48);
            #   }
            #   else
            #   {
            #     v49 = 0;
            #   }
            #   v57 = v79;
            #   v58 = v78;
            #   v60 = v77;
            #   v59 = v76;
            #   v62 = v75;
            #   v63 = v74;
            #   v64 = v73;
            #   v65 = v72;
            #   v66 = v71;
            #   v54 = 7;
            #   v61 = v3;
            #   v67 = v70;
            #   v68 = v49;
            #   if ( v4 == -1 )
            #   {
            #     v55 = 0;
            #     v56 = 0;
            #   }
            #   else
            #   {
            #     v55 = 1;
            #     v56 = v4;
            #   }
            #   v50 = 0;
            #   do
            #   {
            #     v51 = v53[v50++];
            #     *((_BYTE *)&v61 + v50 + 3) = v51;
            #   }
            #   while ( v51 );
            #   if ( *(_DWORD *)dword_E861A4 )
            #   {
            #     word_E85FA0 = sub_89FEA0(20371, 0);
            #     qmemcpy(&dword_E85FA2, &v54, 0x84u);
            #     v52 = sub_840970(*(int *)dword_E861A4, 4, &word_E85FA0, 0x86u);
            #     j_j_j___free_base(0);
            #     --dword_1076B04;
            #     if ( v52 )
            #       sub_83D780(*(int *)dword_E861A4);
            #     else
            #       sub_4EADF0((_DWORD *)dword_CA1D1C, (LPCRITICAL_SECTION **)dword_E861A4);
            #   }
            #   else if ( !byte_E95BA4 )
            #   {
            #     sub_8F18D0("Attempt to send message %d on a void connection.", 20371);
            #   }
            # }
            if functionString.find("= this;") != -1:
                if functionString.find("= 0;") != -1:
                    if functionString.find("= -1;") != -1:
                        if functionString.find("= 1;") != -1:
                            if functionString.find("= 110;") != -1:
                                if functionString.find("= 20;") != -1:
                                    if functionString.find("= 2;") != -1:
                                        if functionString.find("= 3;") != -1:
                                            if functionString.find("= 4;") != -1:
                                                if functionString.find("= 5;") != -1:
                                                    if functionString.find("= 6;") != -1:
                                                        if functionString.find("= 7;") != -1:
                                                            if functionString.find("= 8;") != -1:
                                                                if functionString.find("= 9;") != -1:
                                                                    if functionString.find("= 10;") != -1:
                                                                        if functionString.find("= 11;") != -1:
                                                                            if functionString.find("= 12;") != -1:
                                                                                if functionString.find("= 13;") != -1:
                                                                                    if functionString.find(", 9, ") != -1:
                                                                                        if functionString.find("[2 * ") != -1:
                                                                                            if functionString.find("while") != -1:
                                                                                                functionList["CBazaarSearchWnd__doQuery"] = functionAddress

            # CBazaarConfirmationWnd
            # ----------------------------------------------------------------------------------------------------
            # char __thiscall sub_6DBE80(_DWORD *this, int a2)
            # {
            #   int v2; // esi
            #   signed int v3; // eax
            #   char *v4; // ecx
            #   void *v5; // eax
            #   int v6; // eax
            #   void *v7; // ecx
            #   int v8; // ST00_4
            #   void *v10; // [esp-20h] [ebp-34h]
            #   char *v11; // [esp-1Ch] [ebp-30h]
            #   void *v12; // [esp-18h] [ebp-2Ch]
            #   void *v13; // [esp-14h] [ebp-28h]
            #   void *v14; // [esp-10h] [ebp-24h]
            #   int v15; // [esp-Ch] [ebp-20h]
            #   char *v16; // [esp-8h] [ebp-1Ch]
            #   int v17; // [esp-4h] [ebp-18h]
            #   int v18; // [esp+10h] [ebp-4h]
            #
            #   v2 = (int)this;
            #   v3 = this[148];
            #   if ( v3 < 0 || v3 >= 200 || !dword_DD38B0 )
            #     return 0;
            #   v17 = a2;
            #   v4 = (char *)&this[46 * v3];
            #   v16 = v4 + 764;
            #   v15 = *((_DWORD *)v4 + 188);
            #   v5 = (void *)*(unsigned __int16 *)(v2 + 596);
            #   v14 = (void *)*((_DWORD *)v4 + 182);
            #   v13 = (void *)*((_DWORD *)v4 + 185);
            #   v12 = v5;
            #   v11 = v4;
            #   sub_8ED690((LPVOID *)&v11, v4 + 600);
            #   v6 = 184 * *(_DWORD *)(v2 + 592);
            #   v10 = v7;
            #   v18 = 0;
            #   sub_8ED690(&v10, (void *)(v2 + v6 + 664));
            #   v8 = *(_DWORD *)(184 * *(_DWORD *)(v2 + 592) + v2 + 748);
            #   v18 = -1;
            #   sub_4A3B00((char *)dword_DD38B0, v8, v10, v11, v12, v13, v14, v15, v16, v17);
            #   sub_9239B0(v2, (int *)&v14);
            #   sub_925050((_DWORD *)dword_DD38B0, (int)v14, v15, (int)v16, v17);
            #   v17 = 1;
            #   v16 = (char *)1;
            #   v15 = 1;
            #   (*(void (__stdcall **)(signed int, signed int, signed int))(*(_DWORD *)dword_DD38B0 + 216))(1, 1, 1);
            #   sub_9254B0((void *)dword_DD38B0, 1);
            #   return 1;
            # }
            if re.search("[0-9a-z]+ = this\[\d+\];", functionString):
                if functionString.find(">= 200 || !dword_") != -1:
                    if functionString.find("return 0;") != -1:
                        if functionString.find("return 1;") != -1:
                            matches = re.findall("if \( [0-9a-z]+ \< 0 \|\| [0-9a-z]+ \>\= 200 \|\| \!dword_([0-9A-F]+) \)", functionString, re.MULTILINE)
                            if matches:
                                functionList["CBazaarConfirmationWnd"] = "0x00" + matches[0]

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
            if functionString.find(", 0x2F35u,") != -1 or functionString.find(", 12085,") != -1:    # 12085 You must be completely stopped before doing this action.
                if functionString.find(", 0x22B2u,") != -1 or functionString.find(", 8882,") != -1:    # 8882 open
                    if functionString.find(", 0x22B3u,") != -1 or functionString.find(", 8883,") != -1:    # 8883 close
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
    #out_file.write("void EQ_InitializeAddresses()\n")
    #out_file.write("{\n")
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
    out_file.write("    EQ_ADDRESS_AutoAttack              = " + functionList["AutoAttack"] + ";\n")
    out_file.write("    EQ_ADDRESS_AutoFire                = " + functionList["AutoFire"] + ";\n")
    out_file.write("    EQ_ADDRESS_AutoRun                 = " + functionList["AutoRun"] + ";\n")
    out_file.write("    EQ_ADDRESS_MouseLook               = " + functionList["MouseLook"] + ";\n")
    out_file.write("    EQ_ADDRESS_NetStatus               = " + functionList["NetStatus"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_EQZoneInfo = " + functionList["EQZoneInfo"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_ControlledSpawn    = " + functionList["ControlledSpawn"] + ";\n")
    out_file.write("    EQ_ADDRESS_POINTER_PlayerSpawn        = " + functionList["PlayerSpawn"] + ";\n")
    out_file.write("    EQ_ADDRESS_POINTER_TargetSpawn        = " + functionList["TargetSpawn"] + ";\n")
    out_file.write("\n")
    #out_file.write("    EQ_ADDRESS_FUNCTION_FlushDxKeyboard               = " + functionList["FlushDxKeyboard"] + ";\n")
    #out_file.write("    EQ_ADDRESS_FUNCTION_FlushDxMouse                  = " + functionList["FlushDxMouse"] + ";\n")
    #out_file.write("    EQ_ADDRESS_FUNCTION_ProcessKeyboardEvent          = " + functionList["ProcessKeyboardEvent"] + ";\n")
    #out_file.write("    EQ_ADDRESS_FUNCTION_ProcessMouseEvent             = " + functionList["ProcessMouseEvent"] + ";\n")
    #out_file.write("    EQ_ADDRESS_FUNCTION_WindowProc                    = " + functionList["WindowProc"] + ";\n")
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
    #out_file.write("    EQ_ADDRESS_FUNCTION_AreAlertWindowsModified       = " + functionList["AreAlertWindowsModified"] + ";\n")
    #out_file.write("    EQ_ADDRESS_FUNCTION_get_bearing                   = " + functionList["get_bearing"] + ";\n")
    #out_file.write("    EQ_ADDRESS_FUNCTION_get_melee_range               = " + functionList["get_melee_range"] + ";\n")
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
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav            = " + functionList["CharacterZoneClient__SetNoGrav"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects    = " + functionList["CharacterZoneClient__TotalSpellAffects"] + ";\n")
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
    out_file.write("    EQ_ADDRESS_FUNCTION_EQPlayer__AllowedToAttack       = " + functionList["EQPlayer__AllowedToAttack"] + ";\n")
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
    out_file.write("    EQ_ADDRESS_FUNCTION_CEverQuest__RightClickedOnPlayer    = " + functionList["CEverQuest__RightClickedOnPlayer"] + ";\n")
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
    out_file.write("    EQ_ADDRESS_POINTER_CAlertStackWnd = " + functionList["CAlertStackWnd"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CBazaarSearchWnd = " + functionList["CBazaarSearchWnd"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList = " + functionList["CBazaarSearchWnd__AddItemToList"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem = " + functionList["CBazaarSearchWnd__BuyItem"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery = " + functionList["CBazaarSearchWnd__doQuery"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CBazaarConfirmationWnd = " + functionList["CBazaarConfirmationWnd"] + ";\n")
    out_file.write("\n")
    out_file.write("    EQ_ADDRESS_POINTER_CSpellBookWnd = " + functionList["CSpellBookWnd"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = " + functionList["CSpellBookWnd__GetSpellMemTicksLeft"] + ";\n")
    out_file.write("    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = " + functionList["CSpellBookWnd__GetSpellScribeTicksLeft"] + ";\n")
    #out_file.write("}\n")