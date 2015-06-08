#include "Vec2.h"
#include "D3DGraphics.h"

#pragma once

class triangle
{
public:
	void create(Vec2 pos, float rot)
	{
		if (!iscreated)
		{
			a = { pos.x, pos.y - (float)1.73 * 50 };
			b = { pos.x - 50, pos.y };
			c = { pos.x + 50, pos.y };
			rotation = rot;
			iscreated = true;
			pos = selfpos;
		}
	}

//	void rotate(float rotation);
	void Update(Vec2 cursor)
	{
		selfpos = cursor;

		a = { selfpos.x, selfpos.y - (float)1.73 * 50 };
		b = { selfpos.x - 50, selfpos.y };
		c = { selfpos.x + 50, selfpos.y };
	}
//	void DestroySelf();

	void draw(D3DGraphics& gf)
	{
		if (IsHighLighted)
			color = YELLOW;
		if (IsSelected)
			color = RED;
		if (!IsHighLighted && !IsSelected)
			color = WHITE;


		gf.DrawLine(a, b, color);
		gf.DrawLine(b, c, color);
		gf.DrawLine(c, a, color);
	}

	void scale(float n)
	{
		a.y = a.y * n;
		b.x = b.x - (b.x * n);
		c.x = c.x * n;
	}

	void updateBounderies()
	{
		upperleft = { b.x, a.y };
		downRight = { c.x, c.y };
	}


	Vec2 upperleft;
	Vec2 downRight;
	bool IsHighLighted;
	bool IsSelected = false;

private:
	Vec2 selfpos;
	D3DCOLOR color = WHITE;
	bool iscreated = false;
	int cnt = 0;
	float rotation;
	int pos_x;
	int pos_y;
	Vec2 a;
	Vec2 b;
	Vec2 c;
};