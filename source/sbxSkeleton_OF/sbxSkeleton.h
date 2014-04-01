//
//  sbxSkeleton.h
//
//  Created by Bernardo Santos Schorr on 3/31/14.
//
//

#pragma once
#include "ofMain.h"
#include "ofxSpacebrew.h"
#include "ofxNI2.h"
#include "ofxNiTE2.h"


namespace sbxSkeleton {
    
    class skeletonSender {
        
    public:
        
        //setup for skeleton sender
        void setup ( ofxNiTE2::UserTracker &_tracker, Spacebrew::Connection &_spacebrew, Spacebrew::Config &_config, string _name);
        
        //function for sending skeleton via spacebrew
        void sendSkeleton ( ofxNiTE2::User::Ref user );
        
        //nice utility to convert joint positions from global to screen positions (should probably be in ofxNI2, though...)
        ofVec3f getScreenPosition ( ofxNiTE2::Joint joint );
        
    private:
        
        Spacebrew::Connection * spacebrew;
        ofxNiTE2::UserTracker * tracker;
        string name;
        
        vector<ofVec2f> localPoints;
    
    };
    
}