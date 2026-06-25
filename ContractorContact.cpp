//===========================================================================
// File Name : ContractorContact
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Definition for ContractorContact class.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260530     1.0         000         Zachary Rowson    Initial version
//===========================================================================

#include "ContractorContact.h"

std::string ContractorContact::DEFAULT_COMPANY{ "N/A" };
int ContractorContact::DEFAULT_ASSIGN_DURATION{ 0 };

// constructors and destructor
ContractorContact::ContractorContact() :
	Contact(),
	company(ContractorContact::DEFAULT_COMPANY),
	assign_duration(ContractorContact::DEFAULT_ASSIGN_DURATION)
{}
ContractorContact::ContractorContact(
	std::string first_name,
	std::string last_name,
	std::string business_phone,
	std::string email,
	int location,
	std::string company,
	int assign_duration
) :
	Contact(first_name, last_name, business_phone, email, location),
	company(company),
	assign_duration(assign_duration)
{}
ContractorContact::~ContractorContact() {}

// accessors
std::string ContractorContact::get_company() const {
	return company;
}
int ContractorContact::get_assign_duration() const {
	return assign_duration;
}

// mutators
int ContractorContact::set_company(std::string company) {
	this->company = company;
	return 0;
}
int ContractorContact::set_assign_duration(int assign_duration) {
	this->assign_duration = assign_duration;
	return 0;
}

// behavior functions
void ContractorContact::ShowContact() const {
	std::ios::fmtflags old_flags = std::cout.flags();

	std::cout <<
		std::left <<
		std::setw(20) << name <<
		std::setw(2) << assign_duration <<
		std::setw(23) << " months (contractor)" <<
		std::setw(25) << company <<
		"Room " << std::setw(5) << location <<
		std::setw(17) << business_phone <<
		std::setw(15) << email <<
		std::endl;

	std::cout.flags(old_flags);

	return;
}