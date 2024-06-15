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
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height, int nCmdShow);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;


		UINT mWidth;
		UINT mHight;

		std::vector<GameObject*> mGameObjects;

		/*GameObject mPlayer;
		GameObject2 mPlayer2;*/
	};
}
