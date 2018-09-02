#include <QApplication>
#include <QCustomPlot>
#include <QVector>
#include <iostream>
#include <random>

int main(int argc, char** argv) {
  std::mt19937 rng{std::random_device{}()};
  std::normal_distribution<float> distribution{};

  QVector<double> x(101), y(101);  // initialize with entries 0..100
  double min = 0;
  double max = 0;
  double mean_x = 0;
  double mean_y = 0;
  for (int i = 0; i < 101; ++i) {
    constexpr float a = 1.0f;
    constexpr float b = 2.0f;
    x[i] = i / 50.0 - 1;                      // x goes from -1 to 1
    y[i] = a + b * x[i] + distribution(rng);  // let's plot a quadratic function
    max = std::max(max, y[i]);
    min = std::min(min, y[i]);
    mean_x += x[i];
    mean_y += y[i];
  }
  mean_x /= 101.0;
  mean_y /= 101.0;

  double cov = 0;
  double var = 0;
  for (int i = 0; i < 101; ++i) {
    cov += (x[i] - mean_x) * (y[i] - mean_y);
    var += (x[i] - mean_x) * (x[i] - mean_x);
  }
  double b = cov / var;
  double a = mean_y - b * mean_x;

  std::cout << "a = " << a << std::endl << "b = " << b << std::endl;

  QVector<double> f(101);
  for (int i = 0; i < 101; ++i) {
    f[i] = a + b * x[i];
  }

  QApplication application(argc, argv);
  QCustomPlot plot;
  plot.addGraph();
  plot.graph(0)->setData(x, y);
  plot.graph(0)->setScatterStyle(QCPScatterStyle::ssPlus);
  plot.graph(0)->setLineStyle(QCPGraph::lsNone);

  plot.addGraph();
  plot.graph(1)->setData(x, f);

  plot.xAxis->setRange(-1, 1);
  plot.yAxis->setRange(min - 0.1, max + 0.1);
  plot.replot();
  plot.show();
  return application.exec();
}