//===========================================================================
// File Name : Contact.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Declaration for abstract class Contact. Implemented by
//    EmployeeContact and ContractorContact classes.
// Disclaimer:
// Revision History:
// Date       Version     Change ID   Author            Comment
// 20260529   1.0         000         Zachary Rowson    Initial version
//===========================================================================

#ifndef CONTACT_H
#define CONTACT_H

#include "Name.h"

class Contact {
public:
	static std::string DEFAULT_BUSINESS_PHONE;
	static std::string DEFAULT_EMAIL;
	static int DEFAULT_LOCATION;
private:
	Contact* next;
protected:
	Name name;
	std::string business_phone;
	std::string email;
	int location;
public:
	Contact();
	Contact(
		std::string first_name,
		std::string last_name,
		std::string business_phone,
		std::string email,
		int location
	);
	virtual ~Contact();

	Contact* get_next() const;
	const Name& get_name() const;
	std::string get_business_phone() const;
	std::string get_email() const;
	int get_location() const;

	int set_next(Contact* next);
	int set_name(std::string first_name, std::string last_name);
	int set_business_phone(std::string business_phone);
	int set_email(std::string email);
	int set_location(int location);

	virtual void ShowContact() const = 0;
};

#endif
