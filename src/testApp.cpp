#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    debug = true;

    ofSetWindowTitle("CLOUD BETA");
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
        particles[0].printInfo();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i=0; i<sizeof(particles)/sizeof(particles[0]); i++){
        particles[i].draw();
    }
    ofSetColor(0,0,0);
    string title = "CLOUD BETA\n";
    string keys = "Use number keys to set upper bound of the max speed for each particle.\nKey 0 sets upper to maximum allowed speed.\n";
    string colors = "Position and speed of particles has influence on the color gradient.";
    ofDrawBitmapString(title + keys + colors,5,15);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    float speed = NULL;
    switch (key){
        case '1':
            speed = (1.0/10)*MAX_SPEED;
            break;
        case '2':
            speed = (2.0/10)*MAX_SPEED;
            break;
        case '3':
            speed = (3.0/10)*MAX_SPEED;
            break;
        case '4':
            speed = (4.0/10)*MAX_SPEED;
            break;
        case '5':
            speed = (5.0/10)*MAX_SPEED;
            break;
        case '6':
            speed = (6.0/10)*MAX_SPEED;
            break;
        case '7':
            speed = (7.0/10)*MAX_SPEED;
            break;
        case '8':
            speed = (8.0/10)*MAX_SPEED;
            break;
        case '9':
            speed = (9.0/10)*MAX_SPEED;
            break;
        case '0':
            speed = MAX_SPEED;
            break;
    }
    if (speed != NULL){
        for (int i=0; i<sizeof(particles)/sizeof(particles[0]); i++){
            particles[i].setSpeed(ofRandom(MIN_SPEED,speed));
        }
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
    cout << button << endl;
    if (button == 0){
        for (int i=0; i<sizeof(particles)/sizeof(particles[0]); i++){
            particles[i].setAttract(true);
        }
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if (button == 0){
        for (int i=0; i<sizeof(particles)/sizeof(particles[0]); i++){
            particles[i].setAttract(false);
        }
    }
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
