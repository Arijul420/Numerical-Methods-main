#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double a,b,E=.001;
double arr[4];

double func(double x){
    return arr[3]*x*x*x+arr[2]*x*x+arr[1]*x+arr[0];
}

void bisection(){
    double f1,f0,f2,c;
    f1=func(a);
    f2=func(b);
    if(f1*f2>0)
        return;
    do{
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


int main(){
    double x;
    arr[3]=4;
    arr[2]=-12;
    arr[1]=6;
    arr[0]=-10;
   //The equation is 4*x*x*x-12*x*x+6*x-10;

    /*  printf("Enter equation of this format a3x^3+a2*x^2+a1x+a0 ");
      for(int i=3;i>=0;i--)
      {
          printf("\nEnter a%d ",i);
          scanf("%lf",&x);
          arr[i]=x;
      }
    */

    x=-1*(arr[2]/arr[3]);

    if(x<0){
        a=x;
        b=-1*x;
    }
    else{
        b=x;
        a=-1*x;
    }

    bisection();
}
