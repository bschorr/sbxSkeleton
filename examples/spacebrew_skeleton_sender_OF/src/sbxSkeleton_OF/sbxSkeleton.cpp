//
//  sbxSkeleton.cpp
//
//  Created by Bernardo Santos Schorr on 3/31/14.
//
//

#include "sbxSkeleton.h"

namespace sbxSkeleton {

void skeletonSender::setup( ofxNiTE2::UserTracker &_tracker, Spacebrew::Connection  &_spacebrew, Spacebrew::Config &config, string _name ) {
    
    name = _name;
    config.addPublish(name, "skeleton", "");
    spacebrew = &_spacebrew;
    tracker = &_tracker;
    
}

void skeletonSender::sendSkeleton( ofxNiTE2::User::Ref user ) {
    
    //spacebrew sending data
    Json::Value skeleton = Json::Value( Json::objectValue );
    
    Json::Value neck = Json::Value( Json::objectValue );
    Json::Value head = Json::Value( Json::objectValue );
    
    Json::Value left_shoulder = Json::Value( Json::objectValue );
    Json::Value left_elbow = Json::Value( Json::objectValue );
    Json::Value left_hand = Json::Value( Json::objectValue );
    
    Json::Value right_shoulder = Json::Value( Json::objectValue );
    Json::Value right_elbow = Json::Value( Json::objectValue );
    Json::Value right_hand = Json::Value( Json::objectValue );
    
    Json::Value left_hip = Json::Value( Json::objectValue );
    Json::Value left_knee = Json::Value( Json::objectValue );
    Json::Value left_foot = Json::Value( Json::objectValue );
    
    Json::Value right_hip = Json::Value( Json::objectValue );
    Json::Value right_knee = Json::Value( Json::objectValue );
    Json::Value right_foot = Json::Value( Json::objectValue );
    
    Json::Value torso = Json::Value( Json::objectValue );
    
    //neck and head
    
    neck["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_NECK)).x);
    neck["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_NECK)).y);
    
    head["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_HEAD)).x);
    head["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_HEAD)).y);
    
    //left arm
    left_shoulder["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_SHOULDER)).x);
    left_shoulder["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_SHOULDER)).y);
    
    left_elbow["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_ELBOW)).x);
    left_elbow["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_ELBOW)).y);
    
    left_hand["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_HAND)).x);
    left_hand["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_HAND)).y);
    
    //right arm
    right_shoulder["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_SHOULDER)).x);
    right_shoulder["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_SHOULDER)).y);
    
    right_elbow["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_ELBOW)).x);
    right_elbow["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_ELBOW)).y);
    
    right_hand["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_HAND)).x);
    right_hand["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_HAND)).y);
    
    //left leg
    left_hip["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_HIP)).x);
    left_hip["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_HIP)).y);
    
    left_knee["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_KNEE)).x);
    left_knee["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_KNEE)).y);
    
    left_foot["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_FOOT)).x);
    left_foot["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_LEFT_FOOT)).y);
    
    //right leg
    right_hip["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_HIP)).x);
    right_hip["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_HIP)).y);
    
    right_knee["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_KNEE)).x);
    right_knee["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_KNEE)).y);
    
    right_foot["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_FOOT)).x);
    right_foot["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_RIGHT_FOOT)).y);
    
    //torso
    torso["x"] = round (getScreenPosition(user->getJoint(nite::JOINT_TORSO)).x);
    torso["y"] = round (getScreenPosition(user->getJoint(nite::JOINT_TORSO)).y);
    
    //build skeleton
    skeleton["neck"] = neck;
    skeleton["head"] = head;
    skeleton["torso"] = torso;
    
    skeleton["left_shoulder"] = left_shoulder;
    skeleton["left_elbow"] = left_elbow;
    skeleton["left_hand"] = left_hand;
    
    skeleton["right_shoulder"] = right_shoulder;
    skeleton["right_elbow"] = right_elbow;
    skeleton["right_hand"] = right_hand;
    
    skeleton["left_hip"] = left_hip;
    skeleton["left_knee"] = left_knee;
    skeleton["left_foot"] = left_foot;
    
    skeleton["right_hip"] = right_hip;
    skeleton["right_knee"] = right_knee;
    skeleton["right_foot"] = right_foot;
    
    spacebrew->send( name, "skeleton", skeleton.toStyledString());
    
}
    ofVec3f skeletonSender::getScreenPosition( ofxNiTE2::Joint joint ) {
        
        ofVec3f pos;
        pos = joint.getGlobalPosition();
        pos = tracker->getOverlayCamera().worldToScreen(pos);
        
        return pos;
    }
}
