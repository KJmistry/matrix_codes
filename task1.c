#include <stdio.h>
#include <string.h>
#include <math.h>
int calc(char,int);
void rearrange(int*,char*,int);
int arr[100];
int main()
{
   char str[100],opr[100];
   static int lb=0,index=0,opr_index=0;
   scanf("%s",&str);
   //fgets(str,100,stdin);  
   for(size_t i=0;i<strlen(str)+1;i++)
   {
       //printf("_flag_%d___%d\n",i,str[i]);
       if(str[i]=='+'||str[i]=='-'||str[i]=='/'||str[i]=='*'||str[i]==0)
       {  
           opr[opr_index]=str[i];
           opr_index++;
           //printf("%c====%d\n",str[i],i);
           //int p=i-lb
           //int dec=pow(10,p-1),value=0;
           int dec=1,value=0;
           for(int k=i-1;k>=lb;k--)
           {  
               //printf("%c====%d\n",str[k],k);
               value+=(str[k]-'0')*dec;
               //printf("%d\n",value);
               dec*=10;
           }
           arr[index]=value;
           index++;
           lb=i+1;
       }
  
   }
          
   // for(int i=0;i<3;i++)
   // {
   //     printf("%d\n",arr[i]);
   // }
   // for(int i=0;i<3;i++)
   // {
   //      printf("%c--->%d\n",opr[i],opr[i]);
   // }

   static int ans;
   if(index>1)
   {   static int c;
       c = 99;
       for(int i=0;i<index-1;i++)
       {
           if(opr[i]=='*'||opr[i]=='/')
           {

            rearrange(arr,opr,i);
            //    ans=calc(opr[i],i);
            //    if(i==c+1)
            //    {
            //        arr[i-1]=ans;
            //        printf("--------\n");
            //    }
            //    printf("--%d\n",ans);
            //    c=i;
           }
       }
       for(int i=0;i<index-1;i++)
       {
           if(opr[i]=='+'||opr[i]=='-')
           {
               ans=calc(opr[i],i);
               printf("--%d\n",ans);
           }
       }
   }
   else
   {
       ans=arr[0];
   }
   printf("final ans %d\n",ans);
   return 0;
}

int calc(char opr,int i)
{  
   int ans=0;
   printf("%d--%c--%d\n",arr[i],opr,arr[i+1]);
   switch (opr)
       {
           case 43://+
             ans=arr[i]+arr[i+1];
             //printf("sum\n");
             break;
           case 45://-
             ans=arr[i]-arr[i+1];
             //printf("sub\n");
             break;
           case 47:///
             ans=arr[i]/arr[i+1];
             //printf("div\n");
             break;
           case 42://*
             ans=arr[i]*arr[i+1];
             //printf("mul\n");
             break;
       }
   //arr[i]=ans;
   //arr[i+1]=ans;
   return ans;
}

void rearrange(int arr[],char opr[],int m)
{
        arr[m]=calc(opr[m],m);
        for(int i=m+1;i<index-1;i++)
        {
            arr[i]=arr[i+2];
        }
        for(int i=m;i<index-1;i++)
        {
            opr[i]=opr[i+1];
        }
}