#include<stdio.h>
#include "avg.h"

int main(int argc, char const *argv[])
{
    float a[100], res;
    int i, n;
    printf("Enter no. of elements: \n");
    scanf("%d", &n);

    for(i=0;i< n;i++)
    {
        printf("a[%d]= ",i);
        scanf("%f", &a[i]);
    }

    res = average(a,n);
    printf("Average = %f\n", res);
    
    return 0;
}

