#pragma once
#include "CommonInclude.h"
#include "geGameObject.h"
#include "geInput.h"

namespace ge
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;

		GameObject mPlayer;
		GameObject mPlayer2;
	};
}