#pragma once
#include "sign_up/Teacher.h"
int Teacher::teach_count = 0;



Teacher::Teacher(string val, string NAME, string EMAIL, string PASS) :Person(NAME, EMAIL, PASS) {
	teach_id = val;

	teach_count++;
}
void Teacher::setValues(string val, string NAME, string EMAIL, string PASS) {
	setName(NAME);
	setMail(EMAIL);
	setPass(PASS);
	teach_id = val;
}

string Teacher::get_tid() {
	return teach_id;
}
int Teacher::gettcount() {
	return teach_count;
}