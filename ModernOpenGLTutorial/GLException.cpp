//
//  GLException.cpp
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 15/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#include "GLException.h"

GLException::GLException(std::string _what){
   m_what = _what;
}

GLException::~GLException(){
   
}

const char* GLException::what(){
   return m_what.c_str();
}