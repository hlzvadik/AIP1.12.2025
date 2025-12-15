#include "square.hpp"
#include <stdexcept>
topit::Square::Square(int x, int y, int a):
  d({x, y}),
  a(a)
{
  if (a <= 0)
  {
    throw std::logic_error("The length cannot be less then 0 or equal 0");
  }
}
topit::Square::Square(p_t dd, int a):
  d(dd),
  a(a)
{
  if (a <= 0)
  {
    throw std::logic_error("The length cannot be less then 0 or equal 0");
  }
}
topit::p_t topit::Square::begin() const
{
  return d;
}
topit::p_t topit::Square::next(p_t prev) const
{
  if (a == 1)
  {
    return begin();
  }
  if (prev.x == begin().x)
  {
    if (prev.y == begin().y + a - 1)
    {
      return {prev.x + 1, prev.y};
    }
    else
    {
      return {prev.x, prev.y + 1};  
    }
  }
  else if (prev.y == begin().y + a - 1)
  {
    if (prev.x == begin().x + a - 1)
    {
      return {prev.x, prev.y - 1};
    }
    else
    {
      return {prev.x + 1, prev.y};
    }
  }
  else if (prev.x == begin().x + a - 1)
  {
    if (prev.y == begin().y)
    {
      return {prev.x - 1, prev.y};
    }
    else
    {
      return {prev.x, prev.y - 1};
    }
  }
  else
  {
    return {prev.x - 1, prev.y};
  }
}