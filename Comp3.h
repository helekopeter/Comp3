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
	int fileCount;
public:
	folder(int maxFiles) : maxFiles(maxFiles), fileCount(0)
	{
		Files = new file[maxFiles];
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

	void displayFiles() {
		for (int i = 0; i < fileCount; i++) {
			Files[i].display();
		}
	}

	std::string Name;
	void Rename(std::string n)
	{
		Name = n;
	}
};