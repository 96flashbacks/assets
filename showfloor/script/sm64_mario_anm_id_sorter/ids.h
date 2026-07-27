#ifndef MARIO_ANIMATION_IDS_H
#define MARIO_ANIMATION_IDS_H

/* Mario Animation IDs (with the names from anime.s) */

enum MarioAnimID {
    /* 0x00 */ MARIO_ANIM_SLOW_LEDGE_GRAB,                      // animMarioAscend
    /* 0x01 */ MARIO_ANIM_FALL_OVER_BACKWARDS,                  // animMarioBackDown
    /* 0x02 */ MARIO_ANIM_BACKWARD_AIR_KB,                      // animMarioJumpBackDown
    /* 0x03 */ MARIO_ANIM_DYING_ON_BACK,                        // animMarioBackDownEnd
    /* 0x05 */ MARIO_ANIM_CLIMB_UP_POLE,                        // animMarioBarClimb
    /* 0x06 */ MARIO_ANIM_GRAB_POLE_SHORT,                      // animMarioBarHang
    /* 0x07 */ MARIO_ANIM_GRAB_POLE_SWING_PART1,                // animMarioBarJumping
    /* 0x08 */ MARIO_ANIM_GRAB_POLE_SWING_PART2,                // animMarioBarJumpEnd
    /* 0x0D */ MARIO_ANIM_IDLE_ON_POLE,                         // animMarioBarWaiting
    /* 0x0E */ MARIO_ANIM_A_POSE,                               // animMarioBaseData
    /* 0x0F */ MARIO_ANIM_SKID_ON_GROUND,                       // animMarioBraking
    /* 0x10 */ MARIO_ANIM_STOP_SKID,                            // animMarioBrakeEnd
    /* 0x15 */ MARIO_ANIM_AIRBORNE_ON_STOMACH,                  // animMarioCannonFly
    /* 0x16 */ MARIO_ANIM_WALK_WITH_LIGHT_OBJ,                  // animMarioCarryJogging
    /* 0x17 */ MARIO_ANIM_RUN_WITH_LIGHT_OBJ,                   // animMarioCarryRunning
    /* 0x18 */ MARIO_ANIM_SLOW_WALK_WITH_LIGHT_OBJ,             // animMarioCarryWalking
    /* 0x1C */ MARIO_ANIM_CLIMB_DOWN_LEDGE,                     // animMarioDescend
    /* 0x28 */ MARIO_ANIM_STAND_UP_FROM_LAVA_BOOST,             // animMarioFireJumpEnd
    /* 0x29 */ MARIO_ANIM_FIRE_LAVA_BURN,                       // animMarioFireJumping
    /* 0x2A */ MARIO_ANIM_WING_CAP_FLY,                         // animMarioFlight

    /* 0xA4 */ MARIO_ANIM_WATER_IDLE_WITH_OBJ,                  // animMarioFloatHold
    /* 0xB2 */ MARIO_ANIM_WATER_IDLE,                           // animMarioFloating
    /* 0xD1 */ MARIO_ANIM_WATER_ANALOG_SWIMMING,                // animMarioFloatMoving
    /* 0xAE */ MARIO_ANIM_WATER_PICK_UP_OBJ,                    // animMarioFloatTake
    /* 0xB1 */ MARIO_ANIM_WATER_THROW_OBJ,                      // animMarioFloatThrow

