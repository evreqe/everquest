#pragma once

#define EQ_OFFSET_SPAWN_MANAGER_SPAWN_INFO_FIRST                0x08          // uint32_t pointer
#define EQ_OFFSET_SPAWN_MANAGER_SPAWN_INFO_LAST                 0x0C          // uint32_t pointer

#define EQ_OFFSET_SPAWN_INFO_PREVIOUS                           0x04          // uint32_t pointer
#define EQ_OFFSET_SPAWN_INFO_NEXT                               0x08          // uint32_t pointer
#define EQ_OFFSET_SPAWN_INFO_SPEED_MODIFIER                     0x18          // float
#define EQ_OFFSET_SPAWN_INFO_LAST_NAME                          0x38          // char[0x20]    // surname
#define EQ_OFFSET_SPAWN_INFO_Y                                  0x64          // float
#define EQ_OFFSET_SPAWN_INFO_X                                  0x68          // float
#define EQ_OFFSET_SPAWN_INFO_Z                                  0x6C          // float
#define EQ_OFFSET_SPAWN_INFO_HEADING                            0x80          // float
#define EQ_OFFSET_SPAWN_INFO_NUMBERED_NAME                      0xA4          // char[0x40]    // "a_grass_snake01"
#define EQ_OFFSET_SPAWN_INFO_NAME                               0xE4          // char[0x40]    // "a grass snake"
#define EQ_OFFSET_SPAWN_INFO_TYPE                               0x125         // uint8_t
#define EQ_OFFSET_SPAWN_INFO_BODY_TYPE_DESCRIPTION              0x128         // EQ_CEverQuest->GetBodyTypeDesc(spawnInfo + 0x128);
#define EQ_OFFSET_SPAWN_INFO_HEIGHT                             0x13C         // float
#define EQ_OFFSET_SPAWN_INFO_ID                                 0x148         // uint32_t
#define EQ_OFFSET_SPAWN_INFO_IS_LFG                             0x1F1         // uint8_t    // looking for group
#define EQ_OFFSET_SPAWN_INFO_HP                                 0x1F8         // uint32_t    // hit points
#define EQ_OFFSET_SPAWN_INFO_IS_TRADER                          0x228         // uint32_t
#define EQ_OFFSET_SPAWN_INFO_PET_OWNER_SPAWN_ID                 0x260         // uint32_t
#define EQ_OFFSET_SPAWN_INFO_STANDING_STATE                     0x279         // uint8_t
#define EQ_OFFSET_SPAWN_INFO_IS_AFK                             0x284         // uint32_t
#define EQ_OFFSET_SPAWN_INFO_IS_PVP                             0x2BC         // uint8_t    // player kill flag, red name above head
#define EQ_OFFSET_SPAWN_INFO_MANA                               0x304         // uint32_t
#define EQ_OFFSET_SPAWN_INFO_GUILD_ID                           0x30C         // uint32_t
#define EQ_OFFSET_SPAWN_INFO_LEVEL                              0x315         // uint8_t
#define EQ_OFFSET_SPAWN_INFO_SPELL_CASTING_TIMER                0x448         // uint32_t
#define EQ_OFFSET_SPAWN_INFO_IS_GM                              0x4DA         // uint8_t    // gamemaster
#define EQ_OFFSET_SPAWN_INFO_DEITY                              0xD4D         // uint8_t
#define EQ_OFFSET_SPAWN_INFO_FOLLOW_SPAWN_INFO                  0xDF4         // uint32_t pointer
#define EQ_OFFSET_SPAWN_INFO_RACE                               0xE64         // uint32_t
#define EQ_OFFSET_SPAWN_INFO_CLASS                              0xE68         // uint8_t
#define EQ_OFFSET_SPAWN_INFO_GENDER                             0xE69         // uint8_t
#define EQ_OFFSET_SPAWN_INFO_ACTOR_INFO                         0xF84         // uint32_t pointer
#define EQ_OFFSET_SPAWN_INFO_ANIMATION                          0x1004        // uint32_t
#define EQ_OFFSET_SPAWN_INFO_IS_HOLDING_PRIMARY                 0x10E0        // uint8_t
#define EQ_OFFSET_SPAWN_INFO_IS_HOLDING_SECONDARY               0x10E4        // uint8_t
#define EQ_OFFSET_SPAWN_INFO_IS_INVITED_TO_GROUP                0x1154        // uint8_t

#define EQ_OFFSET_GROUND_SPAWN_INFO_PREVIOUS                    0x00          // uint32_t pointer
#define EQ_OFFSET_GROUND_SPAWN_INFO_NEXT                        0x04          // uint32_t pointer
#define EQ_OFFSET_GROUND_SPAWN_INFO_Z                           0x2C          // float
#define EQ_OFFSET_GROUND_SPAWN_INFO_X                           0x30          // float
#define EQ_OFFSET_GROUND_SPAWN_INFO_Y                           0x34          // float
#define EQ_OFFSET_GROUND_SPAWN_INFO_NAME                        0x38          // char[0x18]

