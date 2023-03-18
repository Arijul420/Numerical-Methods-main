#include<bits/stdc++.h>
using namespace std;
#define nt printf("\t")
#define drawLine printf("___________________________________________________________________________________________________________________\n")
#define E 0.001

double f(double x){
    return x*x - 4*x - 10;
}


double getRoot(double x1, double x2, int iteration){

    double x0, f1, f2, f0;

    f1 = f(x1);
    f2 = f(x2);

    x0 = (x1+x2)/2;
    f0 = f(x0);

    double error = fabs((x2-x1)/x2);

    printf(" %3d    %.4f    %.4f    %.4f    %.4f    %.4f    %.4f    %.4f \n", iteration, x1, x2, x0, f1, f2, f0,error);

    if(f0 == 0)
        return x0;
    if(error < E)
        return (x1+x2)/2;

    if(f1*f0 < 0)
        x2 = x0;
    else
        x1 = x0;

    return getRoot(x1, x2, iteration+1);
}


int main(){
    double x1, x2, root;
    do{
        cout << "Enter the value of x1: ";
        cin >> x1;
        cout << "Enter the value of x2: ";
        cin >> x2;
    }
    while(f(x1)*f(x2) > 0);

    drawLine;
    printf(" Ite.\t   x1\t      x2\t x0\t    f1\t     f2 \t f0 \t  er\n");
    drawLine;

    root = getRoot(x1, x2, 1);

    drawLine;
    cout << "Root using Bisection: " << root << endl;
    return 0;
}
