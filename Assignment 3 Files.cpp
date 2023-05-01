
// Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include<iostream>
#include "Customer.h"
#include "Person.h"
#include "Mechanic.h"
#include "Queue.h"
using namespace std;


Person::Person() : name({}), id(0), age(0) {}

void Person::setID(int id_S) {
	id = id_S;
}

void Person::setName(string name_S) {
	name = name_S;
}

void Person::setAge(int age_S) {
	age = age_S;
}

int Person::getID() const {
	return id;
}

int Person::getAge() const {
	return age;
}

string Person::getName() const {
	return name;
}



void customer::setMechanicID(int mID) {
	MechanicID = mID;
}

double customer::getMechanicID() const {
	return MechanicID;
}

void customer::setAppointment(int h, int m) {
	cust_Mech.hours = h;
	cust_Mech.mins = m;
}




customer::Appointment customer::getAppointment() const
{
	customer customer1;
	customer1.cust_Mech;
	return cust_Mech;
}


bool operator == (const customer& a, const customer& b) {
	if ((a.getAppointment().hours == b.getAppointment().hours) && (a.getAppointment().mins == b.getAppointment().mins))
		return 1;
	else
		return 0;
}


bool operator > (const customer& a, const customer& b) {
	if ((a.getAppointment().hours > b.getAppointment().hours) && (a.getAppointment().mins > b.getAppointment().mins))
		return 1;
	else
		return 0;
}

bool operator < (const customer& a, const customer& b) {
	if ((a.getAppointment().hours < b.getAppointment().hours) && (a.getAppointment().mins < b.getAppointment().mins))
		return 1;
	else
		return 0;
}



void customer::printinfo() const
{
	cout << "Name: " << getName() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Age: " << getAge() << endl;
}




void mechanic::setCounter(int c) {
	counter = c;
}

int mechanic::getCounter() const {
	return counter;
}



bool mechanic::isAvailable(const Appointment& a) {
	int timeH = a.hours + (a.mins) / 60;

	for (int i = 0; i < counter; i++) {
		if (timeH == booked[i].hours)
			return false;
		else
			return true;
	}
}

void mechanic::setBooked(customer c) {
	if (isAvailable(c.getAppointment())) {
		booked->hours = c.getAppointment().hours;
		booked->mins = c.getAppointment().mins;
	}
	else
		cout << c.getAppointment().hours << " : " << c.getAppointment().mins << " is not available" << endl;

}


mechanic::Appointment mechanic::getBooked() const {
	return *booked;
}

void assignAppointFiles(const customer& g, const mechanic& m) {
	string x;
	ofstream infile;
	infile.open("queue.txt");
	infile << "Mr. Ahmed has an appoitmnet at 13:00 with Khaled \t";
	infile << "Mrs. Sara has an appoitmnet at 12:00 with Ayman \t";
	infile << "Mr. Mohammed has an appoitmnet at 13:00 with Mai \t";
	infile << "Mr. Karim has an appoitmnet at 13:00 with Khaled \t";
	infile.close();
	ifstream out;
	out.open("queue.txt");
	getline(out, x);
	cout << x;



}

void mechanic::printinfo() const
{
	cout << "Name: " << getName() << endl;
	cout << "ID: " << getID() << endl;
	cout << "Age: " << getAge() << endl;
}

template <typename T>
Queue<T>::Queue() {
	front = 0;
	rear = 0;
}
template <typename T>
bool Queue<T>::isEmpty() {
	if (rear == -1)
		return true;
	else
		return false;
}
template <typename T>
bool Queue<T>::isFull() {
	if (rear == 99)
		return true;
	else
		return false;
}
template <typename T>
void Queue<T>::push(T x)
{
	if (isFull()) {
		cout << "Queue is full\n";
	}
	else if (isEmpty()) {
		front = rear = 0;
	}
	else {
		rear++;
	}
	q[rear] = x;
}

template <typename T>
void Queue<T> ::pop() {
	if (isEmpty()) {
		cout << "Queue is empty\n";
	}
	else {
		front++;
	}
}

template <typename T>
void Queue<T> ::printQueue() {
	if (isEmpty()) {
		cout << "Queue is empty\n";
		return;
	}
	for (int i = front; i <= rear; i++) {
		cout << q[i] << " ";
	}
	cout << endl;
}







int main()
{

	customer* c = new customer;
	customer* c1 = new customer;
	customer* c2 = new customer;
	customer* c3 = new customer;
	customer* b = new customer;
	mechanic* m = new mechanic;
	mechanic* m1 = new mechanic;
	mechanic* m2 = new mechanic;
	Queue<customer> q;



	m->setName("Ayman");
	m->setAge(30);
	m->setID(11);

	m1->setName("Khaled");
	m1->setAge(35);
	m1->setID(22);

	m2->setName("Mai");
	m2->setAge(22);
	m2->setID(33);

	c->setName("Ahmed");
	c->setAge(18);
	c->setID(111);
	c->setAppointment(12, 00);
	c->setMechanicID(m->getID());
	q.push(*c);



	c1->setName("Sara");
	c1->setAge(20);
	c1->setID(113);
	c1->setAppointment(16, 00);
	c1->setMechanicID(m1->getID());
	q.push(*c1);

	assignAppointFiles(*c1, *m1);


	c2->setName("Karim");
	c2->setAge(25);
	c2->setID(113);
	c2->setAppointment(15, 00);
	c2->setMechanicID(m2->getID());
	q.push(*c2);

	c3->setName("Mohammed");
	c3->setAge(35);
	c3->setID(114);
	c3->setAppointment(12, 00);
	c3->setMechanicID(m1->getID());
	q.push(*c2);



	delete c;
	delete c1;
	delete c2;
	delete m;
	delete m1;
	delete m2;







}
