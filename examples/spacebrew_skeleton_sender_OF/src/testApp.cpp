#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup()
{
    //general settings
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);
    
    width = ofGetWindowWidth();
    height = ofGetWindowHeight();
	
    //openni setup
	device.setup();
	
    //make sure device inited
	if (tracker.setup(device)) cout << "tracker inited" << endl;
    
    //spacebrew setup
    Spacebrew::Config config;
    config.clientName = "spacebrew_skeleton_sender";
    
    //set your skeleton sender with your openni tracker, spacebrew connection, spacebrew config and the name it will take. The default type is "skeleton".
    skeletonSender.setup( tracker, spacebrew, config, "skeleton_sender" );
    
    //connect to spacebrew
    spacebrew.connect( "54.186.254.11", config );
    
    
    
}

//this function makes sure devices are closed when app is terminated.
void testApp::exit()
{
	tracker.exit();
	device.exit();
}

//--------------------------------------------------------------
void testApp::update()
{
	device.update();
    
    //checkout and iterate through users to be sent via the skeleton sender
    int numUsers = tracker.getNumUser();
    
    for (int i = 0; i < numUsers; i++){
        
        // get a reference to this user
        ofxNiTE2::User::Ref user = tracker.getUser(i);
        
        //send it using the spacebrew skeleton sender
        skeletonSender.sendSkeleton(user);
        
    }
    
}

//--------------------------------------------------------------
void testApp::draw()
{
	// draw depth image for debug
	depth_image.setFromPixels(tracker.getPixelsRef(1000, 4000));
	
	ofSetColor(255);
	depth_image.draw(0, 0);
	
	// draw 2d skeleton for debug
	ofPushView();
	tracker.getOverlayCamera().begin(ofRectangle(0, 0, depth_image.getWidth(), depth_image.getHeight()));
	tracker.draw();
	tracker.getOverlayCamera().end();
	ofPopView();
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 30, 30);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}