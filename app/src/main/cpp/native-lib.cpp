#include <jni.h>
#include "pthread.h"
#include "AndroidLog.h"

//声明一个 线程对象
pthread_t pthread;

//声明回调
void *normalCallBack(void *data) {
    LOGD("线程创建成功")
    //关闭线程
    pthread_exit(&pthread);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hxd_cadddemotwo_MainActivity_ThreadTest(JNIEnv *env, jobject instance) {
    //初始化线程
    pthread_create(&pthread, NULL, normalCallBack, NULL);

}
extern "C"
JNIEXPORT void JNICALL
Java_com_hxd_cadddemotwo_MainActivity_mutexThread(JNIEnv *env, jobject instance) {
}


#include "JavaTest.h"

JavaVM *jvm;
JavaTest *javaTest;
pthread_t workThread;


void *workThreadCallBack(void *data) {
    JavaTest *javaTest = (JavaTest *) (data);
    javaTest->onError(0, 101, "工作线程测试成功");
    pthread_exit(&workThread);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hxd_cadddemotwo_Test_callBackTest(JNIEnv *env, jobject instance) {

    javaTest = new JavaTest(jvm, env, env->NewGlobalRef(instance));
    //    javaTest->onError(1, 100, "主线程测试能否成功");

    pthread_create(&workThread, NULL, workThreadCallBack, javaTest);

}

//重写 jvm 的方法 获取jvm 对象
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {

    JNIEnv *env;
    jvm = vm;
    if (vm->GetEnv((void **) (&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    return JNI_VERSION_1_6;
}