#define EQ_OFFSET_ACTOR_INFO_0x00                               0x00          // UNKNOWN
#define EQ_OFFSET_ACTOR_INFO_NAME                               0x10          // char*    // offset is negative, use subtract
#define EQ_OFFSET_ACTOR_INFO_Y1                                 0x28          // float
#define EQ_OFFSET_ACTOR_INFO_X1                                 0x2C          // float
#define EQ_OFFSET_ACTOR_INFO_Z1                                 0x30          // float
#define EQ_OFFSET_ACTOR_INFO_THIS                               0x6C          // uint32_t pointer    // points to 0x00
#define EQ_OFFSET_ACTOR_INFO_SPAWN_INFO                         0x70          // uint32_t pointer
#define EQ_OFFSET_ACTOR_INFO_Y2                                 0xB4          // float    // collision or hitbox, set to 0.0f for zone actors for no collision
#define EQ_OFFSET_ACTOR_INFO_X2                                 0xB8          // float    // collision or hitbox, set to 0.0f for zone actors for no collision
#define EQ_OFFSET_ACTOR_INFO_Z2                                 0xBC          // float    // collision or hitbox, set to 0.0f for zone actors for no collision
#define EQ_OFFSET_ACTOR_INFO_COLLISION_TYPE                     0x100         // uint32_t    // usually equals 2
#define EQ_OFFSET_ACTOR_INFO_COLLISION_RADIUS                   0x104         // float
#define EQ_OFFSET_ACTOR_INFO_MODEL_INFO                         0x11C         // uint32_t pointer
#define EQ_OFFSET_ACTOR_INFO_Y3                                 0x150         // float
#define EQ_OFFSET_ACTOR_INFO_X3                                 0x154         // float
#define EQ_OFFSET_ACTOR_INFO_Z3                                 0x158         // float

#define EQ_OFFSET_ACTOR_INSTANCE_INFO_SPAWN_INFO                0x70          // uint32_t pointer

#define EQ_OFFSET_MODEL_INFO_BONE_LIST                          0x58          // uint32_t pointer

#define EQ_OFFSET_BONE_INFO_Y                                   0x90          // float
#define EQ_OFFSET_BONE_INFO_X                                   0x94          // float
#define EQ_OFFSET_BONE_INFO_Z                                   0x98          // float
#define EQ_OFFSET_BONE_INFO_CHILD_BONE_LIST                     0xE0          // uint32_t

// doors are switches
#define EQ_OFFSET_SWITCH_MANAGER_NUM_DOORS                      0x00          // uint32_t
#define EQ_OFFSET_SWITCH_MANAGER_DOOR_INFO_FIRST                0x04          // uint32_t pointer

#define EQ_OFFSET_DOOR_INFO_NAME                                0x06          // char[0x20]
#define EQ_OFFSET_DOOR_INFO_Y                                   0x44          // float
#define EQ_OFFSET_DOOR_INFO_X                                   0x48          // float
#define EQ_OFFSET_DOOR_INFO_Z                                   0x4C          // float

#define EQ_OFFSET_CHAR_INFO_BANK_ITEM_INFO_FIRST                0x1128        // uint32_t pointer
#define EQ_OFFSET_CHAR_INFO_GROUP_INFO                          0xF1B8        // uint32_t pointer
#define EQ_OFFSET_CHAR_INFO_CI2                                 0xF1D8        // uint32_t pointer
#define EQ_OFFSET_CHAR_INFO_CHARACTER_NAME                      0xF210        // char[0x40]
#define EQ_OFFSET_CHAR_INFO_ZONE_ID                             0xF2D4        // uint16_t
#define EQ_OFFSET_CHAR_INFO_BANK_PLATINUM                       0xF5A4        // uint32_t
#define EQ_OFFSET_CHAR_INFO_BANK_GOLD                           0xF5A8        // uint32_t
#define EQ_OFFSET_CHAR_INFO_BANK_SILVER                         0xF5AC        // uint32_t
#define EQ_OFFSET_CHAR_INFO_BANK_COPPER                         0xF5B0        // uint32_t

#define EQ_OFFSET_GROUP_MEMBER_INFO_SPAWN_INFO                  0x28          // uint32_t pointer

#define EQ_OFFSET_CI2_CHAR_INFO_2                               0x04          // uint32_t pointer

#define EQ_OFFSET_CHAR_INFO_2_INVENTORY_ITEM_INFO_FIRST         0x10          // uint32_t pointer
#define EQ_OFFSET_CHAR_INFO_2_SKILL_SWIMMING                    0x144C        // uint8_t
#define EQ_OFFSET_CHAR_INFO_2_INVENTORY_PLATINUM                0x1654        // uint32_t
#define EQ_OFFSET_CHAR_INFO_2_INVENTORY_GOLD                    0x1658        // uint32_t
#define EQ_OFFSET_CHAR_INFO_2_INVENTORY_SILVER                  0x165C        // uint32_t
#define EQ_OFFSET_CHAR_INFO_2_INVENTORY_COPPER                  0x1660        // uint32_t

#define EQ_OFFSET_CEverQuest_GAME_STATE                         0x5C4

