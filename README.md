# Library Management System in C

This repository contains a simple Library Management System written in C. The program is designed to manage a simple library system using arrays and structures. It allows the user to perform basic operations such as adding a new book, viewing all books, and searching for a book by its title.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Functions](#functions)
- [Code Structure](#code-structure)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Description

The Library Management System is a C program that helps manage a library by allowing users to add new books, view all books, search for books by title, and save the library data to a text file. The program uses arrays and structures to store book information and a menu-based approach for user interaction.

## Features

- Add a new book to the library.
- View all books in the library.
- Search for a book by title.
- Save library data to a text file.
- Menu-based user interface.

## Requirements

1. **Structure Definition:**
    - Define a structure called `Book` with the following attributes:
        - `title` (string)
        - `author` (string)
        - `ISBN` (integer)
        - `year` (integer)
2. **Array of Structures:**
    - Use an array of structures to store information for multiple books. The array size is set to 50 books.
3. **Program Features:**
    - Add a new book to the library.
    - View all books in the library.
    - Search for a book by title and view its details.
4. **File Saving:**
    - Save all data to a text file with each book's data on a new line.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/library-management-system.git
    ```
2. Navigate to the project directory:
    ```bash
    cd library-management-system
    ```
3. Compile the program:
    ```bash
    gcc -o library library.c
    ```

## Usage

1. Run the compiled program:
    ```bash
    ./library
    ```
2. Use the menu to perform various operations:
    - Add a new book
    - View all books
    - Search for a book by title
    - Save library to file
    - Exit the program

## Functions

- **addBook**: Adds a new book to the library.
- **viewAllBooks**: Displays all books in the library.
- **searchBookByTitle**: Searches for a book by its title.
- **saveLibraryToFile**: Saves the library data to a text file.

## Code Structure

```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BOOK 50
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define FILENAME "library.txt"

struct book {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int ISBN;
    int year;
};
struct book library[MAX_BOOK];

void addBook();
void viewAllBooks();
void searchBookByTitle();
void saveLibraryToFile();

int main() {
    int choice;
    int numBooks = 0;
    
    do {
        printf("\n***Library Management System Menu***\n");
        printf(" 1. Add a new book\n");
        printf(" 2. View all books\n");
        printf(" 3. Search for a book by title\n");
        printf(" 4. Save library to file\n");
        printf(" 0. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
        }
        getchar();
    } while(choice != 0);

    return 0;
}

void addBook() {
    int numBooks = 0;

    if (numBooks < MAX_BOOK) {
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

void viewAllBooks() {
    int numBooks = 0;

    if(numBooks == 0) {
        printf("The Library is Empty.\n");
    } else {
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

void searchBookByTitle() {
    int numBooks = 0;
    char searchTitle[MAX_TITLE_LENGTH];

    printf("Enter the title of the book to search: ");
    scanf(" %[^\n]s", searchTitle);

    int found = 0;
    for (int i = 0; i < numBooks; i++) {   
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("%d) Book found:\n", i+1);
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

void saveLibraryToFile() {
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
