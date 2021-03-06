package com.example.foodmaniac;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class order_pg extends AppCompatActivity {
    private boolean ch_1, ch_2 = false;
    private boolean ch_3, ch_4 = false;
    private boolean r_1, r_2 = false;
    private boolean r_3, r_4 = false;
    public double chh, rb = 0.0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.order_pg);
        getSupportActionBar().setTitle("Order here");

    }

    public void btn_check(View v) {
        if (chk_per() && rad_per()) {
            // Code here executes on main thread after user presses button
            Intent page = new Intent(order_pg.this, Chk_pg.class);
            double cost = calc_cost();
            page.putExtra("total" , cost);
            if(ch_1 == true){
                page.putExtra("ch1", "Fish");
            }
            if(ch_2 == true){
                page.putExtra("ch2", "Chicken");
            }
            if(ch_3 == true){
                page.putExtra("ch3", "Roasted Veggies");
            }
            if(ch_4 == true){
                page.putExtra("ch4", "Grilled Steak");
            }


            if(r_1 == true){
                page.putExtra("r1", "Tea");
            }
            if(r_2 == true){
                page.putExtra("r1", "Coffee");
            }
            if(r_3 == true){
                page.putExtra("r1", "Orange juice");
            }
            if(r_4 == true){
                page.putExtra("r1", "Apple juice");
            }
            System.out.println(cost);
            startActivity(page);
        } else {
            if (!chk_per()) {
                Context context = getApplicationContext();
                CharSequence text = "Please select your Food";
                int duration = Toast.LENGTH_SHORT;
                Toast toast = Toast.makeText(context, text, duration);
                toast.show();
            } else {
                Context context = getApplicationContext();
                CharSequence text = "Please select a drink";
                int duration = Toast.LENGTH_SHORT;
                Toast toast = Toast.makeText(context, text, duration);
                toast.show();
            }

        }
    }
    private double calc_cost() {
        double cost = 0.0;
        cost = chh + rb;
        return cost;
    }
    private boolean chk_per() {
        boolean ord = false;
        if (ch_1 == false && ch_2 == false && ch_3 == false && ch_4 == false) {
            ord = false;
        }
      else
        {
            ord = true;
        }

        return ord;
    }
    private boolean rad_per() {
        boolean ord = false;
        if (r_1 == false && r_2 == false && r_3 == false && r_4 == false) {
            ord = false;
        } else {
            ord = true;
        }

        return ord;
    }
    public void onCheckboxClicked(View view) {
        // Is the view now checked?
        boolean checked = false;
        checked = ((CheckBox) view).isChecked();
        String s3 = "";
        // Check which checkbox was clicked
        switch (view.getId()) {
            case R.id.chk_1:
                if (checked) {
                    ch_1 = true;
                    chh += 12;
                } else {
                    chh -= 12;
                    ch_1 = false;
                }
                break;
            case R.id.chk_2:
                if (checked) {
                    ch_2 = true;
                    chh += 11;
                } else {
                    chh -= 11;
                    ch_2 = false;
                }
                break;
            case R.id.chk_3:
                if (checked) {
                    ch_3 = true;
                    chh += 10;
                } else {
                    chh -= 10;
                    ch_3 = false;
                }
                break;
            case R.id.chk_4:
                if (checked) {
                    ch_4 = true;
                    chh += 15;
                } else {
                    chh -= 15;
                    ch_4 = false;
                }
                break;
        }
    }
    public void onRadioButtonClicked(View view) {
        boolean checked = ((RadioButton) view).isChecked();
        rb = 0.0;
        switch (view.getId()) {
            case R.id.rb_1:
                if (checked) {
                    r_1 = true;
                    rb += 1.7;
                } else {
                    rb -= 1.7;
                }
                break;
            case R.id.rb_2:
                if (checked) {
                    r_2 = true;
                    rb += 1.8;
                } else {
                    rb -= 1.8;
                }
                break;
            case R.id.rb_3:
                if (checked) {
                    r_3 = true;
                    rb += 2;
                } else {
                    rb -= 2;
                }
                break;
            case R.id.rb_4:
                if (checked) {
                    r_4 = true;
                    rb += 3;
                } else {
                    rb -= 3;
                }
                break;
        }
    }
}