#include <iostream>
#include <string>

using namespace std;

enum BookStatus
{
    AVAILABLE,
    ISSUED,
    RESERVED
};

struct Book
{
    int id;
    string title;
    string author;
    double price;
    BookStatus status;
};

void clearInput()
{
    if (cin.fail())
    {
        cin.clear();
    }

    cin.ignore(10000, '\n');
}

void pauseProgram()
{
    cout << "\nPress Enter to return to the main menu...";
    clearInput();
    cout << "\n";
}

void addBook(Book books[], int &bookCount)
{
    if (bookCount >= 100)
    {
        cout << "\nLibrary is full. Cannot add more books. :(\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "               ADD BOOK                 \n";
    cout << "========================================\n\n";

    int newBookId;

    cout << "Enter the Book's ID: ";

    if (!(cin >> newBookId))
    {
        cout << "\nInvalid ID entered. Returning to menu. :(\n";
        clearInput();
        return;
    }

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == newBookId)
        {
            cout << "\nBook ID already exists. Please use a different ID. :(\n";
            return;
        }
    }

    int position = bookCount;

    for (int i = 0; i < bookCount; i++)
    {
        if (newBookId < books[i].id)
        {
            position = i;
            break;
        }
    }

    for (int i = bookCount; i > position; i--)
    {
        books[i] = books[i - 1];
    }

    books[position].id = newBookId;

    clearInput();

    cout << "Enter the Book's Title: ";
    getline(cin, books[position].title);

    cout << "Enter the Book's Author: ";
    getline(cin, books[position].author);

    cout << "Enter the Book's Price: ";

    while (!(cin >> books[position].price) || books[position].price < 0)
    {
        cout << "Invalid price. Please enter a valid non-negative number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    books[position].status = AVAILABLE;

    double discount = books[position].price * 0.10;
    double finalPrice = books[position].price - discount;

    cout << "\n========================================\n";
    cout << "          BOOK INFORMATION              \n";
    cout << "========================================\n\n";

    cout << "Book ID: " << books[position].id << '\n';
    cout << "Title: " << books[position].title << '\n';
    cout << "Author: " << books[position].author << '\n';
    cout << "Price: " << books[position].price << '\n';

    if (books[position].status == AVAILABLE)
    {
        cout << "Status: Available :)\n";
    }
    else if (books[position].status == ISSUED)
    {
        cout << "Status: Issued :(\n";
    }
    else
    {
        cout << "Status: Reserved\n";
    }

    cout << "\n========================================\n";
    cout << "             PRICE DETAILS              \n";
    cout << "========================================\n\n";

    cout << "Original Price: " << books[position].price << '\n';
    cout << "Discount: " << discount << '\n';
    cout << "Final Price: " << finalPrice << '\n';

    cout << "\n========================================\n";
    cout << "             BOOK CATEGORY              \n";
    cout << "========================================\n\n";

    if (books[position].price < 300)
    {
        cout << "Category: Budget :)\n";
    }
    else if (books[position].price <= 700)
    {
        cout << "Category: Standard :)\n";
    }
    else
    {
        cout << "Category: Premium :)\n";
    }

    bookCount++;

    cout << "\n========================================\n";
    cout << "            BOOK ADDED :)               \n";
    cout << "========================================\n";

    cout << "Book \"" << books[position].title
         << "\" has been added successfully!\n";
}

void displayBooks(Book books[], int bookCount)
{
    cout << "\n========================================\n";
    cout << "             ALL BOOKS                  \n";
    cout << "========================================\n";

    if (bookCount == 0)
    {
        cout << "\nNo books have been added yet. :(\n";
        return;
    }

    cout << "\nBooks found successfully! :)\n";

    for (int i = 0; i < bookCount; i++)
    {
        cout << "\n----------------------------------------\n";
        cout << "Book " << i + 1 << '\n';
        cout << "----------------------------------------\n";

        cout << "Book ID: " << books[i].id << '\n';
        cout << "Title: " << books[i].title << '\n';
        cout << "Author: " << books[i].author << '\n';
        cout << "Price: " << books[i].price << '\n';

        if (books[i].status == AVAILABLE)
        {
            cout << "Status: Available :)\n";
        }
        else if (books[i].status == ISSUED)
        {
            cout << "Status: Issued :(\n";
        }
        else
        {
            cout << "Status: Reserved\n";
        }
    }
}

void searchBook(Book books[], int bookCount)
{
    cout << "\n========================================\n";
    cout << "              SEARCH BOOK               \n";
    cout << "========================================\n\n";

    if (bookCount == 0)
    {
        cout << "No books have been added yet. :(\n";
        return;
    }

    int searchId;

    cout << "Enter the Book ID to search: ";

    if (!(cin >> searchId))
    {
        cout << "\nInvalid input. :(\n";
        clearInput();
        return;
    }

    int left = 0;
    int right = bookCount - 1;
    int foundIndex = -1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (books[middle].id == searchId)
        {
            foundIndex = middle;
            break;
        }
        else if (searchId < books[middle].id)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    if (foundIndex != -1)
    {
        cout << "\nBook found! :)\n\n";

        cout << "Book ID: " << books[foundIndex].id << '\n';
        cout << "Title: " << books[foundIndex].title << '\n';
        cout << "Author: " << books[foundIndex].author << '\n';
        cout << "Price: " << books[foundIndex].price << '\n';

        if (books[foundIndex].status == AVAILABLE)
        {
            cout << "Status: Available :)\n";
        }
        else if (books[foundIndex].status == ISSUED)
        {
            cout << "Status: Issued :(\n";
        }
        else
        {
            cout << "Status: Reserved\n";
        }
    }
    else
    {
        cout << "\nBook not found. :(\n";
    }
}

