#include "automat.h"

automat::automat()
{
  for (auto x = 0; x < automat_settings::cols; x++)
    for (auto y = 0; y < automat_settings::rows; y++)
      bank[x].numbers[y] = x + y * 10;
}

#include <random>
void automat::Start()
{
  std::default_random_engine generator; // todo fill with random seed
  std::uniform_real_distribution<float> duration_range(4, 5); // animation in seconds
  std::uniform_real_distribution<float> speed_range(0.5, 0.7); // numbers per second
  float animation_duration = duration_range(generator);
  const float time_between_stops = 0.1; // in seconds

  for (auto &col : bank)
  {
    col.rotation_speed = speed_range(generator);
    col.animation_target = col.animation_offset + col.rotation_speed * animation_duration;
    animation_duration += time_between_stops;
  }
}

void automat::Update(float deltat)
{
  for (auto &col : bank)
  {
    col.animation_offset += col.rotation_speed * deltat;
    if (col.animation_offset > col.animation_target)
      col.animation_offset = col.animation_target;
  }
}

void automat::Draw()
{
  // TODO: Draw
}