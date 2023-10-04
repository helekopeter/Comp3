#include <iostream>
#include "Comp3.h"
#include <cstdlib> //for random

using namespace std;

int main(){

	folder root(5);
	string input;

	do {
		cin >> input;
		if (input == "help")
		{
			cout << "newfile -- Make a new file" << endl;
			cout << "dir -- Lists all files and folders in current folder" << endl;
			cout << "rename -- Rename current folder" << endl;
		}
		else if (input == "rename")
		{
			string newname;
			cin >> newname;
			root.Rename(newname);

			cout << root.Name;
		}
		else if (input == "newfile")
		{
			file newfile;
			string newname;
			cin >> newname;
			newfile.Rename(newname);
			newfile.setSize(rand() % 100);
			root.addFile(newfile);
		}
		else if (input == "dir")
		{
			root.displayFiles();
		}
	} while (input != "exit");
}