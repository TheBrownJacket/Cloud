#include "Particle.h"

//Reference objects
const ofVec2f Particle::origin = ofVec2f(0,0);
const ofVec2f Particle::xAxis = ofVec2f(1,0);
const ofVec2f Particle::yAxis = ofVec2f(0,1);

Particle::Particle(int x, int y, float dxdt, float dydt, float r) :
    point(ofPoint(ofClamp(x,r,ofGetWindowWidth()-r),ofClamp(y,r,ofGetWindowHeight()-r))),
    dir(ofVec2f(dxdt,dydt)), radius(r), color(ofColor(ofRandom(255),ofRandom(255),ofRandom(255)))
{

}

//Getters
int Particle::getX(){
    return point.x;
}
int Particle::getY(){
    return point.y;
}
float Particle::getSpeed(){
    return dir.distance(origin);
}
float Particle::getAngle(){
    return dir.angleRad(xAxis);
}
float Particle::getRadius(){
    return radius;
}
int Particle::getAlpha(){
    return alpha;
}
ofColor & Particle::getColor(){
    return color;
}
ofxVectorGraphics & Particle::getGraphic(){
    return graphic;
}

//Setters
void Particle::setX(int x){
    point.x = x;
}
void Particle::setY(int y){
    point.y = y;
}
void Particle::setSpeed(float s){
    s = ofClamp(s,MIN_SPEED,MAX_SPEED); // in progress
}
void Particle::setAngle(float a){

}
void Particle::setRadius(float r){
    radius = ofClamp(r,MIN_RADIUS,MAX_RADIUS);
}
void Particle::setAlpha(int a){
    alpha = ofClamp(a,0,255);
}
void Particle::setColor(int r, int g, int b){
    getColor().r = ofClamp(r,0,255);
    getColor().g = ofClamp(g,0,255);
    getColor().b = ofClamp(b,0,255);
}

//Other methods
void Particle::update(){
    //position + motion
    point += dir;
    if (getX()>=ofGetWindowWidth()-getRadius() || getX()<=getRadius())
    {
        dir.x = -dir.x;
    }
    if (getY()>=ofGetWindowHeight()-getRadius() || getY()<=getRadius())
    {
        dir.y = -dir.y;
    }
    //color
    int r = ((float)getY()/ofGetWindowHeight()+((float)getY()/ofGetWindowHeight()))/2*255;
    int g = (float)ofGetMouseX()/ofGetWindowWidth()*255;
    int b = (float)ofGetMouseY()/ofGetWindowHeight()*255;
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
    cout << ofToString(getX()) + ',' + ofToString(getY()) << endl;
}


