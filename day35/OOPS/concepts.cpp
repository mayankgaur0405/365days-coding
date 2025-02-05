#include<bits/stdc++.h>
using namespace std;
class Teacher{
private:
double salary;

public:
string name;
string dept;
string subject;


void changeDept(string newDept){
    dept = newDept;
}

//setters
void setSalary(double newSalary){
    salary = newSalary;
}

//getters
double getSalary(){
    return salary;
}
};
int main(){
    Teacher t1;
    t1.name = "Mayank Gaur";
    t1.dept = "Information Technology";
    t1.subject = "Data Structures & Algorithms";
    // t1.salary = 90000;
    t1.setSalary(100000);

    cout<<"Name of teacher 1 is "<<t1.name<<endl;
    cout<<"Deptartment of teacher 1 is "<<t1.dept<<endl;
    cout<<"Subject of teacher 1 is "<<t1.subject<<endl;
    // cout<<"Salary of teacher 1 is "<<t1.salary<<endl;
     cout<<"Salary of teacher 1 is "<<t1.getSalary()<<endl;

    return 0;
}