#include<stdio.h>
#include<conio.h>
void towers(int,char,char,char);
int main()
{
	int num;
	printf("enter no of disk:");
	scanf("%d",&num);
	printf("the sequence of moves involed in tower of hanoi:\n");
	towers(num,'a','b','c');
	return 0;
}
void towers(int num,char source,char dest,char spare)
{
	if(num==1)
	{
		printf("\n move the disc 1 source %C to %C dest\n",source,dest);
		return;
	}
	towers(num-1,source,spare,dest);
	printf("\n to move %d disc source %c to %c dest\n",num,source,dest);
	towers(num-1,spare,dest,source);	
	getch();
}
