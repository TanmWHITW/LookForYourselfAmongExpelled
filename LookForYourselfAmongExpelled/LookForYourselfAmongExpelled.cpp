#include <iostream>
#include <Windows.h>
#include <vector>
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
	:id(-1), fullName ("")
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
	University(int amount);
	~University();

	Student GetStudent(int index) const;
	void SetStudent(const Student& student);

	void ExportFile(const char* path) const;

private:
	int m_amount;
	std::vector<Student> m_students;
};

University::University(int amount)
	:m_amount(amount), m_students(std::vector<Student>(amount))
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
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	University university(0);

	university.ExportFile("../lol.txt");

	Sleep(5000);
	system("cls");
}

