#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Application {
public:
	Application() = default;
	~Application();

	void Run();

private:
	bool Init();
	void Shutdown();

private:
	SDL_Window* mWindow = nullptr;
	SDL_Renderer* mRenderer = nullptr;

	SDL_Texture* mImage = nullptr;

	bool mIsRunning = true;
};
