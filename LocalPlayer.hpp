#pragma once

struct LocalPlayer {
    long BasePointer;
    int Team;
    Vector3D LocalOrigin;
    Vector2D ViewAngles;
    float ViewYaw;

    void Read() {
        BasePointer = Memory::Read<uint64_t>(OFF_REGION + OFF_LOCAL_PLAYER);
        if (BasePointer == 0) return;
        Team = Memory::Read<int>(BasePointer + OFF_TEAM_NUMBER);
        LocalOrigin = Memory::Read<Vector3D>(BasePointer + OFF_LOCAL_ORIGIN);
        ViewAngles = Memory::Read<Vector2D>(BasePointer + OFF_VIEW_ANGLES);
    }

    bool IsValid() {
        return BasePointer != 0;
    }
    
};