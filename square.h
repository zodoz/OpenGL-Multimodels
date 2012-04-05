#ifndef __SQUARE_H
#define __SQUARE_H

#include "model.h"

class Square: public Model {
  public:
    void buildModel();
    Square();
  private:
    void buildFace(vec3*, int, vec3, vec3, vec3, vec3);
    GLuint vPosition, vColor;
};

#endif
