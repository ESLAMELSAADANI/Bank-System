#pragma once
#pragma once
#include <iostream>
#include <string>
#include "Client.h"
#include "person.h"
#include "validation.h"
using namespace std;
class Employee:public Person
{
protected:
	//attributes
	double salary;
public:
	//constructors
	Employee():Person() {
		this->salary=0.0;
	}
	Employee(int id,string name,string password,double salary):Person(id,name,password) {
		setSalary(salary);
	}
	//setters
	void setSalary(double salary) {
		if (Validation::validateSalary(salary)) {
			this->salary = salary;
		}
		else {
			cout << "Invalid Salary\n";
		}
	}
	//getters
	double getSalary() {
		return this->salary;
	}
	//methods
	void addClient(Client& c) {
		FilesHelper::saveClient(c);
	}
	Client* searchClient(int id) {
		vector<Client> clients = FilesHelper::getClients();
		for (auto& client : clients) {
			if (client.getId() == id) {
				return &client;
			}
		}
		return nullptr;
	}
	void listClient() {
		vector<Client> clients = FilesHelper::getClients();
		for (auto& client : clients) {
			client.displayInfo();
		}
	}
	void editClient(int id, string name, string password, double balance) {
		vector<Client> clients = FilesHelper::getClients();
		for (auto& client : clients) {
			if (client.getId() == id) {
				client.setName(name);
				client.setPassword(password);
				client.setBalance(balance);
				//Save updated clients back to file
				FilesHelper::clearFile("Client.txt", "LastClientId.txt");
				for (const auto& c : clients) {
					FilesHelper::saveClient(c);
				}
				break;// Exit once the client is edited
			}
		}
	}
	void displayInfo() {
		cout << "======== data of employee " << getName() << " ========\n";
		cout << "name : " << getName() << endl;
		cout << "password : " << getPassword() << endl;
		cout << "salary : " << getSalary() << endl;
		cout << "=======================================================================\n";

	}

};

