#include "GameEngine.h"

// Game constants
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char* args[]) {
	GameEngine::Run<SCREEN_WIDTH, SCREEN_HEIGHT>("Snake");
	return 0;
}