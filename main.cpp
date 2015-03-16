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
    cout << "1 - Создать группу" << endl;
    cout << "2 - Добавить студента" << endl;
    cout << "3 - Удалить студента" << endl;
    cout << "4 - Список группы" << endl;
    cout << "5 - Отличники" << endl;
    cout << "6 - Задолженники" << endl;
    cout << "7 - Средний балл по группе" << endl;
    cout << "8 - Средний балл по группе по предмету" << endl;
    cout << "9 - Очистить группу" << endl;
    cout << "0 - Выход" << endl;
    cout << endl << "Ваш выбор" << endl;
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
      cout << "Введите имя: ";
      string name;
      cin >> name;
      group->SetName(name);
      cout << endl;
    }
    else if (choice == 2)
    {
      if (group == 0)
      {
        cout << "Группа не создана" << endl;
        continue;
      }
      string name;
      int sex;
      unsigned int age;
      cout << "Введите имя: ";
      cin >> name;
      cout << "Введите пол (1 - мальчик, 0 - девочка): ";
      cin >> sex;
      cout << "Введите возраст: ";
      cin >> age;
      VKStudent* student = new VKStudent(name, sex == 1, age);
      cout << "Введите количество предметов: ";
      int count = 0;
      cin >> count;
      for (int i = 0; i < count; i++)
      {
        string name;
        unsigned int mark;
        cout << "Введите предмет: ";
        cin >> name;
        cout << "Введите оценку: ";
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
        cout << "Группа не создана" << endl;
        continue;
      }
      string name;
      int sex;
      unsigned int age;
      cout << "Введите имя: ";
      cin >> name;
      cout << "Введите пол (1 - мальчик, 0 - девочка): ";
      cin >> sex;
      cout << "Введите возраст: ";
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
        cout << "Группа не создана" << endl;
        continue;
      }
      cout << group->Print() << endl;
      cout << endl;
    }
    else if (choice == 5)
    {
      if (group == 0)
      {
        cout << "Группа не создана" << endl;
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
        cout << "Группа не создана" << endl;
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
        cout << "Группа не создана" << endl;
        continue;
      }
      cout << "Средний балл: " << group->GetStudents()->Average() << endl;
      cout << endl;
    }
    else if (choice == 8)
    {
      if (group == 0)
      {
        cout << "Группа не создана" << endl;
        continue;
      }
      string name;
      cout << "Введите название предмета: ";
      cin >> name;
      VKSubject subject(name);
      cout << "Средний балл по предмету: " << group->GetStudents()->Average() << endl;
      cout << endl;
    }
    else if (choice == 9)
    {
      if (group == 0)
      {
        cout << "Группа не создана" << endl;
        continue;
      }
      group->Clear();
      cout << endl;
    }
    else
    {
      cout << "Неверный выбор. Попробуйте еще раз" << endl;
    }
  }
  return 0;
}