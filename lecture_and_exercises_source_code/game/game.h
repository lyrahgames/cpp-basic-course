#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include <QApplication>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QPainterPath>
#include <QTimer>
#include <QWidget>

class Game : public QWidget {
  Q_OBJECT

 public:
  Game(QWidget* parent = nullptr) : QWidget(parent) {
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(loop_slot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000.0f / 60.0f);
  }

 protected:
  void keyPressEvent(QKeyEvent* event) override {
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

  void keyReleaseEvent(QKeyEvent* event) override {
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

  void paintEvent(QPaintEvent* event) override {
    QPainter painter(this);
    QPen pen(Qt::blue, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(Qt::SolidPattern);
    painter.drawRect(QRect(0, 0, width(), height()));

    painter.setBrush(Qt::NoBrush);
    QPainterPath path;
    path.moveTo(20, 80);
    path.lineTo(x, y);
    path.cubicTo(80, 0, 50, 50, 80, 80);
    painter.drawPath(path);

    QRect rect(10, 20, 80, 60);
    painter.drawRect(rect);
  }

 private slots:
  void loop_slot() {
    if (key_up) y -= 1;
    if (key_down) y += 1;
    if (key_left) x -= 1;
    if (key_right) x += 1;
  }

 private:
  bool key_up = false;
  bool key_down = false;
  bool key_left = false;
  bool key_right = false;
  int x = 10;
  int y = 10;
};

#endif  // GAME_GAME_H_