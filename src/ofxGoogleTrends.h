#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ofxGoogleTrends {

    public:
        void setup(string keyword);
    
        int dataLength;
        vector<string> dateText;
        vector<int> value, dateMonth, dateYear;
    
    
    private:
        string fileName;
        ofxJSONElement json;
        std::string url, raw;
};
