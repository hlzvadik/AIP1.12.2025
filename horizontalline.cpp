#include "horizontalline.hpp"
#include <stdexcept>

topit::HorizontalLine::HorizontalLine(int x, int y, int len):
  IDraw(),
  d({x,y}),
  len(len)
{
  if (len == 0)
  {
    throw std::logic_error("The length cannot be equal to 0");
  }
}
topit::HorizontalLine::HorizontalLine(p_t dd, int len):
  IDraw(),
  d(dd),
  len(len)
{
    if (len == 0)
  {
    throw std::logic_error("The length cannot be equal to 0");
  }
}
topit::p_t topit::HorizontalLine::begin() const
{
  return d;
}
topit::p_t topit::HorizontalLine::next(p_t prev) const
{
  if (begin().x + len - (len > 0 ? 1 : -1) == prev.x)
  {
    return begin();
  }
  else
  {
    return {prev.x + (len > 0 ? 1 : -1), prev.y};
  }
}