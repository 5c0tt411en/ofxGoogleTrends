#include "ofApp.h"


void ofApp::setup() {
    ofBackground(0);
    
    gt.setup(keyword);
    
    font.load("Futura", fontSize);
}


void ofApp::draw() {
    ofSetColor(255);
    ofDrawBitmapString("keyword: " + keyword, 20, 20);
    for (int i = 0; i < gt.dataLength; i++) {
        ofDrawCircle(i * 9 + 50, ofGetHeight() - 100 - gt.value[i] * 5, 2);
        font.drawString(ofToString(gt.value[i]), i * 9 + 50 - fontSize / 2, ofGetHeight() - 110 - gt.value[i] * 5);
        
        ofPushMatrix();
        ofTranslate(i * 9 + 50 - fontSize / 2, ofGetHeight() - 50);
        ofRotate(90);
        font.drawString(ofToString(gt.dateMonth[i]) + ", " + ofToString(gt.dateYear[i]), 0, 0);
        ofPopMatrix();
    }
}
