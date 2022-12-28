#pragma once
#include <string>
using namespace std;
class Person
{
private:
	string name;
	string email;
	string password;
	static int person_count;

public:
	Person() {

	}
	Person(string NAME, string EMAIL, string PASS);
	void setName(string val) {
		name = val;
	}
	void setMail(string val) {
		email = val;
	}
	void setPass(string val) {
		password = val;
	}
	string getName();
	string getMail();
	string getPass();
	static int getPcount();
	virtual string getType() = 0;
};

