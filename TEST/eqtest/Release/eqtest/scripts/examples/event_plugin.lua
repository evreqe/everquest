g_PluginIsEnabled = 0

function OnLoad()

    EQ_PrintTextToChat("Plugin loaded!")

end

function OnUnload()

    EQ_PrintTextToChat("Plugin unloaded!")

end

function OnInterpretCommand(text)

    if text == "//Plugin" then

        if g_PluginIsEnabled == 0 then

            g_PluginIsEnabled = 1
            EQ_PrintTextToChat("Plugin: On")

        else

            g_PluginIsEnabled = 0
            EQ_PrintTextToChat("Plugin: Off")

        end

        return 1
    end

    if text == "//PluginOn" then

        g_PluginIsEnabled = 1
        EQ_PrintTextToChat("Plugin: On")

        return 1

    end

    if text == "//PluginOff" then

        g_PluginIsEnabled = 0
        EQ_PrintTextToChat("Plugin: Off")

        return 1

    end

end

function OnTick()

    if g_PluginIsEnabled == 0 then
        return
    end

    EQ_PrintTextToChat("Plugin tick!")

end
