#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
class data{
  public:
  string color;
  int quant;
  void printdata()
  {
      cout<<"Color: "<<color<<endl;
      cout<<"Quantity: "<<quant<<endl;
  }
  //Default Constructor
  data()
  {
      cout<<"default one: will be called everytime an object is declared"<<endl;
  }
  //Parameterized Constructor
  data(string name)
  {
      cout<<"Hello Welcome : "<<name<<endl;
  }
};
int main()
{
    data car1; //default contructor will be called
    car1.color = "red";
    car1.quant = 5;
    data car2("Anonymous");
    car2.color = "blue";
    car2.quant = 45;
    car1.printdata();
    car2.printdata();
    return 0;
}
