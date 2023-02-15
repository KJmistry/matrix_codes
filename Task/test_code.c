#include <stdio.h>
#include <math.h>
#include <string.h>
#define toInt(x) x - '0'

int power(int base, int power)
{
    int ans = 1;
    for (int i = 0; i < power; i++)
    {
        ans *= base;
    }
    return ans;
}

int main()
{
    char num1[10]; // len = m
    printf("Enter First Number:\n");
    scanf("%s", num1);
    char num2[10]; // len = n
    printf("Enter Second Number:\n");
    scanf("%s", num2);

    int num1len = strlen(num1);
    int num2len = strlen(num2);

    // performing  (num1*num2) /// m*n
    int finalMul = 0;
    int decTB = power(10, (num2len - 1));

    for (int topBotIndex = 0; topBotIndex < num2len; topBotIndex++)
    {
        int tempOne = 0, decLR = power(10, (num1len - 1));
        for (int lefRgtIndex = 0; lefRgtIndex < num1len; lefRgtIndex++)
        {
            tempOne += ((toInt(num1[lefRgtIndex])) * (toInt(num2[topBotIndex]))) * decLR;
            // printf("%d--\n",tempOne);

            decLR /= 10;
        }
        finalMul += (tempOne)*decTB;
        decTB /= 10;
    }
    // printf("%d",finalMul);
    char ans[50];
    sprintf(ans, "%d", finalMul);
    printf("Final Ans in String Format : %s\n", ans);
}