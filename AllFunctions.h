#pragma once
#include<iostream>
#include<string>
#include<iomanip>


using namespace std;


// Functions Prototypes: 

bool is_avaliable(int*, int, int);
int* add_ids(int*, int, int);
string* add_titles(string*, int, int);
string* add_authors(string*, int, int);
void search_books(int*, int, int);
int* remove_ids(int*, int, int);
int position(int*, int, int);
string* remove_titles(string*, int, int);
string* remove_authors(string*, int, int);
void update_ids(int*, int, int, int);
void update_titles(int*, string*, int, int, string);
void update_authors(int*, string*, int, int, string);
int* return_ids(int*, int*, int, int);
string* return_titles(string*, string*, int, int);
string* return_authors(string*, string*, int, int);
void display(int*, string*, string*, int);
