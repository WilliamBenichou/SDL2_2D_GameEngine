#include "Renderer.h"

void Renderer::on_added()
{
	Component::on_added();
	//std::cout << "Renderer started" << std::endl;
}

void Renderer::on_enable()
{
	Component::on_enable();
	//std::cout << "Renderer enabled" << std::endl;
}