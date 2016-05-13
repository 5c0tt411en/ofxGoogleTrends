#include "ofxGoogleTrends.h"

void ofxGoogleTrends::setup(string keyword) {
    // get raw data from API
    url = "http://www.google.com/trends/fetchComponent?hl=en-US&q=" + keyword + "&cid=TIMESERIES_GRAPH_0&export=3";
    raw = ofLoadURL(url).data.getText();
    for (int i = 0; i < 62; i++) raw.erase(raw.begin());
    for (int j = 0; j < 2; j++) raw.pop_back();
    ofStringReplace(raw, "new Date(", "");
    for (int i = 0; i < 12; i++) ofStringReplace(raw, "," + ofToString(i) + ",", ofToString(i) + ",");
    ofStringReplace(raw, ",1)", "");
    fileName = keyword + ".json";
    ofBuffer buffer = ofBuffer(raw);
    ofBufferToFile(fileName, buffer);
    bool parsingSuccessful = json.open(fileName);
    if (parsingSuccessful) ofLogNotice("ofApp::setup") << json.getRawString(true);
    else ofLogNotice("ofApp::setup") << "Failed to parse JSON. it seems you sent too many requests, try few minites later.";
    
    // define dataLength
    dataLength = json["table"]["rows"].size();
    
    // get value and dateText
    for (int i = 0; i < dataLength; i++) {
        value.push_back(json["table"]["rows"][i]["c"][1]["v"].asFloat());
        dateText.push_back(json["table"]["rows"][i]["c"][0]["f"].asString());
        int date = json["table"]["rows"][i]["c"][0]["v"].asInt();
        date < 100000 ? dateMonth.push_back(date % 10 != 0 ? date % 10 : 12) : dateMonth.push_back(date % 10 + 10);
        date < 100000 ? dateYear.push_back(date % 10 != 0 ? date / 10 : date / 10 - 1) : dateYear.push_back(date / 100);
    }
}
