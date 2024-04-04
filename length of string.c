#include<stdio.h>
 void main()
 {
    int length=0;
    char word[100],*ptr;
    printf("Enter the word\n");
    scanf("%s",word);
   
 /*for(i=0;i,size;i++)
{
    scanf("d",&arr[i]);
    
}*/
ptr=word;
while((*ptr)!='\0')
{
    length++;
    ptr++;
}
printf("length of the array:%d\n",length);
}
