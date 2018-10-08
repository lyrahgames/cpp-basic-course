#ifndef GAME_PARTICLE_H_
#define GAME_PARTICLE_H_

#include <Eigen/Dense>

class Particle {
 public:
  Particle() = default;

 private:
  Eigen::Vector2f position_{};
  Eigen::Vector2f velocity_{};
  float mass{};
};

#endif  // GAME_PARTICLE_H_