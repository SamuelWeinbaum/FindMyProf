#include "database.h"

void create_rec(Database* db) {
	Record rec;
	cout << "Department: ";
	getline(cin, rec.department);
	cout << "Name: ";
	getline(cin, rec.name);
	cout << "Short bio: ";
	getline(cin, rec.shortBio);
	cout << "Full bio: ";
	getline(cin, rec.fullBio);
	cout << "Email: ";
	getline(cin, rec.email);
	cout << "Office: ";
	getline(cin, rec.office);
	cout << "Office hours: ";
	getline(cin, rec.officeHours);
	cout << "Number of research interests: ";
	string input;
	getline(cin, input);
	rec.topics = stoi(input);
	for (int i = 0; i < rec.topics; i++) {
		cout << "Research interest #" << i+1 << ": ";
		getline(cin, rec.research[i]);
	}
	cout << "Accepting students (y/n): ";
	getline(cin, input);
	if (input == "y")
		rec.acceptingStudents = true;
	else
		rec.acceptingStudents = false;
	db->add_rec(rec);
}

int handleInput(string input, Database* db) {
	if (input == "exit") {
		return 0;
	}
	if (input == "list") {
		for (int i = 0; i < db->size; i++) {
			db->print_rec(i);
			cout << "\n";
		}
	}
	if (input == "add") {
		create_rec(db);
	}
	if (input == "save") {
		db->save("db.txt");
	}
	return 1;
}

int main() {
	string input;
	Database db("db.txt");
	while (handleInput(input, &db)) {
		cout << "> ";
		getline(cin, input);
	}
	return 0;
}