#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(nPasses.setup("nPasses",1,0,10));
    gui.add(offset.setup("offset",1.0,0,20.0));
    gui.loadFromFile("settings.xml");

    
    
    
    ww = ofGetWindowWidth();
    hh = ofGetWindowHeight();
    
    mode = 2;
    
    blur.setup(ww, hh);
    blur.setNPasses(nPasses);
    blur.setOffset(offset);
    blur.setMode(mode);
    
    
    bypass = false; //bypass shader;
    

}

//--------------------------------------------------------------
void ofApp::update(){

    ang+=.5;

    //better with gui events
    blur.setNPasses(nPasses);
    blur.setOffset(offset);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    blur.begin();
    
    //draw here:
    ofBackground(0);
    ofPushMatrix();
    ofTranslate(ww*0.5f, hh*0.5f);
    ofRotateYDeg(ang);
    ofRotateXDeg(ang);

    ofSetColor(255);
    ofDrawBox(0,0,0,200,100,60);
    
    ofPopMatrix();
    
    
    blur.end();
    
    
    
    ofDisableDepthTest();
    gui.draw();
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate(),2), ww-100, 50);
    ofDrawBitmapString("current mode"+ofToString(blur.getMode()) + " (change mode with number keys,\nspace to bypass)", 50,260);

    ofDrawBitmapString("mode 0: constant", 50, 300);
    ofDrawBitmapString("mode 1: linear", 50, 320);
    ofDrawBitmapString("mode 2: inverse linear", 50, 340);
    ofDrawBitmapString("mode 3: exp", 50, 360);
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == ' '){
        bypass = !bypass;
        blur.setBypass(bypass);
    }
    else if(key == '0'){
        blur.setMode(0);
    }
    else if(key == '1'){
        blur.setMode(1);
    }
    else if(key == '2'){
        blur.setMode(2);
    }
    else if(key == '3'){
        blur.setMode(3);
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
