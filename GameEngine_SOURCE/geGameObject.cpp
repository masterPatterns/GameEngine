#include "geGameObject.h"

namespace ge
{
	GameObject::GameObject()
		: mX(0.0f)
		, mY(0.0f)
		, mX2(0.0f)
		, mY2(0.0f)
		, mGubun(0)
	{
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Initialize(int gubun)
	{
		mGubun = gubun;
	}

	void GameObject::Update()
	{
		if(mGubun == 1)
		{
			if (Input::GetKey(eKeyCode::Left))
			{
				mX -= 0.01f;
			}

			if (Input::GetKey(eKeyCode::Right))
			{
				mX += 0.01f;
			}

			if (Input::GetKey(eKeyCode::Up))
			{
				mY -= 0.01f;
			}

			if (Input::GetKey(eKeyCode::Down))
			{
				mY += 0.01f;
			}
		}
		
		if (mGubun == 2)
		{
			if (Input::GetKey(eKeyCode::A))
			{
				mX2 -= 0.01f;
			}

			if (Input::GetKey(eKeyCode::D))
			{
				mX2 += 0.01f;
			}

			if (Input::GetKey(eKeyCode::W))
			{
				mY2 -= 0.01f;
			}

			if (Input::GetKey(eKeyCode::S) )
			{
				mY2 += 0.01f;
			}
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
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

			Ellipse(hdc, 2000 + mX2, 700 + mY2, 2100 + mX2, 800 + mY2);

			SelectObject(hdc, oldBrush2);
			DeleteObject(redBrush);
			DeleteObject(bluePen);
		}
	}

}