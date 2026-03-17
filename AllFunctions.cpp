#include "AllFunctions.h"


using namespace std;

// Functions Code:


bool is_avaliable(int* ids, int size, int id)
{
	for (int i = 0; i < size; i++)
	{
		if (ids[i] == id)
			return true;
	}
	return false;
}

int* add_ids(int* ids, int size, int no_ofBooks)
{
	int* ids_a = new int[size] {};
	int counter = 1;
	for (int i = 0; i < size; i++)
	{
		if (i >= (size - no_ofBooks))
		{
			cout << "Enter the id of added book " << counter << ": ";
			cin >> ids_a[i];
			while (is_avaliable(ids, size, ids_a[i]))
			{
				cout << "Oh! This book is already available , Please add another one: ";
				cin >> ids_a[i];
			}
			cout << endl;
			counter++;
		}
		else
		{
			ids_a[i] = ids[i];
		}
	}
	return ids_a;
}
string* add_titles(string* titles, int size, int no_ofBooks)
{
	string* titles_a = new string[size];
	int counter = 1;
	cin.ignore();
	for (int i = 0; i < size; i++)
	{
		if (i >= (size - no_ofBooks))
		{
			cout << "Enter the title of added book " << counter << ": ";
			getline(cin, titles_a[i]);
			cout << endl;
			counter++;
		}
		else
		{
			titles_a[i] = titles[i];
		}
	}
	return titles_a;
}

string* add_authors(string* authors, int size, int no_ofBooks)
{
	string* authors_a = new string[size];
	int counter = 1;
	for (int i = 0; i < size; i++)
	{
		if (i >= (size - no_ofBooks))
		{
			cout << "Enter the author of added book " << counter << ": ";
			getline(cin, authors_a[i]);
			cout << endl;
			counter++;
		}
		else
		{
			authors_a[i] = authors[i];
		}

	}
	return authors_a;
}

void search_books(int* ids, int size, int no_ofBooks)
{
	int* dis = new int[no_ofBooks];
	for (int i = 0; i < no_ofBooks; i++)
	{
		cout << "Enter the id of searched book " << i + 1 << ": ";
		cin >> dis[i];
		cout << endl;
	}
	for (int i = 0; i < no_ofBooks; i++)
	{
		int found = 0;
		for (int j = 0; j < size; j++)
		{
			if (dis[i] == ids[j])
			{
				cout << "The book with ID " << dis[i] << " is available at position " << j << endl;
				found++;
				continue;
			}
		}
		if (!found)
			cout << "The book with ID " << dis[i] << " is not available " << endl;
	}
	delete[]dis;
}



int* remove_ids(int* ids, int size, int remove)
{
	int* ids_r = new int[size];
	bool counter = 0;
	for (int i = 0; i < size; i++)
	{
		if (ids[i] == remove)
		{
			counter = 1;
		}
		if (counter && i + 1 < size + 1)
		{
			ids_r[i] = ids[i + 1];
		}
		else
		{
			ids_r[i] = ids[i];
		}
	}
	return ids_r;
}

int position(int* ids, int size, int remove)
{
	for (int i = 0; i < size; i++)
	{
		if (ids[i] == remove)
			return i;
	}
	return -1;
}
string* remove_titles(string* titles, int size, int position)
{
	string* titles_r = new string[size];
	for (int i = 0; i < size; i++)
	{
		if (i >= position)
		{
			titles_r[i] = titles[i + 1];
		}
		else
		{
			titles_r[i] = titles[i];
		}
	}
	return titles_r;
}

string* remove_authors(string* authors, int size, int position)
{
	string* authors_r = new string[size];
	for (int i = 0; i < size; i++)
	{
		if (i >= position)
		{
			authors_r[i] = authors[i + 1];
		}
		else
		{
			authors_r[i] = authors[i];
		}
	}
	return authors_r;
}

void update_ids(int* ids, int size, int update, int new_id)
{
	for (int i = 0; i < size; i++)
	{
		if (ids[i] == update)
		{
			ids[i] = new_id;
			break;
		}
	}
}

void update_titles(int* ids, string* titles, int size, int update, string new_title)
{
	int k;
	for (int i = 0; i < size; i++)
	{
		if (ids[i] == update)
		{
			k = i;
			break;
		}
	}
	titles[k] = new_title;
}

void update_authors(int* ids, string* authors, int size, int update, string new_author)
{
	int j;
	for (int i = 0; i < size; i++)
	{
		if (ids[i] == update)
		{
			j = i;
			break;
		}
	}
	authors[j] = new_author;
}

int* return_ids(int* ids, int* ids_b, int size, int pos)
{
	int* ids_r = new int[size];
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			ids_r[i] = ids_b[pos];
		}
		else
		{
			ids_r[i] = ids[i];
		}
	}
	return ids_r;
}

string* return_titles(string* titles, string* titles_b, int size, int pos)
{
	string* titles_r = new string[size];
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			titles_r[i] = titles_b[pos];
		}
		else
		{
			titles_r[i] = titles[i];
		}
	}
	return titles_r;

}

string* return_authors(string* authors, string* authors_b, int size, int pos)
{
	string* authors_r = new string[size];
	for (int i = 0; i < size; i++)
	{
		if (i == size - 1)
		{
			authors_r[i] = authors_b[pos];
		}
		else
		{
			authors_r[i] = authors[i];
		}
	}
	return authors_r;
}

void display(int* ids, string* titles, string* authors, int size)
{
	cout << "Books' ID: " << setw(40) << "Books' Titles: " << setw(51) << "Books' Authors: " << endl;
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	if (size == 0)
		cout << "Nothing Here" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << ids[i] << setw(50) << titles[i] << setw(50) << authors[i] << endl;
	}
}