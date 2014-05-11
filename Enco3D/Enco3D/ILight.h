#ifndef _ENCO3D_ILIGHT_H_
#define _ENCO3D_ILIGHT_H_

#include "Vector3.h"
#include "Shader.h"
#include "Matrix4x4.h"
#include "IGameComponent.h"

namespace Enco3D
{
	namespace Component
	{
		class ILight : public Core::IGameComponent
		{
		protected:
			Core::Vector3f m_color;
			float m_intensity{ 0 };
			Rendering::Shader *m_shader{ nullptr };

		public:
			void InitRendering() { GetRenderingEngine()->AddLight(this); }
			void Deinit() { GetRenderingEngine()->RemoveLight(this); }

			virtual void SetUpShader() {  }

			inline void SetColor(const Core::Vector3f &color) { m_color.Set(color); }
			inline void SetIntensity(float intensity) { m_intensity = intensity; }

			inline Core::Vector3f GetColor() const { return m_color; }
			inline float GetIntensity() const { return m_intensity; }
			inline Rendering::Shader *GetShader() const { return m_shader; }
		};
	}
}

#endif