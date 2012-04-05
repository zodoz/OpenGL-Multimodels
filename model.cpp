#include "model.h"

Model::Model() {
}

void Model::init() {
#ifdef __APPLE__
  glGenVertexArraysAPPLE(1, &vao);
  glBindVertexArrayAPPLE(vao);
#else
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
#endif
  program = InitShader(vShader, fShader);
  glUseProgram(program);

  buffers = new GLuint[bufferCount];
  glGenBuffers(bufferCount, buffers);

  buildModel();

  model_view = glGetUniformLocation(program, "model_view");
  projection = glGetUniformLocation(program, "projection");

  unbindModel();
}

void Model::buildTri(vec3* points, int index, vec3 p1, vec3 p2, vec3 p3) {
  points[index] = p1;
  points[index+1] = p2;
  points[index+2] = p3;
}

void Model::unbindModel() {
#ifdef __APPLE__
  glBindVertexArrayAPPLE(0);
#else
  glBindVertexArray(0);
#endif
}

void Model::bindModel() {
#ifdef __APPLE__
  glBindVertexArrayAPPLE(vao);
#else
  glBindVertexArray(vao);
#endif
}
