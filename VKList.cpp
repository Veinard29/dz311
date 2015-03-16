#include "VKList.h"
// конструктор без параметров
VKList::VKList(void)
{
  head = 0;
}
// конструктор с параметром
VKList::VKList(VKObject *object)
{
  head = new VKListObject(object);
}
// деструктор
VKList::~VKList(void)
{
  Clear();
}
// вывод на печать
string VKList::Print(void)
{
  if (head == 0)
    return "";
// если не в начале списка - идем в начало
  while (head->GetPreviousObject() != 0)
    head = head->GetPreviousObject();
  VKListObject *tmp = head;
  stringstream result;
// перебираем список и выводим на печать
  while (tmp != 0)
  {
    result << tmp->GetObject()->Print() << std::endl;
// переходит на следующий элемент
    tmp = tmp->GetNextObject();
  }
  return result.str();
}
// добавление в список
void VKList::Add(VKObject *object)
{
  if (head == 0)
  {
    head = new VKListObject(object);
  }
  else
  {
// если не в начале списка - идем в начало
    while (head->GetPreviousObject() != 0)
      head = head->GetPreviousObject();
    VKListObject *tmp = head;
// идем в конец списка
    while (tmp->GetNextObject() != 0)
      tmp = tmp->GetNextObject();
// срохранем новый єлемент в конец
    tmp->SetNextObject(new VKListObject(object), true);
  }
}

void VKList::Remove(VKObject *object)
{
  if (head == 0)
    return;
// если не в начале списка - идем в начало
  while (head->GetPreviousObject() != 0)
    head = head->GetPreviousObject();
  VKListObject *tmp = head;
// идем по списку
  while (tmp->GetNextObject() != 0)
  {
// сравниваем элементы
    if (*(tmp->GetObject()) == *object)
    {
// меняем указатели на корректные объекты
      if (tmp->GetPreviousObject() == 0 && tmp->GetNextObject() == 0)
        head = 0;
      else if (tmp->GetPreviousObject() == 0)
        head = tmp->GetNextObject();
      else
        head = tmp->GetPreviousObject();
// удаляем объект
      delete tmp;
      return;
    }
    else
// ищем дальше
    tmp = tmp->GetNextObject();
  }
}
// очистка списка
void VKList::Clear(void)
{
  if (head == 0)
    return;
// если не в начале списка - идем в начало
  while (head->GetPreviousObject() != 0)
    head = head->GetPreviousObject();

  VKListObject *tmp = head;
// методично удаляем все объекты
  while (head != 0)
  {
    tmp = head;
    head = head->GetNextObject();
    delete tmp;
  }
}
