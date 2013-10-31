#include <sstream>
#include <string>

#include "Color.h"


void Color::set_by_name(const string& colorname) {

	if(colorname == "black") {
		red = green = blue = 0;
	} else if(colorname == "white") {
		red = green = blue = 255;
	}
	else if(colorname == "green") {
		red = blue = 0;
		green = 255;
	} else if(colorname == "red") {
		green = blue = 0;
		red = 255;
	} else if(colorname == "blue") {
		red = green = 0;
		blue = 255;
	} else {
		throw "Unknown color name!";
	}
}

string Color::to_string() const {
	stringstream ss;

	ss << "Color (at " << this << "): red=" << red << ", green=" << green
			<< ", blue=" << blue;

	return ss.str();
}

