#ifndef TEXT_H
#define TEXT_H

#include <string>

using namespace std;

#include "Shape.h"

#include "simple_svg_1.0.0.hpp"

class Text: public Shape {

public:

	int x1, y1;
	string txt;
	virtual void write_to_svg(svg::Document& doc);
	virtual string to_string() const;
};

#endif