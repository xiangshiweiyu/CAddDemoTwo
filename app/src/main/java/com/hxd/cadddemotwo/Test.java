package com.hxd.cadddemotwo;

public class Test {

    static {
        System.loadLibrary("native-lib");
    }

    private OnErrorListener mOnErrorListener;

    public void setOnErrorListener(OnErrorListener onErrorListener) {
        mOnErrorListener = onErrorListener;
    }

    public void onError(int code, String content) {

        if (mOnErrorListener != null) {
            mOnErrorListener.onError(code, content);
        }
    }


    public interface OnErrorListener {
        void onError(int code, String content);
    }

    public native void callBackTest();
}
