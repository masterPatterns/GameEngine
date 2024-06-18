#pragma once
#include "..\\GameEngine_SOURCE\\geSceneManager.h"
#include "gePlayScene.h"

//#ifdef _DEBUG
//#pragma comment(lib, "..\\x64\\Debug\\GameEngine_Window.lib")
//#else
//#pragma comment(lib, "..\\x64\\Release\\GameEngine_Window.lib")
//#endif


namespace ge
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}