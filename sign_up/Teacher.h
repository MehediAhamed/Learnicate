#pragma once
#include "Person.h"
class Teacher :
    public Person
{
private:
    string teach_id;
    static int teach_count;
public:
    Teacher() {
        teach_count++;
    }
    Teacher(string val, string NAME, string EMAIL, string PASS);
    void setValues(string val, string NAME, string EMAIL, string PASS);
    string get_tid();
    static int gettcount();
    virtual string getType() {
        return "Teacher";
    }
};

