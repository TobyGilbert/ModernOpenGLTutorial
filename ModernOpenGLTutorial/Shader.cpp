//
//  Shader.cpp
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 14/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#include "Shader.h"
#include "ShaderUtils.h"
#include "GLException.h"

Shader::Shader(std::string _path, GLenum _type){
   m_shaderID = shaderUtils::createShaderFromFile(_path.c_str(), _type);
   if (m_shaderID ==0){
      throw GLException("Shader creation failed");
   }
}

Shader::~Shader(){
   glDeleteShader(m_shaderID);
}

GLuint Shader::getShaderID(){
   return m_shaderID;
}

