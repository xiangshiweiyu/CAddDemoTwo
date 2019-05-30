package com.hxd.cadddemotwo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    private Test test;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        test = new Test();

        test.setOnErrorListener(new Test.OnErrorListener() {
            @Override
            public void onError(int code, String content) {

                Log.d("韩小呆", "code: " + code + "content: " + content);
            }
        });

    }

    public void onClick(View view) {
        Log.d("韩小呆", "点击成功");
        test.callBackTest();
    }
}
