/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class sun_java2d_x11_X11PMBlitLoops */

#ifndef _Included_sun_java2d_x11_X11PMBlitLoops
#define _Included_sun_java2d_x11_X11PMBlitLoops
#ifdef __cplusplus
extern "C" {
#endif
#undef sun_java2d_x11_X11PMBlitLoops_TRACELOG
#define sun_java2d_x11_X11PMBlitLoops_TRACELOG 1L
#undef sun_java2d_x11_X11PMBlitLoops_TRACETIMESTAMP
#define sun_java2d_x11_X11PMBlitLoops_TRACETIMESTAMP 2L
#undef sun_java2d_x11_X11PMBlitLoops_TRACECOUNTS
#define sun_java2d_x11_X11PMBlitLoops_TRACECOUNTS 4L
/*
 * Class:     sun_java2d_x11_X11PMBlitLoops
 * Method:    nativeBlit
 * Signature: (JJJLsun/java2d/pipe/Region;IIIIII)V
 */
JNIEXPORT void JNICALL Java_sun_java2d_x11_X11PMBlitLoops_nativeBlit
  (JNIEnv *, jobject, jlong, jlong, jlong, jobject, jint, jint, jint, jint, jint, jint);

/*
 * Class:     sun_java2d_x11_X11PMBlitLoops
 * Method:    updateBitmask
 * Signature: (Lsun/java2d/SurfaceData;Lsun/java2d/SurfaceData;Z)V
 */
JNIEXPORT void JNICALL Java_sun_java2d_x11_X11PMBlitLoops_updateBitmask
  (JNIEnv *, jclass, jobject, jobject, jboolean);

#ifdef __cplusplus
}
#endif
#endif
