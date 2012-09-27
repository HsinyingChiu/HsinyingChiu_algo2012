#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(255,255,255);
	
	ofSetCircleResolution(100);
	
	
	
	beats.loadSound("01.mp3");
	beats.play();

}

//--------------------------------------------------------------
void testApp::update(){
	
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	//beat01
	float sinOfTime = sin( ofGetElapsedTimef()*5);
	float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 0, 255);
	
	ofFill();
	ofEnableAlphaBlending();
	ofSetColor(255,0, 0,sinOfTimeMapped);
	ofCircle(300, 400,10);
	ofCircle(400, 400,10);
	ofCircle(500, 400,10);
	ofCircle(600, 400,10);
	ofCircle(700, 400,10);
	
	
	
	//beat02
	float sinOfTime02 = sin( ofGetElapsedTimef()*5);
	float sinOfTimeMapped02= ofMap( sinOfTime02, -1, 1, 80, 30);
	
	
	
	ofSetColor(255,0,0);
	ofNoFill();
	ofRect(300-sinOfTimeMapped02/2, 400-sinOfTimeMapped02/2, sinOfTimeMapped02, sinOfTimeMapped02);
	ofRect(400-sinOfTimeMapped02/2, 400-sinOfTimeMapped02/2, sinOfTimeMapped02, sinOfTimeMapped02);
	ofRect(500-sinOfTimeMapped02/2, 400-sinOfTimeMapped02/2, sinOfTimeMapped02, sinOfTimeMapped02);
	ofRect(600-sinOfTimeMapped02/2, 400-sinOfTimeMapped02/2, sinOfTimeMapped02, sinOfTimeMapped02);
	ofRect(700-sinOfTimeMapped02/2, 400-sinOfTimeMapped02/2, sinOfTimeMapped02, sinOfTimeMapped02);

	//ofCircle(800, 100, sinOfTimeMapped02);
	
	//ofCircle(400,400, sinOfTimeMapped);
	
	
	//beat02
	//float sinOfTime02 = sin( ofGetElapsedTimef() *20);
	//float sinOfTimeMapped02= ofMap( sinOfTime02, -1, 1, 50, 80);
	
	//ofSetColor(255, 255, 255);
	//ofCircle(400,600, sinOfTimeMapped02);
	

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

