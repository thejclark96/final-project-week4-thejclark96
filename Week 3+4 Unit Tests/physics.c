#include "physics.h"
#include "app.h"

float                           prev_y_pos;
float                           abs_y_velocity;

float                           shield_force;
float                           shield_input;
float                           shield_accel;
// testing purposes
float                           shield_pos;
struct  hm_attributes           enemy;
struct  platform_attributes     this_platform;


/*** This function enacts gravity on the enemy ***/
void gravity_force(float ggravity, struct hm_attributes *enemy){
  /* Ball is falling; increase speed */
  if(enemy->y_vel >= 0){
      enemy->y_vel = enemy->y_vel + (ggravity);
  }

  /* Ball is rising; decrease speed */
  if(enemy->y_vel <= 0){
      enemy->y_vel =  enemy->y_vel + (1*ggravity);
  }
}


/*** Function to reverse direction when the enemy hits a wall or the slider ***/
void bounce(struct hm_attributes * enemy, struct platform_attributes * shield ){
//  /* Ball hit floor!!! */
//  if(enemy->y_pos  >=  125){
//      enemy->y_vel  = enemy->y_vel * -0.83;
//  }
  /* Ball hit platform!!! */
  if( enemy->y_pos  >= (shield->y_pos - (enemy->display_diameter + 1)) ){
      if ( (enemy->x_pos < shield->x_pos+((shield->length/2)+3)) && (enemy->x_pos > shield->x_pos-((shield->length/2)+3)) ){

          enemy->y_vel  = enemy->y_vel * -0.83;
      }
  }


  /* Ball hit roof!!! */
  if(enemy->y_pos  <=    0.001){
      enemy->y_vel  = enemy->y_vel * -1;
  }

  /* Ball hit left canyon wall!!! */
  if(enemy->x_pos  <=    0){
      enemy->x_vel  = enemy->x_vel * -1;
  }

  /* Ball hit right canyon wall! */
  if(enemy->x_pos  >=  128){
      enemy->x_vel  = enemy->x_vel * -1;
  }
}


/*** This function will eventually be in charge of boosting the enemy when the btn is pressed. ***/
// For now this function just boosts the enemy when it's speed gets too slow
void booster(struct hm_attributes * enemy){
  /* Boost that MF */
  abs_y_velocity  = abs(enemy->y_vel);
  if(abs(enemy->y_vel) < 0.5){
      enemy->y_vel  = (-1)  * abs(enemy->y_vel * 4);
  }
}