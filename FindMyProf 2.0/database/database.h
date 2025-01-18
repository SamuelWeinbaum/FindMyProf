#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
using namespace std;

typedef struct Record {
	string department, name, email, shortBio, fullBio, office, officeHours;
	string research[5];
	int topics = 0;
	bool acceptingStudents = false;
} record;

class Database {
public:
	int size;
	Database(string fileName);
	Record parse_record(string line);
	void add_rec(Record record);
	void print_rec(int index);
	void save(string fileName);
	~Database();
private:
	std::vector<Record> recs;
	int capacity;
};