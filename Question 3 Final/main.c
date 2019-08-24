/*
  This Program invoke external applications.
*/

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int i, j, k, nfile;
    char str1[10][100], str2[10][100];
    char *args_1[2], *args_2[2];


    printf("Enter the number of files\n");    // number of input files is read from user and saved in nflie
    scanf("%d", &nfile);

    for(i=0;i<nfile;i++)
        strcpy(str1[i],argv[i+1]);           // The name of each file is copied a string

    for(i=0;i<nfile;i++)
        str2[i][0]=' ';


    for(k=0;k<nfile;k++)
        for(j=1;j<100; j++)
           str2[k][j]=str1[k][j-1];


    for(i=0;i<nfile;i++){                    // The generated string including the name of input files is set as
        args_1[0] = str2[i];                 //       the arguments for Application 1
        args_1[1] = NULL;
        spawnv( P_WAIT, "Application_1.exe", args_1);

    }

    args_2[0] = " Result_Application_1.txt";   // The output of application 1 is set as the input file for application 2.
    args_2[1] = NULL;

    spawnv( P_WAIT, "Application_2.exe", args_2);

    return 0;
}
