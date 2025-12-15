#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "geom.hpp"
#include "idraw.hpp"
namespace topit 
{
  struct Square: IDraw
  {
    Square(int x, int y, int a);
    Square(p_t dd, int a);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
    int a;
  };
}
#endif