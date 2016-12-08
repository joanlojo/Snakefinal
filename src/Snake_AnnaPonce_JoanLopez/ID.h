#pragma once
#include <iostream>

enum class ObjectID : const int {
	S_00, //background
	S_01, //Play
	S_02 //Exit
};
inline std::ostream &operator<<(std::ostream &os, const ObjectID &id) { return os << int(id); };
inline std::istream &operator>>(std::istream &is, ObjectID &id) { return is >> reinterpret_cast<int&>(id); };