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



class customer: public Person {
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







class mechanic :public Person {
private:
	int counter;
	Appointment *booked = new Appointment;

public:
	//mechanic();
	bool isAvailable(const Appointment& a);

	void setCounter(int c);
	int getCounter() const;

	void setBooked(customer c);
	Appointment getBooked() const;
	virtual void printinfo() const;



};

template <typename T>
class Queue {
private:
    T q[100];
	int front;
    int rear;

public:
    Queue();

    bool isEmpty();

    bool isFull();
   

	void push(T x);

	void pop();

	void printQueue();
};
