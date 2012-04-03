multmodel: multmodel.cpp InitShader.cpp
	g++ -w multmodel.cpp InitShader.cpp -o multmodel -framework Carbon -framework OpenGL -framework GLUT
