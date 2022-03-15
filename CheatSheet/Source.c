#include <stdio.h>
#include <stdlib.h>

//Calling Methods Before using
void name(int name1);
void fileAccess();

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