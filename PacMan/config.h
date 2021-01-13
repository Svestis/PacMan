#pragma once

/**
* FILE: config.h
* TITLE: configureation file
*
* PURPOSE:
*
* Defining all the constants to be used across the programme. It includes, including but not limited to floder paths, universal sizes, colors, etc.
*
* FUNCTIONS:
*
* None
*
* INCLUDED FILES:
*
* None
*
* @file config.h
**/

// PATHS
#define ASSET_PATH "assets\\"

// SIZES
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 600
#define CANVAS_WIDTH 1200
#define CANVAS_HEIGHT 600
#define PLAYER_POSITION_X
#define PLAYER_POSITION_Y

// COLORS
#define COLORPACKMAN_R .816f
#define COLORPACKMAN_G  .753f
#define COLORPACKMAN_B 0.318f
#define COLORRED_R .847f
#define COLORRED_G .298f
#define COLORRED_B .294f
#define COLORBLUE_R .286f
#define COLORBLUE_G .969f
#define COLORBLUE_B .965f
#define COLORCLYDE_R .725f
#define COLORCLYDE_R .725f
#define COLORCLYDE_G .380f
#define COLORCLYDE_B .129f
#define COLORBLINKY_R .682f
#define COLORBLINKY_G .141f
#define COLORBLINKY_B .129f
#define COLORPINKY_R .604f
#define COLORPINKY_G .137f
#define COLORPINKY_B .741f
#define COLORINKY_R .129f
#define COLORINKY_G .529f
#define COLORINKY_B .686f
#define COLORCLYDEC_R 1.f
#define COLORCLYDEC_G .808f
#define COLORCLYDEC_B .192f
#define COLORBLINKYC_R 1.f
#define COLORBLINKYC_G .0f
#define COLORBLINKYC_B .0f
#define COLORPINKYC_R 1.f
#define COLORPINKYC_G .612f
#define COLORPINKYC_B .808f
#define COLORINKYC_R .192f
#define COLORINKYC_G 1.f
#define COLORINKYC_B 1.f

// TEXT
#define TITLE "PAC - MAN"
#define SCORE "SCORE"
#define HSCORE "HI SCORE"
#define BC "Back to classics"
#define BR "Are you bored?"
#define MUSIC "MUSIC"
#define SOUND "SOUND"
#define INFOT "INFO"
#define CLOSET "CLOSE"
#define PLAY "PRESS ENTER TO PLAY"
#define MUSICT "M: TURN ON/OFF THE MUSIC"
#define SOUNDT "N: TURN ON/OFF THE SOUND"
#define SWITCH "SHIFTL: SWITCH TO MODERN MODE"
#define ESCA "ESC: CLOSE THE GAME"
#define MULTIT "Multiplayer"
#define SINGLET "Singleplayer"
#define WEBPAGE "start https://github.com/Svestis/PacMan"
#define FULLSCREEN "SHIFTR: SWITCH TO FULL SCREEN"
#define FULLT "Fullscreen"
#define BOREDT "Online Arcade Games"
#define PONG "pong"
#define WEBPAGEPONG "start https://www.playretrogames.com/coin-op-arcade/all"
#define BACKT "back"
#define SELECTCHAR "player 2 select character"
#define CHARNICK "CHARACTER                    -                    NICKNAME"
#define PINCKYT "- SPEEDY"
#define BLINKYT "- SHADOW"
#define INKYT "- BASHFUL"
#define CLYDET "- POKEY"
#define PINCKYTN "PINKY"
#define BLINKYTN "BLINKY"
#define INKYTN "INKY"
#define CLYDETN "CLYDE"
#define P1 "PLAYER 1"
#define P2 "PLAYER 2"
#define PACMANINF "PACMAN"
#define CLASSSTARTTITLE "             HIGH SCORE             "
#define CREDITS "CREDITS"
#define PUSHSTART "PUSH START BUTTON"
#define HISCORE  "HIGH SCORE"
#define UPSONE "1UP"
#define GAMEOVER "GAME OVER"
#define PLAYAGAIN "PLAY AGAIN?"
#define PAUSET "PAUSE"
#define RESUMET "RESUME"
#define PACMANT "PACMAN"

// MUSIC
#define WELCOME_MUSICM "welcome_music_modern.mp3"
#define WELCOME_MUSICC "welcome_music_classic.mp3"

// FONTS
#define FONTM "cheapmot.ttf"
#define FONTC "arcade.ttf"
#define FONTPACMAN "pacman.ttf"
#define FONTPONG "pong.ttf"