#define EQ_OFFSET_CDisplay_IS_HIDE_CORPSE_LOOTED_ENABLED        0x14          // uint8_t
#define EQ_OFFSET_CDisplay_CAMERA_DATA                          0x118         // uint32_t pointer
#define EQ_OFFSET_CDisplay_TIMER                                0x154         // uint32_t

#define EQ_OFFSET_CAMERA_DATA_FIELD_OF_VIEW                     0x04          // float
#define EQ_OFFSET_CAMERA_DATA_DRAW_DISTANCE                     0x14          // float
#define EQ_OFFSET_CAMERA_DATA_HEADING                           0xB0          // float
#define EQ_OFFSET_CAMERA_DATA_PITCH                             0xB4          // float
#define EQ_OFFSET_CAMERA_DATA_Y                                 0xBC          // float
#define EQ_OFFSET_CAMERA_DATA_X                                 0xC0          // float
#define EQ_OFFSET_CAMERA_DATA_Z                                 0xC4          // float

#define EQ_OFFSET_WINDOW_IS_VISIBLE                             0x124         // uint8_t
#define EQ_OFFSET_WINDOW_IS_OPEN                                0x12C         // uint8_t

#define EQ_OFFSET_CONTAINER_MANAGER_CONTAINER_WINDOW_INFO_FIRST 0x04          // uint32_t pointer

#define EQ_OFFSET_CMapViewWnd_MAP                               0x28C         // uint32_t pointer
#define EQ_OFFSET_CMapViewWnd_MAP_LABEL_INFO_FIRST              0x2D0         // uint32_t pointer
#define EQ_OFFSET_CMapViewWnd_SHOULD_UPDATE_MAP                 0x312         // uint8_t    // set to 1 to force the map to update

#define EQ_OFFSET_CLootWnd_ITEM_INFO_FIRST                      0x228         // uint32_t pointer

#define EQ_OFFSET_SPELL_INFO_NAME                               0x247         // char[0x40]

#define EQ_OFFSET_SPELL_MANAGER_SPELL_INFO_FIRST                0x68          // uint32_t pointer

#define EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO                 0x0C          // uint32_t pointer
#define EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO                       0xB8          // uint32_t pointer
#define EQ_OFFSET_ITEM_INFO_NAME                                0xB8          // char*    // name is just the first thing in the sub info
#define EQ_OFFSET_ITEM_INFO_COUNT                               0xD0          // uint32_t

#define EQ_OFFSET_ITEM_SUB_INFO_ID                              0xD0          // uint32_t
#define EQ_OFFSET_ITEM_SUB_INFO_ICON                            0xDC          // uint32_t
#define EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP                  0xEB          // uint8_t
#define EQ_OFFSET_ITEM_SUB_INFO_IS_LORE                         0xF0          // uint32_t
#define EQ_OFFSET_ITEM_SUB_INFO_SLOTS                           0x475         // uint8_t

#define EQ_OFFSET_CXWndManager_FONT_MANAGER                     0xF8          // uint32_t pointer

#define EQ_OFFSET_FONT_MANAGER_FONT_INFO_1                      0x04          // uint32_t pointer
#define EQ_OFFSET_FONT_MANAGER_FONT_INFO_2                      0x08          // uint32_t pointer

#define EQ_OFFSET_FONT_INFO_SIZE                                0x04          // uint32_t

#define EQ_OFFSET_0x00B112C0_POINTER_2                          0x94          // uint32_t pointer
#define EQ_OFFSET_0x00B112C0_POINTER_2_ZONE_ACTOR_INFO_FIRST    0x5C          // uint32_t pointer

#define EQ_OFFSET_ZONE_ACTOR_INFO_NEXT                          0x04          // uint32_t pointer
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x0C                          0x0C          // uint32_t    // if value == 2 then skip it
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x14                          0x14          // uint32_t pointer
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x14_0x18                     0x18          // uint32_t pointer
#define EQ_OFFSET_ZONE_ACTOR_INFO_NAME_0x14_0x18_0x08           0x08          // char*
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x1C                          0x1C          // uint32_t    // 1 = object, 3 = player or NPC
#define EQ_OFFSET_ZONE_ACTOR_INFO_ACTOR_INFO                0x18              // uint32_t pointer    // same as spawn actor info
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x2C                          0x2C          // uint8_t    // is dynamic model (player, npc, door, tradeskill container, animated torches)
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x2D                          0x2D          // uint8_t    // is static model (not moving object)
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x2E                          0x2E          // uint8_t
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x2F                          0x2F          // uint8_t
#define EQ_OFFSET_ZONE_ACTOR_INFO_Y                             0x30          // float
#define EQ_OFFSET_ZONE_ACTOR_INFO_X                             0x34          // float
#define EQ_OFFSET_ZONE_ACTOR_INFO_Z                             0x38          // float
#define EQ_OFFSET_ZONE_ACTOR_INFO_ROTATION                      0x3C          // float    // 0-512 degrees
#define EQ_OFFSET_ZONE_ACTOR_INFO_SCALE                         0x48          // float    // 0.0 to 0.1
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x54                          0x54          // uint32_t or float or uint8_t[4]

