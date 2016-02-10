/* ====================================
 File name: exerc_3_4.c (or cpp)
 Date: 2016-02-08
 Group Number: 33
 Members that contributed:
 Darja Linkova
 Pooriya Balavi
 Andreas Aronsson
 Demonstration code:
 Important , No code no bonus !
 ====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "db.bin"
#define NAMEMAX 20
#define NRMAX 13

// -----Typedefs -------

typedef struct {

	char firstname[20];
	char famnamne[20];
	char pers_number[13]; // yyyymmddnnnc

} PERSON;

// Function declaration (to be extend )
PERSON input_record(void);

void write_new_file(PERSON *inrecord); //Creats a file and write a first record
void printfile(void); // print out all persons in the file
void search_by_firstname(char *name); // print out person if in list
void search_by_lastname(char *name); // print out person if in list
void append_file(PERSON *inrecord); // appends a new person to the file
void search();

int main(void) {

	PERSON *ppost = malloc(sizeof(PERSON));
	int looping = 1;
	//main loop
	printf(
			"please input your command:\n 1 - Write new file.\n 2 - Add a new person to the file.\n 3 - Search for a person. \n 4 - Print records.\n 5 - Exit the program.\n ");

	int userInput;


	while (looping) {
	scanf("%d", &userInput);

	switch (userInput) {
	case 1:
		write_new_file(ppost);
		break;
	case 2:
		input_record();
		break;
	case 3:
		search();
		break;
	case 4:
		printfile();
		break;
	case 5:
		printf("Exiting");
		exit(1);
		break;
	default:
		printf("Invalid input\n");
	}
	}

}

//Creats a file and write a first record
void write_new_file(PERSON *inrecord) {
	FILE *file;

	//TODO if file exsist delete it and create a new
	if (!file) {
		file = fopen(FILENAME, "wb");
		// write a first record
		strncpy(inrecord->firstname , "Andreas", sizeof(inrecord->firstname));
		strncpy(inrecord->famnamne , "Aronsson", sizeof(inrecord->famnamne));
		strncpy(inrecord->pers_number , "198910305674",
				sizeof(inrecord->pers_number));

		fwrite(inrecord, sizeof(PERSON), 1, file);
		fclose(file);
		printf("Writing to file %s \n", FILENAME);
	} else {
		//delete
	}

}

//takes no arguments returns PERSON
PERSON input_record(void) {

	//TODO if fgets is greater than 20 char it will overflow from fname to lname

	PERSON *person = malloc(sizeof(PERSON));
	char fname[NAMEMAX];
	char lname[NAMEMAX];
	char pnr[NRMAX];
	printf("Input Firstname: \n");
	scanf("%s", fname);
	strcpy(person->firstname, fname);

	printf("Your firstname is %s \n", person->firstname);

	printf("Input Lastname: \n");
	scanf("%s", lname);
	strcpy(person->famnamne, lname);
	printf("Your lastname is %s \n", person->famnamne);

	printf("Input person number: \n");
	scanf("%s", pnr);
	strcpy(person->pers_number, pnr);
	printf("Your person number is %s \n", person->pers_number);

	append_file(person);
	return *person;

}

void search() {


	//if nothing is found returns to menu
	int userInput = 0;
	//char searchname[NAMEMAX];
	char searchFor[20];
	int looping = 1;
	printf("SEARCH\n 1 - Search for firstname.\n 2 - Search for family name\n 3 - Return to Main menu\n");
	scanf("%d", &userInput);


	// set looping to = 0 to break out of loop
	while(looping) {
	switch (userInput) {
	case 1:
		printf("Enter a firstname to search for: \n");

		scanf("%s", &searchFor);
		search_by_firstname(searchFor);
		break;
	case 2:
		printf("Enter a lastname to search for: \n");

		scanf("%s", &searchFor);
		search_by_lastname(searchFor);
		break;
	case 3:
		printf("Returning to main menu \n");
		looping = 0;
		break;
	default:
		printf("Invalid input\nReturning to main menu\n");
		looping = 0;
	} looping = 0;
	}

}

// print out person if in list
void search_by_firstname(char *name) {
	FILE *file;
	PERSON *search = malloc(sizeof(PERSON));
	char nameSearch[NAMEMAX + 1];
	strncpy(nameSearch, name, NAMEMAX+1);

	file = fopen(FILENAME, "rb");

	while (fread(search, sizeof(PERSON), 1, file)) {
		if (!strcmp(nameSearch, search->firstname)) {
			//found record
			printf("Firstname: %s\n", search->firstname);
			printf("Familyname: %s\n", search->famnamne);
			printf("Person number: %s\n", search->pers_number);

		}

	}

}

void search_by_lastname(char *name) {
	FILE *file;
	PERSON *search = malloc(sizeof(PERSON));
	char nameSearch[NAMEMAX + 1];
	strncpy(nameSearch, name, NAMEMAX+1);

	file = fopen(FILENAME, "rb");

	while (fread(search, sizeof(PERSON), 1, file)) {
		if (!strcmp(nameSearch, search->famnamne)) {
			//found record
			printf("Firstname: %s\n", search->firstname);
			printf("Familyname: %s\n", search->famnamne);
			printf("Person number: %s\n", search->pers_number);

		}

	}

}

void append_file(PERSON *inrecord) {
	FILE *file;

	if ((file = fopen(FILENAME, "ab")) == NULL) {
		printf("Can not append to file, Error opening file\n");
		exit(1);
	} else {
		fwrite(inrecord, sizeof(PERSON), 1, file);
		fclose(file);

	}
}

void printfile(void) {
	int n = 0;
	FILE *file;
	PERSON *person = malloc(sizeof(PERSON));

	if ((file = fopen(FILENAME, "rb")) == NULL) {
		printf("Error opening file\n");
		exit(1);
	} else {
		while (!feof(file)) {
			if (fread(person, sizeof(PERSON), 1, file)) {
				printf("Firstname: %s\n", person->firstname);
				printf("Lastname: %s\n", person->famnamne);
				printf("Person number: %s\n", person->pers_number);
				n++;
				person++;
			}
		}

		fclose(file);

	}

}

/*
 1 Create a new file and delete the old.
 2 Add a new person to the file.
 3 Search for a person .
 4 Print out all in list.
 5 Exit the program.*/
