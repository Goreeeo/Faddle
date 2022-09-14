#pragma once

#include "Faddle/Input.h"

namespace Faddle {
	class Win64Input : public Input {
	protected:
		virtual bool IsKeyPressedImpl(int keycode);
		virtual bool IsMouseButtonPressedImpl(int button);
		virtual float GetMouseXImpl();
		virtual float GetMouseYImpl();
	};
}