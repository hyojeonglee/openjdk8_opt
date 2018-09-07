/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class sun_management_Flag */

#ifndef _Included_sun_management_Flag
#define _Included_sun_management_Flag
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     sun_management_Flag
 * Method:    getAllFlagNames
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_sun_management_Flag_getAllFlagNames
  (JNIEnv *, jclass);

/*
 * Class:     sun_management_Flag
 * Method:    getFlags
 * Signature: ([Ljava/lang/String;[Lsun/management/Flag;I)I
 */
JNIEXPORT jint JNICALL Java_sun_management_Flag_getFlags
  (JNIEnv *, jclass, jobjectArray, jobjectArray, jint);

/*
 * Class:     sun_management_Flag
 * Method:    getInternalFlagCount
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_sun_management_Flag_getInternalFlagCount
  (JNIEnv *, jclass);

/*
 * Class:     sun_management_Flag
 * Method:    setLongValue
 * Signature: (Ljava/lang/String;J)V
 */
JNIEXPORT void JNICALL Java_sun_management_Flag_setLongValue
  (JNIEnv *, jclass, jstring, jlong);

/*
 * Class:     sun_management_Flag
 * Method:    setBooleanValue
 * Signature: (Ljava/lang/String;Z)V
 */
JNIEXPORT void JNICALL Java_sun_management_Flag_setBooleanValue
  (JNIEnv *, jclass, jstring, jboolean);

/*
 * Class:     sun_management_Flag
 * Method:    setStringValue
 * Signature: (Ljava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_sun_management_Flag_setStringValue
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     sun_management_Flag
 * Method:    initialize
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_sun_management_Flag_initialize
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
