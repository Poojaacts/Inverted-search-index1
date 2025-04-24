/*
Name:Pooja B S
Date:
Title:
Sample input:
Sample output:
 */

#include<stdio.h>
#include"main.h"

int save_database(main_node_t *hash_table[],char *file)
{
    if(strcmp(strstr(file,"."),".txt")!=0)
    {
	return FAILURE;
    }
    else
    {
	FILE *fptr=fopen(file,"w");
	for(int i=0;i<27;i++)
	{

	    if(hash_table[i]!=NULL)
	    {

		main_node_t *temp=hash_table[i];

		while(temp!=NULL)
		{
		    fprintf(fptr,"%d : %s : %d ",i,temp->word,temp->file_count);

		    sub_node_t *subtemp=temp->sublink;
		    while(subtemp!=NULL)
		    {
			fprintf(fptr,"%s : %d ",subtemp->sub_filename,subtemp->word_count);

			subtemp=subtemp->next_sub_link;
		    }
		    fprintf(fptr,"\n");

		    temp=temp->next_main_link;
		}
	    }
	}
	return SUCCESS;
    }
}



/*
#include <stdio.h>
#include<string.h>
#include"main.h"


int save_database(main_node_t *hash_table[],char *file);
{
    char filename[50] ;
    printf("Enter the file name you want to take backup : ") ;
    scanf("%s",filename) ;
    if(strstr(filename,".txt") == NULL)
    {
	return FAILURE ;
    }
    FILE * fptr = fopen(filename,"w") ;
    if(fptr == NULL)
    {
	return FAILURE ;
    }
    for(int i=0;i<27;i++)
    {
	main_node * temp1 = HT[i].link ;
	while(temp1 != NULL)
	{
	    fprintf(fptr,"%c",'#') ;
	    fprintf(fptr,"%d,",i) ;
	    fprintf(fptr,"%s,",temp1->word) ;
	    fprintf(fptr,"%d,",temp1->file_count) ;
	    sub * temp2 = temp1->sublink ;
	    while(temp2 != NULL)
	    {
		fprintf(fptr,"%s,",temp2->filename) ;
		fprintf(fptr,"%d,",temp2->word_count) ;
		temp2 = temp2->sublink ;
	    }
	    fprintf(fptr,"%s","#\n") ;
	    temp1 = temp1->mainlink ;
	}
    }
    fclose(fptr) ;
    return SUCCESS ;
}

*/
