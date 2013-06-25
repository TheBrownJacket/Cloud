#pragma once

#include "ofMain.h"
#include "Particle.h"

#define NUM_OF_PARTICLES 250
#define FRAMERATE 60

class testApp : public ofBaseApp{
    public:
        bool debug;

        void setup();
        void update();
        void draw();

        vector <Particle> particles;

        string title;
        string colors;
        string keys;
        string mouse;
        string esc;
        string help;

        bool h;

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
