#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>

int navigation{ 0 };

short winWidth{ 0 };
short winHeight{ 0 };

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

void Menu()
{
	std::cout << std::string(winHeight / 2 - 10, '\n');

	std::cout << std::string(winWidth / 2 - 30, ' ') + "************************************************************\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "************************************************************\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "****                                                    ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "**** 1  - Ввод новых студентов                          ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "**** 2  - Вывод всех студентов                          ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "**** 3  - Поиск студентов                               ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "**** 4  - Отчисление (вручную)                          ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "****                                                    ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "**** 5  - Вывод информации по факультету                ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "****                                                    ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "**** 6  - Вывод информации по группе                    ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "****                                                    ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "****                                                    ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "****                                                    ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "****                                                    ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "**** 99 - Удаление всех существующих логов и данных     ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "**** 0  - Выход                                         ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "****                                                    ****\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "************************************************************\n";
	std::cout << std::string(winWidth / 2 - 30, ' ') + "************************************************************\n";

	std::cout << std::string(winHeight / 2 - 11, '\n');

	std::cin >> navigation;

	system("cls");
}

void Setup()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
	GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

	winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

	Menu();
}

int main()
{
	Setup();

	University university;

	do
	{
		switch (navigation)
		{
		case 1:
			std::cout << "Что дальше?" << std::endl;
			std::cin >> navigation;
			break;
		case 2:
			std::cout << "Что дальше?" << std::endl;
			std::cin >> navigation;
			break;
		case 3:  
			std::cout << "Что дальше?" << std::endl;
			std::cin >> navigation;
			break;
		case 4:
			std::cout << "Что дальше?" << std::endl;
			std::cin >> navigation;
			break;
		case 5:
			std::cout << "Что дальше?" << std::endl;
			std::cin >> navigation;
			break;
		case 6:
			std::cout << "Что дальше?" << std::endl;
			std::cin >> navigation;
			break;
			break;
		case 99:
			std::cout << "Что дальше?" << std::endl;
			std::cin >> navigation;
			break;
		default:
			break;
		}
	} while (navigation != 0);
}

