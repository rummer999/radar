#pragma once

typedef uint8_t BYTE;

struct Level {
	std::string uName;
	bool IsPlayable;
	bool IsFiringRange;

	void Read() {
		uName = Memory::ReadString(OFF_REGION + OFF_LEVEL);
		IsPlayable = !uName.empty() && uName != "mp_lobby";
		IsFiringRange = uName == "mp_rr_canyonlands_staging_mu1";
	}
};
