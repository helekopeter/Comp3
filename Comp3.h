#pragma once
#include <string>

class file
{
private:
	int Size;
	int Date;
	std::string Name;
public:
	void Rename(std::string n)
	{
		Name = n;
	}
	void display() {
		std::cout << "File: " << Name << ", Size: " << Size << std::endl;
	}
	void setSize(int size)
	{
		Size = size;
	}
};

class folder
{
private:
	file* Files;

	int maxFiles;
	int maxFolders;
	int fileCount;


public:
	folder** Folders;
	int folderCount;
	std::string Name;
	folder(int maxFiles, int maxFolders) : maxFiles(maxFiles), fileCount(0), maxFolders(maxFolders), folderCount(0)
	{
		Files = new file[maxFiles];
		Folders = new folder*[maxFolders];
	}
	void display() {
		std::cout << "Folder: " << Name << std::endl;
	}
	void addFile(const file& newFile) {
		if (fileCount < maxFiles) {
			Files[fileCount] = newFile;
			fileCount++;
		}
		else {
			std::cout << "Folder is full" << std::endl;
		}
	}

	void addFolder(folder* newFolder) {
		if (folderCount < maxFolders) {
			Folders[folderCount] = newFolder;
			folderCount++;
		}
		else {
			std::cout << "Folder is full" << std::endl;
		}
	}

	void displayFiles() {
		for (int i = 0; i < fileCount; i++) {
			Files[i].display();
		}
	}
	void displayFolders() {
		for (int i = 0; i < folderCount; i++) {
			Folders[i]->display();
			Folders[i]->displayFiles();
		}
	}
	void Rename(std::string n)
	{
		Name = n;
	}
};