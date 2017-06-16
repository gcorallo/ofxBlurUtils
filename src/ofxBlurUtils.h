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
    ofShader maskShader;
    
    ofFbo ping;
    ofFbo pong;
    
    ofFbo mask;
    ofFbo mix;
    
    
    
    
    
    
    int ww;
    int hh;
    
    //basic methods
    void setup(int ww_, int hh_);
    void setupTiltShift();              //enables use of alpha mask.
    void setupRGB(int ww_, int hh_);
    
    void begin();
    void end();
    void endRGB();
    
    //conf methods
    void setMode(int mode_);
    void setNPasses(int nPasses_);
    void setOffset(float offset_);
    
    void setBypass(bool bypass_);
    
    void setTiltShift(bool isTiltShift_);
    
    //events:
    void mouseMoved(ofMouseEventArgs & mouse);
    
     bool atenuateLastPass;
    
    
    //gui
    ofParameterGroup parameters;
    ofParameter <float> offset;
    
    //guiRGB
    ofParameterGroup parametersRGB;
    ofParameter <int> nPasses;
    ofParameter <float> offsetR;
    ofParameter <float> offsetG;
    ofParameter <float> offsetB;
    
    
    
    
    
    
private:
    
    int mode;
    //int nPasses;
    
    //float offSet;
    bool bypass;
    
    
    bool isTiltShift;
    bool isTiltShiftInit;
    
    int maskMode;

   
};


#endif /* ofxBlurUtils_h */
