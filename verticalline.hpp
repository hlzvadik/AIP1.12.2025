#ifndef VERTICALLINE_HPP
#define VERTICALLINE_HPP
#include "geom.hpp"
#include "idraw.hpp"
namespace topit 
{
  struct VerticallLine: IDraw
  {
    VerticallLine(int x, int y, int len);
    VerticallLine(p_t dd, int len);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
    int len;
  };
}
#endif