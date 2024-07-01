#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    //define variable
    string operation;
    double num1,num2;

    //get user input
    cout<<"Enter First Number:- "<<endl;
    cin>>num1;
    cout<<"Enter Operation(+,-,*,/) :- "<<endl;
    cin>>operation;
    cout<<"Enter the Second Number :-"<<endl;
    cin>>num2;

    //if else statement checking entered operation 
    if(operation == "+"){
        cout<<num1+num2;
    }
    else if(operation == "-"){
        cout<<num1-num2;
    }
     else if(operation == "*"){
        cout<<num1*num2;
    }
    else if(operation == "/"){
        cout<<num1/num2;
    }
    else{
        cout<<"NOT VALID!!";
    }
    return 0;
    }
