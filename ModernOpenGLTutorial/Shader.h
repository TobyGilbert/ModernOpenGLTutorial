//
//  Shader.h
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 14/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#ifndef __ModernOpenGLTutorial__Shader__
#define __ModernOpenGLTutorial__Shader__

#include <iostream>
#include <GLFW/glfw3.h>
#include <IL/il.h>
#include <glm/glm.hpp>

class Shader{
public:
   Shader(std::string _path, GLenum _type);
   virtual ~Shader();
   GLuint getShaderID();
private:
   GLuint m_shaderID;
};

#endif /* defined(__ModernOpenGLTutorial__Shader__) */
