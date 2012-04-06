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

  modelView = glGetUniformLocation(program, "modelView");
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

void Model::render() {
  bindModel();
  if(!customRender()) {
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);
  }
  unbindModel();
}
//{{{ matrix set functions
/*void Model::setWorldView(mat4 mat) {
  glUniformMatrix4fv(worldView, 1, GL_TRUE, mat);
}*/

void Model::setModelView(mat4 mat) {
  glUseProgram(program);  //ensure that the correct program is bound
  glUniformMatrix4fv(modelView, 1, GL_TRUE, mat);
}

void Model::setProjection(mat4 mat) {
  glUseProgram(program);  //ensure that the correct program is bound
  glUniformMatrix4fv(projection, 1, GL_TRUE, mat);
}
//}}}
//{{{ optional functions
bool Model::customRender() {
  return false;
}

void Model::preRender() {
}

void Model::postRender() {
}
//}}}
