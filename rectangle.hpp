#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "geom.hpp"
#include "idraw.hpp"
namespace topit 
{
  struct Rectangle: IDraw
  {
    Rectangle(int x, int y, int a, int b);
    Rectangle(p_t d, int a, int b);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
    int a, b;
  };
}
#endif