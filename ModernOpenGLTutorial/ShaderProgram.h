//
//  ShaderProgram.h
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 14/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#ifndef __ModernOpenGLTutorial__ShaderProgram__
#define __ModernOpenGLTutorial__ShaderProgram__

#define GLFW_INCLUDE_GLCOREARB
#include <iostream>
#include <GLFW/glfw3.h>
#include <IL/il.h>
#include <glm/glm.hpp>
#include <vector>

class Shader;

class ShaderProgram{
public:
   ShaderProgram();
   virtual ~ShaderProgram();
   void attachShader(Shader* _shader);
   void bindFragDataLocation(GLuint _colourAttatchment, std::string _name);
   void link();
   void use();
   GLint getAttribLoc(std::string _name);
   GLint getUniformLoc(std::string _name);
private:
   GLuint m_programID;
};

#endif /* defined(__ModernOpenGLTutorial__ShaderProgram__) */
