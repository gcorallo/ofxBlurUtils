#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ww = ofGetWindowWidth();
    hh = ofGetWindowHeight();
    
    blurRGB.setupRGB(ww, hh);
    
    ang = 0.0f;
}

//--------------------------------------------------------------
void ofApp::update(){

     ang+=.5f;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    blurRGB.begin();
    
    ofBackground(0);
    ofPushMatrix();
    ofTranslate(ww*0.5, hh*0.5);
    ofRotateY(ang);
    ofRotateX(ang);
    
    ofSetColor(255);
    ofDrawBox(0,0,0,200,100,60);
    
    ofPopMatrix();
    
    
    blurRGB.endRGB();


    ofDisableDepthTest();
    gui.draw();
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate(),2), ww-100, 50);
    //ofDrawBitmapString("current mode"+ofToString(mode), 50,260);
    ofDrawBitmapString("mode 0: normal", 50, 300);
    ofDrawBitmapString("mode 1: linear", 50, 320);
    ofDrawBitmapString("mode 2: inverse linear", 50, 340);
    ofDrawBitmapString("mode 3: exp", 50, 360);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
