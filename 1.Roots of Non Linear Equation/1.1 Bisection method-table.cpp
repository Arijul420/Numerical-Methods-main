#include<iostream>
#include<cmath>
#include <math.h>
#include<iomanip>

#define E 0.001

using namespace std;
double f(double x);

double f(double x){
    return (x*x)-4*x-10;
}

int main(){
    cout.precision(4);
    cout.setf(ios::fixed);
    double a,b,c,e,fa,fb,fc;
    cout<<"Enter the initial guesses:\na=";
    cin>>a;
    cout<<"b=";
    cin>>b;

    cout<<"\n";

    if (f(a)*f(b)>0)
        cout<<"Please enter a different intial guess"<<endl;


    cout<<"    a"<<"         "<<"b"<<"           "<<"c"<<"          fa"<<"            fb"<<"         "<<"fc"<<"       "<<"error"<<endl;

    while (fabs(a-b)>E){
        c=(a+b)/2.0;
        fa=f(a);
        fb=f(b);
        fc=f(c);

        double error = fabs((b-a)/b);

        cout<<a<<"     "<<b<<"     "<<c<<"      "<<fa<<"        "<<fb<<"     "<<fc<<"     "<<error<<"     "<<endl;
        if (fc==0)
            break;

        else if (fa*fc<0)
            b=c;
        else
            a=c;

    }
    cout<<"The root of the equation is "<<c;
    return 0;
}
