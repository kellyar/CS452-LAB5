#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "shader.h"
#include <iostream>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

GLuint shaderProgramID;
GLuint vao;
GLuint vbo;
GLuint positionID, colorID;
GLuint textID;

#define TextureSize 64
GLuint textures[1];

GLubyte image[TextureSize][TextureSize][3];


GLfloat vertices[] = {
	-1.00000f, -1.00000f, 0.00000f, 
	-1.00000f, 1.00000f, 0.00000f, 
	1.00000f, 1.00000f, 0.00000f, 
	1.00000f, -1.00000f, 0.00000f
};

GLfloat colors[] = {
	1.0f, 0.0f, 0.0f, 0.0f,  //right
	1.0f, 0.0f, 0.0f, 0.0f, //top
	1.0f, 0.0f, 0.0f, 0.0f, //left
	1.0f, 0.0f, 0.0f, 0.0f, //bottom
};

GLfloat tex_coords[] = {
	0.0f, 0.0f,
	0.0f, 1.0f,
	1.0f, 1.0f,
	1.0f, 0.0f
};


void render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	glEnable(GL_TEXTURE_2D);
	glDrawArrays(GL_POLYGON, 0, 4);
	glutSwapBuffers();
}

int main (int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize(800,600);
	glutCreateWindow("Alex Kelly Lab 5");
	glutDisplayFunc(render);
	glewInit();

	shaderProgramID = createShaders();

	glClearColor (0.0, 0.0, 0.0, 0.0);
	
	//texture info
	//makeCheckImage();
	for ( int i = 0; i < TextureSize; i++ ) {
        for ( int j = 0; j < TextureSize; j++ ) {
            GLubyte c = (((i & 0x8) == 0) ^ ((j & 0x8)  == 0)) * 255;
            image[i][j][0]  = c;
            image[i][j][1]  = c;
            image[i][j][2]  = c;
            fprintf(stderr, "%d, %d, %d\n", c, c, c);
        }
    }

    // Initialize texture objects
    glGenTextures( 1, textures );

    glBindTexture( GL_TEXTURE_2D, textures[0] );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, TextureSize, TextureSize, 0,
		  GL_RGB, GL_UNSIGNED_BYTE, image );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

    glActiveTexture( GL_TEXTURE0 );
    glBindTexture( GL_TEXTURE_2D, textures[0] );

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// Create the buffer, but don't load anything yet
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors) + sizeof(vertices) + sizeof(tex_coords), NULL, GL_STATIC_DRAW);
	// Load the vertex points
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); 
	// Load the colors right after that
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(colors), colors);
	//load the textures
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(colors), sizeof(tex_coords), tex_coords);

	// Find the position of the variables in the shader
	positionID = glGetAttribLocation(shaderProgramID, "s_vPosition");
	colorID = glGetAttribLocation(shaderProgramID, "s_vColor");
	textID = glGetAttribLocation(shaderProgramID, "s_vTexCoord");

	glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( sizeof(vertices) ));
	glVertexAttribPointer(textID, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET( sizeof(vertices) + sizeof(colors) ));

	glUseProgram(shaderProgramID);
	glEnableVertexAttribArray(positionID);
	glEnableVertexAttribArray(colorID);
	
	glutMainLoop();

	return 0;
}
