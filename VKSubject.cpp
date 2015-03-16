#include "VKSubject.h"
VKSubject::VKSubject()
{
  SubjectName = "";
}
VKSubject::VKSubject(const string& _SubjectName)
{
  SubjectName = _SubjectName;
}
string VKSubject::GetClassName()
{
  return "VKSubject";
}
string VKSubject::Print()
{
  return GetSubjectName();
}
bool VKSubject::operator==(const VKSubject& object)
{
  VKSubject s = object;
  return s.GetSubjectName() == GetSubjectName();
}
string VKSubject::GetSubjectName()
{
  return SubjectName;
}
void VKSubject::SetSubjectName(const string& _SubjectName)
{
  SubjectName = _SubjectName;
}
