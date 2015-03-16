#include <iostream>
#include <locale>
#include <conio.h>

#include "VKGroup.h"

int main()
{
  setlocale(LC_ALL, "rus");
  int choice;
  VKGroup* group = 0;
  while (true)
  {
    cout << "1 - ������� ������" << endl;
    cout << "2 - �������� ��������" << endl;
    cout << "3 - ������� ��������" << endl;
    cout << "4 - ������ ������" << endl;
    cout << "5 - ���������" << endl;
    cout << "6 - ������������" << endl;
    cout << "7 - ������� ���� �� ������" << endl;
    cout << "8 - ������� ���� �� ������ �� ��������" << endl;
    cout << "9 - �������� ������" << endl;
    cout << "0 - �����" << endl;
    cout << endl << "��� �����" << endl;
    cin >> choice;
    if (choice == 0)
    {
      if (group != 0)
        delete group;
      return 0;
    }
    else if (choice == 1)
    {
      if (group != 0)
      {
        delete group;
      }
      group = new VKGroup();
      cout << "������� ���: ";
      string name;
      cin >> name;
      group->SetName(name);
      cout << endl;
    }
    else if (choice == 2)
    {
      if (group == 0)
      {
        cout << "������ �� �������" << endl;
        continue;
      }
      string name;
      int sex;
      unsigned int age;
      cout << "������� ���: ";
      cin >> name;
      cout << "������� ��� (1 - �������, 0 - �������): ";
      cin >> sex;
      cout << "������� �������: ";
      cin >> age;
      VKStudent* student = new VKStudent(name, sex == 1, age);
      cout << "������� ���������� ���������: ";
      int count = 0;
      cin >> count;
      for (int i = 0; i < count; i++)
      {
        string name;
        unsigned int mark;
        cout << "������� �������: ";
        cin >> name;
        cout << "������� ������: ";
        cin >> mark;
        VKSubject subject(name);
        student->AddMark(new VKMark(subject, mark));
      }
      group->AddStudent(student);
      cout << endl;
    }
    else if (choice == 3)
    {
      if (group == 0)
      {
        cout << "������ �� �������" << endl;
        continue;
      }
      string name;
      int sex;
      unsigned int age;
      cout << "������� ���: ";
      cin >> name;
      cout << "������� ��� (1 - �������, 0 - �������): ";
      cin >> sex;
      cout << "������� �������: ";
      cin >> age;
      VKStudent* student = new VKStudent(name, sex == 1, age);
      group->RemoveStudent(student);
      delete student;
      cout << endl;
    }
    else if (choice == 4)
    {
      if (group == 0)
      {
        cout << "������ �� �������" << endl;
        continue;
      }
      cout << group->Print() << endl;
      cout << endl;
    }
    else if (choice == 5)
    {
      if (group == 0)
      {
        cout << "������ �� �������" << endl;
        continue;
      }
      VKStudentList* list = group->GetExcellentStudents();
      cout << list->Print() << endl;
      delete list;
      cout << endl;
    }
    else if (choice == 6)
    {
      if (group == 0)
      {
        cout << "������ �� �������" << endl;
        continue;
      }
      VKStudentList* list = group->GetBadStudents();
      cout << list->Print() << endl;
      delete list;
      cout << endl;
    }
    else if (choice == 7)
    {
      if (group == 0)
      {
        cout << "������ �� �������" << endl;
        continue;
      }
      cout << "������� ����: " << group->GetStudents()->Average() << endl;
      cout << endl;
    }
    else if (choice == 8)
    {
      if (group == 0)
      {
        cout << "������ �� �������" << endl;
        continue;
      }
      string name;
      cout << "������� �������� ��������: ";
      cin >> name;
      VKSubject subject(name);
      cout << "������� ���� �� ��������: " << group->GetStudents()->Average() << endl;
      cout << endl;
    }
    else if (choice == 9)
    {
      if (group == 0)
      {
        cout << "������ �� �������" << endl;
        continue;
      }
      group->Clear();
      cout << endl;
    }
    else
    {
      cout << "�������� �����. ���������� ��� ���" << endl;
    }
  }
  return 0;
}