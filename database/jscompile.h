#pragma once
#include "database.h"

string prof_data(Database* db, int index);

void fprint_dept(Database* db, ofstream* file, const string Dept, const string dept);

void fprint_helpfunc(ofstream* file);

void js_compile(Database* db);