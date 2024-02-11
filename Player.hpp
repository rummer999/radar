#pragma once

struct Player {
    LocalPlayer* Myself;
    int Index;
    long BasePointer;
    std::string Name;
    int Team;
    Vector3D LocalOrigin;
    bool IsLocal;
    bool friendly;
    bool enemy;
    float DistanceToLocalPlayer;
    float Distance2DToLocalPlayer;

    Player(int PlayerIndex, LocalPlayer* Me) {
        this->Index = PlayerIndex;
        this->Myself = Me;
    }

    void Read() {
        BasePointer = Memory::Read<uint64_t>(OFF_REGION + OFF_ENTITY_LIST + ((Index + 1) << 5));
        if (BasePointer == 0) return;
        Name = Memory::ReadString(BasePointer + OFF_NAME);
        Team = Memory::Read<int>(BasePointer + OFF_TEAM_NUMBER);
        LocalOrigin = Memory::Read<Vector3D>(BasePointer + OFF_LOCAL_ORIGIN);

        if (Myself->IsValid()) {
            IsLocal = Myself->BasePointer == BasePointer;
            enemy = !friendly;
            DistanceToLocalPlayer = Myself->LocalOrigin.Distance(LocalOrigin);
            Distance2DToLocalPlayer = Myself->LocalOrigin.To2D().Distance(LocalOrigin.To2D());

        }
        
    }
   
    bool IsValid() {
        return BasePointer != 0 && (IsPlayer() || IsDummy());
    }

    bool IsCombatReady() {
        if (!IsValid())return false;
       if (IsDummy()) return true;
        return true;
    }
    bool IsPlayer() {
        return Name == "player";
    }
    bool IsDummy() {
        return Team == 97;
    }

};

