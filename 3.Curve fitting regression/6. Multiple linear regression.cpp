#include<bits/stdc++.h>
using namespace std;

int main(){

    cout.precision(2);
    cout.setf(ios::fixed);
    int i,n;
    double value,sum;

    cout<<"Enter how many values you want for(x,y): ";
    cin>>n;

    double x[n],z[n],y[n],x2[n],z2[n],xz[n],xy[n],yz[n];
    double sum_x=0,sum_z=0,sum_y=0,sum_x2=0,sum_z2=0,sum_xz=0,sum_xy=0,sum_yz=0;

    cout<<"\nEnter value for x: ";
    for(i=1;i<=n;i++){
        cin>>x[i];
    }

    cout<<"\nEnter value for z: ";
    for(i=1;i<=n;i++){
        cin>>z[i];
    }

    cout<<"\nEnter value for y: ";
    for(i=1;i<=n;i++){
        cin>>y[i];
    }

    cout<<"\n        xi\tzi\tyi\txi2\tzi2\tx.z\tx.y\ty.z"<<endl;
    cout<<"----------------------------------------"<<endl;

    for(i=1;i<=n;i++){
        x2[i]=x[i]*x[i];
        z2[i]=z[i]*z[i];
        xz[i]=x[i]*z[i];
        xy[i]=x[i]*y[i];
        yz[i]=y[i]*z[i];

        cout<<"      "<<x[i]<<"    "<<z[i]<<"     "<<y[i]<<"    "<<x2[i]<<"    "<<z2[i]<<"    "<<xz[i]<<"    "<<xy[i]<<"    "<<yz[i]<<endl;
    }

    cout<<"----------------------------------------"<<endl;
    for(i=1;i<=n;i++){
        sum_x=sum_x+x[i];
        sum_z=sum_z+z[i];
        sum_y=sum_y+y[i];
        sum_x2=sum_x2+x2[i];
        sum_z2=sum_z2+z2[i];
        sum_xz=sum_xz+xz[i];
        sum_xy=sum_xy+xy[i];
        sum_yz=sum_yz+yz[i];
    }

    cout<<"Sum = "<<sum_x<<"   "<<sum_z<<"     "<<sum_y<<"    "<<sum_x2<<"    "<<sum_z2<<"   "<<sum_xz<<"   "<<sum_xy<<"     "<<sum_yz<<endl;

    cout<<"\nSubstituting these values ,we get:\n\n";

    cout<<n<<" a1 + "<<sum_x<<" a2 + "<<sum_z<<" a3 = "<<sum_y<<endl;

    cout<<sum_x<<" a1 + "<<sum_x2<<" a2 + "<<sum_xz<<" a3 = "<<sum_xy<<endl;

    cout<<sum_z<<" a1 + "<<sum_xz<<" a2 + "<<sum_z2<<" a3 = "<<sum_yz<<endl;

    return 0;

}
