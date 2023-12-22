//
// Created by 沈嘉瑞 on 2023.09.24.
//

#ifndef SIMS_SQLIST_H
#define SIMS_SQLIST_H

#include "Student.h"

const int MaxSize = 100;

template<class T>
class SqList {
public:
    SqList();//构造长度为0的表
    SqList(T a[], int);//复制

    void PrintList();//显示当前所有学生信息记录
    void Insert(int,T);//从键盘输入一条学生信息记录，插入到表中指定的位置(实际位置，不是数组位置)
    T Find(int);//根据记录的位置查找学生的各项信息
    T Find(string);//根据学号查找学生的各项信息
    bool Find(string,int );//根据学号查找学生是否存在
    T Delete(int i);//删除指定位置的学生信息记录
    int Length();//统计表中学生人数
    void Sort(bool num = true, bool smallToBig = true);//按照学号1或者绩点2进行排序,正序逆序
    void Clear();//清空表中所有记录
private:
    T data[MaxSize];
    int length;
};

template<class T>
SqList<T>::SqList(){
    length = 0;
}

template<class T>
SqList<T>::SqList(T a[],int len){
    for (int i = 0; i < len; ++i) {
        data[i] = a[i];
    }
    length = len;
}

template<class T>
void SqList<T>::PrintList() {
    if (length == 0){
        cout<<"数据为空"<<endl;
    } else {
        for (int i = 0; i < length; ++i) {
            cout << "第" << i + 1 << "位:" << data[i] << endl;
        }
    }
}

template<class T>
void SqList<T>::Insert(int i, T x) {
    if (length == 100){
        throw FullExpection("栈已满，记录失败，请考虑删除一些数据。");
    } else if ((i>length+1)||(i<=0)){
        throw IExpection("序号超出范围错误，记录失败。序号范围在1-100，并且小于列表长度+1。可使用6号菜单查看当前长度。");
    } else if (Find(x.getNum(),1)){
        throw DuplicateNumExpection("该学号已存在，记录失败。可以使用1号菜单查看所有学生信息，使用5号菜单更改学生信息。");
    }
    for (int j = length; j >= i; --j) {
        data[j] = data[j-1];
    }
    data[i-1] = x;
    length++;
}

template<class T>
T SqList<T>::Find(int i) {
    if (i>length || i<=0){
        throw IExpection("序号超出范围错误,查找失败。序号应该小于列表长度且大于0。可使用6号菜单查看当前长度。");
    } else{
        cout<<"找到学生信息为:\n"<<data[i-1]<< endl;
        return data[i-1];
    }
}

template<class T>
T SqList<T>::Find(string num) {
    for (int i = 0; i < length; ++i) {
        if (data[i].getNum() == num){
            cout<<"找到学生信息为:"<<data[i]<< endl;
            return data[i];
        }
    }
    throw NoFoundExpection("没有找到该学号对应的学生。");
}

template<class T>
bool SqList<T>::Find(string num,int i) {
    for (int i = 0; i < length; ++i) {
        if (data[i].getNum() == num){
            return true;
        }
    }
    return false;
}

template<class T>
T SqList<T>::Delete(int i){
    if ((i>length)||(i<=0)){
        throw IExpection("删除数据超出范围，删除失败。序号应该小于列表长度且大于0。可使用6号菜单查看当前长度。");
    }
    T del = data[i-1];
    for (int j = i-1; j <length ; ++j) {
        data[j] = data[j+1];
    }
    length--;
    return del;
}

template<class T>
int SqList<T>::Length() {
    return length;
}

//按照学号排名
template<class T>
bool comapreByNum(T& a,T& b){
    return a.getNum() < b.getNum();
}

//按照成绩排名
template<class T>
bool comapreByScore(T& a,T& b){
    return a.getScore() < b.getScore();
}

template<class T>
void SqList<T>::Sort(bool num , bool smallToBig) {
    if (num){
        sort(data,data+length, comapreByNum<T>);
    } else{
        sort(data,data+length, comapreByScore<T>);
    }
    if (!smallToBig){
        //翻转数组
        reverse(data,data+length);
    }
}

template<class T>
void SqList<T>::Clear() {
    for (int i = 0; i < length; ++i) {
        data[i] = {};
    }
    length = 0;
}
#endif //SIMS_SQLIST_H
