#ifndef __MODEL_H
#define __MODEL_H
#include "Angel.h"

class Model {
  public:
    const char *vShader, *fShader;
    GLuint vao, program, model_view, projection;
    GLuint* buffers;
    int vertexCount, bufferCount;
    virtual void buildModel() =0;
    void bindModel();
    void unbindModel();
    void init();
    Model();
  protected:
    void buildTri(vec3* points, int index, vec3 p1, vec3 p2, vec3 p3);
};

#endif
