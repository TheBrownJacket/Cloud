#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowTitle("CLOUD Beta");
    //ofHideCursor();
    ofBackground(255,255,255);
    ofSetFrameRate(FRAMERATE);
    for(int i=0; i<sizeof(particles)/sizeof(particles[0]); i++)    {
        particles[i].getGraphic().fill();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<sizeof(particles)/sizeof(particles[0]); i++)    {
        particles[i].update();
    }

    particles[0].printInfo(); // for debugging
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<sizeof(particles)/sizeof(particles[0]); i++)    {
        particles[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
    for(int i=0; i<sizeof(particles)/sizeof(particles[0]); i++){
        particles[i].reset();
    }
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
