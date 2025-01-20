#include "jscompile.h"

string prof_data(Database* db, int index) {
	string prof = "";
	prof += "name: '" + db->get_rec(index).name + "',\n"
		+ "shortBio: '" + db->get_rec(index).shortBio + "',\n"
		+ "fullBio: '" + db->get_rec(index).fullBio + "',\n"
		+ "email: '" + db->get_rec(index).email + "',\n"
		+ "office: '" + db->get_rec(index).office + "',\n"
		+ "officeHours: '" + db->get_rec(index).officeHours + "',\n"
		+ "researchInterests: [";
	for (int i = 0; i < db->get_rec(index).topics; i++) {
		prof += "'" + db->get_rec(index).research[i] + "'";
		if (i != db->get_rec(index).topics - 1)
			prof += ",";
	}
	prof += "],\n";
	if (db->get_rec(index).acceptingStudents == true)
		prof += "acceptingStudents: true\n";
	else
		prof += "acceptingStudents: false\n";
	return prof;
}

void fprint_dept(Database* db, ofstream* file, const string Dept, const string dept) {
	*file << dept << ": [\n{\n";
	for (int i = 0, j = 1; i < db->size; i++) {
		if (db->get_rec(i).department == Dept) {
			if (j != 1)
				*file << ",\n";
			*file << "id: '" << dept << j << "',\n";
			*file << prof_data(db, i);
			*file << "}";
			j++;
		}
	}
}

void fprint_helpfunc(ofstream* file) {
	string hfuncs = "\n\nfunction getDepartmentProfessors(department) {\n \
		return professors[department] || [];\n \
}\n \
\n \
function getProfessorById(id) {\n \
	for (const dept in professors) {\n \
		const prof = professors[dept].find(p => p.id === id);\n \
		if (prof) return prof;\n \
	}\n \
	return null;\n \
} ";
	*file << hfuncs;
}

void js_compile(Database* db) {
	ofstream file("professors.js");
	file << "const professors = {\n";
	fprint_dept(db, &file, "Math", "math");
	file << "\n],\n";
	fprint_dept(db, &file, "Physics", "phys");
	file << "\n]\n";
	//fprint_dept(db, &file, "Computer Science", "comp");
	//file << "\n]\n";
	file << "};\n";
	fprint_helpfunc(&file);
}

/*file << "math: [\n{\n";
	for (int i = 0, j = 1; i < db->size; i++) {
		if (db->get_rec(i).department == "Math") {
			if (j != 1)
				file << ",\n";
			file << "id: 'math" << j << "',\n";
			file << prof_data(db, i);
			file << "}";
			j++;
		}
	}*/