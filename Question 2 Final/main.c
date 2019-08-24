/*
  This Program computes values of special products for elements of an 1D array
*/

#include <stdio.h>
#include <stdlib.h>

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
    while(!feof(in)){                    // Reading the input numbers and saving them in arr_in[]
            fscanf(in,"%d", &arr_in[i]);
            i++;
    }
    close(in);

    nc=i;                            // nc counts the number of input values


    getSpecialProducts(arr_in, nc);

    return 0;
}

void getSpecialProducts(int arr_input[100], int cnt)
{
   FILE *out;

   int i, j;
   long long int arr_output[100];

   for (i=0;i<cnt;i++)
         arr_output[i]=1;

    for(i=0;i<cnt;i++)                       // Loop to computes the values of special product and save in
        for(j=0;j<cnt;j++)                   //                          arr_output[]
            if(j!=i)
               arr_output[i] *= arr_input[j];

//******************************************************************
// Printing Results
//

    out=fopen("Result.txt","w"); // Opening output file of results
    if(!out){
        printf("cannot open the Result file");
        getch();
        exit(0);
    }

    fprintf(out, "[");
    for(i=0;i<cnt;i++)
        fprintf(out, "%lld\t",arr_output[i]);
    fprintf(out, "]");

    fclose(out);

}

