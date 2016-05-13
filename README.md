# ofxGoogleTrends
openFrameworks addon for google trends visualization and sonification.

## Requirements
- ofxJSON

## Usage

        ofxGoogleTrends gt;
        string keyword = "xxxxxxxx";

        gt.setup(keyword); // setting up with keyword

        // Value (0 ~ 100), date text (e.g. December 2005), date month value (1 ~ 12), date year value(2003 - now) can be called like:
        gt.value[n];
        gt.dateText[n];
        gt.dateMonth[n];
        gt.dateYear[n];

        // Number of array elements (n) can be called like:
        gt.dataLength;

## Demo
[Google Trends Visualization and Sonification](https://youtu.be/IKpcvAYjy0E)

## Caution
Do not call setup(string keyword) too many times in short time.  
Limitation can be caused by too many requests.

## Copyright
Copyright 2016-, Scott Allen([scottallen.ws](http://scottallen.ws)).  
Twitter:[@Scott_Allen__](https://twitter.com/#!/Scott_Allen__ "twitter@Scott_Allen__").
