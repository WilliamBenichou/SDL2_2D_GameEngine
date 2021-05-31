#include "Time.h"

static std::chrono::time_point<std::chrono::steady_clock> s_prev_time;
static float s_deltaTime; //first frame, timer is considered 0.166f

Time::Time()
{
	s_prev_time = std::chrono::steady_clock::now();
	s_deltaTime = 0;
}

void Time::refresh() const
{
	const auto time = std::chrono::steady_clock::now();
	s_deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(time - s_prev_time).count() / 1000000.0f;
	s_prev_time = time;
	//std::cout << "Frame Duration: " << s_deltaTime << "ms (" << (1.0f / s_deltaTime) << "fps)" << std::endl;
}

float Time::curr_frame_duration() const
{
	const auto time = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::microseconds>(time - s_prev_time).count() / 1000000.0f;
}

float Time::delta_time()
{
	return s_deltaTime;
}