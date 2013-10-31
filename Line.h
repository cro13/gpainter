
#ifndef _LINE_H
#define _LINE_H

#include <string>
using namespace std;

#include "Shape.h"

#include "simple_svg_1.0.0.hpp"

class Line: public Shape {

public:

	int x1, y1, x2, y2;

	virtual void write_to_svg(svg::Document& doc);
	virtual string to_string() const;
};

#endif
