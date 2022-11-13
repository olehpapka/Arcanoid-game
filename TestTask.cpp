#include "Headers/Framework.h"
#include "Headers/Brick.h"
#include "Headers/Platform.h"
#include "Headers/Game.h"
#include <array>


/* Test Framework realization */
class MyFramework : public Framework {
private:
	Game* game;
public:
	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 800;
		height = 700;
		fullscreen = false;
	}

	virtual bool Init() 
	{
		srand(time(NULL));
		game = Game::GetInstance();
		getScreenSize(game->SetScreenWidth(), game->SetScreenHeight());
		showCursor(0);
		game->Restart();
		return true;
	}

	virtual void Close() 
	{

	}

	virtual bool Tick() 
	{
		if (!game->GameOver())
		{
			game->GameLogic();
		}
		 
		else
		{
			game->Restart();
		}
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) 
	{
		game->OnMouseMove(x, y, xrelative, yrelative);
		
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) 
	{
		game->OnMouseButtonClicked(button, isReleased);
	}

	virtual void onKeyPressed(FRKey k) 
	{
		game->OnKeyInputReceived(k);
		
	}

	virtual void onKeyReleased(FRKey k) 
	{
		
	}

	virtual const char* GetTitle() override
	{
		return "Arcanoid";
	}

	~MyFramework()
	{
		delete game;
	}
};

int main(int argc, char* argv[])
{
	
	return run(new MyFramework);
}
