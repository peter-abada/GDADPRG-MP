#pragma once
#include "AGameObject.h"

class APoolable : public AGameObject
{
public:
	APoolable(std::string name);
	virtual void initialize() = 0;
	virtual void onRelease() = 0;
	virtual void onActivate() = 0;
	virtual APoolable* clone() = 0;
};

