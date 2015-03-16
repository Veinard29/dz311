#ifndef _VKGROUP_H_
#define _VKGROUP_H_

#include "VKObject.h"
#include "VKStudentList.h"

class VKGroup : public VKObject
{
public:
  VKGroup();
  VKGroup(const string& _Name, VKStudentList* _students);
  virtual ~VKGroup();

  string GetClassName();
  string Print();

  string GetName();
  void SetName(const string& _Name);
  VKStudentList* GetStudents();
  VKStudentList* GetExcellentStudents();
  VKStudentList* GetBadStudents();
  float Average();
  float Average(const VKSubject& subject);
  void Clear();

  void AddStudent(VKStudent* student);
  void RemoveStudent(VKStudent* student);
  VKGroup& operator+=(VKStudent* student);
private:
  string Name;
  VKStudentList* students;
};

#endif  
