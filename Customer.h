#pragma once
#include "Person.h"

class customer : public Person {
private:
	double MechanicID;
	Appointment cust_Mech;


public:

	void setMechanicID(int mID);
	double getMechanicID() const;

	void setAppointment(int h, int m);
	Appointment getAppointment() const;
	virtual void printinfo() const;

	string operator << (const customer& a);




};

bool operator == (const customer& a, const customer& b);


bool operator > (const customer& a, const customer& b);

bool operator < (const customer& a, const customer& b);