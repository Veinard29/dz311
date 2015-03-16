#ifndef _VKMARK_H_
#define _VKMARK_H_
#include "VKObject.h"
#include "VKSubject.h"

class VKMark : public VKObject
{
public:
  VKMark();
  VKMark(const VKSubject& _subject, const unsigned int& _mark);

  string GetClassName();
  string Print();
  bool operator==(const VKMark& object);

  VKSubject GetSubject();
  void SetSubject(const VKSubject& _subject);
  unsigned int GetMark();
  void SetMark(const unsigned int& _mark);

private:
  VKSubject subject;
  unsigned int mark;
};

#endif  
