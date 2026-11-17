#include<stdio.h>
long factorial(int n)
{
    if(n<=1)
      return 1;
    return n * factorial(n-1);  
}
long power(int x,int n)
{
    if(n==0)
      return 1;
    return x * power(x,n-1);  
}
int gcd(int a,int b)
{
    while(b !=0)
    {
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int main(void)
{
    int choice,a,b,n,x;
    do
    {
        printf("1.GCD\n2.LCM\n3.factorial(recursion)\n");
        printf("4.x raised to (recursion)\n5.exit\n");
        printf("enter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("enter two non- negetive integers:");
            scanf("%d%d",&a,&b);
            printf("GCD=%d\n",gcd(a,b));
            break;
        case 2:
            printf("enter two positive integer:");
            scanf("%d%d",&a,&b);
            if(a>0 && b>0)
              printf("LCM=%d\n",(a/gcd(a,b))*b);
            else
              printf("enter positive integer.\n");
            break;
        case 3:
            printf("enter n(0 to 20):");
            scanf("%d",&n);
            if(n>=0 && n<=20)
              printf("factorial=%lld\n",factorial(n));
            else
              printf("enter n between 0 to 20.\n");
            break;
        case 4:
            printf("enter x and non- negetive power n:");
            scanf("%d%d",&x,&n);
            if(n>=0)
               printf("power=%lld\n",power(x,n));
            else
               printf("power n must be non-negetive.\n");
            break;
        case 5:
            printf("exiting...\n");
            break;
        default:
              printf("invalid choice.\n");                                
        }
    }
    while( choice!=5);
    return 0;
}