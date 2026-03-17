# Route_Library_System

A console-based library management system built in **C++**. This program allows users to manage books in a library, including adding, searching, removing, updating, borrowing, and returning books.

---

## Features

* **Add Books** – Add multiple books at once with unique IDs, titles, and authors.  
* **Search Books** – Search multiple books by ID and see their positions.  
* **Remove Books** – Remove books from the library by ID.  
* **Update Books** – Update the ID, title, or author of any book.  
* **Borrow Books** – Borrow books if available; borrowed books are tracked separately.  
* **Return Books** – Return borrowed books and make them available again.  
* **Display Books** – View all available books and borrowed books.  
* **Exit** – Close the program gracefully.

---

## Implementation Details

* **Language:** C++  
* **Concepts Used:**  
  * Dynamic memory allocation (`new` and `delete[]`)  
  * Arrays and strings  
  * Functions with pointers  
  * Input validation for IDs and availability  

* **Data Structures:**  
  * `int* ids` → Book IDs  
  * `string* titles` → Book titles  
  * `string* authors` → Book authors  
  * Separate arrays for borrowed books: `ids_b`, `titles_b`, `authors_b`

---
## How to Run

1. **Clone or download** the repository.  
2. **Compile the program** using a C++ compiler:
   g++ -o library_system library_system.cpp
3. **Run the executable**:
   ./library_system
4. **Follow the interactive menu** to perform operations.  
5. **Exit** the program by choosing option `8`.

---

## Notes

* Book IDs must be **unique**.  
* Borrowed books are tracked separately and removed from available books.  
* Returning a book moves it back to the available books list.  
* Supports adding, removing, and updating multiple books dynamically.
