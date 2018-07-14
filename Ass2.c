//HORIZONTAL OIL SEPERATOR
#include<stdio.h>
#include<math.h>
int D=10,temp2,temp3,t2;
double p0=53.02,pg=3.70,dm=100,ug=0.013,Uo,Re,cd1,d2,y,x,P=1000,Z=0.84,Qg=15,T=520,t=3,Q0=3000,R,ratio,ratio1,ratio01,ratio11,rounded_cd1,temp,LgD,Ls,Ls1,Lg,D2L,L0,r1,r2;
double cd = 0.34;

double Calculate_RG(double r, int d, double cratio)
{	
	temp2=d;
	y = ((pg/(p0-pg))*(r/dm));
	
	LgD= 422*((T*Z*Qg)/P)*sqrt(y);
	LgD= floor(LgD * 1000)/1000;

	
	Lg = LgD/temp2;
	Lg= floor(Lg * 1000)/1000;
	
	Ls = Lg + (temp2/12);
	Ls= floor(Ls * 1000)/1000;

	
	ratio= (12*Ls)/temp2;
	
	
	
	if(ratio <3.0)
	{
		temp2--;
		Calculate_RG(r,temp2,ratio);
		
	}
	else if(ratio > 5.0)
	{
		temp2++;
		Calculate_RG(r,temp2,ratio);
	}
	
	else if(ratio>=3.0 && ratio <=5.0)
	{
		
		if(ratio>cratio)
		{
			
			printf("%d\t\t %0.2f\t\t %0.2f\t\t %0.2f\n\n",temp2,Lg,Ls,ratio);
			t2=temp2-1;
			if(round(ratio)!=5)
			{
				Calculate_RG(r,t2,ratio);
			}
			
	
  		}
		else if(ratio<cratio)
		{
			printf("%d\t\t %0.2f\t\t %0.2f\t\t %0.2f\n\n",temp2,Lg,Ls,ratio);
			t2=temp2+1;

			if(round(ratio)!=3)
			{
				Calculate_RG(r,t2,ratio);
			}
	
		}	
	}
	
	cratio= ratio;
	return cratio;
 }
 
 
 double Calculate_RL(int d2, double cratio1)
 {
 	temp3 = d2;
 	D2L= (Q0*t)/0.7;
 	L0 = D2L/(temp3*temp3);
 	Ls1 = 1.333*L0;
  	ratio1 = (12*Ls1)/temp3;
 	
 	if(ratio1 < 3)
	{
		temp3--;
		Calculate_RL(temp3,ratio1);
	}
	else if(ratio1 > 5)
	{
		temp3++;
		Calculate_RL(temp3,ratio1);
	}
	else if (ratio1>3 && ratio1<5)
	{
		if(ratio1<cratio1)
		{
			printf("%d\t\t %0.2f\t\t %0.2f\t\t %0.2f\n\n",temp3,L0,Ls1,ratio1);
			temp3++;
			if(round(ratio1)!=3)
			{
					Calculate_RL(temp3,ratio1);
			}
		
		}
		else
		{
			printf("%d\t\t %0.2f\t\t %0.2f\t\t %0.2f\n\n",temp3,L0,Ls1,ratio1);
			temp3--;
			if(round(ratio1)!=5)
			{
					Calculate_RL(temp3,ratio1);
			}			
		}
		
	}
	cratio1=ratio1;
	return cratio1;
 }
//2

double Calculate_cd1(double f)
{
	temp = f;
	x = ((p0-pg)/pg) * (dm/temp);
	Uo = 0.01186*sqrt(x);
	Re = 0.0049*((pg*dm*Uo)/ug);
	cd1= ((24/Re) + (3/sqrt(Re)) + 0.34);
	rounded_cd1 = floor(cd1 * 100)/100;
	//printf("%f",rounded_cd1);

	if(f == rounded_cd1)
	{
		printf("\nFOR GAS CAPACITY:\n");
		printf("D\t\t Lg\t\t Ls\t\t Ratio\n\n");
		Calculate_RG(rounded_cd1,D,0.0);
		printf("\nFOR LIQUID CAPACITY:\n");
		printf("D\t\t L0\t\t Ls\t\t Ratio \n\n");
		Calculate_RL(D,0.0);
	}
	else
	{
		
		Calculate_cd1(rounded_cd1);

	}
	
}

//1

input()
{
	printf("-------------------PROTOTYPE------------------------\n\n");
	printf("----WELCOME TO HORIZONTAL OIL SEPERATOR PROGRAM!----\n\n");
	printf("------------START INPUTTING THE VALUES--------------\n\n");
	
	printf("Enter the P0: ");
	scanf("%f",&p0);
	
	printf("Enter the Pg: ");
	scanf("%f",&pg);
	
	printf("Enter the Dm: ");
	scanf("%f",&dm);
	
	printf("Enter the  Ug: ");
	scanf("%f",&ug);
	
	printf("Enter the  T: ");
	scanf("%f",&T);
	
	printf("Enter the  P: ");
	scanf("%f",&P);
	
	printf("Enter the  Z: ");
	scanf("%f",&Z);
	
	printf("Enter the  Qg: ");
	scanf("%f",&Qg);
	
	printf("Enter the  Q0: ");
	scanf("%f",&Q0);
	
	printf("Enter the  t: ");
	scanf("%f",&t);
	
	printf("Enter the  D: ");
	scanf("%d",&D);

}

void main()
{
 
printf("RESULT:\n \n");
Calculate_cd1(cd);
}
