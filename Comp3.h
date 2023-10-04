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
};

class folder
{
private:
	std::string Name;
public:
	void Rename(std::string n)
	{
		Name = n;
	}
};