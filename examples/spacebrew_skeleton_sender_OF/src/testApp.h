#pragma once

#include "ofMain.h"

#include "ofxNI2.h"
#include "ofxNiTE2.h"
#include "ofxSpacebrew.h"
#include "sbxSkeleton.h"

class testApp : public ofBaseApp
{
public:
	void setup();
	void exit();
	
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
    //openni
	ofxNI2::Device device;
	ofxNiTE2::UserTracker tracker;
    
    ofImage depth_image;
    
    //spacebrew + sbxSkeleton
    Spacebrew::Connection spacebrew;
    sbxSkeleton::skeletonSender skeletonSender;
    
    //other utilities
    int width, height;
    
    
};