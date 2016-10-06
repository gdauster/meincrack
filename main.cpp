/* Copyright (c) 2016 Minecrack */
#define GLEW_STATIC
#define GL_GLEXT_PROTOTYPES
#define BUFFER_OFFSET(a) (reinterpret_cast<void*>(a))

#include "main.h"

#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdio.h>
#include <iostream>

using namespace std;
#include "Geometry.h"
#include "Scene.h"

SDL_GLContext glContext;
SDL_Event sdlEvent;
SDL_Window* pWindow = NULL;
bool quit = false;

void destroy(void) {
  if (pWindow != NULL) SDL_DestroyWindow(pWindow);
  SDL_Quit();
}

int main(int argc, char** argv) {
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

  Scene s = Scene();
  while (!quit) {
      while (SDL_PollEvent(&sdlEvent) != 0) {
          if (sdlEvent.type == SDL_QUIT) {
              quit = true;
          }
      }

	  s.DrawAll();

      SDL_GL_SwapWindow(pWindow);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }
  destroy();
  return 0;
}
