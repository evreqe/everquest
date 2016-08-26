#pragma once

#define EQ_OFFSET_SPAWN_INFO_PREVIOUS                           0x00          // DWORD POINTER
#define EQ_OFFSET_SPAWN_INFO_NEXT                               0x00          // DWORD POINTER
#define EQ_OFFSET_SPAWN_INFO_SPEED_MODIFIER                     0x00          // FLOAT
#define EQ_OFFSET_SPAWN_INFO_LAST_NAME                          0x00          // STRING [0x20]    // surname
#define EQ_OFFSET_SPAWN_INFO_Y                                  0x00          // FLOAT
#define EQ_OFFSET_SPAWN_INFO_X                                  0x00          // FLOAT
#define EQ_OFFSET_SPAWN_INFO_Z                                  0x00          // FLOAT
#define EQ_OFFSET_SPAWN_INFO_HEADING                            0x00          // FLOAT
#define EQ_OFFSET_SPAWN_INFO_NUMBERED_NAME                      0x00          // STRING [0x40]    // "a_grass_snake01"
#define EQ_OFFSET_SPAWN_INFO_NAME                               0x00          // STRING [0x40]    // "a grass snake"
#define EQ_OFFSET_SPAWN_INFO_TYPE                               0x00          // BYTE
#define EQ_OFFSET_SPAWN_INFO_BODY_TYPE_DESCRIPTION              0x00          // EQ_CEverQuest->GetBodyTypeDesc(spawnInfo + 0x128);
#define EQ_OFFSET_SPAWN_INFO_HEIGHT                             0x000         // FLOAT
#define EQ_OFFSET_SPAWN_INFO_ID                                 0x000         // DWORD
#define EQ_OFFSET_SPAWN_INFO_IS_LFG                             0x000         // BYTE    // looking for group
#define EQ_OFFSET_SPAWN_INFO_IS_TRADER                          0x000         // DWORD
#define EQ_OFFSET_SPAWN_INFO_PET_OWNER_SPAWN_ID                 0x000         // DWORD
#define EQ_OFFSET_SPAWN_INFO_STANDING_STATE                     0x000         // BYTE
#define EQ_OFFSET_SPAWN_INFO_IS_AFK                             0x000         // DWORD
#define EQ_OFFSET_SPAWN_INFO_IS_PVP                             0x000         // BYTE    // player kill flag, red name above head
#define EQ_OFFSET_SPAWN_INFO_GUILD_ID                           0x000         // DWORD
#define EQ_OFFSET_SPAWN_INFO_LEVEL                              0x000         // BYTE
#define EQ_OFFSET_SPAWN_INFO_SPELL_CASTING_TIMER                0x000         // DWORD
#define EQ_OFFSET_SPAWN_INFO_IS_GM                              0x000         // BYTE    // gamemaster
#define EQ_OFFSET_SPAWN_INFO_DEITY                              0x000         // BYTE
#define EQ_OFFSET_SPAWN_INFO_FOLLOW_SPAWN_INFO                  0x000         // DWORD POINTER
#define EQ_OFFSET_SPAWN_INFO_RACE                               0x000         // DWORD
#define EQ_OFFSET_SPAWN_INFO_CLASS                              0x000         // BYTE
#define EQ_OFFSET_SPAWN_INFO_GENDER                             0x000         // BYTE
#define EQ_OFFSET_SPAWN_INFO_ACTOR_INFO                         0x000         // DWORD POINTER
#define EQ_OFFSET_SPAWN_INFO_ANIMATION                          0x0000        // DWORD
#define EQ_OFFSET_SPAWN_INFO_IS_HOLDING_PRIMARY                 0x0000        // BYTE
#define EQ_OFFSET_SPAWN_INFO_IS_HOLDING_SECONDARY               0x0000        // BYTE
#define EQ_OFFSET_SPAWN_INFO_IS_INVITED_TO_GROUP                0x0000        // BYTE

#define EQ_OFFSET_GROUND_SPAWN_INFO_PREVIOUS                    0x00          // DWORD POINTER
#define EQ_OFFSET_GROUND_SPAWN_INFO_NEXT                        0x00          // DWORD POINTER
#define EQ_OFFSET_GROUND_SPAWN_INFO_Z                           0x00          // FLOAT
#define EQ_OFFSET_GROUND_SPAWN_INFO_X                           0x00          // FLOAT
#define EQ_OFFSET_GROUND_SPAWN_INFO_Y                           0x00          // FLOAT
#define EQ_OFFSET_GROUND_SPAWN_INFO_NAME                        0x00          // STRING [0x18]

#define EQ_OFFSET_ACTOR_INFO_COLLISION_RADIUS                   0x000         // FLOAT
#define EQ_OFFSET_ACTOR_INFO_MODEL_INFO                         0x000         // DWORD POINTER

