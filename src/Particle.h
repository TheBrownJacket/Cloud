#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#include "ofxVectorGraphics.h"

#define MIN_SPEED 1
#define MAX_SPEED 5
#define MIN_RADIUS 1
#define MAX_RADIUS 10

class Particle{
    public:
        Particle(int x=ofRandom(ofGetWindowWidth()), int y=ofRandom(ofGetWindowHeight()),float dxdt=ofRandom(MIN_SPEED,MAX_SPEED),
                 float dydt=ofRandom(MIN_SPEED,MAX_SPEED), float r=ofRandom(MIN_RADIUS,MAX_RADIUS));
        //getters
        int getX();
        int getY();
        float getSpeed();
        float getAngle();
        float getRadius();
        int getAlpha();
        ofColor & getColor();
        ofxVectorGraphics & getGraphic();

        //setters
        void setX(int x);
        void setY(int y);
        void setSpeed(float s);
        void setAngle(float a);
        void setRadius(float r);
        void setAlpha(int a);
        void setColor(int r, int g,  int b);

        //other methods
        void update();
        void reset();
        void draw();
        void printInfo(); //for debugging

    protected:
        const static ofVec2f origin;
        const static ofVec2f xAxis;
        const static ofVec2f yAxis;

        ofPoint point;
        ofVec2f dir;
        ofVec2f accel;

        float radius;
        int alpha;
        ofColor color;
        ofxVectorGraphics graphic;

    private:
};

#endif // PARTICLE_H
