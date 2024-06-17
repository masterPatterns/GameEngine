#include "geComponent.h"

namespace ge
{
	Component::Component()
		: lSize(0.0f)
		, rSize(0.0f)
	{
		setLSize(100.0f);
		setRSize(100.0f);
	}
	Component::~Component()
	{
	
	}

	void Component::Initialize(float mLSize, float mRSize)
	{
		setLSize(mLSize);
		setRSize(mRSize);
	}
	void Component::Update()
	{
		/*const int speed = 200.0f;

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
		}*/

	}
	void Component::LateUpdate()
	{

	}
	void Component::Render(HDC hdc)
	{

	}


}