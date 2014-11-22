//
//  Window.cpp
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 14/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#include "Window.h"
#include "GLException.h"

GLint Window::m_instanceCount = 0;

Window::Window(GLint _width, GLint _height, std::string _title){
   if(m_instanceCount == 0){
      // initialise glfw and devIL
      ilInit();
      ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
      ilEnable(IL_ORIGIN_SET);
      
      GLint glfwStatus = glfwInit();
      if (glfwStatus != GL_TRUE){
         glfwTerminate();
         throw GLException("glfw failed to initialise");
      }
      
      // set the context version
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
      
      std::cout<<"GLFW Initialised"<<std::endl;
   }
   
   m_instanceCount++;
   
   m_window = glfwCreateWindow(_width, _height, _title.c_str(), nullptr, nullptr);
   if (m_window == nullptr){
      glfwTerminate();
      throw GLException("Window creation failed");
   }
}

Window::~Window(){
   m_instanceCount--;
   if (m_instanceCount == 0){
      glfwTerminate();
      std::cout<<"GLFW Deinitialised"<<std::endl;
   }
}

void Window::makeContextCurrent(){
   glfwMakeContextCurrent(m_window);
}

bool Window::shouldClose(){
   return glfwWindowShouldClose(m_window);
}

GLint Window::getFrameBufferWidth(){
   GLint width;
   glfwGetFramebufferSize(m_window, &width, NULL);
   return width;
}

GLint Window::getFrameBufferHeight(){
   GLint height;
   glfwGetFramebufferSize(m_window, &height, NULL);
   return height;
}

void Window::swapBuffers(){
   glfwPollEvents();
   glfwSwapBuffers(m_window);
   GLdouble currentTime = glfwGetTime();
   m_deltaTime = currentTime - m_lastBufferSwapTime;
   m_lastBufferSwapTime = currentTime;
   if (!m_grabbed && glfwGetMouseButton(m_window, 0)){
      m_grabbed = true;
      GLdouble x, y;
      glfwGetCursorPos(m_window, &x, &y);
      m_lastMousePos = glm::vec2(x, y);
      glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

   }
   if ( m_grabbed && glfwGetKey(m_window, GLFW_KEY_ESCAPE)){
      m_grabbed = false;
      glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
   }
   GLdouble x, y;
   glfwGetCursorPos(m_window, &x, &y);
   glm::vec2 currentMousePos = glm::vec2(x, y);
   m_deltaMousePos = currentMousePos - m_lastMousePos;
   m_lastMousePos = currentMousePos;
   
}

GLFWwindow* Window::getWindow(){
   return m_window;
}

GLfloat Window::getDeltaTime(){
   return m_deltaTime;
}

bool Window::isGrabbed(){
   return m_grabbed;
}

glm::vec2 Window::getDeltaMousePos(){
   return m_deltaMousePos;
}