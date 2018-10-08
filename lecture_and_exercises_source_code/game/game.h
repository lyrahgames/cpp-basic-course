#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include <QKeyEvent>
#include <QPaintEvent>
#include <QWidget>

class Game : public QWidget {
  Q_OBJECT

 public:
  Game(QWidget* parent = nullptr);

 protected:
  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent* event) override;
  void paintEvent(QPaintEvent* event) override;

 private slots:
  void loop_slot();

 private:
  bool key_up = false;
  bool key_down = false;
  bool key_left = false;
  bool key_right = false;
  int x = 10;
  int y = 10;
};

#endif  // GAME_GAME_H_