#ifndef SLOPINGLINE_HPP
#define SLOPINGLINE_HPP
#include "geom.hpp"
#include "idraw.hpp"
namespace topit 
{
  struct SlopingLine: IDraw
  {
    SlopingLine(int x, int y, int len);
    SlopingLine(p_t dd, int len);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
    int len;
  };
}
#endif