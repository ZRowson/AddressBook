//===========================================================================
// File Name : AddressBook.h
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : Definition for AddressBook class.
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260531     1.0         000         Zachary Rowson    Initial version
// 20260531     1.1         001         Zachary Rowson    Clearing input buffers and adding getline()
//===========================================================================

#include "AddressBook.h"

std::string AddressBook::DEFAULT_COMPANY_NAME{ "N/A" };

// constructors and destructor
AddressBook::AddressBook() :
	company_name(AddressBook::DEFAULT_COMPANY_NAME),
	running(false),
	contact_list(ContactList())
{}
AddressBook::AddressBook(std::string company_name) :
	company_name(company_name),
	running(false),
	contact_list(ContactList())
{}
AddressBook::~AddressBook() {}

// behavior functions
int AddressBook::Init() {
	return contact_list.Init();
}
int AddressBook::Run() {
	running = true; // adjust object state
	do {
		Menu();
		switch (GetUserOption()) {
		case 1:
			ShowAllContacts();
			break;
		case 2:
			SearchByName();
			break;
		case 3:
			SearchByDepartment();
			break;
		case 4:
			Quit(); // will adjust running state
			break;
		default:
			break;
		}
	} while (running);

	return 0;
}

// helper functions
void AddressBook::Menu() const {
	std::ios::fmtflags old_flags = std::cout.flags();

	std::cout << std::left;
	std::cout <<
		'\n' << company_name << " Address Book Menu" << '\n' <<
		"1. View all contacts" << '\n' <<
		"2. Search by name" << '\n' <<
		"3. Search by department" << '\n' <<
		"4. Quit" <<
		std::endl;

	std::cout.flags(old_flags);

	return;
}
int AddressBook::GetUserOption() const {
	int user_option{};
	bool cin_fail{ false };
	
	std::cout << "\nSelect an option (1-4): ";
	std::cin >> user_option;
	std::cout << std::endl;

	if (cin_fail = std::cin.fail()) {
		std::cin.clear();
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (user_option > 4 || user_option < 1 || cin_fail) {
		std::cout << "*** please select an integer 1-4 ***" << std::endl;
		return -1;
	}

	return user_option;
}
void AddressBook::ShowAllContacts() const {
	contact_list.ShowAllContacts();
	return;
}
void AddressBook::SearchByName() const {
	std::string first_name{};
	std::string last_name{};
	
	std::cout << "Enter a contact first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Enter a contact last name: ";
	std::getline(std::cin, last_name);
	std::cout << std::endl;

	Name name{ first_name, last_name };
	contact_list.SearchByName(name);
	
	return;
}
void AddressBook::SearchByDepartment() const {
	std::string department{};

	std::cout << "Enter a department: ";
	std::getline(std::cin, department);
	std::cout << std::endl;

	contact_list.SearchByDepartment(department);

	return;
}
int AddressBook::Quit() {
	std::cout <<
		"\nThank you for using the " << company_name << " address book" << std::endl;
	running = false; // adjust object state

	return 0;
}