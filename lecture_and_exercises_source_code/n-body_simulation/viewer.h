#ifndef SPRING_VIEWER_H_
#define SPRING_VIEWER_H_

#include <array>
#include <cmath>

#include <Eigen/Dense>

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
    for (int i = 0; i < N; ++i) {
      painter.drawPoint(QPointF{position[i].x() + 0.5f * width(),
                                position[i].y() + 0.5f * height()});
    }
  }

 private slots:
  void loop_slot() {
    constexpr float gamma = 1000.0f;

    time += time_step;

    for (int i = 0; i < N; ++i) {
      Eigen::Vector2f acceleration{0, 0};
      for (int j = 0; j < N; ++j) {
        if (i == j) continue;

        const float squared_norm = (position[j] - position[i]).squaredNorm();
        const float norm = std::sqrt(squared_norm);
        acceleration +=
            mass[j] * (position[j] - position[i]) / (norm * squared_norm);
      }

      velocity[i] += time_step * gamma * acceleration;
    }

    for (int i = 0; i < N; ++i) {
      position[i] += time_step * velocity[i];
    }
  }

 private:
  static constexpr int N = 3;
  float time_step{0.01f};
  float time{0};
  std::array<Eigen::Vector2f, N> position{Eigen::Vector2f{-100.0f, 0.0f},
                                          Eigen::Vector2f{100.0f, 0.0f},
                                          Eigen::Vector2f{0.0f, 0.0f}};
  std::array<Eigen::Vector2f, N> velocity{Eigen::Vector2f{5.0f, 15.0f},
                                          Eigen::Vector2f{-5.0f, -15.0f},
                                          Eigen::Vector2f{0.0f, 0.0f}};
  std::array<float, N> mass{100.0f, 100.0f, 100.0f};
};

#endif  // SPRING_VIEWER_H_