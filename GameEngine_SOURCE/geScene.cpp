#include "geScene.h"

namespace ge
{
	Scene::Scene()
		: mGemeObjects{}
	{
	}
	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (GameObject* gameObj : mGemeObjects)
		{
			gameObj->Initialize();
		}
	}

	void Scene::Update()
	{
		//for (size_t i = 0; i < mGemeObjects.size(); i++)
		//{
		//	mGemeObjects[i]->Update();
		//}

		// 범위 기반 for문
		for (GameObject* gameObj : mGemeObjects)
		{
			gameObj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGemeObjects)
		{
			gameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGemeObjects)
		{
			gameObj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObjedt)
	{
		mGemeObjects.push_back(gameObjedt);
	}
}