#include "Texture2D.h"

#include <utility>

namespace CS123 { namespace GL {

Texture2D::Texture2D(unsigned char *data, int width, int height, GLenum type) :
    Texture()
{
    GLenum internalFormat = type == GL_FLOAT ? GL_RGBA32F : GL_RGBA;

    // Bind the texture by calling bind() and filling it in
    Texture2D::bind();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Generate the texture with glTexImage2D
    glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, GL_RGBA, type, data);

    // unbind
    Texture2D::unbind();
}

void Texture2D::bind() const {
    glBindTexture(GL_TEXTURE_2D, m_handle);
}

void Texture2D::unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

}}
