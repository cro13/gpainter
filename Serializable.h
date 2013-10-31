
#ifndef _SERIALIZABLE_H
#define _SERIALIZABLE_H

#include <iostream>
#include <string>
using namespace std;

class Serializable {

public:
	virtual string to_string() const=0;
	virtual ~Serializable() {}
};

inline std::ostream& operator<<(std::ostream& os, const Serializable& obj)
{
  cout << obj.to_string() << endl;
  return os;
}

#endif
