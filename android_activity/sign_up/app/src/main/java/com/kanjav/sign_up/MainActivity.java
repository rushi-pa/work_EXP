package com.kanjav.sign_up;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.LinearInterpolator;
import android.view.animation.RotateAnimation;
import android.widget.ImageView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    public void callIntent(View view) {
        Intent intent = null;
        switch (view.getId()) {
            case R.id.signup:
                intent = new Intent(com.kanjav.sign_up.MainActivity.this, sign_up.class);
                startActivity(intent);
                break;
            case R.id.GetStarted:
                intent = new Intent(this, sign_in.class);
                startActivity(intent);
                break;
        }
    }

    public void onStart() {

        super.onStart();
        animation();
    }

    public void animation() {
        ImageView view2 =  (ImageView) findViewById(R.id.imageView);

        RotateAnimation anim = new RotateAnimation(0.0f, 360.0f, Animation.RELATIVE_TO_SELF, 0.5f, Animation.RELATIVE_TO_SELF, 0.5f);

        //Setup anim with desired properties
        anim.setInterpolator(new LinearInterpolator());
        anim.setRepeatCount(5); //Repeat animation indefinitely
        anim.setDuration(400); //Put desired duration per anim cycle here, in milliseconds

        //Start animation
        view2.startAnimation(anim);
        //Later on, use view.setAnimation(null) to stop it
    }
    }

