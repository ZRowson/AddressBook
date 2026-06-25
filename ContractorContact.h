//===========================================================================
// File Name : ContractorContact.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Declaration for ContractorContact class, an implementation of
//     abstract base class, Contact.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author          Comment
// 20260530     1.0         000       Zachary Rowson    Initial version
//===========================================================================

#ifndef CONTRACTORCONTACT_H
#define CONTRACTORCONTACT_H

#include "Contact.h"
#include <iomanip>

class ContractorContact : public Contact {
public:
	static std::string DEFAULT_COMPANY;
	static int DEFAULT_ASSIGN_DURATION;
private:
	std::string company;
	int assign_duration;
public:
	ContractorContact();
	ContractorContact(
		std::string first_name,
		std::string last_name,
		std::string business_phone,
		std::string email,
		int location,
		std::string company,
		int assign_duration
	);
	virtual ~ContractorContact();

	std::string get_company() const;
	int get_assign_duration() const;

	int set_company(std::string company);
	int set_assign_duration(int assign_duration);
	
	virtual void ShowContact() const;
};

#endif
