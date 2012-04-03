multmodel: multmodel.cpp InitShader.cpp
	g++ -w multmodel.cpp InitShader.cpp model.cpp square.cpp tri.cpp -o multmodel -framework Carbon -framework OpenGL -framework GLUT
