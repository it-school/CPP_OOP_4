#include <iostream>
#include <string>

using namespace std;

tm* getCurrentDateTime()
{
	const time_t timer = time(NULL);
	tm* currentDate = new tm();
	localtime_s(currentDate, &timer);

	return currentDate;
}

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

	virtual string toString()
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

		this->registrationDate = getCurrentDateTime();
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

		this->registrationDate = getCurrentDateTime();
	}
};

class Student : public Person
{
private:
	string specialty;
	unsigned short yearIn;
public:
	void setSpecialty(string specialty)
	{
		this->specialty = specialty;
	}
	string getSpecialty()
	{
		return this->specialty;
	}

	void setYearIn(unsigned short setYearIn)
	{
		tm* currentDate = getCurrentDateTime();
		if (currentDate->tm_year >= this->yearIn)
			this->yearIn = setYearIn;
		else
			this->yearIn = currentDate->tm_year;
	}
	unsigned short getYearIn()
	{
		return this->yearIn;
	}

	virtual string toString()
	{
		string result = Person::toString();
		result.append("Specialty: " + this->getSpecialty() + "\n");
		result.append("Year of enter: " + to_string(this->getYearIn()) + "\n");

		return result;
	}

	Student() : Person()
	{
		this->setSpecialty("N/a");
		this->setYearIn(getCurrentDateTime()->tm_year + 1900);
	}

	Student(string fullName, unsigned short day, unsigned short month, unsigned short year, string address, string phone, string specialty, unsigned short yearIn) :
		Person(fullName, day, month, year, address, phone) {
		this->setSpecialty(specialty);
		this->setYearIn(yearIn);
	}
};

class Employee : public Person {
private :
	unsigned short yearIn;
	string department;

public:
	void setDepartment(string department)
	{
		this->department = department;
	}
	string getDepartment()
	{
		return this->department;
	}

	void setYearIn(unsigned short setYearIn)
	{
		tm* currentDate = getCurrentDateTime();
		if (currentDate->tm_year >= this->yearIn)
			this->yearIn = setYearIn;
		else
			this->yearIn = currentDate->tm_year;
	}
	unsigned short getYearIn()
	{
		return this->yearIn;
	}

	virtual string toString()
	{
		string result = Person::toString();
		result.append("Department: " + this->getDepartment() + "\n");
		result.append("Year of start work: " + to_string(this->getYearIn()) + "\n");

		return result;
	}

	Employee() : Person()
	{
		this->setDepartment("N/a");
		this->setYearIn(getCurrentDateTime()->tm_year + 1900);
	}

	Employee(string fullName, unsigned short day, unsigned short month, unsigned short year, string address, string phone, string department, unsigned short yearIn) :
		Person(fullName, day, month, year, address, phone) {
		this->setDepartment(department);
		this->setYearIn(yearIn);
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

	cout << "\n------------ Students --------------\n";
	Student student1;
	cout << student1.toString();
	/*	student1.setYearIn(2021);
		student1.setSpecialty("151");
	*/	

	Student student2("John Silver", 5, 10, 1746, "Bristol", "404 123-456-789", "151", 2020);
	cout << student2.toString();

	cout << "\n------------ Employees --------------\n";

	Employee employee1;
	cout << employee1.toString();

	Employee employee2("Billy Bons", 30, 11, 1742, "London", "404 223-356-745", "ICS", 2019);
	cout << employee2.toString();

	cout << "\n------------ University --------------\n";

	const int N = 5;
	Person* people = new Person[N];
	for (size_t i = 0; i < N; i++)
	{
		cout << people[i].toString();
	}

	cout << "\nAfter init:\n";

	people[0] = student1;
	people[1] = employee1;
	people[2] = person1;
	people[3] = student2;
	people[4] = (Employee)employee2;

	for (size_t i = 0; i < N; i++)
	{
		cout << people[i].toString();
	}
}