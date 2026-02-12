#include<stdio.h>
#include<stdio.h>
#define MAX 100
void printBins(int binsused)
{
	printf("bins used: %d\n",binsused);
}
void firstFit(int weight[],int n,int capacity)
{
	int bin_rem[MAX];
	int binsused=0;
	int i,j;
	for(i=0;i<n;i++)
	{
		int placed=0;
		for( j=0;j<binsused;j++)
		{
			if(bin_rem[j]>=weight[i])
			{
				bin_rem[j]-=weight[i];
				placed=1;
				break;
			}
		 	
		}
		if(!placed)
		{
			bin_rem[binsused]=capacity-weight[i];
			binsused++;
		}
	}
	printf("first fit:");
	printBins(binsused);
}
int compare(const void *a,const void *b)
{
	return(*(int*)b-*(int*)a);
}
void firstFitDecreasing(int weight[],int n,int capacity){
	int sorted[MAX];
	int i;
	for( i=0;i<n;i++)
	{
		sorted[i]=weight[i];
	}
	qsort(sorted,n,sizeof(int),compare);
	printf("first fit decreasing:");
	firstFit(sorted,n,capacity);
}
void bestFit(int weight[],int n,int capacity)
{
	int bin_rem[MAX];
	int binsused=0;
	int i,j;
	for( i=0;i<n;i++)
	{
		int bestindex=-1;
		int min_space=capacity+1;
		for( j=0;j<binsused;j++)
		{
			if(bin_rem[j]>=weight[i])
			{
				int left=bin_rem[j]-weight[i];
				if(left<min_space)
				{
					min_space=left;
					bestindex=j;
				}
			}
		}
		if(bestindex!=-1)
		{
				bin_rem[bestindex]-=weight[i];
		}
		else
		{
			bin_rem[binsused]=capacity-weight[i];
			binsused++;
		}
	}
		printf("bestfit:");
		printBins(binsused);	
}
int main()
{
	int n,capacity,i;
	int weight[MAX];
	printf("enter number of items:");
	scanf("%d",&n);
	printf("Enter bin capacity: ");
    scanf("%d", &capacity);
    printf("Enter item weights:\n");
    for ( i = 0; i < n; i++)
	{
        scanf("%d", &weight[i]);
    }

    firstFit(weight, n, capacity);
    firstFitDecreasing(weight, n, capacity);
    bestFit(weight, n, capacity);
	return 0;
}
	

