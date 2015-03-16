#include "VKMark.h"
VKMark::VKMark()
{
  subject = VKSubject();
  mark = 0;
}
VKMark::VKMark(const VKSubject& _subject, const unsigned int& _mark)
{
  subject = _subject;
  mark = _mark;
}
string VKMark::GetClassName()
{
  return "VKMark";
}
string VKMark::Print()
{
  stringstream ss;
  ss << "Subject: " << subject.GetSubjectName() << " Mark: " << mark;
  return ss.str();
}
bool VKMark::operator==(const VKMark& object)
{
  VKMark m = object;
  return (m.GetSubject() == GetSubject() && m.GetMark() == GetMark());
}

VKSubject VKMark::GetSubject()
{
  return subject;
}
void VKMark::SetSubject(const VKSubject& _subject)
{
  subject = _subject;
}
unsigned int VKMark::GetMark()
{
  return mark;
}
void VKMark::SetMark(const unsigned int& _mark)
{
  mark = _mark;
}
