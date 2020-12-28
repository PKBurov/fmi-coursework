#pragma once
#include <cstring>
#include <string>
#include "product.h"

class Watches : public Item {
public:

	Watches() {
	};
	~Watches() {
	};

	string GetWatchMaterial() const;
	string GetWatchGlass() const;
	string GetWatchMovement() const;
	string GetWatchWaterRess() const;
	

	void SetWatchMaterial(string Material);
	void SetWatchGlass( string Glass);
	void SetWatchMovement(string Movement);
	void SetWatchWaterRess(string Ress);

	Watches& operator=(const Watches& rhs);
	Watches(const Watches& rhs);

private:

	string WatchMaterial;
	string WatchGlass ;
	string WatchMovement ;
	string WatchWaterRess;
};