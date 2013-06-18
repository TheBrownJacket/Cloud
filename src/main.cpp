#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main(){
    ofAppGlutWindow window;
    ofSetupOpenGL(&window, 800,600, OF_FULLSCREEN);// can be OF_WINDOW, OF_FULLSCREEN, or OF_GAME_MODE
    ofRunApp( new testApp());
}
