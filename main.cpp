/* Copyright (c) 2016 Minecrack */
#define GLEW_STATIC
#define GL_GLEXT_PROTOTYPES
#define BUFFER_OFFSET(a) (reinterpret_cast<void*>(a))

#include <GL/glew.h>

#ifdef __linux__
#elif _WIN32
	#include <GL/wglew.h>
	#include <Windows.h>
#endif

#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdio.h>
#include <iostream>

using namespace std;

#include "Geometry.h"

enum VAO_IDS { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };

GLuint  VAOs[NumVAOs];
GLuint  Buffers[NumBuffers];

const GLuint NumVertices = 36*3;

void init(void) {
    glGenVertexArrays(NumVAOs, VAOs);
    glBindVertexArray(VAOs[Triangles]);


    GLfloat  vertices[NumVertices] = {
      -1.0f,-1.0f,-1.0f, // triangle 1 : début
      -1.0f,-1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f, // triangle 1 : fin
      1.0f, 1.0f,-1.0f, // triangle 2 : début
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f,-1.0f, // triangle 2 : fin
      1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f,-1.0f,
      1.0f,-1.0f,-1.0f,
      1.0f, 1.0f,-1.0f,
      1.0f,-1.0f,-1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f,-1.0f,
      1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
      -1.0f,-1.0f, 1.0f,
      1.0f,-1.0f, 1.0f,
      1.0f, 1.0f, 1.0f,
      1.0f,-1.0f,-1.0f,
      1.0f, 1.0f,-1.0f,
      1.0f,-1.0f,-1.0f,
      1.0f, 1.0f, 1.0f,
      1.0f,-1.0f, 1.0f,
      1.0f, 1.0f, 1.0f,
      1.0f, 1.0f,-1.0f,
      -1.0f, 1.0f,-1.0f,
      1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
      1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f,
      1.0f,-1.0f, 1.0f
    };

    glGenBuffers(NumBuffers, Buffers);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
    glBufferStorage(GL_ARRAY_BUFFER, sizeof(vertices), vertices, 0);

    glVertexAttribPointer(vPosition, 2, GL_FLOAT,
        GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
}


SDL_GLContext glContext;
SDL_Event sdlEvent;
SDL_Window* pWindow = NULL;
bool quit = false;

void destroy(void) {
  if (pWindow != NULL) SDL_DestroyWindow(pWindow);
  SDL_Quit();
}

int main(int argc, char** argv) {
  Vector3 vector1 = Vector3();
  Vector3 vector2 = Vector3(5, 2, 3);
  Vector3 a = vector2 * 5;
  cout << a.getX() << endl;
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                      SDL_GL_CONTEXT_PROFILE_CORE);

  // SDL Initialisation
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {  // more init flags audio, timer, ...
    fprintf(stderr, "SDL Initialisation Failure (%s)\n", SDL_GetError());
    return -1;
  }

  // Create window
  pWindow = SDL_CreateWindow("Minecrack",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              640, 480,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  if (pWindow == NULL) {
    fprintf(stderr, "Could not create window (%s)\n", SDL_GetError());
    return -1;
  }

  // Create OpenGL context
  glContext = SDL_GL_CreateContext(pWindow);
  if (glContext == NULL) {
    fprintf(stderr, "Could not create OpenGL context (%s)\n", SDL_GetError());
    destroy();
    return -1;
  }

  // Create GLEW context
  GLenum err = glewInit();
  if (GLEW_OK != err) {
    fprintf(stderr, "Could not create GLEW context (%s)\n",
                    glewGetErrorString(err));
    destroy();
    return -1;
  }

  init();
  while (!quit) {
      while (SDL_PollEvent(&sdlEvent) != 0) {
          if (sdlEvent.type == SDL_QUIT) {
              quit = true;
          }
      }

      glClearColor(0.39f, 0.58f, 0.93f, 1.f);

      glBindVertexArray(VAOs[Triangles]);
      glDrawArrays(GL_TRIANGLES, 0, NumVertices);

      SDL_GL_SwapWindow(pWindow);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }
  destroy();
  return 0;
}
