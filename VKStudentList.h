#ifndef _VKSTUDENTLIST_H_
#define _VKSRUDENTLIST_H_
#include "VKSubject.h"
#include "VKStudent.h"
class VKStudentList : public VKObject
{
public:
  string GetClassName();
  VKStudentList* GetExcellentStudents();
  VKStudentList* GetBadStudents();
  float Average();
  float Average(const VKSubject& subject);
  string Print();

  list <VKStudent> students;
};

#endif 