    /* 0x2B */ MARIO_ANIM_HANG_ON_OWL,                          // animMarioFlying
    /* 0x2C */ MARIO_ANIM_LAND_ON_STOMACH,                      // animMarioForeDown
    /* 0x2D */ MARIO_ANIM_AIR_FORWARD_KB,                       // animMarioJumpForeDown
    /* 0x2E */ MARIO_ANIM_DYING_ON_STOMACH,                     // animMarioForeDownEnd
    /* 0x32 */ MARIO_ANIM_DYING_FALL_OVER,                      // animMarioGiddyDown
    /* 0x33 */ MARIO_ANIM_IDLE_ON_LEDGE,                        // animMarioHanging
    /* 0x34 */ MARIO_ANIM_FAST_LEDGE_GRAB,                      // animMarioHangJump
    /* 0x3A */ MARIO_ANIM_GROUND_POUND_LANDING,                 // animMarioHipAttackEnd
    /* 0x3C */ MARIO_ANIM_START_GROUND_POUND,                   // animMarioHipAttackStart
    /* 0x3D */ MARIO_ANIM_GROUND_POUND,                         // animMarioHipAttacking
    /* 0x3F */ MARIO_ANIM_IDLE_WITH_LIGHT_OBJ,                  // animMarioHolding
    /* 0x40 */ MARIO_ANIM_JUMP_LAND_WITH_LIGHT_OBJ,             // animMarioHoldJumpEnd
    /* 0x41 */ MARIO_ANIM_JUMP_WITH_LIGHT_OBJ,                  // animMarioHoldJumping
    /* 0x42 */ MARIO_ANIM_FALL_LAND_WITH_LIGHT_OBJ,             // animMarioHoldLandEnd
    /* 0x43 */ MARIO_ANIM_FALL_WITH_LIGHT_OBJ,                  // animMarioHoldLanding
    /* 0x44 */ MARIO_ANIM_FALL_FROM_SLIDING_WITH_LIGHT_OBJ,     // animMarioHoldSlipLanding
    /* 0x45 */ MARIO_ANIM_SLIDING_ON_BOTTOM_WITH_LIGHT_OBJ,     // animMarioHoldSlipping
    /* 0x46 */ MARIO_ANIM_STAND_UP_FROM_SLIDING_WITH_LIGHT_OBJ, // animMarioHoldSlipEnd
    /* 0x48 */ MARIO_ANIM_WALKING,                              // animMarioJogging
    /* 0x49 */ MARIO_ANIM_FORWARD_FLIP,                         // animMarioJumpBack        (unused)
    /* 0x4B */ MARIO_ANIM_LAND_FROM_DOUBLE_JUMP,                // animMarioJumpEnd2
    /* 0x4C */ MARIO_ANIM_DOUBLE_JUMP_FALL,                     // animMarioJumpFall
    /* 0x4D */ MARIO_ANIM_SINGLE_JUMP,                          // animMarioJumping
    /* 0x4E */ MARIO_ANIM_LAND_FROM_SINGLE_JUMP,                // animMarioJumpEnd
    /* 0x50 */ MARIO_ANIM_DOUBLE_JUMP_RISE,                     // animMarioJumpStep2
    /* 0x51 */ MARIO_ANIM_START_FORWARD_SPINNING,               // animMarioJumpStep3       (unused)
    /* 0x52 */ MARIO_ANIM_THROW_LIGHT_OBJECT,                   // animMarioJumpThrow
    /* 0x56 */ MARIO_ANIM_GENERAL_FALL,                         // animMarioLanding
    /* 0x57 */ MARIO_ANIM_GENERAL_LAND,                         // animMarioLandEnd
    /* 0x58 */ MARIO_ANIM_BEING_GRABBED,                        // animMarioLifted
    /* 0x59 */ MARIO_ANIM_GRAB_HEAVY_OBJECT,                    // animMarioLifting
    /* 0x5A */ MARIO_ANIM_SLOW_LAND_FROM_DIVE,                  // animMarioLostStandup
    /* 0x5B */ MARIO_ANIM_FLY_FROM_CANNON,                      // animMarioMantFlying
    /* 0x5F */ MARIO_ANIM_PULL_DOOR_WALK_IN,                    // animMarioOpenDoor1
    /* 0x60 */ MARIO_ANIM_PUSH_DOOR_WALK_IN,                    // animMarioOpenDoor2
    /* 0x65 */ MARIO_ANIM_GROUND_THROW,                         // animMarioPitching
    /* 0x66 */ MARIO_ANIM_GROUND_KICK,                          // animMarioPowerKick
    /* 0x67 */ MARIO_ANIM_FIRST_PUNCH,                          // animMarioPunchBase
    /* 0x69 */ MARIO_ANIM_FIRST_PUNCH_FAST,                     // animMarioPunchEnd
    /* 0x6B */ MARIO_ANIM_PICK_UP_LIGHT_OBJ,                    // animMarioPunchTake
    /* 0x6C */ MARIO_ANIM_PUSHING,                              // animMarioPushing
    /* 0x6E */ MARIO_ANIM_PLACE_LIGHT_OBJ,                      // animMarioPutting
    /* 0x6F */ MARIO_ANIM_FORWARD_SPINNING,                     // animMarioRolling
    /* 0x70 */ MARIO_ANIM_BACKWARD_SPINNING,                    // animMarioBackRolling
    /* 0x72 */ MARIO_ANIM_RUNNING,                              // animMarioRunning
    /* 0x73 */ MARIO_ANIM_RUNNING_UNUSED,                       // animMarioTurnCont        (unused)
    /* 0x74 */ MARIO_ANIM_SOFT_BACK_KB,                         // animMarioSafeBackDown
    /* 0x75 */ MARIO_ANIM_SOFT_FRONT_KB,                        // animMarioSafeForeDown
    /* 0x7B */ MARIO_ANIM_BACKWARD_KB,                          // animMarioShortBackDown
    /* 0x7C */ MARIO_ANIM_FORWARD_KB,                           // animMarioShortForeDown
    /* 0x7D */ MARIO_ANIM_IDLE_HEAVY_OBJ,                       // animMarioShoulder
    /* 0x7E */ MARIO_ANIM_STAND_AGAINST_WALL,                   // animMarioSideWait
    /* 0x7F */ MARIO_ANIM_SIDESTEP_LEFT,                        // animMarioSideWalkL
    /* 0x80 */ MARIO_ANIM_SIDESTEP_RIGHT,                       // animMarioSideWalkR
    /* 0x81 */ MARIO_ANIM_START_SLEEP_IDLE,                     // animMarioSleeping1
    /* 0x82 */ MARIO_ANIM_START_SLEEP_SCRATCH,                  // animMarioSleeping2
    /* 0x83 */ MARIO_ANIM_START_SLEEP_YAWN,                     // animMarioSleeping3
    /* 0x84 */ MARIO_ANIM_START_SLEEP_SITTING,                  // animMarioSleeping4
    /* 0x85 */ MARIO_ANIM_SLEEP_IDLE,                           // animMarioSleeping5
    /* 0x88 */ MARIO_ANIM_DIVE,                                 // animMarioSlideCatch
    /* 0x89 */ MARIO_ANIM_SLIDE_DIVE,                           // animMarioSlipBack
    /* 0x8B */ MARIO_ANIM_STOP_SLIDE_LIGHT_OBJ,                 // animMarioSlideStandup
    /* 0x8E */ MARIO_ANIM_SLIDE_MOTIONLESS,                     // animMarioSlip
    /* 0x8F */ MARIO_ANIM_STOP_SLIDE,                           // animMarioSlipEnd
    /* 0x90 */ MARIO_ANIM_FALL_FROM_SLIDE,                      // animMarioSlipLanding
    /* 0x92 */ MARIO_ANIM_TIPTOE,                               // animMarioSoftStep
    /* 0x93 */ MARIO_ANIM_TWIRL_LAND,                           // animMarioSpinJpEnd
    /* 0x94 */ MARIO_ANIM_TWIRL,                                // animMarioSpinJumping
    /* 0x95 */ MARIO_ANIM_START_TWIRL,                          // animMarioSpinJpStart
    /* 0x96 */ MARIO_ANIM_STOP_CROUCHING,                       // animMarioSquatEnd
    /* 0x97 */ MARIO_ANIM_START_CROUCHING,                      // animMarioSquatStart
    /* 0x98 */ MARIO_ANIM_CROUCHING,                            // animMarioSquatWaiting
    /* 0x99 */ MARIO_ANIM_CRAWLING,                             // animMarioSquatWalking
    /* 0x9A */ MARIO_ANIM_STOP_CRAWLING,                        // animMarioSquatWalkEnd
    /* 0x9B */ MARIO_ANIM_START_CRAWLING,                       // animMarioSquatWalkStart
    /* 0x9E */ MARIO_ANIM_BACKWARDS_WATER_KB,                   // animMarioSwimBackDown