// IMAGES
#define BACKGROUND_MENUM "back2.png"
#define BACKGROUND_MENUC ""
#define CLOSE "close.png"
#define INFO "info.png"
#define MUSIC_ON "music_on.png"
#define MUSIC_OFF "music_off.png"
#define SOUND_ON "sound_on.png"
#define SOUND_OFF "sound_off.png"
#define CLASSIC "classic.png"
#define PAC0 "pacman.png"
#define DF "trysomethingdifferent.png"
#define SINGLEPALYER "single_player2.png"
#define MULTIPLAYER "single_player2.png"
#define FULL "full.png"
#define NOTFULL "notfull.png"
#define LETSPLAY "letsplay_m.png"
#define VERTICALLINE "verticalline.png"
#define PACMAN_C_START "start_c.png"
#define PACMAN_C_LEFT_1 "left_c_1.png"
#define PACMAN_C_LEFT_2 "left_c_2.png"
#define PACMAN_C_RIGHT_1 "right_c_1.png"
#define PACMAN_C_RIGHT_2 "right_c_2.png"
#define PACMAN_C_UP_1 "up_c_1.png"
#define PACMAN_C_UP_2 "up_c_2.png"
#define PACMAN_C_DOWN_1 "down_c_1.png"
#define PACMAN_C_DOWN_2 "down_c_2.png"
#define BOREDARC "arcades.png"
#define BOREDPONG "pong.png"
#define BACK "back.png"
#define BLINKY_C_UP_1 "blinky_c_up_1.png"
#define BLINKY_C_UP_2 "blinky_c_up_2.png"
#define BLINKY_C_DOWN_1 "blinky_c_down_1.png"
#define BLINKY_C_DOWN_2 "blinky_c_down_2.png"
#define BLINKY_C_LEFT_1 "blinky_c_left_1.png"
#define BLINKY_C_LEFT_2 "blinky_c_left_2.png"
#define BLINKY_C_RIGHT_1 "blinky_c_right_1.png"
#define BLINKY_C_RIGHT_2 "blinky_c_right_2.png"
#define PINKY_C_UP_1 "pinky_c_up_1.png"
#define PINKY_C_UP_2 "pinky_c_up_2.png"
#define PINKY_C_DOWN_1 "pinky_c_down_1.png"
#define PINKY_C_DOWN_2 "pinky_c_down_2.png"
#define PINKY_C_LEFT_1 "pinky_c_left_1.png"
#define PINKY_C_LEFT_2 "pinky_c_left_2.png"
#define PINKY_C_RIGHT_1 "pinky_c_right_1.png"
#define PINKY_C_RIGHT_2 "pinky_c_right_2.png"
#define INKY_C_UP_1 "inky_c_up_1.png"
#define INKY_C_UP_2 "inky_c_up_2.png"
#define INKY_C_DOWN_1 "inky_c_down_1.png"
#define INKY_C_DOWN_2 "inky_c_down_2.png"
#define INKY_C_LEFT_1 "inky_c_left_1.png"
#define INKY_C_LEFT_2 "inky_c_left_2.png"
#define INKY_C_RIGHT_1 "inky_c_right_1.png"
#define INKY_C_RIGHT_2 "inky_c_right_2.png"
#define CLYDE_C_UP_1 "clyde_c_up_1.png"
#define CLYDE_C_UP_2 "clyde_c_up_2.png"
#define CLYDE_C_DOWN_1 "clyde_c_down_1.png"
#define CLYDE_C_DOWN_2 "clyde_c_down_2.png"
#define CLYDE_C_LEFT_1 "clyde_c_left_1.png"
#define CLYDE_C_LEFT_2 "clyde_c_left_2.png"
#define CLYDE_C_RIGHT_1 "clyde_c_right_1.png"
#define CLYDE_C_RIGHT_2 "clyde_c_right_2.png"
#define PACMAN_M_LEFT_3 "left_m_3.png"
#define PACMAN_M_LEFT_1 "left_m_1.png"
#define PACMAN_M_LEFT_2 "left_m_2.png"
#define PACMAN_M_RIGHT_1 "right_m_1.png"
#define PACMAN_M_RIGHT_2 "right_m_2.png"
#define PACMAN_M_RIGHT_3 "right_m_3.png"
#define PACMAN_M_UP_1 "up_m_1.png"
#define PACMAN_M_UP_2 "up_m_2.png"
#define PACMAN_M_UP_3 "up_m_3.png"
#define PACMAN_M_DOWN_1 "down_m_1.png"
#define PACMAN_M_DOWN_2 "down_m_2.png"
#define PACMAN_M_DOWN_3 "down_m_3.png"
#define BLINKY_M_UP_1 "blinky_m_up_1.png"
#define BLINKY_M_UP_2 "blinky_m_up_2.png"
#define BLINKY_M_DOWN_1 "blinky_m_down_1.png"
#define BLINKY_M_DOWN_2 "blinky_m_down_2.png"
#define BLINKY_M_LEFT_1 "blinky_m_left_1.png"
#define BLINKY_M_LEFT_2 "blinky_m_left_2.png"
#define BLINKY_M_RIGHT_1 "blinky_m_right_1.png"
#define BLINKY_M_RIGHT_2 "blinky_m_right_2.png"
#define PINKY_M_UP_1 "pinky_m_up_1.png"
#define PINKY_M_UP_2 "pinky_m_up_2.png"
#define PINKY_M_DOWN_1 "pinky_m_down_1.png"
#define PINKY_M_DOWN_2 "pinky_m_down_2.png"
#define PINKY_M_LEFT_1 "pinky_m_left_1.png"
#define PINKY_M_LEFT_2 "pinky_m_left_2.png"
#define PINKY_M_RIGHT_1 "pinky_m_right_1.png"
#define PINKY_M_RIGHT_2 "pinky_m_right_2.png"
#define INKY_M_UP_1 "inky_m_up_1.png"
#define INKY_M_UP_2 "inky_m_up_2.png"
#define INKY_M_DOWN_1 "inky_m_down_1.png"
#define INKY_M_DOWN_2 "inky_m_down_2.png"
#define INKY_M_LEFT_1 "inky_m_left_1.png"
#define INKY_M_LEFT_2 "inky_m_left_2.png"
#define INKY_M_RIGHT_1 "inky_m_right_1.png"
#define INKY_M_RIGHT_2 "inky_m_right_2.png"
#define CLYDE_M_UP_1 "clyde_m_up_1.png"
#define CLYDE_M_UP_2 "clyde_m_up_2.png"
#define CLYDE_M_DOWN_1 "clyde_m_down_1.png"
#define CLYDE_M_DOWN_2 "clyde_m_down_2.png"
#define CLYDE_M_LEFT_1 "clyde_m_left_1.png"
#define CLYDE_M_LEFT_2 "clyde_m_left_2.png"
#define CLYDE_M_RIGHT_1 "clyde_m_right_1.png"
#define CLYDE_M_RIGHT_2 "clyde_m_right_2.png"
#define WHITE_M_UP_1 "white_m_up_1.png"
#define WHITE_M_UP_2 "white_m_up_2.png"
#define WHITE_M_DOWN_1 "white_m_down_1.png"
#define WHITE_M_DOWN_2 "white_m_down_2.png"
#define WHITE_M_LEFT_1 "white_m_left_1.png"
#define WHITE_M_LEFT_2 "white_m_left_2.png"
#define WHITE_M_RIGHT_1 "white_m_right_1.png"
#define WHITE_M_RIGHT_2 "white_m_right_2.png"
#define PACMANCHAR "pacman_char.png"
#define BLINKYCHAR "blinky_char.png"
#define PINKYCHAR "pinky_char.png"
#define INKYCHAR "inky_char.png"
#define CLYDECHAR "clyde_char.png"
#define ARROWS "arrows.png"
#define WASD "wasd.png"
#define PACDOT_C "pacdot_c.png"
#define PACDOT_M "pacdot_m.png"
#define BLUE_C_1 "blue_c_1.png"
#define BLUE_C_2 "blue_c_2.png"
#define WHITE_C_1 "white_c_1.png"
#define WHITE_C_2 "white_c_2.png"
#define BLUE_M_RIGHT_1 "blue_m_right_1.png"
#define BLUE_M_RIGHT_2 "blue_m_right_2.png"
#define PONG_AI "pong_ai.png"
#define PONG_P "pong_player.png"
#define PONG_BALL "pong_ball.png"
#define PAUSEIMG "pause.png"
#define PLAYIMG "play.png"
#define NO "no.png"
#define YES "yes.png"
#define PACMAN_C_DEATH_1 "death_c_1.png"
#define PACMAN_C_DEATH_2 "death_c_2.png"
#define PACMAN_C_DEATH_3 "death_c_3.png"
#define PACMAN_C_DEATH_4 "death_c_4.png"
#define PACMAN_C_DEATH_5 "death_c_5.png"
#define PACMAN_C_DEATH_6 "death_c_6.png"
#define PACMAN_C_DEATH_7 "death_c_7.png"
#define PACMAN_C_DEATH_8 "death_c_8.png"
#define PACMAN_C_DEATH_9 "death_c_9.png"
#define PACMAN_C_DEATH_10 "death_c_10.png"
#define PACMAN_C_DEATH_11 "death_c_11.png"
#define MAZE1 "modern_maze_1.png"
#define MAZE2 "classic_maze_1.png"

// SOUNDS
#define CHOMP "pacman_chomp.mp3"
#define PONGHIT "pong_hit.mp3"
#define PONGWALL "pong_wall.mp3"
#define GAMEOVERPONG "game_overpong.wav"
#define GAMEOVERPACMAN "pacman_gameover.mp3"
#define WINPACMAN "pacman_win.mp3"
#define TIEPACMAN "pacman_tie.mp3"
#define CHOMPGHOST "pacman_eatghost.wav"
#define CHOMPFRUIT "pacman_eatfruit.wav"