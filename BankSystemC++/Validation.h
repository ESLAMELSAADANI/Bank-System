#pragma once
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class Validation
{
public:
	//Methods
	static bool validateName(string name) {
		if (!(name.size() >= 5 && name.size() <= 20)) {
			return false;
		}
		for (int i = 0; i < name.length(); i++) {
			if (!(isalpha(name[i]) || name[i] == ' ')) {
				return false;
			}
		}
		return true;
	}
	static bool validatePassword(string password) {
		if (!(password.size() >= 8 && password.size() <= 20)) {
			return false;
		}
		return true;
	}
	static bool validateBalance(double balance) {
		if (balance < 1500) {
			return false;
		}
		else {
			return true;
		}
	}
	static bool validateSalary(int salary) {
		if (salary < 5000) {
			return false;
		}
		else {
			return true;
		}
	}


};

