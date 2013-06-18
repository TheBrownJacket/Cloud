#pragma once

#include "ofMain.h"
#include "Particle.h"

#define NUM_OF_PARTICLES 200
#define FRAME_RATE 60

class testApp : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();

        Particle particles[NUM_OF_PARTICLES];

        void keyPressed  (int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

};
