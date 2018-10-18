function OnDrawHUD()
    hudText = "- 1: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(0) .. "\n"
    hudText = hudText .. "- 2: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(1) .. "\n"
    hudText = hudText .. "- 3: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(2) .. "\n"
    hudText = hudText .. "- 4: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(3) .. "\n"
    hudText = hudText .. "- 5: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(4) .. "\n"
    hudText = hudText .. "- 6: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(5) .. "\n"
    hudText = hudText .. "- 7: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(6) .. "\n"
    hudText = hudText .. "- 8: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(7) .. "\n"
    hudText = hudText .. "- 9: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(8) .. "\n"
    hudText = hudText .. "- 10: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(9) .. "\n"
    hudText = hudText .. "- 11: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(10) .. "\n"
    hudText = hudText .. "- 12: " .. EQ_CastSpellWindow_GetSpellGemStateByIndex(11) .. "\n" .. "\n"

    return 1, hudText
end
