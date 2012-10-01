#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){


	ofSetVerticalSync(true);

	cam.initGrabber(320, 240);
	
	ofBackground(255, 255, 255);
	TPR.setup();
	playbackStartTime = 0;
	loopingSound.loadSound("drawbar_c4_a.aif");
	loopingSound.setVolume(0);
	loopingSound.setLoop(true);
	loopingSound.play();
	
	
	/*ofBackground(255,255,255);
	
	frameByframe = false;
	
	fingerMovie.loadMovie("movies/fingers.mov");
	fingerMovie.play();*/
	
	
}


//--------------------------------------------------------------
void testApp::update(){
	
	
	cam.grabFrame();
	/*fingerMovie.idleMovie();
	ofBackground(100,100,100);*/

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	
	
	// -------------------------- draw the line
	TPR.draw();
	
	// -------------------------- draw the point at the current time
	if (TPR.bHaveADrawing()){			// if we have a drawing to work with
		
		// figure out what time we are at, and make sure we playback cyclically (!)
		// use the duration here and make sure our timeToCheck is in the range of 0 - duration
		float timeToCheck = ofGetElapsedTimef() - playbackStartTime;
		while (timeToCheck > TPR.getDuration() && TPR.getDuration() > 0){
			timeToCheck -= TPR.getDuration();
		}
		
		// get the position and velocity at timeToCheck
		ofPoint pos = TPR.getPositionForTime(timeToCheck);
		ofPoint vel = TPR.getVelocityForTime(timeToCheck);
		
		// since velocity is a line, we want to know how long it is. 
		float lengthOfVel = ofDist(0,0,vel.x, vel.y);
		
		
		float soundVolume = ofMap(lengthOfVel, 0,200, 0,1);
		loopingSound.setVolume(soundVolume);
		
		
		float pitch = ofMap(pos.y, 0, (float)ofGetHeight(), 2.5, 0.1);
		loopingSound.setSpeed(pitch);
		
		float pan = ofMap(pos.x, 0, (float)ofGetWidth(), -1, 1);
		loopingSound.setPan(pan);

		
		ofEnableAlphaBlending();
		ofFill();
		
		ofSetColor(lengthOfVel,lengthOfVel,lengthOfVel);
		ofCircle(pos.x, pos.y, 10+ lengthOfVel/5.0);
		
		//ofSetColor(55,0,255,lengthOfVel);
		ofCircle(ofRandom(pos.x-10,pos.x+10), pos.y, 2 + lengthOfVel/5.0);
		ofEnableAlphaBlending();
		
		
		
		
		/*fingerMovie.draw(20,20);
		ofSetHexColor(0x000000);
		unsigned char * pixels = fingerMovie.getPixels();
		// let's move through the "RGB" char array
		// using the red pixel to control the size of a circle.
		for (int i = 4; i < 320; i+=8){
			for (int j = 4; j < 240; j+=8){
				unsigned char r = pixels[(j * 320 + i)*3];
				float val = 1 - ((float)r / 255.0f);
				ofCircle(400 +i,20+j,lengthOfVel/100.0);
			}
		}
		

	}
	ofSetHexColor(0xFFFFFF);
	
	
	
	
    fingerMovie.draw(20,20);
    ofSetHexColor(0x000000);
    unsigned char * pixels = fingerMovie.getPixels();
    // let's move through the "RGB" char array
    // using the red pixel to control the size of a circle.
    for (int i = 4; i < 320; i+=8){
        for (int j = 4; j < 240; j+=8){
            unsigned char r = pixels[(j * 320 + i)*3];
            float val = 1 - ((float)r / 255.0f);
            ofCircle(400 + i,20+j,10*val);
        }*/
    }
	
	cam.draw(ofGetWidth()/2-160, ofGetHeight()/2-120);
	
	
    /*ofSetHexColor(0x000000);
	ofDrawBitmapString("press f to change",20,320);
    if(frameByframe) ofSetHexColor(0xCCCCCC);
    ofDrawBitmapString("mouse speed position",20,340);
    if(!frameByframe) ofSetHexColor(0xCCCCCC); else ofSetHexColor(0x000000);
    ofDrawBitmapString("keys <- -> frame by frame " ,190,340);
    ofSetHexColor(0x000000);
	
    ofDrawBitmapString("frame: " + ofToString(fingerMovie.getCurrentFrame()) + "/"+ofToString(fingerMovie.getTotalNumFrames()),20,380);
    ofDrawBitmapString("duration: " + ofToString(fingerMovie.getPosition()*fingerMovie.getDuration(),2) + "/"+ofToString(fingerMovie.getDuration(),2),20,400);
    ofDrawBitmapString("speed: " + ofToString(fingerMovie.getSpeed(),2),20,420);
	
    if(fingerMovie.getIsMovieDone()){
        ofSetHexColor(0xFF0000);
        ofDrawBitmapString("end of movie",20,440);
    }*/
	

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
	TPR.addPoint(x,y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	TPR.startDrawing(x,y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	TPR.endDrawing();
	playbackStartTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}



