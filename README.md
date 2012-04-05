# OpenGL Multiple Model Test

This program tests the rendering of multiple models via classes. Specifically, I have created a class `Model` which makes rendering of a model much easier:

    model->render();
    
Please examine the `Tri` class for a quick example of how to create a new model extending `Model`, the main requirement is that a `void buildModel()` function be specified.

## Note on rendering

For the purposes of the class which I created this for, we typically did rendering via:

	glDrawArrays(GL_TRIANGLES, 0, vertexCount);
	
If you would like to create a custom rendering funtion, simply override `bool customRender()` and return `true`. This will tell `Model` not to render via the above code.