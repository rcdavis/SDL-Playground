
#include "Application.h"

Application::~Application() {
	Shutdown();
}

void Application::Run() {
	if (!Init()) {
		Shutdown();
		return;
	}

	while (mIsRunning) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				mIsRunning = false;
			}
		}

		SDL_RenderClear(mRenderer);
		SDL_RenderTexture(mRenderer, mImage, nullptr, nullptr);
		SDL_RenderPresent(mRenderer);
	}

	Shutdown();
}

bool Application::Init() {
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}

	if (!SDL_CreateWindowAndRenderer("SDL3 Window", 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE, &mWindow, &mRenderer)) {
		SDL_Log("Could not create window and renderer: %s", SDL_GetError());
		return false;
	}

	mImage = IMG_LoadTexture(mRenderer, "assets/textures/MenuPointer.png");
	if (!mImage) {
		SDL_Log("Could not load image: %s", SDL_GetError());
		return false;
	}

	mIsRunning = true;

	return true;
}

void Application::Shutdown() {
	if (mImage) {
		SDL_DestroyTexture(mImage);
		mImage = nullptr;
	}

	if (mRenderer) {
		SDL_DestroyRenderer(mRenderer);
		mRenderer = nullptr;
	}

	if (mWindow) {
		SDL_DestroyWindow(mWindow);
		mWindow = nullptr;
	}

	SDL_Quit();

	mIsRunning = false;
}
