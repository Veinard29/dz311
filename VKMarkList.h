#ifndef _VKMARKLIST_H_
#define _VKMARKLIST_H_

#include "VKMark.h"
class VKMarkList : public VKObject
{
public:
  string GetClassName();
  unsigned int MinMark();
  unsigned int MaxMark();
  float Average();
  float Average(const VKSubject& subject);
  string Print();

  list <VKMark> marks;
};

#endif 
