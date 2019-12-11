#include "Iori.h"

HRESULT Iori::Create(ID3D11Device* pd3dDevice, ID3D11DeviceContext* Context)
{
	HRESULT hr = S_OK;

	m_pd3dDevice = pd3dDevice;
	m_pContext = Context;
	m_StateList.resize(STATE_COUNT);
	for (int i = 0; i < m_StateList.size(); i++)
	{
		m_StateList[i]=std::make_shared<CSprite>();
		m_StateList[i]->Create(m_pd3dDevice, m_pContext, L"../../data/shader/ColorBlend.txt", nullptr, "VSmat", "PSBlend");
		TextSrc(i);
		m_StateList[i]->SetTextureArray(m_str);
	}

	return hr;
}

void Iori::TextSrc(int i)
{
	m_str.clear();
	int index = 0;
	switch (i)
	{
	case 0:
		m_str.resize(8);
		m_str[index++] = L"../../data/bitmap/iori/stand/Iori Yagami_0.png";
		m_str[index++] = L"../../data/bitmap/iori/stand/Iori Yagami_1.png";
		m_str[index++] = L"../../data/bitmap/iori/stand/Iori Yagami_2.png";
		m_str[index++] = L"../../data/bitmap/iori/stand/Iori Yagami_3.png";
		m_str[index++] = L"../../data/bitmap/iori/stand/Iori Yagami_4.png";
		m_str[index++] = L"../../data/bitmap/iori/stand/Iori Yagami_5.png";
		m_str[index++] = L"../../data/bitmap/iori/stand/Iori Yagami_6.png";
		m_str[index++] = L"../../data/bitmap/iori/stand/Iori Yagami_7.png";
		break;

	case 1:
		m_str.resize(8);
		m_str[index++] = L"../../data/bitmap/iori/MoveLeft/Iori Yagami_8.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveLeft/Iori Yagami_9.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveLeft/Iori Yagami_10.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveLeft/Iori Yagami_11.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveLeft/Iori Yagami_12.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveLeft/Iori Yagami_13.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveLeft/Iori Yagami_14.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveLeft/Iori Yagami_15.png";
		break;

	case 2:
		m_str.resize(12);
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_16.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_17.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_18.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_19.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_20.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_21.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_22.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_23.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_24.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_25.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_26.png";
		m_str[index++] = L"../../data/bitmap/iori/MoveRight/Iori Yagami_27.png";
		break;

	case 3:
		m_str.resize(6);
		m_str[index++] = L"../../data/bitmap/iori/Jump/Iori Yagami_29.png";
		m_str[index++] = L"../../data/bitmap/iori/Jump/Iori Yagami_30.png";
		m_str[index++] = L"../../data/bitmap/iori/Jump/Iori Yagami_31.png";
		m_str[index++] = L"../../data/bitmap/iori/Jump/Iori Yagami_32.png";
		m_str[index++] = L"../../data/bitmap/iori/Jump/Iori Yagami_33.png";
		m_str[index++] = L"../../data/bitmap/iori/Jump/Iori Yagami_34.png";
		
		break;

	case 4:
		m_str.resize(7);
		m_str[index++] = L"../../data/bitmap/iori/Sit/Iori Yagami_35.png";
		m_str[index++] = L"../../data/bitmap/iori/Sit/Iori Yagami_36.png";
		m_str[index++] = L"../../data/bitmap/iori/Sit/Iori Yagami_37.png";
		m_str[index++] = L"../../data/bitmap/iori/Sit/Iori Yagami_38.png";
		m_str[index++] = L"../../data/bitmap/iori/Sit/Iori Yagami_39.png";
		m_str[index++] = L"../../data/bitmap/iori/Sit/Iori Yagami_40.png";
		m_str[index++] = L"../../data/bitmap/iori/Sit/Iori Yagami_41.png";
		
		break;

	case 5:
		m_str.resize(56);
		
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_291.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_292.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_293.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_294.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_295.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_296.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_297.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_298.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_299.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_300.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_301.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_302.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_303.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_304.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_305.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_306.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_307.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_308.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_309.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_310.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_311.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_312.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_313.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_314.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_315.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_316.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_317.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_318.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_319.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_320.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_321.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_323.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_324.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_325.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_326.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_327.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_328.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_329.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_330.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_331.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_332.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_333.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_334.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_335.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_336.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_337.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_338.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_339.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_340.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_341.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_342.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_343.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_344.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_345.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_346.png";
		m_str[index++] = L"../../data/bitmap/iori/attack/Iori Yagami_347.png";
		break;

	case 6:
		m_str.resize(8);
		m_str[index++] = L"../../data/bitmap/iori/attack1/Iori Yagami_267.png";
		m_str[index++] = L"../../data/bitmap/iori/attack1/Iori Yagami_268.png";
		m_str[index++] = L"../../data/bitmap/iori/attack1/Iori Yagami_269.png";
		m_str[index++] = L"../../data/bitmap/iori/attack1/Iori Yagami_270.png";
		m_str[index++] = L"../../data/bitmap/iori/attack1/Iori Yagami_271.png";
		m_str[index++] = L"../../data/bitmap/iori/attack1/Iori Yagami_272.png";
		m_str[index++] = L"../../data/bitmap/iori/attack1/Iori Yagami_273.png";
		m_str[index++] = L"../../data/bitmap/iori/attack1/Iori Yagami_274.png";
		break;
	}
}

Iori::Iori()
{
	StateNUM = STATE_NOMAL;
}


Iori::~Iori()
{
}
