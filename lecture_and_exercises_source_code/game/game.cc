#include "game.h"

#include <QApplication>
#include <QPainter>
#include <QPainterPath>
#include <QTimer>

#include "painter_utils.h"

Game::Game(QWidget* parent) : QWidget(parent) {
  setBackgroundRole(QPalette::Base);
  setAutoFillBackground(true);

  QTimer* timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(loop_slot()));
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start(1000.0f / 60.0f);
}

void Game::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Escape) {
    QApplication::quit();
  } else if (event->key() == Qt::Key_Right) {
    key_right = true;
  } else if (event->key() == Qt::Key_Left) {
    key_left = true;
  } else if (event->key() == Qt::Key_Down) {
    key_down = true;
  } else if (event->key() == Qt::Key_Up) {
    key_up = true;
  }
}

void Game::keyReleaseEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Right) {
    key_right = false;
  } else if (event->key() == Qt::Key_Left) {
    key_left = false;
  } else if (event->key() == Qt::Key_Down) {
    key_down = false;
  } else if (event->key() == Qt::Key_Up) {
    key_up = false;
  }
}

void Game::paintEvent(QPaintEvent* event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  QPen pen(Qt::white, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
  painter.setPen(pen);
  painter.setBrush({Qt::white, Qt::SolidPattern});

  // painter.drawRect(QRect(0, 0, width(), height()));
  painter << QRect{0, 0, width(), height()};

  // painter.setPen({Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin});
  // painter.setBrush(Qt::NoBrush);

  painter << QPen{Qt::black} << QBrush{Qt::NoBrush};

  painter << Qt::SolidPattern << Box{{x - 10, y - 10}, {x + 10, y + 10}};
}

void Game::loop_slot() {
  if (key_up) y -= 1;
  if (key_down) y += 1;
  if (key_left) x -= 1;
  if (key_right) x += 1;
}