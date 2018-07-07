#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    gui.setup();
    gui.add(nPasses.setup("nPasses",1,0,10));
    gui.add(offset.setup("offset",1.0,0,20.0));
    
    
    
    
    ww = ofGetWindowWidth();
    hh = ofGetWindowHeight();
    shift.setup(ww, hh);
    shift.setupTiltShift();
    shift.setNPasses(nPasses);
    shift.setOffset(offset);
    
    
    bypass = false; //bypass shader;
    blurMode = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    ang+=.5;
    
    //better with gui events
    shift.setNPasses(nPasses);
    shift.setOffset(offset);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    shift.begin();
    
    //draw here:
    ofBackground(0);
    ofPushMatrix();
    ofTranslate(ww*0.5f, hh*0.5f);
    ofRotateXDeg(60);
    int cols = 10;
    int rows = 10;
    ofEnableLighting();
    ofSetColor(255);
    
    for(int i=0;i<cols; i++){

        for(int j=0; j<rows; j++){

            ofPushMatrix();
            ofTranslate(i*100 - ww*0.5f, j*100-hh*0.5f, 0);
            float h = sinf(i+j)*100+130;
            ofDrawBox(0, 0, h/2, 5, 5, -h);
           
            
            
            ofPopMatrix();
        }
    }
    
    
    
    ofPopMatrix();
    
    
    shift.end();
    


    
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' '){
        bypass = !bypass;
        shift.setBypass(bypass);
    }
    else if(key == '0'){
        shift.setMode(0);
    }
    else if(key == '1'){
        shift.setMode(1);
    }
    else if(key == '2'){
        shift.setMode(2);
    }
    else if(key == '3'){
        shift.setMode(3);
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
