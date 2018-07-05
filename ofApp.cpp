#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(90);

	ofColor rect_color;
	int radius = 400;
	int deg_span = 24;

	for (int z = -500; z <= 500; z += 120) {

		int noise_deg = ofMap(ofNoise(z * 0.001 + ofGetFrameNum() * 0.005), 0, 1, -360, 360);
		for (int deg = 0; deg < 360; deg += deg_span) {

			rect_color.setHsb(ofMap(deg, 0, 360, 0, 255), 200, 255);
			ofSetColor(rect_color);

			ofPushMatrix();
			ofRotateZ(noise_deg);

			ofPoint rect_point(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z);
			ofTranslate(rect_point);
			ofRotateX(90);
			ofRotateY(deg + 90);

			ofDrawRectangle(0, 0, 160, 90);

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}