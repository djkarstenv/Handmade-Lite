#pragma once

/*===================================================================#
| 'Text' source files last updated on 31 May 2021                    |
#===================================================================*/

#include <map>
#include <memory>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

//TODO - Add proper error messages
//TODO - Make sure asserts are disabled in Release mode

typedef std::map<std::string, TTF_Font*> FontMap;

class Text
{

public:

	enum class FontSize
	{
		SMALL = 72,
		MEDIUM = 144,
		LARGE = 300
	};

	static bool Initialize();
	static bool Load(const std::string& filename,
		const std::string& mapIndex,
		FontSize fontSize = FontSize::SMALL);
	static void Unload(const std::string& mapIndex = "");
	static void Shutdown();

	Text();
	Text(const Text& copy);
	~Text();

	const SDL_Point& GetSize() const;
	const std::string& GetText() const;

	void SetSize(int width, int height);
	void SetText(const std::string& text);
	void SetColor(Uint8 r, Uint8 g, Uint8 b);
	bool SetFont(const std::string& mapIndex);

	void Render(int positionX = 0, int positionY = 0);

private:

	void CreateText();

	std::string m_text;
	SDL_Point m_textSize;

	TTF_Font* m_font;
	SDL_Color m_color;
	SDL_Texture* m_texture;

	static std::unique_ptr<FontMap> s_fonts;

};