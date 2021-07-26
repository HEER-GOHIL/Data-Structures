//Given a number n. 
//Count the number of changes in LED light when display one after another of a given number.
//(Initially all LED is off). Number is given input in the form of a string. 
// to be commented :/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str = "082";
    vector<int>l{6,2,5,5,4,5,6,3,7,5};
    int n = str.length();
    int sum = l[str[0] - '0'];
    for(int i=1;i<n;i++)
    {
        sum = sum + abs(l[str[i] - '0'] - l[str[i - 1] - '0']);
    }
    cout<<sum;
    return 0;
}
