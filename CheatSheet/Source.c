#include <stdio.h>
#include <stdlib.h>

//Calling Methods Before using
void name(int name1);
void fileAccess();
void pointers();

//Struct
typedef struct structName
{
	char name[20];
	int num2;
}structName;

void main()
{
	//Declare Variables
	int num;

	//Declare Struct
	structName example;

	//Array of struct
	structName array[5];

	//Asking user to input for struct
	for (int i = 0; i < 5; i++)
	{
		printf("Please enter name for array: ");
		scanf("%s", array[i].name); //Dont need & for strings

		printf("Please enter num for array: ");
		scanf("%d", &array[i].num2);

		printf("\n");
	}

	//Display Struct Array info
	for (int j = 0; j < 5; j++)
	{
		printf("Name: %s \t Num: %d", array[j].name, array[j].num2);
	}

	//Pointers
	//Declare Variables
	int size = 0; // can ask user to enter how big they would like array

	//Declare pointer array
	structName* pointr;
	pointr = (structName*)malloc(size * sizeof(structName));

	//How to pass pointers to functions
	pointers(pointr, size); //Pass the pointer made and the size of it
}

void fileAccess()
{
	int num = 5;

	//Object of File
	FILE* newFile;

	//Open File to write to
	newFile = fopen("newFile.txt", "w");

	//"a" to append file
	//"r" to read file

	//Write to File
	fprintf("Write here \nNumber %d", num);

	//Close File
	fclose(newFile);
}

void pointers(structName* pointr, int size)
{
	//Declare Variables
	int findptr, changeptr;

	//Set Array items to 0
	for (int i = 0; i < size; i++)
	{
		(*(pointr + i)).num2 = 0;
	}

	//Assign to array
	//to check if array address is empty
	for (int j = 0; j < size; j++)
	{
		if ((*(pointr + j)).num2 == 0)
		{
			//Add detials to next empty array 
			printf("Please Enter Number: ");
			scanf("%d", &(*(pointr + j)).num2);

			printf("Please Enter Name: ");
			scanf("%s", (*(pointr + j)).name);

			return; //Do this so it wont loop back to find next empty 
		}
	}

	//Display Pointer
	//Ask for Book Number
	printf("\nEnter Book Number you want to display: ");
	scanf("%d", &findptr);

	//Check if pointer is not empty
	for (int i = 0; i < size; i++)
	{
		if ((*(pointr + i)).num2 == findptr)
		{
			printf("\nNumber: %ld", (*(pointr + i)).num2);
			printf("\nName: %s", (*(pointr + i)).num2);

			return; //Do this so it wont loop back to find next empty 
		}
	}

	//To edit a spefic pointer 
	//ask for num we do this as we will use one of the variables in struct to define each array
	printf("\nEnter Number you want to change the name of: ");
	scanf("%d", &changeptr);

	//find pointer you want to change
	for (int i = 0; i < size; i++)
	{
		if ((*(pointr + i)).num2 == changeptr)
		{
			//Display old Name
			printf("\nName: was %s", (*(pointr + i)).name);

			//Change Name
			printf("\nNew Name:");
			scanf("%s", &(*(pointr + i)).name);
		}
	}


}