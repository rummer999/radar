//GameVersion=v3.0.52.26
    #pragma once
    //core
    constexpr long OFF_REGION = 0x140000000;                      //[Static]->Region
    constexpr long OFF_LEVEL = 0x16d7de0;                         //[Miscellaneous]->LevelName
    constexpr long OFF_LOCAL_PLAYER = 0x2162818;                  //[Miscellaneous]->LocalPlayer
    constexpr long OFF_ENTITY_LIST = 0x1db4118;                   //[Miscellaneous]->cl_entitylist
    constexpr long OFF_LOCAL_ORIGIN = 0x017c;                     //[DataMap.CBaseViewModel]->m_vecAbsOrigin
    constexpr long OFF_TEAM_NUMBER = 0x030c;                      //[RecvTable.DT_BaseEntity]->m_iTeamNum
    constexpr long OFF_NAME = 0x0449;                             //[RecvTable.DT_BaseEntity]->m_iName
    constexpr long OFF_VIEW_ANGLES = 0x24f4 - 0x14;               //[DataMap.C_Player]-> m_ammoPoolCapacity - 0x14
