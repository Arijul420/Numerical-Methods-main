#include<bits/stdc++.h>
using namespace std;

int main(){

    cout.precision(4);
    cout.setf(ios::fixed);
    int i,n;
    double value,sum;

    cout<<"Enter how many values you want for(x,y): ";
    cin>>n;

    double x[n],y[n],x2[n],xy[n];
    double sum_x=0,sum_y=0,sum_x2=0,sum_xy=0;

    cout<<"\nEnter value for x: ";
    for(i=1;i<=n;i++){
        cin>>x[i];
    }

    cout<<"\nEnter value for y: ";
    for(i=1;i<=n;i++){
        cin>>y[i];
    }

    cout<<"        xi\tyi\txi*xi\txi*yi\t"<<endl;
    cout<<"----------------------------------------"<<endl;

    for(i=1;i<=n;i++){
        x2[i]=x[i]*x[i];
        xy[i]=x[i]*y[i];
        cout<<"        "<<x[i]<<"\t"<<y[i]<<"\t"<<x2[i]<<"\t"<<xy[i]<<endl;
    }

    cout<<"----------------------------------------"<<endl;
    for(i=1;i<=n;i++){
        sum_x=sum_x+x[i];
        sum_y=sum_y+y[i];
        sum_x2=sum_x2+x2[i];
        sum_xy=sum_xy+xy[i];
    }

    cout<<"Sum =  "<<sum_x<<"\t"<<sum_y<<"\t"<<sum_x2<<"\t"<<sum_xy<<endl;

    double b = ((n*sum_xy)-(sum_x*sum_y))/((n*sum_x2)-(sum_x*sum_x));
    double a = (sum_y/n)-(b*(sum_x/n));

    cout<<"\na="<<a;
    cout<<"\nb="<<b;

    cout<<"\n\nThe equation is y = "<<a<<" + "<<b<<" x "<<endl;

    cout<<"\nEnter the value of x :";
    cin>>value;

    sum=a+(b*value);

    cout << "\nValue at " << value << " is "<< sum << endl;

}


/*

5
1 2 3 4 5
3 4 5 6 8

*/
