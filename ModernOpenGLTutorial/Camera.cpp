//
//  Camera.cpp
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 15/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#include "Camera.h"

Camera::Camera(){
   m_position = glm::vec3(0.0, 0.0, 0.0);
   m_rotation = glm::vec3(0.0, 0.0, 0.0);
   m_moveSpeed = 2.0;
   m_rotationSpeed = 5.0;
}

Camera::~Camera(){
   
}

void Camera::setPosition(glm::vec3 _position){
   m_position = _position;
}

void Camera::setRotation(glm::vec3 _rotation){
   m_rotation = _rotation;
}

void Camera::setMoveSpeed(float _moveSpeed){
   m_moveSpeed = _moveSpeed;
}

void Camera::setRotSpeed(float _rotSpeed){
   m_rotationSpeed = _rotSpeed;
}

glm::mat4 Camera::getMatrix(){
   glm::mat4 matrix = glm::mat4();
   matrix = glm::rotate(matrix, m_rotation.x, glm::vec3(1.0, 0.0, 0.0));
   matrix = glm::rotate(matrix, m_rotation.y, glm::vec3(0.0, 1.0, 0.0));
   matrix = glm::rotate(matrix, m_rotation.z, glm::vec3(0.0, 0.0, 1.0));
   matrix = glm::translate(matrix, -m_position);
   
   return matrix;
}

void Camera::pollUserInput(Window *_window){
   GLFWwindow* window = _window->getWindow();
   GLfloat deltaTime = _window->getDeltaTime();
   
   if (_window->isGrabbed()){
      glm::vec2 deltaMousePos = _window->getDeltaMousePos();
      m_rotation.y += deltaMousePos.x * m_rotationSpeed * deltaTime;
      m_rotation.x += deltaMousePos.y * m_rotationSpeed * deltaTime;
   }
   
   if(glfwGetKey(window, GLFW_KEY_W)){
      m_position.x += m_moveSpeed * sinf((m_rotation.y) * (M_PI / 180.0)) * deltaTime;
      m_position.z += -m_moveSpeed * cosf((m_rotation.y) * (M_PI / 180.0)) * deltaTime;

   }
   if(glfwGetKey(window, GLFW_KEY_S)){
      m_position.x += -m_moveSpeed * sinf((m_rotation.y) * (M_PI / 180.0)) * deltaTime;
      m_position.z += m_moveSpeed * cosf((m_rotation.y) * (M_PI / 180.0)) * deltaTime;
      
   }
   if(glfwGetKey(window, GLFW_KEY_A)){
      m_position.x += m_moveSpeed * sinf((m_rotation.y + 270.0) * (M_PI / 180.0)) * deltaTime;
      m_position.z += -m_moveSpeed * cosf((m_rotation.y + 270.0) * (M_PI / 180.0)) * deltaTime;
      
   }
   if(glfwGetKey(window, GLFW_KEY_D)){
      m_position.x += m_moveSpeed * sinf((m_rotation.y + 90.0) * (M_PI / 180.0)) * deltaTime;
      m_position.z += -m_moveSpeed * cosf((m_rotation.y + 90.0) * (M_PI / 180.0)) * deltaTime;
      
   }
   if(glfwGetKey(window, GLFW_KEY_SPACE)){
      m_position.y += m_moveSpeed * deltaTime;
   }
   if(glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) || glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT)){
      m_position.y -= m_moveSpeed * deltaTime;
   }
}