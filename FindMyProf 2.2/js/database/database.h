#pragma once
#include "headers.h"

using namespace std;

typedef struct Record {
	string department, name, email, shortBio, fullBio, office, officeHours;
	string research[5];
	int topics = 0;
	bool acceptingStudents = false;
} record;

// Helper functions
void convert_line(string line, string* fields);
// Converts a line into fields
void assign_fields(string* fields, Record* rec);
// Assigns the fields to a record

class Database {
public:
	int size;
	Database(string fileName);
	Record parse_record(string line);
	void add_rec(Record record);
	void fprint_rec(FILE* file, int index, string delimiter);
	void save(string fileName);
	void edit(int index, int rec_var, string input);
	void reset();
	void load(string fileName);
	void delete_rec(int index);
	Record get_rec(int index) { return recs.at(index); }
	string get_openFile() { return openFile; }
	~Database();
private:
	std::vector<Record> recs;
	string openFile;
	int capacity;
};