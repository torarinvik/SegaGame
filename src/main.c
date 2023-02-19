   /**
* Hello World Example
* Created With Genesis-Code extension for Visual Studio Code
* Use "Genesis Code: Compile" command to compile this program.
**/
#include <genesis.h>
#include <resources.h>
#include "Ball.h"
#include "Collision.h"
#include "Vector.h"


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
   Ball ball =  newBall((Vector){10, 20},   (Vector){0, 0}, 0.5, 1, &imgball);
   //Ball ball2 = newBall((Vector){80, 20},   (Vector){1, 0}, 0.5,  1, &imgball);
   
	
   

   //SYS_die("Game Over");
   const double dt = 2.0;

   while(1)
   {   
      // if (checkBallCollision(&ball, &ball2)){
      //    handleBallCollision(&ball, &ball2);
      // }
      // if (bingIs_colliding(&ball, &ball2)){
      //   bingHandle_collision(&ball, &ball2);
      //} 

      //for ball nr 1
      checkAndHandleWallCollision(&ball, 320, 233);
      //for ball nr 2
      //checkAndHandleWallCollision(&ball2, 320, 233);

      updateBall(&ball, dt);
      //updateBall(&ball2, dt);
      Vector tiss = newVector(0.1, 0.1);
      ball.vel = add(ball.vel, (Vector)newVector(0.01, 0.005));
      
       SPR_update();
       //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
       SYS_doVBlankProcess();
   }   
   return (0);


}






