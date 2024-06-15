#pragma once
#include "CommonInclude.h"
#include "geInput.h"
#include "geTime.h"

namespace ge
{
	class GameObject2
	{
	public:
		GameObject2();
		~GameObject2();

		void Initialize(int gubun);

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y, float x2, float y2)
		{
			mX = x;
			mY = y;

			mX2 = x2;
			mY2 = y2;
		}
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }

		float GetPositionX2() { return mX2; }
		float GetPositionY2() { return mY2; }

	private:
		float mX;
		float mY;

		float mX2;
		float mY2;

		int mGubun;
	};
}
