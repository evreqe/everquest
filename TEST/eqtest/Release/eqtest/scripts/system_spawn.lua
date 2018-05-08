local EQSpawn = {}
EQSpawn.__index = EQSpawn

setmetatable(EQSpawn, {__call = function (cls, ...) return cls.new(...) end,})

function EQSpawn.new(init)
    local self = setmetatable({}, EQSpawn)
    self.value = init
    return self
end

function EQSpawn:SetSpawn(spawn)
    self.value = spawn
end

function EQSpawn:GetSpawn()
    return self.value
end

function EQSpawn:GetSpawnName()
    return EQ_GetSpawnName(self.value)
end
