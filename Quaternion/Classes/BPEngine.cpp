//
//  BPEngine.cpp
//  oGL
//
//  Created by Bojan Percevic on 11/30/12.
//  Copyright (c) 2012 Bojan Percevic. All rights reserved.
//

#include "BPEngine.h"

void BPEngine::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
//    SDL_SetVideoMode(_width, _height, _bpp, SDL_HWSURFACE | SDL_OPENGL);
    
    SDL_Window *sdlWindow;
    SDL_Renderer *sdlRenderer;
    SDL_CreateWindowAndRenderer(_width, _height, SDL_WINDOW_FULLSCREEN_DESKTOP, &sdlWindow, &sdlRenderer);

}

// mutators
int BPEngine::width() { return _width; }
int BPEngine::height() { return _height; }




