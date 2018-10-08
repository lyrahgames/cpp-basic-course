#ifndef GAME_PAINTER_UTILS_H_
#define GAME_PAINTER_UTILS_H_

#include <QPainter>

#include "box.h"

inline QPainter& operator<<(QPainter& painter, const QPen& pen) {
  painter.setPen(pen);
  return painter;
}

inline QPainter& operator<<(QPainter& painter, const QBrush& brush) {
  painter.setBrush(brush);
  return painter;
}

inline QPainter& operator<<(QPainter& painter, const QRect& rect) {
  painter.drawRect(rect);
  return painter;
}

inline QPainter& operator<<(QPainter& painter, const Box& box) {
  painter.drawRect(
      QRect{static_cast<int>(box.min().x()), static_cast<int>(box.min().y()),
            static_cast<int>(box.width()), static_cast<int>(box.height())});
  return painter;
}

#endif  // GAME_PAINTER_UTILS_H_