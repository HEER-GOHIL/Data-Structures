/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {return (a>b)?a:b;}
int knapsack(int w, int wt[], int val[], int n)
{
    if(n==0 || w==0)
    {
        return 0;
    }
    if(wt[n-1]>w)
    {
        return knapsack(w,wt,val,n-1);
    }
    else
    {
        return max(val[n-1] + knapsack(w - wt[n-1],wt,val,n-1),knapsack(w,wt,val,n-1));
        
    }
}
int main()
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(W, wt, val, n);
    return 0;
}
 
