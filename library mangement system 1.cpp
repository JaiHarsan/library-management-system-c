#include <stdio.h>
#include <string.h>



struct Book {
    int id;
    char title[50];
    char author[50];
};

struct Book library[100];
int count = 0;



void printLine() { printf("-------------------------------------------------\n"); }

void printHeader() {
    printLine();
    printf(" ID\t\tTitle\t\tAuthor\n");
    printLine();
}

void printBook(struct Book b) {
    printf(" %d\t\t%s\t\t%s\n", b.id, b.title, b.author);
}



int isLibraryEmpty() { return (count == 0); }

void displayAllBooks() {
    for (int i = 0; i < count; i++)
        printBook(library[i]);
}

void viewBooksModule() {
    if (isLibraryEmpty()) {
        printf("\nNo books available.\n");
        return;
    }
    printHeader();
    displayAllBooks();
}



int searchBookById(int id) {
    for (int i = 0; i < count; i++)
        if (library[i].id == id)
            return i;
    return -1;
}

int searchBookByTitle(char title[]) {
    for (int i = 0; i < count; i++)
        if (strcmp(library[i].title, title) == 0)
            return i;
    return -1;
}

void searchBookModule() {
    int choice, id, index;
    char title[50];

    printf("\nSearch by:\n1. ID\n2. Title\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter Book ID: ");
        scanf("%d", &id);
        index = searchBookById(id);
    } else {
        printf("\nEnter Book Title: ");
        scanf(" %[^\n]", title);
        index = searchBookByTitle(title);
    }

    if (index == -1) printf("\nBook not found!\n");
    else { printHeader(); printBook(library[index]); }
}

 

void getUsername(char user[]) {
    printf("Username: ");
    scanf("%s", user);
}

void getPassword(char pass[]) {
    printf("Password: ");
    scanf("%s", pass);
}

int studentLogin() {
    char user[20], pass[20];

    printf("\n--- Student Login ---\n");
    getUsername(user);
    getPassword(pass);

    return (strcmp(user, "student") == 0 && strcmp(pass, "111") == 0);
}


 

void showStudentMenuOptions() {
    printf("\n===== STUDENT MENU =====\n");
    printf("1. View Books\n");
    printf("2. Search Book\n");
    printf("3. Logout\n");
}

void processStudentChoice(int choice) {
    switch(choice) {
        case 1: viewBooksModule(); break;
        case 2: searchBookModule(); break;
        case 3: return;
        default: printf("Invalid choice!\n");
    }
}

void studentMenu() {
    int choice;

    while (1) {
        showStudentMenuOptions();
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 3) return;
        processStudentChoice(choice);
    }
}


void libPrintLine() { 
    printf("-------------------------------------------------\n");
 }

void libPrintHeader() {
    libPrintLine();
    printf(" ID\t\tTitle\t\tAuthor\n");
    libPrintLine();
}

void libPrintBook(struct Book b) {
    printf(" %d\t\t%s\t\t%s\n", b.id, b.title, b.author);
}


   
void getBookDetails(struct Book *b) {
    printf("\nEnter Book ID: ");
    scanf("%d", &b->id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", b->title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b->author);
}

int isUniqueId(int id) {
    for (int i = 0; i < count; i++)
        if (library[i].id == id) return 0;
    return 1;
}

void addBookModule() {
    struct Book b;
    getBookDetails(&b);

    if (!isUniqueId(b.id)) {
        printf("\nBook ID already exists!\n");
        return;
    }

    library[count++] = b;
    printf("\nBook added successfully!\n");
}




int libSearchById(int id) { return searchBookById(id); }
int libSearchByTitle(char t[]) { return searchBookByTitle(t); }

void searchBookModuleAdmin() {
    int choice, id, index;
    char title[50];

    printf("\nSearch by:\n1. ID\n2. Title\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nEnter Book ID: ");
        scanf("%d", &id);
        index = libSearchById(id);
    } else {
        printf("\nEnter Book Title: ");
        scanf(" %[^\n]", title);
        index = libSearchByTitle(title);
    }

    if (index == -1) printf("\nBook not found!\n");
    else { libPrintHeader(); libPrintBook(library[index]); }
}

   

int getBookIndex(int id) {
    for (int i = 0; i < count; i++)
        if (library[i].id == id) return i;
    return -1;
}

void shiftLeft(int index) {
    for (int i = index; i < count - 1; i++)
        library[i] = library[i + 1];
}

void deleteBookModule() {
    int id;
    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    int index = getBookIndex(id);
    if (index == -1) { printf("\nBook not found!\n"); return; }

    shiftLeft(index);
    count--;
    printf("\nBook deleted successfully!\n");
}

/* ============================================================
   MODULE 10 : LIBRARIAN UPDATE MODULE (3 Functions)
============================================================ */

void updateBookTitle(int i) { printf("New Title: "); scanf(" %[^\n]", library[i].title); }
void updateBookAuthor(int i) { printf("New Author: "); scanf(" %[^\n]", library[i].author); }

void updateBookModule() {
    int id, index, choice;

    printf("\nEnter Book ID to update: ");
    scanf("%d", &id);

    index = getBookIndex(id);
    if (index == -1) { printf("\nBook not found!\n"); return; }

    printf("\n1. Update Title\n2. Update Author\nEnter choice: ");
    scanf("%d", &choice);

    (choice == 1) ? updateBookTitle(index) : updateBookAuthor(index);

    printf("\nBook updated successfully!\n");
}

/* ============================================================
   MODULE 11 : LIBRARIAN LOGIN + MENU MODULE (3 Functions)
============================================================ */

int librarianLogin() {
    char user[20], pass[20];
    printf("\n--- Librarian Login ---\n");
    printf("Username: "); scanf("%s", user);
    printf("Password: "); scanf("%s", pass);
    return (strcmp(user, "admin") == 0 && strcmp(pass, "123") == 0);
}

void showLibrarianMenu() {
    printf("\n===== LIBRARIAN MENU =====\n");
    printf("1. Add Book\n");
    printf("2. View Books\n");
    printf("3. Search Book\n");
    printf("4. Delete Book\n");
    printf("5. Update Book\n");
    printf("6. Logout\n");
}

void librarianMenu() {
    int choice;
    while (1) {
        showLibrarianMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addBookModule(); break;
            case 2: viewBooksModule(); break;
            case 3: searchBookModuleAdmin(); break;
            case 4: deleteBookModule(); break;
            case 5: updateBookModule(); break;
            case 6: return;
            default: printf("Invalid choice!\n");
        }
    }
}

/* ======================= MAIN PROGRAM ======================= */

int main() {
    int ch;

    while (1) {
        printf("\n====== MAIN MENU ======\n");
        printf("1. Librarian Login\n");
        printf("2. Student Login\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                if (librarianLogin()) librarianMenu();
                else printf("\nInvalid Librarian Login!\n");
                break;

            case 2:
                if (studentLogin()) studentMenu();
                else printf("\nInvalid Student Login!\n");
                break;

            case 3:
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }
}
