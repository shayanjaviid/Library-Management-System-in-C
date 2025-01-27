/*Description:
Create a C language program to manage a simple library system using arrays and
structures. The program should allow the user to perform basic operations such as adding a
whistle that displays all books and searches for a book by title.
Requirements:
1. Define a structure called Book with the following attributes:
- Title (string)
Author (string)
- ISBN (integer)
- Year of publication (full)
THE
2. Use an array of structures to store information across multiple books. Choose a size
reasonable for the array, such as 50 books.
3. Implement the following features in your program:
Add a new book to your library.
View all books in the library.
- Search for a book by title and view its details.
4. Save to a text file:
- save all data in a text file;
- save book data in different rows.
5. The program should use a menu-based approach, allowing the user to make several choices
options such as adding a book, viewing all books, searching for a book, and exiting
plan.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOK 50
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define FILENAME "library.txt"

struct book{
    char title[100];
    char author[100];
    int ISBN;
    int year;
};
struct book library[50];


void addBook();
void viewAllBooks();
void searchBookByTitle();
void saveLibraryToFile();

int main(){
    int choice;
    int numBooks = 0;
    
    do{
        printf("\n***Library Management System Menu***\n");
        printf(" 1.Add a new book\n");
        printf(" 2.View all books\n");
        printf(" 3.Search for a book by title\n");
        printf(" 4.Save library to file\n");
        printf(" 0.Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            addBook();
            break;
        case 2:
            viewAllBooks();
            break;
        case 3:
            searchBookByTitle();
            break;
        case 4:
            saveLibraryToFile();
            break;
        case 0:
            printf("Exiting...");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Invalid entry!");
        }getchar();
    }while(choice != 0);

    return 0;
}

void addBook(){
    int numBooks = 0;

    if (numBooks < 50) {
        printf("Enter the title of the book: ");
        scanf(" %[^\n]s", library[numBooks].title);

        printf("Enter the author of the book: ");
        scanf(" %[^\n]s", library[numBooks].author);

        printf("Enter the ISBN of the book: ");
        scanf("%d", &library[numBooks].ISBN);

        printf("Enter the year of publication of the book: ");
        scanf("%d", &library[numBooks].year);

        printf("Book added successfully.\n");
        numBooks++;

    } else {
        printf("The library is full!\n");
    }
}

void viewAllBooks(){
    int numBooks = 0;

    if(numBooks == 0){
        printf("The Library is Empty.\n");
    }else {
        printf("List of all books in the library:\n");
        for (int i = 0; i < numBooks; i++) {
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("ISBN: %d\n", library[i].ISBN);
            printf("Year of publication: %d\n", library[i].year);
            printf("\n");
        }
    }
}

void searchBookByTitle(){
    int numBooks = 0;
    char searchTitle[100];

    printf("Enter the title of the book to search: ");
    scanf(" %[^\n]s", searchTitle);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {   
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("%d)", i+1);
            printf("Book found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("ISBN: %d\n", library[i].ISBN);
            printf("Year of publication: %d\n", library[i].year);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Book '%s' not found in the library.\n", searchTitle);
    }
}
void saveLibraryToFile(){
    int numBooks = 0;

    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < numBooks; i++) {
        fprintf(file, "%s|%s|%d|%d\n", library[i].title, library[i].author, library[i].ISBN, library[i].year);
    }

    fclose(file);
    printf("Library data saved to 'library.txt' successfully.\n");
}