#include "Teacher.h"
int Teacher::teach_count = 0;



Teacher::Teacher(int val, string NAME, string EMAIL, string PASS) :Person(NAME, EMAIL, PASS) {
	teach_id = val;

	teach_count++;
}
void Teacher::setValues(int val, string NAME, string EMAIL, string PASS) {
	setName(NAME);
	setMail(EMAIL);
	setPass(PASS);
	teach_id = val;
}

int Teacher::get_tid() {
	return teach_id;
}
int Teacher::gettcount() {
	return teach_count;
}