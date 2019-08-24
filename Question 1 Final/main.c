/*
  This Programs counts number of characters, words, palindrome words, unique words, and number of lines in a paragraph
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    FILE *in, *out;
    char ch, tmp;
    char str[100], a[50], word[50][50], uniq_word[50][50], str_tmp1[50][50], str_tmp2[50][50];
    int cnt_word_tmp=0, cnt_word=0, cnt_uniq_word=0, cnt_palind=0, cnt_char=0, cnt_line=0,
        i=0, j, k, m,  nreap=0, ndex=0, jndex=0;

// checking the implementation of arguments of main()

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

//************************************************
// Counting numbers of lines, words, and characters
    ch=getc(in);
    while(!feof(in)){

         if(ch=='\n')
            cnt_line++;  // determines number of lines
         else if(ch==' ')
            cnt_word_tmp++;   // determines number of words using space character
         else if(ch!=' '&&ch!='\n'){
            cnt_char++;   // determines number of characters
            if(tmp=='.')
               cnt_word_tmp++; // determines number of words using period character
         }

        tmp=ch;
        if(ch=='.'){
            ndex++;
        }
        else
            str[i-ndex]=ch;  // putting all characters except for period in a string
        i++;                 // str will be used to count number of unique words
        ch=getc(in);
    }
    str[i]='\0';
    fclose(in);

    cnt_line+=1;

    cnt_word=cnt_word_tmp+cnt_line;


//**********************************************************************************
//  Counting number of unique word
//
    i=0;
    for (j = 0;j<=(cnt_word);i++, j++)    //This loop saves all words in a 2D array
    {                                     //             (word[][])
        k = 0;
        tmp=str[0];
        while (str[i] != '\0'){

            if (str[i] == ' '||str[i] == '\n')
                break;
            else {
                word[j][k++] = str[i];
                i++;
            }

        }

        word[j][k] = '\0';
    }

    for(i=0;i<=49;i++)
        strcpy(str_tmp1[i],word[i]);


    i=0, j=0, m=cnt_word;
    for(i=0;i<=cnt_word-1;i++){     // Loop to compute the set of unique words and their numbers
        k=0;
        ndex=0;
        for(j=0;j<=m-1;j++){
           if(!strcmp(word[i],str_tmp1[j])){
                ndex++;
                if(ndex==1){
                    strcpy(uniq_word[jndex], str_tmp1[j]);
                    jndex++;
                }
                else
                    nreap++;         // number of repeated words
           }
           else{
            strcpy(str_tmp2[k],str_tmp1[j]);
            k++;
           }
        }
           m=k;
           for(j=0;j<=k-1;j++)                 // This saves all words except for those which
            strcpy(str_tmp1[j],str_tmp2[j]);   //        have been checked for uniqueness

    }

    cnt_uniq_word = cnt_word-nreap;            // This shows number of unique words


    for(i=0;i<cnt_uniq_word;i++)              // Transforming all capital letters of unique words
        for(j=0;uniq_word[i][j]!=0;j++)       // to small letters. This will be used to count palind. words
            if(uniq_word[i][j]>='A'&&uniq_word[i][j]<='Z')
               uniq_word[i][j]+=32;

// ********************************************************************************
// Checking for palindrome words.

    cnt_palind=0;
    for(i=0; i<cnt_uniq_word;i++){
        strcpy(a,uniq_word[i]);
        strrev(a);
        if(!strcmp(a,uniq_word[i]))
           cnt_palind++;
    }

//*************************************************************************************
// Printing Results
//
    out=fopen("Result.txt","w"); // Opening output file of results
    if(!out){
        printf("cannot open the Result file");
        getch();
        exit(0);
    }

    fprintf(out, "Words #: %2d, Unique Words #: %2d, Palindrome Words #: %2d, Characters #: %2d, Lines #: %2d",
             cnt_word, cnt_uniq_word, cnt_palind, cnt_char, cnt_line);

    fclose(out);


    return 0;

    }
