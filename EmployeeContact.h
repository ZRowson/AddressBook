//===========================================================================
// File Name : EmployeeContact.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Declaration for EmployeeContact class, an implementation of
//     abstract base class, Contact. 
// Disclaimer:
// Revision History:
// Date       Version     Change ID   Author            Comment
// 20260529   1.0         000         Zachary Rowson    Initial version
//===========================================================================

#ifndef EMPLOYEECONTACT_H
#define EMPLOYEECONTACT_H

#include "Contact.h"
#include <iomanip>

class EmployeeContact : public Contact {
public:
	static std::string DEFAULT_TITLE;
	static std::string DEFAULT_DEPARTMENT;
private:
	std::string title;
	std::string department;
public:
	EmployeeContact();
	EmployeeContact(
		std::string first_name,
		std::string last_name,
		std::string business_phone,
		std::string email,
		int location,
		std::string title,
		std::string department
	);
	virtual ~EmployeeContact();

	std::string get_title() const;
	std::string get_department() const;

	int set_title(std::string title);
	int set_department(std::string department);

	virtual void ShowContact() const;
};

#endif
