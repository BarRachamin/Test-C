#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)



void Exe_1()
{
	char arr[100];
	scanf("%s", &arr);
	int len = strlen(arr) / 2;
	for (int i = 0; i < strlen(arr); i++)
	{
		printf("%c", arr[i]);
		if (i == len)
		{
			printf("\n");
		}
	}

}



void Exe2()
{
	char arr[100];
	scanf("%s", &arr);
	int len = strlen(arr) / 2;
	for (int i = 0; i < strlen(arr); i++)
	{
		printf("%c", arr[i]);
		if (len == 1)
		{
			return;
		}
		if (i == len)
		{
			printf("\n");
			i = 0;
			len = len / 2;
		}
		
	}
}



void Exe3(int num)
{
	printf("%d\n", num);
	if (num == 100)
	{
		return;
	}
	Exe3(num + 1);
}



typedef struct s_Lotto
{
	
	int Lottery_Number;
	char  Date[20];
	char Numbers[50];
	struct s_Lotto* next;
	struct s_Lotto* prev;
} Lotto;
Lotto* HEAD_List=NULL;
Lotto* TAIL_List=NULL;

void ReadFile();
void Make_dictionary_List( Lotto* curr);
void search(int number);





void ReadFile()
{

	FILE* Lotto_file= fopen("Lotto.txt", "r");
	if (!Lotto_file)
	{
		//error

	}
	char str[1000];
	char* token = NULL;
	fgets(str, 1000, Lotto_file);
	while (str[0] != NULL)
	{
		 Lotto* curr;
		curr = ( Lotto*)malloc(sizeof( Lotto));
		if (!curr)
		{
			//log error;
			return;
		}
		token = strtok(str, ",");
		int num;
		num = atoi(token);
		curr->Lottery_Number = num;

		token = strtok(NULL, ",");
		//char theyear[15];
		strcpy(curr->Date, token);

		token = strtok(NULL, "\n");
		strcpy(curr->Numbers, token);

		Make_dictionary_List(curr);
		//MATA-DATA

		str[0] = NULL;
		fgets(str, 1000, Lotto_file);


	}

}


void Make_dictionary_List( Lotto* curr)
{

	if (HEAD_List == NULL)
	{
		HEAD_List = TAIL_List = curr;
		curr->next = NULL;
		curr->prev = NULL;
	}
	else
	{
		TAIL_List->next = curr;
		curr->prev = TAIL_List;
		curr->next = NULL;

		TAIL_List = curr;
	}

}

void search(int number)
{
	 Lotto* Look;
	Look = HEAD_List;


	while (Look->Lottery_Number != number)
	{
		if (Look->next != NULL)
		{
			Look = Look->next;
		}
		else
		{
			printf("NOT FOUND\n");
			return;
		}

	}
		printf("%s\n", Look->Date);
	

}


void Exe4()
{
	printf("Hi Dear User \nWhat would you like to do?\n R-Read File\n  S-search Lottery Number\n Q-to EXIT\n");

	char userResponse = 0;
	while (userResponse != 'Q')
	{

		scanf(" %c", &userResponse);

		switch (userResponse)
		{
		case 'R':
			ReadFile();
			printf("Read file\n");

			break;
		case 'S':
			printf("choose lottery Number to search\n");
			int number;
			scanf("%d", &number);
			search(number);
			break;
		default:
			printf("not Exist\n");
			break;
		}
		printf("Hi Dear User \nWhat would you like to do?\nR-Read File \n S-search Lottery Number\n Q-to EXIT\n");
	}
	printf("Good Bye");
}


main()
{
	//Exe_1();
	//Exe2();
	//Exe3(1);
	Exe4();

	

	

	
}