package com.example.lab2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    boolean ch_1 = false;
    String opt ="";
    boolean ch_2 = false;
    String dlv ="";
    int what = 0;
    int order = 0;
    String top ="";
    boolean bx_1 =false;
    boolean bx_2 = false;
    boolean bx_3 = false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportActionBar().setTitle("Pizza Selector- Lab2");

        Button button = (Button) findViewById(R.id.btn1);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                TextView t = (TextView) findViewById(R.id.final_text);
                TextView t2 = (TextView) findViewById(R.id.final_text2);

                String s1 = opt;
               // s1="7878";
                String s2 = dlv;
                String s3 = top;
                if( ch_1==true && ch_2== true){

                    t.setText(s1 + " Pizza " + s3);
                    t.setTextColor(Color.WHITE);
                    t2.setText("Order Type : " + s2);
                    t2.setTextColor(Color.WHITE);
                }else{
                    if(s1==""){
                        t.setText("Please select size for your Pizza ");
                        t.setTextColor(Color.WHITE);
                    }
                    if(s2 == ""){
                        t.setText("Please select Order Type method ");
                        t.setTextColor(Color.WHITE);
                    }
                }
                top = "";
                bx_1 =false ; bx_3 =false ; bx_2 =false;

                final CheckBox checkBox = (CheckBox) findViewById(R.id.chk_1);
                if (checkBox.isChecked())
                    checkBox.setChecked(false);
                final CheckBox checkBox1 = (CheckBox) findViewById(R.id.chk_2);
                if (checkBox1.isChecked())
                    checkBox1.setChecked(false);
                final CheckBox checkBox2 = (CheckBox) findViewById(R.id.chk_3);
                if (checkBox2.isChecked())
                    checkBox2.setChecked(false);


            }

        });
    }

    public void onRadioButtonClicked(View view) {
        String option= "";
        boolean checked = ((RadioButton) view).isChecked();
        // Check which radio button was clicked
        switch (view.getId()) {
            case R.id.size_1:
                if (checked) {
                    ch_1 = true;
                    option= "Large";
                    }
                    break;
            case R.id.size_3:
                if (checked) {
                    ch_1 = true;
                   option = "Small";
                }
                    break;
            case R.id.size_2:
                if (checked) {
                    ch_1 = true;
                    option = "Medium";
                }
                    break;
        }
        opt = option;
    }
    public void onRadioButton(View view) {
        // Is the button now checked?
        boolean checked = ((RadioButton) view).isChecked();
        String s2 ="";
        // Check which radio button was clicked
        switch(view.getId()) {
            case R.id.order_1:
                if (checked) {
                    ch_2 = true;
                    s2 = "Pick-up";
                }
                    break;
            case R.id.order_2:
                if (checked){
                    ch_2 = true;
                   s2 = "Delivery";
                }
                    break;
        }
        dlv = s2;
    }
        public void onCheckboxClicked(View view) {
            // Is the view now checked?
            boolean chec = false;
           chec = ((CheckBox) view).isChecked();
            String s3 ="";
            // Check which checkbox was clicked
            switch(view.getId()) {
                case R.id.chk_1:
                    if (chec) {
                        bx_1=true;
                        s3 = "with Pepperoni";
                    }
                    break;
                case R.id.chk_2:
                    if (chec) {
                        bx_2=true;
                        s3 = "with Green Pepper";
                    }
                    break;
                case R.id.chk_3:
                    if (chec) {
                        s3="with Onions";
                        bx_3= true;
                    }
                    break;
                // TODO: Veggie sandwich
            }
            if(bx_1 ==true && bx_2 ==true){
                s3 = "with Pepperoni and Green Pepper";
            }
            if(bx_1 ==true && bx_3 ==true){
                s3 = "with Pepperoni and Onions";
            }
            if(bx_2 ==true && bx_3 ==true){
                s3 = "with Green Pepper and Onions";
            }
            if(bx_2==true && bx_1== true && bx_3==true){
                s3 = "with Pepperoni, Green Pepper and Onions";
            }
            top = s3;
        }
    }
