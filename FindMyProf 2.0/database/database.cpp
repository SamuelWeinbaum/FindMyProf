#include "database.h"

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
	string fields[9];
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
	for (int i = 0, f = 0; i < fields[7].length(); i++) {
		if (fields[7][i] == ',') {
			f++;
			rec.topics++;
			continue;
		}
		rec.research[f] += fields[7][i];
	}
	rec.acceptingStudents = stoi(fields[8]);
	return rec;
}

void Database::add_rec(Record record)
{
	if (size >= capacity) {
		capacity *= 2;
		recs.resize(capacity * sizeof(Record));
	}
	vector<Record>::iterator it = recs.begin();
	for (int i = 0; i < size; i++)
		it++;
	recs.insert(it, record);
	size++;
}

void Database::print_rec(int index)
{
	cout << recs.at(index).department << '\n' 
		 << recs.at(index).name << '\n'
		 << recs.at(index).shortBio << '\n' 
		 << recs.at(index).fullBio << '\n'
		 << recs.at(index).email << '\n' 
		 << recs.at(index).office << '\n'
		 << recs.at(index).officeHours << '\n';

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
