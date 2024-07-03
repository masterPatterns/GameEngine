#pragma once
#include "geEntity.h"

namespace ge
{
	class GameObject;
	class Component : public Entity
	{
	public:
		Component(enums::eComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		GameObject* GetOwner() const { return mOwner; }
		void SetOwner(GameObject* owner) { mOwner = owner; }
		enums::eComponentType GetType() { return mType; }

	private:
		GameObject* mOwner;
		enums::eComponentType mType;
	};
}
