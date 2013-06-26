#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    debug = false;

    ofSetWindowTitle("CLOUD BETA");
    ofHideCursor();
    ofBackground(0,0,0);
    ofSetFrameRate(FRAMERATE);
    h = false;

    title = "Welcome to CLOUD BETA!\n";
    colors = "Position and speed of particles has influence on the color gradient.\n";
    keys = "Use number keys 0-9 to reset each particle's speed.\n";
    mouse = "Holding left click causes attraction.\nRight click causes repulsion.\nBoth together casts a calm spell.\n";
    esc = "Hit 'r' to reset. Hit 'Esc' to exit.\n";
    help = "Hit 'h' to bring up info on controls.\n";

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
        cout << ofGetFrameRate() << endl;
        particles[0].printInfo();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i=0; i<particles.size(); i++){
        particles[i].draw();
        if(debug){
            ofDrawBitmapString(ofToString(i),particles[i].getX(),ofGetWindowHeight()-particles[i].getY());
        }
    }
    ofSetColor(255,255,255);
    ofDrawBitmapString(title,5,15);
    if (h){
        ofDrawBitmapString(colors+keys+mouse+esc,5,ofGetWindowHeight()-75);
    }
    else {
        ofDrawBitmapString(help,5,ofGetWindowHeight()-5);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    float speed;
    bool num = false;
    float diff = MAX_SPEED-MIN_SPEED;
    switch (key){
        case '0':
            speed = MIN_SPEED;
            num = true;
            break;
        case '1':
            speed = (1.0/9)*diff+MIN_SPEED;
            num = true;
            break;
        case '2':
            speed = (2.0/9)*diff+MIN_SPEED;
            num = true;
            break;
        case '3':
            speed = (3.0/9)*diff+MIN_SPEED;
            num = true;
            break;
        case '4':
            speed = (4.0/9)*diff+MIN_SPEED;
            num = true;
            break;
        case '5':
            speed = (5.0/9)*diff+MIN_SPEED;
            num = true;
            break;
        case '6':
            speed = (6.0/9)*diff+MIN_SPEED;
            num = true;
            break;
        case '7':
            speed = (7.0/9)*diff+MIN_SPEED;
            num = true;
            break;
        case '8':
            speed = (8.0/9)*diff+MIN_SPEED;
            num = true;
            break;
        case '9':
            speed = MAX_SPEED;
            num = true;
            break;
        case 'r':
            for (int i=0; i<particles.size(); i++){
                particles[i].reset();
            }
            break;
        case 'h':
            h = !h;
    }
    if (num){
        for (int i=0; i<particles.size(); i++){
            particles[i].setSpeed(speed);
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
    if (button == 0 || button == 1){
        for (int i=0; i<particles.size(); i++){
            particles[i].setAttract(true);
        }
    }
    else if (button == 2 || button == 1){
        for (int i=0; i<particles.size(); i++){
            particles[i].setRepel(true);
        }
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if (button == 0 || button == 1){
        for (int i=0; i<particles.size(); i++){
            particles[i].setAttract(false);
        }
    }
    else if (button == 2 || button == 1){
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
