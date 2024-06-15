#pragma once
#include "CommonInclude.h"
#include "geGameObject.h"
#include "geGameObject2.h"
#include "geInput.h"
#include "geTime.h"

namespace ge
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height, int nCmdShow);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;


		UINT mWidth;
		UINT mHight;

		GameObject mPlayer;
		GameObject2 mPlayer2;
	};
}
