#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
using namespace std;
class FilesHelper
{
public:
	static void saveLast(string fileName, int id) {
		fstream file(fileName, ios::out);
		if (file.is_open()) {
			file << id;
			file.close();
		}
		else {
			cerr << "Can not save last ID to " << fileName << endl;
		}
	}

	static int getLast(string fileName) {
		ifstream file(fileName);
		int lastId{};
		if (file.is_open()) {
			file >> lastId;
			file.close();
		}
		else {
			cerr << "Can not get last ID from " << fileName<<endl;
		}
		return lastId;
	}

	static void saveClient(Client c) {
		fstream file("Clients.txt", ios::out | ios::app);
		if (file.is_open()) {
			file << c.getId() << "|" << c.getName() << "|" << c.getPassword() << "|" << c.getBalance()<<endl;
			file.close();
		}
		else {
			cerr << "Can not saving client to Clients.txt" << endl;
		}
		
	}

	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		fstream file(fileName, ios::out | ios::app);
		if (file.is_open()) {
			file << e.getId() << "|" << e.getName() << "|" << e.getPassword() << "|" << e.getSalary()<<endl;
			file.close();
			saveLast(lastIdFile, e.getId());
		}
		else {
			cerr << "Can not saving employee to " << fileName << endl;
		}
	}

	static vector<Client> getClients() {
		vector<Client> Clients;
		ifstream file("Clients.txt");
		string line;
		while (getline(file, line)) {
			Client client = Parser::parseToClient(line);
			Clients.push_back(client);
		}
		return Clients;
	}

	static vector<Employee> getEmployees() {
		vector<Employee> Employees;
		ifstream file("Employees.txt");
		string line;
		while (getline(file, line)) {
			Employee employee = Parser::parseToEmployee(line);
			Employees.push_back(employee);
		}
		return Employees;
	}


	static vector<Admin> getAdmins() {
		vector<Admin> Admins;
		ifstream file("Admins.txt");
		string line;
		while (getline(file, line)) {
			Admin admin = Parser::parseToAdmin(line);
			Admins.push_back(admin);
		}
		return Admins;
	}

	static void clearFile(string fileName, string lastIdFile) {
		fstream file(fileName, ios::out);
		if (file.is_open()) {
			file.close();
		}
		else {
			cerr << "Can not clear the file " << fileName<<endl;
		}
		saveLast(lastIdFile, 0);
	}
};

