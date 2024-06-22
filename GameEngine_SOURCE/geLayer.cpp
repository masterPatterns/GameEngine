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

	void Layer::AddGameObject(GameObject* gameObjedt)
	{
		if (gameObjedt == nullptr)
			return;

		mGemeObjects.push_back(gameObjedt);
	}
}