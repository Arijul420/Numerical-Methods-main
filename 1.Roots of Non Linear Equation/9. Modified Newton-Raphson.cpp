#include<bits/stdc++.h>
#define error .001
using namespace std;

int n;
double ar[100],apr[100],br[100];



double func(double x)
{
    double res=ar[n];

    for(int i=n-1;i>=0;i--)
    {
        res=res*x+ar[i];
    }
    return res;
}
double fprime(double x)
{
    for(int i=n;i>0;i--)
    {
       apr[i-1]=ar[i]*i;
    }
    double res=apr[n-1];
    for(int i=n-2;i>=0;i--)
    {
       res=res*x+apr[i];
    }
    return res;
    //return 2*x-3;

}


void p(double x0)
{
    double f1,f2,f3,x1,x2,f0,xr;

     while(n>1)
    {
        while(true)
        {
            double y=func(x0);
            double z=fprime(x0);
            xr=x0-(y/z);
            double err=fabs((xr-x0)/xr);
            if(err<=error)
            {
                cout<<"Root is: "<<xr<<endl;
                break;
            }
            x0=xr;
        }
        br[n]=0;
        for(int i=n;i>0;i--)
        {
            br[i-1]=ar[i]+xr*br[i];
        }
        n--;
        for(int i=0;i<=n;i++)
        {
            ar[i]=br[i];
        }
        x0=xr;



    }
    double x=-ar[0]/ar[1];
    cout<<x;

    return;
}



int main()
{


    cout<<"Enter the degree of the eqn:";
    cin>>n;
    cout<<"Enter coefficients from maximum power: ";
    for(int i=n;i>=0;i--)
    {
        cout<<"Coefficients x["<<i<<"] = ";
        cin>>ar[i];
    }

    double x0,xr;
    cout<<"Enter the value of intial guess x0:";
    cin>>x0;
    p(x0);

}
