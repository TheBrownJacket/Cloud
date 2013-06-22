#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main(){
    ofAppGlutWindow window;
    ofSetupOpenGL(&window,853,480,OF_FULLSCREEN); // Can be OF_WINDOW, OF_FULLSCREEN, or OF_GAME_MODE
    ofRunApp(new testApp());
}
