#ifndef _VKLIST_H_
#define _VKLIST_H_

#include "VKListObject.h"
// базовый класс двунаправленного списка
class VKList
{
public:

  VKList(void);
  VKList(VKObject *object);
  virtual ~VKList(void);
  virtual string Print(void);

  virtual void Add(VKObject *object);
  virtual void Remove(VKObject *object);
  virtual void Clear(void);
protected:
  VKListObject *head;
};

#endif  // _VKLIST_H_
