#include <stdio.h>
#include<string.h>
#include <math.h>
#define toInt(x) x - '0'
void reverseStr(char *str, int strLen)
{
    char temp;
    for(int index = 0 ; index < strLen/2 ; index++ )
    {
        temp = str[index];
        str[index] = str[strLen - (index + 1)];
        str[strLen - (index + 1)] = temp;
    }
}

int addStr(char *str1,char *str2,int len1,int len2, char *finalSum)
{
    int maxLen = len1;

    if(len1 < len2)
    {
        maxLen = len2;
        for(int i = len1; i < len2;i++)
        {   
           str1[i] = '0'; 
        }
        reverseStr(str1,maxLen);
    }
    
    if(len2 < len1)
    {
        for(int i = len2; i < len1;i++)
        {   
           str2[i] = '0'; 
        }
        reverseStr(str2,maxLen);

    }

    int tSum = 0,carry = 0, index = 0,tIndex = 0;
    finalSum[maxLen+1] = '\0';
    for(index = maxLen - 1 ; index >= 0  ; index-- )
    {
        tSum = (toInt(str1[index]))+(toInt(str2[index]))+carry;  
        carry = 0 ;
        if( tSum > 9)
        {
            finalSum[tIndex] = (tSum % 10) + '0';            
            carry = 1;
        }
        else
        {
            finalSum[tIndex] = tSum + '0';            
        }
        tIndex++;
    }

    if( carry == 1)
    {
        finalSum[tIndex] = 1 + '0';
    } 
    finalSum[tIndex+1] = '\0';
    return 0;
}

int main()
{
    char n1[] = "9999";
    char n2[] = "9999";
    char ans[30];

    addStr(n1,n2,strlen(n1),strlen(n2),ans);

    printf("%s",ans);

}