#include<bits/stdc++.h>
#define E 0.00
using namespace std;
float f1,f2,x3;

float fx(float x){
    return x*x-4*x-10;
}

void horner(float x){
   float p[10],a[10];
   int i;

   for(i=2;i>=0;i--){    //i barate komate hobe
     cout<<endl;
     cout<<"A"<<i<<" ?";
     cin>>a[i];
   }

   p[3]=a[3];        //kombe
   cout<<"p3 "<<p[3]<<endl;

   for(i=2;i>=0;i--){
    p[i]=(p[i+1]*x)+a[i];
    cout<<"p"<<i<<" "<<p[i]<<endl;
   }

}

void sc(float x1,float x2){

    f1=fx(x1);
    f2=fx(x2);
    x3=(f2*x1-f1*x2)/(f2-f1);

    if(fx(x3)==0)
        cout<<x3;

    else{
        do{
            x1=x2;
            x2=x3;
            f1=f2;
            f2=fx(x3);
            x3=(f2*x1-f1*x2)/(f2-f1);

        }
        while(fabs((x3-x2)/x3)>E);
        cout<<x3;

    }
    horner(x3);

}

int main(){
    float a,b;
    cout<<"Enter the initial guesses:\na=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    cout<<"\n";
    sc(a,b);
}

//4,2
