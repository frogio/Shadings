#include <stdio.h>
#include <stdlib.h>
#include "ShaderReader.h"

#pragma warning(disable:4996)

void printShaderInfoLog(unsigned int shader) {
	int infologLenght = 0;
	int written = 0;
	char* infoLog;

	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infologLenght);

	if (infologLenght > 0) {
		infoLog = (char*)malloc(sizeof(char) * infologLenght);
		if (infoLog == NULL) {
			printf("Could not alloc InfoLog buf\n");
			exit(1);
		}

		glGetShaderInfoLog(shader, infologLenght, &written, infoLog);
		printf("Shader InfoLog:\n%s\n\n", infoLog);
		free(infoLog);
	}

}

void printProgramInfoLog(unsigned int obj) {
	int infologLength = 0;
	int written = 0;
	char* infoLog;

	glGetProgramiv(obj, GL_INFO_LOG_LENGTH, &infologLength);

	if (infologLength > 0) {
		infoLog = (char*)malloc(sizeof(char) * infologLength);
		glGetProgramInfoLog(obj, infologLength, &written, infoLog);
		printf("%s \n", infoLog);
		free(infoLog);
	}

}

char* readShader(const char * filename) {
	FILE * file;
	char* content = NULL;
	int length = 0;
	if (filename != NULL)
		file = fopen(filename, "r+");
	else {
		printf("File not found.");
		return 0;
	}

	if (file == NULL){
		printf("File not found.\n");
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	length = ftell(file);
	rewind(file);
	if (length > 0) {
		content = (char*)malloc(sizeof(char) * length + 1);
		length = fread(content, sizeof(char), length, file);
		content[length] = '\0';
	}
	fclose(file);

	return content;
}