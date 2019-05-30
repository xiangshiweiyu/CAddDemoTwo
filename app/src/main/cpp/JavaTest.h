//
// Created by HXD on 2019/5/29.
//
//类似于导包操作
#include "jni.h"

#ifndef CADDDEMOTWO_JAVATEST_H
#define CADDDEMOTWO_JAVATEST_H


class JavaTest {
    //声明属性
public:
    //jvm 对象
    JavaVM *jvm;
    //
    _JNIEnv *jenv;
    //全局对象
    jobject jobj;

    jmethodID jmid;

    //声明构造方法
public:
    JavaTest(JavaVM *vm, _JNIEnv *env, jobject job);
    //回收对象时 调用
    ~ JavaTest();

    /**
     * 0:子线程
     * 1：主线程
     * @param threadThread
     * @param code
     * @param msg
     */
    void onError(int threadThread, int code, const char *msg);
};

#endif //CADDDEMOTWO_JAVATEST_H
