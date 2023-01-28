    /**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include <genesis.h>
#include <resources.h>
#include "Ball.h"
#include "Wall.h"
#include "Collision.h"





// Function prototypes for collision detection and resolution functions










void handle_ball_wall_collision(Ball* ball, Wall* walls, int num_walls) {
    for (int i = 0; i < num_walls; i++) {
        if (detect_collision_between_ball_and_wall(ball, &walls[i])) {
            resolve_penetration_between_ball_and_wall(ball, &walls[i]);
            resolve_collision_between_ball_and_wall(ball, &walls[i]);
        }
    }
}

void handle_ball_ball_collision(Ball* ball, Ball* balls, int num_balls) {
    for (int i = 0; i < num_balls; i++) {
        if (detect_collision_between_balls(ball, &balls[i])) {
            prevent_overlap_between_balls(ball, &balls[i]);
            resolve_collision_between_balls(ball, &balls[i]);
        }
    }
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

void gameLoop(Ball* balls, Wall* walls)
{
	 for (int ind = 0; ind < MAX_BALLS; ind++) {
        draw_ball(&balls[ind]);

        handle_ball_wall_collision(&balls[ind], walls, MAX_WALLS);
        handle_ball_ball_collision(&balls[ind], balls, MAX_BALLS);
        reposition_ball(&balls[ind]);
    }
}


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
	Ball ballFromStruct  = new_ball(1, 1, "red", 25, 25, 5, 5, &imgball);
	Ball ballFromStruct2 = new_ball(1, 1, "red", 1, 1, 5, 5, &imgball);
    balls[0] = ballFromStruct;
    balls[1] = ballFromStruct2;
	//Make ball sprite twice as large

    walls[0] = new_wall(0, 0, 100, 0);
    walls[1] = new_wall(0, 0, 0, 100);
    walls[2] = new_wall(100, 0, 100, 100);
    walls[3] = new_wall(0, 100, 100, 100);
	
	

    while(1)
    {   
        gameLoop(balls, walls);
        SPR_update();
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        SYS_doVBlankProcess();
    }   
    return (0);


}






