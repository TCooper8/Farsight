#pragma once

#include "../FarSystem.h"
#include "Vertex.h"

namespace Farsight
{
	class VertexBuffer
	{
		uint id;

	public:
		VertexBuffer();
		VertexBuffer(const Vertex* vertices, const uint count, const uint primitiveType);
		VertexBuffer(const VertexBuffer &buffer);

		uint GetId() const;

		template<typename T>
		void SetData(const T* data, const uint count, const uint primitiveType);
		void SetId(const uint id);
	};
};