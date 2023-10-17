#include <iostream>
#include "Comp3.h"
#include <cstdlib> //for random

using namespace std;

int main(){

	folder root(10,5);
	root.Rename("root");
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
			cout << "Name: ";
			cin >> newname;
			newfile.Rename(newname);
			newfile.setSize(rand() % 100);
			string at;
			cout << "What folder?" << endl;
			cin >> at;
			folder* targetFolder = nullptr;
			for (int i = 0; i < root.folderCount; i++) {
				if (root.Folders[i]->Name == at) {
					targetFolder = root.Folders[i];
					break;
				}
			}
			if (root.Name == at) {
				root.addFile(newfile);
			}

			else if (targetFolder != nullptr) {
				targetFolder->addFile(newfile);
			}
			else {
				std::cout << "Folder not found" << endl;
			}
		}
		else if (input == "newfolder")
		{
			folder* newfolder = new folder(10,5);
			string newname;
			std::cout << "Name: ";
			cin >> newname;
			newfolder->Rename(newname);
			root.addFolder(newfolder);
		}
		else if (input == "dir")
		{
			root.display();
			root.displayFiles();
			root.displayFolders();
		}
	} while (input != "exit");
}