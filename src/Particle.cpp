#include "Particle.h"

// Reference objects
const ofVec2f Particle::origin = ofVec2f(0,0);
const ofVec2f Particle::xAxis = ofVec2f(1,0);
const ofVec2f Particle::yAxis = ofVec2f(0,1);

Particle::Particle() : // Using initializer list
    angle(ofRandomf()*PI), // Set to random angle from -PI to PI
    speed(ofRandom(MIN_SPEED,MAX_SPEED)), // Set to random speed within bounds
    flow(0), // For now, set to zero
    alpha(0), // For now, set to zero

    position(ofVec2f(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()))), // Set to random position
    velocity(ofVec2f(cos(angle)*speed,sin(angle)*speed)), // Set to correct velocity
    acceleration(ofVec2f(0,0)), // For now, set to zero acceleration

    radius(ofRandom(MIN_RADIUS,MAX_RADIUS)), // Set to varible radius
    opaque(255) // For now, set to full visibilty
{

}

// Getters
float Particle::getX(){
    return position.x;
}
float Particle::getY(){
    return position.y;
}
float Particle::getSpeed(){
    return speed;
}
float Particle::getAngle(){
    while (angle>PI){
        angle -= 2*PI;
    }
    while (angle<-PI){
        angle += 2*PI;
    }
    return angle;
}
float Particle::getRadius(){
    return radius;
}
float Particle::getOpaque(){
    return opaque;
}
ofColor & Particle::getColor(){
    return color;
}
ofxVectorGraphics & Particle::getGraphic(){
    return graphic;
}

// Setters
void Particle::setX(float x){
    position.x = x;
}
void Particle::setY(float y){
    position.y = y;
}
void Particle::setSpeed(float s){
    speed = ofClamp(s,0,MAX_SPEED);
    velocity.x = cos(angle)*speed;
    velocity.y = sin(angle)*speed;
}
void Particle::setAngle(float a){
    angle = a;
    setSpeed(getSpeed());
}
void Particle::setRadius(float r){
    radius = ofClamp(r,MIN_RADIUS,MAX_RADIUS);
}
void Particle::setOpaque(float o){
    opaque = ofClamp(o,0,255);
}
void Particle::setColor(int r, int g, int b){ // Currently irrelevant
    getColor().r = ofClamp(r,0,255);
    getColor().g = ofClamp(g,0,255);
    getColor().b = ofClamp(b,0,255);
}

// Other methods
void Particle::update(){
    // position + motion
    if (getX()>=ofGetWindowWidth() || getX()<=0){
        setAngle(-getAngle()+PI);
    }
    if (getY()>=ofGetWindowHeight() || getY()<=0){
        setAngle(-getAngle());
    }
    velocity += acceleration;
    position += velocity;
    // color
    float r = (getY()/ofGetWindowHeight()+getY()/ofGetWindowHeight())/2*255;
    float g = (float)ofGetMouseX()/ofGetWindowWidth()*255;
    float b = (float)ofGetMouseY()/ofGetWindowHeight()*255;
    setColor(r,g,b);
}
void Particle::reset(){
    *this = Particle();
}
void Particle::draw(){
    graphic.setColor(getColor().r,getColor().g,getColor().b);
    graphic.circle(getX(),getY(),getRadius());
}
void Particle::printInfo(){
    if (ofGetFrameNum()%(int)ofGetFrameRate() == 0){
        cout << '(' + ofToString(getX()) + ',' + ofToString(getY()) + ')' << endl;
        cout << getSpeed() << endl;
        cout << endl;
    }
}


