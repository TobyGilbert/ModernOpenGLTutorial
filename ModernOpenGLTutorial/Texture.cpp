//
//  Texture.cpp
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 15/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#include "Texture.h"
#include "TextureUtils.h"
#include "GLException.h"

Texture::Texture(std::string _path){
   m_textureID = TextureUtils::createTexture(_path.c_str());
   if(m_textureID == (GLenum) NULL){
      throw GLException("Texture creation failed");
   }
}

Texture::~Texture(){
   glDeleteTextures(1, &m_textureID);
}

void Texture::bind(GLuint _unit){
   glActiveTexture(GL_TEXTURE0 + _unit);
   glBindTexture(GL_TEXTURE_2D, m_textureID);
}

GLuint Texture::getTextureID(){
   return m_textureID;
}

void Texture::setParamater(GLenum _pname, GLenum _param){
   glBindTexture(GL_TEXTURE_2D, m_textureID);
   glTexParameteri(GL_TEXTURE_2D, _param, _param);
   glBindTexture(GL_TEXTURE_2D, NULL);
}