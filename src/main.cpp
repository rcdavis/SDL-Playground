
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int main(int argc, char **argv) {
	// Initialize SDL
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return SDL_APP_FAILURE;
	}

	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	if (!SDL_CreateWindowAndRenderer("SDL3 Window", 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE, &window, &renderer)) {
		SDL_Log("Could not create window and renderer: %s", SDL_GetError());
		SDL_Quit();
		return SDL_APP_FAILURE;
	}

	// Load an image
	SDL_Texture *image = IMG_LoadTexture(renderer, "assets/textures/MenuPointer.png");
	if (!image) {
		SDL_Log("Could not load image: %s", SDL_GetError());
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return SDL_APP_FAILURE;
	}

	bool running = true;
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
		}

		// Render the image
		SDL_RenderClear(renderer);
		SDL_RenderTexture(renderer, image, nullptr, nullptr);
		SDL_RenderPresent(renderer);
	}

	// Cleanup
	SDL_DestroyTexture(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return SDL_APP_SUCCESS;
}
