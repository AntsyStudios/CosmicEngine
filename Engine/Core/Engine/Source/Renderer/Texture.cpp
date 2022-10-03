module;
#include "cspch.hpp"
module Cosmic.Renderer.Texture;

import Cosmic.Impl.RendererAPI.OpenGL.OpenGLTexture;
import Cosmic.Renderer.RendererAPI;

namespace Cosmic
{

    Texture2D::Texture2D(const String& filePath, ETextureWrapMode wrapMode, ETextureScalingFilter min, ETextureScalingFilter mag)
        : mFilePath(filePath)
    {
        CS_PROFILE_FN();
    }

    Texture2D::Texture2D(uint32 width, uint32 height, ETextureWrapMode wrapMode, ETextureScalingFilter min, ETextureScalingFilter mag)
        : mWidth(width), mHeight(height)
    {
        CS_PROFILE_FN();
    }

    Ref<Texture2D> CreateTexture2D(const String& filePath, ETextureWrapMode wrapMode, ETextureScalingFilter min, ETextureScalingFilter mag)
    {
        CS_PROFILE_FN();

        switch (RendererAPI::Get())
        {
            case ERendererAPI::OpenGL: return CreateRef<OpenGLTexture2D>(filePath, wrapMode, min, mag);
        }
    }

    Ref<Texture2D> CreateTexture2D(uint32 width, uint32 height, ETextureWrapMode wrapMode, ETextureScalingFilter min, ETextureScalingFilter mag)
    {
        CS_PROFILE_FN();

        switch (RendererAPI::Get())
        {
            case ERendererAPI::OpenGL: return CreateRef<OpenGLTexture2D>(width, height, wrapMode, min, mag);
        }
    }

}
