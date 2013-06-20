#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    debug = true;

    ofSetWindowTitle("CLOUD BETA");
    //ofHideCursor();
    ofBackground(255,255,255);
    ofSetFrameRate(FRAMERATE);

    title = "CLOUD BETA\n";
    colors = "Position and speed of particles has influence on the color gradient.\n";
    keys = "Use number keys 0-9 to reset upper bound of each particle's speed.\n";
    mouse = "Left clicking causes attraction; right clicking causes repulsion.\n";
    noise = "Hit 'n' to toggle noise - although it looks more life-like with it on. =D\n";

    particles.assign(NUM_OF_PARTICLES,Particle());
    for (int i=0; i<particles.size(); i++){
        particles[i].getGraphic().fill();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i=0; i<particles.size(); i++){
        particles[i].update();
    }
    if (debug){
        particles[0].printInfo();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();
    for (int i=0; i<particles.size(); i++){
        particles[i].draw();
    }
    ofDisableAlphaBlending();
    ofSetColor(0,0,0);
    ofDrawBitmapString(title+colors+keys+mouse+noise,5,15);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    float speed;
    bool num = false;
    switch (key){
        case '0':
            speed = 0;
            num = true;
            break;
        case '1':
            speed = (1.0/9)*MAX_SPEED;
            num = true;
            break;
        case '2':
            speed = (2.0/9)*MAX_SPEED;
            num = true;
            break;
        case '3':
            speed = (3.0/9)*MAX_SPEED;
            num = true;
            break;
        case '4':
            speed = (4.0/9)*MAX_SPEED;
            num = true;
            break;
        case '5':
            speed = (5.0/9)*MAX_SPEED;
            num = true;
            break;
        case '6':
            speed = (6.0/9)*MAX_SPEED;
            num = true;
            break;
        case '7':
            speed = (7.0/9)*MAX_SPEED;
            num = true;
            break;
        case '8':
            speed = (8.0/9)*MAX_SPEED;
            num = true;
            break;
        case '9':
            speed = (9.0/9)*MAX_SPEED;
            num = true;
            break;
        case 'n':
            for (int i=0; i<particles.size(); i++){
                particles[i].setNoise(!particles[i].getNoise());
            }
    }
    if (num){
        for (int i=0; i<particles.size(); i++){
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
    //cout << button << endl;
    if (button == 0){
        for (int i=0; i<particles.size(); i++){
            particles[i].setAttract(true);
        }
    }
    else if (button == 2){
        for (int i=0; i<particles.size(); i++){
            particles[i].setRepel(true);
        }
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if (button == 0){
        for (int i=0; i<particles.size(); i++){
            particles[i].setAttract(false);
        }
    }
    else if (button == 2){
        for (int i=0; i<particles.size(); i++){
            particles[i].setRepel(false);
        }
    }
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    for (int i=0; i<particles.size(); i++){
        particles[i].reset();
    }
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
