//===========================================================================
// File Name : Contact.cpp
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Definition for Contact class.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author			  Comment
// 20260530     1.0         000         Zachary Rowson    Initial version
//===========================================================================

#include "Contact.h"

std::string Contact::DEFAULT_BUSINESS_PHONE{ "1-555-555-5555" };
std::string Contact::DEFAULT_EMAIL{ "xxx@xxx.xxx" };
int Contact::DEFAULT_LOCATION{ 0 };

// constructors and destructor
Contact::Contact() :
	next(nullptr),
	name(Name{}),
	business_phone(Contact::DEFAULT_BUSINESS_PHONE),
	email(Contact::DEFAULT_EMAIL),
	location(Contact::DEFAULT_LOCATION)
{}
Contact::Contact(
	std::string first_name,
	std::string last_name,
	std::string business_phone,
	std::string email,
	int location
) :
	next(nullptr),
	name(Name{ first_name, last_name }),
	business_phone(business_phone),
	email(email),
	location(location)
{}
Contact::~Contact() {
	std::cout << name << " has gone home..." << std::endl;
}

// accessors
Contact* Contact::get_next() const {
	return next;
}
const Name& Contact::get_name() const {
	return name;
}
std::string Contact::get_business_phone() const {
	return business_phone;
}
std::string Contact::get_email() const {
	return email;
}
int Contact::get_location() const {
	return location;
}

// mutators
int Contact::set_next(Contact* next) {
	this->next = next;
	return 0;
}
int Contact::set_name(std::string first_name, std::string last_name) {
	return name.set_first_name(first_name) + name.set_last_name(last_name);
}
int Contact::set_business_phone(std::string business_phone) {
	this->business_phone = business_phone;
	return 0;
}
int Contact::set_email(std::string email) {
	this->email = email;
	return 0;
}
int Contact::set_location(int location) {
	this->location = location;
	return 0;
}