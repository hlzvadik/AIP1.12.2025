#ifndef HORIZONTALLINE_HPP
#define HORIZONTALLINE_HPP
#include "geom.hpp"
#include "idraw.hpp"
namespace topit 
{
  struct HorizontalLine: IDraw
  {
    HorizontalLine(int x, int y, int len);
    HorizontalLine(p_t dd, int len);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
    int len;
  };
}
#endif