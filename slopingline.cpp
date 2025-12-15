#include "slopingline.hpp"
#include <stdexcept>
topit::SlopingLine::SlopingLine(int x, int y, int len):
  IDraw(),
  d({x,y}),
  len(len)
{
    if (len == 0)
  {
    throw std::logic_error("The length cannot be equal to 0");
  }
}
topit::SlopingLine::SlopingLine(p_t dd, int len):
  IDraw(),
  d(dd),
  len(len)
{
    if (len == 0)
  {
    throw std::logic_error("The length cannot be equal to 0");
  }
}
topit::p_t topit::SlopingLine::begin() const
{
  return d;
}
topit::p_t topit::SlopingLine::next(p_t prev) const
{
  if (begin().y + len - (len > 0 ? 1 : -1) == prev.y)
  {
    return begin();
  }
  else
  {
    return {prev.x + (len > 0 ? 1 : -1), prev.y + (len > 0 ? 1 : -1)};
  }
}