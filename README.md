# OpenGL Multiple Model Test

This program tests the rendering of multiple models via classes. Specifically, I am trying to create a "Model" class which will handel most of the rendering binding and unbinding such that all that needs to be done is the following:

    model->bindModel();
    glDrawArrays(GL_TRIANGLES, 0, model->vertexCount);
    model->unbindModel();