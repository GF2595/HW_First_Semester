#pragma once

struct Hashtable;

//Makes new hashtable
//Returns hashtable pointer
Hashtable* makeTable();

//Adds new word to hash table
//Receives table pointer and string
void addHashElement(Hashtable *table, std::string element);

//Prints hashtable with noting times, each word was added
//Receives table pointer
void printTable(Hashtable *table);

//Deletes hashtable
//Receives table pointer
void deleteTable(Hashtable *table);