#include "rendering/TextureLoader.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

TextureLoader::TextureLoader()
{
}

GLuint TextureLoader::LoadTexture(const std::string& path)
{
	auto it = m_Cache.find(path);
	if (it != m_Cache.end()) {
		return it->second;
	}
	
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (data) {
        GLenum format = GL_RGB;
        if (nrChannels == 1)
            format = GL_RED;
        else if (nrChannels == 3)
            format = GL_RGB;
        else if (nrChannels == 4)
            format = GL_RGBA;

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cerr << "Failed to load texture" << std::endl;
    }

    // Step 5: Free the image memory and unbind the texture
    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);

    return textureID;
}

GLuint TextureLoader::GetTexture(const std::string& path) const
{
    auto it = m_Cache.find(path);
    if (it != m_Cache.end()) {
        return it->second;
    }
    return 0;
}

void TextureLoader::DeleteTexture(const std::string& path)
{
    auto it = m_Cache.find(path);
    if (it != m_Cache.end()) 
    {
        GLuint textureID = it->second;
        glDeleteTextures(1, &textureID);
        m_Cache.erase(it);
    }
    else 
    {
        std::cerr << "Texture not found in cache: " << path << std::endl;
    }
}
