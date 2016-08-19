package com.example.nolight.smartapplication;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view;
import android.view.View;
import android.widget.Button;
import android.widget.button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button button = (Button)findViewById(R.id.button);

        button.setOnClickListener(
                new Button.OnClickListener(){
                    public void onClick(View v){
                        TextView textView = (TextView)findViewById(R.id.textView);
                        textView.setText("BLA");
                    }
                }
        );

        button.setOnLongClickListener(
                new Button.OnLongClickListener(){
                    public boolean onLongClick(View v){
                        TextView textView = (TextView)findViewById(R.id.textView);
                        textView.setText("BLA BLAAAAAAA");
                        return true;
                    }
                }
        );
    }
}
