#ifndef _ENCO3D_BOXCOLLISIONSHAPE_H_
#define _ENCO3D_BOXCOLLISIONSHAPE_H_

#include "ICollisionShape.h"
#include "Vector3.h"
#include "PhysicsHelper.h"

namespace Enco3D
{
	namespace Physics
	{
		class BoxCollisionShape : public ICollisionShape
		{
		private:
			Core::Vector3f m_halfSize;

		public:
			BoxCollisionShape();
			BoxCollisionShape(const Core::Vector3f &size);

			btCollisionShape *ToBulletPhysicsCollisionShape();

			inline void SetHalfSize(const Core::Vector3f &halfSize) { m_halfSize.Set(halfSize); }
			inline void SetSize(const Core::Vector3f &size) { m_halfSize.Set(size * 0.5f); }

			inline Core::Vector3f GetHalfSize() const { return m_halfSize; }
			inline Core::Vector3f GetSize() const { return m_halfSize * 2.0f; }
		};
	}
}

#endif