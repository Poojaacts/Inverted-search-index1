/*
Name:Pooja B S
Date:
Title:
Sample input:
Sample output:
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"main.h"

int Insert_at_last(char *filename,slist **head)
{
    slist *new=malloc(sizeof(slist));
    strcpy(new->file_name,filename);
    new->link=NULL;
    if(*head==NULL)
    {
	*head=new;
	return SUCCESS;
    }
    else
    {
	slist *temp=*head;
	slist *pre=NULL;
	while(temp!=NULL)
	{
	    if(strcmp(temp->file_name,filename)==0)
	    {
		printf("DUPLICATE FILE IS PRESENT\n");
		return FAILURE;
	    }
	    else
	    {
		pre=temp;
		temp=temp->link;
	    }
	}
	pre->link=new;
	return SUCCESS;
    }
}



