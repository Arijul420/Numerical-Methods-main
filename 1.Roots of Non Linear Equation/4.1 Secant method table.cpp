#include<bits/stdc++.h>
#define E 0.005
using namespace std;
float f1,f2,x3;

float fx(float x){
    return x*x-4*x-10;
}


void sc(float x1,float x2){

    cout.precision(4);
    cout.setf(ios::fixed);
	cout <<" x1"<<"          "<<"x2"<<"         "<<"f(x1)"<<"         "<<"f(x2)"<<"        "<<"x3"<<"         "<<"ERROR"<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;

    f1=fx(x1);
    f2=fx(x2);
    x3=(f2*x1-f1*x2)/(f2-f1);
    if(fx(x3)==0){
        cout<<x3;
    }
    else{
        do{
            cout<<x1<<"     "<<x2<<"     "<<f1<<"      "<<f2<<"        "<<x3<<"     "<<abs(x3 - x2)/abs(x3)<<endl;


            x1=x2;
            x2=x3;
            f1=f2;
            f2=fx(x3);
            x3=(f2*x1-f1*x2)/(f2-f1);
        }
        while(fabs((x3-x2)/x3)>E);
        cout<<"Root using secant method :"<<x3;
        cout<<"\n";
    }
}

int main(){

    float a,b;
    cout<<"Enter the initial guesses:\na=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"\n";

    sc(a,b);
}

