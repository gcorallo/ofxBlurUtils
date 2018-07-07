#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ww = ofGetWindowWidth();
    hh = ofGetWindowHeight();
    
    blurRGB.setupRGB(ww, hh);
    blurRGB.setMode(3);
    
    ang = 0.0f;
    
    parameters.setName("settings");
    parameters.add(blurRGB.parametersRGB);
    
    gui.setup(parameters);
    gui.loadFromFile("settings.xml");
    
    
    bypass = false;

}

//--------------------------------------------------------------
void ofApp::update(){

     ang+=.5f;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(0);
    
    blurRGB.begin();
    
    
    
    ofPushMatrix();
    ofTranslate(ww*0.5f, hh*0.5f);
    ofRotateYDeg(ang);
    ofRotateXDeg(ang);

    ofSetColor(255);
    ofDrawBox(0,0,0,200,100,60);
    
    ofPopMatrix();
    
    
    blurRGB.endRGB();


    ofDisableDepthTest();
    gui.draw();
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate(),2), ww-100, 50);
    ofDrawBitmapString("current mode"+ofToString(blurRGB.getMode()) + " (change mode with number keys,\nspace to bypass)", 50,260);
    ofDrawBitmapString("mode 0: normal", 50, 300);
    ofDrawBitmapString("mode 1: linear", 50, 320);
    ofDrawBitmapString("mode 2: inverse linear", 50, 340);
    ofDrawBitmapString("mode 3: exp", 50, 360);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        bypass = !bypass;
        blurRGB.setBypass(bypass);
    }
    else if(key == '0'){
        blurRGB.setMode(0);
    }
    else if(key == '1'){
        blurRGB.setMode(1);
    }
    else if(key == '2'){
        blurRGB.setMode(2);
    }
    else if(key == '3'){
        blurRGB.setMode(3);
    }

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
