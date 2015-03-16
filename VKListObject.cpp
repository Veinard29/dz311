#include "VKListObject.h"
// конструктор без параметров
VKListObject::VKListObject(void)
{
  object = 0;
  previous = 0;
  next = 0;
}
// конструктор с параметров
VKListObject::VKListObject(VKObject *_object)
{
  object = _object;
  previous = 0;
  next = 0;
}
// деструктор
VKListObject::~VKListObject(void)
{
  // удаляем объект
  if (object != 0)
    delete object;
  if (previous != 0)
    previous->SetNextObject(next, true);
  if (next != 0)
    next->SetPreviousObject(previous, true);
}
// получаем объект
VKObject *VKListObject::GetObject(void)
{
  return object;
}
// сохраняем объект
void VKListObject::SetObject(VKObject *_object)
{
  object = _object;
}
// получаем предыдущий объект
VKListObject *VKListObject::GetPreviousObject(void)
{
  return previous;
}
// сохраняем предыдущий объект
void VKListObject::SetPreviousObject(VKListObject *_object, bool bInsertOnly)
{
  previous = _object;
  if (!bInsertOnly)
    previous->SetNextObject(this);
}
// получаем следующий объект
VKListObject *VKListObject::GetNextObject(void)
{
  return next;
}
// сохраняем следующий объект
void VKListObject::SetNextObject(VKListObject *_object, bool bInsertOnly)
{
  next = _object;
  if (!bInsertOnly)
    next->SetPreviousObject(this);
}
