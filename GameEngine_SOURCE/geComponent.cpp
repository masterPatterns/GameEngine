#include "geComponent.h"

namespace ge
{
	Component::Component(enums::eComponentType type)
		:mType(type)
	{
	}
	Component::~Component()
	{
	
	}

	void Component::Initialize()
	{

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