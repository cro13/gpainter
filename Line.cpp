
#include <sstream>

#include "Line.h"

void Line::write_to_svg(svg::Document& doc) {

	doc << svg :: Line(
		svg :: Point ( x1 , y1 ),
		svg :: Point ( x2 , y2 ),
		svg :: Stroke ( 2.0 , svg :: Color ( color . red , color . green , color . blue ) )
		);
}

string Line::to_string() const {

	stringstream ss;

	ss << "Line (at " << this << "): (" << x1 << ", " << y1 << ") - ("
			<< x2 << ", " << y2 << "), color=" << color.to_string();

	return ss.str();
}
