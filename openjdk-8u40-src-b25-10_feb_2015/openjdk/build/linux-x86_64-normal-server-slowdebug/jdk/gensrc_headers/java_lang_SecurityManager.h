/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class java_lang_SecurityManager */

#ifndef _Included_java_lang_SecurityManager
#define _Included_java_lang_SecurityManager
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     java_lang_SecurityManager
 * Method:    getClassContext
 * Signature: ()[Ljava/lang/Class;
 */
JNIEXPORT jobjectArray JNICALL Java_java_lang_SecurityManager_getClassContext
  (JNIEnv *, jobject);

/*
 * Class:     java_lang_SecurityManager
 * Method:    currentClassLoader0
 * Signature: ()Ljava/lang/ClassLoader;
 */
JNIEXPORT jobject JNICALL Java_java_lang_SecurityManager_currentClassLoader0
  (JNIEnv *, jobject);

/*
 * Class:     java_lang_SecurityManager
 * Method:    classDepth
 * Signature: (Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_java_lang_SecurityManager_classDepth
  (JNIEnv *, jobject, jstring);

/*
 * Class:     java_lang_SecurityManager
 * Method:    classLoaderDepth0
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_java_lang_SecurityManager_classLoaderDepth0
  (JNIEnv *, jobject);

/*
 * Class:     java_lang_SecurityManager
 * Method:    currentLoadedClass0
 * Signature: ()Ljava/lang/Class;
 */
JNIEXPORT jclass JNICALL Java_java_lang_SecurityManager_currentLoadedClass0
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
