#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// Box2d Setup
	ofSetVerticalSync(true);
	ofBackground(255,255,255,255);
	ofSetLogLevel(OF_LOG_NOTICE);
	ofDisableAntiAliasing();

	box2d.init();
	box2d.setGravity(0, 0);
	box2d.setFPS(60.0);

	ofEasyCam();


	for (int i = 0; i < 300; i++) {

		float r = ofRandom(2, 5);
		auto circle = make_shared<ofxBox2dCircle>();
		circle->setPhysics(5.0, 0.53, 5);
		//circle->setPhysics(3.0, 0.53, 0.9);
		circle->setup(box2d.getWorld(), ofGetWidth() / 2, ofGetHeight() / 2, r);
		circles.push_back(circle);

		float w = ofRandom(1, 3);
		float h = ofRandom(1, 3);
		auto rect = make_shared<ofxBox2dRect>();
		rect->setPhysics(5.0, 0.53, 7.9);
		rect->setup(box2d.getWorld(), ofGetWidth() / 2, ofGetHeight() / 2, w, h);
		boxes.push_back(rect);
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	box2d.update();
	ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
	float minDis = ofGetMousePressed() ? 50 : 20;

	for (auto &circle : circles) {
		float dis = mouse.distance(circle->getPosition());

		if (dis < minDis) {
			circle->addRepulsionForce(mouse, 1);
		}
		else {
			circle->addAttractionPoint(mouse, .5);
		}
	}

	for (auto &box : boxes) {
		float dis = mouse.distance(box->getPosition());
		if (dis < minDis) box->addRepulsionForce(mouse, 1);
		else {
			box->addAttractionPoint(mouse,.5 );
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){


	for (auto &circle : circles) {
		ofFill();
		ofSetColor(0, 0, 0, 215);
		circle->draw();
	}

	for (auto &box : boxes) {
		ofFill();
		ofSetColor(0,0, 0, 125);
		box->draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 'c') {
		float r = ofRandom(14, 20);
		auto circle = make_shared<ofxBox2dCircle>();
		circle->setPhysics(3.0, 0.53, 0.9);
		circle->setup(box2d.getWorld(), mouseX, mouseY, r);
		circles.push_back(circle);

		shapes.push_back(circle);
	}

	if (key == 'b') {
		float w = ofRandom(14, 20);
		float h = ofRandom(14, 20);
		auto rect = make_shared<ofxBox2dRect>();
		rect->setPhysics(3.0, 0.53, 0.9);
		rect->setup(box2d.getWorld(), mouseX, mouseY, w, h);
		boxes.push_back(rect);

		shapes.push_back(rect);
	}

	if (key == 't') ofToggleFullscreen();
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
