#pragma once

struct automat_settings
{
  static const int rows = 3;
  static const int cols = 5;
};

struct automat_column
{
  int numbers[automat_settings::rows];
  float animation_offset = 0;
  float animation_target = 0;
  float rotation_speed = 0;
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

class automat
{
  automat_column bank[automat_settings::cols];
public:
  automat();

  void Start();
  void SelectLines();
  void Update(float delta_t);
  void Draw();
};