package com.example.bank_starters;

import android.os.Bundle;
import android.widget.Switch;

import androidx.appcompat.app.AppCompatActivity;

public class new_user extends AppCompatActivity {

        Switch s;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.new_user);

        s = (Switch) findViewById(R.id.al_user);
        if(s.isChecked()){
            finish();
        }
    }

}
