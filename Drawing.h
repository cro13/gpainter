/*
 * Drawing.h
 *
 *  Created on: Mar 5, 2013
 *      Author: vinicius
 */

#ifndef _DRAWING_H
#define _DRAWING_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Color.h"
#include "Shape.h"
#include "Serializable.h"

#include "simple_svg_1.0.0.hpp"

class Drawing : public Serializable {
private:

	vector<Shape*> shapes;

public:
	int width;
	int height;

	void add_shape(Shape *shape);

	void show_in_firefox();

	void save_to_file(const string& file_name);

	virtual string to_string() const;

	friend ostream& operator<<(ostream& out, const Drawing& drw);

};

#endif /* _DRAWING_H */
