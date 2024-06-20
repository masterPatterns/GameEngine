#include "geTransform.h"

namespace ge
{
	Transform::Transform()
		: mPosition(0, 0)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{

	}
	void Transform::Update()
	{
		const int speed = 200.0f;

		if (Input::GetKey(eKeyCode::Left))
		{
			mPosition.x -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Right))
		{
			mPosition.x += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Up))
		{
			mPosition.y -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::Down))
		{
			mPosition.y += speed * Time::DeltaTime();
		}
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}