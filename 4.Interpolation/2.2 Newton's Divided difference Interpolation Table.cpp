#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,n;
    float x[100],f[100],a[100],d[100][100],xp,sum,p,s[100][100];
    cout<<"How many records you will be enter : ";
    cin>>n;

    for(i=1;i<=n;i++){
       cout<<"\nEnter the value of x"<<i<<" : " ;
       cin>>x[i];
       cout<<"Enter the value of f(x"<<i<<") : " ;
       cin>>f[i];
    }

    for(i=1;i<=n;i++)
        d[i][1]=f[i];

        cout<<"----------------------------------------------------------------------------------";
        cout<< "\nx \tf(x)"<<endl;
        cout<<"----------------------------------------------------------------------------------";

    for(j=2;j<=n;j++){

        for(i=1;i<=n-j+1;i++){

            d[i][j]= (d[i+1][j-1] - d[i][j-1])/(x[i+j-1]-x[i]);
            s[i][j]=d[i][j];
        }
    }

    for(j=1;j<=n;j++){
        a[j]=d[1][j];
    }

    for(i=1;i<=n;i++)
    {
        cout<<"\n"<< x[i] <<"\t" <<f[i]<<endl;

        for(int j=2;j<=n;j++){
             if(s[i][j]!=0)
            cout<<"\t\t"<<s[i][j];
        }
    }

    cout<<"\nEnter X for finding f(x) : ";
    cin>>xp;

    sum=a[1];
    for(i=2;i<=n;i++){
        p=1.0;
        for(j=1;j<=i-1;j++){
            p=p*(xp-x[j]);
        }
        sum+= a[i]*p;

    }
    cout<<"\n x =  "<<sum<<endl;
    return 0;
}
/*
5
5 150
7 392
11 1452
13 2366
21 9702
6
*/
