#include "Particle.h"

Particle::Particle() : // Using initializer list
    angle(ofRandomf()*PI), // Set to random angle from -PI to PI
    speed(ofRandom(MIN_SPEED,MAX_SPEED)), // Set to random speed within bounds
    alpha(ofRandom(MIN_ALPHA,MAX_ALPHA)), // Set to random rotational acceleration
    flow(ofRandom(MIN_FLOW,MAX_FLOW)), // Set to random translational acceleration

    radius(ofRandom(MIN_RADIUS,MAX_RADIUS)), // Set to varible radius
    color(speed/MAX_SPEED*255,position.x/ofGetWindowWidth()*255,position.y/ofGetWindowHeight()*255), // Set color

    position(ofVec2f(ofRandom(radius,ofGetWindowWidth()-radius),ofRandom(radius,ofGetWindowHeight()-radius))), // Set to random position
    velocity(ofVec2f(cos(angle)*speed,sin(angle)*speed)), // Set to correct velocity

    attract(false), // Set to no attraction
    repel(false), // Set to no repulsion
    alive(true) // Set true to create bug-like movement
{

}

// Getters
float Particle::getX(){
    return position.x;
}
float Particle::getY(){
    return position.y;
}
float Particle::getAngle(){
    return angle;
}
float Particle::getSpeed(){
    return speed;
}
float Particle::getAlpha(){
    return alpha;
}
float Particle::getFlow(){
    return flow;
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
bool Particle::getAlive(){
    return alive;
}

// Setters
void Particle::setX(float x){
    position.x = ofClamp(x,getRadius(),ofGetWindowWidth()-getRadius());
}
void Particle::setY(float y){
    position.y = ofClamp(y,getRadius(),ofGetWindowHeight()-getRadius());
}
void Particle::setAngle(float a){
    while (a>PI){
        a-=2*PI;
    }
    while (a<-PI){
        a+=2*PI;
    }
    angle = a;
    setSpeed(getSpeed());
}
void Particle::setSpeed(float s){
    speed = ofClamp(s,MIN_SPEED,MAX_SPEED);
    velocity.x = cos(angle)*speed;
    velocity.y = sin(angle)*speed;
}
void Particle::setAlpha(float a){
    alpha = ofClamp(a,MIN_ALPHA,MAX_ALPHA);
}
void Particle::setFlow(float f){
    flow = ofClamp(f,MIN_FLOW,MAX_FLOW);
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
void Particle::setAlive(bool a){
    alive = a;
}

// Other methods
void Particle::update(){ // main method that controls all necessary movement
    // attraction and repulsion
    float dy = (ofGetWindowHeight()-ofGetMouseY())-getY();
    float dx = ofGetMouseX()-getX();
    if (getAttract() && !getRepel()){
        float desired = atan2(dy,dx);
        float angdiff = desired-getAngle();
        if ((angdiff>0 && abs(angdiff)<=PI) || (angdiff<0 && abs(angdiff)>PI)){
            setAngle(getAngle()+getAlpha());
        }
        else if ((angdiff>0 && abs(angdiff)>PI) || (angdiff<0 && abs(angdiff)<=PI)){
            setAngle(getAngle()-getAlpha());
        }
//        if (desired+getAlpha()>=getAngle() && desired-getAlpha()<=getAngle()){
//            setSpeed(getSpeed()+getFlow());
//        }
//        else {
//            setSpeed(getSpeed()-getFlow());
//        }
    }
    else if (getRepel() && !getAttract() && sqrt(pow(dy,2)+pow(dx,2))<=BARRIER){
        float desired = atan2(dy,dx)>0 ? atan2(dy,dx)-PI : atan2(dy,dx)+PI;
        float angdiff = desired-getAngle();
        if ((angdiff>0 && abs(angdiff)<=PI) || (angdiff<0 && abs(angdiff)>PI)){
            setAngle(getAngle()+getAlpha());
        }
        else if ((angdiff>0 && abs(angdiff)>PI) || (angdiff<0 && abs(angdiff)<=PI)){
            setAngle(getAngle()-getAlpha());
        }
//        if (desired+getAlpha()>getAngle() && desired-getAlpha()<getAngle()){
//            setSpeed(getSpeed()+getFlow());
//        }
//        else {
//            setSpeed(getSpeed()-getFlow());
//        }
    }
    else if (getAttract() && getRepel()){
        if (getSpeed()>0){
         setSpeed(getSpeed()-getFlow());
        }
    }
    // life
    if (getAlive()){
        setAngle(getAngle()+ofRandomf()*getAlpha());
        setSpeed(getSpeed()+ofRandomf()*getFlow());
        setRadius(getRadius()+ofRandomf()*RADIUS_NOISE);
    }
    // bounds
    if (getX()>ofGetWindowWidth()-getRadius() || getX()<getRadius()){
        setAngle(-getAngle()+PI);
    }
    if (getY()>ofGetWindowHeight()-getRadius() || getY()<getRadius()){
        setAngle(-getAngle());
    }
    // position + motion
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
        cout << getFlow() << "\t" << getAlpha() << endl << endl;
    }
}


