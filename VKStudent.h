#ifndef _VKSTUDENT_H_
#define _VKSTUDENT_H_
#include "VKObject.h"
#include "VKMarkList.h"
class VKStudent : public VKObject
{
public:
  VKStudent();
  VKStudent(const string& _Name, const bool& _Sex, const unsigned int& _Age, VKMarkList* _marks = 0);
  ~VKStudent();

  string GetClassName();
  string Print();
  bool operator==(const VKStudent& object);

  string GetName();
  void SetName(const string& _Name);
  bool GetSex();
  void SetSex(const bool& _Sex);
  unsigned int GetAge();
  void SetAge(const unsigned int& _Age);
  VKMarkList* GetMarks();

  bool IsExcellent();
  bool IsBad();
  void AddMark(VKMark* mark);

private:
  string Name;
  bool Sex;
  unsigned int Age;
  VKMarkList* marks;
};

#endif 
