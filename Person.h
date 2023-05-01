#pragma once
#include <string>
using namespace std;

class Person {

protected:
	string name;
	int id;
	int age;

	struct Appointment {
		int hours;
		int mins;
	};

public:
	
	Person();

	void setName(string name_S);
	void setID(int id_S);
	void setAge(int age_S);

	string getName() const;
	int getID() const;
	int getAge() const;
	virtual void printinfo() const=0;


};


















