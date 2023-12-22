//
// Created by 沈嘉瑞 on 2023.09.24.
//

#ifndef SIMS_STUDENT_H
#define SIMS_STUDENT_H

#include "tool.h"

class Student {
private:
    string num;
    string name;
    double score;
public:
    Student();
    Student(string num,string name,double s);

    string getNum();
    string getName();
    double getScore();

    friend ostream & operator<<(ostream &,Student const &);
};

#endif //SIMS_STUDENT_H
