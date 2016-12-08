#pragma once
#include "Scene.h"
#include "Sprites.h"

class MainMenu : public Scene
{
public:
	explicit MainMenu();
	~MainMenu() override;
	void OnEntry(void) override;
	void OnExit(void) override;
	void Update(void) override;
	void Draw(void) override;
private:
	Sprite background; 
	Sprite play;
	Sprite exit;

};