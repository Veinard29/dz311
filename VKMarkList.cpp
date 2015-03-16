#include "VKMarkList.h"

string VKMarkList::GetClassName()
{
  return "VKMarkList";
}

unsigned int VKMarkList::MinMark()
{
  unsigned int min = INT_MAX;
  for (list<VKMark>::iterator m = marks.begin(); m != marks.end(); ++m)
  {
    unsigned int mark = m->GetMark();
    if (mark < min)
      min = mark;
  }
  return min;
}
unsigned int VKMarkList::MaxMark()
{
  unsigned int max = 0;
  for (list<VKMark>::iterator m = marks.begin(); m != marks.end(); ++m)
  {
    unsigned int mark = m->GetMark();
    if (mark > max)
      max = mark;
  }
  return max;
}
float VKMarkList::Average()
{
  float avg = 0.0;
  unsigned int count = 0;
  for (list<VKMark>::iterator m = marks.begin(); m != marks.end(); ++m)
  {
    unsigned int mark = m->GetMark();
    avg += mark;
    count++;
  }
  return avg / count;
}
float VKMarkList::Average(const VKSubject& subject)
{
  float avg = 0.0;
  unsigned int count = 0;
  for (list<VKMark>::iterator m = marks.begin(); m != marks.end(); ++m)
  {
    if (m->GetSubject() == subject)
    {
      avg += m->GetMark();
      count++;
    }
  }
  return avg / count;
}

string VKMarkList::Print()
{
  stringstream result;
  for (list<VKMark>::iterator m = marks.begin(); m != marks.end(); ++m)
  {
    result << m->Print() << endl;
  }
  return result.str();
}
