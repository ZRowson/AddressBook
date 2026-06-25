//===========================================================================
// File Name : ContactList.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Linked list for storing, searching for, and displaying
//     Contact objects.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260530     1.0			000         Zachary Rowson    Initial version
//===========================================================================

#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "EmployeeContact.h"
#include "ContractorContact.h"

class ContactList {
private:
	Contact* head;
public:
	ContactList();
	~ContactList();

	int Init();
	void ShowAllContacts() const;
	void SearchByName(const Name& name) const;
	void SearchByDepartment(std::string department) const;
private:
	int Insert(Contact* new_contact);
	Contact* FindContact(const Name& name) const;
};

#endif
