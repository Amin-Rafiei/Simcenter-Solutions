#include <stdio.h>
#include <conio.h>

int main()
{
    int num, i, sum=0;
    float ave;
    const int n=3;

    for(i=0; i<n; i++) {
        printf("enter number %d :",i+1);
        scanf("%d",&num);
        sum += num;
        }

        ave=(float)sum/n;

        printf("\n the average is : %6.2f", ave);

        getch();


    return 0;
}
