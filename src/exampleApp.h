#pragma once


#include "ofMain.h"
#include "ofxJSONElement.h"
#include "Poco/RegularExpression.h"


class exampleApp : public ofBaseApp {
public:
    void setup();
    void draw();
    void changeStation();
    void keyPressed(int key);

    
    int selected;
    ofxJSONElement json;
    


};
