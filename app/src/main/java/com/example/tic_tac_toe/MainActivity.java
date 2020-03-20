package com.example.tic_tac_toe;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.WindowManager;
import android.widget.ProgressBar;
import android.widget.TextView;
public class MainActivity extends AppCompatActivity {
    ProgressBar bar;
    TextView textview;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,WindowManager.LayoutParams.FLAG_FULLSCREEN);
        bar=findViewById(R.id.progress_bar);
        textview=findViewById(R.id.percent);
        bar.setMax(100);
        bar.setScaleY(3f);
        progressAnimation();
    }
    public void progressAnimation(){
        ProgressBar_Animation min = new ProgressBar_Animation(this, bar, textview, 0f, 100f );
        min.setDuration(8000);
        bar.setAnimation(min);
    }
}