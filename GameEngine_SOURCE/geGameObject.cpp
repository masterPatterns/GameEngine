#include "geGameObject.h"

namespace ge
{
	GameObject::GameObject()
		: mX(0.0f)
		, mY(0.0f)
		, left(0.0f)
		, top(0.0f)
		, right(0.0f)
		, bottom(0.0f)
	{
	}
	GameObject::~GameObject()
	{
	}

	void GameObject::Initialize()
	{
		left = 100;
		top = 100;
		right = 200;
		bottom = 200;
		for (size_t i = 0; i < 100; i++)
		{
			mMissile[i].Initialize(20);
			mMissile[i].SetPosition(left, top);
			isShoot[i] = 0;
		}
	}

	void GameObject::Update()
	{
		const int speed = 200.0f;

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

		if (isShoot[0] == 0) {
			mMissile[0].SetPosition(left + mX, top + mY);
		}
		else {
			mMissile[0].Update();
		}

		if (Input::GetKey(eKeyCode::Space))
		{
			isShoot[0] = 1;
		}
	}
	void GameObject::LateUpdate()
	{
	}
	void GameObject::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, left + mX, top + mY, right + mX, bottom + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);

		if (isShoot[0] == 1) {
			mMissile[0].Render(hdc);
		}
	}

}