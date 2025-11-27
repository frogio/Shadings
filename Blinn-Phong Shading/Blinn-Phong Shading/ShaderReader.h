#ifndef __SHADER_READER_H__
#define __SHADER_READER_H__

#include "glew.h"

void printShaderInfoLog(unsigned int shader);
void printProgramInfoLog(unsigned int obj);
char* readShader(const char* filename);


#endif