#include <iostream>
#include <string>
using namespace std;


class bankAccount {
public:
	bankAccount(string name, string surname, float balance=0, string phone_number = "");
	bankAccount(const bankAccount& oth);
	~bankAccount();
	bool controlNameSurname(string nameOrSurname);
	bool controlPhoneNumber(string phoneNumber);
	void displayProfile();
	void credit(float);
	void withdraw(float);
	void sendMoney(bankAccount& othAccount, float amount);
	void setPersonName(string name);
	void setPersonSurname(string surname);
	void setPersonPhone(string phone);
	void setPersonBalance(float balance = 0);
	int getPersonBalance() const { return accountBalance; };
	string getPersonName()const { return personName; };
	string getPersonSurname() const { return personSurname; };
	string getPersonPhone() const { return personPhone; };
private:
	float accountBalance;
	string personName, personSurname, personPhone;
};



bankAccount::bankAccount(string name, string surname, float balance, string phone_number) {
	setPersonName(name);
	setPersonSurname(surname);
	setPersonPhone(phone_number);
	setPersonBalance(balance);
	cout << "Bank Account created" << endl;
}

bankAccount::~bankAccount() {
	cout << "Bank Account destroyed." << endl;
}

bankAccount::bankAccount(const bankAccount& othAccount) {
	personName = othAccount.personName;
	personSurname = othAccount.personSurname;
	personPhone = othAccount.personPhone;
	accountBalance = othAccount.accountBalance;
	cout << "Bank Account copied to target" << endl;
}

void bankAccount::setPersonName(string name) {
	while (!controlNameSurname(name)) {
		cout << "Invalid Name, please enter your name:";
		getline(cin, name);
	}
	personName = name;
}


void bankAccount::setPersonSurname(string surname) {
	while (!controlNameSurname(surname)) {
		cout << "Invalid Surname, please enter your surname:";
		getline(cin, surname);
	}
	personSurname = surname;
}

void bankAccount::setPersonPhone(string phone) {
	while (!controlPhoneNumber(phone)) {
		cout << "Invalid Phone-Number, please enter your phone-number:";
		getline(cin, phone);
	}
	personPhone = phone;
}

void bankAccount::setPersonBalance(float balance) {
	if (balance <= 0) {
		accountBalance = 0;
	}
	else {
		accountBalance = balance;
	}
}


bool bankAccount::controlNameSurname(string nameOrSurname) {
	for (unsigned i = 0; i < nameOrSurname.length(); i++) {
		if (!((nameOrSurname.at(i) >= 'A' && nameOrSurname.at(i) <= 'Z') || (nameOrSurname.at(i) >= 'a' && nameOrSurname.at(i) <= 'z'))){
			return false;
		}
	}
	return true;

}
bool bankAccount::controlPhoneNumber(string phoneNumber) {
	if (phoneNumber.empty()){
		return true;
	}
	if (phoneNumber.length() != 11) {
		return false;
	}
	for (unsigned i = 0; i < phoneNumber.length(); i++) {
		if (!(phoneNumber.at(i) >= '0' && phoneNumber.at(i) <= '9')) {
			return false;
		}
	}
	return true;
}

void bankAccount::credit(float amount) {
	while (amount <= 0) {
		cout << "Invalid amount; please enter valid amount:";
		cin >> amount;
	}
	accountBalance += amount;
}

void bankAccount::withdraw(float amount) {

	while (amount <= 0 || amount > accountBalance) {
		cout << "Invalid amount; please enter valid amount:";
		cin >> amount;
	}
	accountBalance -= amount;
}

void bankAccount::displayProfile() {
	cout << "--------------------------------" << endl;
	cout << "Name: " << personName << "\n" << "Surname: " << personSurname << endl;
	if (!personPhone.empty()) {
		cout << "Phone Number:" << personPhone << endl;
	}
	else {
		cout << "Phone Number: None" << endl;
	}
	cout << "Balance: " << accountBalance << endl;
}

void bankAccount::sendMoney(bankAccount &othAccount, float amount) {
	while (amount <= 0 || amount > accountBalance) {
		cout << "Invalid amount; please enter valid amount:";
		cin >> amount;
	}

	accountBalance -= amount;
	othAccount.accountBalance += amount;
}