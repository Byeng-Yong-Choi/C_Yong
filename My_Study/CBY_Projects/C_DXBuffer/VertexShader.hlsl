struct VS_OUT
{
	float4 p : SV_POSITION;
	float4 c : COLOR0;
	float2 t : TEXCOORDO;
};

struct VS_IN
{
	float3 p : POINT;
	float4 c : COLOR;
	float2 t : TEXT;
};

cbuffer m_ConData : register(b0)
{
	float4x4 g_matWorld : packoffset(c0);
	float4x4 g_matView : packoffset(c4);
	float4x4 g_matProj : packoffset(c8);
	float4 time : packoffset(c12);

};

VS_OUT VS(VS_IN data)
{
	VS_OUT vout;
	vout.p = float4(data.p, 1.0f);
	vout.c = data.c;
	vout.t = data.t;
	return vout;
}

VS_OUT VSmat(VS_IN data)
{
	VS_OUT vout;
	float4 vLocal = float4(data.p, 1.0f);
	float4 vWorld = mul(vLocal, g_matWorld);
	float4 vView = mul(vWorld, g_matView);
	float4 vProj = mul(vView, g_matProj);
	vout.p = vProj;
	vout.c = data.c;
	vout.t = data.t;
	return vout;
}

