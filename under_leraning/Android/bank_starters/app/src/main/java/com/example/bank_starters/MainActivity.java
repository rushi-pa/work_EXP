package com.example.bank_starters;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Switch;
import android.widget.TextView;

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
                TextView price = findViewById(R.id.txt_chg);
                EditText fname = findViewById(R.id.log_fname);
                String str = fname.getText().toString();
                EditText lname = findViewById(R.id.log_lname);
                String str1 = lname.getText().toString();
                price.setText("Hi "+str+ " " +str1);
            }
        });
    }
    public void new_usr(View view){

        /*Add in Oncreate() funtion after setContentView()*/
// initiate Switch
        Switch simpleSwitch = (Switch) findViewById(R.id.new_user);

//displayed text of the Switch
        if(simpleSwitch.isChecked()){
            simpleSwitch.setChecked(false);
            Intent page = new Intent(this,new_user.class);
            startActivity(page);
        }

    }


}