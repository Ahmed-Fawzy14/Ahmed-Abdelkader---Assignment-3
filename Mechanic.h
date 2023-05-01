#pragma once
#include "Person.h"
#include "Customer.h"

class mechanic :public Person {
private:
	int counter;
	Appointment* booked = new Appointment;

public:
	//mechanic();
	bool isAvailable(const Appointment& a);

	void setCounter(int c);
	int getCounter() const;

	void setBooked(customer c);
	Appointment getBooked() const;
	virtual void printinfo() const;



};
