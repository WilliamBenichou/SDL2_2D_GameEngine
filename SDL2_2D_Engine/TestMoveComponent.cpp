#include "TestMoveComponent.h"

const int MIN_X = 50;
const int MAX_X = 200;
const float DURATION_IN_SECONDS = 5.0f;

bool reverse = true;
float currTime = 0;

float lerp(float a, float b, float t) {
	return (b - a) * t + a;
}

void TestMoveComponent::on_manage()
{
	currTime += Time::delta_time();
	if (currTime >= DURATION_IN_SECONDS) {
		currTime = 0;
		reverse = !reverse;
	}
	float lerp_factor = currTime / DURATION_IN_SECONDS;
	if (reverse) {
		lerp_factor = 1 - lerp_factor;
	}

	auto pos = _parentGo->getPosition();
	pos.x = lerp(MIN_X, MAX_X, lerp_factor);
	_parentGo->setPosition(pos);
}