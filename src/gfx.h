/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Daniel
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef FRAMEWORK_GFX_H
#define FRAMEWORK_GFX_H

struct Texture;
struct Font;
struct VertexBuffer;
struct IndexBuffer;

typedef struct {
  unsigned short type;
  unsigned short elementCount;
  unsigned short dataType;
  unsigned short offset;
} VertexDecl;

typedef struct {
  void * data;
  unsigned int size;
} Memory;


void gfxInit(int width, int height);
void gfxShutdown();

void gfxResize(unsigned int width, unsigned int height);

Texture * gfxLoadTexture(const char * filename);

const Memory * gfxAlloc(unsigned int size);
const Memory * gfxMakeRef(const void * data, unsigned int size);

VertexBuffer * gfxCreateVertexBuffer(const Memory * mem, const VertexDecl * decl);
IndexBuffer * gfxCreateIndexBuffer(const Memory * mem);

VertexBuffer * gfxCreateDynamicVertexBuffer(const Memory * mem, const VertexDecl * decl);
IndexBuffer * gfxCreateDynamicIndexBuffer(const Memory * mem);

void gfxDestroyVertexBuffer(VertexBuffer * buffer);
void gfxDestroyIndexBuffer(IndexBuffer * buffer);

void gfxUpdateVertexBuffer(VertexBuffer * buffer, const Memory * mem);
void gfxUpdateIndexBuffer(IndexBuffer * buffer, const Memory * mem);

void gfxSetVertexBuffer(VertexBuffer * buffer);
void gxfSetIndexBuffer(IndexBuffer * buffer);

void gfxSetProjection(float fovy, float near, float far);
void gfxSetCamera(float eyeX, float eyeY, float eyeZ, float atX, float atY, float atZ);

void gfxSetTransform(const float * transform);
void gfxSetTransform(float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX = 1, float scaleY = 1, float scaleZ = 1);

void gfxSetTintColor(float r, float g, float b);

void gfxBegin(unsigned int features);
void gfxBnd();

void gfxClear(float r, float g, float b);
void gfxDraw(unsigned int count);



#ifdef FRAMEWORK_GFX_IMPLEMENTATION

struct Texture
{
  unsigned int name;
  unsigned int width;
  unsigned int height;
};

struct Font
{
};

struct VertexBuffer
{
  GLuint id;
  bool dynamic;
  const VertexDecl * decl;
};

struct IndexBuffer
{
  GLuint id;
  char dynamic;
};


void gfxInit(int width, int height)
{

}

void gfxShutdown()
{

}

void gfxResize(unsigned int width, unsigned int height)
{

}

Texture * gfxLoadTexture(const char * filename)
{
  return NULL;
}

static void dispose(const Memory * mem)
{

}

const Memory * gfxAlloc(unsigned int size)
{
  return NULL;
}

const Memory * gfxMakeRef(const void * data, unsigned int size)
{
  return NULL;
}

VertexBuffer * gfxCreateVertexBuffer(const Memory * mem, const VertexDecl * decl)
{
  VertexBuffer * buffer = malloc(sizeof(VertexBuffer));
  buffer->dynamic = 0;
  buffer->decl = decl;

  glGenBuffers(1, &buffer->id);
  glBindBuffer(GL_ARRAY_BUFFER, buffer->id);
  glBufferData(GL_ARRAY_BUFFER, mem->size, mem->data, GL_STATIC_DRAW);

  dispose(mem);
  return buffer;
}

IndexBuffer * gfxCreateIndexBuffer(const Memory * mem)
{
  return NULL;
}

VertexBuffer * gfxCreateDynamicVertexBuffer(const Memory * mem, const VertexDecl * decl)
{
  return NULL;
}

IndexBuffer * gfxCreateDynamicIndexBuffer(const Memory * mem)
{
  return NULL;
}

void gfxDestroyVertexBuffer(VertexBuffer * buffer)
{

}

void gfxDestroyIndexBuffer(IndexBuffer * buffer)
{

}

void gfxUpdateVertexBuffer(VertexBuffer * buffer, const Memory * mem)
{

}

void gfxUpdateIndexBuffer(IndexBuffer * buffer, const Memory * mem)
{

}

void gfxSetVertexBuffer(VertexBuffer * buffer)
{

}

void gxfSetIndexBuffer(IndexBuffer * buffer)
{

}

void gfxSetProjection(float fovy, float near, float far)
{

}

void gfxSetCamera(float eyeX, float eyeY, float eyeZ, float atX, float atY, float atZ)
{

}

void gfxSetTransform(const float * transform)
{

}

void gfxSetTransform(float x, float y, float z, float rotX, float rotY, float rotZ, float scaleX = 1, float scaleY = 1, float scaleZ = 1)
{

}

void gfxSetTintColor(float r, float g, float b)
{

}

void gfxBegin(unsigned int features)
{

}

void gfxBnd()
{

}

void gfxClear(float r, float g, float b)
{

}

void gfxDraw(unsigned int count)
{

}


#endif
#endif