#include<bits/stdc++.h>
#define E 0.005
using namespace std;
float f1,f2,x3;

float fx(float x)
{
    return (x+(5/x))/2;
}
void horner(float x)
{
   float p[10],a[10];
   int i;
   for(i=3;i>=0;i--)
   {
    cout<<endl;
    cout<<"A"<<i<<" ?";
    cin>>a[i];
   }
   p[3]=a[3];
   cout<<"p3"<<p[3]<<endl;
   for(i=2;i>=0;i--)
   {
    p[i]=(p[i+1]*x)+a[i];
    cout<<"p"<<i<<" "<<p[i]<<endl;

   }


}
void fp(float x0)
{
    float x1;
    f1=x0;
    do
    {
    x1=f1;
    f1=fx(x1);

    }

    while(fabs((f1-x1)/f1)>E);
        cout<<f1;


   // horner(x3);

}
int main()
{
    fp(1);
}
