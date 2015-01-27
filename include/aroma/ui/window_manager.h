/********************************************************************[libaroma]*
 * Copyright (C) 2011-2015 Ahmad Amarullah (http://amarullz.com/)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *______________________________________________________________________________
 *
 * Filename    : window_manager.h
 * Description : libaroma window manager
 *
 * + This is part of libaroma, an embedded ui toolkit.
 * + 26/01/15 - Author(s): Ahmad Amarullah
 *
 */
#ifndef __libaroma_aroma_h__
  #error "Include <aroma.h> instead."
#endif
#ifndef __libaroma_window_manager_h__
#define __libaroma_window_manager_h__

/* defines */
#define LIBAROMA_WM_MSG_UNHANDLED       0x0
#define LIBAROMA_WM_MSG_HANDLED         0x1
#define LIBAROMA_WM_MSG_EXIT            0x2

#define LIBAROMA_WM_FLAG_RESET_COLOR    0x1
#define LIBAROMA_WM_FLAG_RESET_THEME    0x2

#define LIBAROMA_WM_FLAG_THEME_PNG9P    0x1
#define LIBAROMA_WM_FLAG_THEME_WMFREE   0x2

/*
 * Structure   : _LIBAROMA_WM
 * Typedef     : LIBAROMA_WM, * LIBAROMA_WMP
 * Descriptions: window manager structure
 */
typedef struct _LIBAROMA_WM LIBAROMA_WM;
typedef struct _LIBAROMA_WM * LIBAROMA_WMP;

/*
 * Typedef     : LIBAROMA_WMCB_*
 * Descriptions: window manager callback
 */
typedef byte (*LIBAROMA_WMCB_MESSAGE_HANDLER) \
  (LIBAROMA_WMP, LIBAROMA_MSGP);
typedef void (*LIBAROMA_WMCB_RESET_HANDLER) \
  (LIBAROMA_WMP, byte flags);

/*
 * Structure   : _LIBAROMA_WM
 * Typedef     : LIBAROMA_WM, * LIBAROMA_WMP
 * Descriptions: window manager structure
 */
struct _LIBAROMA_WM{
  LIBAROMA_SARRAYP theme; /* themeset */
  LIBAROMA_SARRAYP color; /* colorset */
  
  /* hooker callbacks */
  LIBAROMA_WMCB_MESSAGE_HANDLER message_handler;
  LIBAROMA_WMCB_RESET_HANDLER reset_handler;
  
  /* canvas location */
  int x;
  int y;
  int w;
  int h;
  
  /* message state */
  byte client_started;
};

/*
 * Structure   : _LIBAROMA_WM_THEME
 * Typedef     : LIBAROMA_WM_THEME, * LIBAROMA_WM_THEMEP
 * Descriptions: theme structure
 */
typedef struct _LIBAROMA_WM_THEME LIBAROMA_WM_THEME;
typedef struct _LIBAROMA_WM_THEME * LIBAROMA_WM_THEMEP;
struct _LIBAROMA_WM_THEME{
  LIBAROMA_CANVASP canvas;
  byte theme_flags;
  int dpi;
};

/*
 * Function    : libaroma_wm_reset
 * Return Value: byte
 * Descriptions: reset theme and colorset
 */
byte libaroma_wm_reset(byte reset_flag);

/*
 * Function    : libaroma_wm_set_workspace
 * Return Value: byte
 * Descriptions: set window workspace size
 */
byte libaroma_wm_set_workspace(int x, int y, int w, int h);

/*
 * Function    : libaroma_wm_set_message_handler
 * Return Value: byte
 * Descriptions: set message handler
 */
byte libaroma_wm_set_message_handler(
    LIBAROMA_WMCB_MESSAGE_HANDLER callback);

/*
 * Function    : libaroma_wm_set_reset_handler
 * Return Value: byte
 * Descriptions: set theme reset handler
 */
byte libaroma_wm_set_reset_handler(
    LIBAROMA_WMCB_RESET_HANDLER callback);

/*
 * Function    : libaroma_wm_sync
 * Return Value: byte
 * Descriptions: sync window workspace
 */
byte libaroma_wm_sync(int x, int y, int w, int h);

/*
 * Function    : libaroma_wm_canvas
 * Return Value: LIBAROMA_CANVASP
 * Descriptions: request window drawing canvas
 */
LIBAROMA_CANVASP libaroma_wm_canvas(int x, int y, int w, int h);

/*
 * Function    : libaroma_wm_client_start
 * Return Value: void
 * Descriptions: start window client message
 */
byte libaroma_wm_client_start();

/*
 * Function    : libaroma_wm_client_stop
 * Return Value: byte
 * Descriptions: stop window client message
 */
byte libaroma_wm_client_stop();

/*
 * Function    : libaroma_wm_getmessage
 * Return Value: byte
 * Descriptions: get window manager client message
 */
byte libaroma_wm_getmessage(LIBAROMA_MSGP msg);

/*
 * Function    : libaroma_wm_set_theme
 * Return Value: byte
 * Descriptions: set theme
 */
byte libaroma_wm_set_theme(
    char * name,
    LIBAROMA_CANVASP canvas,
    byte theme_flags,
    int dpi);

/*
 * Function    : libaroma_wm_set_theme_stream
 * Return Value: byte
 * Descriptions: set theme from stream
 */
byte libaroma_wm_set_theme_stream(
    char * name,
    LIBAROMA_STREAMP stream,
    byte freestream,
    int dpi);

/*
 * Function    : libaroma_wm_get_theme
 * Return Value: LIBAROMA_WM_THEMEP
 * Descriptions: get theme
 */
LIBAROMA_WM_THEMEP libaroma_wm_get_theme(char * name);

/*
 * Function    : libaroma_wm_draw_theme
 * Return Value: byte
 * Descriptions: draw theme into canvas
 */
byte libaroma_wm_draw_theme(
    LIBAROMA_CANVASP dest, char * name,
    int dx, int dy, int dw, int dh,
    LIBAROMA_PNG9_PADP padding);

/*
 * Function    : libaroma_wm_set_color
 * Return Value: byte
 * Descriptions: set colorset
 */
byte libaroma_wm_set_color(char * name, word color);

/*
 * Function    : libaroma_wm_get_color
 * Return Value: word
 * Descriptions: get colorset
 */
word libaroma_wm_get_color(char * name);

#endif /* __libaroma_window_manager_h__ */