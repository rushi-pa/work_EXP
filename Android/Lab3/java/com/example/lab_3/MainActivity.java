package com.example.lab_3;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.RatingBar;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {


    RecyclerView rc;
    int image[] = {R.drawable.image_1, R.drawable.image_2, R.drawable.image_3,R.drawable.image_4, R.drawable.image_5, R.drawable.image_6,R.drawable.image_7, R.drawable.image_8};
    String s1[] = {"Pizza", "Burger", "french Fries","Samosa", "Kachori","Jalebi","Bombay Chat","Pani puri"};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        rc = findViewById(R.id.rcView);
        MyAdapter myadapter = new MyAdapter(this, s1, image);
        rc.setAdapter(myadapter);
        rc.setLayoutManager(new LinearLayoutManager(this));
//        RatingBar mBar = (RatingBar) findViewById(R.id.ratingBar);
//        mBar.setOnClickListener(v -> {
//            TextView txt = findViewById(R.id.txtv);
//    Context context = getApplicationContext();
//    CharSequence text = "uyciyciycju" + txt;
//    int duration = Toast.LENGTH_SHORT;
//    Toast toast = Toast.makeText(context, text,duration);
//    toast.show();
//        });
    }
//    public void ratBar(View view){
//        RatingBar r = findViewById(R.id.ratingBar);
//        TextView txt = findViewById(R.id.txtv);
//        Context context = getApplicationContext();
//        CharSequence text = "" + txt;
//        int duration = Toast.LENGTH_SHORT;
//        Toast toast = Toast.makeText(context, text,duration);
//        toast.show();
//    }
}