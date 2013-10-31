
#ifndef _COLOR_H
#define _COLOR_H

#include <string>
using namespace std;

#include "Serializable.h"

class Color : public Serializable {
public:

	int red;
	int green;
	int blue;

	void set_by_name(const string& colorname);

	virtual string to_string() const;
};

#endif
