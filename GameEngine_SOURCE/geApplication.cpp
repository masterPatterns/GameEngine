#include "geApplication.h"

namespace ge
{
	Application::Application() 
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
	{
		
	}
	Application::~Application() 
	{
	
	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		mPlayer.Initialize(1);
		mPlayer2.Initialize(2);

		mPlayer.SetPosition(0, 0);
		mPlayer2.SetPosition(0, 0);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		mSpeed += 0.01f;

		mPlayer.Update();
		mPlayer2.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
		mPlayer2.Render(mHdc);
	}
}