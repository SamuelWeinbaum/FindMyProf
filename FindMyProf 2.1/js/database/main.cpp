#include "jscompile.h"

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
			cout << "-=-=-=-=-=-=-=-Entry " << i + 1 << "-=-=-=-=-=-=-=-\n";
			db->print_rec(i);
		}
	}
	if (input == "add") {
		create_rec(db);
	}
	if (input == "save") {
		db->save("db.txt");
		cout << "Database saved.\n";
	}
	if (input == "compile") {
		js_compile(db);
		cout << "Database compiled to professors.js.\n";
	}
	return 1;
}

int main() {
	//cout << "test\n";
	string input;
	Database db("db.txt");
	while (handleInput(input, &db)) {
		cout << "> ";
		getline(cin, input);
	}
	return 0;
}