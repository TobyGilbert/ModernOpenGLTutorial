//
//  main.cpp
//  ModernOpenGLTutorial
//
//  Created by Toby Gilbert on 14/08/2014.
//  Copyright (c) 2014 Toby Gilbert. All rights reserved.
//


#define GLFW_INCLUDE_GLCOREARD

#include <iostream>
#include <OpenGL/gl3.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "TextureUtils.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Window.h"
#include "Texture.h"
#include "Camera.h"

int main(int argc, const char * argv[])
{
   
   Window* window = new Window(640, 640, "Texture Test");
   ShaderProgram* program;
   Shader* vertexShader;
   Shader* fragmentShader;
   Texture* texture;
   
   window->makeContextCurrent();
   std::cout<<glGetString(GL_VERSION)<<std::endl;
   
   // set the clear colour
   glClearColor(0.5, 0.5, 0.5, 1.0);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   
   program = new ShaderProgram();
   vertexShader = new Shader("vertexShader.glsl", GL_VERTEX_SHADER);
   fragmentShader = new Shader("fragmentShader.glsl", GL_FRAGMENT_SHADER);
   
   program->attachShader(vertexShader);
   program->attachShader(fragmentShader);
   program->bindFragDataLocation(0, "fragColour");
   program->link();
   program->use();
   
   delete vertexShader;
   delete fragmentShader;
   
   texture = new Texture("shark.jpg");
   
   // create the vbo
   GLuint myVBO;
   glGenBuffers(1, &myVBO);
   glBindBuffer(GL_ARRAY_BUFFER, myVBO);
   
   // create and add data to the vbo
   GLfloat bufferData[] = {
      +0.5, +0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0,
      -0.5, +0.5, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0,
      -0.5, -0.5, 0.0, 1.0, 1.0, 1.0, 0.0, 1.0,
      +0.5, -0.5, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0
   };
   
   glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData, GL_STATIC_DRAW);
   glBindBuffer(GL_ARRAY_BUFFER, NULL);
   
   // create and add the element data
   GLuint myEBO;
   glGenBuffers(1, &myEBO);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
   
   GLushort indexData[] = {
      0, 1, 2,
      0, 2, 3
   };
   
   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_STATIC_DRAW);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
   
   // create a vao
   GLuint myVAO;
   glGenVertexArrays(1,&myVAO);
   glBindVertexArray(myVAO);
   
   // find the position of the shader input "position"
   GLint positionLoc = program->getAttribLoc("position");
   GLint texCoordLoc = program->getAttribLoc("texCoord");

   
   // connect the data to the shader input
   glEnableVertexAttribArray(positionLoc);
   glEnableVertexAttribArray(texCoordLoc);
   
   glBindBuffer(GL_ARRAY_BUFFER, myVBO);
   glVertexAttribPointer(positionLoc, 4, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), (GLvoid*)(0*sizeof(GL_FLOAT)));
   glVertexAttribPointer(texCoordLoc, 2, GL_FLOAT, GL_FALSE, 8*sizeof(GL_FLOAT), (GLvoid*)(4*sizeof(GL_FLOAT)));
   glBindBuffer(GL_ARRAY_BUFFER, NULL);
   glBindVertexArray(NULL);

   // find the location of the uniform
   GLint colourLoc = program->getUniformLoc("colour");;
   GLint texLoc = program->getUniformLoc("tex");
   GLint projLoc = program->getUniformLoc("projection");
   GLint viewLoc = program->getUniformLoc("view");
   GLint modelLoc = program->getUniformLoc("model");

   // set the uniform value
   glUniform1i(texLoc, 0);
   glUniform4f(colourLoc, 1.0, 1.0, 1.0, 1.0);

   texture->bind(0);
   
   glm::mat4 model = glm::mat4();
   model = glm::translate(model, glm::vec3(0.0, 0.0, -3.0));

   glUniformMatrix4fv(modelLoc, 1, false, glm::value_ptr(model));
   
   Camera cam = Camera();
   cam.setPosition(glm::vec3(0.0, 0.0, 0.0));
   cam.setRotation(glm::vec3(0.0, 0.0, 0.0));
   
   // render function
   while (!window->shouldClose()){
      cam.pollUserInput(window);
      std::cout<<"FPS: "<<1.0 / window->getDeltaTime()<<std::endl;
      // set the width and height of the window
      glViewport(0, 0, window->getFrameBufferWidth(), window->getFrameBufferHeight());
      glClear(GL_COLOR_BUFFER_BIT);
      
      float aspect = window->getFrameBufferWidth() / window->getFrameBufferHeight();
      glm::mat4 projection = glm::perspective(60.0f, aspect, 0.01f, 1000.0f);
      
      glUniformMatrix4fv(viewLoc, 1, false, glm::value_ptr(cam.getMatrix()));
      glUniformMatrix4fv(projLoc, 1, false, glm::value_ptr(projection));
      
      // bind the buffers and draw
      glBindVertexArray(myVAO);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myEBO);
      glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, NULL);
      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
      glBindVertexArray(NULL);
      
      glfwPollEvents();
      window->swapBuffers();
   }
   
   glBindTexture(GL_TEXTURE_2D, NULL);
   
   // delete the buffer and terminate the window
   glDeleteBuffers(1, &myEBO);
   glDeleteBuffers(1, &myVBO);
   glDeleteVertexArrays(1, &myVAO);

   delete texture;
   delete program;
   delete window;
   glfwTerminate();
   return 0;
}
