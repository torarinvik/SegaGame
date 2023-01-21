    /**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include <resources.h>
#include "Ball.h"

/*The edges of the play field*/
const int LEFT_EDGE = 0;
const int RIGHT_EDGE = 320;
const int TOP_EDGE = 0;
const int BOTTOM_EDGE = 224;

Sprite* ball;
Ball* ballFromStruct;
Ball* ballFromStruct2;

int ball_pos_x = 150;
int ball_pos_y = 100;
int ball_vel_x = 1;
int ball_vel_y = 1;
int ball_width = 8;
int ball_height = 8;

void moveBall(){

	//Check horizontal bounds
	if(ball_pos_x < LEFT_EDGE){
		ball_pos_x = LEFT_EDGE;
		ball_vel_x = -ball_vel_x;
	} else if(ball_pos_x + ball_width > RIGHT_EDGE){
		ball_pos_x = RIGHT_EDGE - ball_width;
		ball_vel_x = -ball_vel_x;
	}

	//Check vertical bounds
	if(ball_pos_y < TOP_EDGE){
		ball_pos_y = TOP_EDGE;
		ball_vel_y = -ball_vel_y;
	} else if(ball_pos_y + ball_height > BOTTOM_EDGE){
		ball_pos_y = BOTTOM_EDGE - ball_height;
		ball_vel_y = -ball_vel_y;
	}

	//Position the ball
	ball_pos_x += ball_vel_x;
	ball_pos_y += ball_vel_y;

	SPR_setPosition(ball,ball_pos_x,ball_pos_y);
}
// void moveBallKeypad()
// {
// 	if (JOY_readJoypad(JOY_1) & BUTTON_LEFT)
// 	{
// 		ballFromStruct->po -= 10;
// 		//ball_pos_x -= 10;
// 	}
// 	if (JOY_readJoypad(JOY_1) & BUTTON_RIGHT)
// 	{
// 		//ball_pos_x += 10;
// 		ballFromStruct->pos_x += 10;
// 	}
// 	if (JOY_readJoypad(JOY_1) & BUTTON_UP)
// 	{
// 		//ball_pos_y -= 10;
// 		ballFromStruct->pos_y -= 10;
// 	}
// 	if (JOY_readJoypad(JOY_1) & BUTTON_DOWN)
// 	{
// 		//ball_pos_y += 10;
// 		ballFromStruct->pos_y += 10;
// 	}
// 	SPR_setPosition(ball,ball_pos_x,ball_pos_y);
// }
// void myJoyHandler( u16 joy, u16 changed, u16 state)
// {
// 	/* if (joy == JOY_1)
// 	{
// 		if (state & BUTTON_LEFT)
// 		{
// 			//player 1 press START button
// 		}
// 		if (state & BUTTON_RIGHT)
// 		{
			
// 		}
// 		else if (changed & BUTTON_START)
// 		{
// 			//player 1 released START button	
// 		}
// 	}	 */
// 	moveBallKeypad();
// }




int main()
{
    //COCK
	//JOYSTICK STUFF
	//JOY_init();
	//JOY_setEventHandler( &myJoyHandler );
	//END JOYSTICK
	//VDP_loadTileSet(bgtile.tileset,1,DMA);
    //VDP_setPalette(PAL1, bgtile.palette->data);
    //VDP_setTileMapXY(BG_B,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),2,2);
    
    //VDP_loadTileSet(bgtile.tileset,1,DMA);
    //VDP_setTileMapXY(BG_B,1,2,2);

    PAL_setPalette(PAL1, bgtile.palette->data, DMA);
    //VDP_drawImageEx(BG_B, &bgtile, TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),2,2, FALSE, TRUE);

    SPR_init();
    //ball = SPR_addSprite(&imgball,100,100,TILE_ATTR(PAL1,0, FALSE, FALSE));
	*ballFromStruct = new_ball(1, 1, "red", 25, 25, 1, 1, &imgball);
	*ballFromStruct2 = new_ball(1, 1, "red", 1, 1, 1, 1, &imgball);

	//Make ball sprite twice as large
	
	

    while(1)
    {   
        //moveBall();
        SPR_update();
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        SYS_doVBlankProcess();
    }   
    return (0);
}
