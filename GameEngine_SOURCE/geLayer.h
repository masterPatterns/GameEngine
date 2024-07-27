#pragma once
#include "geEntity.h"
#include "CommonInclude.h"
#include "geGameObject.h"

namespace ge
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObjedt);

	private:
		enums::eLayerType mType;
		std::vector<GameObject*> mGemeObjects;
	};

	typedef std::vector<GameObject*>::iterator GemeObjectIter;
}
