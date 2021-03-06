package com.example.lab_3;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.RatingBar;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class MyAdapter extends RecyclerView.Adapter<MyAdapter.MyViewHolder> {
    String s1[];
    int images[];
    Context ct;
    public MyAdapter(Context ct, String s1[], int images[]){
         this.ct = ct; this.s1 = s1; this.images = images;
    }
    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(ct);
        View view = inflater.inflate(R.layout.my_row,parent,false);

        return new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        holder.txt1.setText(s1[position]);
        holder.myImage.setImageResource(images[position]);
        holder.myImage.setOnClickListener((OnClickListener) v -> {
    Context context = ct.getApplicationContext();
    double x = holder.r.getRating();
    x = x + (x %1);
    CharSequence text = s1[position] +":" + x;
    int duration = Toast.LENGTH_SHORT;
    Toast toast = Toast.makeText(context, text,duration);
            AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(this);
        });
    }

    @Override
    public int getItemCount() {
        return 8;
    }

    public class MyViewHolder extends  RecyclerView.ViewHolder {
        TextView txt1;
        RatingBar r;
        ImageView myImage;
        public MyViewHolder(@NonNull View itemView) {
            super(itemView);
            txt1 = itemView.findViewById(R.id.txtv);
            r = itemView.findViewById(R.id.ratingBar);
            myImage = itemView.findViewById(R.id.imageView);

        }

    }
    }


