#include "database.h"

void convert_line(string line, string* fields) {
	// Converts a line into fields delimited by '|'
	for (int i = 0, f = 0; i < line.length(); i++) {
		if (line[i] == '|') {
			f++;
			continue;
		}
		fields[f] += line[i];
	}
}

void assign_fields(string* fields, Record* rec) {
	// Assigns the fields to their respective variables inside a record
	rec->department = fields[0];
	rec->name = fields[1];
	rec->shortBio = fields[2];
	rec->fullBio = fields[3];
	rec->email = fields[4];
	rec->office = fields[5];
	rec->officeHours = fields[6];
	rec->topics = stoi(fields[7]);
	//cout << "Debug: " << fields[8].length() << "\n";
	for (int i = 0, f = 0; i < fields[8].length(); i++) {
		if (fields[8][i] == ',') {
			f++;
			continue;
		}
		rec->research[f] += fields[8][i];
	}
	rec->acceptingStudents = stoi(fields[9]);
}

Database::Database(string fileName) {
	// Initializes the database
	reset();
	load(fileName);
	openFile = fileName;
}

Record Database::parse_record(string line)
{
	// Parses a line into individual fields (array of strings of length 10 [for now])
	Record rec;
	string fields[10];
	convert_line(line, fields);
	assign_fields(fields, &rec);
	return rec;
}

void Database::add_rec(Record record)
{
	// Adds a record to the database
	if (size >= capacity) { // Doubles the capacity of the vector if it is full
		capacity *= 2;
		recs.resize(capacity * sizeof(Record));
	}
	recs.insert(recs.begin() + size++, record);
}

void Database::fprint_rec(FILE* file, int index, string delimiter) {
	// This monstrocity of a C function prints every variable of a record to a file.
	// For printing to a .txt file, this database uses "|".
	fprintf(file, "%s%s", recs.at(index).department.c_str(), delimiter.c_str());
	fprintf(file, "%s%s", recs.at(index).name.c_str(), delimiter.c_str());
	fprintf(file, "%s%s", recs.at(index).shortBio.c_str(), delimiter.c_str());
	fprintf(file, "%s%s", recs.at(index).fullBio.c_str(), delimiter.c_str());
	fprintf(file, "%s%s", recs.at(index).email.c_str(), delimiter.c_str());
	fprintf(file, "%s%s", recs.at(index).office.c_str(), delimiter.c_str());
	fprintf(file, "%s%s", recs.at(index).officeHours.c_str(), delimiter.c_str());
	fprintf(file, "%i%s", recs.at(index).topics, delimiter.c_str());
	for (int j = 0; j < recs.at(index).topics; j++) {
		fprintf(file, "%s", recs.at(index).research[j].c_str());
		if (j != recs.at(index).topics - 1)
			fprintf(file, "%s", ",");
	}
	fprintf(file, "%s%i%c", delimiter.c_str(), recs.at(index).acceptingStudents, '\n');
}

void Database::save(string fileName)
{
	// Saves the database to the current open file.
	FILE* file; 
	fopen_s(&file, fileName.c_str(), "w");
	for (int i = 0; i < size; i++)
		fprint_rec(file, i, "|");
	if (file != 0) fclose(file);
}

void Database::edit(int index, int rec_var, string input)
{
	// Edit a record's variable.
	string buf = "";
	int topics = 0;
	switch (rec_var) {
	case (0):
		recs.at(index).department = input;
		break;
	case (1):
		recs.at(index).name = input;
		break;
	case (2):
		recs.at(index).shortBio = input;
		break;
	case (3):
		recs.at(index).fullBio = input;
		break;
	case (4):
		recs.at(index).email = input;
		break;
	case (5):
		recs.at(index).office = input;
		break;
	case (6):
		recs.at(index).officeHours = input;
		break;
	case (8):
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == ',') {
				recs.at(index).research[topics++] = buf;
				buf = "";
				continue;
			}
			buf += input[i];
		}
		recs.at(index).topics = topics;
		break;
	case (9):
		if (input == "y")
			recs.at(index).acceptingStudents = true;
		else
			recs.at(index).acceptingStudents = false;
		break;
	}
}

void Database::load(string fileName)
{
	// Loads the file and adds it to the database.
	ifstream file(fileName);
	string line;
	while (getline(file, line)) {
		// Parse all lines in the .txt file into records and add them into the database
		add_rec(parse_record(line));
	}
	file.close();
	openFile = fileName;
}

void Database::reset()
{
	// Resets the database ("reconstructs" it)
	recs.clear();
	recs.shrink_to_fit();
	size = 0;
	capacity = 1;
	recs.reserve(1);
}

void Database::delete_rec(int index)
{
	// Deletes a record in the database at a given index.
	recs.erase(recs.begin() + (index - 1));
	size--;
	//cout << size << "; " << (recs.capacity()/sizeof(Record));
}

Database::~Database()
{
	recs.clear();
	recs.shrink_to_fit();
}

