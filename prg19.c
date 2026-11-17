#include<stdio.h>
#include<stdlib.h>
int main()
{
    int*p,n,i,sum=0,max,min;
    printf("enter number of element:");
    scanf("%d",&n);
    if(n<=0)
      return 0;
    p=(int*)malloc(n*sizeof(int));
    if(p==NULL)
    {
        printf("memory allocation failed!\n");
        return 1;
    }  
    printf("enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",p+i);
    }
    max=min=*p;
    for(i=0;i<n;i++)
    {
        sum += *(p+i);
        if(*(p+i)>max)
          max = *(p+i);
        if(*(p+i)<min)
          min=*(p+i);
    }
    printf("sum=%d\n",sum);
    printf("average=%.2f\n",(float)sum/n);
    printf("largest=5d\n",max);
    printf("samallest=%d\n",min);
    free(p);
    return 0;
}
