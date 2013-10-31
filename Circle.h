
#ifndef _CIRCLE_H
#define _CIRCLE_H

#include <string>
using namespace std;

#include "Shape.h"

#include "simple_svg_1.0.0.hpp"

class Circle : public Shape {

public:

	int radius;
	int x;
	int y;

	virtual void write_to_svg(svg::Document& doc);

	virtual string to_string() const;
};

#endif
