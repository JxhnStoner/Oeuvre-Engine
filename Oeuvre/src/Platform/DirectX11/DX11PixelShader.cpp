#include "DX11PixelShader.h"

#include <string>
#include <iostream>
#include <d3dcompiler.h>

#include "Platform/DirectX11/DX11RendererAPI.h"

namespace Oeuvre
{
	DX11PixelShader::DX11PixelShader(const char* filePath)
	{
		if (!Create(filePath))
			std::cout << "ERROR::Can't create DX11PixelShader!\n";
	}
	DX11PixelShader::~DX11PixelShader()
	{
		if (m_pixelShader) m_pixelShader->Release();
	}
	bool DX11PixelShader::Create(const char* path)
	{
		std::string pathStr{ path };
		std::wstring wPath{ pathStr.begin(), pathStr.end() };
		//ID3DBlob* blobOut = nullptr;
		blobOut = nullptr;
		ID3DBlob* blobErr = nullptr;
		HRESULT hr = S_OK;
		hr = D3DCompileFromFile(wPath.c_str(), 0, D3D_COMPILE_STANDARD_FILE_INCLUDE, "PSMain", "ps_5_0",
			D3DCOMPILE_ENABLE_STRICTNESS, 0, &blobOut, &blobErr);
		if (FAILED(hr))
		{
			if (blobErr != nullptr)
			{
				OutputDebugStringA((char*)blobErr->GetBufferPointer());
				blobErr->Release();
			}
			return false;
		}

		auto device = static_cast<DX11RendererAPI*>(RendererAPI::GetInstance().get())->GetDevice();
		hr = device->CreatePixelShader(blobOut->GetBufferPointer(),
			blobOut->GetBufferSize(), 0, &m_pixelShader);
		if (FAILED(hr))
		{
			blobOut->Release();
			return false;
		}

		return true;
	}

	void DX11PixelShader::Bind()
	{
		auto deviceContext = static_cast<DX11RendererAPI*>(RendererAPI::GetInstance().get())->GetDeviceContext();
		deviceContext->PSSetShader(m_pixelShader, 0, 0);
	}

	void DX11PixelShader::Unbind()
	{
		auto deviceContext = static_cast<DX11RendererAPI*>(RendererAPI::GetInstance().get())->GetDeviceContext();
		deviceContext->PSSetShader(nullptr, 0, 0);
	}
}


