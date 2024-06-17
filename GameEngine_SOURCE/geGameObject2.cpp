#include "geGameObject2.h"

namespace ge
{
	GameObject2::GameObject2()
		: mX(0.0f)
		, mY(0.0f)
		, mX2(0.0f)
		, mY2(0.0f)
		, mGubun(0)
	{
	}
	GameObject2::~GameObject2()
	{
	}

	void GameObject2::Initialize(int gubun)
	{
		mGubun = gubun;
	}

	void GameObject2::Update()
	{
		const float speed = 150.0f;
		if (mGubun == 1)
		{
			if (Input::GetKey(eKeyCode::Left))
			{
				mX -= speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::Right))
			{
				mX += speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::Up))
			{
				mY -= speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::Down))
			{
				mY += speed * Time::DeltaTime();
			}
		}

		if (mGubun == 2)
		{
			if (Input::GetKey(eKeyCode::A))
			{
				mX2 -= speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::D))
			{
				mX2 += speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::W))
			{
				mY2 -= speed * Time::DeltaTime();
			}

			if (Input::GetKey(eKeyCode::S))
			{
				mY2 += speed * Time::DeltaTime();
			}
		}
	}
	void GameObject2::LateUpdate()
	{
	}
	void GameObject2::Render(HDC hdc)
	{
		if (mGubun == 1)
		{
			HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

			HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
			HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
			SelectObject(hdc, oldPen);

			Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

			SelectObject(hdc, oldBrush);
			DeleteObject(blueBrush);
			DeleteObject(redPen);
		}

		if (mGubun == 2)
		{
			HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
			HBRUSH oldBrush2 = (HBRUSH)SelectObject(hdc, redBrush);

			HPEN bluePen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
			HPEN oldPen2 = (HPEN)SelectObject(hdc, bluePen);
			SelectObject(hdc, oldPen2);

			Ellipse(hdc, 1400 + mX2, 650 + mY2, 1500 + mX2, 750 + mY2);

			SelectObject(hdc, oldBrush2);
			DeleteObject(redBrush);
			DeleteObject(bluePen);
		}
	}

}