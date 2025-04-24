/*
Name:Pooja B S
Date:
Title:
Sample input:
Sample output:
 */
#include<stdio.h>
#include"main.h"


int update_database(main_node_t *hash_table[],char *file_name,slist *head)
{
    //scanf("%s",file_name); 
           
    if(strcmp(strstr(file_name,"."),".txt")==0)
    {
	FILE *fptr=fopen(file_name,"r"); 
	if(fptr==NULL)
	{
	    //perror("error opening file");
	    return FAILURE;
	}
	else
	{
	    fseek(fptr,0,SEEK_END);

	    if(ftell(fptr)!=0)
	    {
		Insert_at_last(file_name,&head);

		create_database(&head,hash_table);

		return SUCCESS;
	    }
	}
    }
}



