package com.example.tic_tac_toe;

import android.content.Context;
import android.content.Intent;
import android.view.animation.Animation;
import android.view.animation.Transformation;
import android.widget.ProgressBar;
import android.widget.TextView;

public class ProgressBar_Animation extends Animation {

    private Context context;
    private ProgressBar bar;
    private TextView textView;
    private float from;
    private float to;

    public ProgressBar_Animation(Context context, ProgressBar bar, TextView textView, float from, float to){
        this.context=context;
        this.bar=bar;
        this.textView=textView;
        this.from=from;
        this.to=to;
    }

    @Override
    protected void applyTransformation(float interpolatedTime, Transformation t) {
        super.applyTransformation(interpolatedTime, t);
        float value =from+(to-from)*interpolatedTime;
        bar.setProgress((int)value);
        textView.setText((int)value+" %");

        if(value==to){
            context.startActivity(new Intent(context, HomeActivity.class ));
        }
    }
}
