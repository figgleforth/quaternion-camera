//
//  BPEngine.h
//  oGL
//
//  Created by Bojan Percevic on 11/30/12.
//  Copyright (c) 2012 Bojan Percevic. All rights reserved.
//

#ifndef __oGL__BPEngine__
#define __oGL__BPEngine__

#include <iostream>
#include <SDL2/SDL.h>

class BPEngine {
private:
    int _width;
    int _height;
    int _bpp;

    
public:

    
    ~BPEngine() {};
    BPEngine(int w, int h, int bpp) : _width(w), _height(h), _bpp(bpp) {};
        
    void init();
    
    // mutators
    int width();
    int height();
    
};



#endif /* defined(__oGL__BPEngine__) */
