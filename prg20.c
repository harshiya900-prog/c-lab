#include<stdio.h>
struct student
{
  int reg;
  char name[30];
  int m1,m2,m3;
};
void show(struct student s)
{
  int total=s.m1+s.m2+s.m3;
  float per=total/3.0f;
  printf("\n register:%d\n",s.reg);
  printf("name:%s\n",s.name);
  printf("marks:%d %d %d\n",s.m1,s.m2,s.m3);
  printf("total:%d\n",total);
  printf("percentage:%.2f\n",per);
  if(s.m1<35||s.m2<35||s.m3<35)
    printf("result:fail\n");
  else
    printf("result:pass\n");  
}
int main()
{
  struct student s;
  FILE *fp;
  int ch,key,found;
  do
  {
    printf("\n1.add record");
    printf("\n2.dispiay record");
    printf("\n3.search regidter number");
    printf("\n4.exit");
    printf("\n enter your chice :");
    scanf("%d",&ch);
    if(ch==1)
    {
      printf("enter regidter number and name:");
      scanf("%d %29s",&s.reg,s.name);
      printf("enter marks in three subjects:");
      scanf("%d %d %d",&s.m1,&s.m2,&s.m3);
      fp=fopen("student.txt","a");
      if(fp==NULL)
      {
        printf("cannot open file\n");
        continue;
      }
      fprintf(fp,"%d %s %d %d %d\n",s.reg,s.name,s.m1,s.m2,s.m3);
      fclose(fp);
      printf("record added successfully.\n");
    }  
    else if(ch==2)
    {
      fp=fopen("student.txt","r");
     if(fp==NULL)
     {
       printf("NO records found.\n");
       continue; 
     }
     while(fscanf(fp,"%d %29s %d %d %d",&s.reg,&s.name,&s.m1,&s.m2,&s.m3)==5)
     {
       show(s);
     }
     fclose(fp);
    }
   else if (ch==3)
   {
     printf("enter register number to search:");
     scanf("%d",&key);
     found=0;
     fp=fopen("student.txt","r");
     if(fp==NULL)
     {
       printf("NO records found.\n");
       continue;
     }
     while(fscanf(fp,"%d %29s %d %d %d", &s.reg,s.name,&s.m1,&s.m2,&s.m3)==5)
     {
       if(s.reg==key)
       {
         show(s);
         found=1;
       }
     }
     fclose(fp);
     if(!found)
       printf("record not found.\n");
   }
   else if(ch!=4)
   {
     printf("invalid choice.\n");
   }
  }
  while(ch!=4);
  return 0; 
}