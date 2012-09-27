#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(255,255,255);
	
	ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	float sinOfTime = sin( ofGetElapsedTimef() *2);
	float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 10, 80);
	
	float sinOfTime2			= sin( ofGetElapsedTimef() *2);
	float sinOfTimeMapped2		= ofMap( sinOfTime2, -1, 1, 50, 200);
	
	float sinOfTime3			= sin( ofGetElapsedTimef() *2);
	float sinOfTimeMapped3		= ofMap( sinOfTime2, -1, 1, 50, 200);
	
	float xorig = mouseX;
	float yorig = mouseY;
	float radius = 50;
	float angle = ofGetElapsedTimef()*5;
	
	float x = xorig + radius * cos(angle);
	float y = yorig + radius * -sin(angle);
	
	float x2 = xorig + radius * -cos(angle);
	float y2= yorig + radius * -sin(angle);
	
	ofEnableAlphaBlending();
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	ofSetColor(255,200,0,sinOfTimeMapped2);
	ofCircle(x, y,sinOfTimeMapped);
	
	ofSetColor(255,0,0,sinOfTimeMapped3);
	ofCircle(x2, y2,sinOfTimeMapped);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

