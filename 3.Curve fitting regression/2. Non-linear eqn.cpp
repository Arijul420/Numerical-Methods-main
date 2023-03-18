#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main(){

    cout.precision(4);
    cout.setf(ios::fixed);
    int n;
    cout<<"Enter number of data sets: ";
    cin >> n;
    int i;
    double x[n],y[n],lx[n],ly[n],lx2[n],lxy[n];
    double sum_x=0, sum_y=0,sum_lx=0,sum_ly=0,sum_lx2=0,sum_lxy=0;

    cout<<"\nEnter value for x: ";
    for(i=1;i<=n;i++){
        cin>>x[i];
    }

    cout<<"\nEnter value for y: ";
    for(i=1;i<=n;i++){
        cin>>y[i];
    }

    cout<<"\n\n        xi\t yi\t ln(xi)\t   ln(yi)\t  ln(xi)^2\tln(xi)*ln(xi)"<<endl;
    cout<<"--------------------------------------------------"<<endl;

    for(i=1;i<=n;i++){
        lx[i] = log(x[i]);
        ly[i] = log(y[i]);
        lx2[i] = (log(x[i]))*(log(x[i]));
        lxy[i] = (log(x[i]))*(log(y[i]));

        cout<<"        "<<x[i]<<"\t  "<<y[i]<<"\t  "<<lx[i]<<"\t  "<<ly[i]<<"\t  "<<lx2[i]<<"\t  "<<lxy[i]<<endl;
    }
    cout<<"--------------------------------------------------"<<endl;


    for(int i=1; i<=n; i++){
        sum_x=sum_x+x[i];
        sum_y=sum_y+y[i];
        sum_lx=sum_lx+lx[i];
        sum_ly=sum_ly+ly[i];
        sum_lx2=sum_lx2+lx2[i];
        sum_lxy=sum_lxy+lxy[i];
    }

    cout<<"Sum =  "<<sum_x<<"\t "<<sum_y<<"\t "<<sum_lx<<"\t  "<<sum_ly<<"\t\t"<<sum_lx2<<"\t  "<<sum_lxy<<endl;


    double b =((n*sum_lxy)-(sum_lx*sum_ly))/((n*sum_lx2)-(sum_lx*sum_lx));
    double la=((sum_ly-(b*sum_lx))/n);
    double a= exp(la);

    cout<<"a = "<< a <<endl <<"b =  "<<b;
    return 0;
}

