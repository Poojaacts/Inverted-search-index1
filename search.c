


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"main.h"

int search_database(main_node_t *hash_table[],char *word)
{
    int index;
    if(word[0]>='a' && word[0]<='z' || word[0]>='A' && word[0]<='Z')
    {
	index= tolower(word[0]) % 97;
    }
    else
    {
	index=26;
    }
    if(hash_table[index] != NULL)
    {
	main_node_t *temp=hash_table[index];
	while(temp!=NULL)
	{
	    if(strcmp(temp->word,word)==0)
	    {
		printf("The word %s is present in %d files\n",temp->word,temp->file_count);

		sub_node_t *subtemp=temp->sublink;

		while(subtemp !=NULL)
		{
		    printf("%s presents %d times\n",subtemp->sub_filename,subtemp->word_count);

		    subtemp=subtemp->next_sub_link;

		}
		return SUCCESS;
	    }
	    else
	    {
		temp=temp->next_main_link;
	    }
	}
    }
    return FAILURE;
}


