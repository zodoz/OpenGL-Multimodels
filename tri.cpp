#include "tri.h"

Tri::Tri() {
  vShader = "vshader.glsl";
  fShader = "fshader.glsl";
  vertexCount = 3;
  bufferCount = 2;
}

void Tri::buildModel() {
  vec3* points = new vec3[vertexCount];
  vec3* colors = new vec3[vertexCount];
  
  buildTri(points,0,vec3(-.3,-.3,.5), vec3(0,.3,.5), vec3(.3,-.3,.5));

  for(int i=0;i<vertexCount;i++)
    colors[i] = vec3(0,0,1); //blue

  glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
  glBufferData(GL_ARRAY_BUFFER,vertexCount*sizeof(vec3),points,GL_STATIC_DRAW);
  vPosition = glGetAttribLocation(program, "vPosition");
  glEnableVertexAttribArray(vPosition);
  glVertexAttribPointer(vPosition, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

  glBindBuffer(GL_ARRAY_BUFFER, buffers[1]);
  glBufferData(GL_ARRAY_BUFFER,vertexCount*sizeof(vec3),colors,GL_STATIC_DRAW);
  vPosition = glGetAttribLocation(program, "vColor");
  glEnableVertexAttribArray(vColor);
  glVertexAttribPointer(vColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

  delete[] points;
  delete[] colors;
}
