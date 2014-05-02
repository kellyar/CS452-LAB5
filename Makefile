run: lab5.cpp
	g++ lab5.cpp MathHelper.cpp -lglut -lGLU -lSOIL -lGL -lGLEW -g
	
clean: 
	rm -f *.out *~ run
	
