
#include "Asteroid.hpp"

Asteroid::Asteroid() {
    // random size, position, speed and colour
    a.set(ofRandom(1, 10));
    pos = ofVec3f(ofRandom(-ofGetWidth()*.2, ofGetWidth()*.2), -20, ofRandom(-2000, -10000));
    color = ofColor(ofRandom(0, 255), ofRandom(0, 255), ofRandom(0, 255));
    speed = ofRandom(1, 20);
    wiggleAmount = ofRandom(5);
    wiggleSpeed = ofRandom(0.01);
}

void Asteroid::draw() {
    ofSetColor(color);
    a.draw();
}

void Asteroid::update(ofBoxPrimitive player) {
    ofVec3f playerPos = player.getPosition();
    float playerSize = player.getSize().x;
    
    // reset asteroid position once it is off screen
    if(pos.z > 0) respawn();
    
    // move asteroid towards player
    pos.z += speed;
    
    // wiggle asteroid
    pos.x += ofMap(ofNoise(ofGetElapsedTimeMillis() * wiggleSpeed), 0, 1, -wiggleAmount, wiggleAmount);
    
    a.setPosition(pos);
}

void Asteroid::respawn() {
    // position asteroid way in the distance
    pos.z = ofRandom(-8000, -10000);
}

bool Asteroid::collision(ofBoxPrimitive player) {
    ofVec3f playerPos = player.getPosition();
    float playerSize = player.getSize().x;
    
    if(pos.z > playerPos.z && pos.x < playerPos.x + playerSize && pos.x > playerPos.x - playerSize)
        return true;

	return false;
}
