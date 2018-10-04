#include <iostream>

#include <QApplication>

#include "game.h"

int main(int argc, char** argv) {
  QApplication application(argc, argv);
  Game game{};
  game.show();
  return application.exec();
}