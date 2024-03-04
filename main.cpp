#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

using namespace std;

int main(int argv, char* argc[]){

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow("Game",300,200,800,400,0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Surface* surface = SDL_LoadBMP("texture/pic.bmp");
    SDL_Surface* chr = IMG_Load("texture/chr.png");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Texture* entity = SDL_CreateTextureFromSurface(renderer, chr);


    bool running = true;

    while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT)running = false;


        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,tex,NULL,NULL);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(tex);
    SDL_DestroyTexture(entity);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);


return 0;
}