    /* 0xA1 */ MARIO_ANIM_FLUTTERKICK_WITH_OBJ,                 // animMarioSwimCarry

    /* 0xA5 */ MARIO_ANIM_DROWNING_PART1,                       // animMarioSwimDown1
    /* 0xA6 */ MARIO_ANIM_DROWNING_PART2,                       // animMarioSwimDown2
    /* 0xA7 */ MARIO_ANIM_WATER_DYING,                          // animMarioSwimDownEnd
    /* 0xA8 */ MARIO_ANIM_WATER_FORWARD_KB,                     // animMarioSwimForeDown

    /* 0xA3 */ MARIO_ANIM_STOP_GRAB_OBJ_WATER,                  // animMarioSwimHold

    /* 0xAA */ MARIO_ANIM_SWIM_PART1,                           // animMarioSwimming1
    /* 0xAB */ MARIO_ANIM_SWIM_PART2,                           // animMarioSwimming2
    /* 0xAC */ MARIO_ANIM_FLUTTERKICK,                          // animMarioSwimming3
    
    /* 0xAD */ MARIO_ANIM_WATER_ACTION_END,                     // animMarioSwimStop

    /* 0xB3 */ MARIO_ANIM_WATER_STAR_DANCE,                     // animMarioSwimWinDemo
    /* 0xB5 */ MARIO_ANIM_GRAB_BOWSER,                          // animMarioSwingStart
    /* 0xB6 */ MARIO_ANIM_SWINGING_BOWSER,                      // animMarioSwingAttack
    /* 0xB7 */ MARIO_ANIM_RELEASE_BOWSER,                       // animMarioSwingDown
    /* 0xB8 */ MARIO_ANIM_HOLDING_BOWSER,                       // animMarioSwingWait
    /* 0xB9 */ MARIO_ANIM_HEAVY_THROW,                          // animMarioThrowing
    /* 0xBA */ MARIO_ANIM_WALK_PANTING,                         // animMarioTiredWaiting
    /* 0xBB */ MARIO_ANIM_WALK_WITH_HEAVY_OBJ,                  // animMarioTransfer
    /* 0xBC */ MARIO_ANIM_TURNING_PART1,                        // animMarioTurning
    /* 0xBD */ MARIO_ANIM_TURNING_PART2,                        // animMarioTurnEnd
    /* 0xBE */ MARIO_ANIM_SLIDEFLIP_LAND,                       // animMarioUJumpEnd
    /* 0xBF */ MARIO_ANIM_SLIDEFLIP,                            // animMarioUJumping
    /* 0xC2 */ MARIO_ANIM_FIRST_PERSON,                         // animMarioViewing
    /* 0xC3 */ MARIO_ANIM_IDLE_HEAD_LEFT,                       // animMarioWaiting1
    /* 0xC4 */ MARIO_ANIM_IDLE_HEAD_RIGHT,                      // animMarioWaiting2
    /* 0xC5 */ MARIO_ANIM_IDLE_HEAD_CENTER,                     // animMarioWaiting3
    /* 0xC8 */ MARIO_ANIM_WAKE_FROM_SLEEP,                      // animMarioWakeup
    /* 0xCA */ MARIO_ANIM_START_TIPTOE,                         // animMarioWalking
    /* 0xCB */ MARIO_ANIM_SLIDEJUMP,                            // animMarioWallJump
    /* 0xCC */ MARIO_ANIM_START_WALLKICK,                       // animMarioWallStay
    /* 0xCD */ MARIO_ANIM_STAR_DANCE                            // animMarioWinDemoA
};

#endif // MARIO_ANIMATION_IDS_H
