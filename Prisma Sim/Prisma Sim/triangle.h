#include "Vec2.h"

class triangle
{
public:
	void create(Vec2 pos, float rot)
	{
		a = { pos.x, pos.y - (float)1.732 * 10 };
		b = { pos.x - 10, pos.y };
		c = { pos.x + 10, pos.y };
		rotation = rot;
	}

	void rotate(float rotation);
	void MoveWithCursor();
	void DestroySelf();
	void draw()
	{
		float rc = (a.y - b.y) / (a.x - b.x);
		for (int i = b.x; i != a.x; i++)
		{
			int x = i;
			int y = rc*i;

			screen[(int)x][(int)y];
		}
	}

	void scale();


	bool IsHighLighted;

private:
	int screen[800][600];
	float rotation;
	int pos_x;
	int pos_y;
	Vec2 a;
	Vec2 b;
	Vec2 c;
};