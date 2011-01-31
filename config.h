/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-misc-fixed-medium-r-*-*-12-*-*-*-*-60-iso10646-1";
static const char normbordercolor[] = "#eeeeee";
static const char normbgcolor[]     = "#eeeeee";
static const char normfgcolor[]     = "#555555";
static const char selbordercolor[]  = "#0066ff";
static const char selbgcolor[]      = "#0066ff";
static const char selfgcolor[]      = "#ffffff";
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5" };

static const Rule rules[] = {
	/* class            instance    title       tags mask     isfloating   monitor */
	{ "Keepassx",       NULL,       NULL,       0,              True,       -1 },
	{ "MPlayer",        NULL,       NULL,       0,              True,       -1 },
	{ "Wine",           NULL,       NULL,       0,              False,      -1 },
	{ "XFontSel",       NULL,       NULL,       0,              True,       -1 },
	{ "Gajim.py",       NULL,       NULL,       0,              True,       -1 },
	{ "Nitrogen",       NULL,       NULL,       0,              True,       -1 },
	{ "Galculator",     NULL,       NULL,       0,              True,       -1 },
	{ "stalonetray",    NULL,       NULL,       1 << 4,         True,       -1 },
	{ "Gimp",           NULL,       NULL,       1 << 3,         True,       -1 },
	{ "Nautilus",       NULL,       NULL,       1 << 2,         False,      -1 },
	{ "Nautilus-cd-burner", NULL,   NULL,       0,              True,       -1 },
	{  NULL,            NULL, "File Management Preferences", 0, True        -1 },
	{  NULL,          "file_properties",  NULL, 0,              True        -1 },
	{ "Tabbed",         NULL,       NULL,       1 << 1,         False,      -1 },
	{ "Chromium",       NULL,       NULL,       1 << 1,         False,      -1 },
	{ "Namoroka",       NULL,       NULL,       1 << 1,         False,      -1 },
	{ "XCalc",          NULL,       NULL,       0,              True,       -1 },
	{ "Vlc",            NULL,       NULL,       0,              True,       -1 },
	{  NULL,           "wicd-client.py", NULL,  0,              True,       -1 },
	{  NULL,            NULL,      "alsamixer", 0,              True,       -1 },
	{  NULL,           "gnome-alsamixer", NULL, 0,              True,       -1 },
	{ "Worker",         NULL,       NULL,       1 << 2,         False,      -1 },
	{ "Worker",        "Copy",      NULL,       0,              True,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[M]",      monocle },   /* first entry is default */
	{ "[T]",      tile },
	{ "[F]",      NULL },      /* >(((°> no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "xterm", NULL };
//static const char *termcmd[]  = { "gnome-terminal", NULL };

static Key keys[] = {
	/* for octal keycodes see /usr/share/X11/XKeysymDB */
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          SHCMD("exec gmrun") },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },                   /* toggle statusbar */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },            /* cycle clients on current tag */
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },            /* cycle clients on current tag */
	{ Mod1Mask,                     XK_Tab,    focusstack,     {.i = +1 } },            /* cycle clients windows-style */
	{ Mod1Mask|ShiftMask,           XK_Tab,    focusstack,     {.i = -1 } },            /* cycle clients windows-style */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },          /* shrink master column */
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },          /* expand master column */
	{ MODKEY,                       XK_Return, zoom,           {0} },                   /* toggle client to master column */
	{ MODKEY,                       XK_Tab,    view,           {0} },                   /* toggle last tag */
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },                   /* kill selected client */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },    /* set tile layout */
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[2]} },    /* set float layout */
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[0]} },    /* set monocle layout */
	{ MODKEY,                       XK_space,  setlayout,      {0} },                   /* toggle last layout */
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },                   /* toggle floating on selected client */
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },           /* view all tags */
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },           /* focused client is tagged all */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },            /* focus prev monitor (xinerama) */
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },            /* focus next monitor (xinerama) */
	{ MODKEY,                       XK_z,      focusmon,       {.i = +1 } },            /* focus next monitor (xinerama) */
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },            /* tag client to prev monitor */
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },            /* tag client to next monitor */
	{ MODKEY|ShiftMask,             XK_z,      tagmon,         {.i = +1 } },            /* tag client to next monitor */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,                       XK_q,      quit,           {0} },                       /* restart dwm on-the-fly */
	{ MODKEY|ShiftMask,             XK_q,      spawn,          SHCMD("killall startdwm") }, /* kill the dwm session */
	{ MODKEY,                       XK_s,      spawn,          SHCMD("exec xterm -e bash -c 'screen -dRR -S $HOSTNAME'") },
	{ MODKEY,                       XK_e,      spawn,          SHCMD("exec nautilus") },
	{ MODKEY,                       XK_n,      spawn,          SHCMD("exec wicd-client -n") },
	{ MODKEY,                       XK_c,      spawn,          SHCMD("xcalc") },
	{ MODKEY,                       XK_w,      spawn,          SHCMD("exec tabbed-vimprobable2") },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("exec chromium") },
	{ MODKEY,                       XK_v,      spawn,          SHCMD("exec gnome-alsamixer") },
	{ Mod1Mask|ControlMask|ShiftMask,  XK_k,   spawn,          SHCMD("xkill") },
	{ Mod1Mask|ControlMask,         XK_l,      spawn,          SHCMD("slock") },
	{ Mod1Mask|ControlMask,         XK_Delete, spawn,          SHCMD("sudo shutdown -r now") },
	{ Mod1Mask|ControlMask,         XK_Insert, spawn,          SHCMD("sudo shutdown -h now") },
	{ 0,                            XK_Print,  spawn,          SHCMD("scrot %Y%m%d-%H.%M.%S.png -t 280x175 -e 'mv $f $m ~/tmp/'") },
	{ 0|ShiftMask,                  XK_Print,  spawn,          SHCMD("scrot %Y%m%d-%H.%M.%S.png -t 280x175 -d 5 -e 'mv $f $m ~/tmp/'") },
	{ 0,                            0x1008FF11, spawn,         SHCMD("dvolbar --decrease 6") },     /* fn hotkey: vol down */
	{ 0,                            0x1008FF12, spawn,         SHCMD("dvolbar --toggle") },         /* fn hotkey: vol mute */
	{ 0,                            0x1008FF13, spawn,         SHCMD("dvolbar --increase 6") },     /* fn hotkey: vol up */
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        focusstack,     {.i = -1 } },
	{ ClkWinTitle,          0,              Button2,        killclient,     {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

