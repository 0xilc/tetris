#include "rendering/UBOManager.h"

UBOManager::UBOManager()
{
}

UBOManager::~UBOManager()
{
    for (auto& ubo : m_Cache) {
        glDeleteBuffers(1, &ubo.second.first);
    }
}

void UBOManager::CreateUBO(const std::string& name, GLuint bindingPoint, GLsizeiptr size)
{
    GLuint uboID;
    glGenBuffers(1, &uboID);
    glBindBuffer(GL_UNIFORM_BUFFER, uboID);
    glBufferData(GL_UNIFORM_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    glBindBufferBase(GL_UNIFORM_BUFFER, bindingPoint, uboID);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
    
    m_Cache[name] = std::make_pair(uboID, bindingPoint);
}

void UBOManager::UpdateUBO(const std::string& name, GLsizeiptr offset, GLsizeiptr size, const void* data)
{
    auto it = m_Cache.find(name);
    if (it != m_Cache.end())
    {
        glBindBuffer(GL_UNIFORM_BUFFER, it->second.first);
        glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
        glBindBuffer(GL_UNIFORM_BUFFER, 0);
    }
}

void UBOManager::BindUBO(const std::string& name)
{
    auto it = m_Cache.find(name);
    if (it != m_Cache.end())
    {
        glBindBufferBase(GL_UNIFORM_BUFFER, it->second.second, it->second.first);
    }
}

GLuint UBOManager::GetUBO(const std::string& name)
{
    auto it = m_Cache.find(name);
    if (it != m_Cache.end()) 
    {
        return it->second.first;
    }
    return 0;
}
