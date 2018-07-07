//
//  ofxBlurUtils.cpp
//  Grow_1b
//
//  Created by Guido Corallo on 5/10/17.
//
//

#include <ofxBlurUtils.h>

void ofxBlurUtils::setup(int ww_, int hh_){
    ww = ww_;
    hh = hh_;
    
    ping.allocate(ww, hh, GL_RGB);
    pong.allocate(ww, hh, GL_RGB);
    
    ping.begin();
    ofClear(0);
    ping.end();
    
    pong.begin();
    ofClear(0);
    pong.end();
    
    //load shaders.
    blurX.load("../../../../../addons/ofxBlurUtils/shaders/shaderBlurX");
    blurY.load("../../../../../addons/ofxBlurUtils/shaders/shaderBlurY");
    maskShader.load("../../../../../addons/ofxBlurUtils/shaders/maskSh");
    
    offset = 1.0;
    mode = 0;
    nPasses = 1;
    atenuateLastPass = false;
    
    ofAddListener(ofEvents().mouseMoved, this, &ofxBlurUtils::mouseMoved);
    
    isTiltShift = false;
    
}

void ofxBlurUtils::setupRGB(int ww_, int hh_){
    ww = ww_;
    hh = hh_;
    
    ping.allocate(ww, hh, GL_RGB);
    pong.allocate(ww, hh, GL_RGB);
    
    ping.begin();
    ofClear(0);
    ping.end();
    
    pong.begin();
    ofClear(0);
    pong.end();
    
    //load shaders.
    //blurX.load("../../../../../addons/ofxBlurUtils/shaders/shaderBlurX");
    //blurY.load("../../../../../addons/ofxBlurUtils/shaders/shaderBlurY");
    
    
    blurX.load("../../../../../addons/ofxBlurUtils/shaders/shaderBlurX_RGB");
    blurY.load("../../../../../addons/ofxBlurUtils/shaders/shaderBlurY_RGB");
    maskShader.load("../../../../../addons/ofxBlurUtils/shaders/maskSh");
    
    
    //gui
    parametersRGB.setName("parametersRGB");
    parametersRGB.add(nPasses.set("nPasses",1,1,10));
    parametersRGB.add(offsetR.set("offsetR",1.0,0.0,1.0));
    parametersRGB.add(offsetG.set("offsetG",1.0,0.0,1.0));
    parametersRGB.add(offsetB.set("offsetB",1.0,0.0,1.0));
    parametersRGB.add(mult.set("mult",1.0,1.0,10.0));
    parametersRGB.add(multX.set("multX",1.0,0.0,1.0));
    parametersRGB.add(multY.set("multY",1.0,0.0,1.0));
    parametersRGB.add(gain.set("gain",1.0,1.0,2.0));
    
    
    
    

    mode = 0;
    atenuateLastPass = false;
    
    
    ofAddListener(ofEvents().mouseMoved, this, &ofxBlurUtils::mouseMoved);
    
}


void ofxBlurUtils::begin(){
    
    
    
    if(!bypass){
        
        if(isTiltShift){
            mask.begin();
            maskShader.begin();
            maskShader.setUniform1i("mode", maskMode);
            ofSetColor(255);
            ofDrawRectangle(0, 0, ww, hh);
            
            maskShader.end();
            mask.end();
            
        }
        
        
        pong.begin();
        ofBackground(0);
    }
    
    
    
}


