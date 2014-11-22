//
//  Texture.h
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 15/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#ifndef __ModernOpenGLTutorial__Texture__
#define __ModernOpenGLTutorial__Texture__

#define GLFW_INCLUDE_GLCOREARB

#include <iostream>
#include <GLFW/glfw3.h>
#include <IL/il.h>
#include <glm/glm.hpp>

class Texture{
public:
   Texture(std::string _path);
   ~Texture();
   void bind(GLuint _unit);
   GLuint getTextureID();
   void setParamater(GLenum _pname, GLenum _param);
private:
   GLuint m_textureID;
   
};
#endif /* defined(__ModernOpenGLTutorial__Texture__) */
