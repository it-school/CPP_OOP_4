#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string fullName; // Full Name
	tm* birthday;	 // 1.1.2000
	string address;  // Odessa
	string phone;	 // +xx (xxx) xxx-xx-xx
	tm* registrationDate;
public:
	string getFullName()
	{
		return this->fullName;
	}	
	void setFullName(string fullName)
	{
		this->fullName = fullName;
	}

	tm* getBirthday()
	{
		return this->birthday;
	}
	void setBirthday(tm* birthday)
	{
		this->birthday = birthday;
	}

	string getAddress()
	{
		return this->address;
	}
	void setAddress(string address)
	{
		this->address = address;
	}

	string getPhone()
	{
		return this->phone;
	}
	void setPhone(string phone)
	{
		this->phone = phone;
	}

	tm* getRegistrationDate()
	{
		return this->registrationDate;
	}

	string toString()
	{
		string result = "\n";
		char time[11];

		strftime(time, 11, "%d.%m.%Y", this->birthday);
		result.append("Name: " + this->getFullName() + "\n");
		result.append("Address: " + this->getAddress() + "\n");
		result.append("Birthday: " + string(time) + "\n");
		result.append("Phone: " + this->getPhone() + "\n");
		strftime(time, 11, "%d.%m.%Y", this->getRegistrationDate());
		result.append("Registration date: " + string(time) + "\n");
/*		
		result.append("Registration date: " + to_string(this->getRegistrationDate()->tm_mday));
		result.append("." + to_string(this->getRegistrationDate()->tm_mon + 1));
		result.append("." + to_string(this->getRegistrationDate()->tm_year + 1900));
*/
		return result;
	}

	Person()
	{
		this->setFullName("Anonymous");
		this->setAddress("Odessa");
		this->setPhone("+38(0xx) xxx-xx-xx");
		this->birthday = new tm;

		tm* birthday = new tm();
		birthday->tm_mday = 1;
		birthday->tm_mon = 0;
		birthday->tm_year = 100;
		this->setBirthday(birthday);

		const time_t timer = time(NULL);
		tm* currentDate = new tm();
		localtime_s(currentDate, &timer);
		this->registrationDate = currentDate;
	}

	Person(string fullName, unsigned short day, unsigned short month, unsigned short year, string address, string phone)
	{
		this->setFullName(fullName);
		this->setAddress(address);
		this->setPhone(phone);

		tm* birthday = new tm();
		birthday->tm_mday = day;
		birthday->tm_mon = month - 1;
		birthday->tm_year = year - 1900;

		this->setBirthday(birthday);

		const time_t timer = time(NULL);
		tm* currentDate = new tm;
		localtime_s(currentDate, &timer);
		this->registrationDate = currentDate;
	}
};

int main()
{
	cout << "Practice\n";

	Person person;
	person.setFullName("Alex Yustasu");
	cout << person.toString();

	Person person1("Cho Ne Spish", 12, 12, 1992, "China", "(303) 743-9777");
	cout << person1.toString();	
}