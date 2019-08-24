#include <stdio.h>
#include <stdlib.h>

// Solves the problem completely. Just function has not been defined here.

void getSpecialProducts(int arr_input[100], int);
int main(int argc, char *argv[])
{
    FILE *in;
    int i, j, nc=0;
    int arr_in[100];


// checking arguments of main()

   if(argc<=1){
        printf("number of parameters is wrong");
        getch();
        exit(0);
    }
    in=fopen(argv[1],"r"); // Opening input file of data
    if(!in){
        printf("cannot open the Input file");
        getch();
        exit(0);
    }

    i=0;
    while(!feof(in)){
            fscanf(in,"%6d", &arr_in[i]);
            i++;
    }
    close(in);

    nc=i;


    getSpecialProducts(arr_in, nc);

    return 0;
}

void getSpecialProducts(int arr_input[100], int cnt)
{
   FILE *out;

   int i, j;
   long long int arr_output[100];

   printf("The Concatenated List Of Integers is :\n");

   for (i=0;i<cnt;i++)
        printf("%6d", arr_input[i]);

   for (i=0;i<cnt;i++)
         arr_output[i]=1;

    for(i=0;i<cnt;i++)
        for(j=0;j<cnt;j++)
            if(j!=i)
               arr_output[i] *= arr_input[j];

    printf("\nResults:\n");
    for (i=0;i<cnt;i++)
        printf("\t%lld", arr_output[i]);


   getch();

  }

