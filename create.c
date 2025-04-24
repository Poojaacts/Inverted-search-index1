/*
Name:Pooja B S
Date:
Title:
Sample input:
Sample output:
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"main.h"

int create_database(slist **head,main_node_t *hash_table[])
{
    slist *temp = *head;
    int index;
    char word[WORD_SIZE];
    int word_flag=0,filename_flag=0;



    while(temp != NULL)
    {
	FILE *fptr = fopen (temp -> file_name,"r");
	while(fscanf(fptr,"%s",word)!=EOF)
	{
	    if(word[0] >= 'a' && word[0] <= 'z' || word[0] >= 'A' && word[0] <= 'Z')
	    {
		index=tolower(word[0])%97;
	    }
	    else
	    {
		index=26;
	    }

	    if(hash_table[index] == NULL)
	    {
		main_node_t *m_new = malloc(sizeof(main_node_t));

		sub_node_t *s_new = malloc(sizeof(sub_node_t));

		if(m_new == NULL || s_new == NULL)
		{
		    return FAILURE;
		}


		m_new -> file_count = 1;
		strcpy (m_new -> word,word);

		m_new -> sublink=s_new;
		m_new -> next_main_link= NULL;

		s_new -> word_count = 1;
		strcpy(s_new -> sub_filename,temp -> file_name);
		s_new -> next_sub_link = NULL;

		hash_table[index] = m_new;
	    }
	    else if(hash_table[index] != NULL)
	    {
		main_node_t *main_temp = hash_table[index];

		main_node_t *main_pre;

		while(main_temp)
		{
		    if(strcmp(main_temp -> word,word)!= 0)
		    {
			main_pre= main_temp;
			main_temp=main_temp -> next_main_link;
			word_flag=1;
		    }
		    else
		    {
			word_flag=0;
			sub_node_t *sub_pre;
			sub_node_t *sub_temp=main_temp->sublink;

			while(sub_temp)
			{
			    if(strcmp(sub_temp -> sub_filename,temp -> file_name)!=0)
			    {
				sub_pre=sub_temp;
				filename_flag=1;
				sub_temp=sub_temp->next_sub_link;
			    }
			    else
			    {
				filename_flag=0;
				(sub_temp -> word_count)++;
				break;
			    }
			}

			if(filename_flag)
			{
			    sub_node_t *new_sub= malloc(sizeof(sub_node_t));
			    if(new_sub == NULL)
			    {
				return FAILURE;
			    }

			    new_sub -> word_count=1;
			    strcpy (new_sub -> sub_filename,temp -> file_name);

			    new_sub -> next_sub_link = NULL;
			    sub_pre -> next_sub_link = new_sub;
			    (main_temp -> file_count)++;
			    filename_flag=0;
			}
			break;
		    }
		}

		if(word_flag)
		{
		    main_node_t *new_word_main = malloc(sizeof(main_node_t));
		    sub_node_t *new_file_sub = malloc(sizeof(sub_node_t));


		    if(new_word_main == NULL || new_file_sub == NULL)
		    {
			return FAILURE;
		    }


		    new_word_main -> file_count =1;
		    strcpy(new_word_main -> word,word);

		    new_word_main -> sublink = new_file_sub;
		    new_word_main -> next_main_link = NULL;

		    new_file_sub -> word_count =1;
		    strcpy(new_file_sub -> sub_filename,temp -> file_name);
		    new_word_main -> next_main_link = NULL;


		    main_pre -> next_main_link = new_word_main;
		    word_flag = 0;
		}
	    }
	}
	fclose(fptr);
	temp=temp->link;
    }
    return SUCCESS;
}


