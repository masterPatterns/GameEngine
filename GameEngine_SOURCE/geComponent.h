#pragma once
#include "geEntity.h"

namespace ge
{
	class GameObject;

	class Component : public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize(float mLSize, float mRSize);
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		GameObject* GetOwner() const { return mOwner; }
		void SetOwner(GameObject* owner) { mOwner = owner; }

		void setLSize(float mLSize) { lSize = mLSize; }
		void setRSize(float mRSize) { rSize = mRSize; }
		float getLSize() { return lSize; }
		float getRSize() { return rSize; }

	private:
		float lSize;
		float rSize;
		GameObject* mOwner;
	};
}
