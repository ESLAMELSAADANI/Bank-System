#pragma once
#include <string>
#include "Validation.h"
using namespace std;
class Person:public Validation
{
protected:
	//Attributes
	int id;
	string name,password;
public:
	Person() {
		this->id = 0;
		this->name = "";
		this->password = "";
	}
	//Constructors
	Person(int id,string name, string password) {
		setId(id);
		setName(name);
		setPassword(password);
	}
	//Setters
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		if (Validation::validateName(name)) {
			this->name = name;
		}
		else {
			cout << "Invalid Name\n";
		}
	}
	void setPassword(string password) {
		if (Validation::validatePassword(password)) {
			this->password = password;
		}
		else {
			cout << "Invalid Password\n";
		}
	}
	//Getters
	int getId() {
		return this->id;
	}
	string getName() {
		return this->name;
	}
	string getPassword() {
		return this->password;
	}
	//Methods
	virtual void displayInfo() = 0;
};

