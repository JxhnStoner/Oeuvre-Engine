#pragma once

#include <glm/glm.hpp>
#include <memory>

#include "Oeuvre/Renderer/VertexArray.h"

namespace Oeuvre
{
	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0, DirectX11 = 1
		};
	public:
		virtual ~RendererAPI() = default;

		virtual void Init() = 0;
		virtual void Shutdown() = 0;
		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		virtual void SetClearColor(const glm::vec4& color) = 0;
		virtual void Clear() = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, uint32_t indexCount) = 0;
		virtual void DrawLines(const std::shared_ptr<VertexArray>& vertexArray, uint32_t vertexCount) = 0;

		virtual void SetLineWidth(float width) = 0;

		virtual void OnWindowResize(int width, int height) = 0;

		static API GetAPI() { return s_API; }
		static std::shared_ptr<RendererAPI> GetInstance();

	private:
		static API s_API;
		static std::shared_ptr<RendererAPI> s_RendererAPI;
	};
}

