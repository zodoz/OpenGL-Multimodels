#include "square.h"

Square::Square() {
  vShader = "vshader.glsl";
  fShader = "fshader.glsl";
  vertexCount = 2*3; //2 tris/face, 3 verticies/tri
  bufferCount = 2;
}

void Square::buildModel() {
  int verticies = 6;
  vec3* points = new vec3[verticies];
  vec3* colors = new vec3[verticies];
  //front
  buildFace(points, 0,
      vec3(0.3,0.3,0.3), vec3(-0.3,0.3,0.3),
      vec3(-0.3,-0.3,0.3), vec3(0.3,-0.3,0.3));
  for(int i=0;i<verticies;i++)
    colors[i] = vec3(1,0,0); //red

  glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
  glBufferData(GL_ARRAY_BUFFER, verticies*sizeof(vec3), points, GL_STATIC_DRAW);
  vPosition = glGetAttribLocation(program, "vPosition");
  glEnableVertexAttribArray(vPosition);
  glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

  glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
  glBufferData(GL_ARRAY_BUFFER, verticies*sizeof(vec3), colors, GL_STATIC_DRAW);
  vColor = glGetAttribLocation(program, "vColor");
  glEnableVertexAttribArray(vColor);
  glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

  delete[] points;
  delete[] colors;
}

/**
 * p2 - p1
 * |  / |
 * | /  |
 * p3 - p4
 */
void Square::buildFace(vec3* points, int i, vec3 p1, vec3 p2, vec3 p3, vec3 p4) {
  /*points[i] = p1; points[i+1] = p2; points[i+2] = p3;
  i+=3;
  points[i] = p2; points[i+1] = p4; points[i+2] = p3;*/
  buildTri(points, i, p1, p2, p3);
  buildTri(points, i+3, p1, p4, p3);
}
