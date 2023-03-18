#include<bits/stdc++.h>
using namespace std;
#define Max 100
int main()
{
    double x[Max],fx[Max],sum=0.0,xreq,prodfunc;
    int n;
    cout<<"How many records you will be enter : ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the value of x"<<i<<" : " ;
        cin>>x[i];
        cout<<"\nEnter the value of f(x"<<i<<") : " ;
        cin>>fx[i];

    }
    cout<<"\nEnter X for finding f(x) : ";
    cin>>xreq;

    for(int i=0;i<n;i++)
    {
        prodfunc=1.0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                prodfunc*=(xreq-x[j])/(x[i]-x[j]);
            }
        }
        sum+=prodfunc*fx[i];
    }
    cout<<"Interpolated function value at x:  "<<xreq<<" is : "<<sum<<endl;
    return 0;
}
