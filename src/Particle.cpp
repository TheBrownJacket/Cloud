#include "Particle.h"

// Reference objects
const ofVec2f Particle::origin = ofVec2f(0,0);
const ofVec2f Particle::xAxis = ofVec2f(1,0);
const ofVec2f Particle::yAxis = ofVec2f(0,1);

Particle::Particle() : // Using initializer list
    angle(ofRandomf()*PI), // Set to random angle from -PI to PI
    speed(ofRandom(MIN_SPEED,MAX_SPEED)), // Set to random speed within bounds
    flow(ofRandomf()*MAX_FLOW), // Set to variable tanslational acceleration
    alpha(ofRandomf()*MAX_ALPHA), // Set to variable rotational acceleration

    position(ofVec2f(ofRandom(0,ofGetWindowWidth()),ofRandom(0,ofGetWindowHeight()))), // Set to random position
    velocity(ofVec2f(cos(angle)*speed,sin(angle)*speed)), // Set to correct velocity
    acceleration(ofVec2f(0,0)), // For now, set to zero acceleration

    radius(ofRandom(MIN_RADIUS,MAX_RADIUS)), // Set to varible radius
    color(speed/MAX_SPEED*255,position.x/ofGetWindowWidth()*255,position.y/ofGetWindowHeight()*255), // Set to formulaic color

    attract(false), // Set to no attraction
    repel(false), // Set to no repulsion
    noise(true) // Set noise on to create "bug"-like movement
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
    return angle;
}
float Particle::getRadius(){
    return radius;
}
ofColor & Particle::getColor(){
    return color;
}
ofxVectorGraphics & Particle::getGraphic(){
    return graphic;
}
bool Particle::getAttract(){
    return attract;
}
bool Particle::getRepel(){
    return repel;
}
bool Particle::getNoise(){
    return noise;
}

// Setters
void Particle::setX(float x){
    position.x = ofClamp(x,0,ofGetWindowWidth());
}
void Particle::setY(float y){
    position.y = ofClamp(y,0,ofGetWindowHeight());
}
void Particle::setSpeed(float s){
    speed = ofClamp(s,MIN_SPEED,MAX_SPEED);
    velocity.x = cos(angle)*speed;
    velocity.y = sin(angle)*speed;
}
void Particle::setAngle(float a){
    while (a>PI){
        a -= 2*PI;
    }
    while (a<-PI){
        a += 2*PI;
    }
    angle = a;
    setSpeed(getSpeed());
}
void Particle::setRadius(float r){
    radius = ofClamp(r,MIN_RADIUS,MAX_RADIUS);
}
void Particle::setColor(int r, int g, int b){
    getColor().r = ofClamp(r,0,255);
    getColor().g = ofClamp(g,0,255);
    getColor().b = ofClamp(b,0,255);
}
void Particle::setAttract(bool a){
    attract = a;
}
void Particle::setRepel(bool r){
    repel = r;
}
void Particle::setNoise(bool n){
    noise = n;
}

// Other methods
void Particle::update(){
    // attraction and repulsion
    if (attract){
        float dy = ((float)ofGetWindowHeight()-ofGetMouseY())-getY();
        float dx = ofGetMouseX()-getX();
        if (dx>=0){
            setAngle(atan(dy/dx));
        }
        else {
            setAngle(atan(dy/dx)+PI);
        }
    }
    else if (repel){
        float dy = ((float)ofGetWindowHeight()-ofGetMouseY())-getY();
        float dx = ofGetMouseX()-getX();
        if (dx>=0){
            setAngle(atan(dy/dx)+PI);
        }
        else {
            setAngle(atan(dy/dx));
        }
    }
    // noise
    if (noise){
        setAngle(getAngle()+ofRandomf()*ANGLE_NOISE);
        setSpeed(getSpeed()+ofRandomf()*SPEED_NOISE);
        setRadius(getRadius()+ofRandomf()*RADIUS_NOISE);
    }
    // bounds
    if (getX()>=ofGetWindowWidth() || getX()<=0){
        setAngle(-getAngle()+PI);
    }
    if (getY()>=ofGetWindowHeight() || getY()<=0){
        setAngle(-getAngle());
    }
    // position + motion
    velocity += acceleration;
    position += velocity;
    // color
    float r = (getSpeed()/MAX_SPEED)*255;
    float g = (getY()/ofGetWindowHeight())*255;
    float b = (1-getY()/ofGetWindowHeight())*255;
    setColor(r,g,b);
}
void Particle::reset(){
    *this = Particle();
}
void Particle::draw(){
    graphic.setColor(getColor().r,getColor().g,getColor().b);
    graphic.circle(getX(),ofGetWindowHeight()-getY(),getRadius());
}
void Particle::printInfo(){
    if (ofGetFrameNum()%(int)ofGetFrameRate() == 0){
        cout << '(' << getX() << ',' << getY() << ')' << endl;
        cout << getSpeed() << "\t" << getAngle() << endl;
        cout << getRadius() << endl << endl;
    }
}


