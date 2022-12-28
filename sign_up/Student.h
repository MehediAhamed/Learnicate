#pragma once
#include "Person.h"




class Student :
    public Person
{
private:
    string student_id ;
    static int student_count;
public:

    class AnError //exception class
    {
    };
    string get_sid() {
        return student_id;
    } 

    Student() {
        student_count++;
    }

    
    Student(string val, string NAME, string EMAIL, string PASS);
    void setValues(string val, string NAME, string EMAIL, string PASS);
    static int gettcount();
    virtual string getType() {
        return "Student";
    }
    
};





