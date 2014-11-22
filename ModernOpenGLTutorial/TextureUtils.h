//
//  TextureUtils.h
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 14/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#ifndef __ModernOpenGLTutorial__TextureUtils__
#define __ModernOpenGLTutorial__TextureUtils__

#include <iostream>
#include <GLFW/glfw3.h>
#include <IL/il.h>

class TextureUtils{
public:
   static GLuint createTexture(const GLchar* path);
};

#endif /* defined(__ModernOpenGLTutorial__TextureUtils__) */
