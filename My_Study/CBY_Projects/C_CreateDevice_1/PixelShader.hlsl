Texture2D		g_txDiffuseA : register(t0);
Texture2D		g_txDiffuseB : register(t1);
SamplerState	g_Sample0 : register(s0);

struct VS_OUT
{
	float4 p : SV_POSITION;
	float4 c : COLOR0;
	float2 t : TEXCOORDO;
};

struct PS_OUT
{
	float4 c : SV_TARGET;
};

PS_OUT PS(VS_OUT vsdata)
{
	PS_OUT pout;
	pout.c = g_txDiffuseA.Sample(g_Sample0,vsdata.t);
	return pout;
}

PS_OUT PSBlend(VS_OUT vsdata)
{
	PS_OUT pout;
	float4 SRC= g_txDiffuseB.Sample(g_Sample0, vsdata.t);
	float4 DESK = g_txDiffuseA.Sample(g_Sample0, vsdata.t);

	pout.c = SRC * DESK;
	return pout;
}