/*Problem Code: CIELAB*/
#include<stdio.h>
int main(void)
{
	int a, b, dif;
	scanf("%d %d", &a, &b);
	if(a>b)
	{
		dif = a-b;
		if(dif%10 == 9)
			dif=dif-1;
		else
			dif=dif+1;
	}
	else
	{
		dif = b-a;
		if(dif%10 == 9)
			dif=dif-1;
		else
			dif=dif+1;
	}
    printf("%d", dif);
	return(0);
}

