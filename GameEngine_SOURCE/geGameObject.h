#pragma once
#include "CommonInclude.h"

namespace ge
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Initialize(int gubun);

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

		float mX2;
		float mY2;

		int mGubun;
	};
}
