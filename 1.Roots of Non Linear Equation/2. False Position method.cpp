#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double a,b,E=0.001;
double arr[4];

double f(double x){
    return arr[3]*x*x*x+arr[2]*x*x+arr[1]*x+arr[0];
}


void falsePosition(){
    double c,f0,f1,f2;
    f1=f(a);
    f2=f(b);
    if(f1*f2>0)
        return;
    do{
        c=a-((f1*(b-a))/(f2-f1));
        f0=f(c);
        if(f0==0){
            printf("%lf",c);
            return;
        }
        if(f(a)*f(c)<0)
            b=c;
        else
            a=c;

    }while((fabs((b-a)/b))>E);

    printf("Root using false position method = %lf\n",c);
}

int main(){
    double x;
    arr[3]=4;
    arr[2]=-12;
    arr[1]=6;
    arr[0]=-10;
    //The equation is 4*x*x*x-12*x*x+6*x-10;

   /* printf("Enter equation of this format a3x^3+a2*x^2+a1x+a0 ");
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

    falsePosition();

}
