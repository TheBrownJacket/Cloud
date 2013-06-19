#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    debug = true;

    ofSetWindowTitle("CLOUD Beta");
    //ofHideCursor();
    ofBackground(255,255,255);
    ofSetFrameRate(FRAMERATE);
    for (int i=0; i<sizeof(particles)/sizeof(particles[0]); i++){
        particles[i].getGraphic().fill();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i=0; i<sizeof(particles)/sizeof(particles[0]); i++){
        particles[i].update();
    }
    if (debug){

        particles[3].printInfo();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i=0; i<sizeof(particles)/sizeof(particles[0]); i++){
        particles[i].draw();
    }
    ofSetColor(0,0,0);
    string keys = "Use number keys to set upper bound of the max speed for each particle. Key 0 sets upper to 10.\n";
    string colors = "Position of mouse has influence on the color gradient of particles.";
    ofDrawBitmapString(keys + colors,0,10);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    float speed;
    switch (key){
        case '1':
            speed = 1;
            break;
        case '2':
            speed = 2;
            break;
        case '3':
            speed = 3;
            break;
        case '4':
            speed = 4;
            break;
        case '5':
            speed = 5;
            break;
        case '6':
            speed = 6;
            break;
        case '7':
            speed = 7;
            break;
        case '8':
            speed = 8;
            break;
        case '9':
            speed = 9;
            break;
        case '0':
            speed = 10;
            break;
    }
    for (int i=0; i<sizeof(particles)/sizeof(particles[0]); i++){
        particles[i].setSpeed(ofRandom(MIN_SPEED,speed));
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    for (int i=0; i<sizeof(particles)/sizeof(particles[0]); i++){
        particles[i].reset();
    }
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
