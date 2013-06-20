#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include <cmath>

#define MIN_SPEED 0.0
#define MAX_SPEED 10.0

#define MIN_FLOW 0.0
#define MAX_FLOW 2.0

#define MAX_ALPHA PI/2

#define MIN_RADIUS 1.0
#define MAX_RADIUS 5.0

class Particle{
    public:
        Particle();
        // Getters
        float getX();
        float getY();
        float getSpeed();
        float getAngle();
        float getRadius();
        float getOpaque();
        ofColor & getColor();
        ofxVectorGraphics & getGraphic();
        bool getAttract();
        bool getRepel();

        // Setters
        void setX(float x);
        void setY(float y);
        void setSpeed(float s);
        void setAngle(float a);
        void setRadius(float r);
        void setOpaque(float o);
        void setColor(int r, int g,  int b);
        void setAttract(bool a);
        void setRepel(bool r);

        // Other methods
        void update();
        void reset();
        void draw();
        void printInfo(); // for debugging

    protected:
        const static ofVec2f origin;
        const static ofVec2f xAxis;
        const static ofVec2f yAxis;

        float angle;
        float speed;
        float flow; // translational acceleration ;not used yet
        float alpha; // rotational acceleration ;not used yet

        ofVec2f position;
        ofVec2f velocity;
        ofVec2f acceleration;

        float radius;
        float opaque; // not used yet
        ofColor color;
        ofxVectorGraphics graphic;

        bool attract;
        bool repel;

    private:
};

#endif // PARTICLE_H
