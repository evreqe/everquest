function OnInterpretCommand(commandText)

    if commandText == "/cheevo" then
       EQ_PlaySound("achievement.wav")
       EQ_PrintTextToChat("CONGLATURATION !!!")
       EQ_PrintTextToChat("YOU HAVE COMPLETED A GREAT GAME.")
       EQ_PrintTextToChat("AND PROOVED THE JUSTICE OF OUR CULTURE.")
       EQ_PrintTextToChat("NOW GO AND REST OUR HEROES !")
       return 1
    end

end
