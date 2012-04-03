#include "Angel.h"
#include "model.h"
#include "square.h"
#include "tri.h"

Square s;
Tri t;

const int
  DRAW_BOTH_SQUARE_FIRST = 1,
  DRAW_BOTH_TRI_FIRST = 2,
  DRAW_ONLY_SQUARE = 3,
  DRAW_ONLY_TRIANGLE = 4;

int drawMethod = DRAW_BOTH_SQUARE_FIRST;

//{{{ printError()
void printError() {
  GLenum err = glGetError();
  switch(err) {
    case GL_NO_ERROR:
      break;
    case GL_INVALID_ENUM:
      printf("gl error - invalid enum\n");
      break;
    case GL_INVALID_VALUE:
      printf("gl error - invalid value\n");
      break;
    case GL_INVALID_OPERATION:
      printf("gl error - invalid operation\n");
      break;
    case GL_INVALID_FRAMEBUFFER_OPERATION:
      printf("gl error - invalid framebuffer operation\n");
      break;
    case GL_OUT_OF_MEMORY:
      printf("gl error - out of memory\n");
      break;
  }
}
//}}}
//{{{1 Color Functions
/**
 * Converts 1 character hex to int
 * 
 * precondition: cHex element of [0-9A-Ea-e]
 */
int hexCharToInt(char hex) {
  int sub = 48;
  if(hex >= 'A') {
    sub = 55;
  }
  if(hex >= 'a') {
    sub = 87;
  }
  return hex-sub;
}

/**
 * Converts 2 character hex codes to a float from [0,1]
 */
int hexToInt(char* hex) {
  return hexCharToInt(hex[0])*16 + hexCharToInt(hex[1]);
}

/**
 * Converts 6 character hex codes to vec3
 */
vec3 hexToVec3(char* hex) {
  return vec3(
      ((float)hexToInt(hex))/256.0,
      ((float)hexToInt(hex+2))/256.0,
      ((float)hexToInt(hex+4))/256.0);
}

vec3 randomColor() {
  return vec3(
      (float)rand()/(float)RAND_MAX,
      (float)rand()/(float)RAND_MAX,
      (float)rand()/(float)RAND_MAX);
}
//}}}1
//{{{1 display()

void renderModel(Model* m) {
  m->bindModel();

  printf("drawing model\n");
  glDrawArrays(GL_TRIANGLES, 0, m->vertexCount);
  printError();

  m->unbindModel();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //draw arrays
  switch(drawMethod) {
    case DRAW_BOTH_SQUARE_FIRST:
      renderModel(dynamic_cast<Model*>(&s));
      renderModel(dynamic_cast<Model*>(&t));
      break;
    case DRAW_BOTH_TRI_FIRST:
      renderModel(dynamic_cast<Model*>(&t));
      renderModel(dynamic_cast<Model*>(&s));
      break;
    case DRAW_ONLY_SQUARE:
      renderModel(dynamic_cast<Model*>(&s));
      break;
    case DRAW_ONLY_TRIANGLE:
      renderModel(dynamic_cast<Model*>(&t));
      break;
  }
  printError();
  
  glutSwapBuffers();
  printf("swapped buffers\n");
}
//}}}1
//{{{1 Init Funciton
void init() {
  //init models
  s.init();
  t.init();
  
  //rest
  glEnable(GL_DEPTH_TEST);

  glClearColor(1.0, 1.0, 1.0, 1.0);  // background color
}
//}}}1
//{{{1 keyPressed
void keyPressed(unsigned char key, int x, int y) {
  switch(key) {
    case 'q':
      exit(EXIT_SUCCESS);
      break;
    case 'r':
      glutPostRedisplay();
      break;

    case '1':
      drawMethod = DRAW_BOTH_SQUARE_FIRST;
      glutPostRedisplay();
      break;
    case '2':
      drawMethod = DRAW_BOTH_TRI_FIRST;
      glutPostRedisplay();
      break;
    case '3':
      drawMethod = DRAW_ONLY_SQUARE;
      glutPostRedisplay();
      break;
    case '4':
      drawMethod = DRAW_ONLY_TRIANGLE;
      glutPostRedisplay();
      break;
  }
}
//}}}1
//{{{1 reshape()
void reshape(int w, int h) {
  printf("reshaping\n");
  printf("test\n");
  glViewport(0,0,w,h);
  printf("got viewport\n");
  printError();
  printf("getting aspect\n");
  GLfloat aspect = GLfloat(w)/h;
  printError();

  mat4 proj = Ortho(-1, 1, -1, 1, -1, 1);
  glUniformMatrix4fv(s.projection, 1, GL_TRUE, proj);
  glUniformMatrix4fv(s.model_view, 1, GL_TRUE, mat4(1));//*/
  glUniformMatrix4fv(t.projection, 1, GL_TRUE, proj);
  glUniformMatrix4fv(t.model_view, 1, GL_TRUE, mat4(1));//*/
  printf("sent matricies\n");
  printError();
}
//}}}1

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(512, 512);
  //TODO change window name
  glutCreateWindow("main");

  init();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyPressed);
  //glutMouseFunc(mouse);
  //glutMotionFuncion(motion);
  //glutIdleFunc(idle);
  
  glutMainLoop();
  return 0;
}
