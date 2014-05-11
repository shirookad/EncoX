#ifndef _ENCO3D_ITEXTURE_H_
#define _ENCO3D_ITEXTURE_H_

#include "ReferenceCounter.h"

#include <GL/glew.h>
#include <iostream>
#include <assert.h>
#include <string>
#include <map>

#include "stb_image.h"

namespace Enco3D
{
	namespace Rendering
	{
		enum TextureFilter : unsigned int
		{
			Nearest = GL_NEAREST,
			Linear = GL_LINEAR,
			MipmapLinear = 1,
		};

		enum TextureWrap : unsigned int
		{
			Clamp = GL_CLAMP,
			Repeat = GL_REPEAT,
			ClampToEdge = GL_CLAMP_TO_EDGE,
		};

		enum TextureSampler : unsigned int
		{
			Sampler0,
			Sampler1,
			Sampler2,
			Sampler3,
			Sampler4,
			Sampler5,
			Sampler6,
			Sampler7,
			Sampler8,
			Sampler9,
			Sampler10,
			Sampler11,
			Sampler12,
			Sampler13,
			Sampler14,
			Sampler15,
			Sampler16,
			Sampler17,
			Sampler18,
			Sampler19,
			Sampler20,
			Sampler21,
			Sampler22,
			Sampler23,
			Sampler24,
			Sampler25,
			Sampler26,
			Sampler27,
			Sampler28,
			Sampler29,
			Sampler30,
			Sampler31,
		};

		class ITexture
		{
		protected:
			GLuint m_id;
			unsigned int m_width, m_height;

		public:
			virtual ~ITexture() {  }

			virtual void Bind(unsigned int unit = 0) const = 0;
			
			inline GLuint GetID() const { return m_id; }
			inline unsigned int GetWidth() const { return m_width; }
			inline unsigned int GetHeight() const { return m_height; }
		};
	}
}

#endif