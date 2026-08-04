#include<iostream>
using namespace std;

class Student{
public:
    int rno;
    string name;

    Student(){ // default constructor

    }
    Student(int rno, string name, float marks){ // setting marks works fine because constructor is member of function of the student class
        this->rno = rno;
        this->name = name;
        this->marks = marks;
    }
    float getmarks(){
        return marks;
    }
    void setMarks(int marks){
        this->marks = marks;
    }
private:
    float marks;

};

int main(){
    Student s1(76, "Raghav", 93.5); // 
    Student s2;
    s2.rno = 56;
    s2.name = "Parth";
    //s2.marks = 67.3   // -> thi will give error 
    // cout<<s1.marks;
    cout<<s1.getmarks()<<endl;
    s1.setMarks(90);
    cout<<s1.getmarks()<<endl;
}