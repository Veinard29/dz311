#include "VKGroup.h"
VKGroup::VKGroup()
{
  Name = "";
  students = new VKStudentList();
}
VKGroup::VKGroup(const string& _Name, VKStudentList* _students)
{
  Name = _Name;
  students = _students;
  if (students == 0)
    students = new VKStudentList();
}
VKGroup::~VKGroup()
{
  if (students != 0)
    delete students;
}
string VKGroup::GetClassName()
{
  return "VKGRoup";
}
string VKGroup::Print()
{
  stringstream ss;
  ss << "Name: " << Name << endl << "Students: " << endl << students->Print();
  return ss.str();
}
string VKGroup::GetName()
{
  return Name;
}
void VKGroup::SetName(const string& _Name)
{
  Name = _Name;
}
VKStudentList* VKGroup::GetStudents()
{
  return students;
}
VKStudentList* VKGroup::GetExcellentStudents()
{
  return students->GetExcellentStudents();
}
VKStudentList* VKGroup::GetBadStudents()
{
  return students->GetBadStudents();
}
float VKGroup::Average()
{
  return students->Average();
}
float VKGroup::Average(const VKSubject& subject)
{
  return students->Average(subject);
}
void VKGroup::Clear()
{
  students->students.clear();
  students = 0;
}
void VKGroup::AddStudent(VKStudent* student)
{
  students->students.push_back(*student);
}
void VKGroup::RemoveStudent(VKStudent* student)
{
  students->students.remove(*student);
}
VKGroup& VKGroup::operator+=(VKStudent* student)
{
  students->students.push_back(*student);
  return* this;
}
