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

    SDL_FreeSurface(surface);

    int frame = 0,state = 1;
    Uint32 lastTime = SDL_GetTicks();
    Uint32 frameTime = 100;

    bool running = true,action = false;

    while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT)running = false;

            if(e.type == SDL_MOUSEBUTTONDOWN){
                if(e.button.button == SDL_BUTTON_LEFT){
                    frame = 0;
                    state = 5;
                    action = true;
                    lastTime = SDL_GetTicks();
                }
            }
        }

        if(action){
          Uint32 currentTime = SDL_GetTicks();
            if(currentTime - lastTime >= frameTime){
                frame++;
                lastTime = currentTime;
                if(frame >= 5){
                    frame = 0;
                    state = 1;
                    action = false;
                }
            }
        }

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,tex,NULL,NULL);


        SDL_Rect src = {frame * 48,state * 48,48,48};
        SDL_Rect dst = {50,175,48*4,48*4};
        SDL_RenderCopy(renderer,entity,&src,&dst);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(tex);
    SDL_DestroyTexture(entity);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);


return 0;
}
