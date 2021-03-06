/*
** Configuration file for standalone Carbon Python.
**
** Note: enabling the switches below is not enough to enable the
** specific features, you may also need different sets of sources.
*/
#define ACCESSOR_CALLS_ARE_FUNCTIONS 1
#define OPAQUE_TOOLBOX_STRUCTS 1
#define TARGET_API_MAC_CARBON 1

#define USE_GUSI2		/* Stdio implemented with GUSI 2 */
#define USE_GUSI
#define WITH_THREAD		/* Use thread support (needs GUSI 2, not GUSI 1) */
#define USE_MSL			/* Use Mw Standard Library (as opposed to Plaugher C libraries) */
#define USE_TOOLBOX		/* Include toolbox modules in core Python */
#define USE_QT			/* Include quicktime modules in core Python */
#define USE_WASTE		/* Include waste module in core Python */
/* #define USE_IMG	       		/* Include img modules in core Python */
/* #define USE_MAC_SHARED_LIBRARY	/* Enable code to add shared-library resources */
/* #define USE_MAC_APPLET_SUPPORT	/* Enable code to run a PYC resource */
/* #define HAVE_DYNAMIC_LOADING		/* Enable dynamically loaded modules */
#define USE_GDBM		/* Include the gdbm module */
#define USE_ZLIB		/* Include the zlib module */
#define USE_IC			/* Include Internet Config module */
#define USE_PYEXPAT		/* Include Pyexpat module */
#define XML_NS 1
#define XML_DTD 1
#define BYTEORDER 4321
#define XML_CONTEXT_BYTES 1024
#define USE_MSL_MALLOC	/* Disable private malloc. Also disables next two defines */
#ifndef USE_MSL_MALLOC
/* #define USE_MALLOC_DEBUG			/* Enable range checking and other malloc debugging */
#endif
#define WITHOUT_FRAMEWORKS /* Use old-style Universal Header includes, not Carbon/Carbon.h */

#ifdef USE_MSL
#define MSL_USE_PRECOMPILED_HEADERS 0	/* Don't use precomp headers: we include our own */
#include <ansi_prefix.mac.h>
#endif
/* Missing declarations. Should these go to pyport.h? */
#ifdef USE_GUSI2
#include <stdio.h>
extern int fileno(FILE *);
#endif
#ifndef Py_DEBUG
#define NDEBUG
#endif
