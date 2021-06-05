#include "core.h"

list<string> core::fromListBox(ListBox^ box)
{
	list<string> list;

	for (int i = 0; i < box->Items->Count; i++)
		list.push_back(convertToString(box->Items[i]->ToString()));

	return list;
}

std::string core::convertToString(String^ st_ptr)
{
	std::string st = msclr::interop::marshal_as<std::string>(st_ptr);
	return st;
}

list<string> core::Delete(int line, list<string>l)
{
	list<string>::iterator it = l.begin();
	advance(it, line);
	l.erase(it);
	return l;
}

int core::find(string s, list<string>l)
{
	bool isfound = false;
	int cnt = 0;
	for (auto& it : l)
	{

		if (it.find(s) >= 0 && it.find(s) <= 10000)
		{
			isfound = true;
			break;
		}
		else cnt++;
	}
	if (isfound)
		return cnt;
	else
		return -1;

}
list<int> core::FindAll(string s, list<string>& l)
{
	list<int> pos;
	int cnt = 0;
	for (auto& it : l)
	{
		if (it.find(s) >= 0 && it.find(s) <= 10000)
		{
			pos.push_back(cnt);
		}
		cnt++;
	}
	return pos;
}

list<string> core::ReplaceAll(list<string>lst, string oldst, string newst)
{

	for (auto& it : lst)
	{
		if (it.find(oldst) >= 0 && it.find(oldst) <= 10000)
		{
			it.replace(it.find(oldst), oldst.length(), newst);
			while (it.find(oldst) >= 0 && it.find(oldst) <= 10000)
			{
				it.replace(it.find(oldst), oldst.length(), newst);
			}
		}

	}
	return lst;
}


list<string> core::read(string fileName,list<string> box)
{
	fstream infile(fileName, ios::in);
	string line = "";
	if (infile.is_open()) {
		while (getline(infile,line))
		{
			box.push_back(line);
		}
	infile.close();
	}

	return box;
}

void core::write(string fileName, list<string>box)
{
	fstream file(fileName, ios::out);
	list<string>::iterator it;
	while (file.is_open()) {
		for (auto it : box) {
			file << it;
			file << "\n";
		}
	file.close();
	}
}

list<string> core::insert(int index, string line, list<string>box)
{
	list<string>::iterator it = box.begin();
	advance(it, index);
	box.insert(it, line);

	return box;
}
list<string> core::update(int index, string line, list<string>box)
{
	list<string>::iterator it = box.begin();
	advance(it, index);
	box.insert(it, line);
	box.erase(it);
	return box;
}


