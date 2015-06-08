/****************************************************************************************** 
 *	Chili DirectX Framework Version 14.03.22											  *	
 *	Game.cpp																			  *
 *	Copyright 2014 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"

Game::Game( HWND hWnd,KeyboardServer& kServer,const MouseServer& mServer )
:	gfx( hWnd ),
	audio( hWnd ),
	kbd( kServer ),
	mouse( mServer )
{
	triangle.create({ 100, 100 }, 0);
}

Game::~Game()
{
}

void Game::Go()
{
	UpdateModel();
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel( )
{
	if (kbd.KeyIsPressed(187))
		triangle.scale(1.1);
	if (kbd.KeyIsPressed(189))
		triangle.scale(0.9);

	//selection
	Vec2 MousePos = { (float)mouse.GetMouseX(), (float)mouse.GetMouseY() };
	triangle.updateBounderies();
	if (triangle.upperleft.y < MousePos.y && MousePos.y < triangle.downRight.y && triangle.upperleft.x < MousePos.x && MousePos.x < triangle.downRight.x)
	{
		triangle.IsHighLighted = true;
		if (mouse.LeftIsPressed())
		{
			triangle.IsSelected = true;
		}
	}
	else
	{
		triangle.IsHighLighted = false;
	}
	if (triangle.IsSelected)
		triangle.Update(MousePos);
	if (mouse.RightIsPressed())
		triangle.IsSelected = false;

}

void Game::ComposeFrame()
{
	triangle.draw(gfx);
}
