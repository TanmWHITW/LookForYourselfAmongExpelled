#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>

struct Student
{
	int id;
	std::string fullName;

	Student();
	Student(int id, std::string fullname);
	~Student();
};

Student::Student()
	:id(0), fullName ("")
{
}

Student::Student(int id, std::string fullname)
	:id(id), fullName(fullname)
{
}

Student::~Student()
{
}

class University
{
public:
	University();
	~University();

	Student GetStudent(int index) const;
	void SetStudent(const Student& student);

	void ExportFile(const char* path) const;
	void ImportFile(const Student& student, const char* path);


private:
	std::vector<Student> m_students;
};

University::University()
	:m_students(std::vector<Student>())
{
}

University::~University()
{
}

Student University::GetStudent(int index) const
{
	return m_students[index];
}

void University::SetStudent(const Student& student)
{
	m_students.push_back(student);
}

void University::ImportFile(const Student& student, const char* path)
{
	std::string str;

	int id{0};
	std::string fullName;

	std::ifstream file;
	file.open(path, std::ios::in);

	if (!file.is_open())
	{
		std::cout << "Файл не может быть открыт/создан!\n";
		return;
	}

	while (std::getline(file, str))
	{
		std::getline(file, str);
		id = std::stoi(str);

		std::getline(file, fullName);

		SetStudent(Student(id, fullName));
	}

	file.close();
}

void University::ExportFile(const char* path) const
{
	std::ofstream file;
	file.open(path, std::ios::out);

	if (!file.is_open())
	{
		std::cout << "Файл не может быть открыт/создан!\n";
		return;
	}

	file << m_students.size();

	std::cout << "\nФайл создан!";
	file.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	University university;

	university.ImportFile(Student(), "../import.txt");

	university.ExportFile("../data.txt");

	Sleep(5000);
	system("cls");
}

