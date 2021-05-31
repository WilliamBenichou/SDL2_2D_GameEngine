#include "AEntityObject.h"

AEntityObject::AEntityObject()
{
	GameEnv::getInstance()->registerGameEntity(this);
}

AEntityObject::~AEntityObject()
{
}