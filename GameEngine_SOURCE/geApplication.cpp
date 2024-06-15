#include "geApplication.h"

namespace ge
{
	Application::Application() 
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{
		
	}
	Application::~Application() 
	{
	
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height, int nCmdShow)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, nCmdShow);

		// 윈도우 해상도에 맞는 백버퍼생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.Initialize();
		mPlayer2.Initialize(2);

		mPlayer.SetPosition(0.0f, 0.0f);
		mPlayer2.SetPosition(0.0f, 0.0f, 0.0f, 0.0f);

		Input::Initailize();
		Time::Initailize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
		mPlayer2.Update();
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);
		mPlayer2.Render(mBackHdc);

		BitBlt(mHdc, 0, 0, mWidth, mHight, mBackHdc, 0, 0, SRCCOPY);
	}
}