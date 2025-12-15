#include <iostream>
#include "ascii_draw.hpp"

int main() {
  using topit::IDraw;
  using topit::Dot;
  using topit::HorizontalLine;
  using topit::VerticallLine;
  using topit::SlopingLine;
  using topit::Square;
  using topit::Rectangle;
  using topit::f_t;
  using topit::p_t;
  int err = 0;
  size_t count = 6;
  IDraw* shps[count] = {};
  p_t * pts = nullptr;
  size_t s = 0;
  try {
      shps[0] = new Dot(0,0);
      shps[1] = new HorizontalLine(2,0,5);
      shps[2] = new VerticallLine(8,0,5);
      shps[3] = new SlopingLine(10,0,5);
      shps[4] = new Square(16,0,5);
      shps[5] = new Rectangle(22,0,5,6);
    for (size_t i = 0; i < count; ++i) {
      s += points(*(shps[i]), &pts, s);
    }
    f_t fr = frame(pts, s);
    char * cnv = canvas(fr, '.');
    for (size_t i = 0; i < s; ++i) {
      paint(cnv, fr, pts[i], '#');
    }
    flush(std::cout, cnv, fr);
    delete [] cnv;
  } catch (...) {
    err = 2;
    std::cerr << "Bad drawing\n";
  }
  delete [] pts;
  for (size_t i = 0; i < count; ++i)
  {
    delete shps[i];
  }
  return err;
}
