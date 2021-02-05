#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(10);
    ofEnableDepthTest();
    
    cam.setup(320, 240);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    
    // send camera to optical flow algorithm
    if(cam.isFrameNew())
        fb.calcOpticalFlow(cam);

	avgFlow = fb.getAverageFlow();
	smoothAvgFlow = onePole(smoothAvgFlow, avgFlow);

	cout << smoothAvgFlow << endl;

	movePlayerUsingFlow();


}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(255);
    ofSetLineWidth(1);
    
    ofPushMatrix();
        // draw camera feed in top right corner
        ofTranslate(ofGetWidth()-cam.getWidth(), 0);
       fb.draw(0,0);
       cam.draw(0,0);
    ofPopMatrix();
  
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//ofDrawLine(0, 0, avgFlow.x * 100, avgFlow.y * 100);
	ofDrawLine(0, 0, smoothAvgFlow.x * 100, smoothAvgFlow.y * 100);

    game.run();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_LEFT)  game.move(-2);
    if(key == OF_KEY_RIGHT) game.move(2);

}

//--------------------------------------------------------------

void ofApp::movePlayerUsingFlow() {
	float speed = 0.9;
	float threshold = 0.1;

	if (smoothAvgFlow.x < -threshold) 
	{
		game.move(-speed);
	}
	else if (smoothAvgFlow.x > threshold)
	{
		game.move(speed);
	}
}

//--------------------------------------------------------------

ofVec2f ofApp::onePole(ofVec2f current, ofVec2f prev) {

	//coefficient
	float a = 0.9;

	return prev + a * (current - prev);

}