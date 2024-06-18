#pragma once
#include "geEntity.h"
#include "geComponent.h"
#include "geInput.h"
#include "geTime.h"

namespace ge
{
	class Transform : public Component
	{
	public:
		Transform();
		virtual ~Transform();

		void Initialize(float mLSize, float mRSize) override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		Vector2 GetPosition() { return mPosition; }

	private:
		Vector2 mPosition;
	};
}
