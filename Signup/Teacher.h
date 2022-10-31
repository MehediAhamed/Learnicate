#pragma once
#include "Person.h"
class Teacher :
    public Person
{
private:
    int teach_id=0;
    static int teach_count;
public:
    Teacher() {
        teach_count++;
    }
    Teacher(int val, string NAME, string EMAIL, string PASS);
    void setValues(int val, string NAME, string EMAIL, string PASS);
    int get_tid();
    static int gettcount();
};

