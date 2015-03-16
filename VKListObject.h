#ifndef _VKLISTOBJECT_H_
#define _VKLISTOBJECT_H_

#include "VKObject.h"
// класс элемента двунаправленного списка
class VKListObject
{
public:
  VKListObject(void);
  VKListObject(VKObject *_object);
  ~VKListObject(void);

  VKObject *GetObject(void);
  void SetObject(VKObject *_object);
  VKListObject *GetPreviousObject(void);
  void SetPreviousObject(VKListObject *_object, bool bInsertOnly = false);
  VKListObject *GetNextObject(void);
  void SetNextObject(VKListObject *_object, bool bInsertOnly = false);

private:
  VKObject *object;
  VKListObject *previous;
  VKListObject *next;
};

#endif  // _VKLISTOBJECT_H_
