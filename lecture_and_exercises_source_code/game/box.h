#ifndef GAME_BOX_H_
#define GAME_BOX_H_

#include <Eigen/Dense>

class Box {
  using vector_type = Eigen::Vector2f;

 public:
  Box() = default;
  Box(const vector_type& point) : min_{point}, max_{point} {}
  Box(const vector_type& min, const vector_type& max)
      : min_{min.array().min(max.array()).matrix()},
        max_{max.array().max(min.array()).matrix()} {}
  Box(const vector_type& point, float width, float height)
      : min_{point - vector_type{0.5f * width, 0.5f * height}},
        max_{point + vector_type{0.5f * width, 0.5f * height}} {}

  const vector_type& min() const { return min_; }
  const vector_type& max() const { return max_; }

  vector_type center() const { return 0.5f * (min() + max()); }
  float radius() const { return 0.5f * (max() - min()).norm(); }
  float width() const { return max().x() - min().x(); }
  float height() const { return max().y() - min().y(); }

 private:
  vector_type min_{};
  vector_type max_{};
};

inline Eigen::Vector2f center(const Box& box) { return box.center(); }
inline float radius(const Box& box) { return box.radius(); }
inline float width(const Box& box) { return box.width(); }
inline float height(const Box& box) { return box.height(); }

#endif  // GAME_BOX_H_