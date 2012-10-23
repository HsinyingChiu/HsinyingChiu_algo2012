#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetFrameRate(36);
	ofBackground(0, 0, 0);
	
	gravity.y = 0.2;	
}

//--------------------------------------------------------------
void testApp::update(){
	
	ps.applyForce(gravity);
	ps.update();

	for(int i=0; i<10; i++) {
		ps.addParticle(ofGetWidth()/2, ofGetHeight()-10);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ps.draw();
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
	//r.drag(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//r.clicked(x, y);


}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	//r.stopDragging();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
