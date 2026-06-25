//===========================================================================
// File Name : main.cpp
// Author : Zachary Rowson
// Copyright : No touchy, no changey
// Description : main() function for Address Book program
// Disclaimer:
// Revision History:
// Date         Version     Change ID   Author            Comment
// 20260529     1.0         000         Zachary Rowson    Initial version
// 20260530     2.0         000         Zachary Rowson    Unit testing Name
// 20260530     3.0         000         Zachary Rowson    Unit testing EmployeeContact
// 20260530     4.0         000         Zachary Rowson    Unit testing ContractorContact
// 20260531     5.0         000         Zachary Rowson    Unit testing ContactList
// 20260531     6.0         000         Zachary Rowson    Unit testing AddressBook
// 20260531     7.0         000         Zachary Rowson    Final main
//===========================================================================

#include "AddressBook.h"

using namespace std;

int main() {
	AddressBook* p_address_book = new AddressBook{ "TP Communications" };
	p_address_book->Init();
	p_address_book->Run();

	delete p_address_book;

	return 0;
}