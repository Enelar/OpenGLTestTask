#include "automat.h""

#include <iostream>
#include <GL/freeglut.h>
#include <GL/gl.h>

#include <functional>

static automat test; // i dont care. test task.

void animate()
{
  test.Draw();
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
  glutInitContextVersion(4, 1);
  glutInitContextProfile(GLUT_CORE_PROFILE);
  glutCreateWindow(argv[0]);

  glutDisplayFunc(animate);
  glutIdleFunc(update);

  test.Start();
  glutMainLoop();
}