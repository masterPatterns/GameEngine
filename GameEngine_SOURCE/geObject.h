#pragma once
#include "geComponent.h"
#include "geGameObject.h"
#include "geLayer.h"
#include "geScene.h"
#include "geSceneManager.h"

namespace ge::object
{
	template <typename T>
	static T* Instantiate(ge::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(ge::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPos(position);

		return gameObject;
	}
}