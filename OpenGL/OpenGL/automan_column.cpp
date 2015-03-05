#include "automat.h"

void automat_column::Draw()
{
  const float color = 0.3;

  glBegin(GL_QUADS);
  {
    glColor3f(color, color, color);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glVertex2f(1, 3);
    glVertex2f(0, 3);
  }
  glEnd();
}

void automat_column::Update(float deltat)
{
  animation_offset += rotation_speed * deltat;
  if (animation_offset > animation_target)
    animation_offset = animation_target;
}

void automat_column::BakeTexture()
{
  GLuint textureA;
  glGenTextures(1, &textureA);
  glBindTexture(GL_TEXTURE_2D, textureA);
}