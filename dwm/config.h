/* See LICENSE file for copyright and license details. */

/* appearance */
static const int GAP_PX             = 12;		/* gap size */
static const int BORDER_PX          = 2;		/* border pixel of windows  */
static const int start_with_gaps	= 1;
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "scientifica","Fixed:pixelsize=13", "hack:pixelsize=9:antialias=false", "mplus:pixelsize=10","inconsolata:pixelsize=11","ipamincho:pixelsize=8:antialias=false", "symbola:size=10","unifont:pixelsize=5:antialias=false" };

/* pywal colors */
#include "/home/void/.cache/wal/colors-wal-dwm.h"
#include "selfrestart.c"
#include "mpdcontrol.c"
#include "fibonacci.c"
#include "exresize.c"

/* tagging */
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class          instance    title        tags mask     iscentered,    isfloating   monitor */
	{ "Gimp",         NULL,       NULL,        0,           	0,             1,           -1 },
	{ "tint2",        NULL,       NULL,        0,               0, 			   0,           -1 },
	{ "Firefox",      NULL,       NULL,        0,               0, 			   0,           -1 },
	{ "Qutebrowser",  NULL,       NULL,        0,               0, 			   0,           -1 },
	{ "mpv",          NULL,       NULL,        0,           	1,             1,           -1 },
	{ "feh",          NULL,       NULL,        0,           	1,             1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ /*"[]="*/"0",      tile },    /* first entry is default */
	{ /*"><>"*/"0",      NULL },    /* no layout function means floating behavior */
	{ /*"[M]"*/"0",      monocle },
	{ /*"|M|"*/"0",      centeredmaster },
	{ /*">M>"*/"0",      centeredfloatingmaster },

};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *menu[] 		   = { "rofi", "-show", "run", NULL };
static const char *term[]          = { "st", NULL };
static const char *ranger[]        = { "st", "-e", "ranger", NULL };
static const char *ncmpcpp[]       = { "st", "-g", "135x35", "-t", "music", "-e", "ncmpcpp", NULL };
static const char *alsa[]          = { "st", "-e", "alsamixer", NULL };
static const char *shutdown[]      = { "sudo", "shutdown", "-h", "now", NULL };
static const char *lock[]          = { "st", "-e", "~/Scripts/lock/lock", NULL };
static const char *shot[]          = { "/home/void/Scripts/shot", NULL };
static const char *killffmpeg[]    = { "killall", "ffmpeg", NULL };
static const char *ffmpeg[]        = { "ffmpeg", "-f", "x11grab", "-s", "1280x800", "-r", "25", "-i", ":0.0", "output.mkv", NULL };
static const char *web[]           = { "qutebrowser", NULL };
static const char *fire[]          = { "firefox", NULL };
static const char *gimp[]          = { "gimp", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = {"st","-t",scratchpadname,"-g","120x34",NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = menu } },
	{ MODKEY,                       XK_Return, spawn,          {.v = term } },
	{ MODKEY,                       XK_q,      spawn,          {.v = web } },
	{ MODKEY,                       XK_n,      spawn,          {.v = ncmpcpp } },
	{ MODKEY,                       XK_r,      spawn,          {.v = ranger } },
	{ MODKEY,                       XK_a,      spawn,          {.v = alsa } },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = fire } },
	{ MODKEY,                       XK_F8,     spawn,          {.v = shot } },
	{ MODKEY,                       XK_i,      spawn,          {.v = lock } },
	{ MODKEY|ShiftMask,             XK_g,      spawn,          {.v = gimp } },
	{ MODKEY,                       XK_g,      togglegaps,     {0} },
	{ MODKEY,                       XK_F9,     spawn,          {.v = killffmpeg } },
	{ MODKEY|ShiftMask,             XK_F9,     spawn,          {.v = ffmpeg } },
	{ MODKEY|ShiftMask,             XK_r,      self_restart,   {0} },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
/*  { MODKEY,                       XK_b,      togglebar,      {0} },*/
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_x,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_x,      spawn,          {.v = shutdown } },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_F1,     mpdchange,      {.i = -1 } },
	{ MODKEY,                       XK_F2,     mpdchange,      {.i = +1 } },
	{ MODKEY,                       XK_Escape, mpdcontrol,     {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

	{ MODKEY,                       XK_KP_7,   explace,                {.ui = EX_NW }},
	{ MODKEY,                       XK_KP_8,   explace,                {.ui = EX_N  }},
	{ MODKEY,                       XK_KP_9,   explace,                {.ui = EX_NE }},
	{ MODKEY,                       XK_KP_4,   explace,                {.ui = EX_W  }},
	{ MODKEY,                       XK_KP_5,   explace,                {.ui = EX_C  }},
	{ MODKEY,                       XK_KP_6,   explace,                {.ui = EX_E  }},
	{ MODKEY,                       XK_KP_1,   explace,                {.ui = EX_SW }},
	{ MODKEY,                       XK_KP_2,   explace,                {.ui = EX_S  }},
	{ MODKEY,                       XK_KP_3,   explace,                {.ui = EX_SE }},
	
	{ MODKEY|ShiftMask,             XK_KP_8,   exresize,               {.v = (int []){   0, 25 }}},
	{ MODKEY|ShiftMask,             XK_KP_2,   exresize,               {.v = (int []){   0, -25 }}},
	{ MODKEY|ShiftMask,             XK_KP_6,   exresize,               {.v = (int []){  25, 0 }}},
	{ MODKEY|ShiftMask,             XK_KP_4,   exresize,               {.v = (int []){ -25, 0 }}},
	{ MODKEY|ShiftMask,             XK_KP_5,   exresize,               {.v = (int []){  25, 25 }}},
	{ MODKEY|ShiftMask|ControlMask, XK_KP_5,   exresize,               {.v = (int []){ -25, -25 }}},
	
	{ MODKEY|ControlMask,           XK_KP_6,   togglehorizontalexpand, {.i = +1} },
	{ MODKEY|ControlMask,           XK_KP_3,   togglehorizontalexpand, {.i =  0} },
	{ MODKEY|ControlMask,           XK_KP_4,   togglehorizontalexpand, {.i = -1} },
	{ MODKEY|ControlMask,           XK_KP_8,   toggleverticalexpand,   {.i = +1} },
	{ MODKEY|ControlMask,           XK_KP_1,   toggleverticalexpand,   {.i =  0} },
	{ MODKEY|ControlMask,           XK_KP_2,   toggleverticalexpand,   {.i = -1} },
	{ MODKEY|ControlMask,           XK_KP_9,   togglemaximize,         {.i = -1} },
	{ MODKEY|ControlMask,           XK_KP_7,   togglemaximize,         {.i = +1} },
	{ MODKEY|ControlMask,           XK_KP_5,   togglemaximize,         {.i =  0} },

};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = term } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

