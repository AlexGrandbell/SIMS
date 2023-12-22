//
// Created by 沈嘉瑞 on 2023.09.25.
//

#include "menu.h"
SqList<Student> stuList;

void outPutMenu(){
    cout<<"\n ----------菜单----------"<<endl;
    cout<<" |1.显式所有学生信息记录|"<<endl;
    cout<<" |2.录入学生信息记录    |"<<endl;
    cout<<" |3.查找学生信息记录    |"<<endl;
    cout<<" |4.删除学生信息记录    |"<<endl;
    cout<<" |5.更改学生信息记录    |"<<endl;
    cout<<" |6.统计学生人数        |"<<endl;
    cout<<" |7.排序学生信息记录    |"<<endl;
    cout<<" |8.清空学生信息记录    |"<<endl;
    cout<<" |0.退出程序            |"<<endl;
    cout<<" ------------------------"<<endl;
    //输出提示选择编号
    cout<<"请选择菜单项编号(0-8):";
}

void ShowAll(){
    cout<<"--------学生信息--------"<<endl;
    stuList.PrintList();
    cout<<"------------------------"<<endl;
};

void Add() {
    cout << "--------插入信息--------" << endl;
    int i = stuList.Length() + 1;
    double score;
    string num, name;
    try {
        cout << "请输入插入的位置:";
        i = inputInt();
        cout << "请输入学生学号:";
        num = inputString();
        cout << "请输入学生姓名:";
        name = inputString();
        cout << "请输入学生绩点:";
        score = inputDouble();
        stuList.Insert(i, Student(num, name, score));
        cout << "记录成功。" << endl;
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "------------------------" << endl;
};

void Find() {
    cout << "--------查找信息--------" << endl;
    bool byNum = true;
    string tmp = "Y";
    try {
        cout << "是否使用学号查找(Y-学号/N-直接访问序号):";
        tmp = inputString();
        if (tmp != "Y" && tmp != "y") {
            byNum = false;
        }

        if (byNum) {
            cout << "已选择使用学号查找。请输入学号:";
            stuList.Find(inputString());
        } else {
            cout << "已选择使用序号查找。请输入序号:";
            stuList.Find(inputInt());
        }
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "------------------------" << endl;
};
void Delete() {
    cout << "--------删除信息--------" << endl;
    int i;
    string tmp = "N", input;
    try {
        cout << "请输入删除信息的序号:";
        i = inputInt();
        stuList.Find(i);
        cout << "确认要删除该记录吗?(Y-确认/N-取消):";
        tmp = inputString();
        if (tmp == "Y" || tmp == "y") {
            stuList.Delete(i);
            cout << "删除成功。" << endl;
        } else {
            cout << "已取消删除。" << endl;
        }
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "------------------------" << endl;
};
void Refresh() {
    cout << "--------更改信息--------" << endl;
    int i;
    try {
        string tmp = "N";
        cout << "请输入更改信息的序号:";
        i = inputInt();
        stuList.Find(i);
        cout << "确认要更改该记录吗?(Y-确认/N-取消):";
        tmp = inputString();
        if (tmp == "Y" || tmp == "y") {
            double score;
            string num, name, scoreInput;
            cout << "请输入新的学号:";
            num = inputString();
            cout << "请输入新的姓名:";
            name = inputString();
            cout << "请输入新的绩点:";
            score = inputDouble();
            cout << "正在写入新信息..." << endl;
            stuList.Insert(i, Student(num, name, score));
            cout << "写入成功。正在删除原信息..." << endl;
            stuList.Delete(i + 1);
            cout << "更改成功" << endl;
        } else {
            cout << "已取消更改。" << endl;
        }
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout << "------------------------" << endl;
};
void Length(){
    cout<<"--------学生人数--------"<<endl;
    cout<<"学生人数为"<<stuList.Length()<<"个"<<endl;
    cout<<"------------------------"<<endl;
};
void Sorts(){
    cout<<"--------排序信息--------"<<endl;
    bool byNum = true,sTob = true;
    string tmp = "Y";
    cout<<"是否使用学号排序(Y-学号/N-绩点):";
    tmp = inputString();
    if (tmp != "Y" && tmp != "y"){
        byNum = false;
    }
    byNum ? cout<<"已选择使用学号排序。"<<endl : cout<<"已选择使用绩点排序。"<<endl;
    cout<<"是否使用顺序排序(Y-顺序/N-逆序):";
    tmp = inputString();
    if (tmp != "Y" && tmp != "y"){
        sTob = false;
    }
    sTob ? cout<<"已选择使用顺序排序。"<<endl : cout<<"已选择使用逆序排序。"<<endl;
    stuList.Sort(byNum,sTob);
    cout<<"排序完成，可使用1号菜单查看。"<<endl;
    cout<<"------------------------"<<endl;
};
void Clear(){
    cout<<"--------清除信息--------"<<endl;
    try {
        string tmp = "Y";
        cout << "是否清除所有学生信息(Y/N)?:";
        tmp = inputString();
        if (tmp == "Y" || tmp == "y") {
            stuList.Clear();
            cout << "清除成功。" << endl;
        } else {
            cout << "已取消。" << endl;
        }
    }catch (const exception &e) {
        cerr << e.what() << endl;
    }
    cout<<"------------------------"<<endl;
};
void ExitApp(){
    cout<<"\n欢迎再次使用，再见。"<<endl;
};