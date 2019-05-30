//
// Created by HXD on 2019/5/29.
//

#include "JavaTest.h"

//实现头文件内相关方法
JavaTest::JavaTest(JavaVM *vm, _JNIEnv *env, jobject job) {

    jvm = vm;
    jenv = env;
    jobj = job;
    //获取 jclass
    jclass clz = jenv->GetObjectClass(jobj);
    //判空操作
    if (!clz) {
        return;
    }
    jmid = jenv->GetMethodID(clz, "onError", "(ILjava/lang/String;)V");


}

void JavaTest::onError(int threadThread, int code, const char *msg) {
    if (threadThread == 0) {
        //子线程 必须根据 jvm 获取 jnienv 对象
        JNIEnv *env;
        jvm->AttachCurrentThread(&env, 0);
        jstring jms = env->NewStringUTF(msg);
        env->CallVoidMethod(jobj, jmid, code, jms);
        env->DeleteLocalRef(jms);//释放内存
        jvm->DetachCurrentThread();//释放jvm
    } else if (threadThread == 1) {
        //主线程
        jstring jms = jenv->NewStringUTF(msg);
        jenv->CallVoidMethod(jobj, jmid, code, jms);
        jenv->DeleteLocalRef(jms);//释放内存
    }
}
