//
//  Window.h
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 14/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#ifndef __ModernOpenGLTutorial__Window__
#define __ModernOpenGLTutorial__Window__

#define GLFW_INCLUDE_GLCOREARB
#include <iostream>
#include <GLFW/glfw3.h>
#include <IL/il.h>
#include <glm/glm.hpp>

class Window {
public:
   Window(GLint _width, GLint _height, std::string _title);
   virtual ~Window();
   void makeContextCurrent();
   bool shouldClose();
   GLint getFrameBufferWidth();
   GLint getFrameBufferHeight();
   void swapBuffers();
   GLFWwindow* getWindow();
   GLfloat getDeltaTime();
   bool isGrabbed();
   glm::vec2 getDeltaMousePos();
private:
   static GLint m_instanceCount;
   GLFWwindow* m_window;
   GLdouble m_lastBufferSwapTime;
   GLdouble m_deltaTime;
   bool m_grabbed;
   glm::vec2 m_lastMousePos;
   glm::vec2 m_deltaMousePos;
};

#endif /* defined(__ModernOpenGLTutorial__Window__) */
