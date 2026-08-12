#include <iostream>
#include <string>

using namespace std;

struct Book
{
    int id;
    string title;
    string author;
    double price;
    bool available;
};

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
    cin >> newBookId;

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

    cin.ignore();

    cout << "Enter the Book's Title: ";
    getline(cin, books[position].title);

    cout << "Enter the Book's Author: ";
    getline(cin, books[position].author);

    cout << "Enter the Book's Price: ";
    cin >> books[position].price;

    cout << "Is the book available? (1 = Yes, 0 = No): ";
    cin >> books[position].available;

    cout << "\nBook added successfully! :)\n";

    double discount = books[position].price * 0.10;
    double finalPrice = books[position].price - discount;

    cout << "\n========================================\n";
    cout << "          BOOK INFORMATION              \n";
    cout << "========================================\n\n";

    cout << "Book ID: " << books[position].id << '\n';
    cout << "Title: " << books[position].title << '\n';
    cout << "Author: " << books[position].author << '\n';
    cout << "Price: " << books[position].price << '\n';

    if (books[position].available)
    {
        cout << "Available: Yes :)\n";
    }
    else
    {
        cout << "Available: No :(\n";
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

        if (books[i].available)
        {
            cout << "Availability: Available :)\n";
        }
        else
        {
            cout << "Availability: Issued :(\n";
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
    cin >> searchId;

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

        if (books[foundIndex].available)
        {
            cout << "Availability: Available :)\n";
        }
        else
        {
            cout << "Availability: Issued :(\n";
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
    cin >> issueId;

    bool found = false;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == issueId)
        {
            found = true;

            if (books[i].available)
            {
                books[i].available = false;

                cout << "\nBook issued successfully! :)\n";
                cout << "Book: " << books[i].title << '\n';
            }
            else
            {
                cout << "\nThis book is already issued. :(\n";
            }

            break;
        }
    }

    if (!found)
    {
        cout << "\nBook not found. :(\n";
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
    cin >> returnId;

    bool found = false;

    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].id == returnId)
        {
            found = true;

            if (!books[i].available)
            {
                books[i].available = true;

                cout << "\nBook returned successfully! :)\n";
                cout << "Book: " << books[i].title << '\n';
            }
            else
            {
                cout << "\nThis book has not been issued. :(\n";
            }

            break;
        }
    }

    if (!found)
    {
        cout << "\nBook not found. :(\n";
    }
}

int main()
{
    cout << "========================================\n";
    cout << "       LIBRARY MANAGEMENT SYSTEM        \n";
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
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook(books, bookCount);
            break;

        case 2:
            displayBooks(books, bookCount);
            break;

        case 3:
            searchBook(books, bookCount);
            break;

        case 4:
            issueBook(books, bookCount);
            break;

        case 5:
            returnBook(books, bookCount);
            break;

        case 6:
            cout << "\n========================================\n";
            cout << "                 EXIT                   \n";
            cout << "========================================\n\n";

            cout << "Exiting Library Management System... :)\n";
            break;

        default:
            cout << "\nInvalid choice. Please enter a number between 1 and 6. :(\n";
        }

        if (choice != 6)
        {
            cout << "\nPress Enter to return to the main menu...";

            cin.ignore();
            cin.get();

            cout << "\n";
        }

    } while (choice != 6);

    cout << "\n========================================\n";
    cout << "  Thank you for using the Library LMS! \n";
    cout << "========================================\n";

    return 0;
}