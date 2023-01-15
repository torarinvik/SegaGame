/* /* #include <genesis.h>
#include <resources.h>

/*The edges of the play field*/
/*
typedef struct
{
    int pos_x, pos_y, vel_x, vel_y, width, height;
} Ball;
enum Wall
{
    LEFT_EDGE = 0,
    RIGHT_EDGE = 320,
    TOP_EDGE = 0,
    BOTTOM_EDGE = 224
};


Sprite* ballSprite;
Ball ball;
ball.pos_x = 150;
ball.pos_y = 100;
ball.vel_x = 1;
ball.vel_y = 1;
ball.width = 8;
ball.height = 8;


void moveBall(Ball ball){

	//Check horizontal bounds
	if(ball.pos_x < LEFT_EDGE){
		ball.pos_x = LEFT_EDGE;
		ball.vel_x = -ball.vel_x;
	} else if(ball.pos_x + ball.width > RIGHT_EDGE){
		ball.pos_x = RIGHT_EDGE - ball.width;
		ball.vel_x = -ball.vel_x;
	}

	//Check vertical bounds
	if(ball.pos_y < TOP_EDGE){
		ball.pos_y = TOP_EDGE;
		ball.vel_y = -ball.vel_y;
	} else if(ball.pos_y + ball.heigh > BOTTOM_EDGE){
		ball.pos_y = BOTTOM_EDGE - ball.heigh;
		ball.vel_y = -ball.vel_y;
	}

	//Position the ball
	ball.pos_x += ball.vel_x;
	ball.pos_y += ball.vel_y;

	SPR_setPosition(ballSprite,ball.pos_x,ball.pos_y);
}
void moveBallKeypad()
{
	if (JOY_readJoypad(JOY_1) & BUTTON_LEFT)
	{
		ball.pos_x -= 10;
	}
	if (JOY_readJoypad(JOY_1) & BUTTON_RIGHT)
	{
		ball.pos_x += 10;
	}
	if (JOY_readJoypad(JOY_1) & BUTTON_UP)
	{
		ball.pos_y -= 10;
	}
	if (JOY_readJoypad(JOY_1) & BUTTON_DOWN)
	{
		ball.pos_y += 10;
	}
	SPR_setPosition(ballSprite,ball.pos_x,ball.pos_y);
}
void myJoyHandler( u16 joy, u16 changed, u16 state)
{
	/* if (joy == JOY_1)
	{
		if (state & BUTTON_LEFT)
		{
			//player 1 press START button
		}
		if (state & BUTTON_RIGHT)
		{
			
		}
		else if (changed & BUTTON_START)
		{
			//player 1 released START button	
		}
	}	 
	moveBallKeypad();
}
  */