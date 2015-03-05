#pragma once
#include <Windows.h>
#include <GL\GL.h>

struct automat_settings
{
  static const int rows = 3;
  static const int cols = 5;
};

struct scene_object
{
  virtual void Draw() = 0;
  virtual void Update(float t) = 0;
};

struct automat_column : scene_object
{
  int numbers[automat_settings::rows];
  float animation_offset = 0;
  float animation_target = 0;
  float rotation_speed = 0;

  void Draw() override;
  void Update(float t) override;

  void BakeTexture();
};

class automat;

struct virtual_row_iterator
{
  automat &target;
  int row, col;

  int operator->() const;
  virtual_row_iterator &operator++();
};

struct virtual_row_container
{
  automat &target;
  int row;

  virtual_row_iterator begin();
  virtual_row_iterator end();
};

class automat : scene_object
{
  automat_column bank[automat_settings::cols];
public:
  automat();

  void Start();
  void SelectLines();
  void Draw() override;
  void Update(float t) override;
};