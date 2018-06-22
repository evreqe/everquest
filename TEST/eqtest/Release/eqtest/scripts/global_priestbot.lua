g_PriestBotIsEnabled = 0

g_PriestBotTargetName = "Paldn"

function PriestBot_BigHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)
    EQ_InterpretCommand("//Cast 1")
end

function PriestBot_FastHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)
    EQ_InterpretCommand("//Cast 3")
end

function PriestBot_InstantHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)
    EQ_InterpretCommand("//Cast 7")
end