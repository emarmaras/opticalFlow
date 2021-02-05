#pragma once

#include "ofMain.h"
#include "GamePlay.hpp"
#include "ofxCv.h"

using namespace ofxCv;

class ofApp : public ofBaseApp{
    
    public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
        
		ofVec2f onePole(ofVec2f current, ofVec2f prev);
		void movePlayerUsingFlow();

        ofVideoGrabber cam;
        FlowFarneback fb;
    
        GamePlay game;

		ofVec2f avgFlow;
		ofVec2f smoothAvgFlow;

};
