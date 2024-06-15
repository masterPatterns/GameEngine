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
		adjustWindowRect(hwnd, width, height, nCmdShow);
		createBuffer(width, height);
		initializeEtc();
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

		for (size_t i = 0; i < 100; i++)
		{
			mGameObjects[i]->Update();
		}
		/*mPlayer.Update();
		mPlayer2.Update();*/
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		clearRenderTarget();

		for (size_t i = 0; i < 100; i++)
		{
			mGameObjects[i]->Render(mBackHdc);
		}
		/*mPlayer.Render(mBackHdc);
		mPlayer2.Render(mBackHdc);*/

		Time::Render(mBackHdc);

		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHight, source, 0, 0, SRCCOPY);
	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height, int nCmdShow)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);
		ShowWindow(mHwnd, nCmdShow);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 백버퍼생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}
	
	void Application::initializeEtc()
	{
		for (size_t i = 0; i < 100; i++)
		{
			GameObject* gameObj = new GameObject();
			gameObj->Initialize();
			gameObj->SetPosition(rand() % 1600, rand() % 900);
			mGameObjects.push_back(gameObj);
		}

		/*mPlayer.Initialize();
		mPlayer2.Initialize(2);*/

		/*mPlayer.SetPosition(0.0f, 0.0f);
		mPlayer2.SetPosition(0.0f, 0.0f, 0.0f, 0.0f);*/

		Input::Initailize();
		Time::Initailize();
	}
	
}