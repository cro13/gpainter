
#ifndef _SHAPE_H
#define _SHAPE_H

#include "simple_svg_1.0.0.hpp"

#include "Serializable.h"
#include "Color.h"

class Shape : public Serializable {

public:

	Color color;

	virtual ~Shape() {}

	virtual void write_to_svg(svg::Document& doc)=0;
};

#endif
