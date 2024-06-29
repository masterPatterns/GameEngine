#pragma once
#include "geScene.h"

namespace ge
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name, int isActiveScene)
		{
			T* scene = new T();
			scene->SetName(name);
			if(isActiveScene == 1)
				mActiveScene = scene;

			mInitScene = scene;
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; }
		static Scene* GetWorkScene() { return mInitScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);


	private:
		//static std::vector<Scene*> mScene;
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
		static Scene* mInitScene;

	};
}
