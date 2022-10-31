#include "Person.h"

int Person::person_count = 0;

Person::Person(string NAME, string EMAIL, string PASS) {
	name = NAME;
	email = EMAIL;
	password = PASS;
	person_count++;
}

string Person::getName() {
	return name;
}
string Person::getMail() {
	return email;
}
string Person::getPass() {
	return password;
}
int Person::getPcount() {
	return person_count;
}