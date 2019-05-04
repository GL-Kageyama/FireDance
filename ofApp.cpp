#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetCircleResolution(100);
    
    width = 850;
    height = 850;
    
    fluid.allocate(width, height, 0.5);
    
    fluid.dissipation = 0.99;
    fluid.velocityDissipation = 0.99;
    
    fluid.setGravity(ofVec2f(0.0, 0.0));
    
    fluid.begin();
    ofSetColor(0, 0);
    ofSetColor(255);
    ofCircle(width*0.5, height*0.35, 170);
    fluid.end();
    fluid.setUseObstacles(false);
    
    fluid.addConstantForce(ofPoint(width*0.5, height*0.95),
                           ofPoint(0,-4),
                           ofFloatColor(0.9, 0.3, 0.2), 20.f);
    
    ofSetWindowShape(width, height);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofPoint m = ofPoint(mouseX, mouseY);
    ofPoint d = (m - oldM)*20.0;
    oldM =m;
    ofPoint c = ofPoint(640*0.5, 480*0.5) - m;
    c.normalize();
    fluid.addTemporalForce(m, d, ofFloatColor(c.x, c.y, 0.5)*sin(ofGetElapsedTimef()), 3.0f);
    
    fluid.update();
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}
    
//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_LINEAR);
    
    fluid.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'p'){
        bPaint = !bPaint;
    }
    if(key == 'o'){
        bObstacle = !bObstacle;
    }
    if(key == 'b'){
        bBounding = !bBounding;
    }
    if(key == 'c'){
        bClear = !bClear;
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
