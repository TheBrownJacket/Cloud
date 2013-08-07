#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#include "ofxVectorGraphics.h"
#include <cmath>

#define MIN_SPEED 0.0
#define MAX_SPEED 15.0

#define MIN_ALPHA PI/180
#define MAX_ALPHA PI/18

#define MIN_FLOW 0.1
#define MAX_FLOW 1.0

#define MIN_RADIUS 1.0
#define MAX_RADIUS 5.0

#define RADIUS_NOISE 1.0

#define BARRIER 500
#define ORBITAL_FACTOR 1 // testing this out

class Particle{
    public:
        Particle();

        // Getters
        float getX();
        float getY();
        float getAngle();
        float getSpeed();
        float getAlpha();
        float getFlow();
        float getRadius();
        ofColor & getColor();
        ofxVectorGraphics & getGraphic();
        bool getAttract();
        bool getRepel();
        bool getAlive();

        // Setters
        void setX(float x);
        void setY(float y);
        void setAngle(float a);
        void setSpeed(float s);
        void setAlpha(float a);
        void setFlow(float f);
        void setRadius(float r);
        void setColor(int r, int g,  int b);
        void setAttract(bool a);
        void setRepel(bool r);
        void setAlive(bool a);

        // Other methods
        void update();
        void reset();
        void draw();
        void printInfo(); // for debugging

    protected:
        float angle;
        float speed;
        float alpha; // rotational acceleration
        float flow; // translational acceleration

        float radius;
        ofColor color;

        ofVec2f position;
        ofVec2f velocity;
        ofxVectorGraphics graphic;

        bool attract;
        bool repel;
        bool alive;

    private:
};

#endif // PARTICLE_H
