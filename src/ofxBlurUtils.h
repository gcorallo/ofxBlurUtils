//
//  ofxBlurUtils.h
//  Grow_1b
//
//  Created by Guido Corallo on 5/10/17.
//
//

#ifndef ofxBlurUtils_h
#define ofxBlurUtils_h

#include "ofMain.h"

class ofxBlurUtils{

    
public:
    
    ofxBlurUtils(){
        
    }
    
    
    ofShader blurX;
    ofShader blurY;
    
    ofFbo ping;
    ofFbo pong;
    
    int ww;
    int hh;
    
    //basic methods
    void setup(int ww_, int hh_);
    void begin();
    void end();
    
    //conf methods
    void setMode(int mode_);
    void setNPasses(int nPasses_);
    void setOffset(float offset_);
    
    void setBypass(bool bypass_);
    
private:
    
    int mode;
    int nPasses;
    
    float offSet;
    bool bypass;
    
    
    
    


};


#endif /* ofxBlurUtils_h */
