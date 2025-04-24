/*
Name:Pooja B S
Date:
Title:
Sample input:
Sample output:
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
//#include "insert_at_last.c"

int read_and_validate(int argc,char *argv[],slist **head)
{
    int i;
    for(i=1;i<argc;i++)
    {
	//printf("NO DUPLICATE FILES\n");
	if(strcmp(strstr(argv[i],"."),".txt")==0)
	{
	    printf("File is .txt file\n");
	    FILE *fptr=fopen(argv[i],"r");
	    if(fptr!=NULL)
	    {
		printf("File is present\n");
		fseek(fptr,0,SEEK_END);
		if(ftell(fptr)!=0)
		{
		    printf("File is not Empty\n");

		    if(Insert_at_last(argv[i],head)==SUCCESS)
		    {
			printf("Insert at last is done successfully\n");
		    }
		    else
		    {
			printf("Failed to Insert at last \n");
		    }
		}
		else
		{
		    printf("File is Empty\n");
		}
	    }
	    else
	    {
		printf("File is not present\n");
	    }
	}
	else
	{
	    printf("File is not .txt file\n");
	}
    }
    return SUCCESS;
}


