/* Copyright (c) 2016 Meincrack */
#ifndef _MAIN_H_
#define _MAIN_H_

#define BUFFER_OFFSET(a) (reinterpret_cast<void*>(a))

#include <GL/glew.h>

#ifdef __linux__
#elif _WIN32
#include <GL/wglew.h>
#include <Windows.h>
#endif


#endif