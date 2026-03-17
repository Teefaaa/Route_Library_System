#include"AllFunctions.h"
using namespace std;




int main()
{
	cout << " \t\t  */		Welcome to Alex Library Management System		\\* " << endl << endl;
	cout << "List of operations: " << endl << endl;
	cout << " 1- Add " << "\t New feature: you can add more than a book on one occasion!" << endl;
	cout << " 2- Search " << "\t New feature: you can search for more than a book on one occasion!" << endl;
	cout << " 3- Remove " << endl;
	cout << " 4- Update " << endl;
	cout << " 5- Borrow " << endl;
	cout << " 6- Return " << endl;
	cout << " 7- Display " << endl;
	cout << " 8- Exit " << endl << endl;
	int operation;
	int size = 10;
	int no_ofBooks;                               // no.of books you wanna add or search
	int* ids = new int[size] {1,2,3,4,5,6,7,8,9,10};
	string* titles = new string[size] {"To Kill a Mockingbird " , "1984" , "Sapiens: A Brief History of Humankind" , "Pride and Prejudice" , "One Hundred Years of Solitude" , "Crime and Punishment " , "The Great Gatsby" ,  "Frankenstein" , "Man's Search for Meaning" , "Beloved"};
	string* authors = new string[size]{ "Harper Lee" , "George Orwell" , "Yuval Noah Harari" , "Jane Austen" , "Gabriel García Márquez " , "Fyodor Dostoevsky" , "F. Scott Fitzgerald" , "Mary Shelley " , "Viktor Frankl" , "Toni Morrison" };
	int exist = 0;                             // to check th number of borrowed books
	int* ids_b = new int[size] {};            // ids of borrowed books
	string* titles_b = new string[size];     // titles of borrowed books
	string* authors_b = new string[size];   // authors of borrowed books
	do
	{
		cout << " Select the operation you want: ";
		cin >> operation;
		switch (operation)
		{
		case 1:
		{
			cout << "How many books do you want to add? : ";
			cin >> no_ofBooks;
			cout << endl;
			size += no_ofBooks;
			int* ids_a = add_ids(ids, size, no_ofBooks);
			delete[] ids;
			ids = ids_a;
			string* titles_a = add_titles(titles, size, no_ofBooks);
			delete[] titles;
			titles = titles_a;
			string* authors_a = add_authors(authors, size, no_ofBooks);
			delete[] authors;
			authors = authors_a;
			break;
		}
		case 2:
		{
			cout << "How many books do you want to search? : ";
			cin >> no_ofBooks;
			cout << endl;
			search_books(ids, size, no_ofBooks);
			break;
		}
		case 3:
		{
			int remove;               
			cout << "Enter the ID of the book that you need to remove : ";
			cin >> remove;
			if (!is_avaliable(ids, size, remove))
				cout << "This book is already unavailable!!! " << endl;
			else
			{
				int pos = position(ids, size, remove);
				size--;
				cout << endl;
				int* ids_r = remove_ids(ids, size, remove);
				delete[] ids;
				ids = ids_r;
				string* titles_r = remove_titles(titles, size, pos);
				delete[] titles;
				titles = titles_r;
				string* authors_r = remove_authors(authors, size, pos);
				delete[] authors;
				authors = authors_r;
			}
			break;

		}
		case 4:
		{
			int update;
			cout << "Enter the ID of the book that you need to update : ";
			cin >> update;
			if (!is_avaliable(ids, size, update))
				cout << "This book is already unavailable!!! " << endl;
			else
			{
				int choice;
				cout << "What do you need to update? " << endl;
				cout << "1- ID" << endl << "2- Title" << endl << "3- Author" << endl << "Enter your operation : ";
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					int new_id;
					cout << "Enter the new ID to update: ";
					cin >> new_id;
					cout << endl;
					update_ids(ids, size, update, new_id);
					break;
				}
				case 2:
				{
					string new_title;
					cout << "Enter the new title to update: ";
					cin.ignore();
					getline(cin, new_title);
					cout << endl;
					update_titles(ids, titles, size, update, new_title);
					break;
				}
				case 3:
				{
					string new_author;
					cout << "Enter the new author to update: ";
					cin.ignore();
					getline(cin, new_author);
					cout << endl;
					update_authors(ids, authors, size, update, new_author);
					break;
				}
				}
			}
			break;
		}
		case 5:
		{
			int borrow;
			cout << "Enter the ID of book you need to borrow : ";
			cin >> borrow;
			cout << endl;
			if (is_avaliable(ids, size, borrow))
			{
				cout << "Fortunately, this Book is available, so you can borrow it" << endl;
				int pos = position(ids, size, borrow);
				size--;
				ids_b[exist] = ids[pos];
				titles_b[exist] = titles[pos];
				authors_b[exist] = authors[pos];
				int* ids_temp = remove_ids(ids, size, borrow);
				delete[] ids;
				ids = ids_temp;
				string* titles_temp = remove_titles(titles, size, pos);
				delete[] titles;
				titles = titles_temp;
				string* authors_temp = remove_authors(authors, size, pos);
				delete[] authors;
				authors = authors_temp;
				exist++;
			}
			else
			{
				cout << "Unfortunately, this Book is not available" << endl;
			}
			break;
		}	
		case 6:
		{
			int retrn;
			cout << "Enter the ID of book you need to return : ";
			cin >> retrn;
			cout << endl;
			if (is_avaliable(ids_b, exist, retrn))
			{
				cout << "Thanks, and we hope you enjoyed the book " << endl;
				int posi = position(ids_b, exist, retrn);
				size++;
				int* ids_r = return_ids(ids, ids_b, size, posi);
				delete[]ids;
				ids = ids_r;
				string* titles_r = return_titles(titles, titles_b, size, posi);
				delete []titles;
				titles = titles_r;
				string* authors_r = return_authors(authors, authors_b, size, posi);
				delete[]authors;
				authors = authors_r;
				int* ids_tem = remove_ids(ids_b, exist, retrn);
				delete[] ids_b;
				ids_b = ids_tem;
				string* titles_tem = remove_titles(titles_b, exist, posi);
				delete[] titles_b;
				titles_b = titles_tem;
				string* authors_tem = remove_authors(authors_b, exist, posi);
				delete[] authors_b;
				authors_b = authors_tem;
				exist--;
			}
			else
			{
				cout << "This book was not borrowed!!! " << endl;
			}
			break;
		}
		case 7:
		{
			cout << "Available Books: " << endl << "-----------------" << endl;
			display(ids, titles, authors, size);
			cout << endl << "---------------------------------------------" << endl;
			cout << "Borrowed Books: " << endl << "------------------" << endl;
			display(ids_b, titles_b, authors_b, exist);
			cout << endl;
			break;
		}
		}
	}
	while (operation < 8 && operation > 0);
	cout << endl <<  " Have a Good Time! " << endl;
	return 0;
}

