#pragma once
#include "../Data Types/dstring.h"
#include "../Data Types/dvector2D.h"
#include "../Logging/logging.h"
#include "platform.h"

typedef struct REWindowSettings REWindowSettings;
typedef struct RELibrary RELibrary;
typedef struct REPlatform REPlatform;
typedef struct REWindow REWindow;
typedef struct REContextSettings REContextSettings;
typedef struct REContext REContext;

struct REWindowSettings
{
	DString name;
	DVector2D pos;
	DVector2D size;
	int style;
};

struct REContextSettings
{
	int minor, major, profile;
};

struct REPlatform
{
	DBool(*platform_init)();
	void(*platform_terminate)();
	DBool(*platform_create_window)(REWindow*, REWindowSettings*);
	void(*platform_poll_events)();
	void(*platform_free_window)(REWindow*);
	DBool(*platform_make_current)(REWindow*);
	void(*platform_swap_buffers)(REWindow*);
};

struct RELibrary
{
	REPlatform platform;
	REWindow* mainWindow;

	PLATFORM_LIBRARY
};

struct REContext
{
	REContextSettings* settings;

	PLATFORM_CONTEXT
};

struct REWindow
{
	REContext* context;
	REWindow* share;
	REWindowSettings* settings;
	DBool fullscreen;
	DBool running;

	PLATFORM_WINDOW
};

RELibrary relib;

DBool re_init();
void re_terminate();

REWindow* re_create_window(DVector2D size, DString name, DBool fullscreen, REWindow* share);
void re_poll_events();
void re_free_window(REWindow* window);

void re_make_current(REWindow* window);
void re_swap_buffers(REWindow* window);