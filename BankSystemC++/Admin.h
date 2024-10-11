#pragma once
#include "Employee.h"
class Admin:public Employee
{
public:
	//constructors
	Admin() :Employee(){

	}
	Admin(int id,string name,string password,double salary):Employee(id,name,password,salary) {

	}
	//Methods
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
	void addEmployee(Employee& employee) {
		FilesHelper::saveEmployee("Employees.txt", "LastEmployeeId.txt", employee);
	}
	Employee* searchEmployee(int id) {
		vector<Employee> employees = FilesHelper::getEmployees();
		for (auto& employee : employees) {
			if (employee.getId() == id) {
				return &employee;
			}
		}
		return nullptr;
	}
	Employee* searchEmployee(int id) {
		vector<Employee> employees = FilesHelper::getEmployees();
		for (auto& employee : employees) {
			if (employee.getId() == id) {
				return &employee;
			}
		}
		return nullptr;
	}
	void editEmployee(int id, string name, string password, double salary) {
		vector<Employee> employees = FilesHelper::getEmployees();
		for (auto& employee : employees) {
			if (employee.getId() == id) {
				employee.setName(name);
				employee.setPassword(password);
				employee.setSalary(salary);
			}
		}
	}
	void listEmployee() {
		vector<Employee> employees = FilesHelper::getEmployees();
		for (auto& employee : employees) {
			employee.displayInfo();
		}
	}
	void displayInfo() {
		cout << "======== data of Admin " << getName() << " ========\n";
		cout << "name : " << getName() << endl;
		cout << "password : " << getPassword() << endl;
		cout << "salary : " << getSalary() << endl;
		cout << "=======================================================================\n";
	}
};

