#include "geMissile.h"

namespace ge
{
	Missile::Missile()
		: mX(0.0f)
		, mY(0.0f)
		, size(0.0f)
	{
	}
	Missile::~Missile()
	{
	}

	void Missile::Initialize(float mSize)
	{
		size = mSize;
	}

	void Missile::Update()
	{
		const int speed = 200.0f;

		mY -= speed * Time::DeltaTime();
	}
	void Missile::LateUpdate()
	{
	}
	void Missile::Render(HDC hdc)
	{
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush2 = (HBRUSH)SelectObject(hdc, redBrush);

		HPEN bluePen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen2 = (HPEN)SelectObject(hdc, bluePen);
		SelectObject(hdc, oldPen2);

		//Ellipse(hdc, 100, 100, 120, 120);
		Ellipse(hdc, (int)mX, (int)mY, (int)(mX + size), (int)(mY + size));

		SelectObject(hdc, oldBrush2);
		DeleteObject(redBrush);
		DeleteObject(bluePen);
	}

}