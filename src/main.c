   /**
* Hello World Example
* Created With Genesis-Code extension for Visual Studio Code
* Use "Genesis Code: Compile" command to compile this program.
**/
#include <genesis.h>
#include <resources.h>
#include "Ball.h"
//#include "Collision.h"


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
   Ball ball = newBall((Vector){0, 0}, (Vector){1, 1}, 4, &imgball);
   //ball = SPR_addSprite(&imgball,100,100,TILE_ATTR(PAL1,0, FALSE, FALSE));
	
   

   //balls[0] = new_ball(1, 1, "red", 0, 0, 0, 0, &imgball);
   //balls[1] = new_ball(1, 1, "red", 3, 3, 1, 1, &imgball);

   //SYS_die("Game Over");
   const double dt = 2.0;

   while(1)
   {   
      updateBall(&ball, dt);
      checkAndHandleWallCollision(&ball, 320, 233);
       SPR_update();
       //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
       SYS_doVBlankProcess();
   }   
   return (0);


}