void issueBook(Book books[], int bookCount)
{
    cout << "\n========================================\n";
    cout << "               ISSUE BOOK               \n";
    cout << "========================================\n\n";

    if (bookCount == 0)
    {
        cout << "No books have been added yet. :(\n";
        return;
    }

    int issueId;

    cout << "Enter the Book ID to issue: ";

    if (!(cin >> issueId))
    {
        cout << "\nInvalid input. :(\n";
        clearInput();
        return;
    }

    int left = 0;
    int right = bookCount - 1;
    int foundIndex = -1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (books[middle].id == issueId)
        {
            foundIndex = middle;
            break;
        }
        else if (issueId < books[middle].id)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    if (foundIndex == -1)
    {
        cout << "\nBook not found. :(\n";
        return;
    }

    if (books[foundIndex].status == AVAILABLE)
    {
        books[foundIndex].status = ISSUED;

        cout << "\nBook issued successfully! :)\n";
        cout << "Book: " << books[foundIndex].title << '\n';
    }
    else if (books[foundIndex].status == ISSUED)
    {
        cout << "\nThis book is already issued. :(\n";
    }
    else
    {
        cout << "\nThis book is reserved and cannot be issued. :(\n";
    }
}

void returnBook(Book books[], int bookCount)
{
    cout << "\n========================================\n";
    cout << "              RETURN BOOK               \n";
    cout << "========================================\n\n";

    if (bookCount == 0)
    {
        cout << "No books have been added yet. :(\n";
        return;
    }

    int returnId;

    cout << "Enter the Book ID to return: ";

    if (!(cin >> returnId))
    {
        cout << "\nInvalid input. :(\n";
        clearInput();
        return;
    }

    int left = 0;
    int right = bookCount - 1;
    int foundIndex = -1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (books[middle].id == returnId)
        {
            foundIndex = middle;
            break;
        }
        else if (returnId < books[middle].id)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    if (foundIndex == -1)
    {
        cout << "\nBook not found. :(\n";
        return;
    }

    if (books[foundIndex].status == ISSUED)
    {
        books[foundIndex].status = AVAILABLE;

        cout << "\nBook returned successfully! :)\n";
        cout << "Book: " << books[foundIndex].title << '\n';
    }
    else if (books[foundIndex].status == AVAILABLE)
    {
        cout << "\nThis book has not been issued. :(\n";
    }
    else
    {
        cout << "\nThis book is reserved. :(\n";
    }
}

void deleteBook(Book books[], int &bookCount)
{
    cout << "\n========================================\n";
    cout << "              DELETE BOOK               \n";
    cout << "========================================\n\n";

    if (bookCount == 0)
    {
        cout << "No books have been added yet. :(\n";
        return;
    }

    int deleteId;

    cout << "Enter the Book ID to delete: ";

    if (!(cin >> deleteId))
    {
        cout << "\nInvalid input. :(\n";
        clearInput();
        return;
    }

    int left = 0;
    int right = bookCount - 1;
    int foundIndex = -1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (books[middle].id == deleteId)
        {
            foundIndex = middle;
            break;
        }
        else if (deleteId < books[middle].id)
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    if (foundIndex == -1)
    {
        cout << "\nBook not found. :(\n";
        return;
    }

    cout << "\nBook found! :)\n";
    cout << "Book: " << books[foundIndex].title << '\n';

    for (int i = foundIndex; i < bookCount - 1; i++)
    {
        books[i] = books[i + 1];
    }

    bookCount--;

    cout << "\nBook deleted successfully! :)\n";
}

int main()
{
    cout << "========================================\n";
    cout << "        LIBRARY MANAGEMENT SYSTEM       \n";
    cout << "========================================\n\n";

    const int MAX_BOOKS = 100;

    Book books[MAX_BOOKS];

    int bookCount = 0;
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "               MAIN MENU                \n";
        cout << "========================================\n\n";

        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Exit\n";

        cout << "\nEnter your choice: ";

        if (!(cin >> choice))
        {
            cout << "\nInvalid choice. Please enter a number between 1 and 7. :(\n";
            clearInput();
            continue;
        }

        switch (choice)
        {
        case 1:
            addBook(books, bookCount);
            pauseProgram();
            break;

        case 2:
            displayBooks(books, bookCount);
            pauseProgram();
            break;

        case 3:
            searchBook(books, bookCount);
            pauseProgram();
            break;

        case 4:
            issueBook(books, bookCount);
            pauseProgram();
            break;

        case 5:
            returnBook(books, bookCount);
            pauseProgram();
            break;

        case 6:
            deleteBook(books, bookCount);
            pauseProgram();
            break;

        case 7:
            cout << "\n========================================\n";
            cout << "                 EXIT                   \n";
            cout << "========================================\n\n";

            cout << "Exiting Library Management System... :)\n";
            break;

        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 7. :(\n";
            pauseProgram();
        }

    } while (choice != 7);

    cout << "\n========================================\n";
    cout << "  Thank you for using the Library LMS! \n";
    cout << "========================================\n";

    return 0;
}