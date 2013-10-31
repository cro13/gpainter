#include "Circle.h"

void Circle::write_to_svg(svg::Document& doc) {

	doc << svg::Circle(svg::Point(x, y),
			radius*2,
			svg::Fill(svg::Color(color.red, color.green, color.blue)),
			svg::Stroke(1, svg::Color(color.red, color.green, color.blue)));
}

string Circle::to_string() const {
	stringstream ss;

	ss << "Circle (at " << this << "): center=(" << x << ", " << y
			<< "), radius=" << radius << ", color=" << color.to_string();

	return ss.str();
}
