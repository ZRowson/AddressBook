//===========================================================================
// File Name : AddressBook.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Provides an interface for users to work with a ContactList
//     object. Contains methods for adding, searching for, and displaying
//     contacts.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260530     1.0         000         Zachary Rowson    Initial version
//===========================================================================

#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "ContactList.h"

class AddressBook {
public:
	static std::string DEFAULT_COMPANY_NAME;
private:
	std::string company_name;
	bool running; // adding running state, contolled by Run() and Quit()
	ContactList contact_list;
public:
	AddressBook();
	AddressBook(std::string company_name);
	~AddressBook();

	int Init();
	int Run();
private:
	void Menu() const;
	int GetUserOption() const;
	void ShowAllContacts() const;
	void SearchByName() const;
	void SearchByDepartment() const;
	int Quit();
};
#endif
