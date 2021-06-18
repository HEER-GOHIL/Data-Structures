//Structure is a user defined data type
//A structure creates a data type that can be used to group items of possibly different types into a single type
//The value of varibles inside a structure cannot be initialized 
#include <bits/stdc++.h>
using namespace std;
struct student
{
    string name;
    int age;
    string grade;
};
int main()
{
    struct student p1;
    p1.name = "abc";
    p1.age = 12;
    p1.grade = "third";
    struct student p2;
    p2.name = "xyz";
    p2.age = 13;
    p2.grade = "fifth";
    cout<<"data of first student : "<<p1.name<<" "<<p1.age<<" "<<p1.grade<<endl;
    cout<<"data of second student : "<<p2.name<<" "<<p2.age<<" "<<p2.grade<<endl;
    return 0;
}
