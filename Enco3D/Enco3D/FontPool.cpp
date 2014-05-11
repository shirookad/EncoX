#include "FontPool.h"

Enco3D::Rendering::Font *Enco3D::Rendering::FontPool::LoadFont(const std::string &filename, const FontType &type)
{
	return new Font(filename, type);
}

Enco3D::Rendering::Font *Enco3D::Rendering::FontPool::GetFont(const std::string &filename, const FontType &type)
{
	if (m_loadedFonts.find(filename) != m_loadedFonts.end())
		return m_loadedFonts[filename];

	Font *result = LoadFont(filename, type);
	m_loadedFonts.insert(std::pair<std::string, Font *>(filename, result));

	return result;
}

void Enco3D::Rendering::FontPool::Release()
{
	for (std::map<std::string, Font*>::iterator it = m_loadedFonts.begin(); it != m_loadedFonts.end(); it++)
		delete it->second;
}