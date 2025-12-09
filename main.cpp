#include <iostream>
namespace topit {
  struct p_t { int x, y; };
  bool operator==(p_t, p_t);
  bool operator!=(p_t, p_t);
  struct f_t { p_t aa, bb; };

  struct IDraw {
    virtual ~IDraw() = default;
    virtual p_t begin() const = 0;
    virtual p_t next(p_t) const = 0;
  };

  struct Dot: IDraw {
    Dot(int x, int y);
    explicit Dot(p_t dd);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
  };

  struct HorizontalLine: IDraw
  {
    HorizontalLine(int x, int y, int len);
    HorizontalLine(p_t dd, int len);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
    int len;
  };

  struct VerticallLine: IDraw
  {
    VerticallLine(int x, int y, int len);
    VerticallLine(p_t dd, int len);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
    int len;
  };

  struct SlopingLine: IDraw
  {
    SlopingLine(int x, int y, int len);
    SlopingLine(p_t dd, int len);
    p_t begin() const override;
    p_t next(p_t) const override;
    p_t d;
    int len;
  };

  // Домашнее задание:
  // - Добавить ещё 2-3 фигуры:
  //   - Вертикальный отрезок
  //   - Горизонтальный отрезок
  //   - Диагональ под 45 заданной длины
  //   - Придумать свою фигуру

  // расширять заданный массив точками из очередной фигуры
  // - extend...
  size_t points(const IDraw& d, p_t** pts, size_t s);

  // найти минимум и максимум по каждой координате среди точек и сформировать фрейм
  f_t frame(const p_t* pts, size_t s);

  // построить полотно (из фрейма получить количество столбцов и колонок)
  char * canvas(f_t fr, char fill);

  // координаты точки перевести в координаты в двумерном массиве
  void paint(char* cnv, f_t fr, p_t p, char fill);

  // вывод двумперного массива на основе размеров, определяемых фреймом
  void flush(std::ostream& os, const char* cnv, f_t fr);


  void extend(p_t** pts, size_t s, p_t p);
  size_t rows(f_t);
  size_t cols(f_t);
}



int main() {
  using topit::IDraw;
  using topit::Dot;
  using topit::HorizontalLine;
  using topit::VerticallLine;
  using topit::f_t;
  using topit::p_t;
  using topit::SlopingLine;
  int err = 0;
  IDraw* shps[3] = {};
  p_t * pts = nullptr;
  size_t s = 0;
  try {
    shps[0] = new SlopingLine(0,0,5);
    shps[1] = new VerticallLine(5, 7, -2);
    shps[2] = new HorizontalLine(-5, -2, 1);
    for (size_t i = 0; i < 3; ++i) {
      s += points(*(shps[i]), &pts, s);
    }
    f_t fr = frame(pts, s);
    char * cnv = canvas(fr, ' ');
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
  delete shps[0];
  delete shps[1];
  delete shps[2];
  return err;
}
topit::Dot::Dot(p_t dd):
 IDraw(),
 d{dd}
{}
topit::Dot::Dot(int x, int y):
 IDraw(),
 d{x, y}
{}
topit::p_t topit::Dot::begin() const {
  return d;
}
topit::p_t topit::Dot::next(p_t prev) const {
  if (prev != begin()) {
    throw std::logic_error("bad impl");
  }
  return d;
}

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

bool topit::operator==(p_t a, p_t b) {
  return a.x == b.x && a.y == b.y;
}
bool topit::operator!=(p_t a, p_t b) {
  return !(a == b);
}

void topit::extend(p_t** pts, size_t s, p_t p)
{
  p_t* res = new p_t[s+1];
  for (size_t i = 0; i < s; ++i)
  {
    res[i] = (*pts)[i];
  }
  res[s] = p;
  delete[] *pts;
  *pts = res;
}

size_t topit::points(const IDraw& d, p_t** pts, size_t s)
{
  p_t p = d.begin();
  extend(pts, s, p);
  size_t delta = 1;

  while (d.next(p) != d.begin())  
  {
    p = d.next(p);
    extend(pts, s + delta, p);
    ++delta;
  }
  return delta;  
}

topit::f_t topit::frame(const p_t* pts, size_t s)
{
  if (!s)
  {
    throw std::logic_error("Bad size");
  }
  int minx = pts[0].x, maxx = minx;
  int miny = pts[0].y, maxy = miny;
  for (size_t i = 1; i < s; ++i)
  {
    minx = std::min(minx, pts[i].x);
    maxx = std::max(maxx, pts[i].x);
    miny = std::min(miny, pts[i].y);
    maxy = std::max(maxy, pts[i].y);
  }
  p_t aa{minx, miny};
  p_t bb{maxx, maxy};
  return {aa, bb};
}

size_t topit::rows(f_t fr)
{
  return (fr.bb.y - fr.aa.y + 1);
}

size_t topit::cols(f_t fr)
{
  return (fr.bb.x - fr.aa.x + 1);
}

char* topit::canvas(f_t fr, char fill)
{
  char* cnv = new char[rows(fr) * cols(fr)];
  for (size_t i = 0; i < rows(fr) * cols(fr); ++i)
  {
    cnv[i] = fill;
  }
  return cnv;
}

void topit::paint(char* cnv, f_t fr, p_t p, char fill)
{
  int dx = p.x - fr.aa.x;
  int dy = fr.bb.y - p.y;
  cnv[dy * cols(fr) + dx] = fill;
}


void topit::flush(std::ostream& os, const char* cnv, f_t fr)
{
  for (size_t i = 0; i < rows(fr); ++i)
  {
    for (size_t j = 0; j < cols(fr); ++j)
    {
      os <<cnv[i * cols(fr) + j];
    }
    os << '\n';
  }
}
