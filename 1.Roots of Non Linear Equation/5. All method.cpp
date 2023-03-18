#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double a,b,E=.001;
double arr[4];

double func(double x)
{
    return arr[3]*x*x*x+arr[2]*x*x+arr[1]*x+arr[0];
}
double dfx(double x)
{
    return arr[3]*3*x*x+arr[2]*2*x+arr[1];
}

void bisection()
{
    double f1,f0,f2,c;
    f1=func(a);
    f2=func(b);
    if(f1*f2>0)
        return;
    do
    {
        f1=func(a);
        f2=func(b);
        c=(a+b)/2.0;
        f0=func(c);
        if(f0==0)
        {
            printf("%lf",c);
            return;
        }
        if(f1*f0<0)
            b=c;
        else
            a=c;
    }
    while(fabs((b-a)/b)>E);

    printf("Root using bisection method = %lf\n",c);

}

void falsePosition()
{
    double c,f0,f1,f2;
    f1=func(a);
    f2=func(b);
    if(f1*f2>0)
        return;
    do
    {
        c=a-((f1*(b-a))/(f2-f1));
        f1=func(a);
        f2=func(b);
        f0=func(c);
        if(f0==0)
        {
            printf("%lf",c);
            return;
        }

    }
    while((fabs((b-a)/b))>E);
    printf("Root using false position method = %lf\n",c);
}
void newtonRaphson()
{
    double x1,x2,dfa,fa;
    x1=a;
    do
    {
        fa=func(x1);
        dfa=dfx(x1);
        x2=x1-(fa/dfa);
        x1=x2;
    }
    while(fabs((x2-x1)/x2)>E);
    printf("Root using newton Raphson method = %lf\n",x2);

}
void secant()
{
    double f1,f2,x3;
    double x1=a,x2=b;
    f1=func(x1);
    f2=func(x2);
    x3=(f2*x1-f1*x2)/(f2-f1);
    if(func(x3)==0)
    {
        printf("%lf",x3);
    }
    else
    {
        do
        {
            x1=x2;
            x2=x3;
            f1=f2;
            f2=func(x3);
            x3=(f2*x1-f1*x2)/(f2-f1);

        }
        while(fabs((x3-x2)/x3)>E);
        printf("Root using secant method = %lf\n",x3);

    }
}


int main()
{
    double x;
    arr[3]=4;
    arr[2]=-12;
    arr[1]=6;
    arr[0]=-10;
    //The equation is 4*x*x*x-12*x*x+6*x-10;

    /* printf("Enter equation of this format a3x^3+a2*x^2+a1x+a0 ");

      for(int i=3;i>=0;i--){
          printf("\nEnter a%d ",i);
          scanf("%lf",&x);
          arr[i]=x;
      }

*/

    x=-1*(arr[2]/arr[3]);
    if(x<0)
    {
        a=x;
        b=-1*x;
    }
    else
    {
        b=x;
        a=-1*x;
    }


    bisection();
    falsePosition();
    newtonRaphson();
    secant();
}
