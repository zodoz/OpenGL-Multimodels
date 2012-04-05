#ifndef __MODEL_H
#define __MODEL_H

#include "Angel.h"

class Model {
  public:
    //variables
    const char *vShader, *fShader;
    GLuint* buffers;
    int vertexCount, bufferCount;

    //functions
    Model();
    void bindModel();
    void unbindModel();
    void init();
    void render();
    void setModelView(mat4);
    void setProjection(mat4);

    //optional functions
    bool customRender();
    void preRender();
    void postRender();

    //virtual functions
    virtual void buildModel() =0;
  protected:
    GLuint vao, program, modelView, projection;
    void buildTri(vec3* points, int index, vec3 p1, vec3 p2, vec3 p3);
};

#endif
