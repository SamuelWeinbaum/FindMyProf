#include "database.h"

void convert_line(string line, string* fields) {
	for (int i = 0, f = 0; i < line.length(); i++) {
		if (line[i] == '|') {
			f++;
			continue;
		}
		fields[f] += line[i];
	}
}

Database::Database(string fileName) {
	size = 0;
	capacity = 1;
	recs.reserve(1);
	ifstream file(fileName);
	string line;
	while (getline(file, line)) {
		add_rec(parse_record(line));
	}
	file.close();
}

Record Database::parse_record(string line)
{
	Record rec;
	string fields[10];
	//convert_line(line, fields);
	for (int i = 0, f = 0; i < line.length(); i++) {
		if (line[i] == '|') {
			f++;
			continue;
		}
		fields[f] += line[i];
	}
	rec.department = fields[0];
	rec.name = fields[1];
	rec.shortBio = fields[2];
	rec.fullBio = fields[3];
	rec.email = fields[4];
	rec.office = fields[5];
	rec.officeHours = fields[6];
	rec.topics = stoi(fields[7]);
	//cout << "Debug: " << fields[8].length() << "\n";
	for (int i = 0, f = 0; i < fields[8].length(); i++) {
		if (fields[8][i] == ',') {
			f++;
			continue;
		}
		rec.research[f] += fields[8][i];
	}
	rec.acceptingStudents = stoi(fields[9]);
	return rec;
}

void Database::add_rec(Record record)
{
	if (size >= capacity) { // Doubles the capacity of the vector if it is full
		capacity *= 2;
		recs.resize(capacity * sizeof(Record));
	}

	vector<Record>::iterator it = recs.begin(); // Sets the iterator to the start of the vector
	for (int i = 0; i < size; i++) it++; // Brings the iterator to the index where a Record is to be added
	recs.insert(it, record); // Insert the Record at that index
	size++;
}

void Database::print_rec(int index)
{
	cout<< recs.at(index).department << '\n'
		<< recs.at(index).name << '\n'
		<< recs.at(index).shortBio << '\n'
		<< recs.at(index).fullBio << '\n'
		<< recs.at(index).email << '\n'
		<< recs.at(index).office << '\n'
		<< recs.at(index).officeHours << '\n'
		<< recs.at(index).topics << '\n';

	for (int i = 0; i < recs.at(index).topics; i++) {
		cout << recs.at(index).research[i] << '\n';
	}

	cout << recs.at(index).acceptingStudents << '\n';
}

void Database::save(string fileName)
{
	ofstream file(fileName);
	for (int i = 0; i < size; i++) {
		file << recs.at(i).department << "|";
		file << recs.at(i).name << "|";
		file << recs.at(i).shortBio << "|";
		file << recs.at(i).fullBio << "|";
		file << recs.at(i).email << "|";
		file << recs.at(i).office << "|";
		file << recs.at(i).officeHours << "|";
		file << recs.at(i).topics << "|";
		for (int j = 0; j < recs.at(i).topics; j++) {
			file << recs.at(i).research[j];
			if (j != recs.at(i).topics - 1)
				file << ",";
		}
		file << "|" << recs.at(i).acceptingStudents << "\n";
	}
}

Database::~Database()
{
	recs.clear();
	recs.shrink_to_fit();
}
