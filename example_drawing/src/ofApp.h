#pragma once


#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxGoogleTrends.h"

class ofApp: public ofBaseApp
{
public:
    void setup();
    void draw();
    
    ofxGoogleTrends gt;
    const string keyword = "openFrameworks";
    
    // font
    ofTrueTypeFont font;
    float fontSize = 5.0;
};
