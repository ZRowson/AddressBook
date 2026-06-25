//===========================================================================
// File Name : ContactList.cpp
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Definition for ContactList class.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260531     1.0         000         Zachary Rowson    Initial version
//===========================================================================

#include "ContactList.h"

// constructor and destructor
ContactList::ContactList() : head(nullptr) {}
ContactList::~ContactList() {
	Contact* p_node{ head };
	while (p_node != nullptr) {
		Contact* p_next{ p_node->get_next() };
		delete p_node;
		p_node = p_next;
	}
}

// behavior functions
int ContactList::Init() {
	int error_sum{ 0 };

	error_sum += Insert(
		new EmployeeContact(
			"David",
			"Summer",
			"1-408-790-1682",
			"davids@tpcommuniations",
			23,
			"Software Engineer",
			"Engineering"
		)
	);
	error_sum += Insert(
		new EmployeeContact(
			"Jennifer",
			"Hans",
			"1-408-790-2381",
			"jenniferh@tpcommuniations",
			17,
			"HR Representative",
			"Human Resources"
		)
	);
	error_sum += Insert(
		new ContractorContact(
			"Cindy",
			"Morgan",
			"1-408-790-3953",
			"cindym@tpcommuniations",
			43,
			"TK Consultings",
			12
		)
	);
	error_sum += Insert(
		new EmployeeContact(
			"Marcus",
			"Reynolds",
			"1-408-790-4721",
			"marcusr@tpcommunications",
			31,
			"Product Manager",
			"Product"
		)
	);
	error_sum += Insert(
		new ContractorContact(
			"Sophia",
			"Patel",
			"1-408-790-5839",
			"sophiap@tpcommunications",
			28,
			"Apex Solutions",
			35
		)
	);
	error_sum += Insert(
		new EmployeeContact(
			"Daniel",
			"Kowalski",
			"1-408-790-6174",
			"danielk@tpcommunications",
			52,
			"Financial Analyst",
			"Finance"
		)
	);
	error_sum += Insert(
		new ContractorContact(
			"Rachel",
			"Thornton",
			"1-408-790-7263",
			"rachelt@tpcommunications",
			19,
			"Bridgepoint Consulting",
			27
		)
	);
	error_sum += Insert(
		new EmployeeContact(
			"Kevin",
			"Nakamura",
			"1-408-790-8345",
			"kevinn@tpcommunications",
			44,
			"Systems Architect",
			"Engineering"
		)
	);
	error_sum += Insert(
		new EmployeeContact(
			"Laura",
			"Fitzpatrick",
			"1-408-790-9512",
			"lauraf@tpcommunications",
			37,
			"Marketing Specialist",
			"Marketing"
		)
	);
	error_sum += Insert(
		new ContractorContact(
			"Omar",
			"Hassan",
			"1-408-790-1047",
			"omarh@tpcommunications",
			61,
			"Vertex Technologies",
			18
		)
	);
	error_sum += Insert(
		new EmployeeContact(
			"Natalie",
			"Chambers",
			"1-408-790-2938",
			"nataliec@tpcommunications",
			25,
			"UX Designer",
			"Design"
		)
	);
	error_sum += Insert(
		new ContractorContact(
			"Brian",
			"Gallagher",
			"1-408-790-3716",
			"briang@tpcommunications",
			48,
			"Pinnacle Group",
			42
		)
	);
	error_sum += Insert(
		new EmployeeContact(
			"Yasmine",
			"Carter",
			"1-408-790-4829",
			"yasminec@tpcommunications",
			33,
			"Data Scientist",
			"Analytics"
		)
	);
	error_sum += Insert(
		new ContractorContact(
			"Patrick",
			"Sullivan",
			"1-408-790-5163",
			"patricks@tpcommunications",
			56,
			"Crestline Staffing",
			9
		)
	);
	error_sum += Insert(
		new EmployeeContact(
			"Angela",
			"Morrison",
			"1-408-790-6487",
			"angelam@tpcommunications",
			41,
			"Operations Manager",
			"Operations"
		)
	);
	error_sum += Insert(
		new ContractorContact(
			"Tyler",
			"Nguyen",
			"1-408-790-7954",
			"tylern@tpcommunications",
			22,
			"Ironclad Enterprises",
			31
		)
	);

	return error_sum;
}
void ContactList::ShowAllContacts() const {
	Contact* p_node{ head };
	while (p_node != nullptr) {
		p_node->ShowContact();
		p_node = p_node->get_next();
	}
	return;
}
void ContactList::SearchByName(const Name& name) const {
	Contact* p_found_node{ FindContact(name) };

	if (p_found_node != nullptr) {
		p_found_node->ShowContact();
		return;
	}
	std::cout << "*** contact " << name << " not found ***" << std::endl;
	return;
}
void ContactList::SearchByDepartment(std::string department) const {
	Contact* p_node{ head };
	while (p_node != nullptr) {
		EmployeeContact* p_employee = dynamic_cast<EmployeeContact*>(p_node);
		if (p_employee != nullptr && p_employee->get_department() == department) {
			p_employee->ShowContact();
		}
		p_node = p_node->get_next();
	}

	return;
}

//helper functions
int ContactList::Insert(Contact* new_contact) {
	new_contact->set_next(head);
	head = new_contact;
	return 0;
}
Contact* ContactList::FindContact(const Name& name) const {
	Contact* p_node{ head };
	while (p_node != nullptr) {
		if (p_node->get_name() == name) {
			return p_node;
		}
		p_node = p_node->get_next();
	}

	return nullptr;
}