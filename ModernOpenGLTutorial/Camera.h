//
//  Camera.h
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 15/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#ifndef __ModernOpenGLTutorial__Camera__
#define __ModernOpenGLTutorial__Camera__

#include <iostream>
#define GLFW_INCLUDE_GLCOREARD

#include <iostream>
#include <OpenGL/gl3.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Window.h"

class Camera{
public:
   Camera();
   ~Camera();
   void setPosition(glm::vec3 _position);
   void setRotation(glm::vec3 _rotation);
   void setMoveSpeed(float _moveSpeed);
   void setRotSpeed(float _rotSpeed);
   glm::mat4 getMatrix();
   void pollUserInput(Window* _window);

private:
   glm::vec3 m_position;
   glm::vec3 m_rotation;
   float m_moveSpeed;
   float m_rotationSpeed;
};

#endif /* defined(__ModernOpenGLTutorial__Camera__) */
