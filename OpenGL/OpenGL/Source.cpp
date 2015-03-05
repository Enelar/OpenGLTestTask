#include "automat.h""

#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include <functional>

static automat test; // i dont care. test task.

void animate()
{
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  test.Draw();

  glFlush();
}

void update()
{
  test.Update(0.01);
}


int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutInitContextProfile(GLUT_CORE_PROFILE);
  glutCreateWindow(argv[0]);

  glutDisplayFunc(animate);
  glutIdleFunc(update);

  glEnable(GL_TEXTURE_2D);

  test.Start();
  glutMainLoop();
}