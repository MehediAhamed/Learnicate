#pragma once
#include "../sign_up/Student.h"



int Student::student_count = 0;


Student::Student(string val, string NAME, string EMAIL, string PASS) :Person(NAME, EMAIL, PASS) {
	student_id = val;

	student_count++;
}

void Student::setValues(string val, string NAME, string EMAIL, string PASS) {
	setName(NAME);
	setMail(EMAIL);
	setPass(PASS);
	student_id = val;
}

int Student::gettcount() {
	if (student_count == 0)
		throw Student::AnError();
	else
	return student_count;
}

