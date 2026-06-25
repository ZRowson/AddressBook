//===========================================================================
// File Name : EmployeeContact.cpp
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Definition for EmployeeContact class.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260530     1.0         000         Zachary Rowson    Initial version
//===========================================================================

#include "EmployeeContact.h"

std::string EmployeeContact::DEFAULT_TITLE{ "N/A" };
std::string EmployeeContact::DEFAULT_DEPARTMENT{ "N/A" };

// constructors and destructor
EmployeeContact::EmployeeContact() :
	Contact(),
	title(EmployeeContact::DEFAULT_TITLE),
	department(EmployeeContact::DEFAULT_DEPARTMENT)
{}
EmployeeContact::EmployeeContact(
	std::string first_name,
	std::string last_name,
	std::string business_phone,
	std::string email,
	int location,
	std::string title,
	std::string department
) :
	Contact(first_name, last_name, business_phone, email, location),
	title(title),
	department(department)
{}
EmployeeContact::~EmployeeContact() {}

// accessors
std::string EmployeeContact::get_title() const {
	return title;
}
std::string EmployeeContact::get_department() const {
	return department;
}

// mutators
int EmployeeContact::set_title(std::string title) {
	this->title = title;
	return 0;
}
int EmployeeContact::set_department(std::string department) {
	this->department = department;
	return 0;
}

// behavior functions
void EmployeeContact::ShowContact() const {
	std::ios::fmtflags old_flags = std::cout.flags();

	std::cout <<
		std::left <<
		std::setw(20) << name <<
		std::setw(25) << title <<
		std::setw(25) << department <<
		"Room " << std::setw(5) << location <<
		std::setw(17) << business_phone <<
		std::setw(15) << email << 
		std::endl;

	std::cout.flags(old_flags);

	return;
}