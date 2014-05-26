#include "exampleApp.h"

    string station[11] = {"UT", "ASD", "RTD", "LEDN", "SHL", "EHV", "HT", "AMF", "AH", "GV","GVC"};

//------------------------------------------------------------------------------
void exampleApp::setup()
{
    selected = 0;

    std::string url = "http://www.kimonolabs.com/api/clkvbhi0?apikey=635a729bb796878d046abb2a5a5544ef&from="+station[selected];
	// Now parse the JSON
	bool parsingSuccessful = json.open(url);
	if (parsingSuccessful) {
		cout << json.getRawString(true) << endl;

	} else {
		cout  << "Failed to parse JSON" << endl;
	}
}

//------------------------------------------------------------------------------
void exampleApp::draw()
{
    ofBackground(0);
    ofSetColor(255);
    int length = json["results"]["collection1"].size();
    int mins[length];
    string tmp;
	for(int i=0; i<length; i++)
	{
        std::string delay = json["results"]["collection1"][i]["vertraging"].asString();
        delay.erase(0,3);
        stringstream ss(delay);
        //cout << delay << endl;
        ss >> mins[i] >> tmp;
        //cout << mins[i] << endl;
		//ofDrawBitmapString(delay, 20, i*24+40);
        ofDrawBitmapString(ofToString(mins[i]), 20, i*24+40);
        ofCircle(i*20+20, ofGetHeight()/2, mins[i]*3);
	}
    
}

void exampleApp::changeStation(){
    selected += 1;
    if(selected ==11) selected = 0;
    std::string url = "http://www.kimonolabs.com/api/clkvbhi0?apikey=635a729bb796878d046abb2a5a5544ef&from="+station[selected];
	// Now parse the JSON
    cout << station[selected] << endl;
	bool parsingSuccessful = json.open(url);

}

void exampleApp::keyPressed(int key){
    switch (key) {
        case 's': changeStation();
            break;
            
        default:
            break;
    }
}
