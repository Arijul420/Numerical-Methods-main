#include<stdio.h>
#include<conio.h>
#include<math.h>

double f(double x){
    return x*x - x - 2;
}

int main()
{

	 float x0, x1, x2, f0, f1, f2, e;
	 int step = 1;
	 /* Inputs */
	 up:
	 printf("Enter two initial guesses:");
	 scanf("%f%f", &x0, &x1);
	 printf("\nEnter tolerable error:");
	 scanf("%f", &e);

	 f0 = f(x0);
	 f1 = f(x1);

	 if( f0*f1 > 0){
		  printf("Incorrect Initial Guesses.\n");
		  goto up;
	 }

	 printf("\nStep\t x1\t  x2 \t     f(x1)\tf(x2)\t  x0\t     f(x0)\n");
	 do{
		  x2 = x0 - (x0-x1) * f0/(f0-f1);
		  f2 = f(x2);
		  printf("%d\t%.4f    %.4f    %.4f    %.4f     %.4f    %.4f\t\n",step, x0, x1, f0, f1, x2, f2);

		  if(f0*f2 < 0){
			   x1 = x2;
			   f1 = f2;
		  }
		  else{
			   x0 = x2;
			   f0 = f2;
		  }
		  step = step + 1;

	 }while(fabs(f2)>e);

	 printf("\nRoot is: %f", x2);
	 return 0;
}
