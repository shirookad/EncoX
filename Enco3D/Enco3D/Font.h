#ifndef _ENCO3D_FONT_H_
#define _ENCO3D_FONT_H_

#include "Texture2D.h"
#include "DebugLogger.h"

#include <string>
#include <fstream>
#include <iostream>

namespace Enco3D
{
	namespace Rendering
	{
		typedef struct __CharacterData
		{
			float startU, startV, endU, endV;
			int offsX, offsY;
			unsigned int advanceX, width, height;
		} CharacterData;

		enum FontType : unsigned char
		{
			Default,
			Italic,
			Bold,
			BoldAndItalic,
		};

		class Font
		{
		private:
			Texture2D *m_texture{ nullptr };
			CharacterData *m_characterData{ nullptr };
			unsigned int m_fontSize{ 0 };

		public:
			Font();
			Font(const std::string &name, const FontType &type);
			~Font();

			inline Texture2D *GetTexture() const { return m_texture; }
			inline CharacterData GetCharacterData(unsigned int index) { return m_characterData[index]; }
			inline unsigned int GetFontSize() const { return m_fontSize; }
		};
	}
}

#endif