#pragma once
#include "CommonInclude.h"
#include "geInput.h"
#include "geTime.h"
#include "geMissile.h"
#include "geComponent.h"
#include "geTransform.h"
#include "geSpriteRenderer.h"

namespace ge
{
	class GameObject : public Entity
	{
	public:
		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;
			// mComponents.push_back(comp); 

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}

		eState GetActive() { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}

		void Death() { mState = eState::Dead; }

	private:
		void initializeTransform();
		

	private:
		eState mState;
		std::vector<Component*> mComponents;
	};
}
