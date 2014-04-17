#version 130

in vec4 s_vPosition;
in vec2 s_vTexCoord;
in vec4 s_vColor;

out vec2 texCoord;
out vec4 color;

void main () {
	gl_Position = s_vPosition;
	color = s_vColor;
	texCoord = s_vTexCoord;
}
