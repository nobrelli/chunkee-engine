#pragma once

#include "Component.hxx"


namespace Chunkee
{
	namespace GUI
	{
		enum class Alignment
		{
			LEFT, RIGHT, CENTER
		};

		class Container : public Component
		{
		public:
			Container(float spacing);
			void addChild(const String& id, Node* node) override;

		private:
			float m_spacing;
			float m_innerHeight;
		};
	}
}