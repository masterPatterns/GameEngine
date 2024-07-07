#pragma once
#include "..\\GameEngine_SOURCE\\geResources.h"
#include "..\\GameEngine_SOURCE\\geTexture.h"

namespace ge
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"TITLE", L"..\\Resources\\title.bmp");
		Resources::Load<graphcis::Texture>(L"BG", L"..\\Resources\\CloudOcean.png");
		Resources::Load<graphcis::Texture>(L"END", L"..\\Resources\\event.bmp");

		Resources::Load<graphcis::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
	}
}
