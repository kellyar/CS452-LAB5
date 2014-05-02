/* OBJ2H program, copyright Jeff Chastine */
/* Original file: cube.obj */
/* Version 1.0*/


#ifndef CUBE_H
#define CUBE_H

GLfloat vertices[] = {
//main
	 0.00f,  0.00f, -2.0f,
	 2.00f,  0.00f, -2.0f,
	 0.00f,  0.25f, -2.0f,
	 2.00f,  0.25f, -2.0f,
	 0.00f,  0.00f,  2.0f,
	 2.00f,  0.00f,  2.0f,
	 0.00f,  0.25f,  2.0f,
	 2.00f,  0.25f,  2.0f,

//extra not being used
	 1.00f,  0.25f,  0.0f,         
	 1.10f, 0.25f, 0.0f,         
	 1.00f,  0.27f,  0.0f,         
	 1.10f, 0.27f, 0.0f,         
	 1.00f,  0.25f,  0.1f,         
	 1.10f, 0.25f, 0.1f,         
	 1.00f,  0.27f,  0.1f,         
	 1.10f, 0.27,  0.1f
};

GLfloat colors[] = {
	1.0f, 1.0f, 1.0f, 
	1.0f, 1.0f, 1.0f, 
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f
};

GLuint indices[] = {
	0,	6,	4,
	0,	2,	6,
	0,	3,	2,
	0,	1,	3,
	2,	7,	6,
	2,	3,	7,
	4,	6,	7,
	4,	7,	5,
	0,	4,	5,
	0,	5,	1,
	1,	5,	7,
	1,	7, 	3
};

GLfloat textures[] = {
	0.0,1.0,
	1.0,1.0,
	0.0,1.0,
	1.0,1.0,
	0.0,0.0,
	1.0,0.0,
	0.0,0.0,
	1.0,0.0
};





#endif //cube_H
