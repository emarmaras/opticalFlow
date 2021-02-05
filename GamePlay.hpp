
#pragma once

#include "ofMain.h"
#include "Asteroid.hpp"

#include <vector>

class GamePlay {
    
    public:
        GamePlay();
    
        void run();
        void playing();
        void gameOver();
        void addAsteroids(int num);
    
        void borders();
        void move(float amount);
    
        ofBoxPrimitive player;
        ofCamera camera;
        vector<Asteroid> asteroids;
    
        int score, finalScore, state;
};
