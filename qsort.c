#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
	int tem=*a;
	*a=*b;
	*b=tem;
}
void sort(int arr[],int front,int last)
{
	if(front>=last)
		return;
	int i=front,j=last-1;
	int flag=arr[last];
	int pos=last;
	while(1)
	{
		while(arr[i]<flag && i<=last)
			i++;
		while(arr[j]>=flag && j>=0)
		{
			if(arr[j]>=flag && (j==0 || arr[j-1]<flag))
				pos=j;
			j--;
		}
		if(i>=j)
			break;
		swap(&arr[i],&arr[j]);
	}
	swap(&arr[pos],&arr[last]);
	sort(arr,front,pos-1);
	sort(arr,pos+1,last);

}
int main(void)
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
		if((i+1)%10==0)
			printf("\n");
	}
	return 0;
}
