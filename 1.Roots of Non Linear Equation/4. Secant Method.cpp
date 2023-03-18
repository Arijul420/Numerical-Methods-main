#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

double error, maximum_abs_root;
double a0,a1,a2,a3;


double func(double x){
    return a2*pow(x,2)+ a1*x +a0;
}


double secant()
{
    double x3, x1 = maximum_abs_root, x2 = (-1)*maximum_abs_root;

    do{
        x3 = (func(x2)*x1-func(x1)*x2)/(func(x2)-func(x1));

        x1=x2;
        x2=x3;

    }
    while(fabs((x2-x1)/x2)>error);

    return x3;
}


int main()
{
    cout<<"Enter the coefficients:"<<endl;
    cout<<"a2 : ";
    cin>>a2;
    cout<<"a1 : ";
    cin>>a1;
    cout<<"a0 : ";
    cin>>a0;


    error = 0.5*pow(10, 2-5);

    double value = ((a1/a2)*(a1/a2))-(2*(a0/a2));
    maximum_abs_root = fabs(sqrt(value));

    double secant_root = secant();

    cout<<endl<<"The root found by the Secant Method is : "<<setprecision(5)<<secant_root<<endl;
}

