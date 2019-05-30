//
// Created by HXD on 2019/5/29.
//日志打印头文件

#ifndef CADDDEMOTWO_ANDROIDLOG_H
#define CADDDEMOTWO_ANDROIDLOG_H

#endif //CADDDEMOTWO_ANDROIDLOG_H

#include <android/log.h>
#define LOGD(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"韩小呆",FORMAT,##__VA_ARGS__);