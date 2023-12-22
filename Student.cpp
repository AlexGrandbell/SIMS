//
// Created by 沈嘉瑞 on 2023.09.24.
//

#include "Student.h"

Student::Student() {
    num = "";
    name = "";
    score = 0;
}

Student::Student(string num, string name, double s):num(""),name(""),score(0) {
    this->num = num;
    this->name = name;
    score = s;
    if (!(score>=0 && score<=5)){
        throw ScoreExpection("成绩超出绩点范围，记录失败。绩点范围是0.0-5.0。");
    }
}

ostream & operator<<(ostream & out,Student const &t){
    out <<left<<"学号:"<<setw(15)<<t.num<<"绩点:"<< setw(10)<<fixed<< setprecision(3)<<t.score<<"姓名:"<<setw(15)<<t.name;
    return out;
}

string Student::getNum() {
    return num;
}

string Student::getName() {
    return name;
}

double Student::getScore() {
    return score;
}
