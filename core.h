#pragma once
#include <list>
#include <iostream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include <fstream>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;

class core
{

public:	

	static list<string> fromListBox(ListBox^ box);
	static std::string convertToString(String^ st_ptr);
	static list<string> read(string fileName,list<string>);
	static void write(string fileName, list<string>);
	static list<string> insert(int index, string line,list<string>);
	static list<string> update(int index, string line,list<string>);
	static list<string> Delete(int line, list<string>);
	static int find(string , list<string>);
	static list<int> FindAll(string s, list<string>& l);
		
	static list<string> ReplaceAll(list<string>, string oldst, string newst);

};

