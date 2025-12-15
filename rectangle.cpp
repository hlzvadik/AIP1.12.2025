#include "rectangle.hpp"
#include <stdexcept>
topit::Rectangle::Rectangle(int x, int y, int a, int b):
  d({x, y}),
  a(a),
  b(b)
{
  if (a <= 0 || b <= 0)
  {
    throw std::logic_error("The length cannot be less then 0 or equal 0");
  }
}
topit::Rectangle::Rectangle(p_t dd, int a, int b):
  d(dd),
  a(a),
  b(b)
{
  if (a <= 0 || b <= 0)
  {
    throw std::logic_error("The length cannot be less then 0 or equal 0");
  }
}
topit::p_t topit::Rectangle::begin() const
{
  return d;
}
topit::p_t topit::Rectangle::next(p_t prev) const
{
  if (a == 1 && b == 1)
  {
    return begin();
  }
  if (prev.x == begin().x)
  {
    if (prev.y == begin().y + a - 1)
    {
      if (b == 1)
      {
        return begin();
      }
      return {prev.x + 1, prev.y};
    }
    else
    {
      return {prev.x, prev.y + 1};  
    }
  }
  else if (prev.y == begin().y + a - 1)
  {
    if (prev.x == begin().x + b - 1)
    {
      if (a == 1)
      {
        return begin();
      }
      return {prev.x, prev.y - 1};
    }
    else
    {
      return {prev.x + 1, prev.y};
    }
  }
  else if (prev.x == begin().x + b - 1)
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
