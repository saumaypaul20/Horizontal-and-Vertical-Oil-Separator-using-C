#include<stdio.h>
#include<math.h>
int i,t;
float p1,pg,dm,u,Vt,Re,cd1,d2,y,x,P,Z,Qg,T,Q,h,l,ratio,rounded_cd1,temp,d;
float cd = 0.34;

//3
float Calculate_second(float r)
{
    	printf("CD= %0.3f\n",r);
    	y = ((pg/(p1-pg))*(r/dm));
		d2= 5040*((T*Z*Qg)/P)*sqrt(y);
		d = sqrt(d2);
		d = round(d);
	
    	for(i=0;i<5; i++)
		{
			for(t=1;t<=4;t++)
			{	
			
			//calculate H
			h = (t*Q)/(0.12*d*d);
			printf("\n");
			printf("For time T: %d \n",t);
			printf("Value of D = %0.3f \n",d);
			printf("Value of H: %0.3f \n",h);

			//calculate L
				if(d>=36){
					
					l=(h+d+40)/12;	
				}
				else
				{
					l=(h+76)/12;	
				}
	 		
	 		printf("Value of L: %0.3f \n",l);

				//calculate L*12/D
				
				ratio= (l*12)/d;
				
				if(ratio>3.0  && ratio < 4.0)
					{
						printf("\nAcceptable L/D: %0.2f\n\n\n", ratio);
					
					}
				else
					{
						printf("\nUnacceptable L/D: %0.2f\n\n\n",ratio);
					}

			}
			d=d+2;
		}

}
//2

float Calculate_cd1(float f)
{
	temp = f;
	x = ((p1-pg)/pg) * (dm/temp);
	Vt = 0.0119*sqrt(x);
	Re = 0.0049*((pg*dm*Vt)/u);
	cd1= ((24/Re) + (3/sqrt(Re)) + 0.34);
	rounded_cd1 = floor(cd1 * 1000)/1000;
	

	if(f == rounded_cd1)
	{
		Calculate_second(rounded_cd1);
	}
	else
	{
		printf("REPEAT\n\n");
		Calculate_cd1(rounded_cd1);

	}
	
}

//1

input()
{
	printf("-------------------PROTOTYPE------------------------\n\n");
	printf("-----WELCOME TO VERTICAL OIL SEPERATOR PROGRAM!-----\n\n");
	printf("------------START INPUTTING THE VALUES--------------\n\n");
	
	printf("Enter the P1: ");
	scanf("%f",&p1);
	
	printf("Enter the Pg: ");
	scanf("%f",&pg);
	
	printf("Enter the Dm: ");
	scanf("%f",&dm);
	
	printf("Enter the  u: ");
	scanf("%f",&u);
	
	printf("Enter the  T: ");
	scanf("%f",&T);
	
	printf("Enter the  P: ");
	scanf("%f",&P);
	
	printf("Enter the  Z: ");
	scanf("%f",&Z);
	
	printf("Enter the  Qg: ");
	scanf("%f",&Qg);
	
	printf("Enter the  Q: ");
	scanf("%f",&Q);
	

}

void main()
{
input();
printf("RESULT:\n \n");
Calculate_cd1(cd);
}