#define EQ_OFFSET_ACTOR_INSTANCE_INFO_SPAWN_INFO                0x00          // DWORD POINTER

#define EQ_OFFSET_MODEL_INFO_BONE_LIST                          0x00          // DWORD POINTER

#define EQ_OFFSET_BONE_INFO_Y                                   0x00          // FLOAT
#define EQ_OFFSET_BONE_INFO_X                                   0x00          // FLOAT
#define EQ_OFFSET_BONE_INFO_Z                                   0x00          // FLOAT

// doors are switches
#define EQ_OFFSET_SWITCH_MANAGER_NUM_DOORS                      0x00          // DWORD
#define EQ_OFFSET_SWITCH_MANAGER_DOOR_INFO_FIRST                0x00          // DWORD POINTER

#define EQ_OFFSET_DOOR_INFO_NAME                                0x00          // STRING [0x20]
#define EQ_OFFSET_DOOR_INFO_Y                                   0x00          // FLOAT
#define EQ_OFFSET_DOOR_INFO_X                                   0x00          // FLOAT
#define EQ_OFFSET_DOOR_INFO_Z                                   0x00          // FLOAT

#define EQ_OFFSET_CHAR_INFO_BANK_ITEM_INFO_FIRST                0x0000        // DWORD POINTER
#define EQ_OFFSET_CHAR_INFO_GROUP_INFO                          0x0000        // DWORD POINTER
#define EQ_OFFSET_CHAR_INFO_CI2                                 0x0000        // DWORD POINTER
#define EQ_OFFSET_CHAR_INFO_CHARACTER_NAME                      0x0000        // STRING [0x40]
#define EQ_OFFSET_CHAR_INFO_ZONE_ID                             0x0000        // WORD
#define EQ_OFFSET_CHAR_INFO_BANK_PLATINUM                       0x0000        // DWORD
#define EQ_OFFSET_CHAR_INFO_BANK_GOLD                           0x0000        // DWORD
#define EQ_OFFSET_CHAR_INFO_BANK_SILVER                         0x0000        // DWORD
#define EQ_OFFSET_CHAR_INFO_BANK_COPPER                         0x0000        // DWORD

#define EQ_OFFSET_GROUP_MEMBER_INFO_SPAWN_INFO                  0x00          // DWORD POINTER

#define EQ_OFFSET_CI2_CHAR_INFO_2                               0x00          // DWORD POINTER

#define EQ_OFFSET_CHAR_INFO_2_INVENTORY_ITEM_INFO_FIRST         0x00          // DWORD POINTER
#define EQ_OFFSET_CHAR_INFO_2_SKILL_SWIMMING                    0x0000        // BYTE
#define EQ_OFFSET_CHAR_INFO_2_INVENTORY_PLATINUM                0x0000        // DWORD
#define EQ_OFFSET_CHAR_INFO_2_INVENTORY_GOLD                    0x0000        // DWORD
#define EQ_OFFSET_CHAR_INFO_2_INVENTORY_SILVER                  0x0000        // DWORD
#define EQ_OFFSET_CHAR_INFO_2_INVENTORY_COPPER                  0x0000        // DWORD

#define EQ_OFFSET_CEverQuest_GAME_STATE                         0x000

#define EQ_OFFSET_CDisplay_IS_HIDE_CORPSE_LOOTED_ENABLED        0x00          // BYTE
#define EQ_OFFSET_CDisplay_CAMERA_INFO                          0x118         // DWORD POINTER
#define EQ_OFFSET_CDisplay_TIMER                                0x154         // DWORD

#define EQ_OFFSET_CAMERA_INFO_FIELD_OF_VIEW                     0x04          // FLOAT
#define EQ_OFFSET_CAMERA_INFO_DRAW_DISTANCE                     0x14          // FLOAT
#define EQ_OFFSET_CAMERA_INFO_HEADING                           0xB0          // FLOAT
#define EQ_OFFSET_CAMERA_INFO_PITCH                             0xB4          // FLOAT
#define EQ_OFFSET_CAMERA_INFO_Y                                 0xBC          // FLOAT
#define EQ_OFFSET_CAMERA_INFO_X                                 0xC0          // FLOAT
#define EQ_OFFSET_CAMERA_INFO_Z                                 0xC4          // FLOAT

#define EQ_OFFSET_WINDOW_IS_VISIBLE                             0x000         // BYTE
#define EQ_OFFSET_WINDOW_IS_OPEN                                0x000         // BYTE

#define EQ_OFFSET_CONTAINER_MANAGER_CONTAINER_WINDOW_INFO_FIRST 0x00          // DWORD POINTER

