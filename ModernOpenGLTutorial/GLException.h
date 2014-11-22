//
//  GLException.h
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 15/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//

#ifndef __ModernOpenGLTutorial__GLException__
#define __ModernOpenGLTutorial__GLException__

#include <iostream>

class GLException: public std::exception{
public:
   GLException(std::string _what);
   virtual ~GLException();	
private:
   std::string m_what;
   virtual const char* what();
};
#endif /* defined(__ModernOpenGLTutorial__GLException__) */
