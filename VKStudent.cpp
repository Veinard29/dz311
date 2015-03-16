#include "VKStudent.h"
VKStudent::VKStudent()
{
  Name = "";
  Sex = true;
  Age = 0;
  marks = new VKMarkList();
}
VKStudent::VKStudent(const string& _Name, const bool& _Sex, const unsigned int& _Age, VKMarkList* _marks)
{
  Name = _Name;
  Sex = _Sex;
  Age = _Age;
  marks = _marks;
  if (marks == 0)
    marks = new VKMarkList();
}
VKStudent::~VKStudent()
{
  delete marks;
}
string VKStudent::GetClassName()
{
  return "VKStudent";
}
string VKStudent::Print()
{
  stringstream ss;
  stringstream sm;
  ss << "Name: " << Name << " Sex: " << ((Sex == true) ? "M" : "F") << " Age: " << Age;
  sm << marks->Print();
  if (!sm.str().empty()) 
    ss << " Marks: " << endl << ss.str();
  return ss.str();
}
bool VKStudent::operator==(const VKStudent& object)
{
  VKStudent s = object;
  return (Name == s.GetName() && Sex == s.GetSex() && Age == s.GetAge());
}
string VKStudent::GetName()
{
  return Name;
}
void VKStudent::SetName(const string& _Name)
{
  Name = _Name;
}
bool VKStudent::GetSex()
{
  return Sex;
}
void VKStudent::SetSex(const bool& _Sex)
{
  Sex = _Sex;
}
unsigned int VKStudent::GetAge()
{
  return Age;
}
void VKStudent::SetAge(const unsigned int& _Age)
{
  Age = _Age;
}
VKMarkList* VKStudent::GetMarks()
{
  return marks;
}
bool VKStudent::IsExcellent()
{
  return (marks->MinMark() == 5);
}
bool VKStudent::IsBad()
{
  return (marks->MinMark() <= 3);
}
void VKStudent::AddMark(VKMark* mark)
{
  marks->marks.push_back(*mark);
}