void ofxBlurUtils::end(){
    
    
    
    if(!bypass){
        pong.end();
        ofSetColor(255);
        
        pong.draw(0,0);
        
        
        
        
        for(int i=0; i< nPasses+1 ; i++){
            float offsetChoice;
            if(mode == 0){
                offsetChoice = offset;
            }
            else if(mode == 1){
                offsetChoice = i*offset;
            }
            else if(mode == 2){
                offsetChoice = (nPasses-i)*offset;
            }
            else if(mode == 3){
                offsetChoice = (i*i)*offset;
            }
            
            
            
            ping.begin();
            ofClear(0,255);
            blurX.begin();
            pong.draw(0,0);
            blurX.setUniform1f("blurAmnt", offsetChoice);
            ofSetColor(255);
            blurX.end();
            ping.end();
            
            
            pong.begin();
            ofClear(0,255);
            blurY.begin();
            blurY.setUniform1f("blurAmnt", offsetChoice);
            
            if(i==nPasses){
                blurY.setUniform1f("atenuateLastPass", atenuateLastPass);
            }
            else{
                blurY.setUniform1f("atenuateLastPass", false);
            }
            
            ofSetColor(255);
            ping.draw(0,0);
            blurY.end();
            pong.end();
            
        }

        if(isTiltShift){
            mix.begin();
            pong.draw(0,0);
            mix.end();
            
            
            mix.getTexture().setAlphaMask(mask.getTexture());
            mix.draw(0,0);
            
        }
        else{
            pong.draw(0, 0);
        }
        
    }
    
    
    
    
    
}


void ofxBlurUtils::endRGB(){
    
    
    
    if(!bypass){
        pong.end();
        ofSetColor(255);
        
        pong.draw(0,0);
        
        for(int i=0; i< nPasses+1 ; i++){
            float offsetMode;
            if(mode == 0){
                offsetMode = 1.0;
            }
            else if(mode == 1){
                offsetMode = i;
            }
            else if(mode == 2){
                offsetMode = (nPasses-i);
            }
            else if(mode == 3){
                offsetMode = (i*i);
            }
            
            
            ping.begin();
            ofClear(0,255);
            blurX.begin();
            pong.draw(0,0);
            blurX.setUniform1f("blurAmntR", offsetMode * offsetR * mult * multX);
            blurX.setUniform1f("blurAmntG", offsetMode * offsetG * mult * multX);
            blurX.setUniform1f("blurAmntB", offsetMode * offsetB * mult * multX);
            blurX.setUniform1f("gain", gain);
            ofSetColor(255);
            blurX.end();
            ping.end();
            
            
            pong.begin();
            ofClear(0,255);
            blurY.begin();
            blurY.setUniform1f("blurAmntR", offsetMode * offsetR * mult * multY);
            blurY.setUniform1f("blurAmntG", offsetMode * offsetG * mult * multY);
            blurY.setUniform1f("blurAmntB", offsetMode * offsetB * mult * multY);
            blurY.setUniform1f("gain", gain);
            
            
            
            if(i==nPasses){
                blurY.setUniform1f("atenuateLastPass", atenuateLastPass);
            }
            else{
                blurY.setUniform1f("atenuateLastPass", false);
            }
            
            ofSetColor(255);
            ping.draw(0,0);
            blurY.end();
            pong.end();
            
        }

        
        
        
        if(isTiltShift){
            mix.begin();
            pong.draw(0,0);
            mix.end();
            
            
            mix.getTexture().setAlphaMask(mask.getTexture());
            mix.draw(0,0);
            
        }
        else{
            pong.draw(0, 0, ww, hh);
        }
        
    }
    
    
    
    
    
}




void ofxBlurUtils::setMode(int mode_){
    
    mode = mode_;
    
}

void ofxBlurUtils::setNPasses(int nPasses_){
    
    nPasses = nPasses_;
    
}

void ofxBlurUtils::setOffset(float offset_){ 
    
    offset = offset_;
    
}

void ofxBlurUtils::setBypass(bool bypass_){
    
    bypass = bypass_;
    
}

void ofxBlurUtils::setupTiltShift(){
    
    mask.allocate(ww, hh, GL_RGB);
    mix.allocate(ww, hh, GL_RGBA);
    
    mask.begin();
    ofClear(0);
    mask.end();
    
    mix.begin();
    ofClear(0);
    mix.end();
    
    isTiltShiftInit = true;
    isTiltShift = true;
    
    maskMode = 1;
    
}

void ofxBlurUtils::mouseMoved(ofMouseEventArgs & mouse){
    
    //cout<<"moved!!!:: "<<mouse.x<<endl;
    //cout<<mouse.Pressed<<endl;

}

int ofxBlurUtils::getMode(){

    return mode;
    
}



