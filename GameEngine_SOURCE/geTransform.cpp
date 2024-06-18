#include "geTransform.h"

namespace ge
{
	Transform::Transform()
		/*: mX(0)
		, mY(0)*/
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize(float mLSize, float mRSize)
	{
		setLSize(mLSize);
		setRSize(mRSize);
	}
	void Transform::Update()
	{
		//const int speed = 200.0f;

		/*if (Input::GetKey(eKeyCode::Left))
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
		}*/
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}