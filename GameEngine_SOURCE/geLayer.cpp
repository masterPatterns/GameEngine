#include "geLayer.h"

namespace ge
{
	Layer::Layer()
		: mType(enums::eLayerType::None)
		, mGemeObjects{}
	{

	}
	Layer::~Layer()
	{
		for (GameObject* gameObj : mGemeObjects)
		{
			if (gameObj == nullptr)
				continue;

			delete gameObj;
			gameObj = nullptr;
		}
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : mGemeObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObj : mGemeObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : mGemeObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGemeObjects)
		{
			if (gameObj == nullptr)
				continue;

			gameObj->Render(hdc);
		}
	}

	void Layer::Destroy()
	{
		for (GemeObjectIter iter = mGemeObjects.begin()
			; iter != mGemeObjects.end()
			; )
		{
			GameObject::eState active = (*iter)->GetActive();
			if (active == GameObject::eState::Dead)
			{
				GameObject* deathObj = (*iter);

				iter = mGemeObjects.erase(iter);

				delete deathObj;
				deathObj = nullptr;

				continue;
			}

			iter++;
		}
	}

	void Layer::AddGameObject(GameObject* gameObjedt)
	{
		if (gameObjedt == nullptr)
			return;

		mGemeObjects.push_back(gameObjedt);
	}
}