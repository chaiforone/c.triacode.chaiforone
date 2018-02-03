#ifndef TRIACODECONFIG_H_INCLUDED
#define TRIACODECONFIG_H_INCLUDED

#include <limits.h>
#include <stddef.h>


/* #define TRIA_CODE_USE_C89 */

/*
** By default, TRIA CODE on Windows use (some) specific Windows features
*/
#if !defined(TRIA_CODE_USE_C89) && defined(_WIN32) && !defined(_WIN32_WCE)
#define TRIA_CODE_USE_WINDOWS  /* enable goodies for regular Windows */
#endif


#if defined(TRIA_CODE_USE_WINDOWS)
#define TRIA_CODE_DL_DLL	/* enable support for DLL */
#define TRIA_CODE_USE_C89	/* broadly, Windows is C89 */
#endif


#if defined(TRIA_CODE_USE_LINUX)
#define TRIA_CODE_USE_POSIX
#define TRIA_CODE_USE_DLOPEN		/* needs an extra library: -ldl */
#define TRIA_CODE_USE_READLINE	/* needs some extra libraries */
#endif


#if defined(TRIA_CODE_USE_MACOSX)
#define TRIA_CODE_USE_POSIX
#define TRIA_CODE_USE_DLOPEN		/* MacOS does not need -ldl */
#define TRIA_CODE_USE_READLINE	/* needs an extra library: -lreadline */
#endif

/*
@@ TRIA_CODE_C89_NUMBERS ensures that TRIA_CODE uses the largest types available for
** C89 ('long' and 'double'); Windows always has '__int64', so it does
** not need to use this case.
*/
#if defined(TRIA_CODE_USE_C89) && !defined(LUA_USE_WINDOWS)
#define TRIA_CODE_C89_NUMBERS
#endif

/*
@@ TRIA_CODE_API is a mark for all core API functions.
@@ TRIA_CODE_LIB_API is a mark for all auxiliary library functions.
@@ TRIA_CODE_MOD_API is a mark for all standard library opening functions.
** CHANGE them if you need to define those functions in some special way.
** For instance, if you want to create one Windows DLL with the core and
** the libraries, you may want to use the following definition (define
** TRIA_CODE_BUILD_AS_DLL to get it).
*/
#if defined(TRIA_CODE_BUILD_AS_DLL)	/* { */

#if defined(TRIA_CODE_CORE) || defined(TRIA_CODE_LIB)	/* { */
#define TRIA_CODE_API __declspec(dllexport)
#else						/* }{ */
#define TRIA_CODE_API __declspec(dllimport)
#endif						/* } */

#else				/* }{ */

#define TRIA_CODE_API		extern

#endif				/* } */


#endif // TRIACODECONFIG_H_INCLUDED
