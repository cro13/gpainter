#include <cstdlib>
#include <iostream>
#include <sstream>
#include "layout.h"

#include "Drawing.h"
#include "Shape.h"

#include "simple_svg_1.0.0.hpp"

void Drawing::add_shape(Shape* shape) {
	shapes.push_back(shape);
}

void Drawing::save_to_file(const string& file_name) {

    svg::Dimensions dimensions(width, height);
    svg::Document doc(file_name, svg::Layout(dimensions, svg::Layout::TopLeft));

    // Adds a white background
	doc << svg::Rectangle(svg::Point(0, height), width, height,
		svg::Fill(svg::Color(255, 255, 200)),
		svg::Stroke(1, svg::Color::Black)
		);

    for (vector<Shape*>::iterator it = shapes.begin() ; it != shapes.end(); ++it) {
    	(*it)->write_to_svg(doc);
    }

    doc.save();
}

string Drawing::to_string() const {
	stringstream ss;

	ss << "Drawing (at " << this << "), size " << width << "x" << height 
		<< " with " << shapes.size() << " shapes:" << endl;

	for(unsigned int i = 0; i < shapes.size(); i++) {
		ss << "\t** Shape " << (i+1) << ":" << endl
				<< "\t" << shapes[i]->to_string() << endl;
	}

	return ss.str();
}

ostream& operator<<(ostream& out, const Drawing& drw) {

    svg::Dimensions dimensions(drw.width, drw.height);
    svg::Document  doc(svg::Layout(dimensions, svg::Layout::TopLeft));

    for (vector<Shape*>::const_iterator it = drw.shapes.begin() ; it != drw.shapes.end(); ++it) {
    	(*it)->write_to_svg(doc);
    }
    
    out << doc.toString();

	return out;
}