#define EQ_OFFSET_CMapViewWnd_MAP                               0x000         // DWORD POINTER
#define EQ_OFFSET_CMapViewWnd_MAP_LABEL_INFO_FIRST              0x000         // DWORD POINTER
#define EQ_OFFSET_CMapViewWnd_SHOULD_UPDATE_MAP                 0x000         // BYTE    // set to 1 to force the map to update

#define EQ_OFFSET_CLootWnd_ITEM_INFO_FIRST                      0x000         // DWORD POINTER

#define EQ_OFFSET_SPELL_INFO_NAME                               0x000         // STRING [0x40]

#define EQ_OFFSET_SPELL_MANAGER_SPELL_INFO_FIRST                0x00          // DWORD POINTER

#define EQ_OFFSET_ITEM_INFO_CONTAINER_ITEM_INFO                 0x00          // DWORD POINTER
#define EQ_OFFSET_ITEM_INFO_ITEM_SUB_INFO                       0x00          // DWORD POINTER
#define EQ_OFFSET_ITEM_INFO_NAME                                0x00          // STRING PCHAR     // name is just the first thing in the sub info
#define EQ_OFFSET_ITEM_INFO_COUNT                               0x00          // DWORD

#define EQ_OFFSET_ITEM_SUB_INFO_ID                              0x00          // DWORD
#define EQ_OFFSET_ITEM_SUB_INFO_ICON                            0x00          // DWORD
#define EQ_OFFSET_ITEM_SUB_INFO_IS_NOT_NO_DROP                  0x00          // BYTE
#define EQ_OFFSET_ITEM_SUB_INFO_IS_LORE                         0x00          // DWORD
#define EQ_OFFSET_ITEM_SUB_INFO_SLOTS                           0x000         // BYTE

#define EQ_OFFSET_CXWndManager_FONT_MANAGER                     0x00          // DWORD POINTER

#define EQ_OFFSET_FONT_MANAGER_FONT_INFO_1                      0x00          // DWORD POINTER
#define EQ_OFFSET_FONT_MANAGER_FONT_INFO_2                      0x00          // DWORD POINTER

#define EQ_OFFSET_FONT_INFO_SIZE                                0x00          // DWORD

#define EQ_OFFSET_0x00B112C0_POINTER_2                          0x00          // DWORD POINTER
#define EQ_OFFSET_0x00B112C0_POINTER_2_ZONE_ACTOR_INFO_FIRST    0x00          // DWORD POINTER

#define EQ_OFFSET_ZONE_ACTOR_INFO_NEXT                          0x00          // DWORD POINTER
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x0C                          0x00          // DWORD    // if value == 2 then skip it
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x14                          0x00          // DWORD POINTER
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x14_0x18                     0x00          // DWORD POINTER
#define EQ_OFFSET_ZONE_ACTOR_INFO_NAME_0x14_0x18_0x08           0x00          // PCHAR
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x1C                          0x00          // DWORD    // 1 = object, 3 = player or NPC
#define EQ_OFFSET_ZONE_ACTOR_INFO_ACTOR_SUB_INFO                0x00          // DWORD POINTER
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x2C                          0x00          // BYTE    // is dynamic model (player, npc, door, tradeskill container, animated torches)
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x2D                          0x00          // BYTE    // is static model (not moving object)
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x2E                          0x00          // BYTE
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x2F                          0x00          // BYTE
#define EQ_OFFSET_ZONE_ACTOR_INFO_Y                             0x00          // FLOAT
#define EQ_OFFSET_ZONE_ACTOR_INFO_X                             0x00          // FLOAT
#define EQ_OFFSET_ZONE_ACTOR_INFO_Z                             0x00          // FLOAT
#define EQ_OFFSET_ZONE_ACTOR_INFO_ROTATION                      0x00          // FLOAT    // 0-512 degrees
#define EQ_OFFSET_ZONE_ACTOR_INFO_SCALE                         0x00          // FLOAT    // 0.0 to 0.1
#define EQ_OFFSET_ZONE_ACTOR_INFO_0x54                          0x00          // DWORD or FLOAT or BYTE[4]

#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_NAME                      0x00          // PCHAR    // offset is negative
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Y1                        0x00          // FLOAT
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_X1                        0x00          // FLOAT
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Z1                        0x00          // FLOAT
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_THIS                      0x00          // DWORD POINTER    // points to address of this zone actor sub info structure
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_SPAWN_INFO                0x00          // DWORD POINTER
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Y2                        0x00          // FLOAT    // collision or hitbox
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_X2                        0x00          // FLOAT    // collision or hitbox
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Z2                        0x00          // FLOAT    // collision or hitbox
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Y3                        0x000         // FLOAT
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_X3                        0x000         // FLOAT
#define EQ_OFFSET_ZONE_ACTOR_SUB_INFO_Z3                        0x000         // FLOAT

