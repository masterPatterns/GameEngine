#pragma once
#include "geEntity.h"
#include "geComponent.h"

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

		void SetPos(int x, int y) { mX = x; mY = y; }
		int GetX() { return mX; }
		int GetY() { return mY; }

	private:
		int mX;
		int mY;
	};
}
