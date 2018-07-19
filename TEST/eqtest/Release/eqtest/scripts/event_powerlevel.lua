function OnOneSecond()
    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerClass = EQ_GetSpawnClass(playerSpawn)
    if playerClass == EQ_CLASS_SHADOWKNIGHT then
        local targetSpawn = EQ_GetTargetSpawn()
        if targetSpawn == 0 then
            return
        end

        local targetType = EQ_GetSpawnType(targetSpawn)
        if targetType ~= EQ_SPAWN_TYPE_NPC then
            return
        end

        local targetHP = EQ_GetSpawnHPCurrent(targetSpawn)
        if targetHP <= 45 then
            EQ_InterpretCommand("//BCT Gobn //Stand;//TargetID ${Target.ID};//Follow;//AutoAttackOn")
            EQ_InterpretCommand("//BCT Mezrr //Stand;//TargetID ${Target.ID};//Follow;//AutoAttackOn")
            EQ_InterpretCommand("//BCT Erigg //Stand;//TargetID ${Target.ID};//Follow;//AutoAttackOn")
            EQ_InterpretCommand("//BCT Berserkobn //Stand;//TargetID ${Target.ID};//Follow;//AutoAttackOn")
        end
    end
end
