#pragma once
#include "geEntity.h"
#include "geGameObject.h"

namespace ge
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObjedt);

	private:
		std::vector<GameObject*> mGemeObjects;
	};
}

