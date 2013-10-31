
#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include <string>
using namespace std;

#include "Shape.h"

#include "simple_svg_1.0.0.hpp"


class Rectangle : public Shape {

public:

	int x1, y1, x2, y2;

	virtual void write_to_svg(svg::Document& doc);
	virtual string to_string() const;
};

#endif
