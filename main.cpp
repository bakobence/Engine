#include "source\App.h"

App* App::instance = nullptr;

int main()
{
	App* engine = App::getInstance();
	engine->run();
	return(0);
}