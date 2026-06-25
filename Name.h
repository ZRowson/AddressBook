//===========================================================================
// File Name : Name.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Declaration for Name class which holds first and last name
//     information and provides operators for comparison and output.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260519     1.0         000         Zachary Rowson    Initial version
//===========================================================================

#ifndef NAME_H
#define NAME_H

#include <string>
#include <iostream>

class Name {
public:
	static std::string DEFAULT_FIRST_NAME;
	static std::string DEFAULT_LAST_NAME;
private:
	std::string first_name;
	std::string last_name;
public:
	Name();
	Name(std::string first_name, std::string last_name);
	~Name();

	std::string get_first_name() const;
	std::string get_last_name() const;
	int set_first_name(std::string first_name);
	int set_last_name(std::string last_name);

	bool operator==(const Name& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Name& name);
};
#endif