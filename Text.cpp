#include <sstream>

#include "Text.h"

void Text::write_to_svg(svg::Document& doc) {

	doc<<svg::Text(
		svg::Point(x1,y1),
		txt,
		svg::Fill(svg::Color(color.red, color.green, color.blue)),
		svg::Font(svg::Font(15,"Times New Roman")),
		svg::Stroke(2.0,svg::Color(color.red,color.green,color.blue))
		);
}

string Text::to_string() const {

	stringstream ss;
	ss << "Text (at " << this << "): (" << x1 << ", " << y1 << ") - ("
			", color=" << color.to_string()<<"Text is "<<txt;
	

	return ss.str();
}
