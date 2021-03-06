package com.example.foodmaniac;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;
import java.util.List;

public class Chk_pg extends AppCompatActivity {


    private View view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        //String[] mobileArray = {""};
        List<String> mobileArray = new ArrayList<String>();
        super.onCreate(savedInstanceState);
        setContentView(R.layout.chk_pg);
        Intent intent = getIntent();
        Bundle b = getIntent().getExtras();

        double value = intent.getDoubleExtra("total", 0.0);
        String rad = intent.getStringExtra("r1");
        String ch1 = intent.getStringExtra("ch1");
        String ch2 = intent.getStringExtra("ch2");
        String ch3 = intent.getStringExtra("ch3");
        String ch4 = intent.getStringExtra("ch4");
        if(ch1 !=null) mobileArray.add(ch1);
        if(ch2 !=null) mobileArray.add(ch2);
        if(ch3 !=null) mobileArray.add(ch3);
        if(ch4 !=null) mobileArray.add(ch4);
        mobileArray.add(rad);
        ArrayAdapter adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_list_item_1, mobileArray);

        ListView listView = (ListView) findViewById(R.id.ls_view);
        listView.setAdapter(adapter);

        TextView t = (TextView) findViewById(R.id.tot_txt);
        t.setText("TOTAL     : " + value);
    }
    public void edt_ord(View view){
            finish();
    }
    public void sub(View view){
        Intent intent = new Intent(this, MainActivity.class);
        intent.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        startActivity(intent);
    }
    }
