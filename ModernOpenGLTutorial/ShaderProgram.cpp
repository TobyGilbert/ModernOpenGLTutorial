//
//  ShaderProgram.cpp
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 14/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#include "ShaderProgram.h"
#include "Shader.h"
#include "GLException.h"

ShaderProgram::ShaderProgram(){
   m_programID = glCreateProgram();
}

ShaderProgram::~ShaderProgram(){
   glDeleteProgram(m_programID);
}

void ShaderProgram::attachShader(Shader* _shader){
   glAttachShader(m_programID, _shader->getShaderID());
}

void ShaderProgram::bindFragDataLocation(GLuint _colourAttachment, std::string _name){
   glBindFragDataLocation(m_programID, _colourAttachment, _name.c_str());
}

void ShaderProgram::link(){
   glLinkProgram(m_programID);
   
   GLint linkStatus;
   glGetProgramiv(m_programID, GL_LINK_STATUS, &linkStatus);
   if (linkStatus != GL_TRUE){
      std::cerr<<"Program link failed to compile: "<<std::endl;
      
      GLint infoLogLength;
      glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
      GLchar* infoLog = new GLchar[infoLogLength + 1];
      glGetProgramInfoLog(m_programID, infoLogLength + 1, NULL, infoLog);
      std::cerr<<infoLog <<std::endl;
      delete infoLog;
      throw GLException("Shader program link failed");
   }
}

void ShaderProgram::use(){
   glUseProgram(m_programID);
}

GLint ShaderProgram::getAttribLoc(std::string _name){
   return glGetAttribLocation(m_programID, _name.c_str());
}

GLint ShaderProgram::getUniformLoc(std::string _name){
   return glGetUniformLocation(m_programID, _name.c_str());
}