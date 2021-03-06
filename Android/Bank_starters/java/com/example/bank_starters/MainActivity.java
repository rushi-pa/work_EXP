package com.example.bank_starters;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Switch;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportActionBar().setTitle("User Info");
        final Button button = findViewById(R.id.sub_btn);
        button.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                // Code here executes on main thread after user presses button


            }
        });
    }
    public void new_usr(View view){

        /*Add in Oncreate() funtion after setContentView()*/
// initiate Switch
        Switch simpleSwitch = (Switch) findViewById(R.id.new_user);

//displayed text of the Switch
        if(simpleSwitch.isChecked()){

            Intent page = new Intent(this,new_user.class);
            startActivity(page);
            simpleSwitch.setChecked(false);
        }

    }


}