#include <iostream>
#include <string>

using namespace std;

void addBook(
    int bookIds[],
    string bookTitles[],
    string authors[],
    double prices[],
    bool availabilities[],
    int &bookCount)
{
    if (bookCount >= 100)
    {
        cout << "\nLibrary is full. Cannot add more books. :(\n";
        return;
    }

    cout << "\n========================================\n";
    cout << "               ADD BOOK                 \n";
    cout << "========================================\n\n";

    cout << "Enter the Book's ID: ";
    cin >> bookIds[bookCount];

    cin.ignore();

    cout << "Enter the Book's Title: ";
    getline(cin, bookTitles[bookCount]);

    cout << "Enter the Book's Author: ";
    getline(cin, authors[bookCount]);

    cout << "Enter the Book's Price: ";
    cin >> prices[bookCount];

    cout << "Is the book available? (1 = Yes, 0 = No): ";
    cin >> availabilities[bookCount];

    cout << "\nBook added successfully! :)\n";

    double discount = prices[bookCount] * 0.10;
    double finalPrice = prices[bookCount] - discount;

    cout << "\n========================================\n";
    cout << "          BOOK INFORMATION              \n";
    cout << "========================================\n\n";

    cout << "Book ID: " << bookIds[bookCount] << '\n';
    cout << "Title: " << bookTitles[bookCount] << '\n';
    cout << "Author: " << authors[bookCount] << '\n';
    cout << "Price: " << prices[bookCount] << '\n';

    if (availabilities[bookCount])
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

    cout << "Original Price: " << prices[bookCount] << '\n';
    cout << "Discount: " << discount << '\n';
    cout << "Final Price: " << finalPrice << '\n';

    cout << "\n========================================\n";
    cout << "             BOOK CATEGORY              \n";
    cout << "========================================\n\n";

    if (prices[bookCount] < 300)
    {
        cout << "Category: Budget :)\n";
    }
    else if (prices[bookCount] <= 700)
    {
        cout << "Category: Standard :)\n";
    }
    else
    {
        cout << "Category: Premium :)\n";
    }

    bookCount++;
}

void displayBooks(
    int bookIds[],
    string bookTitles[],
    string authors[],
    double prices[],
    bool availabilities[],
    int bookCount)
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

        cout << "Book ID: " << bookIds[i] << '\n';
        cout << "Title: " << bookTitles[i] << '\n';
        cout << "Author: " << authors[i] << '\n';
        cout << "Price: " << prices[i] << '\n';

        if (availabilities[i])
        {
            cout << "Availability: Available :)\n";
        }
        else
        {
            cout << "Availability: Issued :(\n";
        }
    }
}

void searchBook(
    int bookIds[],
    string bookTitles[],
    string authors[],
    double prices[],
    bool availabilities[],
    int bookCount)
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

    bool found = false;

    for (int i = 0; i < bookCount; i++)
    {
        if (bookIds[i] == searchId)
        {
            cout << "\nBook found! :)\n\n";

            cout << "Book ID: " << bookIds[i] << '\n';
            cout << "Title: " << bookTitles[i] << '\n';
            cout << "Author: " << authors[i] << '\n';
            cout << "Price: " << prices[i] << '\n';

            if (availabilities[i])
            {
                cout << "Availability: Available :)\n";
            }
            else
            {
                cout << "Availability: Issued :(\n";
            }

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nBook not found. :(\n";
    }
}

void issueBook(
    int bookIds[],
    string bookTitles[],
    bool availabilities[],
    int bookCount)
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
        if (bookIds[i] == issueId)
        {
            found = true;

            if (availabilities[i])
            {
                availabilities[i] = false;

                cout << "\nBook issued successfully! :)\n";
                cout << "Book: " << bookTitles[i] << '\n';
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

void returnBook(
    int bookIds[],
    string bookTitles[],
    bool availabilities[],
    int bookCount)
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
        if (bookIds[i] == returnId)
        {
            found = true;

            if (!availabilities[i])
            {
                availabilities[i] = true;

                cout << "\nBook returned successfully! :)\n";
                cout << "Book: " << bookTitles[i] << '\n';
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

    int bookIds[MAX_BOOKS];
    string bookTitles[MAX_BOOKS];
    string authors[MAX_BOOKS];
    double prices[MAX_BOOKS];
    bool availabilities[MAX_BOOKS];

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
            addBook(
                bookIds,
                bookTitles,
                authors,
                prices,
                availabilities,
                bookCount);
            break;

        case 2:
            displayBooks(
                bookIds,
                bookTitles,
                authors,
                prices,
                availabilities,
                bookCount);
            break;

        case 3:
            searchBook(
                bookIds,
                bookTitles,
                authors,
                prices,
                availabilities,
                bookCount);
            break;

        case 4:
            issueBook(
                bookIds,
                bookTitles,
                availabilities,
                bookCount);
            break;

        case 5:
            returnBook(
                bookIds,
                bookTitles,
                availabilities,
                bookCount);
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