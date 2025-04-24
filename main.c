/*
Name:Pooja B S
Date:
Title:
Sample input:
Sample output:
 */

#include<stdio.h>
#include"main.h"

int main(int argc,char *argv[])
{
    slist *head=NULL;
    if(argc<2)
    {
	printf("Invalid Arguements, Please provide atleast 2 arguemrnts");
    }
    else
    {
	if(read_and_validate(argc,argv,&head)==SUCCESS)
	{
	    printf("Read and validate are done successfully\n");
	}
	else
	{
	    printf("Read and validate is failed\n");
	}

    }
    printf("\n");
    main_node_t *hash_table[27]={NULL};
    int option;
    char ch;
    do
    {
	printf("1.create Database\n2.Display Database\n3.Search Database\n4.Save Database\n5.Update Database\n\n");
	printf("Enter the choice: ");
	scanf("%d",&option);
	switch(option)
	{
	    case 1:
		printf("1.Create Database\n");
		if(create_database(&head,hash_table)==SUCCESS)
		{
		    printf("Create database done successfully\n");
		}
		else
		{
		    printf("Create_database failed\n");
		}
		break;
	    case 2:
		printf("2.Display Database\n");

		display_database(hash_table);
		break;
	    case 3:
		printf("Search Database\n");

		char word[20];
		printf("Enter the word to search: \n");
		scanf("%s",word);

		if(search_database(hash_table,word)==SUCCESS)
		{
		    printf("Word is found\n");
		}
		else
		{
		    printf("Word is not found\n");
		}

		break;
		  
	    case 4:
		printf("Save Database\n");

		char filename[20];
		printf("Enter the backup file name in .txt extension:");
		scanf("%s",filename);

		if(save_database(hash_table  ,filename  )==SUCCESS)
		{
		    printf("Saved the data successfully\n");
		}
		else
		{
		    printf("Failed to save data\n");
		}
		break;
	   
	    case 5:
		printf("Update Database\n");

		char file_name[20];
		printf("Enter the file name to update in .txt extension:");
		scanf("%s",file_name);
		if(update_database(hash_table,file_name,head)==SUCCESS)
		{
		    printf("Update database is done successfully\n");
		}
		else
		{
		    printf("Update database is failed\n");
		}
		break;
	}
	printf("\n");

	printf("Do you want to continue(y/n): \n");
	scanf(" %c",&ch);

    }while(ch=='Y'|| ch=='y');

}



