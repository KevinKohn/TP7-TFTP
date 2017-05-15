#include "filelib.h"

using namespace std;

string filetostring(string s) {
	fstream file;
	file.open(s);
	string line=s;
	line += '\n';
	string temp;
	if (file.good()) {
		while (file.good()) {
			getline(file, temp);
			if (file.good()) {
				temp += '\n';
			}
			line += temp;
		}
	}
	else
		throw runtime_error("ERROR");
	file.close();
	return line;
}


string filetostring()
{
	string s;
	cout << "escriba el nombre del archivo: " << endl;
	cin >> s;
	fstream file;
	file.open(s);
	string line = s;
	line += '\n';
	string temp;
	if (file.good()) {
		while (file.good()) {
			getline(file, temp);
			if (file.good()) {
				temp += '\n';
			}
			line += temp;
		}
		file.close();
		system("cls");
		return line;
	}
	else
	{
		system("cls");
		return filetostring();
	}
}

ofstream createfile(string pos,string name) {
	boost::filesystem::path dir(pos);
	boost::filesystem::create_directory(dir);
	ofstream dest(pos + "\\" + name);
	return dest;
}

void stringtofile(string pos, string s) {
	int count = 0;
	while (s[count] != '\n')
		count++;
	string s1;
	for (int i = 0; i < count; i++)
		s1.push_back(s[i]);
	ofstream newfile = createfile(pos, s1);
	if (count < s.size()) {
		string s2;
		for (int i = count + 1; i < s.size(); i++)
			s2.push_back(s[i]);
		newfile << s2;
	}
}


