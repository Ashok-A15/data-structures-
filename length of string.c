#include<stdio.h>
 void main()
 {
    int length=0;
    char word[100],*ptr;
    printf("Enter the word\n");
    scanf("%s",word);
ptr=word;
while((*ptr)!='\0')
{
    length++;
    ptr++;
}
printf("length of the array:%d\n",length);
}
