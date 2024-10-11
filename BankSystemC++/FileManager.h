#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourceInterface.h"
#include "FilesHelper.h"
class FileManager :public  DataSourceInterface
{
public:
	 static void addClient(Client c) {
		 FilesHelper::saveClient(c);
	}
	 static void  addEmployee(Employee e) {
		 FilesHelper::saveEmployee("Employees.txt", "LastEmployeeId.txt", e);
	}
	 static void addAdmin(Admin a) {
		FilesHelper::saveEmployee("Admins.txt", "LastAdminId.txt", a);
	}

	 static vector<Client> getAllClients() {
		 return FilesHelper::getClients();
	 }
	 static vector<Employee> getAllEmployees() {
		 return FilesHelper::getEmployees();
	 }
	 static vector<Admin> getAllAdmins() {
		 return FilesHelper::getAdmins();
	 }

	 static void removeAllClients() {
		 FilesHelper::clearFile("Clients.txt", "LastClientId.txt");
	 }
	 static void removeAllEmployees() {
		 FilesHelper::clearFile("Employees.txt", "LastEmployeeId.txt");
	 }
	 static void removeAllAdmins() {
		 FilesHelper::clearFile("Admins.txt", "LastAdminId.txt");
	 }
};

