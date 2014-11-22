//
//  ShaderUtils.h
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 14/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#ifndef __ModernOpenGLTutorial__ShaderUtils__
#define __ModernOpenGLTutorial__ShaderUtils__

#include <iostream>
#include <GLFW/glfw3.h>
#include <fstream>
#include <streambuf>
#include <string>

class shaderUtils{
public:
   static GLuint createShaderFromFile(const GLchar* path, GLenum shaderType);
};
#endif /* defined(__ModernOpenGLTutorial__ShaderUtils__) */
