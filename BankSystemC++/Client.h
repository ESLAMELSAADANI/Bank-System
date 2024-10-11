#pragma once
#include <iostream>
#include <string>
#include "Validation.h"
#include "Person.h"
using namespace std;
class Client:public Person
{
private:
	double balance;
public:
	//Constructors
	Client() {
		this->balance = 0.0;
	}
	Client(int id,string name,string password,double balance):Person(id,name,password) {
		setBalance(balance);
	}
	//Setters
	void setBalance(double balance){
		if (Validation::validateBalance(balance)) {
			this->balance = balance;
		}
		else {
			cout << "Invalid Balance\n";
		}
	}
	//Getters
	double getBalance() {
		return this->balance;
	}
	//Methods
	void deposit(double amount) {
		if (amount > 0) {
			this->balance = balance + amount;
		}
	}
	void withdraw(double amount) {
		if (amount <= balance && amount > 0) {
			this->balance -= amount;
		}
	}
	void transferTo(double amount, Client& recipient) {
		withdraw(amount);
		recipient.deposit(amount);
	}
	void checkBalance() {
		cout << "Your Balance is " << this->balance<<endl;
	}
	void displayInfo() {
		cout << "======== Data of Client " << getName() << " ========\n";
		cout << "Id : " << this->getId() << endl;
		cout << "Name : " << this->getName() << endl;
		cout << "Balance : " << this->getBalance() << endl;
		cout << "=======================================================================\n";

	}

};
