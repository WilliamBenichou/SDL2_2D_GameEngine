#pragma once
#include <string>
#include "GameEnv.h"
class AEntityObject
{
private:
	AEntityObject();
	~AEntityObject();
protected:
	virtual static void create();
};
