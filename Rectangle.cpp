
#include <sstream>

#include "Rectangle.h"

void Rectangle::write_to_svg(svg::Document& doc) {

	doc << svg::Rectangle(
		svg::Point(x1,y1),
		x2-x1,
		y2-y1,
		svg::Fill(svg::Color(color.red, color.green, color.blue))
		);
}

string Rectangle::to_string() const {

	stringstream ss;

	ss << "Rectangle (at " << this << "): (" << x1 << ", " << y1 << ") - ("
			<< x2 << ", " << y2 << "), color=" << color.to_string();

	return ss.str();
}
