#ifndef SPRING_VIEWER_H_
#define SPRING_VIEWER_H_

#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QWidget>

class Viewer : public QWidget {
  Q_OBJECT

 public:
  Viewer(QWidget* parent = nullptr) : QWidget(parent) {
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(loop_slot()));
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000.0f / 60.0f);
  }

 protected:
  void paintEvent(QPaintEvent* event) override {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QPen pen(Qt::white, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);
    painter.setBrush({Qt::white, Qt::SolidPattern});
    painter.drawRect(QRect(0, 0, width(), height()));

    painter.setPen({Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin});
    painter.drawPoint(QPointF{x + 0.5f * width(), y + 0.5f * height()});
    painter.drawPoint(QPointF{0.5f * width(), 0.5f * height()});
  }

 private slots:
  void loop_slot() {
    // float new_x = x + dt * v;
    // float new_v = v - dt * omega * omega * x;
    // x = new_x;
    // v = new_v;

    // v = v - dt * omega * omega * x;
    // x = x + dt * v;

    v_x = v_x - dt * omega * omega * x;
    v_y = v_y - dt * omega * omega * y;
    x = x + dt * v_x;
    y = y + dt * v_y;
  }

 private:
  float x{100.0f};
  float y{0.0f};
  float v_x{0};
  float v_y{100 * 10};
  float dt{0.01f};
  float omega{10.0f};
};

#endif  // SPRING_VIEWER_H_