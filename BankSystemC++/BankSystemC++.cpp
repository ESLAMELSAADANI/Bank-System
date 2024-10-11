// BankSystemC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Validation.h"
#include "Admin.h"
#include "FileManager.h"
#include "FilesHelper.h"
#include "Parser.h"
using namespace std;
int main()
{
	//===============Test Client=================== 
	/*Client Mimo("Eslam Elsaadany", "123456789", 1000);
	Client Himo("Karim Mostafa", "56589555313", 4500);
	Mimo.displayInfo();
	Himo.displayInfo();*/

	////===============Test Employee=================== 
	//Employee Eslam("Eslam Elsaadany", "22222255555", 50001);
	//Eslam.displayInfo();
	//
	//Employee Karim("Karim Mostafa", "55558878855", 4000);
	//Karim.displayInfo();

	////===============Test Admin=================== 
	/*Admin Ahmed(100, "Ahmed Mohamed", "123598745", 5000);
	Ahmed.displayInfo();*/
	
    Client c1(1, "John Doe", "pass123456", 3000);
    Client c2(2, "Jane Smith", "pass456789", 5000);
    FileManager::addClient(c1);
    FileManager::addClient(c2);

    // 2. Add Employee
    Employee e1(1, "Alice Johnson", "emp123456", 7000);
    Employee e2(2, "Bob Williams", "emp456789", 8000);
    FileManager::addEmployee(e1);
    FileManager::addEmployee(e2);

    // 3. Add Admin
    Admin a1(1, "Charlie Brown", "admin123456", 8000);
    Admin a2(2, "Diana Prince", "admin456789", 10000);
    FileManager::addAdmin(a1);
    FileManager::addAdmin(a2);

    // 4. Get Clients and display them
    cout << "Clients from file:" << endl;
    vector<Client> clients = FileManager::getAllClients();
    for (Client& client : clients) {
        cout << "ID: " << client.getId() << ", Name: " << client.getName() << ", Balance: " << client.getBalance() << endl;
    }

    // 5. Get Employees and display them
    cout << "\nEmployees from file:" << endl;
    vector<Employee> employees = FileManager::getAllEmployees();
    for ( Employee& employee : employees) {
        cout << "ID: " << employee.getId() << ", Name: " << employee.getName() << ", Salary: " << employee.getSalary() << endl;
    }

    // 6. Get Admins and display them
    cout << "\nAdmins from file:" << endl;
    vector<Admin> admins = FileManager::getAllAdmins();
    for (Admin& admin : admins) {
        cout << "ID: " << admin.getId() << ", Name: " << admin.getName() << ", Salary: " << admin.getSalary() << endl;
    }

    // 7. Remove all clients, employees, and admins
    cout << "\nClearing all files..." << endl;
    FileManager::removeAllClients();
    FileManager::removeAllEmployees();
    FileManager::removeAllAdmins();

    // Check if files are cleared
    cout << "\nClients after clearing the file:" << endl;
    clients = FileManager::getAllClients();
    if (clients.empty()) {
        cout << "No clients found." << endl;
    }

    cout << "\nEmployees after clearing the file:" << endl;
    employees = FileManager::getAllEmployees();
    if (employees.empty()) {
        cout << "No employees found." << endl;
    }

    cout << "\nAdmins after clearing the file:" << endl;
    admins = FileManager::getAllAdmins();
    if (admins.empty()) {
        cout << "No admins found." << endl;
    }

	




}

