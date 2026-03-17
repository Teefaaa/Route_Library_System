# Route Library System

A console-based library management system built in **C++**. This program allows users to manage books in a library, including adding, searching, removing, updating, borrowing, and returning books.

---

## Features

* **Add Books** – Add multiple books at once with unique IDs, titles, and authors.  
* **Search Books** – Search multiple books by ID and see their positions.  
* **Remove Books** – Remove books from the library by ID.  
* **Update Books** – Update the ID, title, or author of any book.  
* **Borrow Books** – Borrow books if available; borrowed books are tracked separately.  
* **Return Books** – Return borrowed books and make them available again.
* **Display Books** – View all available books and borrowed books in a formatted table.  
* **Exit** – Close the program gracefully.

---

## Implementation Details

* **Language:** C++
* **Compiler:** GCC/G++ or any standard C++ compiler
* **Key Concepts Used:**  
  * Dynamic memory allocation (`new` and `delete[]`)
  * Pointer manipulation and array management
  * Functions with pointers and references
  * Input validation for IDs and book availability  
  * Formatted output using `iomanip`

* **Data Structures:**  
  * `int* ids` → Book IDs  
  * `string* titles` → Book titles  
  * `string* authors` → Book authors
* Separate tracking arrays for borrowed books: `ids_b`, `titles_b`, `authors_b`

---

## Project Structure

```
Route_Library_System/
├── main.cpp              # Main program with menu interface
├── AllFunctions.h        # Function prototypes
├── AllFunctions.cpp      # Function implementations
└── README.md             # Project documentation
```

---

## How to Compile and Run

1. **Clone or download** the repository:
   ```bash
   git clone https://github.com/Teefaaa/Route_Library_System.git
   cd Route_Library_System
   ```

2. **Compile the program** using a C++ compiler:
   ```bash
   g++ -o library_system main.cpp AllFunctions.cpp
   ```

3. **Run the executable**:
   ```bash
   ./library_system
   ```

4. **Follow the interactive menu** to perform operations (options 1-8).  
5. **Exit** the program by selecting option `8`.

---

## Usage Example

```
Welcome to Alex Library Management System

List of operations:
 1- Add      New feature: you can add more than a book on one occasion!
 2- Search   New feature: you can search for more than a book on one occasion!
 3- Remove
 4- Update
 5- Borrow
 6- Return
 7- Display
 8- Exit

Select the operation you want: 1
How many books do you want to add? : 2
Enter the id of added book 1: 11
Enter the title of added book 1: New Book Title
Enter the author of added book 1: Author Name
...
```

---

## Key Functions

| Function | Purpose |
|----------|---------|
| `is_avaliable()` | Check if a book ID exists in the library |
| `add_ids()`, `add_titles()`, `add_authors()` | Add new books to the library |
| `search_books()` | Search for books by ID and display their positions |
| `remove_ids()`, `remove_titles()`, `remove_authors()` | Remove books from the library |
| `update_ids()`, `update_titles()`, `update_authors()` | Update book information |
| `display()` | Show all books in a formatted table |

---

## Important Notes

* Book IDs must be **unique** – the system validates this during addition.  
* Borrowed books are tracked separately in `ids_b`, `titles_b`, and `authors_b` arrays and are removed from the available books list.  
* Returning a book moves it back to the available books list.  
* The system supports dynamic addition and removal of books during runtime using pointer-based memory management.
* Pre-loaded library contains 10 classic books at startup.

---

## Author

Individual project by **Teefaaa**

---

## License

This project is open-source and available for educational purposes.
