#include "verticalline.hpp"
#include <stdexcept>
topit::VerticallLine::VerticallLine(int x, int y, int len):
  IDraw(),
  d({x,y}),
  len(len)
{
    if (len == 0)
  {
    throw std::logic_error("The length cannot be equal to 0");
  }
}
topit::VerticallLine::VerticallLine(p_t dd, int len):
  IDraw(),
  d(dd),
  len(len)
{
    if (len == 0)
  {
    throw std::logic_error("The length cannot be equal to 0");
  }
}
topit::p_t topit::VerticallLine::begin() const
{
  return d;
}
topit::p_t topit::VerticallLine::next(p_t prev) const
{
  if (begin().y + len - (len > 0 ? 1 : -1) == prev.y)
  {
    return begin();
  }
  else
  {
    return {prev.x, prev.y + (len > 0 ? 1 : -1)};
  }
}
