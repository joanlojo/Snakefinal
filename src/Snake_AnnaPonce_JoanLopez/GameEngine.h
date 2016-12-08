#pragma once
#pragma region GAME_SCENES
#include "MainMenu.h"
#include "ID.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "Renderer.h"
#include "TimeManager.h"

#pragma endregion TODO

//! Initializes game needs and controls the game loop
namespace GameEngine {
	//cargas todas las imagenes e sptrites
	void LoadMedia(void) {
		R.LoadTexture<ObjectID::S_00>("gfx/background.png");
		R.LoadTexture<ObjectID::S_01>("gfx/play.png");
		R.LoadTexture<ObjectID::S_02>("gfx/exit.png");
	}
	//Gestionas las scenes, ya sea añadiendolas o diciendo cual es la acutal
	void AddScenes(void) {
		SM.AddScene<MainMenu>(); //instanciando a Scene Manager añader una nueva escena
		SM.SetCurScene <MainMenu> ();

	}
	/**
	* Runs the game specifying the window's name and dimensions
	* @tparam screenWidth Determines the window's width
	* @tparam screenHeight Determines the window's height
	* @param name Determines the window's title
	*/
	template<int screenWidth, int screenHeight>
	void Run(std::string &&name) {
		Window::Instance(std::move(name), screenWidth, screenHeight); // Initialize window Singleton instance for the first time
		LoadMedia(); // Loads the resource assets
		AddScenes(); // Loads the scenes
		bool m_isRunning{ true }; // Decides if the game loop is running
		Scene *&m_curScene(SM.GetCurScene()); // Defines a reference to a pointer that points to the current scene pointer (mindblown)
		while (!IM.HasQuit() && m_isRunning) { // Checks while game's still playable
			TM.FPSBegin(); // Calculates the time difference for deltaTime and FPS limiting purposes
#pragma region GAME_UPDATE
			switch (m_curScene->GetState()) { // Check for the state of the screen
			case SceneState::RUNNING:	IM.Update(); m_curScene->Update(); break; // Updates the InputManager and the current scene
			case SceneState::EXIT:		m_isRunning = false; break; // Triggers an end of the game looping
			case SceneState::SLEEP: default:;
			}
#pragma endregion
#pragma region GAME_DRAW
			TM.FPSEnd([&]() { // Limits the FPS rendering with a lambda function as the parameter that draws the whole game
				if (m_curScene->CheckState<SceneState::RUNNING>()) { // If screen object exists and its state is running
					R.Clear();			// Clear the screen buffer
					m_curScene->Draw(); // Call the draw method of the scene
					R.Render();			// Update the screen buffer with all sprites that were pushed
				}});
#pragma endregion
		}
	}
}