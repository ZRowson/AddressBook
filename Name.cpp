//===========================================================================
// File Name : Name.cpp
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Definition for Name class.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260530     1.0         000         Zachary Rowson    Initial version
//===========================================================================

#include "Name.h"

std::string Name::DEFAULT_FIRST_NAME{ "N/A" };
std::string Name::DEFAULT_LAST_NAME{ "N/A" };

// constructors and destructor
Name::Name() :
	first_name(Name::DEFAULT_FIRST_NAME),
	last_name(Name::DEFAULT_LAST_NAME)
{};
Name::Name(std::string first_name, std::string last_name) :
	first_name(first_name),
	last_name(last_name)
{};
Name::~Name() {};

// accessors
std::string Name::get_first_name() const {
	return first_name;
}
std::string Name::get_last_name() const {
	return last_name;
}

// mutators
int Name::set_first_name(std::string first_name) {
	this->first_name = first_name;
	return 0;
}
int Name::set_last_name(std::string last_name) {
	this->last_name = last_name;
	return 0;
}

// operators
bool Name::operator==(const Name& other) const {
	return first_name == other.first_name && last_name == other.last_name;
}
std::ostream& operator<<(std::ostream& os, const Name& name) {
	os << name.first_name + " " + name.last_name;
	return os;
}