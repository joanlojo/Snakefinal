#include "MainMenu.h"
#include "ID.h"
#include "InputManager.h"
#include "Logger.h"
#include "SceneManager.h"
using namespace Logger;


MainMenu::MainMenu() {
	play = { { 450,250,W.GetWidth() / 6, W.GetHeight() / 6 }, ObjectID:: S_01 };
	exit = { { 450,550,W.GetWidth() / 6, W.GetHeight() / 6 }, ObjectID:: S_02 };
	background = { { 0, 0, W.GetWidth(), W.GetHeight() }, ObjectID:: S_00}; //defines el background de la escena, instanciando a window para el tamaño y con la clase ID dices q el tipo es background

}
MainMenu::~MainMenu() {
}
void MainMenu::OnEntry(void) {
}
void MainMenu::OnExit(void) {
}
void MainMenu::Update(void) {
	static MouseCoords mouseCoords(0, 0);
	if (IM.IsMouseDown<MOUSE_BUTTON_LEFT>()) {
		mouseCoords = IM.GetMouseCoords();

		if ((mouseCoords.x >= 460 && mouseCoords.x <= 606) && (mouseCoords.y >= 260 && mouseCoords.y <= 360)) {
			printf("play");
			//SM.SetCurScene<GameScene>(); ESCENA DEL DIFICULTADES
		}
		else if ((mouseCoords.x >= 455 && mouseCoords.x <= 616) && (mouseCoords.y >= 555 && mouseCoords.y <= 670)) {
			printf("exit");
			SetState<SceneState::EXIT>();
		}
	}

}
void MainMenu::Draw(void) {
	background.Draw();
	play.Draw();
	exit.Draw();

}