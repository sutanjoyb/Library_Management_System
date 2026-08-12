# C++ Library Management System (LMS)

A lightweight, console-based **Library Management System** built in C++ using structured data encapsulation with `struct`. This application manages core library operations such as adding, searching, issuing, and returning books, along with custom book categorization and automated discount logic.

---

## Features & Highlights

- **Structured Data Encapsulation**
  - Uses `struct Book` to group related data fields into a single entity.
  - Fields include `id`, `title`, `author`, `price`, and `available`.

- **Core Library Operations**
  - **Add Book**
    - Add books with ID, title, author, price, and availability.
    - Automatically calculates a 10% discount.
    - Automatically categorizes books into:
      - `Budget`
      - `Standard`
      - `Premium`

  - **Display All Books**
    - View complete book information.
    - View real-time availability status.

  - **Search Book**
    - Search for a book using its ID.
    - Uses linear search through the stored books.

  - **Issue Book**
    - Issue an available book.
    - Prevents issuing a book that has already been issued.

  - **Return Book**
    - Return an issued book.
    - Prevents returning a book that is already available.

- **Console UI Navigation**
  - Interactive menu-driven interface.
  - Uses a continuous menu loop.
  - Includes screen pauses between operations for better navigation.

---

## Software Architecture & Flow

### Data Structure Modeling

```cpp
struct Book
{
    int id;
    std::string title;
    std::string author;
    double price;
    bool available;
};
```

### System Architecture Design

```text
+-----------------------------------------------------------------------------------+
|                                  struct Book                                      |
+-----------------------------------------------------------------------------------+
| + id: int | + title: string | + author: string | + price: double | + available: bool |
+-----------------------------------------------------------------------------------+
                                          ^
                                          | Array Allocation
                                          |
+-----------------------------------------------------------------------------------+
|                                     main()                                        |
+-----------------------------------------------------------------------------------+
| - books: Book[100]  (Fixed array storage up to 100 books)                         |
| - bookCount: int    (Tracks current record count)                                 |
+-----------------------------------------------------------------------------------+
                                          |
                        +-----------------+-----------------+
                        |                 |                 |
                        v                 v                 v
                +---------------+ +---------------+ +---------------+
                |   addBook()   | | displayBooks()| | searchBook()  |
                +---------------+ +---------------+ +---------------+
                        |                 |                 |
                        +-----------------+-----------------+
                                          |
                                          v
                                +---------------+ +---------------+
                                |  issueBook()  | | returnBook()  |
                                +---------------+ +---------------+
```

---

## Execution Flowchart

```text
                               +-------------------+
                               |       START       |
                               +---------+---------+
                                         |
                                         v
                     +---------------------------------------+
                     | Instantiate Array of Structs:         |
                     |                                       |
                     |   Book books[100];                    |
                     |   Set bookCount = 0                    |
                     +-------------------+-------------------+
                                         |
                                         v
                     +---------------------------------------+
                     |          Display Main Menu            |
                     |                                       |
                     |   1. Add    2. Display  3. Search     |
                     |   4. Issue  5. Return   6. Exit       |
                     +-------------------+-------------------+
                                         |
                                         v
                               +-------------------+
                               |  Read User Choice |
                               |    from Console   |
                               +---------+---------+
                                         |
        +----------------+---------------+---------------+----------------+
        |                |               |               |                |
        v                v               v               v                v
 [Choice = 1]     [Choice = 2]    [Choice = 3]    [Choice = 4]     [Choice = 5]
        |                |               |               |                |
        v                v               v               v                v
  +-----------+    +-----------+   +-----------+   +-----------+    +-----------+
  |  addBook  |    |  display  |   |  search   |   | issueBook |    |  return   |
  |           |    |   Books   |   |   Book    |   |           |    |   Book    |
  | (books,   |    |  (books)  |   |  (books)  |   | (books,   |    |  (books,  |
  | &count)   |    |           |   |           |   |  count)   |    |   count)  |
  +-----+-----+    +-----+-----+   +-----+-----+   +-----+-----+    +-----+-----+
        |                |               |               |                |
        +----------------+---------------+---------------+----------------+
                                         |
                                         v
                               +-------------------+
                               |    Is Choice = 6? |
                               |   Exit Program?   |
                               +---------+---------+
                                         |
                              +----------+----------+
                              |                     |
                            (No)                   (Yes)
                              |                     |
                              +---------------------+
                                         |
                                         v
                               +-------------------+
                               |        END        |
                               +-------------------+
```

---

## Project Structure

```text
Library_Management_System/
│
├── src/
│   └── main.cpp
│
└── README.md
```

---

## Build & Run

### 1. Clone the Repository

```bash
git clone https://github.com/sutanjoyb/Library_Management_System.git
```

### 2. Navigate to the Project

```bash
cd Library_Management_System
```

### 3. Compile Using g++

Compile the project from the root directory:

```bash
g++ -std=c++17 src/main.cpp -o lms
```

### 4. Execute the Program

On Linux or macOS:

```bash
./lms
```

On Windows:

```bash
lms.exe
```

---

## Technologies Used

- **C++**
- **C++17**
- **Standard Library**
  - `<iostream>`
  - `<string>`

---

## Concepts Practiced

This project currently demonstrates:

- Variables
- Data types
- `if / else if / else`
- Boolean logic
- `for` loops
- `do-while` loops
- `switch` statements
- Functions
- Function parameters
- Return types
- References
- Arrays
- `struct`
- Array of structures
- Linear search
- State management
- Console input/output

---

## Current Limitations

- Data is stored only in memory.
- All books are lost when the program terminates.
- Maximum capacity is currently limited to 100 books.
- Book search currently uses linear search.
- No user authentication system.
- No persistent database or file storage.

These limitations will be addressed as the project is expanded with more advanced C++ concepts.

---

## Author

**Sutanjoy Bhattacharjee**