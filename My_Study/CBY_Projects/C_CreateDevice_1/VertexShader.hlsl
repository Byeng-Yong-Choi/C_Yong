struct VS_OUT
{
	float4 p : SV_POSITION;
	float4 c : COLOR0;
	float2 t : TEXCOORDO;
};

struct VS_IN
{
	float4 p : POINT;
	float4 c : COLOR;
	float2 t : TEXT;
};

VS_OUT VS(VS_IN data)
{
	VS_OUT vout;
	vout.p = data.p;
	vout.c = data.c;
	vout.t = data.t;
	return vout;
}

