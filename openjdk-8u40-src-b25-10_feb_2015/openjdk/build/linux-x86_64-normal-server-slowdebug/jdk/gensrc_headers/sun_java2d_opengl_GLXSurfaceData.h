/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class sun_java2d_opengl_GLXSurfaceData */

#ifndef _Included_sun_java2d_opengl_GLXSurfaceData
#define _Included_sun_java2d_opengl_GLXSurfaceData
#ifdef __cplusplus
extern "C" {
#endif
#undef sun_java2d_opengl_GLXSurfaceData_LOOP_UNKNOWN
#define sun_java2d_opengl_GLXSurfaceData_LOOP_UNKNOWN 0L
#undef sun_java2d_opengl_GLXSurfaceData_LOOP_FOUND
#define sun_java2d_opengl_GLXSurfaceData_LOOP_FOUND 1L
#undef sun_java2d_opengl_GLXSurfaceData_LOOP_NOTFOUND
#define sun_java2d_opengl_GLXSurfaceData_LOOP_NOTFOUND 2L
#undef sun_java2d_opengl_GLXSurfaceData_PBUFFER
#define sun_java2d_opengl_GLXSurfaceData_PBUFFER 2L
#undef sun_java2d_opengl_GLXSurfaceData_FBOBJECT
#define sun_java2d_opengl_GLXSurfaceData_FBOBJECT 5L
#undef sun_java2d_opengl_GLXSurfaceData_PF_INT_ARGB
#define sun_java2d_opengl_GLXSurfaceData_PF_INT_ARGB 0L
#undef sun_java2d_opengl_GLXSurfaceData_PF_INT_ARGB_PRE
#define sun_java2d_opengl_GLXSurfaceData_PF_INT_ARGB_PRE 1L
#undef sun_java2d_opengl_GLXSurfaceData_PF_INT_RGB
#define sun_java2d_opengl_GLXSurfaceData_PF_INT_RGB 2L
#undef sun_java2d_opengl_GLXSurfaceData_PF_INT_RGBX
#define sun_java2d_opengl_GLXSurfaceData_PF_INT_RGBX 3L
#undef sun_java2d_opengl_GLXSurfaceData_PF_INT_BGR
#define sun_java2d_opengl_GLXSurfaceData_PF_INT_BGR 4L
#undef sun_java2d_opengl_GLXSurfaceData_PF_INT_BGRX
#define sun_java2d_opengl_GLXSurfaceData_PF_INT_BGRX 5L
#undef sun_java2d_opengl_GLXSurfaceData_PF_USHORT_565_RGB
#define sun_java2d_opengl_GLXSurfaceData_PF_USHORT_565_RGB 6L
#undef sun_java2d_opengl_GLXSurfaceData_PF_USHORT_555_RGB
#define sun_java2d_opengl_GLXSurfaceData_PF_USHORT_555_RGB 7L
#undef sun_java2d_opengl_GLXSurfaceData_PF_USHORT_555_RGBX
#define sun_java2d_opengl_GLXSurfaceData_PF_USHORT_555_RGBX 8L
#undef sun_java2d_opengl_GLXSurfaceData_PF_BYTE_GRAY
#define sun_java2d_opengl_GLXSurfaceData_PF_BYTE_GRAY 9L
#undef sun_java2d_opengl_GLXSurfaceData_PF_USHORT_GRAY
#define sun_java2d_opengl_GLXSurfaceData_PF_USHORT_GRAY 10L
#undef sun_java2d_opengl_GLXSurfaceData_PF_3BYTE_BGR
#define sun_java2d_opengl_GLXSurfaceData_PF_3BYTE_BGR 11L
/*
 * Class:     sun_java2d_opengl_GLXSurfaceData
 * Method:    initOps
 * Signature: (Lsun/awt/X11ComponentPeer;J)V
 */
JNIEXPORT void JNICALL Java_sun_java2d_opengl_GLXSurfaceData_initOps
  (JNIEnv *, jobject, jobject, jlong);

/*
 * Class:     sun_java2d_opengl_GLXSurfaceData
 * Method:    initPbuffer
 * Signature: (JJZII)Z
 */
JNIEXPORT jboolean JNICALL Java_sun_java2d_opengl_GLXSurfaceData_initPbuffer
  (JNIEnv *, jobject, jlong, jlong, jboolean, jint, jint);

#ifdef __cplusplus
}
#endif
#endif
