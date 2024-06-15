#pragma once
#include "CommonInclude.h"
#include "geInput.h"
#include "geTime.h"

namespace ge
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Initialize();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

	private:
		float mX;
		float mY;
	};
}
