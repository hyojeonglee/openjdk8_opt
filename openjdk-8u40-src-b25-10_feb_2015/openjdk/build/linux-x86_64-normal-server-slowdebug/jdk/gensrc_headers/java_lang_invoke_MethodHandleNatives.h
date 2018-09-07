/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class java_lang_invoke_MethodHandleNatives */

#ifndef _Included_java_lang_invoke_MethodHandleNatives
#define _Included_java_lang_invoke_MethodHandleNatives
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    init
 * Signature: (Ljava/lang/invoke/MemberName;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_java_lang_invoke_MethodHandleNatives_init
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    expand
 * Signature: (Ljava/lang/invoke/MemberName;)V
 */
JNIEXPORT void JNICALL Java_java_lang_invoke_MethodHandleNatives_expand
  (JNIEnv *, jclass, jobject);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    resolve
 * Signature: (Ljava/lang/invoke/MemberName;Ljava/lang/Class;)Ljava/lang/invoke/MemberName;
 */
JNIEXPORT jobject JNICALL Java_java_lang_invoke_MethodHandleNatives_resolve
  (JNIEnv *, jclass, jobject, jclass);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    getMembers
 * Signature: (Ljava/lang/Class;Ljava/lang/String;Ljava/lang/String;ILjava/lang/Class;I[Ljava/lang/invoke/MemberName;)I
 */
JNIEXPORT jint JNICALL Java_java_lang_invoke_MethodHandleNatives_getMembers
  (JNIEnv *, jclass, jclass, jstring, jstring, jint, jclass, jint, jobjectArray);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    objectFieldOffset
 * Signature: (Ljava/lang/invoke/MemberName;)J
 */
JNIEXPORT jlong JNICALL Java_java_lang_invoke_MethodHandleNatives_objectFieldOffset
  (JNIEnv *, jclass, jobject);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    staticFieldOffset
 * Signature: (Ljava/lang/invoke/MemberName;)J
 */
JNIEXPORT jlong JNICALL Java_java_lang_invoke_MethodHandleNatives_staticFieldOffset
  (JNIEnv *, jclass, jobject);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    staticFieldBase
 * Signature: (Ljava/lang/invoke/MemberName;)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_java_lang_invoke_MethodHandleNatives_staticFieldBase
  (JNIEnv *, jclass, jobject);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    getMemberVMInfo
 * Signature: (Ljava/lang/invoke/MemberName;)Ljava/lang/Object;
 */
JNIEXPORT jobject JNICALL Java_java_lang_invoke_MethodHandleNatives_getMemberVMInfo
  (JNIEnv *, jclass, jobject);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    getConstant
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_java_lang_invoke_MethodHandleNatives_getConstant
  (JNIEnv *, jclass, jint);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    setCallSiteTargetNormal
 * Signature: (Ljava/lang/invoke/CallSite;Ljava/lang/invoke/MethodHandle;)V
 */
JNIEXPORT void JNICALL Java_java_lang_invoke_MethodHandleNatives_setCallSiteTargetNormal
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    setCallSiteTargetVolatile
 * Signature: (Ljava/lang/invoke/CallSite;Ljava/lang/invoke/MethodHandle;)V
 */
JNIEXPORT void JNICALL Java_java_lang_invoke_MethodHandleNatives_setCallSiteTargetVolatile
  (JNIEnv *, jclass, jobject, jobject);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    registerNatives
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_java_lang_invoke_MethodHandleNatives_registerNatives
  (JNIEnv *, jclass);

/*
 * Class:     java_lang_invoke_MethodHandleNatives
 * Method:    getNamedCon
 * Signature: (I[Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_java_lang_invoke_MethodHandleNatives_getNamedCon
  (JNIEnv *, jclass, jint, jobjectArray);

#ifdef __cplusplus
}
#endif
#endif
