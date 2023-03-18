#include<bits/stdc++.h>
using namespace std;

int main(){

    cout.precision(4);
    cout.setf(ios::fixed);
    int i,n;
    double value,sum;

    cout<<"Enter how many values you want for(x,y): ";
    cin>>n;

    double x[n],y[n],x2[n],x3[n],x4[n],xy[n],yx2[n];
    double sum_x=0,sum_y=0,sum_x2=0,sum_x3=0,sum_x4=0,sum_xy=0,sum_yx2=0;

    cout<<"\nEnter value for x: ";
    for(i=1;i<=n;i++){
        cin>>x[i];
    }

    cout<<"\nEnter value for y: ";
    for(i=1;i<=n;i++){
        cin>>y[i];
    }

    cout<<"\n        xi\tyi\t  xi2\t    xi3\t      xi4\t    yx\t    yx2"<<endl;
    cout<<"----------------------------------------"<<endl;

    for(i=1;i<=n;i++){
        x2[i]=x[i]*x[i];
        x3[i]=x[i]*x[i]*x[i];
        x4[i]=x[i]*x[i]*x[i]*x[i];
        xy[i]=x[i]*y[i];
        yx2[i]=y[i]*x2[i];

        cout<<"      "<<x[i]<<"    "<<y[i]<<"    "<<x2[i]<<"    "<<x3[i]<<"    "<<x4[i]<<"    "<<xy[i]<<"    "<<yx2[i]<<endl;
    }

    cout<<"----------------------------------------"<<endl;
    for(i=1;i<=n;i++){
        sum_x=sum_x+x[i];
        sum_y=sum_y+y[i];
        sum_x2=sum_x2+x2[i];
        sum_x3=sum_x3+x3[i];
        sum_x4=sum_x4+x4[i];
        sum_xy=sum_xy+xy[i];
        sum_yx2=sum_yx2+yx2[i];
    }

    cout<<"Sum = "<<sum_x<<"   "<<sum_y<<"    "<<sum_x2<<"    "<<sum_x3<<"   "<<sum_x4<<"   "<<sum_xy<<"     "<<sum_yx2<<endl;

    cout<<"\nSubstituting these values, we get:\n\n";

    cout<<n<<" a1 + "<<sum_x<<" a2 + "<<sum_x2<<" a3 = "<<sum_y<<endl;

    cout<<sum_x<<" a1 + "<<sum_x2<<" a2 + "<<sum_x3<<" a3 = "<<sum_xy<<endl;

    cout<<sum_x2<<" a1 + "<<sum_x3<<" a2 + "<<sum_x4<<" a3 = "<<sum_yx2<<endl;

    return 0;

}
