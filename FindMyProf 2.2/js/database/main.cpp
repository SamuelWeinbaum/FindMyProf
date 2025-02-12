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

void handleEdit(Database* db) {
	string index, rec_var, new_string;
	cout << "Index of entry: ";
	getline(cin, index);
	cout << "Which field would you like to edit?\n \
	0: Department\n \
	1: Name\n \
	2: shortBio\n \
	3: fullBio\n \
	4: Email\n \
	5: Office\n \
	6: Office Hours\n \
	8: Research Interests (format: Interest1,Interest2,...)\n \
	9: Accepting Students (y/n)\n \
Enter number: ";
	getline(cin, rec_var);
	cout << "Enter new string: ";
	getline(cin, new_string);
	db->edit(stoi(index), stoi(rec_var), new_string);
}

void help() {
	cout << "Welcome to the FindMyProf Database! \n\
Written by Aidan Marcelissen \n\n\
		Database Functions:\n\n\
	'help': Displays this message.\n\n\
	'exit': Exits the program (without saving!). \n\n\
	'list': Lists contents of the database (rudimentary at the moment).\n\n\
	'add': Adds an entry into the database. User will be prompted with each field to enter.\n\n\
	'load <file>': Loads a file to be written to. If no file is specified, loads 'db.txt' by default\n\
				   (and is what is loaded upon startup).\n\n\
	'save <file>': Saves the database to the specified file. If no file is specified, saves to the\
				   current open file (specified from 'load').\n\n\
	'reload': Reloads the currently open file to the database (unsaved entries will be lost!).\n\n\
	'compile': Compiles the database into 'professors.js', to be read by the website.\n\n\
	'edit': Edits an entry in the database. User will be prompted with which index and variable to edit.\n\n\
	'delete': Deletes an entry in the database. User will be prompted with which index to delete. \n\n";
}

int handleInput(string input, Database* db) {
	if (input == "exit") {
		return 0;
	}
	if (input == "list") {
		for (int i = 0; i < db->size; i++) {
			cout << "-=-=-=-=-=-=-=-Entry " << i + 1 << "-=-=-=-=-=-=-=-\n";
			db->fprint_rec(stdout, i, "\n");
		}
	}
	if (input == "add") {
		create_rec(db);
	}
	if (input.substr(0, 4) == "save") {
		cout << "Database saved to ";
		if (input.length() == 4) {
			db->save(db->get_openFile());
			cout << db->get_openFile() << ".\n";
		}
		else {
			db->save(&input[5]);
			cout << &input[5] << ".\n";
		}
		
	}
	if (input == "compile") {
		js_compile(db);
		cout << "Database compiled to professors.js.\n";
	}
	if (input == "edit") {
		handleEdit(db);
	}
	if (input.substr(0, 4) == "load") {
		db->reset();
		if (input.length() == 4)
			db->load(DEFAULT_DBFILE);
		else
			db->load(&input[5]);
		cout << "Loaded " << db->get_openFile() << ".\n";
	}
	if (input == "delete") {
		string index;
		cout << "Index of entry: ";
		getline(cin, index);
		db->delete_rec(stoi(index));
	}
	if (input == "reload") {
		db->reset();
		db->load(db->get_openFile());
		cout << "Reloaded " << db->get_openFile() << ".\n";
	}
	if (input == "help")
		help();
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